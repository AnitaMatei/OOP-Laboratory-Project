#include "RoomRepository.hpp"


Room* RoomRepository::findByName(const std::string &name)
{
	for (int i = 0; i < mEntities.size(); i++)
		if (mEntities[i]->getName() == name)
			return mEntities[i];
}

std::vector<Room*> RoomRepository::findRoomsOfType(Room::RoomType type)
{
	std::vector<Room*> temp;
	for (int i = 0; i < mEntities.size(); i++)
		if (mEntities[i]->getType() == type)
			temp.push_back(mEntities[i]);
	return temp;
}

std::vector<Room*> RoomRepository::findRoomsOfMinCapacity(const unsigned int capacity)
{
	std::vector<Room*> temp;
	for (int i = 0; i < mEntities.size(); i++)
		if (mEntities[i]->getCapacity() >= capacity)
			temp.push_back(mEntities[i]);
	return temp;
}
