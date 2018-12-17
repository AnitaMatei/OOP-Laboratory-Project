#include "DidacticActivity.hpp"

DidacticActivity::DidacticActivity(Room *location, Person *owner, std::string description):
	Activity(location,owner,description)
{
}

void DidacticActivity::addGrade(const std::string firstName, const std::string lastName, const int grade)
{
	for (int i = 0; i < mActivityEntries.size(); i++) {
		if (mActivityEntries[i]->getPerson()->getFirstName() == firstName && mActivityEntries[i]->getPerson()->getLastName()==lastName) {
			std::cout << firstName +" "+lastName << " received a " << grade << "."<<std::endl;
			mActivityEntries[i]->addGrade(grade);
			return;
		}
	}
}

void DidacticActivity::startActivity(std::vector<Person*> participants, std::vector<bool> presences)
{
	std::cout << "\"" << mDescription << "\" " << "didactic activity has started." << std::endl;
	for (int i = 0; i < presences.size(); i++) {
		mActivityEntries.push_back(new ActivityEntry(participants[i]));
		if (presences[i] == true) {
			mActivityEntries[i]->isPresent();
		}
	}
}

void DidacticActivity::endActivity(StudentRegister &studentRegister)
{
	std::cout << "\"" << mDescription << "\" " << "didactic activity has finished." << std::endl;
	studentRegister.addEntries(mActivityEntries, mDescription);
	while (mActivityEntries.size() > 0) {
		mActivityEntries.pop_back();
	}
}

