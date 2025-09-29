classdef Visualizer2D < matlab.System
    % VISUALIZER2D 2D Robot Visualizer for MATLAB R2025a
    % Works with binaryOccupancyMap or occupancyMap directly
    % Displays robot pose, trajectory, waypoints, lidar, and objects.

    %% PROPERTIES
    properties(Nontunable)
        robotRadius = 0;    % Robot radius [m]
        mapName = '';       % Map filename (optional)
    end     
    properties(Nontunable, Logical)
        showTrajectory = true;      % Show trajectory
        hasWaypoints = false;       % Accept waypoints
        hasLidar = false;           % Accept lidar inputs
        hasObjDetector = false;     % Accept object detections
    end
    properties
        sensorOffset = [0 0];        % Lidar sensor offset (x,y) [m] 
        scanAngles = [-pi/4,0,pi/4]; % Scan angles [rad]
        objDetectorOffset = [0 0];   % Object detector offset (x,y) [m] 
        objDetectorAngle = 0;        % Object detector angle [rad]
        objDetectorFOV = pi/4;       % Object detector field of view [rad] 
        objDetectorMaxRange = 5;     % Object detector max range [m]
        objectColors = [1 0 0;0 1 0;0 0 1];  % Object colors [RGB rows]
        objectMarkers = 's';         % Object markers [char array]
    end

    %% PRIVATE PROPERTIES
    properties(Access = private)
        map;                % Map object (binaryOccupancyMap)
        fig;                % Figure window
        ax;                 % Axes for plotting
        RobotHandle;        % Robot plot handle
        OrientationHandle;  % Orientation line handle
        LidarHandles;       % Lidar line handles
        TrajHandle;         % Trajectory plot handle
        trajX = [];         % X trajectory points
        trajY = [];         % Y trajectory points
        WaypointHandle;     % Waypoints plot handle
        ObjectHandles;      % Object plot handles
        ObjDetectorHandles; % Object detector line handles
    end

    %% METHODS
    methods(Access = protected)
        
        function setupImpl(obj)
            % Create figure
            FigureName = 'Robot Visualization';
            FigureTag = 'RobotVisualization';
            existingFigures = findobj('type','figure','tag',FigureTag);
            if ~isempty(existingFigures)
                obj.fig = figure(existingFigures(1));
                clf;
            else
                obj.fig = figure('Name',FigureName,'tag',FigureTag);
            end
            obj.ax = axes('parent',obj.fig);   
            hold(obj.ax,'on');

            % Load map from workspace or file
            if evalin('base','exist(''map'',''var'')')
                obj.map = evalin('base','map'); % Use preloaded map
                show(obj.map,'Parent',obj.ax);
            elseif ~isempty(obj.mapName) && exist(obj.mapName,'file')
                loadedMap = load(obj.mapName);
                if isfield(loadedMap,'map')
                    obj.map = loadedMap.map;
                    show(obj.map,'Parent',obj.ax);
                else
                    obj.map = [];
                end
            else
                obj.map = [];
            end

            % Initialize robot plot
            obj.OrientationHandle = plot(obj.ax,0,0,'r','LineWidth',1.5);
            if obj.robotRadius > 0
                [x,y] = internal.circlePoints(0,0,obj.robotRadius,17);
                obj.RobotHandle = plot(obj.ax,x,y,'b','LineWidth',1.5);
            else
                obj.RobotHandle = plot(obj.ax,0,0,'bo', ...
                    'LineWidth',1.5,'MarkerFaceColor',[1 1 1]);
            end

            % Initialize trajectory
            if obj.showTrajectory
                obj.TrajHandle = plot(obj.ax,0,0,'b.-');
            end

            % Initialize waypoints
            if obj.hasWaypoints
                obj.WaypointHandle = plot(obj.ax,0,0,'rx','MarkerSize',10,'LineWidth',2);
            end

            % Initialize lidar lines
            if obj.hasLidar
                for idx = 1:numel(obj.scanAngles)
                    obj.LidarHandles(idx) = plot(obj.ax,0,0,'b--');
                end
            end

            % Initialize object detector
            if obj.hasObjDetector
                if numel(obj.objectMarkers) == 1
                    obj.ObjectHandles = scatter(obj.ax,0,0,75,... 
                        obj.objectMarkers,'filled','LineWidth',2);
                else
                    for idx = 1:numel(obj.objectMarkers)
                        obj.ObjectHandles(idx) = scatter(obj.ax,0,0,75,... 
                            obj.objectMarkers(idx),'filled','LineWidth',2);
                    end
                end
                objDetectorFormat = 'g-.';
                obj.ObjDetectorHandles(1) = plot(obj.ax,0,0,objDetectorFormat); 
                obj.ObjDetectorHandles(2) = plot(obj.ax,0,0,objDetectorFormat); 
            end

            % Final setup
            title(obj.ax,'Robot Visualization');
            hold(obj.ax,'off'); 
            axis equal          
        end

        function stepImpl(obj,pose,varargin)
            x = pose(1);
            y = pose(2);
            theta = pose(3);

            if ~isvalid(obj.fig)
                return;
            end

            idx = 1;
            if obj.hasWaypoints
                waypoints = varargin{idx}; idx = idx + 1;
            end
            if obj.hasLidar
                ranges = varargin{idx}; idx = idx + 1;
            end
            if obj.hasObjDetector
                objects = varargin{idx};
            end

            % Update trajectory
            if obj.showTrajectory
               obj.trajX = [obj.trajX;x];
               obj.trajY = [obj.trajY;y];
               set(obj.TrajHandle,'xdata',obj.trajX,'ydata',obj.trajY);
            end

            % Update waypoints
            if obj.hasWaypoints && numel(waypoints) > 1
                set(obj.WaypointHandle,'xdata',waypoints(:,1),'ydata',waypoints(:,2));
            end

            % Update robot pose
            xAxesLim = get(obj.ax,'XLim');
            lineLength = diff(xAxesLim)/20;
            if obj.robotRadius > 0
                [xc,yc] = internal.circlePoints(x,y,obj.robotRadius,17);
                set(obj.RobotHandle,'xdata',xc,'ydata',yc);
                len = max(lineLength,2*obj.robotRadius);
                xp = [x, x+(len*cos(theta))];
                yp = [y, y+(len*sin(theta))];
                set(obj.OrientationHandle,'xdata',xp,'ydata',yp);
            else
                xp = [x, x+(lineLength*cos(theta))];
                yp = [y, y+(lineLength*sin(theta))];
                set(obj.RobotHandle,'xdata',x,'ydata',y);
                set(obj.OrientationHandle,'xdata',xp,'ydata',yp);
            end

            % Update lidar lines
            if obj.hasLidar
                offsetVec = [cos(theta) -sin(theta); sin(theta) cos(theta)]*obj.sensorOffset';
                sensorLoc = [x,y] + offsetVec';  
                for idx = 1:numel(ranges)
                    if ~isnan(ranges(idx))
                        if size(sensorLoc,1) == 1
                            sensorPos = sensorLoc;
                        else
                            sensorPos = sensorLoc(idx,:); 
                        end
                        alpha = theta + obj.scanAngles(idx);                      
                        lidarX = sensorPos(1) + [0, ranges(idx)*cos(alpha)];
                        lidarY = sensorPos(2) + [0, ranges(idx)*sin(alpha)];
                        set(obj.LidarHandles(idx),'xdata',lidarX,'ydata',lidarY); 
                    else
                        set(obj.LidarHandles(idx),'xdata',[],'ydata',[]); 
                    end 
                end
            end

            % Update object detector
            if obj.hasObjDetector
                if isempty(objects)
                    set(obj.ObjectHandles,'xdata',[],'ydata',[],'cdata',[]);
                else
                    if size(obj.objectColors,1) == 1
                        colorData = obj.objectColors;
                    else
                        colorData = obj.objectColors(objects(:,3),:);
                    end
                    if numel(obj.objectMarkers) == 1
                        set(obj.ObjectHandles,'xdata',objects(:,1),'ydata',objects(:,2),'cdata',colorData);
                    else
                        for idx = 1:numel(obj.objectMarkers)
                            indices = (objects(:,3) == idx);
                            set(obj.ObjectHandles(idx),'xdata',objects(indices,1),'ydata',objects(indices,2),'cdata',colorData(indices,:));
                        end
                    end
                end

                offsetVec = [cos(theta) -sin(theta); sin(theta) cos(theta)]*obj.objDetectorOffset';
                sensorLoc = [x,y] + offsetVec';  

                alphaLeft = theta + obj.objDetectorAngle + obj.objDetectorFOV/2;        
                if ~isempty(obj.map) 
                    intPtsLeft = rayIntersection(obj.map,[sensorLoc alphaLeft],0,obj.objDetectorMaxRange);
                else
                    intPtsLeft = NaN;
                end
                if ~isnan(intPtsLeft)
                    objLeftX = [sensorLoc(1) intPtsLeft(1)];
                    objLeftY = [sensorLoc(2) intPtsLeft(2)];    
                else
                    objLeftX = sensorLoc(1) + [0, obj.objDetectorMaxRange*cos(alphaLeft)];
                    objLeftY = sensorLoc(2) + [0, obj.objDetectorMaxRange*sin(alphaLeft)];   
                end
                set(obj.ObjDetectorHandles(1),'xdata',objLeftX,'ydata',objLeftY); 

                alphaRight = theta + obj.objDetectorAngle - obj.objDetectorFOV/2;        
                if ~isempty(obj.map) 
                    intPtsRight = rayIntersection(obj.map,[sensorLoc alphaRight],0,obj.objDetectorMaxRange);
                else
                    intPtsRight = NaN; 
                end
                if ~isnan(intPtsRight)
                    objRightX = [sensorLoc(1) intPtsRight(1)];
                    objRightY = [sensorLoc(2) intPtsRight(2)];    
                else
                    objRightX = sensorLoc(1) + [0, obj.objDetectorMaxRange*cos(alphaRight)];
                    objRightY = sensorLoc(2) + [0, obj.objDetectorMaxRange*sin(alphaRight)];   
                end
                set(obj.ObjDetectorHandles(2),'xdata',objRightX,'ydata',objRightY); 
            end

            drawnow('limitrate')
        end

        function num = getNumInputsImpl(obj)
            num = 1;
            if obj.hasWaypoints, num = num + 1; end
            if obj.hasLidar, num = num + 1; end
            if obj.hasObjDetector, num = num + 1; end
        end

        function [namePose,varargout] = getInputNamesImpl(obj)
            namePose = 'pose';
            idx = 1;
            if obj.hasWaypoints, varargout{idx} = 'waypoints'; idx = idx+1; end
            if obj.hasLidar, varargout{idx} = 'ranges'; idx = idx+1; end
            if obj.hasObjDetector, varargout{idx} = 'objects'; end
        end

        function flag = isInactivePropertyImpl(obj,prop)
            flag = false;
            switch prop
                case {'sensorOffset','scanAngles'}, flag = ~obj.hasLidar;
                case {'objDetectorOffset','objDetectorAngle','objDetectorFOV','objDetectorMaxRange','objectColors','objectMarkers'}, flag = ~obj.hasObjDetector;
            end
        end
    end

    methods (Access = public)
        function attachLidarSensor(obj,lidar)
            obj.hasLidar = true;
            obj.sensorOffset = lidar.sensorOffset;
            obj.scanAngles = lidar.scanAngles;
        end

        function attachObjectDetector(obj,detector)
            obj.hasObjDetector = true;
            obj.objDetectorOffset = detector.sensorOffset;
            obj.objDetectorAngle = detector.sensorAngle;
            obj.objDetectorFOV = detector.fieldOfView;
            obj.objDetectorMaxRange = detector.maxRange;
        end
    end

    methods (Static, Access = protected)
        function flag = showSimulateUsingImpl, flag = false; end
        function simMode = getSimulateUsingImpl, simMode = 'Interpreted execution'; end
    end
end
