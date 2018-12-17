#include "DidacticActivity.hpp"

DidacticActivity::DidacticActivity(Room *location, Person *owner, std::string description):
	Activity(location,owner,description),
	onGoing(false)
{
}

void DidacticActivity::addGrade(const std::string firstName, const std::string lastName, const int grade)
{	
	if (onGoing) {
		for (int i = 0; i < mActivityEntries.size(); i++) {
			if (mActivityEntries[i]->getPerson()->getFirstName() == firstName && mActivityEntries[i]->getPerson()->getLastName() == lastName) {
				std::cout << firstName + " " + lastName << " received a " << grade << "." << std::endl;
				mActivityEntries[i]->addGrade(grade);
				return;
			}
		}
	}
	else {
		std::cout << firstName + " " + lastName << " can't receive a grade because the activity didn't start."<<std::endl;
	}
}

void DidacticActivity::startActivity(std::vector<Person*> participants, std::vector<bool> presences)
{
	Room* currentRoom = ((Activity*)this)->getLocation();
	if (currentRoom->isUseable() && currentRoom->isFree()) {
		std::cout << "\"" << mDescription << "\" " << "didactic activity has started in " + currentRoom->getName() + "." << std::endl;
		for (int i = 0; i < presences.size(); i++) {
			mActivityEntries.push_back(new ActivityEntry(participants[i]));
			if (presences[i] == true) {
				mActivityEntries[i]->isPresent();
			}
		}
		onGoing = true;
	}
	else if(!currentRoom->isUseable()){
		std::cout << "\"" << mDescription << "\" " << "didactic activity can't start because " + currentRoom->getName() + " is not useable at the moment." << std::endl;
	}
	else if (!currentRoom->isFree()) {
		std::cout << "\"" << mDescription << "\" " << "didactic activity can't start because " + currentRoom->getName() + " is busy at the moment." << std::endl;
	}
}

void DidacticActivity::endActivity(StudentRegister &studentRegister)
{
	if (onGoing) {
		std::cout << "\"" << mDescription << "\" " << "didactic activity has finished." << std::endl;
		studentRegister.addEntries(mActivityEntries, mDescription);
		while (mActivityEntries.size() > 0) {
			mActivityEntries.pop_back();
		}
		onGoing = false;
	}
	else {
		std::cout << "\"" << mDescription << "\" " << "didactic activity can't finish because it hasn't started." << std::endl;
	}
}

