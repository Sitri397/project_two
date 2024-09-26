#include "Student.h"
void ived(Student &st){
    string input;
    int rezultatas;
    char pasirinkimas;
    int i = 1;
    cout << "Iveskite studento varda ir pavarde: " << endl;
    cin >> st.vardas >> st.pavarde;
    cout << "Ar sugeneruoti studento namu darbu ir egzamino rezultatus?(t/n): " << endl;
    cin >> pasirinkimas;
    if(pasirinkimas == 't'){
        srand(time(nullptr));
        for (int i = 0; i < 5; ++i) {
            st.nd.push_back(rand() % 10 + 1);
        }

        st.egzaminas = rand() % 10 + 1;
    }
    else if(pasirinkimas == 'n'){
        cout << "Iveskite namu darbu rezultatus(-1 uzbaigti)" << endl;
        while(cin >> rezultatas && rezultatas != -1){
            st.nd.push_back(rezultatas);
        }
        cout << "Iveskite egzamino rezultata: " << endl;
        cin >> st.egzaminas;
    }


}

void valymas(Student &Lok){
    Lok.vardas.clear();
    Lok.pavarde.clear();
    Lok.nd.clear();
}

double Gal_Balas_vid(Student &Lok){
    double sum = 0;
    for(int i = 0;i < Lok.nd.size();i++){
        sum += Lok.nd.at(i);
    }
    double vid = sum / Lok.nd.size();
    double galutinis = 0.4*vid + Lok.egzaminas*0.6;
    return galutinis;

}

double Gal_Balas_med(Student &Lok){
    vector<int> darbai = Lok.nd;
    sort(darbai.begin(), darbai.end());
    double mediana;
    int size = darbai.size();

    if (size % 2 == 0) {
        mediana = (darbai[size / 2 - 1] + darbai[size / 2]) / 2.0;
    } else {
        mediana = darbai[size / 2];
    }
    double galutinis = 0.4 * mediana + 0.6 * Lok.egzaminas;

    return galutinis;

}



void isvedimas(Student &Lok, char mode){
    if(mode == 'v'){
        cout << setw(15) << fixed << left <<Lok.vardas << setw(15) << fixed << left << Lok.pavarde << setw(3) << fixed << right << setprecision(2) << Gal_Balas_vid(Lok) << endl;
    }
    else if(mode == 'm'){
        cout << setw(15) << fixed << left <<Lok.vardas << setw(15) << fixed << left << Lok.pavarde << setw(3) << fixed << right << setprecision(2) << Gal_Balas_med(Lok) << endl;
    }


}

void nuskaitymasIsFailo(vector<Student> &students,string failo_pavadinimas) {
    ifstream inFile(failo_pavadinimas);
    if (!inFile) {
        throw runtime_error("Neisejo atidaryti failo");
    }

    string line;


    getline(inFile, line);

    while (getline(inFile, line)) {
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
            throw runtime_error("Klaida: studentas neturi pazymiu: " + temp.vardas + " " + temp.pavarde);
        }

        students.push_back(temp);
        temp.nd.clear();
        temp.vardas.clear();
        temp.pavarde.clear();
    }

    inFile.close();
}

int comper(Student st1, Student st2){
    if(st1.vardas < st2.vardas){
        return st1.vardas < st2.vardas;
    }
    else if(st1.vardas == st2.vardas){
        return st1.pavarde < st2.pavarde;
    }
}
