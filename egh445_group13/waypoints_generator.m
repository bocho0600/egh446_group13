function wp_list = waypoints_generator(num, xlim, ylim)
    % Generates a list of random (X,Y) waypoints
    % num = number of waypoints to generate
    
    X = randi(xlim, num, 1);
    Y = randi(ylim, num, 1);
    
    wp_list = [X Y];
end