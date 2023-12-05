#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <map>
#include <string>
using namespace std;

// class to create a student object for each course
class Student
{
public:
    string name;
    int marks;

    // constructor
    Student(const string &n, int m) : name(n), marks(m) {}

    // comparison operator (it is needed for priority queue)
    bool operator<(const Student &other) const
    {
        // higher marks have higher priority
        return marks < other.marks;
    }
};

int main()
{
    // creating a map that stores 5 keys for 5 courses,and each key points to a priority queue that contains sorted data in descending order
    map<string, priority_queue<Student>> courses;

    // opening  the CSV file
    ifstream file("file.csv");

    if (!file.is_open())
    {
        cerr << "Error opening the file." << endl;
        return 1;
    }

    // reading the header row to get course names
    string header;
    getline(file, header);

    // extracting course names from the header row
    istringstream headerStream(header);

    // vector used to store the names of the courses
    vector<string> courseNames;
    string courseName;

    // first column contains the names of the students, so skipping this column
    getline(headerStream, courseName, ',');

    // reading the rest of the columns as coursenames
    while (getline(headerStream, courseName, ','))
    {
        courseNames.push_back(courseName);
    }

    // reading the student data
    string studentData;
    while (getline(file, studentData))
    {
        istringstream ss(studentData);
        string name;
        int marks;

        // reading student name
        getline(ss, name, ',');

        // reading marks for each course and store them in the respective course's priority queue
        for (int i = 0; i < courseNames.size(); i++)
        {
            string coursesMarksInString;
            getline(ss, coursesMarksInString, ',');

            // converting the strings of marks to integer marks
            marks = stoi(coursesMarksInString);

            // create a Student object and push it to the respective course's priority queue
            courses[courseNames[i]].push(Student(name, marks));
        }
    }

    // displaying the highest marks for each course
    for (const auto &data : courses)
    {
        cout << "Student in " << data.first << " has the highest marks:\n";

        // accessing the priority queue for the current course
        const priority_queue<Student> &requiredCourseQueue = data.second;

        // displaying the highest marks for the course
        if (!requiredCourseQueue.empty())
        {
            Student student = requiredCourseQueue.top();
            cout << student.name << ": " << student.marks << endl;
        }
        else
        {
            cout << "No students in this course.\n";
        }
    }

    file.close();
    return 0;
}
