#ifndef ROOMREPOSITORY_HPP_
#define ROOMREPOSITORY_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Room.hpp"

class RoomRepository {

public:
	RoomRepository() {}
	
	void addRoom(Room*);
	Room* findByName(const std::string&);
	std::vector<Room*> findRoomsOfType(Room::RoomType);
	std::vector<Room*> findRoomsOfMinCapacity(const unsigned int);
	void deleteRoom(Room*);

private:
	std::vector<Room*> rooms;

};



#endif //ROOMREPOSITORY_HPP_