#include "Student.h"


int main(){
    vector<Student> Vec1;
    vector<Student> nuskriaustukai;
    vector<Student> galvociai;
    Student Temp;
    int n;
    cout << "Norite nuskaityti is failo ar ivesti rankiniu budu?(n-nuskaityti/i-ivesti): " << endl;
    char pasirinkimas;
    cin >> pasirinkimas;
    if(pasirinkimas == 'n'){
        string failo_pavadinimas;
        cout << "Ar sugeneruoti failus?(t/n): " << endl;
        cin >> pasirinkimas;
        if(pasirinkimas == 't'){
            generuotiFaila("stud1000.txt",1000);
            generuotiFaila("stud10000.txt",10000);
            generuotiFaila("stud100000.txt",100000);
            generuotiFaila("stud1000000.txt",1000000);
            generuotiFaila("stud10000000.txt",10000000);
            cout << "Failai sugeneruoti sekmingai!" << endl;
        }
        cout << system("dir *.txt") << endl;
        cout << "Iveskite failo pavadinima: " << endl;
        cin >> failo_pavadinimas;
        n = capacity_nustatymas(failo_pavadinimas);
        Vec1.reserve(n+1);
        nuskaitymasIsFailo(Vec1, failo_pavadinimas);
    }
    else if(pasirinkimas == 'i'){
        cout << "Kiek studentu?: " << endl;
        cin >> n;
        for(int i = 0;i < n;i++){
            cout << "Iveskite studento duomenis: " << endl;
            ived(Temp);
            Vec1.push_back(Temp);
            valymas(Temp);
        }
    }
    nuskriaustukai.reserve(n+1);
    galvociai.reserve(n+1);
    cout << "Pasirinkite galutinio balo skaiciavimo buda(v-vidurkis/m - mediana): " << endl;
    cin >> pasirinkimas;
    if(pasirinkimas == 'v'){
        for(int i = 0;i < n;i++){
            Vec1[i].galutinis = Gal_Balas_vid(Vec1[i]);
        }

    }
    else if(pasirinkimas == 'm'){
        for(int i = 0;i < n;i++){
            Vec1[i].galutinis = Gal_Balas_med(Vec1[i]);
        }
    }
    sort(Vec1.begin(), Vec1.end(), comper);

    for(int i = 0;i < n;i++){
        priskirti_grupej(Vec1[i],nuskriaustukai,galvociai);
    }
    Vec1.clear();
    Vec1.shrink_to_fit();


    isvedimas(galvociai,nuskriaustukai, pasirinkimas);

    system("pause");
    return 0;
}

