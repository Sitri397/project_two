#include "Student.h"


int main(){
    vector<Student> Vec1;
    Student Temp;
    cout << "Kiek studentu?: " << endl;
    int n;
    cin >> n;
    cout << "Norite nuskaityti is failo ar ivesti rankiniu budu?(n-nuskaityti/i-ivesti): " << endl;
    char pasirinkimas;
    cin >> pasirinkimas;
    if(pasirinkimas == 'n'){
        string failo_pavadinimas;
        cout << system("dir *.txt") << endl;
        cout << "Iveskite failo pavadinima: " << endl;
        cin >> failo_pavadinimas;
        nuskaitymasIsFailo(Vec1, failo_pavadinimas);
    }
    else if(pasirinkimas == 'i'){
        for(int i = 0;i < n;i++){
        cout << "Iveskite studento duomenis: " << endl;
        ived(Temp);
        Vec1.push_back(Temp);
        valymas(Temp);
        }
    }
    cout << "Pasirinkite galutinio balo skaiciavimo buda(v-vidurkis/m - mediana): " << endl;

    cin >> pasirinkimas;
    if(pasirinkimas == 'v'){
        cout << setw(15) << fixed << left << "Vardas" << setw(15) << fixed << left << "Pavarde" << setw(3) << fixed << right << "Galutinis (Vid.)" << endl;
        cout << string(50, '-') << endl;
    }
    else if(pasirinkimas == 'm'){
        cout << setw(15) << fixed << left << "Vardas" << setw(15) << fixed << left << "Pavarde" << setw(3) << fixed << right << "Galutinis (Med.)" << endl;
        cout << string(50, '-') << endl;
    }
    sort(Vec1.begin(), Vec1.end(), comper);
    for(int i = 0;i < n;i++){
        isvedimas(Vec1.at(i), pasirinkimas);
    }
    system("pause");
    return 0;
}

