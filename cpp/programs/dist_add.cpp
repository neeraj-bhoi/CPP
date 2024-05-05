 /*
 Program : To overload + operator to add two distances
 Program By : Anil Donwade
 Program : 10-1-2024
 */

 //include files
 #include<iostream>
 #include<cstring>
 using namespace std;

 //class definition for the Distance class
 class Distance{
 int meter;
 int centimeter;
 public:
 //constructors
 Distance(){ //default constructor19: meter=0;
 centimeter=0;
 }

 Distance( int meter, int centimeter){ //two parameter const24: this->meter=meter;
 this->centimeter=centimeter;
 }

 Distance(const Distance &d){ //copy constructor
 this->meter=d.meter;
 this->centimeter=d.centimeter;
 }

 //member function to display the object of the class
 void display(){
 cout << meter << " meter " << centimeter << " centimeter" <<e36: }

 //operator overloading function
 Distance operator+(const Distance &d){
 cout << " operator overloading function called ......" << end41: Distance temp; //default constructor will be invoked
 //..will also initialize meter & centimet43: //populate temp with invoking object data
 temp.meter += this->meter;
 temp.centimeter += this->centimeter;

 //add parameterr data to temp object
 temp.meter += d.meter;
 temp.centimeter += d.centimeter;

 //adjust meter & centimeter
 if(temp.centimeter >=100){
 temp.centimeter -= 100;
 temp.meter += 1;
 }
 cout <<"inside operator overloading function, temp =" << mete57:
 return temp; //return the resulting string59: 
 }

 //operator overloading function
 Distance operator+(int x){
 Distance temp; //create a temporary object

 //populate temp with invoking object data
 temp.meter = this->meter;
 temp.centimeter = this->centimeter;

 //add x meters to existing object
 temp.meter += x;

 return temp;
 }

 //operator overloading function
 Distance operator++(){
 /*Distance temp;
 temp.meter = this->meter;
 temp.centimeter = this->centimeter;
 //add x meters to existing object
 temp.meter++;
 return temp;
 */
 this->meter++;
 return *this;
 }

 //operator overloading function, for post-increment
 Distance operator++(int x){ // the integer x is a dummy par90: this->meter++;
 return *this;
 }

 //friend functions for overloading +, << and >> operators
 friend Distance operator+(int x, Distance& d); //adding 96: friend ostream& operator<<(ostream& osr, Distance d); //inserte97: friend istream& operator>>(istream& isr, Distance &d); //extract98: };

 //operator overloading function for x + Distance obj expression
 Distance operator+(int x, Distance& d){
 Distance temp; //

 //populate temp with invoking object data
 temp.meter = d.meter;
 temp.centimeter = d.centimeter;

 //add x meters to existing object
 temp.meter += x;

 return temp;
 }

 //overloading of an extractor object, <<
 ostream& operator<<(ostream& osr, Distance d){
 osr << d.meter << " meter " << d.centimeter << " centimeter"<117: return osr;
 }

 //overloading of an inserter object, >>
 istream& operator>>(istream& isr, Distance &d){
 cout << endl << "Enter meter:";
 isr >> d.meter;
 cout << endl <<"Enter centimeter:";
 isr >> d.centimeter;
 return isr;
 }

 int main(){
 //create objects of Distance class
 Distance d1(100, 26), d2(20, 84);

 Distance d3; //resulting distance

 d1.display();
 d2.display();

 d3 = d1 + d2; //addition of two distances

 d3.display(); // display the resulting distance

 Distance d4 = d3 + 5; //d4 = d3.operator+(5)
 d4.display();

 //pre-increment
 ++d4;
 d4.display();

 //post-increment
 d4++;
 d4.display();

 //we must use friend function do this
 Distance d5;
 d5 = 5 + d4; //d5 = 5.operator+(d4) ==> d5=operator+(5, d4)156: d5.display();

 //using friend function also we can do this
 Distance d6 = d5 + 10; // d6=operator+(d5, 10);

 Distance da(1,1), db(2, 2), dc(3,3);
 Distance dsum = da + db + dc; // t1 = da.operator(db)
 // dsum = t1 + dc
 dsum.display();

 Distance dx, dy, dz;
 cin >> dx; //accept the first distance
 cin >> dy; //accept the second distance
 dz = dx + dy; //add two distances
 cout << "----------- Displaying Distance ------------" << endl;
 cout << dz; //display the resulting distance
 }
 