#include "Discipline.hpp"
#include "ActivityEntry.hpp"

Discipline::Discipline(const std::string & subject,const DisciplineType type, const std::string& specialization, const int group):
	mSubject(subject),
	mPresences(0),
	mType(type),
	mSpecialization(specialization),
	mGroup(group)
{

}

Discipline::Discipline(const Discipline &discipline):
	mSubject(discipline.mSubject),
	mType(discipline.mType),
	mSpecialization(discipline.mSpecialization),
	mGroup(discipline.mGroup),
	mPresences(0)
{
}

void Discipline::addGrade(const int grade)
{
	mGrades.push_back(grade);
}

void Discipline::addPresence()
{
	mPresences++;
}

const std::string Discipline::getSubjectName() const
{
	std::string temp;
	switch (mType) {
	case COURSE:
		temp = "Course " + mSubject + " " + mSpecialization;
		break;
	case LABORATORY:
		temp = "Laboratory " + mSubject+ " " + std::to_string(mGroup);
		break;
	case SEMINARY:
		temp = "Seminary " + mSubject + " " + std::to_string(mGroup);
		break;
	}
	return temp;
}

const std::string Discipline::getSubject() const
{
	return mSubject;
}

const std::string Discipline::getSpecialization() const
{
	return mSpecialization;
}

const int Discipline::getGroup() const
{
	return mGroup;
}

std::vector<int> Discipline::getGrades() const
{
	return mGrades;
}

const int Discipline::getPresences() const
{
	return mPresences;
}
