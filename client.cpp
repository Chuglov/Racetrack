#include <iostream>
#include "client.h"
#include "valid.h"

using namespace std;

Client::Client(Track &track_) : track(track_)
{
	do
	{
		cout << "Enter your name: ";
		getline(cin, name);
	} while (!str_valid(name));

	this->track.attach(this);
}

Client::~Client()
{
	this->track.detach(this);
}

void Client::bet()
{

}

void Client::update()
{

}