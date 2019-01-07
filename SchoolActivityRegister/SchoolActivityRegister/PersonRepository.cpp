#include "PersonRepository.hpp"


Person* PersonRepository::findByFullName(const std::string& firstName, const std::string& lastName)
{
	for (int i = 0; i < mEntities.size(); i++) {
		if (!(mEntities[i]->getFirstName()).compare(firstName) && !(mEntities[i]->getLastName()).compare(lastName))
			return mEntities[i];
	}
}

std::vector<Person*> PersonRepository::findPersonsOfRole(Role::RoleType type)
{
	std::vector<Person*> personsofRole;
	std::vector<Role*> tempRoles;
	for (int i = 0; i < mEntities.size(); i++) {
		tempRoles = mEntities[i]->getRoles();
		for (int j = 0; j < tempRoles.size(); j++)
			if (tempRoles[j]->getType() == type) {
				personsofRole.push_back(mEntities[i]);
				break;
			}
	}
	return personsofRole;
}

std::vector<Person*> PersonRepository:: findStudentsInGroup(const int group)
{
	std::vector<Person*> studentsInGroup;
	for (int i = 0; i < mEntities.size(); i++) {
		StudentRole* temp = dynamic_cast<StudentRole*>(mEntities[i]->getStudentRole());
		if (mEntities[i]->isStudent() && temp->getGroup()==group)
			studentsInGroup.push_back(mEntities[i]);
	}
	return studentsInGroup;
}

void PersonRepository::removeStudentByName(const std::string &firstName, const std::string &lastName)
{
	for (int i = 0; i < mEntities.size(); i++) {
		if (mEntities[i]->getFirstName() == firstName && mEntities[i]->getLastName()==lastName) {
			mEntities[i]->deleteStudentRole();
			notify();
			return;
		}
	}
}

void PersonRepository::addObserver(StudentRegister *studentRegister)
{
	mObserver = studentRegister;
}

void PersonRepository::notify()
{
	mObserver->updateStudents();
}


int PersonRepository::getPersonCount()
{
	return mEntities.size();
}
