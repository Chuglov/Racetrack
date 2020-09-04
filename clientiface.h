#pragma once
#include <string>

class IClient
{
public:
	virtual ~IClient() {};
	virtual void bet() = 0;
	virtual void update() = 0;
};