#ifndef PERSONREPOSITORY_HPP_
#define PERSONREPOSITORY_HPP_


#include "Person.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Repository.hpp"


class PersonRepository : public Repository<Person> {
public:
	PersonRepository() {}


	Person* findByFullName(const std::string&, const std::string&);
	std::vector<Person*> findPersonsOfRole(Role::RoleType);
	std::vector<Person*> findStudentsInGroup(const int);

	int getPersonCount();

private:

};

#endif //PERSONREPOSITORY_HPP_