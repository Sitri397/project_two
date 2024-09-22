#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Student{
    string vardas;
    string pavarde;
    vector<int> nd;
    int egzaminas;
    double galutinis;
};

void ived(Student &st){
    cout << "Iveskite studento varda, pavarde ir egzamino rezultata: " << endl;
    cin >> st.vardas >> st.pavarde >> st.egzaminas;
    cout << "Iveskite studento namu darbu skaiciu: " << endl;
    int n;
    int k;
    cin >> n;
    cout << "Iveskite namu darbu rezultatus: " << endl;
    for(int i = 0;i < n;i++){
      cin >> k;
      st.nd.push_back(k);
    }

}

void valymas(Student &Lok){
    Lok.vardas.clear();
    Lok.pavarde.clear();
    Lok.nd.clear();
}

void Gal_Balas(Student &Lok){
    double sum = 0;
    for(int i = 0;i < Lok.nd.size();i++){
        sum += Lok.nd.at(i);
    }
    double vid = sum / Lok.nd.size();
    Lok.galutinis = 0.4*vid + Lok.egzaminas*0.6;
}

void isvedimas(Student &Lok){
    cout << setw(15) << fixed << left <<Lok.vardas << setw(15) << fixed << left << Lok.pavarde << setw(3) << fixed << right << setprecision(2) << Lok.galutinis << endl;

}

int main(){
    vector<Student> Vec1;
    Student Temp;
    cout << "Kiek studentu?: " << endl;
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        cout << "Iveskite studento duomenis: " << endl;
        ived(Temp);
        Gal_Balas(Temp);
        Vec1.push_back(Temp);
        valymas(Temp);
    }
    cout << setw(15) << fixed << left << "Vardas" << setw(15) << fixed << left << "Pavarde" << setw(3) << fixed << right << "Galutinis (Vid.)" << endl;
    cout << string(50, '-') << endl;
    for(int i = 0;i < n;i++){
        isvedimas(Vec1.at(i));
    }
    system("pause");
    return 0;
}

