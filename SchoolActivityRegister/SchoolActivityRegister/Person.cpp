#include "Person.hpp"

Person::Person(const std::vector<Role*> roles, std::vector<int>CNP, std::string firstName, std::string lastName, std::string email):
																									mRoles(roles),
																									mCNP(CNP),
																									mFirstName(firstName),
																									mLastName(lastName),
																									mEmail(email)
{
}

Person::Person(const Person *person, const std::vector<Role*> roles):
																	mCNP(person->mCNP),
																	mFirstName(person->mFirstName),
																	mLastName(person->mLastName),
																	mEmail(person->mEmail),
																	mRoles(roles)
{
}

void Person::addRole(Role * role)
{
	mRoles.push_back(role);
}
void Person::deleteStudentRole()
{
	for (int i = 0; i < mRoles.size(); i++) {
		if (mRoles[i]->getType() == Role::STUDENT_ROLE) {
			delete mRoles[i];
			mRoles.erase(mRoles.begin() + i, mRoles.begin() + i + 1);
		}
	}
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
StudentRole * Person::getStudentRole() const
{
	for (int i = 0; i < mRoles.size(); i++)	{
		if (mRoles[i]->getType() == Role::STUDENT_ROLE)
			return dynamic_cast<StudentRole*>(mRoles[i]);
	}
	return nullptr;
}
TeacherRole * Person::getTeacherRole() const
{
	for (int i = 0; i < mRoles.size(); i++) {
		if (mRoles[i]->getType() == Role::TEACHER_ROLE)
			return dynamic_cast<TeacherRole*>(mRoles[i]);
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
