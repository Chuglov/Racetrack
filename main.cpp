#include <iostream>
#include "track.h"
#include "client.h"
#include "valid.h"

using namespace std;

int main()
{
	Track *t = new Track();
	Client *client = new Client(*t);
	string str;
	int result;

	while (true)
	{
		system("cls");
		result = t->race();

		if (result == -1)
			break;

		do
		{
			cout << "Do you want to bet again (y/n): ";
			getline(cin, str);
		} while (str != "y" && str != "n");

		if (str == "n")
			break;

		cout << endl;
	}

	delete t;
	delete client;

	return 0;
}