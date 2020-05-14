#pragma once

constexpr bool PWR = true;
constexpr bool NORM = false;

class AutoTransmission
{
private:
	char position;
	bool mode;
	bool blocked;
public:
	AutoTransmission();
	~AutoTransmission();

	char get_position()const;
	bool is_pwr_mode()const;
	bool is_blocked()const;

	void set_position(char new_position);
	void toggle_mode();
	void to_block();
	void to_unblock();
};

