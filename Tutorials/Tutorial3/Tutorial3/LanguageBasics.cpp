#include<iostream>
#include<string>


class Animal
{
	// members of a class are default private
public:
	Animal();
	Animal(std::string name, int age, int numberOfLimbs);
	std::string Name;
	int Age;
	int NumberOfLimbs;

	void Report();
};

// Dog inherits from Animal
class Dog : public Animal
{
public:
	Dog();
	Dog(std::string name, int age, int numberOfLimbs);

	void Speak();
};

class Corgi : public Dog 
{
public:
	void Waddle();

};

class Creature
{
public:
	Creature();
	void SetName(std::string name);
	std::string GetName();
	float GetHealth();

	void TakeDamage(float damage);

private:
	std::string Name;
	float Health;

protected: 
	int NumberOfLimbs;

};

class Goblin : public Creature // public, so inherits all the same ACCESS MODIFIERS from Creature
{
public:
	// constructor needs to be public to be able to instantiate class
	Goblin();
};

int main() 
{
	// CLASS Initialization
	// Use the parameterless constructor
	Animal animal;
	animal.Report();

	// use this specific constructor
	Animal animal2("Cheetah", 7, 5);


	// INHERITANCE

	// Dog has a default provided constructor if none is provided
	// and also the parameterless parent constructor is invoked
	Dog spot;

	std::cout << "------" << std::endl;


	// if we call this, it will call the constructor on animal that takes NO input parameters
	// then the constructor on dog that takes 3 input parameters
	// and then call the Animal constructor with 3 input parameters explicitly
	// 3 constructors are called. 
	// We then changed the Dog Constructor to use the 3 argument parent constructor, 
	// so now only 2 constructors are called.
	Dog Rex("Rex", 4, 5);

	Rex.Speak();

	std::cout << "------" << std::endl;


	// Useful to inherit base functionality, and then specify corgi-specific functionality.
	Corgi myCorgi;
	myCorgi.Speak();
	myCorgi.Report();
	myCorgi.Waddle();
	// CORGI is a DOG, and a DOG is an ANIMAL
	// An ANIMAL is NOT a CORGI, in other words 
	// this relationship is uni-directional and heirarchical

	std::cout << "------" << std::endl;
	std::cout << "------" << std::endl;

	// ACCESS MODIFIERS
	// inside a class, defines sections of methods and members
	// private: (defaults to private)
	// cannot access outside, only inside the class
	// public:
	// everything in this section is accessible outside the class
	// protected:
	// only accessible from within the class, or a derived class. (child classes)
	// ACCESS MODIFIERs are inherited if public is used in the inheritance
	// if protected, all public in parent become protected, all protected stay protected, 
	// if private, all public become private, all protected become private
	// usually always use public, to inherit the access modifiers.
	// can have as many sections as you want.
	

	Creature Igor;
	// Can't do this because Name is private
	// Igor.Name = "Igor";
	// private variables should be accessible through a getter/setter methods that 
	// can validate the changes, and avoid invalid data or states
	// providing getter and setter methods is called "Encapsulation"

	// use the setter to set the name
	Igor.SetName("Igor");
	// use the getter to get the name
	std::cout << "Name: " << Igor.GetName() << std::endl;

	std::cout << "Health: " << Igor.GetHealth() << std::endl;

	std::cout << "Igor will take 5.0 damage now!" << std::endl;
	Igor.TakeDamage(5.0);

	std::cout << "Igor will take 100.0 damage now!" << std::endl;
	Igor.TakeDamage(100.0);
	std::cout << "Health: " << Igor.GetHealth() << std::endl;

	std::cout << "------" << std::endl;

	Goblin gobby;
	std::cout << "Name: " << gobby.GetName() << std::endl;


}

// Defining the constructor outside of the class declaration
Animal::Animal()
{
	std::cout << "An Animal is born!" << std::endl;
	Name = "DEFAULT";
	Age = 2;
	NumberOfLimbs = 4;
}

//Overload the constructor and match the function declaration
//Animal::Animal(std::string name, int age, int numberOfLimbs) 
//{
//	Name = name;
//	Age = age;
//	NumberOfLimbs = numberOfLimbs;
//}

// Instead we can do this, "Initializer list method", can return after colon for formatting
Animal::Animal(std::string name, int age, int numberOfLimbs)
	: Name(name), Age(age), NumberOfLimbs(numberOfLimbs)
{
	Report();
}

void Animal::Report() 
{
	std::cout << std::endl;
	std::cout << "Name: " << Name << std::endl;
	std::cout << "Age: " << Age << std::endl;
	std::cout << "Number of limbs: " << NumberOfLimbs << std::endl;
}

Dog::Dog() 
{
	std::cout << "A Dog is born" << std::endl;
}

// If we only want a specific constructor on the parent class, we need to use this specific syntax
// This will ensure 2 constructors are called, this one, and the specific parent one
// if the Animal constructor is inside the body, the default parameterless Animal constructor would
// also be called.
Dog::Dog(std::string name, int age, int numberOfLimbs): Animal(name, age, numberOfLimbs)
{
	
}

void Dog::Speak()
{
	std::cout << "Woof!" << std::endl;
}

void Corgi::Waddle()
{
	std::cout << "waddle waddle" << std::endl;

}

Creature::Creature()
{
	Health = 100.f;
	std::cout << "A Creature has been instantiated!" << std::endl;
}

// Setter
void Creature::SetName(std::string name)
{
	Name = name;
}

// Getter
std::string Creature::GetName()
{
	return Name;
}
float Creature::GetHealth() 
{
	return Health;
}
void Creature::TakeDamage(float damage) 
{
	if (damage > Health) 
	{
		Health = 0.0f;
		std::cout << GetName() << " has died!" << std::endl;
	}
	else
	{
		Health -= damage;
		std::cout << GetName() << " has " << GetHealth() << " health left." <<std::endl;
	}
}

Goblin::Goblin()
{
	// has access to protected variables in the Creature class
	NumberOfLimbs = 5;

	// private is inaccessible from child class
	// This will not work
	// Name = "Gobby";
	// instead we can use setter
	SetName("Gobby");
}