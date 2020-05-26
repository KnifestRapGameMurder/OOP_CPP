#pragma once
#include"Engine.h"
#include"Tank.h"
#include"CarLights.h"
#include"Trunk.h"
#include"Wheel.h"
#include"AutoTransmission.h"
#include"Rudder.h"

#include<thread>

constexpr int STRAIGHT = 0;
constexpr int TO_THE_LEFT = -1;
constexpr int TO_THE_RIGHT = 1;

class Car
{
private:
	Engine engine;
	Tank tank;
	AutoTransmission auto_trans;
	Rudder rudder;

	Headlight right_hl;
	Headlight left_hl;
	Taillight right_tl;
	Taillight left_tl;

	Trunk trunk;

	bool gas_pedal;
	bool break_pedal;

	double speed = 0;

	Wheel front_right_wheel = FRONT_WHEEL;
	Wheel front_left_wheel = FRONT_WHEEL;
	Wheel rear_right_wheel;
	Wheel rear_left_wheel;

	void turn_on_red_beam();
	void turn_off_red_beam();

	void turn_on_tail_beam();
	void turn_off_tail_beam();

	bool driver_in = false;
	bool need_to_feel_tank = false;
	bool need_to_set_trans_p = false;

	struct ControlPanel
	{
		std::thread* main_thread;
		std::thread* panel_thread;
		std::thread* idle_thread;	//холостой ход двигателя
		std::thread* gas_thread;
		std::thread* speed_thread;
	}control_panel;
public:
	

	Car();
	~Car();

	void fill_tank(double amount);
	void start();
	void off();

	void set_trans_position(char new_p);
	void set_PWR_mode();
	void set_NORM_mode();
	void block_trans();
	void unblock_trans();

	void press_gas();
	void run_engine();
	void press_break();

	void turn_on_left_ts();
	void turn_on_right_ts();
	void turn_off_left_ts();
	void turn_off_right_ts();
	void turn_to_left();
	void turn_to_right();
	void go_straight();
	void beep();
	void stop_beep();
	void turn_on_emergency();
	void turn_off_emergency();

	void turn_on_low_beam();
	void turn_off_low_beam();
	void turn_on_high_beam();
	void turn_off_high_beam();

	const double get_fuel_level()const;

	void show_info();
	void idle();
	void control();

	void speed_change();

	void get_in();
	void get_out();
};
