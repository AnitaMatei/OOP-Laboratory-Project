#ifndef PERSON_HPP_
#define PERSON_HPP_

#include <iostream>
#include <vector>
#include <string>
#include "Role.hpp"
#include "TeacherRole.hpp"
#include "StudentRole.hpp"

class Person {
public:
	Person(const std::vector<int> = {}, const std::string="", const std::string="", const std::string="");
	Person(const Person&);
	/*
	void addTeacherRole(std::vector<std::string>);
	void addStudentRole(const int = 0, const std::string = "", const int = 0);
	*/
	void addRole(Role*);


	friend std::istream& operator>>(std::istream&, Person&);
	friend std::ostream& operator<<(std::ostream&, Person&);

	const bool isStudent() const;
	const bool isTeacher() const;
	const std::string& getFirstName() const;
	const std::string& getLastName() const;
	const std::string& getEmail() const;
	const int getRoleCount() const;
	Role* getStudentRole() const;
	Role* getTeacherRole() const;
	std::vector<Role*> getRoles() const;

protected:
	std::vector<int> mCNP;
	std::string mFirstName;
	std::string mLastName;
	std::string mEmail;
	std::vector<Role*> mRoles;
};



#endif //PERSON_HPP_