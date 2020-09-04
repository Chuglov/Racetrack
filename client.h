#pragma once
#include <string>
#include "track.h"
#include "clientiface.h"

class Client : public IClient
{
private:
	Track &track;
	std::string name;

public:
	Client(Track &);
	virtual ~Client();
	int bet() override;
	void update(std::string) override;

	std::string get_name() override;
};