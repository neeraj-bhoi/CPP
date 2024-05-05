// #include <iostream>
// #include <vector>
// #include <queue>
// #include <memory>
// #include <string>

// class Employee {
// public:
//     Employee(std::string name, int salary, int experience)
//         : name(name), salary(salary), experience(experience) {}

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

// // Custom comparator function for Employee objects
// struct EmployeeComparator {
//     bool operator()(const std::shared_ptr<Employee>& lhs, const std::shared_ptr<Employee>& rhs) const {
//         return lhs->getSalary() < rhs->getSalary();
//     }
// };

// // Custom container using std::vector and custom comparator
// // template<typename T, typename Compare = std::less<typename std::vector<T>::value_type>>
// // class CustomVectorPriorityQueue : public std::priority_queue<T, std::vector<T>, Compare> {
// // public:
// //     using std::priority_queue<T, std::vector<T>, Compare>::priority_queue;
// //     using std::priority_queue<T, std::vector<T>, Compare>::push;
// //     using std::priority_queue<T, std::vector<T>, Compare>::emplace;

// //     // Expose the underlying vector for additional operations (optional)
// //     const std::vector<T>& getContainer() const {
// //         return this->c;
// //     }
// // };

// int main() {
//     // Create Employee objects using shared_ptr
//     auto employee1 = std::make_shared<Employee>("John", 50000, 3);
//     auto employee2 = std::make_shared<Employee>("Jane", 60000, 5);
//     auto employee3 = std::make_shared<Employee>("Bob", 45000, 2);
//     auto employee4 = std::make_shared<Employee>("Alice", 70000, 8);
//     auto employee5 = std::make_shared<Employee>("Charlie", 55000, 4);

//     // Create a priority queue of Employee objects with custom comparator and container
//     std::priority_queue<std::shared_ptr<Employee>, std::vector<std::shared_ptr<Employee>>, EmployeeComparator> priorityQueue;

//     // Store Employee objects in the priority queue
//     priorityQueue.push(employee1);
//     priorityQueue.push(employee2);
//     priorityQueue.push(employee3);
//     priorityQueue.push(employee4);
//     priorityQueue.push(employee5);

//     // Retrieve and print objects from the priority queue
//     while (!priorityQueue.empty()) {
//         auto employee = priorityQueue.top();
//         priorityQueue.pop();
//         std::cout << "Name: " << employee->getName() << ", Salary: " << employee->getSalary()
//                   << ", Experience: " << employee->getExperience() << std::endl;
//     }

//     return 0;
// }
