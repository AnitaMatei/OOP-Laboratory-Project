#ifndef ROOM_HPP_
#define ROOM_HPP_


#include <iostream>
#include <vector>
#include <string>

class Room {

public:
	enum RoomType {AMPHITHEATER_ROOM,
				LABORATORY_ROOM,
				SEMINARY_ROOM
	};

	Room(const std::string, const unsigned int, const RoomType);

	const std::string& getName() const;
	const unsigned int getCapacity() const;
	const RoomType getType() const;


protected:
	std::string mName;
	unsigned int mCapacity;
	RoomType mType;
};

#endif //ROOM_HPP_