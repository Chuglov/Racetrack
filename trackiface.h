#pragma once
#include <list>
#include <string>
#include "clientiface.h"
#include "horse.h"

class IRacetrack
{
public:
	virtual ~IRacetrack() {};
	virtual std::list<Horse *> get_horses() = 0;
	virtual void race() = 0;
	virtual void notify(int) = 0;
};