#include <iostream>
#include <fstream>
#include <exception>
#include <string>
#include "track.h"
#include "valid.h"

using namespace std;

Track::~Track()
{
}

void Track::attach(IClient *client)
{
	client_list.push_back(client);
}

void Track::detach(IClient *client)
{
	client_list.remove(client);
}

void Track::place_bets()
{
	list<IClient *>::iterator it = client_list.begin();

	while (it != client_list.end())
	{
		(*it)->bet();
		++it;
	}
}

list<Horse *> Track::get_horses()
{
	list<Horse *> horses;
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
				h->set_speed();
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

	fin.close();
	return horses;
}

void Track::notify()
{
	list<IClient *>::iterator it = client_list.begin();

	while (it != client_list.end())
	{
		(*it)->update();
		++it;
	}
}