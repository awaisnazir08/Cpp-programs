// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main()
{
    char message[] = "hello";
    char *pmessage = "hello";
    cout << message[0] << endl;
    cout << message << endl;
    cout<<&message[0]<<endl;
    cout<<&message<<endl;
    cout<<pmessage<<endl;
    cout<<*pmessage<<endl;
    char *months[] = {"Illegal month", "Jan", "Feb", "Mar"};
    cout << *(months + 2) << endl;
    cout << *(months[3] + 2) << endl;
    cout << *months[3] << endl;
    cout << months[3] << endl;
    cout<<&months[3]<<endl;
    cout<<&months<<endl;
    cout<<months<<endl;
    cout<<&months[0]<<endl;
    // int arr[]={1,2,3,5};

    return 0;
}