#include "PersonRepository.hpp"

void PersonRepository::addPerson(Person* person, std::vector<Role*> roles)
{
	persons.push_back(person);
	for(int i=0;i<roles.size();i++)
		persons[persons.size() - 1]->addRole(roles[i]);
}

Person& PersonRepository::findByFullName(const std::string& firstName, const std::string& lastName)
{
	for (int i = 0; i < persons.size(); i++) {
		if (!(persons[i]->getFirstName()).compare(firstName) && !(persons[i]->getLastName()).compare(lastName))
			return *persons[i];
	}
}

std::vector<Person*> PersonRepository::findPersonsOfRole(Role::RoleType type)
{
	std::vector<Person*> personsofRole;
	std::vector<Role*> tempRoles;
	for (int i = 0; i < persons.size(); i++) {
		tempRoles = persons[i]->getRoles();
		for (int j = 0; j < tempRoles.size(); j++)
			if (tempRoles[j]->getType() == type) {
				personsofRole.push_back(persons[i]);
				break;
			}
	}
	return personsofRole;
}

std::vector<Person*> PersonRepository:: findStudentsInGroup(const int group)
{
	std::vector<Person*> studentsInGroup;
	for (int i = 0; i < persons.size(); i++) {
		StudentRole* temp = dynamic_cast<StudentRole*>(persons[i]->getStudentRole());
		if (persons[i]->isStudent() && temp->getGroup()==group)
			studentsInGroup.push_back(persons[i]);
	}
	return studentsInGroup;
}

void PersonRepository::deletePerson(Person *person)
{
	persons.erase(std::remove(persons.begin(), persons.end(), person), persons.end());
}

int PersonRepository::getPersonCount()
{
	return persons.size();
}
