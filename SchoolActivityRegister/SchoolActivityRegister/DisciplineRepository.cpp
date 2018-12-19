#include "DisciplineRepository.hpp"

Discipline * DisciplineRepository::getDisciplineBySubjectName(const std::string &subjectName)
{
	for (int i = 0; i < mEntities.size(); i++) {
		if (mEntities[i]->getSubjectName() == subjectName) {
			return new Discipline(*mEntities[i]);
		}
	}
}

std::vector<Discipline*> DisciplineRepository::getDisciplinesByGroup(const int group)
{
	std::vector<Discipline*> temp;
	for (int i = 0; i < mEntities.size(); i++) {
		if (mEntities[i]->getGroup() == group) {
			temp.push_back(new Discipline(*mEntities[i]));
		}
	}
	return temp;
}

std::vector<Discipline*> DisciplineRepository::getDisciplinesBySpecialization(const std::string &specialization)
{
	std::vector<Discipline*> temp;
	for (int i = 0; i < mEntities.size(); i++) {
		if (mEntities[i]->getSpecialization() == specialization) {
			temp.push_back(new Discipline(*mEntities[i]));
		}
	}
	return temp;
}

std::vector<Discipline*> DisciplineRepository::getDisciplinesBySubject(const std::string &subject)
{
	std::vector<Discipline*> temp;
	for (int i = 0; i < mEntities.size(); i++) {
		if (mEntities[i]->getSubject() == subject) {
			temp.push_back(new Discipline(*mEntities[i]));
		}
	}
	return temp;
}
