#include "Object.h"
#include "Actor.h"
#include "Pawn.h"

int main()
{
	Object* obj = new Object;
	obj->BeginPlay();

	// separator
	std::cout << "---" << std::endl;
	Actor* actor = new Actor;
	actor->BeginPlay();

	// separator
	std::cout << "---" << std::endl;
	Pawn* pawn = new Pawn;
	pawn->BeginPlay();

	std::cout << "---" << std::endl;
}