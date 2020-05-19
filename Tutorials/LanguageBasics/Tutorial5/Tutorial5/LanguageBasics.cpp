#include<iostream>
#include<string>

class Object
{
public:
	//set virtual so we can override in child classes
	virtual void BeginPlay();
};

class Actor: public Object
{
public:
	// don't have to set virtual, its inherited, but it makes it clear for future
	// derived classes just so its clear. Just a reminder when we are other places in the code.
	// override also tells us explicitly that its an override, not required but good to have
	virtual void BeginPlay() override;
};

class Pawn : public Actor
{
public:
	virtual void BeginPlay() override;
};

class Animal
{
public:
	virtual void makeSound();

	void AnimalFunction()
	{
		std::cout << "AnimalFunction Called!" << std::endl;
	}
};
class Dog : public Animal
{
public:
	virtual void makeSound() override;


	void DogFunction()
	{
		std::cout << "DogFunction Called!" << std::endl;
	}
};
class Collie: public Dog
{
public:
	virtual void makeSound() override;
	void CollieFunction()
	{
		std::cout << "CollieFunction Called!" << std::endl;
	}
};

int main() {
	// METHOD OVERRIDING using virtual functions
	// OVERRIDING methods that exist in a parent class from a child class
	// virtuality of a method is inherited by a parent class
	// you don't have to mark a function as virtual in the child classes,
	// but doing that can make it more clear.
	// provide the word override to indicate that it is overriding a function from the parent class

	//Dynamically create a new Object
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
	// POLYMORPHISM
	// Treating a Child class as if it is a parent class.
	// Collie inherits from Dog inherits from Animal
	//Dynamically create an Animal
	Animal* ptrToAnimal = new Animal();
	Dog* ptrToDog = new Dog();
	Collie* ptrToCollie = new Collie();

	// We can treat each of these subclasses as their common parent class
	Animal* AnimalArray[] = {ptrToAnimal, ptrToDog, ptrToCollie};
	
	for (int i = 0; i < 3; i++) 
	{
		AnimalArray[i]->makeSound();
		// can't do this alone because Animal doesn't have a DogFunction
		//AnimalArray[i]->DogFunction();

		// access the ith element as an animal
		Animal* animal = AnimalArray[i];
		// try to cast it, if it fails it will return a null_ptr
		Dog* dog = dynamic_cast<Dog*>(animal);

		// if its a null_ptr this won't happen
		if (dog) 
		{
			// this will work for a DOG, and a Collie!
			// so this will happen twice!
			dog->DogFunction();
		}

		Collie* collie = dynamic_cast<Collie*>(animal);
		if (collie)
		{
			collie->CollieFunction();
		}

		std::cout << std::endl;

	}


	// MULTIPLE INHERITANCE
	// a child class can inherit from multiple parents
	// Diamond inheritance can cause an issue, and you have to specify the desired parent function
	// If you use virtual inheritance, you only get one set of the parent's functions
	// reading: https://isocpp.org/wiki/faq/multiple-inheritance#mi-needed

	std::cout << "---" << std::endl;

	// CASTING
	// IMPLICIT TYPE CONVERSION
	// When it happens behind the scenes;
	float f = 5.0;
	std::cout << f << std::endl;

	// 5.0 is implicitly converted to int, fractional portion is truncated 
	int i = f;
	std::cout << i << std::endl;

	// EXPLICIT TYPE CONVERSION
	// C-Style CASTING (not typical in C++ but still possible)
	// does not perform any kind of safety checks to see if the conversion is really possible
	// could result in garbage
	float d = 4.564;
	int j = (int)d;

	// DYNAMIC CASTING
	// Casting between objects that are in an inheritance chain
	// only works on polymorphic types - at least one virtual member function
	// UPCASTING is not necessary (casting from a child to a parent)
	// DOWNCASTING is a way to treat a something that is currently being treated 
	// as a parent (but is a child) back to a child 
	// CROSSCASTING is when sibling-classes are cast to each other. 
	// DYNAMIC CASTING requires runtime-type information to be supported.
	// (runtime type checking)
	
	// STATIC CAST
	// casting between types but does not perform runtime type checking
	// can be used with nonpolymorphic types in a derivation chain
	// can also used like c-style casts to cast between types

	// CONST cast
	// can cast from a const to a non-const variable 
	// safe if the original variable is a non-const type 
	
	// RE-INTERPRET CASE
	// most powerful, most dangerous
	// convert a pointer of any type to any other type with no type checking



	// clean up our dynamically created objects
	delete obj;
	delete actor;
	delete pawn;

	// delete dynamically created objects
	delete ptrToAnimal;
	delete ptrToDog;
	delete ptrToCollie;
}

void Object::BeginPlay()
{
	std::cout << "Object BeginPlay Called!" << std::endl;
}
void Actor::BeginPlay()
{
	// Can also call the BeginPlay() from Object by doing this
	Object::BeginPlay();

	std::cout << "Actor BeginPlay Called!" << std::endl;
}
void Pawn::BeginPlay()
{
	// Can also call the BeginPlay() from Object by doing this
	Object::BeginPlay();
	// Can also call the BeginPlay() from Actor by doing this CAREFUL - (this will call Object::BeginPlay twice!!)
	Actor::BeginPlay();
	std::cout << "Pawn BeginPlay Called!" << std::endl;
}

void Animal::makeSound()
{
	std::cout << "Animal Make Sound Called!" << std::endl;
}
void Dog::makeSound()
{
	std::cout << "Dog Make Sound Called!" << std::endl;
}
void Collie::makeSound()
{
	std::cout << "Collie Make Sound Called!" << std::endl;
}