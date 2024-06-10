 %% Model Parameters GoKart
%  17.11.2023


%% Motor Parameters

motor.Imax_front_fwd            = 30;       % [A] maximum forward driving current on front motors
motor.Imax_rear_fwd             = 30;       % [A] maximum forward driving current on rear motors

motor.Imax_front_rev            = 30;       % [A] maximum reverse driving current on front motors
motor.Imax_rear_rev             = 30;       % [A] maximum revers driving current on rear motors

motor.Imax_front_brk            = 30;       % [A] maximum braking current on front motors
motor.Imax_rear_brk             = 30;       % [A] maximum braking current on rear motors

motor.rpm_multiplier_front        = 1;      % multiplier for rpm calculation (pole pairs) front motors
motor.rpm_multiplier_rear         = 1;      % multiplier for rpm calculation (pole pairs) rear motors

%% Drivetrain parameters 

drive.wheel_diameter_front        = 0.38;   % [m] front wheel diameter
drive.wheel_diameter_rear         = 0.38;   % [m] rear wheel diameter

drive.gearing_ratio_front         = 1;      % gearing ration front (1 = direct drive)
drive.gearing_ration_rear         = 5;      % gearing ration rear (chain transmission)

%% vehicle parameters

vehicle.weight                     = 100;   % [kg] total vehicle weight w/o driver
vehicle.wheelbase                  = 1.35;  % [m] vehicle weelbase 
vehicle.trackwidth_front           = 0.79;  % [m] track width front
vehicle.trackwidth_rear            = 0.72;  % [m] track width rear
