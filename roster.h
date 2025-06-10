#ifndef ROSTER_H
#define ROSTER_H

#include "student.h"

class Roster {
public:
    const static int numStudents = 5;
    Student* classRosterArray[numStudents] = { nullptr };
    int lastIndex = -1;

    // Required methods
    void ParseThenAdd(std::string row);
    void Add(std::string id, std::string first, std::string last, std::string email, int age, int d1, int d2, int d3, DegreeProgram degree);
    void Remove(std::string id);
    void PrintAll();
    void PrintAverageDaysInCourse(std::string id);
    void PrintInvalidEmails();
    void PrintByDegreeProgram(DegreeProgram degree);

    // Destructor
    ~Roster();
};

#endif



