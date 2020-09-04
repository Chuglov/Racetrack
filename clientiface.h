#pragma once
#include <string>

class IClient
{
public:
	virtual ~IClient() {};
	virtual int bet() = 0;
	virtual void update(std::string) = 0;
	virtual std::string get_name() = 0;
};