#include "StudentRole.hpp"


StudentRole::StudentRole(int group, std::string specialisation, int nrCourses) :Role(STUDENT_ROLE),
mGroup(group),
mSpecialisation(specialisation),
mNrCourses(nrCourses)
{

}

const int StudentRole::getGroup() const
{
	return mGroup;
}
