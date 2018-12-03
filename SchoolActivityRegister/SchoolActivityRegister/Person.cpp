#include "Person.hpp"

Person::Person(std::vector<int>CNP, std::string firstName, std::string lastName, std::string email): 
																									mFirstName(firstName),
																									mLastName(lastName),
																									mEmail(email)
{
	mCNP = CNP;
}

Person::Person(const Person & p)
{
	mCNP = p.mCNP;
	mFirstName = p.mFirstName;
	mLastName = p.mLastName;
	mEmail = p.mEmail;
}
void Person::addRole(Role * role)
{
	mRoles.push_back(role);
}
const bool Person::isStudent() const
{
	for (int i = 0; i < mRoles.size(); i++) {
		if (mRoles[i]->getType() == Role::STUDENT_ROLE)
			return true;
	}
	return false;
}
const bool Person::isTeacher() const
{
	for (int i = 0; i < mRoles.size(); i++) {
		if (mRoles[i]->getType() == Role::TEACHER_ROLE)
			return true;
	}
	return false;
}
const std::string& Person::getFirstName() const
{
	return mFirstName;
}
const std::string & Person::getLastName() const
{
	return mLastName;
}
const std::string & Person::getEmail() const
{
	return mEmail;
}
const int Person::getRoleCount() const
{
	return mRoles.size();
}
Role * Person::getStudentRole() const
{
	for (int i = 0; i < mRoles.size(); i++)	{
		if (mRoles[i]->getType() == Role::STUDENT_ROLE)
			return mRoles[i];
	}
}
Role * Person::getTeacherRole() const
{
	for (int i = 0; i < mRoles.size(); i++) {
		if (mRoles[i]->getType() == Role::TEACHER_ROLE)
			return mRoles[i];
	}
}
std::vector<Role*> Person::getRoles() const
{
	return mRoles;
}
/*
void Person::addTeacherRole(const std::vector<std::string> courses)
{
	mRoles.push_back(new TeacherRole(courses));
}

void Person::addStudentRole(int group, std::string specialisation, int nrCourses)
{
	mRoles.push_back(new StudentRole(group, specialisation, nrCourses));
}
*/
std::istream & operator>>(std::istream & in, Person & p)
{
	std::string sCNP;
	in >> sCNP;
	for (int i = 0; i < 13; i++) {
		p.mCNP.push_back((int)(sCNP.at(i)-48));
	}
	in >> p.mFirstName;
	in >> p.mLastName;
	in >> p.mEmail;

	return in;
}

std::ostream & operator<<(std::ostream & out, Person & p)
{
	out << "CNP:";
	for (int i = 0; i < 13; i++) {
		out << p.mCNP[i];
	}

	out << "\nName: " << p.mLastName << " " << p.mFirstName<<'\n';
	out << "Email: " << p.mEmail << "\n";

	return out;
}
