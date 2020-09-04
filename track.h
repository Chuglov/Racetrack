#pragma once
#include <string>
#include <list>
#include "trackiface.h"

class Track : public IRacetrack
{
private:
	IClient *client;
	std::list<Horse *> horses;
	std::string message;

public:
	virtual ~Track();

	std::list<Horse *> get_horses() override;
	void race() override;
	void notify(int) override;
};