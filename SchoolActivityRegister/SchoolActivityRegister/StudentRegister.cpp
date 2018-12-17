#include "StudentRegister.hpp"

void StudentRegister::addToRegister(StudentRole *studentRole, subjectNames subjects)
{
	mStudents.push_back(studentRole);
	mSubjects.push_back(subjects);
	grades tempGrades;
	tempGrades.push_back({ {} });
	mGrades.push_back(tempGrades);
}

void StudentRegister::addEntries(const std::vector<ActivityEntry*> &activityEntry, const std::string subjectName)
{
	for (int i = 0; i < activityEntry.size(); i++) {
		int studentIndex=-1;
		int subjectIndex=-1;
		for (int j = 0; j < mStudents.size(); j++) {
			if (mStudents[j] == activityEntry[i]->getPerson()->getStudentRole()) {
				studentIndex = j;
			}
		}
		
		for (int k = 0; k < mSubjects[studentIndex].size(); k++) {
			if (mSubjects[studentIndex][k] == subjectName) {
				subjectIndex = k;
			}
		}

		if(studentIndex!=-1 && subjectIndex!=-1)
			mGrades[studentIndex][subjectIndex].push_back(activityEntry[i]->getGrade());
	}
}
