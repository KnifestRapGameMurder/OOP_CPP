#include "Wheel.h"

Wheel::Wheel(bool beeing_front)
	:beeing_front(beeing_front),drive(true),tire(true),direction(0){}

Wheel::~Wheel(){}

bool Wheel::is_there_a_drive() const
{
	return drive;
}

bool Wheel::is_there_a_tire() const
{
	return tire;
}

void Wheel::take_off_the_tire(){
	tire = false;
}

void Wheel::put_on_the_tire(){
	tire = true;
}

void Wheel::change_drive(){}

bool Wheel::is_ready_to_go() const
{
	return (drive&&tire);
}

bool Wheel::get_direction() const
{
	return direction;
}

void Wheel::set_direction(int new_dir)
{
	if (beeing_front && new_dir >= -1 && new_dir <= 1)
		direction = new_dir;
}
