#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;

class Course; // Forward declaration

class Person {
protected:
    int id;
    string name;
    string email;
public:
    Person(int id, const string& name, const string& email) : id(id), name(name), email(email) {}
    virtual void displayInfo() const = 0;
};

class Student; // Forward declaration

class Enrollment {
private:
    weak_ptr<Student> student; // Using weak_ptr to avoid circular dependency
    weak_ptr<Course> course;
    double grade;

public:
    Enrollment(const shared_ptr<Student>& student, const shared_ptr<Course>& course)
        : student(student), course(course), grade(0.0) {}

    void updateGrade(double newGrade) {
        if (newGrade >= 0.0 && newGrade <= 100.0) {
            grade = newGrade;
        } else {
            cout << "Invalid grade value. Grade should be between 0 and 100.\n";
        }
    }

    double getGrade() const { return grade; }
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
    vector<Enrollment> enrollments; // Keep track of enrollments

    void enrollStudent(const shared_ptr<Student>& student) {
        enrolledStudents.push_back(student);
        enrollments.emplace_back(student, shared_from_this()); // Create an enrollment object
    }

    void removeStudent(const shared_ptr<Student>& student) {
        // Implementation to remove a student from the course
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

    const vector<Enrollment>& getEnrollments() const {
        return enrollments;
    }
};

class Student : public Person, public enable_shared_from_this<Student> {
private:
    vector<shared_ptr<Course>> enrolledCourses;
    float marks;

public:
    Student(int id, const string& name, const string& email) : Person(id, name, email), marks(0.0) {}

    void enroll(const shared_ptr<Course>& course) {
        enrolledCourses.push_back(course);
        course->enrollStudent(shared_from_this());
    }

    void accessCourseMaterial(const shared_ptr<Course>& course) const {
        vector<string> courseMaterial = course->getCourseMaterial();
    }

    void displayInfo() const override {
        cout << "Student ID: " << id << ", Name: " << name << ", Email: " << email << "\n";
        cout << "Courses...\n";
        int i = 1;
        for (auto it : enrolledCourses) {
            cout << "Course " << i++ << ": " << it->getName() << "\n";
        }
    }

    void setMarks(float f) {
        if (f >= 0) {
            marks = f;
        } else {
            cout << "Marks cannot be less than zero..!!\n";
        }
    }
    float getMarks()
    {
        return marks;
    }
    string getName()
    {
        return name;
    }
};

class Professor : public Person {
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

    void uploadCourseMaterial(Course* course, const string material) {
        course->addMaterial(material);
    }

    const string& getDepartment() const { return department; }
};

class Report {
public:
    static void generateGradeReport(const shared_ptr<Student>& student, const shared_ptr<Course>& course) {
        cout << "Generating grade report for ";
        student->displayInfo();
        cout << "Course: " << course->getName() << "\n";

        for (const auto& enrollment : course->getEnrollments()) {
            if (enrollment.getGrade() > 0.0) {
                cout << "Grade for " << student->getName() << ": " << enrollment.getGrade() << "\n";
            } else {
                cout << "Grade not available for " << student->getName() << "\n";
            }
        }
    }

    static void generatePerformanceReport(const shared_ptr<Student>& student) {
        cout << "Generating performance report for ";
        student->displayInfo();
        cout << "Overall Marks: " << student->getMarks() << "\n";
    }
};
