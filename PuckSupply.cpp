#include "PuckSupply.h"

PuckSupply::PuckSupply()
{
	this->pucks.push_back(Puck());
	this->pucks.push_back(Puck());
	this->pucks.push_back(Puck());
}

//
//PuckSupply::~PuckSupply()
//{
//}

bool PuckSupply::have_alive_puck() 
{
	for (auto it = this->pucks.begin(); it < this->pucks.end(); it++)
	{
		if (!it->isDead)
			return true;
	}
	return false;
}

Puck & PuckSupply::get_alive_puck() 
{
	for (auto it = this->pucks.begin(); it < this->pucks.end(); it++)
	{
		if (!it->isDead)
			return *it;
	}
}