#ifndef STUDENTREGISTER_HPP_
#define STUDENTREGISTER_HPP_

#include "StudentRole.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
#include "ActivityEntry.hpp"

class StudentRegister {

	typedef std::vector<std::string> subjectNames;
	typedef std::vector<std::vector<int>> grades;
	typedef std::vector<int> presences;

public:
	StudentRegister() {}

	void addToRegister(StudentRole*, subjectNames);

	void addEntries(const std::vector<ActivityEntry*>&, const std::string);

	friend std::ostream& operator<<(std::ostream&, StudentRegister&);

private:
	std::vector<StudentRole*> mStudents;
	std::vector<subjectNames> mSubjects;
	std::vector<grades> mGrades;
	std::vector<presences> mPresences;
};



#endif //STUDENTREGISTER_HPP_
