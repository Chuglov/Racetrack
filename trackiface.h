#pragma once
#include <list>
#include <string>
#include "clientiface.h"
#include "horse.h"

class IRacetrack
{
public:
	virtual ~IRacetrack() {};
	virtual void attach(IClient *) = 0;
	virtual void detach(IClient *) = 0;
	virtual void place_bets() = 0;
	virtual std::list<Horse *> get_horses() = 0;
	virtual void notify() = 0;
};