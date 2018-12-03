#include <iostream>
#include "Person.hpp"
#include <vector>
#include "Room.hpp"
#include "Activity.hpp"
#include "Role.hpp"
#include "Person.hpp"
#include "PersonRepository.hpp"

using namespace std;


/*


		Person [vector<Role*> mRoles, ]


		Activity  [Room* mLocation, Person* ]

		Room [string nume]


		Role
	/			|				|				\
	StudentRole  GuestRole		TeacherRole		AdministrativeRole


*/




int main() {
	vector<Room*> rooms;
	rooms.push_back(new Room("Amfiteatru Haret", 100));
	rooms.push_back(new Room("Amfiteatru Pompeiu", 50));
	rooms.push_back(new Room("Lab 310", 30));

	StudentRole *sr=new StudentRole(252, "CTI", 7);
	TeacherRole *tr=new TeacherRole({ "POO" });
	StudentRole *sr2 = new StudentRole(501, "Ceva", 3);

	vector<Person*> persoane;
	persoane.push_back(new Person({ 1 }, "Anita", "Matei", "chidosir94@gmail.com"));
	persoane.push_back(new Person({ 2 }, "Stefan", "Rapeanu", "sr@sr.sr"));

	persoane[0]->addRole(sr);
	persoane[1]->addRole(sr2);
	persoane[1]->addRole(tr);

	Activity *activitate = new Activity(*rooms[2], *persoane[1],"Laborator POO");

	PersonRepository pr;

	pr.addPerson(new Person({ 1 }, "Anita", "Matei", "chidosir94@gmail.com"), { new StudentRole(252, "CTI", 7) });
	pr.addPerson(new Person({ 1 }, "Coman", "Valentin", "cv@cv.cv"), { new StudentRole(252,"CTI",7) });
	pr.addPerson(new Person({ 2 }, "Stefan", "Rapeanu", "sr@sr.sr"), { new TeacherRole({ "POO" }),new StudentRole(501, "Ceva", 3) });

	vector<Person*> personsIn252 = pr.findPersonsOfRole(Role::STUDENT_ROLE);
	pr.deletePerson(&pr.findByFullName("Anita", "Matei"));



	system("pause");
	return 0;
}