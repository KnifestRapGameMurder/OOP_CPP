#include "Car.h"
#include<conio.h>

#include<iostream>

void Car::turn_on_red_beam()
{
	if (!left_tl.get_red_beam() && !right_tl.get_red_beam()) {
		left_tl.toggle_red_beam();
		right_tl.toggle_red_beam();
	}
}

void Car::turn_off_red_beam()
{
	if (left_tl.get_red_beam() && right_tl.get_red_beam()) {
		left_tl.toggle_red_beam();
		right_tl.toggle_red_beam();
	}
}

void Car::turn_on_tail_beam()
{
	if (!left_tl.get_low_beam() && !right_tl.get_low_beam()) {
		left_tl.toggle_low_beam();
		right_tl.toggle_low_beam();
	}
}

void Car::turn_off_tail_beam()
{
	if (left_tl.get_low_beam() && right_tl.get_low_beam()) {
		left_tl.toggle_low_beam();
		right_tl.toggle_low_beam();
	}
}



Car::Car()
	:engine(5,tank),tank(40),gas_pedal(false),break_pedal(false)
{
	control_panel.main_thread = new std::thread(&Car::control, this);
	control_panel.panel_thread = new std::thread(&Car::show_info, this);
}

Car::~Car(){
	if (control_panel.main_thread->joinable())control_panel.main_thread->join();
	if (control_panel.panel_thread->joinable())control_panel.panel_thread->join();
}

void Car::fill_tank(double amount)
{
	tank.fill_tank(amount);
}



void Car::start()
{
	if (tank.get_fuel_level()) {
		engine.start();
		turn_on_red_beam();
		control_panel.idle_thread = new std::thread(&Car::idle, this);
		
	}
	else {
		std::cout << "No fuel!\n";
	}
}

void Car::off()
{
	engine.off();
	control_panel.idle_thread->join();
	turn_off_low_beam();
	turn_off_red_beam();
	turn_off_high_beam();
}

void Car::set_trans_position(char new_p)
{
	auto_trans.set_position(new_p);
	if (new_p == 'R' || new_p == 'r') turn_on_red_beam();
}

void Car::set_PWR_mode()
{
	if(!auto_trans.is_pwr_mode())
		auto_trans.toggle_mode();
}

void Car::set_NORM_mode()
{
	if (auto_trans.is_pwr_mode())
		auto_trans.toggle_mode();
}

void Car::block_trans()
{
	auto_trans.to_block();
}

void Car::unblock_trans()
{
	auto_trans.to_unblock();
}

void Car::press_gas()
{
	if (auto_trans.get_position() != 'P' && auto_trans.get_position() != 'N' && !gas_pedal) {
		control_panel.gas_thread = new std::thread(&Car::run_engine, this);
		gas_pedal = true;
	}
	
}
void Car::run_engine() {
	if (gas_pedal) {
		turn_off_red_beam();
		engine.run();
	}
	using namespace std::chrono_literals;
	std::this_thread::sleep_for(1s);
}


void Car::press_break()
{
	break_pedal = true;
	break_pedal = true;
}



void Car::turn_on_left_ts()
{
	rudder.turn_on_left_ts();
}

void Car::turn_on_right_ts()
{
	rudder.turn_on_right_ts();
}

void Car::turn_off_left_ts()
{
	rudder.turn_off_left_ts();
}

void Car::turn_off_right_ts()
{
	rudder.turn_off_right_ts();
}

void Car::turn_to_left()
{
	rudder.set_direction(TO_THE_LEFT);
}

void Car::turn_to_right()
{
	rudder.set_direction(TO_THE_RIGHT);
}

void Car::go_straight()
{
	rudder.set_direction(STRAIGHT);
}

void Car::beep()
{
	rudder.to_beep();
}

void Car::stop_beep()
{
	rudder.turn_off_beep();
}

void Car::turn_on_emergency()
{
	rudder.turn_on_emergency();
}

