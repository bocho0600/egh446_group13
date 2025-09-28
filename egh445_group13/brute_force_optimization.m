function optimized_waypoints = brute_force_optimization(waypoints)
    % Start position is the first waypoint
    init_pos = waypoints(1, :);
    % Remaining waypoints to visit
    remaining_points = waypoints(2:end, :);

    % Number of remaining points
    n = size(remaining_points, 1);

    % Generate all permutations of the remaining waypoints
    perms_idx = perms(1:n);

    min_dist = inf;
    best_order = [];

    % Check all possible orders
    for i = 1:size(perms_idx, 1)
        order = perms_idx(i, :);
        route = [init_pos; remaining_points(order, :)];

        % Calculate total distance for this route
        dist = 0;
        for k = 1:(size(route, 1) - 1)
            dx = route(k+1, 1) - route(k, 1);
            dy = route(k+1, 2) - route(k, 2);
            dist = dist + sqrt(dx^2 + dy^2);
        end

        % Check if this route is shorter
        if dist < min_dist
            min_dist = dist;
            best_order = order;
        end
    end

    % Build the optimized waypoint list
    optimized_waypoints = [init_pos; remaining_points(best_order, :)];
end
