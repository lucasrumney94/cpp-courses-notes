#include<iostream>
#include <string>

int addOne(const int a);
void passOnlyVars(int& num);
void canPassLiterals(const int& num);

int main()
{
	// C-STYLE STRINGS
	// Null terminated char arrays
	// must end with "\0", the null character
	char red[4] = { 'r', 'e', 'd', '\0' };
	std::cout << red << std::endl;


	// STRINGS

	// initialization
	std::string myString = "hello world!";
	std::cout << myString << std::endl;

	std::string pet("Spot");
	std::cout << pet << std::endl;

	// concatenation
	std::string firstName = "Lucas";
	std::string lastName = "Rumney";
	std::string separator = " ";
	std::string fullName = firstName + separator + lastName;
	std::cout << fullName << std::endl;

	std::string fullPetName = pet;
	fullPetName += separator + lastName;
	std::cout << fullPetName << std::endl;

	int x = 5;
	std::cout << addOne(x) << std::endl;



	// CONSTANTS
	// must be initialized with a value
	const float PI = 3.14159F;
	// cannot alter constants
	//PI++;

	// PASS BY REFERENCE / LITERALS 
	int y = 2;
	passOnlyVars(y);

	// this will fail because an int literal has no memory address, 
	// and thus can't be a reference
	// passOnlyVars(5)


	int b = 4;
	// because of the const on the arg, this function can pass literals
	// but it cannot modify it, its a const.
	canPassLiterals(5);

	// even though we pass in a variable, the const on the arg means
	// that we cannot actually modify b, even though its not const.
	canPassLiterals(b);


	// BOOLEAN OPERATORS (AND, OR) [Truth Tables]
	bool i = true;
	bool j = false;
	std::cout << "i || j  is " << (i || j) << std::endl;
	std::cout << "i && j  is " << (i && j) << std::endl;


	// ARRAYS
	// containers for values of same data type
	// contiguous memory locations, 
	// Random Access : indexing is O(1) 
	// because index is just memory offset calculation
	int myIntArray[3];
	myIntArray[0] = 16;
	myIntArray[1] = 32;
	myIntArray[2] = 64;

	// This will print out the initial memory location
	std::cout << "myIntArray is " << myIntArray << std::endl;

	// This will print out the initial value
	// (the value present at the initial memory location)
	std::cout << "myIntArray[0] is " << myIntArray[0] << std::endl;

	// iterate over contents
	for (int i = 0; i < 3; i++)
	{
		std::cout << "myIntArray at "<< i << " is " << myIntArray[i] << std::endl;
	}

	double myDoubleArray[] = { 3.14, 6.28 };
	std::cout << "myDoubleArray[0] is " << myIntArray[0] << std::endl;


	// ENUMS 
	// list of named integer constants
	// this is really useful for states or options
	// convention is to abbreviate the enum name as a prefix for the 
	// enum components
	enum PlayerState {
		PS_Crouched, //0
		PS_Standing, //1
		PS_Running, //2
		PS_Sprinting //3
	};

	PlayerState myPlayerState = PS_Crouched;

	// SWITCH STATEMENTS
	// cleaner than If/Else If/Else
	// 
	switch (myPlayerState) {
	case PS_Crouched:
		std::cout << "crouching" << std::endl;
		break;
	case PS_Running:
		std::cout << "running" << std::endl;
		break;
	case PS_Standing:
		std::cout << "standing" << std::endl;
		break;
	case PS_Sprinting:
		std::cout << "sprinting" << std::endl;
		break;
	default:
		std::cout << "invalid state!?" << std::endl;
		break;
	}

	// OBJECT ORIENTED PROGRAMMING
	// STRUCTS
	// Blueprint 
	struct Information 
	{
		std::string label;
		int id;

		int GetID() 
		{
			return id;
		}
	};

	// Object Instantiation of a struct
	Information myInfo = { "myLabel", 4 };
	std::cout << myInfo.label << std::endl;
	std::cout << myInfo.GetID() << std::endl;



	// POINTERS
	int myInt = 5;
	// this creates 4 bytes of storage to contain myInt
	// the beginning address of myInt, is the address.

	// create an integer pointer (int*) (not an int!)
	// unlike a reference it doesn't have to be initialized.
	// a pointer contains a memory address
	// assign it to the address of myInt (&myInt)
	// this & (address of) operator is different than the reference declaration &
	int* myIntPointer = &myInt;
	std::cout << myIntPointer << std::endl;
	 
	// Use the de-referencing the pointer to access the contents.
	std::cout << *myIntPointer << std::endl;
	
	// Passing by value to functions, copying the data can be large and time-consuming
	// Passing pointers will only ever pass the memory location


	// POINTER ARITHMETIC

	int numbers[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	// can set to the address of the array
	// name of array is the same as a memory address of the first element
	// points to a particular integer
	int* numberPtr = numbers;

	std::cout << numbers << std::endl;

	// de-reference and get the value 0
	std::cout << *numberPtr << std::endl;

	// move to the next memory address.
	// this works because arrays are contiguous
	numberPtr++;
	std::cout << *numberPtr << std::endl; 


	struct Container 
	{
		std::string Name;

		int X;
		int Y;
		int Z;
	};

	Container container = { "Sam Fisher", 5, 6, 7 };
	Container* ptrToContainer = &container;

	// can de-reference and then index the struct
	// without the parens, the dot operator would supercede the de-reference and fail
	std::cout << (*ptrToContainer).Name << std::endl;

	// Or use the combined operation that C++ provides
	std::cout << ptrToContainer->Name << std::endl;

	// CLASSES
	// Classes are 'blueprints' for instantiations of that object.
	class Dog 
	{
	// to access these variables from other places, they need to be public
	public:
		// constructor needs to have the same signature as class
		// called when the class is instantiated
		Dog()
		{
			Bark();
			
			// everything should be initialized to a reasonable value
			// in a constructor if possible, or else it may point to garbage data.
			name = "default name";
			age = 15;

		}

		std::string name;
		int age;
		void Bark() 
		{
			std::cout << "BARK!" << std::endl;
		}
		void walk();
	};
	

	Dog Rex;
	Dog Spot;

	std::cout << Rex.name << std::endl;
	Rex.name = "Rex";
	// Functions and constructors can be defined outside the class
	// by using Dog::Dog() or Dog::Bark()
	// But I am just doing demonstration code in main so that won't work here.



}


// by using const on the input parameter you keep the function from
// being able to modify a.
int addOne(const int a) {
	return a + 1;
}

void passOnlyVars(int& num)
{
	std::cout << num << std::endl;
}

void canPassLiterals(const int& num)
{
	std::cout << num << std::endl;
}