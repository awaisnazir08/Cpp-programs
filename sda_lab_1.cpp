#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;
class Person {
protected:
    int id;
    string name;
    string email;
public:
    Person(int id, const string& name, const string& email) : id(id), name(name), email(email) {}
    virtual void displayInfo() const = 0;
};

class Student : public Person, public enable_shared_from_this<Student> {
private:
    vector<shared_ptr<Course>> enrolledCourses;
    float marks;
public:
    Student(int id, const string& name, const string& email) : Person(id, name, email) {
    }

    void enroll(const shared_ptr<Course>& course) {
        enrolledCourses.push_back(course);
        course->enrollStudent(shared_from_this());
    }

    void accessCourseMaterial(const shared_ptr<Course>& course) const {
        vector<string> courseMaterial = course->getCourseMaterial();
    }

    void displayInfo() const override {
        cout << "Student ID: " << id << ", Name: " << name << ", Email: " << email << "\n";
        cout<<"Courses..."<<endl;
        int i = 1;
        for(auto it: enrolledCourses)
        {
            cout<<"Course: "<<i<<" "<<it->getName();
        }
    }
    void getMarks(float f)
    {
        if(f > 0)
        {
            marks = f;
        }
        else{
            cout<<"Marks cannot be less than zero..!!"<<endl;
        }
    }
};

class Course {
private:
    int id;
    string name;
    string description;
    vector<string> materials;
    friend class Student;
    friend class Professor;
    vector<shared_ptr<Student>> enrolledStudents;

    void enrollStudent(const shared_ptr<Student>& student) {
    enrolledStudents.push_back(student);
    }
protected:
    void addMaterial(const string& material) {
    materials.push_back(material);
    }
public:
    Course(int id, const string& name, const string& description) : id(id), name(name), description(description) {}
    const string& getName() const {
        return name;
    }

    const vector<shared_ptr<Student>>& getEnrolledStudents() const {
        return enrolledStudents;
    }

    vector<string> getCourseMaterial() const {
        return materials;
    }
};

class Professor : public Person, protected Course {
private:
    string department;

public:
    Professor(int id, const string& name, const string& email, const string& department)
        : Person(id, name, email), department(department) {}

    void addStudentInCourse(const shared_ptr<Student>& student, const shared_ptr<Course>& course) {
        student->enroll(course);
    }

    void removeStudentFromCourse(const shared_ptr<Student>& student, const shared_ptr<Course>& course) {
        course->removeStudent(student);
    }

    void uploadCourseMaterial(Course* course, const string material)
    {
        course->addMaterial(material);
    }

    const string& getDepartment() const { return department; }
};

class Enrollment {
private:
    shared_ptr<Student> student;
    shared_ptr<Course> course;
    double grade;

public:
    Enrollment(const shared_ptr<Student>& student, const shared_ptr<Course>& course, double grade)
        : student(student), course(course), grade(grade) {}

    double getGrade() const { return grade; }
};

class Report {
public:
    static void generateGradeReport(const shared_ptr<Student>& student, const shared_ptr<Course>& course) {
        // Implementation to generate a grade report
        cout << "Generating grade report for ";
        student->displayInfo();
        cout << "Course: " << course->getName() << "\n";
        // Implement specific report generation logic
    }
};

int main() {
    shared_ptr<Student> student1 = make_shared<Student>(1, "Alice", "alice@example.com");
    shared_ptr<Professor> professor1 = make_shared<Professor>(2, "Bob", "Computer Science");

    shared_ptr<Course> course1 = make_shared<Course>(1, "Introduction to Programming", "Learn basic programming concepts");
    student1->enroll(course1);

    // Add more courses, students, professors, enrollments, etc.

    Report::generateGradeReport(student1, course1);

    // No need to free allocated memory for smart pointers

    return 0;
}
