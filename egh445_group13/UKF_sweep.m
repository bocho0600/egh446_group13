%% UKF RMSE heatmap tuner (uses existing Q, R, P0, initial_state)
% Model must output Vehicle 1 cross-track error as simOut.error1

clc; close all;

model = 'sl_groundvehicleDynamics';
stopTime   = '150';      % shorten to sweep quickly; verify later with long run
settle_sec = 2.0;        % ignore initial seconds when computing RMSE
useFastRestart = true;   % big speed-up for parameter sweeps

% ----- Capture your current Q and R (shapes & magnitudes) -----
Q_base = evalin('base','Q');     % uses your current variable
R_base = evalin('base','R');

% ----- Define sweep grids (log-spaced usually works best) -----
qScales = logspace(-3, 1, 9);    % 1e-3 ... 10 (9 points)
rScales = logspace(-3, 1, 9);

RMSE = nan(numel(qScales), numel(rScales));

% Open model once
load_system(model);
if useFastRestart
    set_param(model,'FastRestart','on');
else
    set_param(model,'FastRestart','off');
end

alphaList = [1e-3 5e-3 1e-2 5e-2 0.1];
RMSE3 = nan(numel(alphaList), numel(qScales), numel(rScales));
ukfBlk = 'sl_groundvehicleDynamics/Unscented Kalman Filter';
for ia = 1:numel(alphaList)
    set_param(ukfBlk, 'Alpha', num2str(alphaList(ia)));  % change Alpha in the mask
    
            % Scale your existing matrices (keep structure, only change magnitude)
            Q = 1 * Q_base;   %#ok<NASGU>
            R = 0.00316  * R_base;   %#ok<NASGU>
    
            % Push Q,R to base so the UKF block reads them
            assignin('base','Q',Q);
            assignin('base','R',R);
    
            % Run the model
            simOut = sim(model, 'StopTime', stopTime, 'CaptureErrors','on');
    
            % === Compute RMSE from Vehicle 1 cross-track error ===
            t = simOut.error1.Time;
            e = simOut.error1.Data;
            mask = t >= (t(1) + settle_sec);
            e = e(mask);
    
            RMSE = sqrt(mean(e.^2));
            fprintf('Alpha=%8.3g RMSE=%.4f\n', alphaList(ia), RMSE);
end 

% Restore original Q, R and Fast Restart
assignin('base','Q',Q_base);
assignin('base','R',R_base);
set_param(model,'FastRestart','off');

%% ----- Plot heatmap -----
figure('Color','w'); box on;
imagesc(log10(rScales), log10(qScales), RMSE);  % x: R, y: Q
axis xy; colorbar; colormap(parula);
xlabel('log_{10}(R scale)'); ylabel('log_{10}(Q scale)');
title('UKF RMSE heatmap (Vehicle 1 cross-track error)');

% Mark the minimum
[minVal, idx] = min(RMSE, [], 'all', 'linear');
[iqBest, irBest] = ind2sub(size(RMSE), idx);
hold on;
plot(log10(rScales(irBest)), log10(qScales(iqBest)), 'wo', 'MarkerSize', 10, 'LineWidth', 2);
text(log10(rScales(irBest)), log10(qScales(iqBest)), sprintf('  min=%.3f',minVal), ...
     'Color','w','FontWeight','bold');

fprintf('\nBest RMSE = %.4f at Q = %.3g * Q_base,  R = %.3g * R_base\n', ...
        minVal, qScales(iqBest), rScales(irBest));