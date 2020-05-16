#include "Pawn.h"

void Pawn::BeginPlay()
{
	// Can also call the BeginPlay() from Object by doing this
	Object::BeginPlay();
	// Can also call the BeginPlay() from Actor by doing this CAREFUL - (this will call Object::BeginPlay twice!!)
	Actor::BeginPlay();
	std::cout << "Pawn BeginPlay Called!" << std::endl;
}