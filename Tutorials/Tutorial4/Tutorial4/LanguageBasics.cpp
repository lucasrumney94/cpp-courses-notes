#include<iostream>
#include <string>

// STRUCTS
struct Character
{
	// create a constructor that I define, need to define if i declare
	Character();
	void PrintHealth();
	 
	std::string Name;
	float Health;

};

class Player
{
public:
	// Constructor
	Player();
	// Destructor
	~Player();

	int* PlayerAge;
	float* PlayerHealth;
};


void AddToCount()
{
	// subsequent initializations are ignored
	static int count = 0;
	count++;
	std::cout << count << std::endl;
}

class Item
{
public:
	Item()
	{
		std::cout << "An Item was instantiated" << std::endl;
	}
	~Item()
	{
		std::cout << "An Item was deleted" << std::endl;
	}
};

class Critter
{
public:
	Critter()
	{
		std::cout << "A Critter is instantiated!" << std::endl;
		CritterCount++;
	}
	static int CritterCount;
};
// initialize the static member outside of the class
// independent of instantiations of the class
int Critter::CritterCount = 0;

int main()
{
	// STACK MEMORY
	// Function frames are pushed and popped to the stack as functions are called

	// HEAP MEMORY
	// dynamic memory
	// responsible for allocating and de-allocating memory
	// new and delete keywords
	// dynamically allocated memory does not go out of scope.
	// new allocates the space, writes the correct data if initialized, and returns the memory address
	// if a pointer is reassigned without freeing up what it was pointing to, 
	// this is called a memory LEAK, and we can no longer access it because we no longer have anything
	// that is pointing to it. Over time, this will take up memory
	// delete frees that space in memory up for use by anything else.
	// if you delete a pointer, it points to something meaningless in memory,
	// if you de-reference it later, it may return garbage data.
	// so it is needed to re-assign the pointer to nullptr. 
	// in other words It is a pointer that doesn't point anywhere meaningful anymore;


	// calls default constructor for struct
	// health will be 0.0, std::string will be ""
	// Using new keyword to create it will be stored on the heap
	// not create something at compile time, but at runtime.
	// it won't be automatically released due to scope
	//Character* ptrToChar = new Character();

	// Here's an example of how to overload the Heap memory (using a really large iteration number)
	for (int i = 0; i < 10; i++) //0000000000; i++) 
	{
		Character* ptrToChar = new Character();

		std::cout << ptrToChar->Name << std::endl;
		ptrToChar->PrintHealth();

		// This line will free the memory and keep the program from terminating
		delete(ptrToChar);
	}


	// DESTRUCTORS
	// Anytime an object is deleted, a DESTRUCTOR on that object is called
	// This is useful to clean up any dynamically allocated memory when something is deleted
	// dynamically allocated is any memory that is allocated at runtime
	 
	// Dynamically allocate memory on the heap, constructor is called
	Player* myPlayer = new Player();
	// delete the player instance, the destructor is called
	delete myPlayer;


	// STATIC Variables
	// STATIC variables exist in a different part of memory than local variables
	// local variables exist within a given scope. when that scope exits, the local variable is deleted
	// STATIC variables live past the function scope... if uninitialized it gets a default value
	// subsequent initializations of a static variable are ignored.

	// static class instantiations stay in memory until the program exits.

	// a static data member inside a class 
	// is there even without an instantiation of a class,
	// it exists between all instantiations of that class. "Class Variable"
	// It has to be initialized outside of a class. You cannot re-define, but you can change it.

	// static functions in a class
	// call the function even if there are no instantiations of the class
	// can just call the function, it belongs to the class, not an instantiations


	// STATIC variables in a function
	for (int j = 0; j < 100; j++)
	{
		AddToCount();
	}
	// cannot access count here, 
	// count--; won't work because its not accessible in this scope, even though it exists until program exit
	
	{
		// adding static here allows item to exist past the scope of this block
		static Item item;
	}


	// Can access and use CritterCount
	//Critter::CritterCount = 13;
	//std::cout << Critter::CritterCount << std::endl;

	Critter myCritter;
	// because of the increment in the constructor, this will reflect the number of critters
	std::cout << Critter::CritterCount << std::endl;
	Critter myCritter2;
	// because of the increment in the constructor, this will reflect the number of critters
	std::cout << Critter::CritterCount << std::endl;


}

// CAN DEFINE CONSTRUCTOR and FUNCTION DEFINITIONS OUTSIDE OF THE STRUCT
Character::Character()
{
	Name = "DefaultName";
	Health = 100.0f;
}

//FULLY qualifying the name of the function
void Character::PrintHealth()
{
	std::cout << "Health: " << Health << std::endl;

}

Player::Player()
{
	std::cout << "A new Player was instantiated" << std::endl;

	// dynamically allocated on the heap, so we are responsible for deleting it
	PlayerAge = new int(24);
	PlayerHealth = new float(100.f);

}
Player::~Player()
{
	std::cout << "A Player instance was deleted." << std::endl;

	delete PlayerAge;
	delete PlayerHealth;
}