#include <iostream>
 
class Opreator_Overloading
{
private:
    int max_size;
    int *memory_alloc_size;
 
public:
    int x, y, z;
    Opreator_Overloading(/* args */)
    {
        x = 0;
        y = 0;
        z = 0;
    }
    Opreator_Overloading( int size);
 
    int &operator[](int size_x);
 
    Opreator_Overloading operator+(const Opreator_Overloading &rhs) const;
 
    friend std::ostream &operator<<(std::ostream &os, const Opreator_Overloading &obj);
    friend std::istream &operator>>(std::istream &is, Opreator_Overloading &obj);
 
    ~Opreator_Overloading() { delete[] memory_alloc_size; }
    // constructor for new memory allocation
};
 
Opreator_Overloading::Opreator_Overloading(int size)  {
    memory_alloc_size = new int[size];
     max_size = size;
}
 
// Overloading [] operator
int &Opreator_Overloading::operator[](int size_x)
{
    static int inValid_size = -1;
    if (size_x >= 0 && size_x < max_size)
    {
        return memory_alloc_size[size_x];
    }
    else
    {
        std::clog << "Size bound voilation: " << inValid_size << std::endl;
        return inValid_size;
    }
}
Opreator_Overloading Opreator_Overloading::operator+(const Opreator_Overloading & rhs) const
{
    Opreator_Overloading result;
    result.x = x * rhs.y;
    return result;
    }
 
    std::ostream &operator<<(std::ostream &os, const Opreator_Overloading &rhs)
    {
        os << rhs.x;
        return os;
    }
 
    std::istream &operator>>(std::istream &is, Opreator_Overloading &obj)
    {
        is >> obj.x;
        return is;
    }
 
int main()
{

    Opreator_Overloading op1;
    op1.y = 4;
    Opreator_Overloading op2;
    op2.x = 5;
    std::cin >> op2;
    Opreator_Overloading result = op2 + op1;
    std::cout << std::endl;
    std::cout << "Without Overlod  <<: " << result.x << std::endl; // not overloaded
    std::cout << "Overloded <<: " << result ;
    std::cout << std::endl;
    Opreator_Overloading obj(10);

    int count = 10;
    for (int i = 0; i < count; i++)
    {
        obj[i]= i;
    }  
        obj[3] = obj[9];
    
    
     for (int i = 0; i <= 10; i++)
    {
        std::cout << obj[i] << std::endl;
    }

    // for(auto x: obj.)

       
    }