void Car::turn_off_emergency()
{
	rudder.turn_off_emergency();
}

void Car::turn_on_low_beam()
{
	if (!right_hl.get_low_beam()&&!left_hl.get_low_beam()) {
		right_hl.toggle_low_beam();
		left_hl.toggle_low_beam();
	}
}

void Car::turn_off_low_beam()
{
	if (right_hl.get_low_beam() && left_hl.get_low_beam()) {
		right_hl.toggle_low_beam();
		left_hl.toggle_low_beam();
	}
}

void Car::turn_on_high_beam()
{
	if (!right_hl.get_high_beam() && !left_hl.get_high_beam()) {
		right_hl.toggle_high_beam();
		left_hl.toggle_high_beam();
	}
}

void Car::turn_off_high_beam()
{
	if (right_hl.get_high_beam() && left_hl.get_high_beam()) {
		right_hl.toggle_high_beam();
		left_hl.toggle_high_beam();
	}
}

const double Car::get_fuel_level() const
{
	return tank.get_fuel_level();
}

void Car::show_info()
{
	while (true)
	{
		system("cls");
		if (driver_in) {
			std::cout << "Engine status: " << (engine.is_eng_started() ? "started " : "switched off ")
				<< "\tFuel level: " << tank.get_fuel_level() << std::endl;
			if (gas_pedal) { std::cout << "runing" << std::endl; }
			std::cout << "Transmission: " << auto_trans.get_position()<<"\t\tSPORT MODE: "<< (auto_trans.is_pwr_mode()?"ON ":"OFF ") << std::endl;
			std::cout << std::endl;
			
			std::cout<<"[1]\t-\t change transmission position" << std::endl;
			std::cout<<"[2]\t-\t change transmission mode" << std::endl;
			std::cout<<"[Enter]\t-\t start" << std::endl;
			std::wcout<<"[up arrow]\t-\t drive" << std::endl;
			std::cout<<"[E]\t-\t get out" << std::endl;
			
			if (need_to_set_trans_p) {
				char p;
				std::cout << "SELECT POSITION: ";
				std::cin >> p;
				set_trans_position(p);
				need_to_set_trans_p = false;
			}
		}else{
			std::cout << "Press 'E' to get in car" << std::endl;
			std::cout << std::endl;
			std::cout << "[F]\t-\t fiil tank" << std::endl;
			if (need_to_feel_tank) {
				double amount;
				std::cout << "How much: ";
				std::cin >> amount;
				fill_tank(amount);
				need_to_feel_tank = false;
			}
		}
		
		
		using namespace std::chrono_literals;
		std::this_thread::sleep_for(1ms);
	}
	
}

void Car::idle()
{
	while (engine.is_eng_started() &&
		tank.give_fuel(engine.get_consumption_per_s())
		)
	{
		using namespace std::chrono_literals;
		std::this_thread::sleep_for(1s);
	}
	engine.off();
}

void Car::control()
{
	char key = 0;
	do {

		key = _getch();
		switch (key)
		{
		case 'e':
			if (!driver_in) get_in();
			else			get_out();
			break;
		case 13:
			if (!engine.is_eng_started())	start();
			else							off();
			break;
		case 'f':
			if(!driver_in)need_to_feel_tank = true;
			break;
		case 72:
			press_gas();
			break;
		case '1':
			need_to_set_trans_p = true;
			break;
		default:
			break;
		}

		if (gas_pedal)
		{
			if(control_panel.gas_thread->joinable())control_panel.gas_thread->join();
			gas_pedal = false;
		}

		using namespace std::chrono_literals;
		std::this_thread::sleep_for(1ms);
		
	} while (key != 27);
	if(control_panel.main_thread->joinable())control_panel.main_thread->join();
	if (control_panel.panel_thread->joinable())control_panel.panel_thread->join();
}

void Car::get_in()
{
	driver_in = true;
	
}

void Car::get_out()
{
	
	driver_in = false;
}
