// Created by Noe on 29/06/24.

#ifndef DATABASE_STUDENT_H
#define DATABASE_STUDENT_H

#pragma once

#include "Personal.h"
#include <fstream>
#include <iostream>
#include <cstring>

class Student : public Personal {
public:
    Student();
    Student(char*, char*, char*, int, long, char*);
    void writeToFile(std::fstream&) const;
    void readFromFile(std::fstream&);
    int size() const {
        return Personal::size() + majorLen;
    }
protected:
    char* major;
     int majorLen=10;


    std::ostream& writeLegibly(std::ostream&);
    friend std::ostream& operator<<(std::ostream& out, Student& sr) {
        return sr.writeLegibly(out);
    }
    std::istream& readFromConsole(std::istream&);
    friend std::istream& operator>>(std::istream& in, Student& sr) {
        return sr.readFromConsole(in);
    }
};

#endif //DATABASE_STUDENT_H
