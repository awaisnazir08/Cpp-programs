#include <iostream>
#include <string>
#include <ctime>

enum class Gender {
    Male,
    Female,
    Other
};

class Person {
public:
    string FirstName;
    string LastName;
    Gender Gender;
    time_t DateOfBirth;
};

class PersonFormatter {
public:
    string Format(const Person& person, const string& formatType) {
        string formattedString;
        if (formatType == "JSON") {
            formattedString = FormatJSON(person);
        } else if (formatType == "FirstAndLastName") {
            formattedString = FormatFirstAndLastName(person);
        } else {
            formattedString = FormatDefault(person);
        }
        return formattedString;
    }

private:
    string FormatJSON(const Person& person) {
        // Implement JSON formatting here
        // Sample implementation
        return "{ \"FirstName\": \"" + person.FirstName + "\", \"LastName\": \"" + person.LastName + "\", \"Gender\": \"" + GenderToString(person.Gender) + "\", \"DateOfBirth\": \"" + to_string(person.DateOfBirth) + "\" }";
    }

    string FormatFirstAndLastName(const Person& person) {
        // Implementation of first & last name formatting here
        // Sample implementation
        return person.FirstName + " " + person.LastName;
    }

    string FormatDefault(const Person& person) {
        // Implementation of default formatting
        // Sample implementation
        return "Unknown format";
    }

    string GenderToString(Gender gender) {
        switch (gender) {
            case Gender::Male:
                return "Male";
            case Gender::Female:
                return "Female";
            case Gender::Other:
                return "Other";
        }
        return "Unknown";
    }
};
