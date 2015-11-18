function init_sim(obj,event) %timer object callback function
% set_param(gcs,'SimulationMode','external') %simulate Simulink model
% set_param(gcs,'SimulationCommand','connect')
set_param(gcs,'SimulationCommand','start')
wait(obj) %wait for timer object to stop running (occurs when simulation is finished)
end

