#ifndef DISCIPLINE_HPP_
#define DISCIPLINE_HPP_

#include <vector>
#include <string>

class Discipline {
	
public:

	enum DisciplineType { COURSE, LABORATORY, SEMINARY };

	Discipline(const std::string&, const DisciplineType, const std::string&, const int=-1);
	Discipline(const Discipline&);

	void addGrade(const int);
	void addPresence();

	const std::string getSubjectName() const;
	const std::string getSubject() const;
	const std::string getSpecialization() const;
	const int getGroup() const;
	std::vector<int> getGrades() const;
	const int getPresences() const;

private:
	std::string mSubject;
	std::vector<int> mGrades;
	int mPresences;
	DisciplineType mType;
	/*
	Depending on the type of discipline, discipline will have only a specialisation (COURSE) or both a specialisation and a group (SEMINARY, LABORATORY)  
	*/
	std::string mSpecialization;
	int mGroup;		//-1 means there is no group assigned


};




#endif //DISCIPLINE_HPP_