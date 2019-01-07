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


	const std::string getName() const;
	const unsigned int getCapacity() const;
	const void addCapacity(const int);
	const RoomType getType() const;
	const bool isUseable() const;
	const void setUseable(bool);
	const bool isFree() const;
	const void setAvailability(bool);


protected:
	bool mUseable;		//if the room has problems or not
	bool mAvailable;			//if the room is used by another activity
	std::string mName;
	unsigned int mCapacity;
	RoomType mType;
};

#endif //ROOM_HPP_