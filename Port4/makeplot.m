%% ADA port4 
% Load plot



load example.txt;
x = example(:,2);
y = example(:,1);

plot(y,x,'o');

xlabel('Time [ms]');
ylabel('Elements N');
title('Time as function of elements');