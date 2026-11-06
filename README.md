# C++ Student Roster

**WGU C867 · Scripting and Programming: Applications**

A class roster app in C++. It reads student records from text, stores them, and runs reports on them. C++ doesn't clean up memory for you, so a big part of this project is freeing every object it creates.

## What it does

Each student has an ID, name, email, age, days spent in 3 courses, and a degree program.

- **Add:** splits a text record into fields and creates a student.
- **Remove:** deletes a student by ID and says whether it worked.
- **Print all:** lists every student still on the roster.
- **Average days:** shows a student's average days per course.
- **Bad emails:** flags any email missing an `@` or `.`, or containing a space.
- **By degree:** lists only Security, Network or Software students.

## How it's built

- `Student` class holds one record, with private data and getters.
- `Roster` class holds an array of pointers to students.
- Degree programs are an `enum`, so only valid values are possible.
- When the roster closes, it deletes every student and clears every pointer. No memory leaks.

## Run it

Open the `.sln` in Visual Studio, or:

```
g++ main.cpp roster.cpp student.cpp -o roster
./roster
```

## Files

- `main.cpp`: runs the program
- `roster.cpp`, `roster.h`: the roster and its reports
- `student.cpp`, `student.h`: the student record
- `degree.h`: degree program list

**Built with:** C++
