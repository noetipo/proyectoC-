#include "Personal.h" // Nombre de la cabecera con minúscula
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

Personal::Personal() : nameLen(10), cityLen(10) {
    name = new char[nameLen + 1];
    city = new char[cityLen + 1];
}

Personal::Personal(char *ssn, char *n, char *c, int y, long s)
        : nameLen(10), cityLen(10), year(y), salary(s) {
    name = new char[nameLen + 1];
    city = new char[cityLen + 1];
    strncpy(SSN, ssn, 9);
    strncpy(name, n, nameLen);
    strncpy(city, c, cityLen);
}

void Personal::writeToFile(fstream& out) const {
    out.write(SSN, 9);
    out.write(name, nameLen);
    out.write(city, cityLen);
    out.write(reinterpret_cast<const char*>(&year), sizeof(int));
    out.write(reinterpret_cast<const char*>(&salary), sizeof(long));
}

void Personal::readFromFile(fstream& in) {
    in.read(SSN, 9);
    in.read(name, nameLen);
    in.read(city, cityLen);
    in.read(reinterpret_cast<char*>(&year), sizeof(int));
    in.read(reinterpret_cast<char*>(&salary), sizeof(long));
}

void Personal::readKey() {
    char s[80];
    cout << "Enter SSN: ";
    cin.getline(s, 80);
    strncpy(SSN, s, 9);
}

ostream& Personal::writeLegibly(ostream& out) {
    SSN[9] = name[nameLen] = city[cityLen] = '\0';
    out << "SSN = " << SSN << ", name = " << name
        << ", city = " << city << ", year = " << year
        << ", salary = " << salary;
    return out;
}

istream& Personal::readFromConsole(istream& in) {
    SSN[9] = name[nameLen] = city[cityLen] = '\0';
    char s[80];
    cout << "SSN: ";
    in.getline(s, 80);
    strncpy(SSN, s, 9);
    cout << "Name: ";
    in.getline(s, 80);
    strncpy(name, s, nameLen);
    cout << "City: ";
    in.getline(s, 80);
    strncpy(city, s, cityLen);
    cout << "Birthyear: ";
    in >> year;
    cout << "Salary: ";
    in >> salary;
    in.ignore();
    return in;
}
