%% ADA port4 
% Load plot
clear;
clc;
%% A)
load A.txt;
x = A(:,2);
y = A(:,1);
n = (1:y(length(y)));
yy=power(n,2);
figure(1)
subplot(2,1,1)
plot(n,yy)   %plot 1
xlabel('Time [ms]');
ylabel('Elements N');
title('O(N^2)');
subplot(2,1,2)
plot(y,x,'o');
xlabel('Time [ms]');
ylabel('Elements N');
title('Time as function of elements');
saveas(gca,'report/graphics/test1', 'epsc')

<<<<<<< Updated upstream
% B)
load B.txt;
x1 = B(:,2);
y1 = B(:,1);
n1 = (1:y1(length(y1)));
yy1=times(n1,log10(n1));
figure(2)
subplot(2,1,1)
plot(n1,yy1)
xlabel('Time [ms]');
ylabel('Elements N');
title('O(N log(N))');
subplot(2,1,2)
plot(y1,x1,'o');
=======
datanum='example1.dat';

load datanum;
x = datanum(:,1);
y = datanum(:,2);

plot(x,y,'o');

>>>>>>> Stashed changes
xlabel('Time [ms]');
ylabel('Elements N');
title('Time as function of elements');
saveas(gca,'report/graphics/test2', 'epsc')