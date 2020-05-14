#pragma once

constexpr auto FRONT_WHEEL = true;



class Wheel
{
private:
	bool beeing_front;
	bool drive;
	bool tire;
	int direction;
public:
	Wheel(bool beeing_front = false);
	~Wheel();

	bool is_there_a_drive()const;
	bool is_there_a_tire()const;

	void take_off_the_tire();
	void put_on_the_tire();

	void change_drive();

	bool is_ready_to_go()const;

	bool get_direction()const;
	void set_direction(int new_direction);
};

