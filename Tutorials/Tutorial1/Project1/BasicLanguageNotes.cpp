// include iostream from the standard library
// All code provided by iostream is now accessible for use
#include<iostream>
//include string from the standard library
#include<string>

// using namespace std;
// this would allow me to forego using std:: every time, however 
// we should embrace using namespaces properly and be explicit about 
// which namespace we are using each time.
// as an alternative, I could use a typedef, or further specify
// using namespace std::cout, or put using namespace::std in a limited
// scope like a function or class definition


// Function Definition (prior to usage)
int add(int parameterOne, int parameterTwo) 
{
	return parameterOne + parameterTwo;
}

void printNumber(int numberToPrint) 
{
	std::cout << numberToPrint << std::endl;
}

void printNumber(int firstNum, int secondNum) 
{
	std::cout << firstNum << ","<< secondNum << std::endl;
}

void printNumber(double numberToPrint)
{
	std::cout << numberToPrint << std::endl;
}

// passing in a reference will mean I am actually modifying that 
// portion of memory, not copying the value.
void addOne(int& num) 
{
	num++;
}

// function DECLARATION early in file (just args, return types)
void addExclaim(std::string& str);


// Required entry point for every C++ program. 
int main() 
{
	// BASIC OUTPUT

	// cout  character output to standard output stream (stdout)
	// insertion operator (<<) used to write characters to it.
	// \n is the character for a new line
	std::cout << "You died!"<< std::endl;
	// semicolons are used specify the end of a statement.
	std::cout << std::endl;

	// FUNDAMENTAL DATA TYPES
	// INTEGRAL TYPES

	// integer, typically 4 bytes
	int myInt;
	myInt = 5;
	std::cout << "int: " << myInt << std::endl;

	short myShortInt;
	myShortInt = 3;
	std::cout << "short: " << myInt << std::endl;


	// declares but does not initialize a character
	// char, 1 byte
	char myCharacter;
	// initialize the space in memory that we set aside with a real value
	myCharacter = 'h';
	std::cout << "char: " << myCharacter << std::endl;
	myCharacter = 'e';
	std::cout << "reassigned char: "<< myCharacter << std::endl;

	// bool, 1 byte
	bool myBool;
	myBool = true;
	std::cout << "bool:" << myBool << std::endl;

	// FLOATING POINT DATA TYPES
	// float, 4 bytes
	// represented as a whole and fractional component in scientific 
	// notation ie 8.932345*10^3 or 8.932345e3
	float myFloat;
	myFloat = 8932.345F; // literal needs F to be considered a float.
	std::cout << "float: " << myFloat << std::endl;

	// double, typically twice the size of a float (8 bytes)
	double myDouble;
	myDouble = 9782345.4584;
	std::cout << "double: " << myDouble << std::endl;


	// EXPRESSIONS
	// TRUTH VALUES
	if (0) { std::cout << "0 is true" << std::endl; }
	else { std::cout << "0 is false" << std::endl; }
	
	if (1) { std::cout <<  "1 is true" << std::endl; }
	else { std::cout << "1 is false" << std::endl; }

	if (-1) { std::cout << "-1 is true" << std::endl; }
	else { std::cout << "-1 is false" << std::endl; }

	if (-000000) { std::cout << "-000000 is true" << std::endl; }
	else { std::cout << "-000000 is false" << std::endl; }

	if (0.01) { std::cout << "0.01 is true" << std::endl; }
	else { std::cout << "0.01 is false" << std::endl; }

	// COMPARISONS
	if (5 == 5) { std::cout << "5 equal to 5" << std::endl; }
	else { std::cout << "5 is not equal to 5" << std::endl; }

	if (5>3) { std::cout << "5 is greater than 3" << std::endl; }
	else { std::cout << "5 is less that 3" << std::endl; }

	if (!false) { std::cout << "!false is true" << std::endl; }
	else { std::cout << "!false is false" << std::endl; }


	// IF, ELSE IF, ELSE
	int givenNumber = 7;
	std::cout << "givenNumber is " << givenNumber << std::endl;
	if (givenNumber < 3)
	{
		std::cout << "givenNumber is less than 3" << std::endl;
	}
	else if (givenNumber < 8)
	{
		std::cout << "givenNumber is less than 8" << std::endl;
	}
	else 
	{
		std::cout << "givenNumber is greater than 8" << std::endl;
	}



	// SCOPE
	// curly braces define blocks, which have local scope.
	// blocks can be nested.
	{
		int a = 7;
		std::cout << "locally defined int a in this block: " << a << std::endl;
	}
	// causes an error because a is not in this outer scope
	// std::cout << a << std::endl;

	{
		int z = 10;
		{
			std::cout << "z in the inner block before local initialization is: " << z << std::endl;
			int z = 11;
			std::cout << "z in the inner block after local initialization is: " << z << std::endl;
		}
		std::cout << "z in the outer block is: " << z << std::endl;
	}



	// IDENTIFIERS
	// "names that we give our variables"
	// Case sensitive.
	// Letters, numbers, underscores
	// cannot start with numbers
	
	// Common Conventions
	// descriptive variable names
	// myAwesomeInteger camelCase:
	// bMyBool, (prefix booleans with 'b')
	// MyClass, classes are uppercase usually
	// cannot use specific keywords like bool, for, if, etc.


	// FUNCTION USAGE
	// main is the caller
	// 6 is returned as an int to the caller
	// Lower operations defined by an Appliation Binary Interface
	// EX: https://en.wikipedia.org/wiki/X86_calling_conventions
	// GENERALLY SPEAKING THIS IS THE PROCESS... 
	// when a function is called, the CALLER...
	// pushes space for the return value to the stack
	// pushes parameters to the stack
	// pushes the return address 
	// (the address in memory to return to once the function execution is complete)
	// then the CALLEE...
	// pushes the address of the previous stack frame
	// push values of the registers that this function uses (for later restoration)
	// push space for local variables
	// perform function computation
	// restore the registers 
	// restore the previous stack frame
	// store the function result 
	// jump execution back to the return address.
	// then the CALLER... 
	// pops the parameters, 
	// pops the return value

	// This is pass by value
	int resultOf2plus4 = add(2, 4);
	std::cout << "2 + 4 is: " << resultOf2plus4 << std::endl;

	// void function without a return value
	printNumber(5);


	// Basic console input
	std::cout << "input a single character: ";
	char response;
	std::cin >> response;
	std::cout << "You typed: " << response << std::endl;


	// incrementing and decrementing
	int myHealth = 100;
	std::cout << "inital health: " << myHealth << std::endl;
	myHealth = myHealth - 10;
	std::cout << "health: " << myHealth << std::endl;
	myHealth += 10;
	std::cout << "health: " << myHealth << std::endl;
	myHealth -= 50;
	std::cout << "health: " << myHealth << std::endl;
	myHealth *= 2;
	std::cout << "health: " << myHealth << std::endl;

	// PREINCREMENT
	// first increments by 1
	// then returns the result
	int amount = 5;
	myHealth += ++amount;
	std::cout << "health after preinc: " << myHealth << std::endl;

	// POSTINCREMENT
	// first returns the result
	// then increments by 1
	amount = 5;
	myHealth += amount++;
	std::cout << "health after postinc: " << myHealth << std::endl;

	// COMPUTATIONS
	int r = 2;
	float k = 6.0;

	float result = r / k;
	// implicit conversion to int
	int intResult = r / k;
	std::cout << "float result of (2/6.0): " << result << std::endl;
	std::cout << "int result of (2/6.0): " << intResult << std::endl;


	// LOOPS

	//WHILE 
	bool loopCondition = true;
	while (loopCondition) 
	{
		std::cout << "Setting loop condition to false to avoid infinite loop" << std::endl;
		loopCondition = false;
	}

	float f1 = 0.0;
	float f2 = 1.0;
	while (f1 < f2) {
		std::cout << "in loop - f1: " << f1 << "  f2: " << f2 << std::endl;
		f1 += 0.1;
	}
	std::cout << "after loop - f1: " << f1 << "  f2: " << f2 << std::endl;

	// DO WHILE
	// execute loop interior ONCE before condition is evaluated
	double d1 = 0.0;
	double d2 = 1.0;
	do 
	{
		d1 += 2.0;
	} while (d1 < d2);
	std::cout << "after loop - d1: " << d1 << "  d2: " << d2 << std::endl;

	// BREAK
	// breaks out of the loop
	int u = 0;
	while (true) 
	{
		u++;
		std::cout << "in loop - u: " << u << std::endl;
		if (u > 10) 
		{
			break;
		}
	}
	std::cout << "after loop - u: " << u << std::endl;

	// CONTINUE 
	// continue to the next iteration of the loop without running the remaining code
	int j = 0;
	int l = 0;
	while (j<1000) {
		if (l > j) 
		{
			j++;
			continue;
		}	
		l += 2;
	}
	std::cout << "after loop - j: " << j << "  l: " << l << std::endl;

	
	// FOR LOOPS
	// useful for specifying number of iterations
	// initialization, loop body, incrementation
	for (int i = 0; i < 10; i++)
	{
		std::cout << "this should be printed 10 times i: " << i << std::endl;
	}

	// Nesting is supported, but this usually makes algorithms O(n^2) or more
	// so this is usually a bad idea in real implementations, expensive
	for (int i = 0; i < 5; i++) 
	{
		for (int j = 0; j < 5; j++)
		{
			std::cout << "in loop - i: " << i << "  j: " << j << std::endl;
		}
	}

	// PASSING BY VALUE
	int t = 5;
	std::cout << "t is: " << t << std::endl;
	add(t, t);
	std::cout << "t is: " << t << std::endl;
	t = add(t, t); // this will modify the value because we reassign it

	t = 5;
	// PASSING BY REFERENCE
	// a refernce is not a copy or just holding the value
	// it is actually the memory location, the same exact variable.
	// can be used to change/effect variables values in other scopes.
	int& tRef = t;
	std::cout << "t is: " << t << std::endl;
	std::cout << "tRef is: " << tRef << std::endl;

	tRef++;
	std::cout << "t is: " << t << std::endl;
	std::cout << "tRef is: " << tRef << std::endl;

	addOne(tRef);
	std::cout << "t is: " << t << std::endl;
	std::cout << "tRef is: " << tRef << std::endl;


	// STRINGS AND ALIASES(references)

	std::string myString = "Hello";
	std::string& myStringRef = myString;

	std::cout << "My String: " << myString << std::endl;
	std::cout << "My String Ref: " << myStringRef << std::endl;

	// String concatenation
	myString += ", ";
	myStringRef += " There";

	std::cout << "My String: " << myString << std::endl;
	std::cout << "My String Ref: " << myStringRef << std::endl;

	// accepts a string, uses reference
	addExclaim(myString);
	std::cout << "My String: " << myString << std::endl;
	std::cout << "My String Ref: " << myStringRef << std::endl;

	// also accepts a string reference directly
	addExclaim(myStringRef);
	std::cout << "My String: " << myString << std::endl;
	std::cout << "My String Ref: " << myStringRef << std::endl;

	// but will not work for string literals (const char[]) anymore because
	// they are constants, cannot be changed.
	// addExclaim("Woohoo");

	
	// FUNCTION OVERLOADING
	// allows you to define a single function, with multiple definitions
	// dependent on the function arguments
	// same name, different arguments
	int jk = 5;
	int uv = 10;
	float xw = 4.0;

	// use the int,int overload
	printNumber(jk, uv);
	// use the float overload
	printNumber(xw);

	// Platform specific (and unsafe) hack to keep the console window open.
	// Uses the Window command-line Pause program and waits for that to terminate
	// before terminating the program (closing the window)
	//system("pause");
}

// Function DEFINITION contains full function definition
void addExclaim(std::string& str) {
	str += "!";
}