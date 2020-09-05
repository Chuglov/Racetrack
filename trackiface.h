#pragma once
#include <list>
#include <string>
#include "clientiface.h"
#include "horse.h"

class ITrack
{
public:
	virtual ~ITrack() {};
	virtual std::list<Horse *> get_horses() = 0;
	virtual int race() = 0;
	virtual void notify(int) = 0;
	virtual void set_client(IClient *) = 0;
};