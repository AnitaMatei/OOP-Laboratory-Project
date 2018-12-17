#include "ActivityEntry.hpp"

ActivityEntry::ActivityEntry(Person * person):
	mPresence(false),
	mPerson(person)
{
}

void ActivityEntry::addGrade(const int grade)
{
	mGrade = grade;
}

void ActivityEntry::isPresent()
{
	mPresence = true;
}

const Person * ActivityEntry::getPerson() const
{
	return mPerson;
}

const int ActivityEntry::getGrade() const
{
	return mGrade;
}

const bool ActivityEntry::getPresence() const
{
	return mPresence;
}
