#ifndef PuckSupply_H
#define PuckSupply_H

#include "Puck.h"

class PuckSupply: public Puck{
    std::vector<Puck> pucks;
public:
	PuckSupply();

	bool have_alive_puck();
     
	Puck & get_alive_puck();
};

#endif
