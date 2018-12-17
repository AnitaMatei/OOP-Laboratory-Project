#ifndef STUDENTREGISTER_HPP_
#define STUDENTREGISTER_HPP_

#include "StudentRole.hpp"
#include <vector>
#include <algorithm>
#include "ActivityEntry.hpp"

class StudentRegister {

	typedef std::vector<std::string> subjectNames;
	typedef std::vector<std::vector<int>> grades;

public:
	StudentRegister() {}

	void addToRegister(StudentRole*, subjectNames);

	void addEntries(const std::vector<ActivityEntry*>&, const std::string);

private:
	std::vector<StudentRole*> mStudents;
	std::vector<subjectNames> mSubjects;
	std::vector<grades> mGrades;
};



#endif //STUDENTREGISTER_HPP_
