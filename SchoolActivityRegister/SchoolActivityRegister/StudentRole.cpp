#include "StudentRole.hpp"


StudentRole::StudentRole(int group, std::string specialisation, const std::vector<Discipline*> disciplines) :Role(STUDENT_ROLE),
mGroup(group),
mSpecialisation(specialisation),
mDisciplines(disciplines)
{

}

void StudentRole::addDiscipline(Discipline *discipline)
{
	mDisciplines.push_back(discipline);
}

const int StudentRole::getGroup() const
{
	return mGroup;
}

std::vector<Discipline*> StudentRole::getDisciplines() const
{
	return mDisciplines;
}
