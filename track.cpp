#include <iostream>
#include <fstream>
#include <exception>
#include <algorithm>
#include <string>
#include "track.h"
#include "valid.h"

using namespace std;

Track::~Track()
{
}

list<Horse *> Track::get_horses()
{
	Horse *h = new Horse();
	ifstream fin("horses.txt");
	string str, tmp;
	int flag = 0;
	int pos;
	int num = 1;

	try
	{
		if (!fin.is_open())
			throw exception("Error while opening file \"horses.txt\"");

		if (fin.peek() == EOF)
			throw exception("File \"horses.txt\" is empty");

		while (fin.peek() != EOF && num != 0)
		{
			getline(fin, str);
			if (str.empty())
				continue;

			cout << str << endl;
			
			switch (flag)
			{
			case 0:
				if (pos = str.find("Number of horses: ") != 0)
					throw exception("There is an error in the file\n");

				tmp = str.substr(18);
				if (!num_valid(tmp))
					throw exception("There is a number of horses error in the file");

				num = stoi(tmp);
				break;

			case 1:
				if (pos = str.find("Horse name: ") != 0)
					throw exception("There is an error in the file\n");

				h->set_name(str.substr(12));
				break;

			case 2:
				if (pos = str.find("Breed: ") != 0)
					throw exception("There is an error in the file\n");

				h->set_breed(str.substr(7));
				break;
				
			case 3:
				if (pos = str.find("Birth year: ") != 0)
					throw exception("There is an error in the file\n");

				tmp = str.substr(12);
				if (!num_valid(tmp) && (stoi(tmp) < 2000 || stoi(tmp) > 2010) )
					throw exception("There is a horse birth year error in the file");

				h->set_bdyear(stoi(tmp));
				break;
					
			case 4:
				if (pos = str.find("Victories: ") != 0)
					throw exception("There is an error in the file\n");

				tmp = str.substr(11);
				if (!num_valid(tmp) && stoi(tmp) >= 0 )
					throw exception("There is a victories error in the file");

				h->set_victories(stoi(tmp));
				break;
			}

			if (flag == 4)
			{
				cout << endl;
				flag = 0;
				horses.push_back(h);
			}

			flag++;
			num--;
		}
	}
	catch (exception &ex)
	{
		cout << ex.what() << endl;
		getchar();
	}

	delete h;
	fin.close();
	return this->horses;
}

void Track::race()
{
	list<Horse *>::iterator it = this->horses.begin();
	string horse_name;
	int horse_num;
	int victories = 0;
	int client_bet = client->bet();

	for (int i = 0; i < 5; ++i)
	{
		it = this->horses.begin();

		horse_num = 0;
		while (it != this->horses.end())
		{
			if (horse_num == client_bet)
				horse_name = (*it)->get_name();

			(*it)->set_speed();
			++it;
			++horse_num;
		}
	
		horses.sort([](const Horse *h1, const Horse *h2)
		{
			return h1->get_speed() > h2->get_speed();
		});

		it = this->horses.begin();
		cout << "Race #" << i + 1 << " winner: " << (*it)->get_name() << endl;
		if (horse_name == (*it)->get_name())
			++victories;
	}

	cout << endl;
	notify(victories);

}

void Track::notify(int victories)
{
	string result = "Dear " + client->get_name() + ", your bet has won " + victories << " times";
	this->client->update(result);
}