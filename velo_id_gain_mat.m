%function velo_id_gain_mat
clear all;
close all;
%  sim('velo_id_gain',[],simset('SrcWorkspace','current'));
simset('SrcWorkspace','current');
ts = 1/50;
u_ini = 1.5;
%set_param('velo_id_gain/Constant1', 'value', num2str(u_ini));

u_ref_list = 1:0.125:2.5;

open_system('velo_id_gain.slx');
open_system('velo_id_gain/Scope');

y_mean_list = [];
for i=1:length(u_ref_list)
    u_ref = u_ref_list(i);
    %set_param('velo_id_gain/Constant', 'value', num2str(u_ref_list(i)));
    %sim('velo_id_gain');
    set_param('velo_id_gain', 'SimulationCommand', 'start');
    while(1)
        stat = get_param('velo_id_gain','SimulationStatus');
        eval stat;
        if(strcmp(stat,'stopped')) 
            break;
        end
        pause(5);        
    end
    %     wait('velo_id_gain');
    %     T = timer('TimerFcn',@init_sim); %initialize timer object
    %     start(T) %start timer object running
    t=yout.time;
    y=yout.signals.values;
    y_mean = mean(y(250:end));
    fprintf('y_mean=%f\n',y_mean);
    y_mean_list(i) = y_mean;
    figure(1);
    plot(t,y,t,ones(size(y))*y_mean,'r');
    xlabel('Time [s]');
    ylabel('Velocity [V]');
    axis([0 10 0 3]);
    drawnow;
end

figure(2);
plot(u_ref_list,y_mean_list,'bo');
xlabel('Input Voltage[V]');
ylabel('Velocity [V]');
axis([0 3 0 3]);

while(1)
    disp('Please input Umin and Umax for fit');
    umin = input('Umin = ');
    umax = input('Umax = ');
    sidx = min(find(u_ref_list >= umin));
    eidx = max(find(u_ref_list <= umax));
    P = polyfit(u_ref_list(sidx:eidx),y_mean_list(sidx:eidx),1);
    Pin = 0:3;
    Pout = P(1)*Pin + P(2);
    u_offset = -P(2)/P(1);
    fprintf('*** Motor parameters ***\n');
    fprintf('K         = %f\n',P(1));
    fprintf('u_offset  = %f\n',u_offset);
    
    figure(2);
    plot(u_ref_list,y_mean_list,'o',...
        u_ref_list(sidx:eidx),y_mean_list(sidx:eidx),'ro',...
        Pin,Pout,'r-');
    xlabel('Input voltage [V]');
    ylabel('Velocity [V]');
    axis([0 3 0 3]);
    
    sw = input('OK? (1:Quit, 2:Retry) = ')
    switch sw
        case 1;
            break;
        case 2;
            continue;
    end
end

%end

