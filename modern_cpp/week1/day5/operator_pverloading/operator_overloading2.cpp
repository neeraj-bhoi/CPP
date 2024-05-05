// subscripting.cpp
// compile with: /EHsc
#include <iostream>
using namespace std;

class Opreator_Overloading {
private:
   int *memory_alloc_size;
   int max_size;

public:
   Opreator_Overloading( int size );
   ~Opreator_Overloading() { delete [] memory_alloc_size; }
   int& operator[](int size_x);

};

// Construct an Opreator_Overloading.
Opreator_Overloading::Opreator_Overloading(int size) {
   memory_alloc_size = new int[10];
   max_size = size;
}

// Subscript operator for Opreator_Overloading.
int& Opreator_Overloading::operator[](int size_x) {
   static int iErr = -1;

   if( size_x >= 0 && size_x < max_size )
      return memory_alloc_size[size_x];
   else {
      std::cout << "Array bounds violation." << endl;
      return iErr;
   }
}

// Test the Opreator_Overloading class.
int main() {
   Opreator_Overloading v( 10 );
   int i;

   for( i = 0; i <= 10; ++i )
      v[i] = i;

   v[3] = v[9];

   for ( i = 0; i <= 10; ++i )
      cout << "Element: [" << i << "] = " << v[i] << endl;
}