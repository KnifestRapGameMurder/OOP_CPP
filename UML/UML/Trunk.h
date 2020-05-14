#pragma once

class Trunk
{
private:
	bool opened;
	bool empty;
public:
	Trunk();
	~Trunk();

	bool isOpened()const;
	bool isEmpty()const;

	void open();
	void close();
	void fill();
	void to_empty();
};

