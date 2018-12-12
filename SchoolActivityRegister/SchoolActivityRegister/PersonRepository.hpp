#ifndef PERSONREPOSITORY_HPP_
#define PERSONREPOSITORY_HPP_


#include "Person.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>




class PersonRepository {
public:
	PersonRepository() {}

	void addPerson(Person*, std::vector<Role*>);	//a person can have multiple roles so we ask for a vector
	Person* findByFullName(const std::string&, const std::string&);
	std::vector<Person*> findPersonsOfRole(Role::RoleType);
	std::vector<Person*> findStudentsInGroup(const int);
	void deletePerson(Person*);

	int getPersonCount();

private:
	std::vector<Person*> persons;

};

#endif //PERSONREPOSITORY_HPP_