#pragma once
#include <string>
#include "degree.h"

using namespace std;

class Student {
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysInCourse[3];
    DegreeProgram degreeProgram;

public:
    Student(string studentID, string firstName, string lastName,
        string emailAddress, int age, int daysInCourse[],
        DegreeProgram degreeProgram);

    string GetStudentID() const;
    string GetFirstName() const;
    string GetLastName() const;
    string GetEmailAddress() const;
    int GetAge() const;
    int* GetDaysInCourse();
    DegreeProgram GetDegreeProgram() const;

    void SetStudentID(string id);
    void SetFirstName(string first);
    void SetLastName(string last);
    void SetEmailAddress(string email);
    void SetAge(int age);
    void SetDaysInCourse(int days[]);
    void SetDegreeProgram(DegreeProgram degree);

    void Print();
};

