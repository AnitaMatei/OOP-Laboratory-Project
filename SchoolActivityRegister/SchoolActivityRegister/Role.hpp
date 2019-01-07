#ifndef ROLE_HPP_
#define ROLE_HPP_

#include <iostream>
#include <string>

class Role {
public:
	enum RoleType{STUDENT_ROLE,
					TEACHER_ROLE,SERVICE_ROLE};
	Role(RoleType type);
	virtual ~Role() {}		//making it a polymorphic class to be able to use dynamic_cast<>

	const RoleType getType() const;

protected:
	RoleType mType;
};










#endif //ROLE_HPP_
