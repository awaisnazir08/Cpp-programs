#include <iostream>
#include <queue>
#include <map>

// Struct to represent a student
struct Student {
    std::string name;
    int marks;

    // Constructor
    Student(const std::string& n, int m) : name(n), marks(m) {}

    // Comparison operator for priority queue
    bool operator<(const Student& other) const {
        // Assuming higher marks have higher priority
        return marks < other.marks;
    }
};

int main() {
    // Creating 5 priority queues for different courses
    std::priority_queue<Student> course1;
    std::priority_queue<Student> course2;
    std::priority_queue<Student> course3;
    std::priority_queue<Student> course4;
    std::priority_queue<Student> course5;

    // Map to store the queues with course names as keys
    std::map<std::string, std::priority_queue<Student>> courseMap;

    // Adding some sample data
    course1.push(Student("Alice", 90));
    course1.push(Student("Bob", 85));

    course2.push(Student("Charlie", 95));
    course2.push(Student("David", 88));

    course3.push(Student("Eve", 92));
    course3.push(Student("Frank", 89));

    course4.push(Student("Grace", 87));
    course4.push(Student("Hank", 91));

    course5.push(Student("Ivy", 93));
    course5.push(Student("Jack", 86));

    // Adding queues to the map with course names as keys
    courseMap["Course1"] = course1;
    courseMap["Course2"] = course2;
    courseMap["Course3"] = course3;
    courseMap["Course4"] = course4;
    courseMap["Course5"] = course5;

    // Example: Accessing the priority queue for a specific course
    std::string targetCourse = "Course3";

    // Check if the course exists in the map
    if (courseMap.find(targetCourse) != courseMap.end()) {
        std::cout << "Students in " << targetCourse << " with their marks:\n";
        // Accessing the priority queue for the target course
        std::priority_queue<Student> targetQueue = courseMap[targetCourse];

        // Pop elements from the queue until it's empty
        while (!targetQueue.empty()) {
            Student student = targetQueue.top();
            std::cout << student.name << ": " << student.marks << "\n";
            targetQueue.pop();
        }
    } else {
        std::cout << "Course not found.\n";
    }

    return 0;
}



