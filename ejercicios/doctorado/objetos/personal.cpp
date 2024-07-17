//[/ Rr kR kR Rk kxR Ak Rk kR % personal,h KAk kkkkkkkk kR kA kKA Rk
#ifndef PERSONAL
#define PERSONAL
#include <fstreams #include <cstring> using namespace std;
class Personal {
public:
    Personal () ;
    Personal (char*,char*,char*,int,long) ;
    void writeToFile (fstream£) const;
    void readFromFile(fstreamé) ;
    void readKey ();
    int size() const (
    return 9 + nameLen + citylen + sizeof (year) + sizeof (salary) ;
    )
    bool operator==(const Personalé pr) const (
    return strncmp (pr.SSN,SSN,9) == 0;
    ) protected:
    const int nameLen, cityLen;
    char SSN[10], *name, *city;
    int year;
    long salary;
    ostreamé writeLegibly (ostreame) ;
    friend ostream& operator<<(ostream& out, Personal& pr) (
    return pr.writeLegibly (out) ;
    )
    istream& readFromConsole (istreamé) ;
    friend istream& operator>>(istreamá in, Personalé pr) (
    return pr.readFromConsole (in) ;
    );
#endif
   // ] kxR R Rk kR k kR ko AEA persOnal.Cpp kR kK kA kkk Rk kKR KAk
#include "personal.h"
    Personal: :Personal () : nameLen(10), cityLen(10) (
    name = new char [nameLen+1] ;

    city = new char[cityLen+1] ;
    Personal: :Personal (char *ssn, char *n, char *c, int y, long s)
    nameLen (10), cityLen(10) (
    name = new char[nameLen+1] ; city = new char[cityLen+1];
    strcpy (SSN, ssn) ;
    strcpy (name,n) ;
    strepy (city,c); year = y;
    salary = s;
    )
    void Personal: :writeToFile (fstream& out) const (
    out.write (SSN,9) ;
    out.write (name, nameLen) ;
    out.write(city,cityLen) ;
    out.write(reinterpret_cast<const char*>(£year),sizeof (int));
    out.write(reinterpret_cast<const char*>(&salary),sizeof (int));
    void Personal::readFromFile (fstream& in) (
            in.read (SSN, 9) ;
    in.read (name, nameLen) ;
    in.read(city,cityLen) ;
    in.read(reinterpret cast<char*> (£year), sizeof (int));
    in.read(reinterpret cast<char*> (&salary),sizeof (int));
    )
    void Personal: :readKey () ( char s[80]; cout << "Enter SSN: "; cin.getline (s,80) ; strncpy (SSN, s, 9) ;
    )
    ostream& Personal: :writeLegibly (ostreams out) (
    SSN[9] = name[nameLen] = city[cityLen] = '\0';
    out << "SSN = " << SSN << ", name = " << name << ", city = " << city << ", year = " << year
    << ", salary = " << salary;
    return out;


    istream& Personal: :readFromConsole (istreams in) (
    SSN[9] = name[nameLen] = city[cityLen]
    char s[80];
    cout << "SSN: ";
    in.getline(s,80);
    strncpy (SSN, s, 9) ;
    cout << "Name: ";
    in.getline(s,80);
    strncpy (name, s, nameLen) ;
    TEHiEgs Dh
    in.getline(s,80);
    strncpy (city, s, cityLen) ;
    cout << "Birthyear:
    in >> year; "Salary:
    in >> salary;
    in.ignore() ;
    return in;
    cout <<
    cout <<
    ) [ A a AA AA
#ifndef STUDENT
#define STUDENT
#include "personal.h"
    student.h
    class Student
public:
    Student () ;
public Personal {
        "No';
        ANAN
        Student (char*,char*,char*,int,long,char*) ;
        void writeToFile(fstream£) const;
        void readFromFile (fstream£) ; int size() const {
            return Personal: :size()
            ) protected:
            char *major;
            + majorLen;
            const int majorLen;
            ostream& writeLegibly (ostream&) ;
            friend ostream& operator<<(ostream& out
            return sr.writeLegibly (out);
        } istreams readFromConsole (istreamé) ;
        Student& sr) (
        friend istreamé operator>>(istream& in, Student& sr) ( return sr.readFromConsole (in) ;
        )
#endif

        // / Sstudent.cpp kR kAR Ak Rk Rk kK ARk
#include "student.h"
        Student: :Student () : majorLen(10) (
                Personal () ; major = new char[majorLen+1] ;
        Student : :Student (char *ssn, char *n, char *c, int y, long s, char *m)
        majorLen(11) (
                Personal (ssn,n,c,y,s); major = new char [majorLen+1] ;
        strepy (major,m) ;
        void Student
        Personal
        riteToFile (fstream& out) const (
                riteToFile(out);
        out .write (major,majorLen) ;
        void Student::readFromFile (fstreame in) (
                Personal : :readFromFile (in) ;
        in.read (major, majorLen) ;
        ostream& Student::writeLegibly (ostream& out) ( Personal : :writeLegibly (out) ; major [majorLen] = 'V0'; out << ", major = " << major;
        return out;
        istream& Student::readFromConsole (istream& in) (
                Personal: : readFromConsole (in) ;
        char s[80];
        cout << "Major: ";
        in.getline (s,80);
        strncpy (major,s,9);
        return in;

        (/]44X Xaa AAAAAAAAAAAAAAA database.h +*9X**x*AA AEA
#ifndef DATABASE
#define DATABASE
        template<class T>
        class Database ( public:
        Database () ; void
        private: run();
        fstream database;
        char fName [20] ;
        ostream& print (ostream£) ;
        void
        bool
        void
        add (T&) ; find(const T&);
        modify (const T&) ;
        friend ostream& operator<<(ostream& out,
        )i
#endif
        return db.print (out) ;
        Database& db) (
        /[XXARARAARAARAAA TRAR database.cpp kR kK Kk x kR Kk kKRR Ak
#include
#include
#include
#include
                <iostream>
        "student .h"
        "personal.h"
        "database.h"
        template<class T>
        Database<T>: :Database () (
        )
        template<class T>
        void Database<T>::add(T& d) (
                database.open (fName,ios::in|ios::out |ios: :binary) ;
        database.seekp (0,ios: nd) ;
        d.writeToFile (database) ;
        database.close(); ) template<class T>
        void Database<T>: :modify (const Te d) (