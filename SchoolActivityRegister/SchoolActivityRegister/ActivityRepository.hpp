#ifndef ACTIVITYREPOSITORY_HPP_
#define ACTIVITYREPOSITORY_HPP_

#include "Activity.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Repository.hpp"

class ActivityRepository : public Repository<Activity> {

public:
	ActivityRepository() {}

	Activity* getActivityByDesc(const std::string);

private:

};

#endif //ACTIVITYREPOSITORY_HPP_
