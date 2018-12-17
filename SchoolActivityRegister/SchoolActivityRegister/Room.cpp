#include "Room.hpp"

Room::Room(std::string name, unsigned int capacity, const RoomType type) :mName(name),
mCapacity(capacity),
mType(type),
mUseable(true)
{
}


const std::string Room::getName() const
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

const bool Room::isUseable() const
{
	return mUseable;
}

const void Room::setUseable(bool useable)
{
	mUseable = useable;
}

const bool Room::isFree() const
{
	return mAvailable;
}

const void Room::setAvailability(bool available)
{
	mAvailable = available;
}
