#ifndef DISCIPLINEREPOSITORY_HPP_
#define DISCIPLINEREPOSITORY_HPP_

#include "Repository.hpp"
#include "Discipline.hpp"
#include <string>

class DisciplineRepository : public Repository<Discipline> {

public:
	DisciplineRepository(){}

	Discipline* getDisciplineBySubjectName(const std::string&);

	std::vector<Discipline*> getDisciplinesByGroup(const int);
	std::vector<Discipline*> getDisciplinesBySpecialization(const std::string&);
	std::vector<Discipline*> getDisciplinesBySubject(const std::string&);



private:


};

#endif //DISCIPLINEREPOSITORY_HPP_
