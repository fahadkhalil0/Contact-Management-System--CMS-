#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// contact management system
// class
class temp
{
    fstream file;
    string phoneNo, name, address, description, search;

public:
    void addContact();
    void showAll();
    void searchContact();
} obj;

// main function
int main()
{

    int choice;
    cout << "1---> Add Contact :: " <<endl;
    cout << "2--->  Show All :: " <<endl;
    cout << "3---> Search Contact :: " <<endl;
    cout << "4---> Exit :: " <<endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
        obj.addContact();
        break;
    case 2:
        obj.showAll();
        break;
    case 3:
        obj.searchContact();
        break;
    case 4:
        cout << "Exiting from the program... " <<endl;
        break;
    default:
    cout << " Enter the valid choice.... " <<endl;
        break;
    }

    return 0;
}

void temp ::addContact()
{
    cin.ignore();
    cout << " PhoneNo ::";
    getline(cin, phoneNo);
    cout << " Name ::";
    getline(cin, name);
    cout << " Address ::";
    getline(cin, address);
    cout << " Description ::";
    getline(cin, description);

    file.open("data.csv", ios::out | ios::app);
    file << phoneNo << "," << name << "," << address << "," << description << "\n";
    file.close();
}

void temp ::showAll()
{
    file.open("data.csv", ios::in);
    getline(file, phoneNo, ',');
    getline(file, name, ',');
    getline(file, address, ',');
    getline(file, description);

    while (!file.eof())
    {
        cout << " Phone No :: " << phoneNo << endl;
        cout << "  name :: " << name << endl;
        cout << "  address :: " << address << endl;
        cout << " description :: " << description << endl;

        cout << endl;

        getline(file, phoneNo, ',');
        getline(file, name, ',');
        getline(file, address, ',');
        getline(file, description);
    }
    file.close();
}

void temp ::searchContact()
{
    cin.ignore();
    cout << " Enter the phone no:: " << endl;
    getline(cin, search);

    file.open("data.csv", ios::in);
    getline(file, phoneNo, ',');
    getline(file, name, ',');
    getline(file, address, ',');
    getline(file, description);

    while (!file.eof())
    {
        if (phoneNo == search)
        {
            cout << " Phone No :: " << phoneNo << endl;
            cout << "  name :: " << name << endl;
            cout << "  address :: " << address << endl;
            cout << " description :: " << description << endl;
        }
        
            getline(file, phoneNo, ',');
            getline(file, name, ',');
            getline(file, address, ',');
            getline(file, description);
    }
    file.close();
}