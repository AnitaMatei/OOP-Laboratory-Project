#include "StudentRegister.hpp"

void StudentRegister::addToRegister(Person *student)
{
	mStudents.push_back(student);
}

void StudentRegister::addEntries(const std::vector<ActivityEntry*> &activityEntries, const std::string subjectName)
{

	std::vector<Discipline*> disciplines;
	for (int i = 0; i < activityEntries.size(); i++) {
		const Person* person = activityEntries[i]->getPerson();
		disciplines = activityEntries[i]->getPerson()->getStudentRole()->getDisciplines();
		for (int j = 0; j < disciplines.size(); j++) {
			if (disciplines[j]->getSubjectName() == subjectName) {
				if (activityEntries[i]->getGrade() != 0) {
					disciplines[j]->addGrade(activityEntries[i]->getGrade());
				}
				if (activityEntries[i]->getPresence())
					disciplines[j]->addPresence();
				break;
			}
		}
	}
}

void StudentRegister::updateStudents()
{
	for (int i = 0; i < mStudents.size(); i++) {
		if (mStudents[i]->getStudentRole() == nullptr) {
			std::cout << mStudents[i]->getFirstName() + " " + mStudents[i]->getLastName() << " has been removed from the register as he isn't a student anymore." << std::endl;
			mStudents.erase(mStudents.begin() + i);
			return;
		}
	}
}

std::ostream & operator<<(std::ostream &out, StudentRegister &studentRegister)
{
	for (int i = 0; i < studentRegister.mStudents.size(); i++) {
		out << studentRegister.mStudents[i]->getFirstName()+" "+ studentRegister.mStudents[i]->getLastName() << " has the following grades and presences at these subjects: ";
		std::vector<Discipline*> disciplines = dynamic_cast<StudentRole*>(studentRegister.mStudents[i]->getStudentRole())->getDisciplines();
		for (int j = 0; j < disciplines.size(); j++) {
			out << std::endl << '\t' << disciplines[j]->getSubjectName() + ":" << std::endl;
			out << '\t' << '\t' << "Grades: ";
			std::vector<int> grades = disciplines[j]->getGrades();
			for (int k = 0; k < grades.size(); k++) {
				out << grades[k]<<" ";
			}
			out << std::endl << '\t' << '\t' << "Presences: " << disciplines[j]->getPresences()<<std::endl;
		}
	}
	return out;
}
