#ifndef REPOSITORY_HPP_
#define REPOSITORY_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


template <typename Entity>
class Repository {
public:
	Repository(){}
	~Repository();

	void add(Entity*);
	void remove(Entity*);

protected:
	std::vector<Entity*> mEntities;

};


#endif //REPOSITORY_HPP

template<typename Entity>
inline Repository<Entity>::~Repository()
{
	for (int i = 0; i < mEntities.size(); i++) {
		delete mEntities[i];
	}
}

template<typename Entity>
inline void Repository<Entity>::add(Entity *entity)
{
	mEntities.push_back(entity);
}

template<typename Entity>
inline void Repository<Entity>::remove(Entity *entity)
{
	mEntities.erase(std::remove(mEntities.begin(), mEntities.end(), entity), mEntities.end());
}
