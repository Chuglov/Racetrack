#pragma once
#include <string>
#include <list>
#include "trackiface.h"

class Track : public ITrack
{
private:
	IClient *client;
	std::list<Horse *> horses;

public:
	Track();
	virtual ~Track();

	std::list<Horse *> get_horses() override;
	int race() override;
	void notify(int) override;
	void set_client(IClient *) override;
};