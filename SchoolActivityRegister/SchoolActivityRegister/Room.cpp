#include "Room.hpp"

Room::Room(std::string name, unsigned int capacity, const RoomType type) :mName(name),
mCapacity(capacity),
mType(type)
{
}

const std::string & Room::getName() const
{
	return mName;
}

const unsigned int Room::getCapacity() const
{
	return mCapacity;
}

const Room::RoomType Room::getType() const
{
	return mType;
}
