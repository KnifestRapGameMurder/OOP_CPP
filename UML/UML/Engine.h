#pragma once

#include"Tank.h"

class Engine
{
private:
	bool started;
	double consumption;
	double consumption_per_s;

	Tank* tank = nullptr;
public:
	bool is_eng_started()const;
	double get_consumption()const;
	double get_consumption_per_s()const;

	Engine();
	Engine(double consumption);
	Engine(double consumption,Tank& tank);
	~Engine();

	void start();
	void run();
	void off();

	void set_consump_per_s(double consump_per_s);
};