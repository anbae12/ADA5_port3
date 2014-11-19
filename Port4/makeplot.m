%% ADA port4 
% Load plot
clear;
clc;
%% A)
maxNo=30000; % Have to checked...

load example.txt;
x = example(:,2);
y = example(:,1);

n = (1:maxNo);
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

% B)
load datanum.txt;
x1 = datanum(:,2);
y1 = datanum(:,1);

n1 = (1:maxNo);
yy1=times(n1,log10(n1));

figure(2)
subplot(2,1,1)
plot(n1,yy1)
xlabel('Time [ms]');
ylabel('Elements N');
title('O(N log(N))');


subplot(2,1,2)
plot(y1,x1,'o');
xlabel('Time [ms]');
ylabel('Elements N');
title('Time as function of elements');
saveas(gca,'report/graphics/test2', 'epsc')


