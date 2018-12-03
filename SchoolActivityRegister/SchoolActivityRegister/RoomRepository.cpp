#include "RoomRepository.hpp"

void RoomRepository::addRoom(Room *room)
{
	rooms.push_back(room);
}

Room* RoomRepository::findByName(const std::string &name)
{
	for (int i = 0; i < rooms.size(); i++)
		if (rooms[i]->getName() == name)
			return rooms[i];
}

std::vector<Room*> RoomRepository::findRoomsOfType(Room::RoomType type)
{
	std::vector<Room*> temp;
	for (int i = 0; i < rooms.size(); i++)
		if (rooms[i]->getType() == type)
			temp.push_back(rooms[i]);
	return temp;
}

std::vector<Room*> RoomRepository::findRoomsOfMinCapacity(const unsigned int capacity)
{
	std::vector<Room*> temp;
	for (int i = 0; i < rooms.size(); i++)
		if (rooms[i]->getCapacity() >= capacity)
			temp.push_back(rooms[i]);
	return temp;
}

void RoomRepository::deleteRoom(Room *room)
{
	rooms.erase(std::remove(rooms.begin(), rooms.end(), room), rooms.end());
}
