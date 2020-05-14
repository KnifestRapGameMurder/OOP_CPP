#pragma once

#include<iostream>

class Tank
{
private:
	const unsigned int DEF_VOLUME = 20;
	const unsigned int MAX_VOLUME = 60;
	unsigned int volume;
	void set_volume(unsigned int volume);

	double fuel_level;
public:
	const unsigned int get_volume()const;
	const double get_fuel_level()const;

	Tank();
	Tank(unsigned int volume);
	~Tank();

	void fill_tank(double amount);

	void tank_info()const;

	double give_fuel(double amount);

	friend class Engine;
};