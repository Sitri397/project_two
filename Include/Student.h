#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include "mylib.h"

class Student {
private:
    string vardas_;
    string pavarde_;
    vector<int> nd_;
    int egzaminas_ = 0;
    double galutinis_ = 0.0;

public:
    Student() = default;
    Student(const string& vardas, const string& pavarde) : vardas_(vardas), pavarde_(pavarde) {}

    Student(const Student& other)
        : vardas_(other.vardas_), pavarde_(other.pavarde_),
          nd_(other.nd_), egzaminas_(other.egzaminas_),
          galutinis_(other.galutinis_) {}


    Student& operator=(const Student& other) {
        if (this != &other) {
            vardas_ = other.vardas_;
            pavarde_ = other.pavarde_;
            nd_ = other.nd_;
            egzaminas_ = other.egzaminas_;
            galutinis_ = other.galutinis_;
        }
        return *this;
    }

    friend istream& operator>>(istream& in, Student& student);
    friend ostream& operator<<(ostream& out, const Student& student);

    string get_vardas() const { return vardas_; }
    string get_pavarde() const { return pavarde_; }
    vector<int> get_nd() const { return nd_; }
    int get_egzaminas() const { return egzaminas_; }
    double get_galutinis() const { return galutinis_; }


    void setVardas(const string& vardas) { vardas_ = vardas; }
    void setPavarde(const string& pavarde) { pavarde_ = pavarde; }
    void addNd(int grade) { nd_.push_back(grade); }
    void setEgzaminas(int grade) { egzaminas_ = grade; }
    void setGalutinis(double balas) { galutinis_ = balas; }
    void setNd(vector<int> nd) {nd_ = nd;}


    void clear() {
        vardas_.clear();
        pavarde_.clear();
        nd_.clear();
        egzaminas_ = 0;
        galutinis_ = 0.0;
    }

    double calcGalBalasVid() const;
    double calcGalBalasMed() const;

    void ived();

    ~Student() {
    vardas_.clear();
    pavarde_.clear();
    nd_.clear();
}






};

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
        ss << st << endl;
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
        ss << st << endl;
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
        temp.setVardas(vardas);
        temp.setPavarde(pavarde);

        int rezultatas;
        vector<int> nd;
        while (iss >> rezultatas) {
            nd.push_back(rezultatas);
        }


        if (!nd.empty()) {
            temp.setEgzaminas(nd.back());
            nd.pop_back();
            temp.setNd(nd);
        } else {
            cout << "Klaida: studentas neturi pazymiu: " << temp.get_vardas() << " " << temp.get_pavarde() << endl;
            continue;
        }

        students.push_back(temp);
    }

}

template <typename T>
void priskirti_grupej_1(T &vec,T &nuskriaustukai,T &galvociai){
    for(auto &st: vec){
        if(st.get_galutinis() < 5){
            nuskriaustukai.push_back(st);
        }
        else{
            galvociai.push_back(st);
        }
    }
}

template <typename Container>
void priskirti_grupej_2(Container& students, Container &nuskriaustukai) {
   for (auto it = students.begin(); it != students.end();) {
       if (it->get_galutinis() < 5) {
            nuskriaustukai.push_back(*it);
            it = students.erase(it);
        } else {
           ++it;
        }
    }
}

template <typename Container>
void priskirti_grupej_3(Container& students, Container& vargsiukai) {
    auto partition_point = std::stable_partition(students.begin(), students.end(), [](const Student& st) {
        return st.get_galutinis() >= 5;
    });


    vargsiukai.insert(vargsiukai.end(), partition_point, students.end());

    students.erase(partition_point, students.end());
}

bool compareByName(const Student& st1, const Student& st2);


bool compareByLastName(const Student& st1, const Student& st2) ;

bool compareByMark(const Student& st1, const Student& st2) ;


int capacity_nustatymas(string failo_pavadinimas);
#endif // STUDENT_H_INCLUDED
