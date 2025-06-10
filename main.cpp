#include <iostream>
#include <sstream>  // ? Required for stringstream and getline
#include <string>
#include "roster.h" // ? Make sure to include your Roster class

using namespace std;

int main() {
    cout << "Course Title: C867 – Scripting and Programming – Applications\n";
    cout << "Programming Language: C++\n";
    cout << "WGU Student ID: [012194418]\n";
    cout << "Name: [Michael Williams]\n\n";

    const string studentData[] = {
        "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_Lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Michael,Williams,mwill199@wgu.edu,25,20,25,30,SOFTWARE"
    };

    Roster classRoster;

    // Loop through student data and add each student
    for (int i = 0; i < 5; ++i) {
        classRoster.ParseThenAdd(studentData[i]);
    }

    cout << "Displaying all students:\n";
    classRoster.PrintAll();
    cout << "\n";

    cout << "Displaying invalid emails:\n";
    classRoster.PrintInvalidEmails();
    cout << "\n";

    for (int i = 0; i < 5; ++i) {
        classRoster.PrintAverageDaysInCourse(classRoster.classRosterArray[i]->GetStudentID());
    }
    cout << "\n";

    cout << "Displaying students by degree program: SOFTWARE\n";
    classRoster.PrintByDegreeProgram(SOFTWARE);
    cout << "\n";

    cout << "Removing student with ID A3:\n";
    classRoster.Remove("A3");
    cout << "\n";

    cout << "Attempting to remove student A3 again:\n";
    classRoster.Remove("A3");
    cout << "\n";

    return 0;
}

