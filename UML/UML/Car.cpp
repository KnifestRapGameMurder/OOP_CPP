#include "Car.h"
#include<conio.h>
using namespace std::chrono_literals;
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
	:engine(5, tank), tank(40), gas_pedal(false), break_pedal(false), max_speed(250)
{
	control_panel.main_thread = new std::thread(&Car::control, this);

}

Car::~Car() {
	if (control_panel.main_thread->joinable())control_panel.main_thread->join();
	//if (control_panel.panel_thread->joinable())control_panel.panel_thread->join();

}

void Car::fill_tank(double amount)
{
	tank.fill_tank(amount);
}



void Car::start()
{
	if (tank.get_fuel_level())
	{
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
	change_consumption();
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
	if (!auto_trans.is_pwr_mode())
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
	if (auto_trans.get_position() != 'P' && auto_trans.get_position() != 'N' 
		&& !gas_pedal && engine.is_eng_started()) {
		control_panel.gas_thread = new std::thread(&Car::run_engine, this);
		gas_pedal = true;
	}

}
void Car::run_engine() {
	if (gas_pedal) {
		turn_off_red_beam();
		engine.run();
		speed += 10;
		if (speed > max_speed)speed = max_speed;
		change_consumption();
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
	if (!right_hl.get_low_beam() && !left_hl.get_low_beam()) {
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
	while (driver_in)
	{
		system("cls");
		if (driver_in) {
			std::cout << "Engine status: " << (engine.is_eng_started() ? "started " : "switched off ")
				<< "\tFuel level: " << tank.get_fuel_level() << std::endl;
			if (gas_pedal) { std::cout << "runing" << std::endl; }
			std::cout << "Transmission: " << auto_trans.get_position() << "\t\tSPORT MODE: " << (auto_trans.is_pwr_mode() ? "ON " : "OFF ") <<(tank.get_fuel_level()<5?"\t\tLOW FUEL":"")<< std::endl;
			std::cout << "Consumption/s: " << engine.get_consumption_per_s() << std::endl;
			std::cout << "Speed: "<<speed<<" ";
			for (int i = 0; i < speed / 10; i++) {
				std::cout << "|";
			}
			std::cout << "\n\n";

			std::cout << "[1]\t-\t change transmission position" << std::endl;
			std::cout << "[2]\t-\t change transmission mode" << std::endl;
			std::cout << "[Enter]\t-\t start" << std::endl;
			std::wcout << "[up arrow]\t-\t drive" << std::endl;
			std::cout << "[E]\t-\t get out" << std::endl;

			if (need_to_set_trans_p) {
				char p;
				std::cout << "SELECT POSITION: ";
				std::cin >> p;
				set_trans_position(p);
				need_to_set_trans_p = false;
			}
		}


		using namespace std::chrono_literals;
		std::this_thread::sleep_for(100ms);
	}

}

void Car::idle()
{
	while (engine.is_eng_started() &&
		tank.give_fuel(engine.get_consumption_per_s())
		)
	{
		change_consumption();
		using namespace std::chrono_literals;
		std::this_thread::sleep_for(1s);
	}
	engine.off();
}

void Car::control()
{
	char key = 0;
	do {
		
		if (!driver_in) 
		{
			system("cls");
			std::cout << "Press 'E' to get in car" << std::endl;
			std::cout << std::endl;
			std::cout << "[F]\t-\t fiil tank" << std::endl;
			if (need_to_feel_tank)
			{
				/*double amount;
				std::cout << "How much: ";
				std::cin >> amount;
				fill_tank(amount);
				need_to_feel_tank = false;*/
			}
		}
		key = _getch();
		switch (key)
		{
		case 'e':
			if (!driver_in) { get_in(); }
			else { get_out(); }
			break;
		case 13:
			if (!engine.is_eng_started())	start();
			else							off();
			break;
		case 'f':
			if (!driver_in) {
				double amount;
				std::cout << "How much: ";
				std::cin >> amount;
				fill_tank(amount);
				need_to_feel_tank = false;
			}
			//need_to_feel_tank = true;
			break;
		case 72:
			press_gas();
			break;
		case '1':
			need_to_set_trans_p = true;
			break;
		case '2':
		default:
			break;
		}

		if (gas_pedal)
		{
			if (control_panel.gas_thread->joinable())control_panel.gas_thread->join();
			gas_pedal = false;
		}

		if (speed > 0 && control_panel.wheeling_thread == nullptr)
			control_panel.wheeling_thread = new std::thread(&Car::free_wheeling, this);
		else if (speed == 0 && control_panel.wheeling_thread && control_panel.wheeling_thread->joinable())
		{
			control_panel.wheeling_thread->join();
			control_panel.wheeling_thread = nullptr;
		}

		
		std::this_thread::sleep_for(1ms);

	} while (key != 27);
	get_out();
	//if (control_panel.panel_thread->joinable())control_panel.panel_thread->join();

}

void Car::free_wheeling()
{
	//using namespace std::chrono_literals;
	while (speed > 0)
	{
		speed--;
		std::this_thread::sleep_for(1s);
	}
}

void Car::change_consumption()
{
	if (speed > 0 && speed <= 60)
		engine.set_consump_per_s(.002);
	else if (speed > 60 && speed <= 100)
		engine.set_consump_per_s(.0014);
	else if (speed > 100 && speed <= 140)
		engine.set_consump_per_s(.002);
	else if (speed > 140 && speed <= 200)
		engine.set_consump_per_s(.0025);
	else if (speed > 200 && speed <= 1250)
		engine.set_consump_per_s(.003);
	else
		engine.set_consump_per_s(engine.get_consumption()/10000);
	
	if (!engine.is_eng_started())
		engine.set_consump_per_s(0);
}


void Car::get_in()
{
	driver_in = true;
	control_panel.panel_thread = new std::thread(&Car::show_info, this);
}

void Car::get_out()
{
	driver_in = false;
	if (control_panel.panel_thread->joinable())control_panel.panel_thread->join();
}
