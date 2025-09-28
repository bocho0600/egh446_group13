function xk1 = fState(xk, uk)
% State: xk = [x; y; theta; xdot; ydot; omega]
% Input: uk = [v; omega]
Ts = 0.05;                      % your sample time

x     = xk(1);  y   = xk(2);  th = xk(3);
v     = uk(1);  om  = uk(2);

x1    = x  + Ts * v * cos(th);
y1    = y  + Ts * v * sin(th);
th1   = wrapToPi(th + Ts * om);
xd1   = v * cos(th);
yd1   = v * sin(th);
om1   = om;                     % or: om1 = xk(6);  (random-walk choice)

xk1   = [x1; y1; th1; xd1; yd1; om1];
end
