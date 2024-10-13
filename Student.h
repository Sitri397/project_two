#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include "mylib.h"

struct Student {
    string vardas;
    string pavarde;
    vector<int> nd;
    int egzaminas;
    double galutinis;
};

void ived(Student &st);
void valymas(Student &Lok);
double Gal_Balas_vid(Student &Lok);
double Gal_Balas_med(Student &Lok);
void isvedimas(vector<Student> &galvociai,vector<Student> &nuskriaustikai, char &pasirinkimas);
void nuskaitymasIsFailo(vector<Student> &students,string failo_pavadinimas);
int comper(Student& st1, Student& st2);
int capacity_nustatymas(string failo_pavadinimas);
void generuotiFaila(const string& failoPavadinimas, int studentuSk);
void priskirti_grupej(Student& temp,vector<Student> &nuskriaustukai,vector<Student> &galvociai);


#endif // STUDENT_H_INCLUDED
