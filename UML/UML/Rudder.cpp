#include "Rudder.h"

Rudder::Rudder()
	:direction(0),beep(false),left_turn_signal(false),right_turn_signal(false),emergency(false){}

Rudder::~Rudder(){}

int Rudder::get_direction() const
{
	return direction;
}

bool Rudder::get_beep() const
{
	return beep;
}

bool Rudder::get_left_ts() const
{
	return left_turn_signal;
}

bool Rudder::get_right_ts() const
{
	return right_turn_signal;
}

bool Rudder::get_emergency() const
{
	return emergency;
}

void Rudder::set_direction(int new_dir){
	if (new_dir >= -1 && new_dir <= 1)
		direction = new_dir;
}

void Rudder::to_beep(){
	beep = true;
}

void Rudder::turn_off_beep(){
	beep = false;
}

void Rudder::turn_on_left_ts(){
	left_turn_signal = true;
}

void Rudder::turn_on_right_ts(){
	right_turn_signal = true;
}

void Rudder::turn_off_left_ts(){
	left_turn_signal = false;
}

void Rudder::turn_off_right_ts(){
	right_turn_signal = false;
}

void Rudder::turn_on_emergency(){
	emergency = true;
}

void Rudder::turn_off_emergency(){
	emergency = false;
}
