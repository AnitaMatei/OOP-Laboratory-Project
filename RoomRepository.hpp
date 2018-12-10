#ifndef ROOMREPOSITORY_HPP_
#define ROOMREPOSITORY_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Room.hpp"
#include "Repository.hpp"


class RoomRepository : public Repository<Room> {

public:
	RoomRepository() {}
	
	Room* findByName(const std::string&);
	std::vector<Room*> findRoomsOfType(Room::RoomType);
	std::vector<Room*> findRoomsOfMinCapacity(const unsigned int);

private:

};



#endif //ROOMREPOSITORY_HPP_