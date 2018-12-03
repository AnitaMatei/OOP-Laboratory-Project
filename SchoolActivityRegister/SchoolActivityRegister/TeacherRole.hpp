#ifndef TEACHERROLE_HPP_
#define TEACHERROLE_HPP_

#include <iostream>
#include <vector>
#include <string>
#include "Role.hpp"

class TeacherRole : public Role {

public:
	TeacherRole(const std::vector<std::string> = {});


private:
	std::vector<std::string> mCourses;
};


#endif //TEACHERROLE_HPP_