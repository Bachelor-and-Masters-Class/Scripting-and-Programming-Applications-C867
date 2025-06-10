#include <iostream>
#include "student.h"

using namespace std;

Student::Student(string studentID, string firstName, string lastName,
    string emailAddress, int age, int daysInCourse[],
    DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int i = 0; i < 3; i++) this->daysInCourse[i] = daysInCourse[i];
    this->degreeProgram = degreeProgram;
}

string Student::GetStudentID() const { return studentID; }
string Student::GetFirstName() const { return firstName; }
string Student::GetLastName() const { return lastName; }
string Student::GetEmailAddress() const { return emailAddress; }
int Student::GetAge() const { return age; }
int* Student::GetDaysInCourse() { return daysInCourse; }
DegreeProgram Student::GetDegreeProgram() const { return degreeProgram; }

void Student::SetStudentID(string id) { studentID = id; }
void Student::SetFirstName(string first) { firstName = first; }
void Student::SetLastName(string last) { lastName = last; }
void Student::SetEmailAddress(string email) { emailAddress = email; }
void Student::SetAge(int age) { this->age = age; }
void Student::SetDaysInCourse(int days[]) {
    for (int i = 0; i < 3; i++) daysInCourse[i] = days[i];
}
void Student::SetDegreeProgram(DegreeProgram degree) { degreeProgram = degree; }

void Student::Print() {
    cout << studentID << "\tFirst Name: " << firstName
        << "\tLast Name: " << lastName
        << "\tAge: " << age
        << "\tdaysInCourse: {" << daysInCourse[0] << ", "
        << daysInCourse[1] << ", " << daysInCourse[2] << "}"
        << "\tDegree Program: ";

    switch (degreeProgram) {
    case SECURITY: cout << "SECURITY"; break;
    case NETWORK:  cout << "NETWORK";  break;
    case SOFTWARE: cout << "SOFTWARE"; break;
    }
    cout << endl;
}
