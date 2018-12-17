#include "ActivityRepository.hpp"

Activity * ActivityRepository::getActivityByDesc(const std::string description)
{
	for (int i = 0; i < mEntities.size(); i++) {
		if (mEntities[i]->getDescription() == description) {
			return mEntities[i];
		}
	}
}
