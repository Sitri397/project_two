//stud.cpp
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





int comper_by_name(Student& st1, Student& st2) {
    if (st1.vardas != st2.vardas) {
        return st1.vardas < st2.vardas;
    } else {
        return st1.pavarde < st2.pavarde;
    }
}

int comper_by_last_name(Student& st1, Student& st2) {
    if (st1.pavarde != st2.pavarde){
        return st1.pavarde < st2.pavarde;
    }
}

int comper_by_mark(Student& st1, Student& st2) {
    if (st1.galutinis != st2.galutinis){
        return st1.galutinis < st2.galutinis;
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

Student get(vector<Student> &vec,int i){
    return vec[i];
}

Student get(list<Student> _list, int _i){
    list<Student>::iterator it = _list.begin();
    for(int i=0; i<_i; i++){
        ++it;
    }
    return *it;
}


