#include "Actor.h"

void Actor::BeginPlay()
{
	// Can also call the BeginPlay() from Object by doing this
	Object::BeginPlay();

	std::cout << "Actor BeginPlay Called!" << std::endl;
}