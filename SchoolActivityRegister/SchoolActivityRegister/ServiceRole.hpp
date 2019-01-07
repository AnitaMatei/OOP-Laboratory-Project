#ifndef SERVICEROLE_HPP_
#define SERVICEROLE_HPP_

#include "Role.hpp"
#include <iostream>
#include <vector>
#include <string>
class ServiceRole : public Role {

public:
	ServiceRole(const std::string);


private:
	std::string mJobDescription;

};
#endif //SERVICEROLE_HPP_