#ifndef ACTIVITYENTRY_HPP_
#define ACTIVITYENTRY_HPP_

#include "Person.hpp"
#include <string>

class ActivityEntry {
public:
	ActivityEntry(Person*);

	void addGrade(const int);
	void isPresent();

	const Person* getPerson() const;
	const int getGrade() const;

private:
	bool mPresence;
	int mGrade;
	Person* mPerson;

};

#endif //ACTIVITYENTRY_HPP_