#ifndef STUDENTROLE_HPP_
#define STUDENTROLE_HPP_

#include "Role.hpp"
#include "Discipline.hpp"
#include <iostream>
#include <vector>
#include <string>
#include "Discipline.hpp"

class StudentRole : public Role {

public:
	StudentRole(const int = 0, const std::string = "", const std::vector<Discipline*> = {});

	void addDiscipline(Discipline*);

	const int getGroup() const;
	std::vector<Discipline*> getDisciplines() const;


private:
	int mGroup;
	std::string mSpecialisation;
	int mNrCourses;
	std::vector<Discipline*> mDisciplines;

};


#endif //STUDENTROLE_HPP_