#include <iostream>
#include <sstream>
#include "roster.h"

using namespace std;

void Roster::ParseThenAdd(string row) {
    stringstream ss(row);
    string id, first, last, email, degreeStr;
    int age, d1, d2, d3;
    DegreeProgram degree;

    getline(ss, id, ',');
    getline(ss, first, ',');
    getline(ss, last, ',');
    getline(ss, email, ',');
    ss >> age;
    ss.ignore();
    ss >> d1;
    ss.ignore();
    ss >> d2;
    ss.ignore();
    ss >> d3;
    ss.ignore();
    getline(ss, degreeStr);

    if (degreeStr == "SECURITY") degree = SECURITY;
    else if (degreeStr == "NETWORK") degree = NETWORK;
    else degree = SOFTWARE;

    Add(id, first, last, email, age, d1, d2, d3, degree);
}

void Roster::Add(string id, string first, string last, string email, int age, int d1, int d2, int d3, DegreeProgram degree) {
    int days[3] = { d1, d2, d3 };
    classRosterArray[++lastIndex] = new Student(id, first, last, email, age, days, degree);
}

void Roster::Remove(string id) {
    bool found = false;
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->GetStudentID() == id) {
            found = true;
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
            cout << "Student " << id << " removed.\n";
            break;
        }
    }
    if (!found) cout << "Student " << id << " not found.\n";
}

void Roster::PrintAll() {
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i] != nullptr) classRosterArray[i]->Print();
    }
}

void Roster::PrintAverageDaysInCourse(string id) {
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i]->GetStudentID() == id) {
            int* days = classRosterArray[i]->GetDaysInCourse();
            cout << "Student " << id << " average days in course: "
                << (days[0] + days[1] + days[2]) / 3 << endl;
        }
    }
}

void Roster::PrintInvalidEmails() {
    for (int i = 0; i <= lastIndex; ++i) {
        string email = classRosterArray[i]->GetEmailAddress();
        if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos) {
            cout << "Invalid email: " << email << endl;
        }
    }
}

void Roster::PrintByDegreeProgram(DegreeProgram degree) {
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i]->GetDegreeProgram() == degree) {
            classRosterArray[i]->Print();
        }
    }
}

Roster::~Roster() {
    for (int i = 0; i <= lastIndex; ++i) {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}

