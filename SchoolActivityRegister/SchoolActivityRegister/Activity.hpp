#ifndef ACTIVITY_HPP_
#define ACTIVITY_HPP_

#include <iostream>
#include <vector>
#include <string>
#include "Room.hpp"
#include "Person.hpp"

class Activity {

public:
	Activity(Room*, Person*, const std::string);
	virtual ~Activity(){}
	
	virtual void startActivity() {}
	const std::string getDescription()const;

protected:
	Room* mLocation;
	Person* mOwner;
	std::string mDescription;
};


#endif //ACTIVITY_HPP_