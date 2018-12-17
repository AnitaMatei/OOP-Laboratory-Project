#include "StudentRegister.hpp"

void StudentRegister::addToRegister(Person *studentRole, subjectNames subjects)
{
	mStudents.push_back(dynamic_cast<StudentRole*>(studentRole->getStudentRole()));
	mSubjects.push_back(subjects);
	mStudentNames.push_back(studentRole->getFirstName() + " " + studentRole->getLastName());

	std::cout <<mStudentNames[mStudentNames.size()-1]<< " has been added to the register with the subjects: ";

	grades tempGrades;
	presences tempPresences;
	for (int i = 0; i < mSubjects[mSubjects.size() - 1].size(); i++) {
		std::cout << mSubjects[mSubjects.size() - 1][i];
		if (i < mSubjects[mSubjects.size() - 1].size() - 1) {
			std::cout << ", ";
		}

		tempGrades.push_back({});
		tempPresences.push_back(0);
	}
	std::cout << std::endl;
	
	mGrades.push_back(tempGrades);
	mPresences.push_back(tempPresences);
}

void StudentRegister::addEntries(const std::vector<ActivityEntry*> &activityEntry, const std::string subjectName)
{
	for (int i = 0; i < activityEntry.size(); i++) {
		int studentIndex = -1;
		int subjectIndex = -1;
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


		if (studentIndex != -1 && subjectIndex != -1) {
			mGrades[studentIndex][subjectIndex].push_back(activityEntry[i]->getGrade());
			if (activityEntry[i]->getPresence()) {
				mPresences[studentIndex][subjectIndex]++;
			}
		}
	}
}

std::ostream & operator<<(std::ostream &out, StudentRegister &studentRegister)
{
	for (int i = 0; i < studentRegister.mStudents.size(); i++) {
		out << studentRegister.mStudentNames[i] << " has the following grades and presences at these subjects: ";
		for (int j = 0; j < studentRegister.mSubjects[i].size(); j++) {
			out << std::endl << '\t' << studentRegister.mSubjects[i][j] + ":" << std::endl;
			out << '\t' << '\t' << "Grades: ";
			for (int k = 0; k < studentRegister.mGrades[i][j].size(); k++) {
				out << studentRegister.mGrades[i][j][k];
			}
			out << std::endl << '\t' << '\t' << "Presences: " << studentRegister.mPresences[i][j]<<std::endl;
		}
	}
	return out;
}
