#include "Trunk.h"

Trunk::Trunk()
	:opened(false), empty(true){}

Trunk::~Trunk(){}

bool Trunk::isOpened() const{
	return opened;
}

bool Trunk::isEmpty() const
{
	return empty;
}

void Trunk::open(){
	opened = true;
}

void Trunk::close(){
	opened = false;
}

void Trunk::fill(){
	empty = false;
}

void Trunk::to_empty(){
	empty = true;
}
