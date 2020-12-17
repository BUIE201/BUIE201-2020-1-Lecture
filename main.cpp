#include "order.h"
#include "meat.h"
#include "dessert.h"

int main()
{
	ORDER o1; // +		&o1	-> 0x000000f8708ff568 an address in stack

	
	auto pM1 = new MEAT(10); // Parameter is the cost of the dish.

	// MEAT -> +		pM1's value 0x000002da5e522850 an address in heap
	// &pM1	0x000000f8708ff5a8 an address in stack


	auto pM2 = new MEAT(20); // Parameter is the cost of the dish.
	auto pD1 = new DESSERT(4); // Parameter is the cost of the dish.
	o1.AddItem(pM1);
	o1.AddItem(pM2);
	o1.AddItem(pD1);
	o1.PrintORDER();	// Output should read MEAT = 10TL, MEAT = 20TL, DESSERT = 4TL, TOTAL = 34TL.

	return 1;
}
// do not use ifs and function overloading.




// first line creates a local variable named o1. so ORDER must be a class.
// 2-4 lines creates dynamic variables. so MEAT and DESSERT must be classes.
// the paranthesis and the values that comes after the class names must be calls to their constructors.
// through the explanation provided I know that MEAT and DESSERT both have cost attributes.

// line 5-6. AddItem must be a public function of the ORDER class. Parameter of this function 
// should be a pointer to a MEAT

// line 7. AddItem must be a public function of the ORDER class. Parameter of this function 
// should be a pointer to a DESSERT

// FIRST OPTION: We could have used function overloading: have two separate functions with to input types.

// SECOND OPTION: Create a class called DISH which is a base class for MEAT and DESSERT.
// Now, ORDER::AddItem can have a DISH* parameter.