// C++ Program to Demonstrate the Functioning of Enumerators 
// with an example of Gender 
// #include <bits/stdc++.h> 
// using namespace std; 

// int main() 
// { 
// 	// Defining enum Gender 
// 	enum Gender { Male, Female }; 

// 	// Creating Gender type variable 
// 	Gender gender = Male; 

// 	switch (gender) { 
// 	case Male: 
// 		cout << "Gender is Male"; 
// 		break; 
// 	case Female: 
// 		cout << "Gender is Female"; 
// 		break; 
// 	default: 
// 		cout << "Value can be Male or Female"; 
// 	} 
// 	return 0; 
// }


// C++ Program to Demonstrate the Functioning of Enumerators 
// with an Example of Year 
#include <bits/stdc++.h> 
using namespace std; 

// Defining enum Year 
enum year { 
	Jan, 
	Feb, 
	Mar, 
	Apr, 
	May, 
	Jun, 
	Jul, 
	Aug, 
	Sep, 
	Oct, 
	Nov, 
	Dec 
}; 

// Driver Code 
int main() 
{ 
	int i; 

	// Traversing the year enum 
	for (i = Jan; i <= Dec; i++) 
		cout << i << " "; 

	return 0; 
}

