#ifndef STUDENTREGISTER_HPP_
#define STUDENTREGISTER_HPP_

#include "StudentRole.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
#include "ActivityEntry.hpp"

class StudentRegister {

public:
	StudentRegister() {}

	void addToRegister(Person*);
	void addEntries(const std::vector<ActivityEntry*>&, const std::string);
	void updateStudents();

	friend std::ostream& operator<<(std::ostream&, StudentRegister&);

private:
	std::vector<Person*> mStudents;
};



#endif //STUDENTREGISTER_HPP_
