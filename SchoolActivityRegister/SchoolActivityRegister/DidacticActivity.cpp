#include "DidacticActivity.hpp"

DidacticActivity::DidacticActivity(Room *location, Person *owner, std::string description):
	Activity(location,owner,description)
{
}

void DidacticActivity::addGrade(const std::string firstName, const std::string lastName, const int grade)
{
	for (int i = 0; i < mActivityEntries.size(); i++) {
		if (mActivityEntries[i]->getPerson()->getFirstName() == firstName && mActivityEntries[i]->getPerson()->getLastName()==lastName) {
			mActivityEntries[i]->addGrade(grade);
			return;
		}
	}
}

void DidacticActivity::startActivity(std::vector<Person*> participants, std::vector<bool> presences)
{
	for (int i = 0; i < presences.size(); i++) {
		mActivityEntries.push_back(new ActivityEntry(participants[i]));
		if (presences[i] == true) {
			mActivityEntries[i]->isPresent();
		}
	}
}

void DidacticActivity::endActivity(StudentRegister &studentRegister)
{
	studentRegister.addEntries(mActivityEntries, mDescription);
	while (mActivityEntries.size() > 0) {
		mActivityEntries.pop_back();
	}
}

