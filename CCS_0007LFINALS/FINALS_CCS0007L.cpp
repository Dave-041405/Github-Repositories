#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

struct Student {
    string studentID;
    string fullname;
    string birthday;
    string address;
    char gender;
    string degreeProgram;
    string yearLevel;
    Student* next; 
};

const string FILE_NAME = "records.txt";

void addRecord() {
    Student* newStudent = new Student();
    ofstream file(FILE_NAME.c_str(), ios::app);

    cout<<"Add new record"<<endl;
    cout<<"Enter Student ID: ";
    cin>>newStudent->studentID;
    cin.ignore();

    cout<<"Enter Full Name: ";
    getline(cin, newStudent->fullname);
    transform(newStudent->fullname.begin(), newStudent->fullname.end(), newStudent->fullname.begin(), ::toupper);

    cout<<"Enter Birthdate (mm/dd/yyyy): ";
    getline(cin, newStudent->birthday);
    transform(newStudent->birthday.begin(), newStudent->birthday.end(), newStudent->birthday.begin(), ::toupper);

    cout<<"Enter Address: ";
    getline(cin, newStudent->address);
    transform(newStudent->address.begin(), newStudent->address.end(), newStudent->address.begin(), ::toupper);

    cout<<"Enter Gender (M/F): ";
    cin>>newStudent->gender;
    newStudent->gender = toupper(newStudent->gender);
    cin.ignore();

    cout<<"Enter Degree Program: ";
    getline(cin, newStudent->degreeProgram);
    transform(newStudent->degreeProgram.begin(), newStudent->degreeProgram.end(), newStudent->degreeProgram.begin(), ::toupper);

    cout<<"Enter Year Level (1/2/3/4/Irregular): ";
    cin>>newStudent->yearLevel;
    transform(newStudent->yearLevel.begin(), newStudent->yearLevel.end(), newStudent->yearLevel.begin(), ::toupper);
    cin.ignore();

    newStudent->next = NULL; 

    if (file.is_open()) {
        file<<"Student ID: "<<newStudent->studentID<<endl;
        file<<"Full Name: "<<newStudent->fullname<<endl;
        file<<"Birthday: "<<newStudent->birthday<<endl;
        file<<"Address: "<<newStudent->address<<endl;
        file<<"Gender: "<<newStudent->gender<<endl;
        file<<"Degree Program: "<<newStudent->degreeProgram<<endl;
        file<<"Year Level (1/2/3/4/Irregular): "<<newStudent->yearLevel<<endl;
        file<<"-----------------"<<endl;
        cout<<"Record Added!"<<endl;
        file.close();
    } else {
        cout<<"Error in file creation!"<<endl;
    }

    delete newStudent; 
}

void searchRecord() {
    string searchID, line;
    bool found = false;

    cout<<"Search Record"<<endl;
    cout<<"Enter Student ID to search: ";
    cin>>searchID;
    transform(searchID.begin(), searchID.end(), searchID.begin(), ::toupper);
    cin.ignore();

    ifstream file(FILE_NAME.c_str());
    if (file.is_open()) {
        while (getline(file, line)) {
            if (line.find("Student ID: " + searchID) != string::npos) {
                found = true;
                cout<<"\nRecord Found:\n";
                cout<<line<<endl;
                for (int i = 0; i < 6; ++i) {
                    getline(file, line);
                    cout<<line<<endl;
                }
                cout<<"-----------------"<<endl;
                break;
            }
        }
        if (!found) {
            cout<<"No record found with Student ID: "<<searchID<<endl;
        }
        file.close();
    } else {
        cout<<"Unable to open file."<<endl;
    }
}

void displayRecords() {
    ifstream inFile(FILE_NAME.c_str());
    if (!inFile) {
        cout<<"Error: Unable to open file for reading."<<endl;
        return;
    }

    Student student;
    string line;
    while (getline(inFile, line)) {
        if (line.find("Student ID: ") != string::npos) {
            cout<<line<<endl;
            for (int i = 0; i < 6; ++i) { 
                getline(inFile, line);
                cout<<line<<endl;
            }
            cout<<"-----------------"<<endl;
        }
    }
    inFile.close();
}

void deleteRecord(string id) {
    ifstream inFile(FILE_NAME.c_str());
    ofstream tempFile("temp.txt");

    if (!inFile || !tempFile) {
        cout<<"Error: Unable to open file for reading or writing."<<endl;
        return;
    }

    string line;
    bool found = false;
    while (getline(inFile, line)) {
        if (line.find("Student ID: " + id) != string::npos) {
            for (int i = 0; i < 7; ++i) { 
                getline(inFile, line);
            }
            found = true;
        } else {
            tempFile<<line<<endl;
        }
    }
    inFile.close();
    tempFile.close();

    remove(FILE_NAME.c_str());
    rename("temp.txt", FILE_NAME.c_str());

    if (found) {
        cout<<"Record deleted successfully."<<endl;
    } else {
        cout<<"No record found with Student ID: "<<id<<endl;
    }
}

int main() {
    int choice;
    do {
        cout <<"1. Add Record\n2. Search Record\n3. Delete Record\n4. Display Records\n5. Exit"<<endl;
        cout<<"Please enter your selection: ";
        cin>>choice;
        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                searchRecord();
                break;
            case 3:
                {
                    string id;
                    cout<<"Enter Student ID to delete: ";
                    cin>>id;
                    deleteRecord(id);
                }
                break;
            case 4:
                displayRecords();
                break;
            default:
                break;
        }
    } while (choice != 5);

    cout<<"Group: Solo"<<endl;
    cout<<"Members: Dave Maurece P. Rivas"<<endl;

    return 0;
}

