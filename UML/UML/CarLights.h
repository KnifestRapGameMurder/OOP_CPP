#pragma once

class Headlight
{
private:
	bool low_beam;
	bool high_beam;
	bool turn_signal;
public:
	Headlight();
	~Headlight();

	bool get_low_beam()const;
	bool get_high_beam()const;
	bool get_turn_signal()const;

	void toggle_low_beam();
	void toggle_high_beam();
	void toggle_turn_signal();
};

class Taillight
{
private:
	bool low_beam;
	bool red_beam;
	bool turn_signal;
public:
	Taillight();
	~Taillight();

	bool get_low_beam()const;
	bool get_red_beam()const;
	bool get_turn_signal()const;

	void toggle_low_beam();
	void toggle_red_beam();
	void toggle_turn_signal();
};