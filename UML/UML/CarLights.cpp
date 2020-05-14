#include "CarLights.h"

Headlight::Headlight()
	:low_beam(false),high_beam(false),turn_signal(false){}

Headlight::~Headlight(){}

bool Headlight::get_low_beam() const{	return low_beam;}

bool Headlight::get_high_beam() const{	return high_beam;}

bool Headlight::get_turn_signal() const{	return turn_signal;}

void Headlight::toggle_low_beam(){
	if (low_beam) low_beam = false;
	else low_beam = true;
}

void Headlight::toggle_high_beam(){
	if (high_beam) high_beam = false;
	else high_beam = true;
}

void Headlight::toggle_turn_signal(){
	if (turn_signal) turn_signal = false;
	else turn_signal = true;
}

Taillight::Taillight()
	:low_beam(false), red_beam(false), turn_signal(false) {}

Taillight::~Taillight(){}

bool Taillight::get_low_beam() const
{
	return low_beam;
}

bool Taillight::get_red_beam() const
{
	return red_beam;
}

bool Taillight::get_turn_signal() const
{
	return turn_signal;
}

void Taillight::toggle_low_beam(){
	if (low_beam) low_beam = false;
	else low_beam = true;
}

void Taillight::toggle_red_beam(){
	if (red_beam) red_beam = false;
	else red_beam = true;
}

void Taillight::toggle_turn_signal(){
	if (turn_signal) turn_signal = false;
	else turn_signal = true;
}
