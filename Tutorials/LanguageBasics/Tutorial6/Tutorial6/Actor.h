#pragma once
// Pragma once preprocessor directive
// if this object is already included, will not include it again
#include "Object.h"
#include <iostream>

class Actor : public Object
{
public:
	virtual void BeginPlay() override;
};