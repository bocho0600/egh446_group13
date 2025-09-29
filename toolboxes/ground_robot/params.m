%% Parameters setup
close all;
rng;
theta=(pi/180)*randi([-180 180],1,2);
vehicle1=randi([-100 100],1,2);
vehicle1(3) = theta(1);
rng;
vehicle2=randi([-100 100],1,2);
vehicle2(3)=theta(2);



