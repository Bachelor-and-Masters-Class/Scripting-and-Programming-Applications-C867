**Overview**

This repository contains my completed submission for the WGU course **C867 – Scripting and Programming: Applications**.

The project is a **C++ student roster management application** demonstrating object-oriented design in a language without automatic memory management. The program parses a set of student records from delimited string data, stores them as dynamically allocated objects, and provides reporting operations across the roster.

Because C++ requires the developer to manage memory explicitly, a significant part of this assignment is correct allocation and deallocation: every object created on the heap is released through a destructor that walks the roster and frees each record.

**Scenario**

A university needs a small application to manage a class roster. Each student record contains an ID, first and last name, email address, age, the number of days spent in each of three courses, and a degree program.

The application must parse these records from raw delimited input, expose them through a set of reporting operations, and validate email formatting to catch data entry errors.

**Project Objectives**

-Design a class structure using object-oriented principles

-Parse delimited string records into fully constructed objects

-Manage dynamically allocated memory correctly, with no leaks

-Implement reporting operations across the roster

-Validate email address formatting and report invalid entries

-Filter and display students by degree program

**Technical Implementation**

**Student Class**
Encapsulates a single student record with private data members and public accessors. Days in course are stored as a fixed-size array, and the class provides a print method that formats the record for output.

**Degree Program Enumeration**
A DegreeProgram enumerated type defines SECURITY, NETWORK, and SOFTWARE. Using an enumeration rather than raw strings makes degree comparisons type-safe and prevents invalid values from entering the system.

**Roster Class**
Manages an array of Student pointers and provides the application's core operations:

-**ParseThenAdd** – tokenizes a delimited record with a string stream, converts the degree string into its enumerated value, and delegates to Add

-**Add** – constructs a new Student on the heap and stores its pointer in the roster array

-**Remove** – locates a student by ID, deletes the object, nulls the pointer, and reports whether the removal succeeded

-**PrintAll** – prints every active record, skipping removed entries

-**PrintAverageDaysInCourse** – computes and prints the mean days in course for a given student ID

-**PrintInvalidEmails** – flags any email address missing an at sign or a period, or containing a space

-**PrintByDegreeProgram** – prints only students enrolled in a specified degree program

**Memory Management**
The Roster destructor iterates the full array, deletes each allocated Student, and sets each pointer to null, ensuring all heap memory is released at program termination.

**Skills Demonstrated**

-Object-oriented programming in C++

-Class design with encapsulation and accessor methods

-Header and implementation file separation

-Dynamic memory allocation and explicit deallocation

-Destructor implementation and resource cleanup

-Pointer arrays and pointer lifecycle management

-String parsing with string streams

-Enumerated types for type-safe domain values

-Input validation logic

**How to Build and Run**

Open the solution in Visual Studio and build, or compile from the command line:

```
g++ main.cpp roster.cpp student.cpp -o roster
./roster
```

**Repository Contents**

-`main.cpp`, `main.h` – Program entry point and roster driver logic

-`roster.cpp`, `roster.h` – Roster class: parsing, add, remove, and reporting operations

-`student.cpp`, `student.h` – Student class definition and implementation

-`degree.h` – DegreeProgram enumeration

-`C867GitLab.sln`, `C867GitLab.vcxproj` – Visual Studio solution and project files
