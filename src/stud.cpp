#include "Student.h"

void Student::ived() {
    char pasirinkimas;

    cout << "Iveskite studento varda ir pavarde: ";
    cin >> vardas_ >> pavarde_;

    cout << "Ar sugeneruoti studento rezultatus? (t/n): ";
    cin >> pasirinkimas;

    if (pasirinkimas == 't') {
        srand(time(nullptr));
        for (int i = 0; i < 5; ++i) {
            addNd(rand() % 10 + 1);
        }
        setEgzaminas(rand() % 10 + 1);
    } else {
        int grade;
        cout << "Iveskite namu darbu rezultatus (-1 uzbaigti): ";
        while (cin >> grade && grade != -1) {
            addNd(grade);
        }
        cout << "Iveskite egzamino rezultata: ";
        cin >> grade;
        setEgzaminas(grade);
    }
}

double Student::calcGalBalasVid() const {
    if (nd_.empty()) throw runtime_error("Nera ivestu namu darbu rezultatu");
    double vidurkis = accumulate(nd_.begin(), nd_.end(), 0.0) / nd_.size();
    return 0.4 * vidurkis + 0.6 * egzaminas_;
}

double Student::calcGalBalasMed() const {
    if (nd_.empty()) throw runtime_error("Nera ivestu namu darbu rezultatu");
    vector<int> sortedNd = nd_;
    sort(sortedNd.begin(), sortedNd.end());
    double mediana = (sortedNd.size() % 2 == 0)
                     ? (sortedNd[sortedNd.size() / 2 - 1] + sortedNd[sortedNd.size() / 2]) / 2.0
                     : sortedNd[sortedNd.size() / 2];
    return 0.4 * mediana + 0.6 * egzaminas_;
}

int capacity_nustatymas(string failo_pavadinimas){
    int cap = 0;
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
        cap += 1;
    }
    return cap;
}

void generuotiFaila(const string& failoPavadinimas, int studentuSk) {
    ofstream outFile(failoPavadinimas);

    if (!outFile.is_open()) {
        cerr << "Nepavyko atidaryti failo.\n";
        return;
    }


    outFile << setw(20) << fixed << left << "Vardas" <<  fixed << left << setw(20) << "Pavarde";
    for (int i = 1; i <= 15; ++i) {
        outFile << setw(10) << fixed << left << "ND" + to_string(i);
    }
    outFile << setw(10)  << fixed << left << "Egz." << endl;


    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distNd(1, 10);
    uniform_int_distribution<> distEgz(1, 10);

    for (int i = 1; i <= studentuSk; ++i) {
        outFile << setw(20) << fixed << left << "Vardas" + to_string(i)
                << setw(20) << fixed << left << "Pavarde" + to_string(i);

        for (int j = 0; j < 15; ++j) {
            outFile << setw(10) << fixed << left << distNd(gen);
        }

        outFile << setw(10) << fixed << left << distEgz(gen) << endl;
    }

    outFile.close();
}

bool compareByName(const Student& st1, const Student& st2) {
    return st1.get_vardas() < st2.get_vardas()|| (st1.get_vardas() == st2.get_vardas() && st1.get_pavarde() < st2.get_pavarde());
}
bool compareByLastName(const Student& st1, const Student& st2) {
    return st1.get_pavarde() < st2.get_pavarde();
}
bool compareByMark(const Student& st1, const Student& st2) {
    return st1.get_galutinis() < st2.get_galutinis();
}

