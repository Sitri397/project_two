//Student.h
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

Student get(list<Student> _list, int _i);
Student get(vector<Student> &vec,int i);

int comper_by_name(Student& st1, Student& st2);
int comper_by_last_name(Student& st1, Student& st2);
int comper_by_mark(Student& st1, Student& st2);
int capacity_nustatymas(string failo_pavadinimas);
void generuotiFaila(const string& failoPavadinimas, int studentuSk);

template <typename T>
void isvedimas(T &galvociai,T &nuskriaustikai, char &pasirinkimas) {
    Student Lok;
    ofstream wr1("nuskriaustikai.txt");
    ofstream wr2("galvociai.txt");
    if(pasirinkimas == 'v'){
        wr1 << setw(15) << fixed << left << "Vardas" << setw(15) << fixed << left << "Pavarde" << setw(3) << fixed << right << "Galutinis (Vid.)" << endl;
        wr1 << string(50, '-') << endl;
        wr2 << setw(15) << fixed << left << "Vardas" << setw(15) << fixed << left << "Pavarde" << setw(3) << fixed << right << "Galutinis (Vid.)" << endl;
        wr2 << string(50, '-') << endl;
    }
    else if(pasirinkimas == 'm'){
        wr1 << setw(15) << fixed << left << "Vardas" << setw(15) << fixed << left << "Pavarde" << setw(3) << fixed << right << "Galutinis (Med.)" << endl;
        wr1 << string(50, '-') << endl;
        wr2 << setw(15) << fixed << left << "Vardas" << setw(15) << fixed << left << "Pavarde" << setw(3) << fixed << right << "Galutinis (Med.)" << endl;
        wr2 << string(50, '-') << endl;
    }
    ostringstream ss;
    auto start = std::chrono::high_resolution_clock::now();
    for(auto &st: galvociai){
        ss << setw(15) << fixed << left << st.vardas
        << setw(15) << fixed << left << st.pavarde
        << setw(3) << fixed << right << setprecision(2)
        << st.galutinis << endl;
    }
    wr2 << ss.str();
    wr2.close();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start;
    cout <<"Galvociu irasymo laikas: " << diff.count() << endl;
    ss.str("");
    ss.clear();
    start = std::chrono::high_resolution_clock::now();
    for(auto &st:nuskriaustikai){
        ss << setw(15) << fixed << left << st.vardas
        << setw(15) << fixed << left << st.pavarde
        << setw(3) << fixed << right << setprecision(2)
        << st.galutinis << endl;
    }
    wr1 << ss.str();
    wr1.close();
    end = std::chrono::high_resolution_clock::now();
    diff = end-start;
    cout <<"Nuskriaustiku irasymo laikas: " << diff.count() << endl;


}

template <typename T>
void nuskaitymasIsFailo(T &students, string failo_pavadinimas) {
    ifstream inFile(failo_pavadinimas);
    if (!inFile) {
        throw runtime_error("Neisejo atidaryti failo: " + failo_pavadinimas);
    }

    stringstream FileStream;
    FileStream << inFile.rdbuf();
    inFile.close();
    string line;
    getline(FileStream,line);

    while (getline(FileStream, line)) {
        istringstream iss(line);
        Student temp;
        string vardas, pavarde;
        iss >> vardas >> pavarde;
        temp.vardas = vardas;
        temp.pavarde = pavarde;

        int rezultatas;
        vector<int> nd;
        while (iss >> rezultatas) {
            nd.push_back(rezultatas);
        }


        if (!nd.empty()) {
            temp.egzaminas = nd.back();
            nd.pop_back();
            temp.nd = nd;
        } else {
            cout << "Klaida: studentas neturi pazymiu: " << temp.vardas << " " << temp.pavarde << endl;
            continue;
        }

        students.push_back(temp);
    }

}


template <typename T>
void priskirti_grupej(T &vec,T &nuskriaustukai,T &galvociai){
    for(auto &st: vec){
        if(st.galutinis < 5){
            nuskriaustukai.push_back(st);
        }
        else{
            galvociai.push_back(st);
        }
    }
}


#endif // STUDENT_H_INCLUDED
