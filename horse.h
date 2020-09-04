#pragma once
#include <string>
#include <fstream>

class Horse
{
private:
	std::string breed;
	std::string name;
	int birth_year;
	int victories;
	int speed;

public:
	Horse();
	Horse(const Horse &);
	~Horse();

	void set_breed(std::string);
	void set_name(std::string);
	void set_bdyear(int);
	void set_victories(int);
	void set_speed();

	std::string get_breed();
	std::string get_name();
	int get_bdyear();
	int get_victories();
	int get_speed() const;
};