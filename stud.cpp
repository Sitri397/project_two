#include "Student.h"


void ived(Student &st) {
    string input;
    int rezultatas;
    char pasirinkimas;
    cout << "Iveskite studento varda ir pavarde: " << endl;
    cin >> st.vardas >> st.pavarde;

    cout << "Ar sugeneruoti studento namu darbu ir egzamino rezultatus? (t/n): " << endl;
    cin >> pasirinkimas;
    if (pasirinkimas == 't') {
        srand(time(nullptr));
        for (int i = 0; i < 5; ++i) {
            st.nd.push_back(rand() % 10 + 1);
        }
        st.egzaminas = rand() % 10 + 1;
    } else if (pasirinkimas == 'n') {
        cout << "Iveskite namu darbu rezultatus (-1 uzbaigti)" << endl;
        while (true) {
            cin >> input;
            try {
                rezultatas = stoi(input);
                if (rezultatas == -1) break;
                if (rezultatas < 0 || rezultatas > 10) {
                    cout << "Netinkamas ivestis! Prasome ivesti skaiciu nuo 1 iki 10 arba -1, kad uzbaigti." << endl;
                    continue;
                }
                st.nd.push_back(rezultatas);
            } catch (invalid_argument&) {
                cout << "Neteisingas formatas! Prasome ivesti skaiciu arba -1, kad baigti." << endl;
                cin.clear();
                cin.ignore();
            }
        }


        cout << "Iveskite egzamino rezultata: " << endl;
        while (true) {
            cin >> input;
            try {
                st.egzaminas = stoi(input);
                if (st.egzaminas < 0 || st.egzaminas > 10) {
                    cout << "Netinkamas egzamino rezultatas! Prasome ivesti skaiciu nuo 1 iki 10." << endl;
                    continue;
                }
                break;
            } catch (invalid_argument&) {
                cout << "Neteisingas formatas! Prasome ivesti skaiciu." << endl;
                cin.clear();
                cin.ignore();
            }
        }
    }
}


void valymas(Student &Lok) {
    Lok.vardas.clear();
    Lok.pavarde.clear();
    Lok.nd.clear();
}


double Gal_Balas_vid(Student &Lok) {
    if (Lok.nd.empty()) throw runtime_error("Nera ivestu namu darbu rezultatu");
    double sum = 0;
    for (int i = 0; i < Lok.nd.size(); i++) {
        sum += Lok.nd.at(i);
    }
    double vid = sum / Lok.nd.size();
    return 0.4 * vid + Lok.egzaminas * 0.6;
}


double Gal_Balas_med(Student &Lok) {
    if (Lok.nd.empty()) throw runtime_error("Nera ivestu namu darbu rezultatu");
    vector<int> darbai = Lok.nd;
    sort(darbai.begin(), darbai.end());
    double mediana;
    int size = darbai.size();

    if (size % 2 == 0) {
        mediana = (darbai[size / 2 - 1] + darbai[size / 2]) / 2.0;
    } else {
        mediana = darbai[size / 2];
    }
    return 0.4 * mediana + 0.6 * Lok.egzaminas;
}


void isvedimas(Student &Lok, char mode) {
    ostringstream ss;
    if (mode == 'v') {
        ss << setw(15) << fixed << left << Lok.vardas
           << setw(15) << fixed << left << Lok.pavarde
           << setw(3) << fixed << right << setprecision(2)
           << Gal_Balas_vid(Lok) << endl;
    } else if (mode == 'm') {
        ss << setw(15) << fixed << left << Lok.vardas
           << setw(15) << fixed << left << Lok.pavarde
           << setw(3) << fixed << right << setprecision(2)
           << Gal_Balas_med(Lok) << endl;
    }

    cout << ss.str();
}


void nuskaitymasIsFailo(vector<Student> &students, string failo_pavadinimas) {
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


int comper(Student& st1, Student& st2) {
    if (st1.vardas != st2.vardas) {
        return st1.vardas < st2.vardas;
    } else {
        return st1.pavarde < st2.pavarde;
    }
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
