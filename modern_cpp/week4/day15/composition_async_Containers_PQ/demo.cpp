// #include <iostream>
// #include <queue>
// #include <string>

// class Employee {
// public:
//     Employee(std::string name, int salary, int experience) 
//         : name(name), salary(salary), experience(experience) {}

//     // Define the comparison logic based on your priority criteria
//     bool operator<(const Employee& other) const {
//         return salary < other.salary;
//     }

//     // Getter functions (optional)
//     std::string getName() const {
//         return name;
//     }

//     int getSalary() const {
//         return salary;
//     }

//     int getExperience() const {
//         return experience;
//     }

// private:
//     std::string name;
//     int salary;
//     int experience;
// };

// int main() {
//     // Create Employee objects
//     Employee employee1("John", 50000, 3);
//     Employee employee2("Jane", 60000, 5);
//     Employee employee3("Bob", 45000, 2);
//     Employee employee4("Alice", 70000, 8);
//     Employee employee5("Charlie", 55000, 4);

//     // Create a priority queue of Employee objects
//     std::priority_queue<Employee> priorityQueue;

//     // Store Employee objects in the priority queue
//     priorityQueue.push(employee1);
//     priorityQueue.push(employee2);
//     priorityQueue.push(employee3);
//     priorityQueue.push(employee4);
//     priorityQueue.push(employee5);

//     // Retrieve and print objects from the priority queue
//     while (!priorityQueue.empty()) {
//         Employee employee = priorityQueue.top();
//         priorityQueue.pop();
//         std::cout << "Name: " << employee.getName() << ", Salary: " << employee.getSalary() 
//                   << ", Experience: " << employee.getExperience() << std::endl;
//     }

//     return 0;
// }
