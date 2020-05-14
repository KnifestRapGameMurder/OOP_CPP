#include "AutoTransmission.h"

AutoTransmission::AutoTransmission()
	:position('P'),mode(NORM),blocked(false){}

AutoTransmission::~AutoTransmission(){}

char AutoTransmission::get_position() const
{
	return position;
}

bool AutoTransmission::is_pwr_mode() const
{
	return mode;
}

bool AutoTransmission::is_blocked() const
{
	return blocked;
}

void AutoTransmission::set_position(char new_p){
	switch (new_p)
	{
	case 'p':position = 'P'; break;
	case 'P':position = 'P'; break;
	case 'r':position = 'R'; break;
	case 'R':position = 'R'; break;
	case 'n':position = 'N'; break;
	case 'N':position = 'N'; break;
	case 'd':position = 'D'; break;
	case 'D':position = 'D'; break;
	case '2':position = '2'; break;
	case 'l':position = 'L'; break;
	case 'L':position = 'L'; break;
	}
}

void AutoTransmission::toggle_mode(){
	if (mode)	mode = NORM;
	else mode = PWR;
}

void AutoTransmission::to_block(){
	blocked = true;
}

void AutoTransmission::to_unblock(){
	blocked = false;
}
