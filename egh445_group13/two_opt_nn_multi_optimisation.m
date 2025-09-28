function optimized_waypoints = two_opt_nn_multi_optimisation(waypoints)
    N = size(waypoints,1);
    bestLen = inf; bestOrder = [];
    for s = 1:N
        order = nn_single(waypoints, s);
        L = route_length(waypoints, order);
        if L < bestLen
            bestLen = L;
            bestOrder = order;
        end
    end
    order2 = two_opt(waypoints, bestOrder);
    optimized_waypoints = waypoints(order2, :);
end

% Nearest Neighbour
function order = nn_single(P, startIdx)
    n = size(P,1);
    visited = false(1,n);
    order   = zeros(1,n);
    order(1) = startIdx;
    visited(startIdx) = true;

    for k = 1:n-1
        i = order(k);
        bestj = 0; bestd = inf;
        for j = 1:n
            if visited(j), continue; end
            d = hypot(P(j,1)-P(i,1), P(j,2)-P(i,2));
            if d < bestd - eps || (abs(d-bestd)<=eps && j < bestj)
                bestd = d; bestj = j;
            end
        end
        order(k+1) = bestj;
        visited(bestj) = true;
    end
end

% 2-opt
function order = two_opt(P, order)
    n = numel(order);
    improved = true;
    while improved
        improved = false;
        for i = 1:n-2
            for j = i+1:n-1
                a = order(i); b = order(i+1);
                c = order(j); d = order(j+1);
                cur  = distP(P,a,b) + distP(P,c,d);
                prop = distP(P,a,c) + distP(P,b,d);
                if prop + 1e-12 < cur
                    order(i+1:j) = order(j:-1:i+1);
                    improved = true;
                end
            end
        end
    end
end

% Route length
function L = route_length(P, order)
    coords = P(order, :);
    diffs  = diff(coords,1,1);
    L = sum(sqrt(sum(diffs.^2,2)));
end

% Point-to-point distance
function d = distP(P,i,j)
    d = hypot(P(j,1)-P(i,1), P(j,2)-P(i,2));
end
