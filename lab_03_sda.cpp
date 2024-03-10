#include <iostream>
#include <string>
using namespace std;
class LibraryItem
{
    string title;
    int id;

public:

    LibraryItem(string t, int id_): title(t), id(id_) {}
    void setTitle(string t)
    {
        title = t;
    }
    void setId(int id)
    {
        this->id = id;
    }
    string getTitle()
    {
        return title;
    }
    int getId()
    {
        return id;
    }

    virtual void displayDetails() = 0;
    virtual bool isAvailable() = 0;
};

// Derived class for Book
class Book : public LibraryItem {
private:
    string author;
    bool available;

public:
    Book(string _title, int _id, string _author)
        : LibraryItem(_title, _id), author(_author), available(true) {}

    void displayDetails() {
        cout << "Book Title: " << getTitle() << endl;
        cout << "Book ID: " << getId() << endl;
        cout << "Author: " << author << endl;
    }

    bool isAvailable() {
        return available;
    }
};

// Derived class for DVD
class DVD : public LibraryItem {
private:
    string director;
    bool available;

public:
    DVD(string _title, int _id, string _director)
        : LibraryItem(_title, _id), director(_director), available(false) {}

    void displayDetails() {
        cout << "DVD Title: " << getTitle() << endl;
        cout << "DVD ID: " << getId() << endl;
        cout << "Director: " << director << endl;
    }

    bool isAvailable() {
        return available;
    }
};

// Derived class for Journal
class Journal : public LibraryItem {
private:
    string publisher;
    bool available;

public:
    Journal(string _title, int _id, string _publisher)
        : LibraryItem(_title, _id), publisher(_publisher), available(true) {}

    void displayDetails() {
        cout << "Journal Title: " << getTitle() << endl;
        cout << "Journal ID: " << getId() << endl;
        cout << "Publisher: " << publisher << endl;
    }

    bool isAvailable() {
        return available;
    }
};

int main() {
    // testing the polymorphic behavior
    LibraryItem* items[] = {
        new Book("The adventures of Tom Sawyer", 124, "Mark Twain"),
        new DVD("The Karate Kid", 214, "Robert Mark Kamen"),
        new Journal("African Journal of Food Science and Technology", 309, "Nature Africa")
    };

    for (const auto& item : items) {
        item->displayDetails();
        cout << "Available: " << (item->isAvailable() ? "Yes" : "No") << endl;
        cout << "-------------------------" << endl;
    }

    //cleaning up the allocated memory
    for (const auto& item : items) {
        delete item;
    }

    return 0;
}


// class LibraryItem {
// private:
//     std::string title;
//     int id;

// public:
//     // Constructors, getters, setters, and pure virtual functions...
// };

// class Book : public LibraryItem {
// private:
//     std::string author;

// public:
//     // Additional properties specific to Book...
//     // Overriding pure virtual functions...
// };

class LibraryItem {
private:
    std::string title;
    int id;

public:
    // Public member functions for controlled access...
};
