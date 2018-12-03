#include "Role.hpp"

Role::Role(RoleType type) : mType(type)
{
}

const Role::RoleType Role::getType() const
{
	return mType;
}
