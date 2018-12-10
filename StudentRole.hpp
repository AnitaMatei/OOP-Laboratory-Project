#ifndef STUDENTROLE_HPP_
#define STUDENTROLE_HPP_

#include "Role.hpp"
#include <iostream>
#include <vector>
#include <string>

class StudentRole : public Role {

public:
	StudentRole(const int = 0, const std::string = "", const int = 0);

	const int getGroup() const;


private:
	int mGroup;
	std::string mSpecialisation;
	int mNrCourses;

};


#endif //STUDENTROLE_HPP_