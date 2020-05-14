#include "Tank.h"

const unsigned int Tank::get_volume() const
{
	return volume;
}

const double Tank::get_fuel_level() const
{
	return fuel_level;
}

Tank::Tank()
	:volume(DEF_VOLUME),fuel_level(0)
{
}

Tank::Tank(unsigned int volume)
	:fuel_level(0)
{
	set_volume(volume);
}

Tank::~Tank()
{
}

void Tank::fill_tank(double amount)
{
	if (amount <= 0) return;
	fuel_level += (fuel_level + amount <= volume ? amount : volume);
}

void Tank::tank_info() const
{
	std::cout << "Tank volume:\t" << volume
		<< " l\tTank level:\t" << fuel_level << " l\n";
}

double Tank::give_fuel(double amount)
{
	fuel_level -= amount;
	if (fuel_level < 0)fuel_level = 0;
	return fuel_level;
}

void Tank::set_volume(unsigned int volume)
{
	this->volume = (volume<DEF_VOLUME ? DEF_VOLUME : volume > MAX_VOLUME ? MAX_VOLUME : volume);
}
