/*
    A pointer is as address of "something".
*/

void Magic(int *arr) {

}

/*
    use case 1: Make an array
    [10,    20,     30]
    0x11H  0x15H  0x19H
    |
    |
    ptr
*/
void F1() {
    int arr[] = {10, 20, 30};
    int * ptr = arr;        // attach array's 1st location to ptr
    Magic(arr);
}

/*
    use case 2: Make an array of objects
*/
struct Employee{
    int _id;
    float _salary;
    Employee(int id, float salary) : _id{id}, _salary{salary} {}
    ~Employee(){}
};

void Magic1(Employee *arr){}

void F2() {
    Employee e1 (10, 10000);
    Employee e2 (20, 20000);
    Employee arr[2] = {e1, e2};
    Magic1(arr);
}

/*
    usecase3: array of object pointers
*/
void Magic1(Employee **arr, int size){}

void F2() {
    Employee* e1 = new Employee(10, 10000);
    Employee* e2 = new Employee(20, 20000);
    Employee* arr[2] = {e1, e2};
    Magic1(arr, 2);
}

