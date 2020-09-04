#pragma once
#include <string>
#include <list>
#include "trackiface.h"

class Track : public IRacetrack
{
private:
	std::list<IClient *> client_list;
	std::string message;

public:
	virtual ~Track();

	void attach(IClient *) override;
	void detach(IClient *) override;
	void place_bets() override;
	std::list<Horse *> get_horses() override;
	void notify() override;
};