#ifndef DIDACTICACTIVITY_HPP_
#define DIDACTICACTIVITY_HPP_

#include "Activity.hpp"
#include "ActivityEntry.hpp"
#include "StudentRegister.hpp"

class DidacticActivity : public Activity{
public:

	DidacticActivity(Room*, Person*, const std::string);
	virtual ~DidacticActivity() {}
	
	void addGrade(const std::string, const std::string, const int);
	void startActivity(std::vector<Person*>, std::vector<bool>);
	void endActivity(StudentRegister&);

private:
	bool onGoing;
	std::vector<ActivityEntry*> mActivityEntries;	

};

#endif //DIDACTICACTIVITY_HPP_