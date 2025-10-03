%%

%load map and obstable
load('obstacles_air_ground.mat')
load('complexMap_air_ground.mat')


% lidar FOV/2
fov_half = 120; %in degrees
fov_half = fov_half * pi/180;


% angular resolution with 30 returns
scanAngles = linspace(-fov_half,fov_half, 30);




