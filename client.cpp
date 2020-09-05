#include <iostream>
#include <list>
#include "client.h"
#include "valid.h"
#include "horse.h"

using namespace std;

Client::Client(Track &track_) : track(track_)
{
	do
	{
		cout << "Enter your name: ";
		getline(cin, name);
	} while (!str_valid(name));

	this->track.set_client(this);
}

Client::~Client()
{
}

int Client::bet()
{
	list<Horse *>h;
	list<Horse *>::iterator it;
	string tmp;
	int num = 1;
	int choice;

	h = this->track.get_horses();
	if (h.empty())
		return -1;

	it = h.begin();

	while (it != h.end())
	{
		cout << num << ". " << (*it)->get_name() << endl;
		++num;
		++it;
	}

	while (true)
	{
		cout << "Horse number: ";
		getline(cin, tmp);
		choice = atoi(tmp.c_str());
		if (num_valid(tmp))
			if (choice > 0 && choice < num)
				break;
	}

	return choice;
}

void Client::update(std::string result)
{
	cout << result << endl;
}

std::string Client::get_name()
{
	return name;
}