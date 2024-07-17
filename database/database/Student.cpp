#pragma warning(disable: 4996)
#include "Student.h"
#include <iostream>

Student::Student() : Personal(), majorLen(10) {
    major = new char[majorLen + 1];
}

Student::Student(char* ssn, char* n, char* c, int y, long s, char* m) : Personal(ssn, n, c, y, s), majorLen(10) {
    major = new char[majorLen + 1];
    std::strcpy(major, m);
}

void Student::writeToFile(std::fstream& out) const {
    Personal::writeToFile(out);
    out.write(major, majorLen);
}

void Student::readFromFile(std::fstream& in) {
    Personal::readFromFile(in);
    in.read(major, majorLen);
}

std::ostream& Student::writeLegibly(std::ostream& out) {
    Personal::writeLegibly(out);
    major[majorLen] = '\0';
    out << ", major = " << major;
    return out;
}

std::istream& Student::readFromConsole(std::istream& in) {
    Personal::readFromConsole(in);
    char s[80];
    std::cout << "Major: ";
    in.getline(s, 80);
    std::strncpy(major, s, 9);
    major[9] = '\0';
    return in;
}
