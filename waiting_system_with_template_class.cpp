#include <iostream>
// #include <queue>
#include <string>
#include <vector>
using namespace std;
#define N 100

class Patient
{
private:
    string name;
    int id;

public:
    // Patient()
    // {
    // }
    Patient(string name, int id)
    {
        this->name = name;
        this->id = id;
    }

    string getName()
    {
        return name;
    }

    void setName(string name)
    {
        this->name = name;
    }

    int getId()
    {
        return id;
    }

    void setId(int id)
    {
        this->id = id;
    }
};

template <typename T>
class Queue
{
    T *arr;
    int front;
    int back;
    int count;

public:
    Queue()
    {
        arr = new T[N];
        front = back = -1;
    }

    // Queue(int maxCapacity)
    // {
    //     arr = new T[maxCapacity];
    //     // capacity = maxCapacity;
    //     front = back = -1;
    // }
    ~Queue()
    {
        delete[] arr;
    }
    void Enqueue(T val)
    {
        if (back == N - 1)
        {
            cout << "The queue is full!" << endl;
        }
        else if (front == -1 && back == -1)
        {
            front = back = 0;
            arr[back] = val;
        }
        else
        {
            back++;
            arr[back] = val;
        }
    }
    T Dequeue()
    {
        if (front == -1 && back == -1)
        {
            cout << "The queue is empty!" << endl;
            // return T;
        }
        else if (front == back)
        {
            T temp = arr[back];
            front = back = -1;
            return temp;
        }
        else
        {
            T temp = arr[front];
            front++;
            return temp;
        }
    }
    bool isEmpty()
    {
        if (front == -1 && back == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isFull()
    {
        if (back == N - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void Clear()
    {
        front = -1;
        back = -1;
    }
    T firstElement()
    {
        if (front == -1 && back == -1)
        {
            cout << "The queue is empty!" << endl;
            // return;
        }
        else
        {
            return arr[front];
        }
    }
};

class WaitingRoom
{
    Queue<Patient> patients;
    static int id;

public:
    void RegisterPatient()
    {
        id++;
        string name;
        cout << "Enter the name of the patient: ";
        getline(cin, name);
        // Patient* p = new Patient(name, id);
        Patient p(name, id);
        patients.Enqueue(p);
        cout << "The patient has been successfully registered!" << endl;
    }

    void ServePatient()
    {
        if (patients.isEmpty())
        {
            cout << "There are no Patients to serve..!!" << endl;
            return;
        }
        Patient patient = patients.firstElement();
        patients.Dequeue();
        cout << "The Patient with name " << patient.getName() << " and Id " << patient.getId() << " is being served now..!!" << endl;
    }

    void CancelAll()
    {
        if (patients.isEmpty())
        {
            cout << "There are no pending appointments..!!" << endl;
            return;
        }
        while (!patients.isEmpty())
        {
            patients.Dequeue();
        }
        cout << "All appointments have been cancelled" << endl;
    }

    bool CanDoctorGoHome()
    {
        return patients.isEmpty();
    }

    void ShowAllPatients()
    {
        if (patients.isEmpty())
        {
            cout << "There are no patients to display..!!" << endl;
            return;
        }
        vector<Patient> p;
        while (!patients.isEmpty())
        {
            p.push_back(patients.firstElement());
            patients.Dequeue();
        }

        for (int i = 0; i < p.size() - 1; i++)
        {
            for (int j = 0; j < p.size() - i - 1; j++)
            {
                if (p[j].getName() > p[j + 1].getName())
                {
                    Patient temp = p[j];
                    p[j] = p[j + 1];
                    p[j + 1] = temp;
                }
            }
        }
        cout << "Patient Id\t\tPatient Name\n";
        for (int i = 0; i < p.size(); i++)
        {
            cout << p[i].getId() << "\t\t\t" << p[i].getName() << endl;
        }

        for (int i = 0; i < p.size() - 1; i++)
        {
            for (int j = 0; j < p.size() - i - 1; j++)
            {
                if (p[j].getId() > p[j + 1].getId())
                {
                    Patient temp = p[j];
                    p[j] = p[j + 1];
                    p[j + 1] = temp;
                }
            }
        }
        for (int i = 0; i < p.size(); i++)
        {
            patients.Enqueue(p[i]);
        }
    };
};

int WaitingRoom::id = 0;

int main()
{
    WaitingRoom waitingRoom;
    int choice = 0;
    // waitingRoom.RegisterPatient();
    // Display the menu
    // Get the user's choice
    while (choice != 6)
    {
        cout << "Waiting Room Management System:\n\n1. Register Patient\n2. Serve Patient\n3. Cancel All\n4. Can Doctor go Home?\n5. Show all Patients\n\n6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        system("CLS");
        // Perform the selected operation
        switch (choice)
        {
        case 1:
            waitingRoom.RegisterPatient();
            break;
        case 2:
            waitingRoom.ServePatient();
            break;
        case 3:
            waitingRoom.CancelAll();
            break;
        case 4:
            if (waitingRoom.CanDoctorGoHome())
            {
                cout << "Yes, the doctor can go home." << endl;
            }
            else
            {
                cout << "No, there are still patients waiting." << endl;
            }
            break;
        case 5:
            waitingRoom.ShowAllPatients();
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
    }

    return 0;
}
