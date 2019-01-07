#ifndef MAINTENANCEACTIVITY_HPP_
#define MAINTENANCEACTIVITY_HPP_

#include <string>
#include <iostream>
#include "Activity.hpp"

class MaintenanceActivity:public Activity {

public:
	MaintenanceActivity(Room*, Person*, const std::string);
	virtual ~MaintenanceActivity() {}

	void startActivity();
	void fixRoom();
	void addCapacity(const int);
	void endActivity();

private:
	bool onGoing;
};

#endif //MAINTENANCE_ACTIVITY_HPP_