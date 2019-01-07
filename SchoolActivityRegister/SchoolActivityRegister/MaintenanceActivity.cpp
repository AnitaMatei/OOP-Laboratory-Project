#include "MaintenanceActivity.hpp"

MaintenanceActivity::MaintenanceActivity(Room *location, Person *owner, std::string description) :
	Activity(location, owner, description),
	onGoing(false)
{
}

void MaintenanceActivity::startActivity()
{
	if (mOwner->getServiceRole() != nullptr) {
		Room* currentRoom = ((Activity*)this)->getLocation();
		if (currentRoom->isFree()) {
			std::cout << "\"" << mDescription << "\" " << "maintenance activity has started in " + currentRoom->getName() + "." << std::endl;
			onGoing = true;
		}
		else if (!currentRoom->isFree()) {
			std::cout << "\"" << mDescription << "\" " << "maintenance activity can't start because " + currentRoom->getName() + " is busy at the moment." << std::endl;
		}
	}
	else {
		std::cout << mOwner->getFirstName()+mOwner->getLastName() << " can't coordinate maintenance activities." << std::endl;
	}
}

void MaintenanceActivity::fixRoom()
{
	if (!mLocation->isUseable())
	{
		std::cout << "The problems in the room " + mLocation->getName() << " have been fixed."<<std::endl;
		mLocation->setUseable(true);
	}
	else {
		std::cout << "The room " + mLocation->getName() << " is already perfectly working." << std::endl;
	}

}

void MaintenanceActivity::addCapacity(const int additionalCapacity)
{
	if (mLocation->getType() == Room::AMPHITHEATER_ROOM) {
		std::cout << "Amphitheaters can't have their capacity increased." << std::endl;
	}
	else {
		mLocation->addCapacity(additionalCapacity);
		std::cout << "The capacity in the room " + mLocation->getName() << " has been increased by "<<additionalCapacity<< " new spots." << std::endl;
	}
}

void MaintenanceActivity::endActivity()
{
	if (onGoing) {
		std::cout << "Maintenance in the room " + mLocation->getName() << " has ended." << std::endl;
		onGoing = false;
	}
	else {
		std::cout << "Maintenance in the room " + mLocation->getName() << " can't end because it hasn't started." << std::endl;
	}

}
