#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "horse.h"

Horse::Horse()
{
}

Horse::Horse(const Horse &h)
{
	this->breed = h.breed;
	this->name = h.name;
	this->birth_year = h.birth_year;
	this->victories = h.victories;
	this->speed = h.speed;
}

Horse::~Horse()
{
}

void Horse::set_breed(std::string breed)
{
	this->breed = breed;
}

void Horse::set_name(std::string name)
{
	this->name = name;
}

void Horse::set_bdyear(int birth_year)
{
	this->birth_year = birth_year;
}

void Horse::set_victories(int victories)
{
	this->victories = victories;
}

void Horse::set_speed()
{
	srand(time(NULL));
	this->speed = rand() % 40 + 10;
}

std::string Horse::get_breed()
{
	return this->breed;
}

std::string Horse::get_name()
{
	return this->name;
}

int Horse::get_bdyear()
{
	return this->birth_year;
}

int Horse::get_wins()
{
	return this->victories;
}

int Horse::get_speed() const
{
	return this->speed;
}