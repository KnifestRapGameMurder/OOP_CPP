#pragma once

class Rudder
{
private:
	int direction;
	bool beep;
	bool left_turn_signal;
	bool right_turn_signal;
	bool emergency;
public:
	Rudder();
	~Rudder();

	int get_direction()const;
	bool get_beep()const;
	bool get_left_ts()const;
	bool get_right_ts()const;
	bool get_emergency()const;

	void set_direction(int new_dir);
	void to_beep();
	void turn_off_beep();

	void turn_on_left_ts();
	void turn_on_right_ts();
	void turn_off_left_ts();
	void turn_off_right_ts();

	void turn_on_emergency();
	void turn_off_emergency();
};

