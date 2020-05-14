#include"Engine.h"


void Engine::start()
{
	started = true;
}

void Engine::run()
{
	if (!started || tank->fuel_level==0) return;
	this->tank->fuel_level -= consumption_per_s;
}

void Engine::off()
{
	started = false;
}

Engine::Engine()
	:started(false),consumption(3),consumption_per_s(consumption/1000)
{
}

Engine::Engine(double consumption)
	:started(false)
{
	this->consumption = consumption < 3 ? 3 : consumption>20 ? 20 : consumption;
	this->consumption_per_s = this->consumption / 1000;
}

Engine::Engine(double consumption,Tank& tank)
	:Engine(consumption)
{
	this->tank = &tank;
}

Engine::~Engine()
{
}

bool Engine::is_eng_started()const
{
	return started;
}

double Engine::get_consumption_per_s() const
{
	return consumption_per_s;
}
