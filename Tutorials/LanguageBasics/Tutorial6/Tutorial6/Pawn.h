#pragma once
// Pragma once preprocessor directive
// if this object is already included, will not include it again
#include "Actor.h"

class Pawn : public Actor
{
public:
	virtual void BeginPlay() override;
};