#include "Activity.hpp"

Activity::Activity(Room * location, Person * owner, std::string description):
	mDescription(description),
	mLocation(location),
	mOwner(owner)
{
}
