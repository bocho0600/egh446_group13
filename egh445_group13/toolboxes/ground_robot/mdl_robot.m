% Ground Robot parameters 
%
%
% Properties:
%
% This is a structure with the following elements:
%
% X       initial position X (1x1)
% Y       initial position Y (1x1)
% Theta   initial orientation (1x1)

%
% Notes::
% - SI units are used.
%
cuztomized_wp = [5.0, 7 ;...
                 6.0 , 18 ;...
                 13 ,  9.0;...
                 17 ,  18 ;...
                 23, 3.5];
cuztomized_wp = cuztomized_wp*2;
waypoints = waypoints_generator(5, [0 52], [0 41]);
optimized_waypoints = two_opt_nn_multi_optimisation(cuztomized_wp);

load('obstacles_air_ground.mat')
load('complexMap_air_ground.mat')
%load('optimized_waypoints.mat');  % Load preset waypoints (optimized)

% Get initial waypoint
init_wp = optimized_waypoints(1, :);

% Set radius for random starting position

% Assign to robot struct
robot.X = 2;                  
robot.Y = 2;                   
robot.Theta = 0;

initial_state = [robot.X ; robot.Y; robot.Theta; 0; 0; 0];

%Kalman stuff
sig2_theta = 2 * (pi/180)^2;   % = 0.000609 rad^2
sig2_vx = (0.20)^2;           % (m/s)^2
sig2_vy = (0.20)^2;           % (m/s)^2
sig2_r  = (deg2rad(5))^2;     % (rad/s)^2
R = diag([0.1, 0.1, sig2_theta, sig2_vx, sig2_vy, sig2_r]);
Q = diag([1e-3, 1e-3, (deg2rad(0.5))^2, 1e-2, 1e-2, (deg2rad(1))^2]);
R = 0.00316  * R;
Alpha = 0.05;

P0 = diag([5^2, 5^2, (deg2rad(30))^2, 1^2, 1^2, (deg2rad(10))^2]);


Ts = 0.05;  

A  = [ 1 0 0 Ts  0  0;
       0 1 0  0 Ts  0;
       0 0 1  0  0 Ts;
       0 0 0  1  0  0;
       0 0 0  0  1  0;
       0 0 0  0  0  1 ];

% linearised at theta=0
B = [ Ts   0;  
      0    0;   
      0   Ts;  
      0    0;   
      0    0;   
      0    0 ];       

C  = eye(6);
D = zeros(6,2);

sig_ax   = 0.1;    % m/s^2
sig_ay   = 0.1;    % m/s^2
sig_alpha= 2;    % rad/s^2

G = [0.5*Ts^2  0          0;
     0         0.5*Ts^2   0;
     0         0          0.5*Ts^2; 
     Ts        0          0;
     0         Ts         0;
     0         0          Ts];

Qc = diag([sig_ax^2, sig_ay^2, sig_alpha^2]);   
Q2  = G*Qc*G.';                                  

R2  = diag([0.5^2, 0.5^2, (2*pi/180)^2, 0.3^2, 0.3^2, (2*pi/180)^2]);

x0 = [0;0;0; 0;0;0];           
P02 = diag([3^2, 3^2, (10*pi/180)^2, 1^2, 1^2, (10*pi/180)^2]);