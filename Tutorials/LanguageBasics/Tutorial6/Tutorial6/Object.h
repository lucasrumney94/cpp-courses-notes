#pragma once
// Pragma once preprocessor directive
// if this object is already included, will not include it again

class Object
{
public:
	//set virtual so we can override in child classes
	virtual void BeginPlay();
};