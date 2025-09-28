function wp_list = waypoints_generator(num, bound)
    % Generates a list of random (X,Y) waypoints
    % num = number of waypoints to generate
    
    X = randi(bound, num, 1);
    Y = randi(bound, num, 1);
    
    wp_list = [X Y];
end