%% ADA port4 
% Load plot

filename='example1.dat';

load filename;
x = filename(:,1);
y = filename(:,2);

plot(x,y,'o');

xlabel('Time [ms]');
ylabel('Elements N');
title('Time as function of elements');