//main.cpp
#include "Student.h"


int main(){
    char pasirinkimas;
    char pasirinkimas2;
    Student Temp;
    int n;
    cout << "Naudosime vector arba list?(1 - vector/2 - list)" << endl;
    cin >> pasirinkimas;
    if(pasirinkimas == '1'){
    vector<Student> Vec1;
    vector<Student> nuskriaustukai;
    vector<Student> galvociai;
    cout << "Norite nuskaityti is failo ar ivesti rankiniu budu?(n-nuskaityti/i-ivesti): " << endl;
    cin >> pasirinkimas;
    if(pasirinkimas == 'n'){
        string failo_pavadinimas;
        cout << "Ar sugeneruoti failus?(t/n): " << endl;
        cin >> pasirinkimas;
        if(pasirinkimas == 't'){
            auto start = std::chrono::high_resolution_clock::now();
            generuotiFaila("stud1000.txt",1000);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diff = end-start;
            cout << "Failas stud1000.txt sugeneruotas uz " << diff.count() << " sekundziu!" << endl;

            start = std::chrono::high_resolution_clock::now();
            generuotiFaila("stud10000.txt",10000);
            end = std::chrono::high_resolution_clock::now();
            diff = end-start;
            cout << "Failas stud10000.txt sugeneruotas uz " << diff.count() << " sekundziu!" << endl;

            start = std::chrono::high_resolution_clock::now();
            generuotiFaila("stud100000.txt",100000);
            end = std::chrono::high_resolution_clock::now();
            diff = end-start;
            cout << "Failas stud100000.txt sugeneruotas uz " << diff.count() << " sekundziu!" << endl;

            start = std::chrono::high_resolution_clock::now();
            generuotiFaila("stud1000000.txt",1000000);
            end = std::chrono::high_resolution_clock::now();
            diff = end-start;
            cout << "Failas stud1000000.txt sugeneruotas uz " << diff.count() << " sekundziu!" << endl;

            start = std::chrono::high_resolution_clock::now();
            generuotiFaila("stud10000000.txt",10000000);
            end = std::chrono::high_resolution_clock::now();
            diff = end-start;
            cout << "Failas stud10000000.txt sugeneruotas uz " << diff.count() << " sekundziu!" << endl;

            cout << "Failai sugeneruoti sekmingai!" << endl;
        }
        cout << "Iveskite failo pavadinima: " << endl;
        cin >> failo_pavadinimas;
        n = capacity_nustatymas(failo_pavadinimas);
        Vec1.reserve(n+1);
        auto start = std::chrono::high_resolution_clock::now();
        nuskaitymasIsFailo(Vec1, failo_pavadinimas);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end-start;
        cout << "Failas is " << n <<" irasu nuskaitymo laikas: "  << diff.count() << endl;
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
    cin >> pasirinkimas2;
    if(pasirinkimas2 == 'v'){
        for(int i = 0;i < n;i++){
            Vec1[i].galutinis = Gal_Balas_vid(Vec1[i]);
        }

    }
    else if(pasirinkimas2 == 'm'){
        for(int i = 0;i < n;i++){
            Vec1[i].galutinis = Gal_Balas_med(Vec1[i]);
        }
    }
    cout << "Pagal ka rusiojama?(1-varda/2-pavarde/3-pazymi): " << endl;
    cin >> pasirinkimas;
    if(pasirinkimas == '1'){
        auto start = std::chrono::high_resolution_clock::now();
        sort(Vec1.begin(), Vec1.end(), comper_by_name);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end-start;
        cout << n <<" irasu rusiavimas su sort funkcija laikas: " << diff.count() << endl;
    }
    else if (pasirinkimas == '2'){
        auto start = std::chrono::high_resolution_clock::now();
        sort(Vec1.begin(), Vec1.end(), comper_by_last_name);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end-start;
        cout << n <<" irasu rusiavimas su sort funkcija laikas: " << diff.count() << endl;
    }
    else{
        auto start = std::chrono::high_resolution_clock::now();
        sort(Vec1.begin(), Vec1.end(), comper_by_mark);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end-start;
        cout << n <<" irasu rusiavimas su sort funkcija laikas: " << diff.count() << endl;
    }

    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 0;i < n;i++){
        priskirti_grupej(Vec1[i],nuskriaustukai,galvociai);
    }
    Vec1.clear();
    Vec1.shrink_to_fit();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start;
    cout << n <<" irasu dalijimo i 2 grupes laikas: " << diff.count() << endl;


    isvedimas(galvociai,nuskriaustukai, pasirinkimas2);

    system("pause");
    return 0;
    }

    else{
    list<Student> Vec1;
    list<Student> nuskriaustukai;
    list<Student> galvociai;
    cout << "Norite nuskaityti is failo ar ivesti rankiniu budu?(n-nuskaityti/i-ivesti): " << endl;
    cin >> pasirinkimas;
    if(pasirinkimas == 'n'){
        string failo_pavadinimas;
        cout << "Ar sugeneruoti failus?(t/n): " << endl;
        cin >> pasirinkimas;
        if(pasirinkimas == 't'){
            auto start = std::chrono::high_resolution_clock::now();
            generuotiFaila("stud1000.txt",1000);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diff = end-start;
            cout << "Failas stud1000.txt sugeneruotas uz " << diff.count() << " sekundziu!" << endl;

            start = std::chrono::high_resolution_clock::now();
            generuotiFaila("stud10000.txt",10000);
            end = std::chrono::high_resolution_clock::now();
            diff = end-start;
            cout << "Failas stud10000.txt sugeneruotas uz " << diff.count() << " sekundziu!" << endl;

            start = std::chrono::high_resolution_clock::now();
            generuotiFaila("stud100000.txt",100000);
            end = std::chrono::high_resolution_clock::now();
            diff = end-start;
            cout << "Failas stud100000.txt sugeneruotas uz " << diff.count() << " sekundziu!" << endl;

            start = std::chrono::high_resolution_clock::now();
            generuotiFaila("stud1000000.txt",1000000);
            end = std::chrono::high_resolution_clock::now();
            diff = end-start;
            cout << "Failas stud1000000.txt sugeneruotas uz " << diff.count() << " sekundziu!" << endl;

            start = std::chrono::high_resolution_clock::now();
            generuotiFaila("stud10000000.txt",10000000);
            end = std::chrono::high_resolution_clock::now();
            diff = end-start;
            cout << "Failas stud10000000.txt sugeneruotas uz " << diff.count() << " sekundziu!" << endl;

            cout << "Failai sugeneruoti sekmingai!" << endl;
        }
        cout << "Iveskite failo pavadinima: " << endl;
        cin >> failo_pavadinimas;
        n = capacity_nustatymas(failo_pavadinimas);
        auto start = std::chrono::high_resolution_clock::now();
        nuskaitymasIsFailo(Vec1, failo_pavadinimas);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end-start;
        cout << "Failas is " << n <<" irasu nuskaitymo laikas: "  << diff.count() << endl;
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
    cout << "Pasirinkite galutinio balo skaiciavimo buda(v-vidurkis/m - mediana): " << endl;
    cin >> pasirinkimas2;
    if(pasirinkimas2 == 'v'){
        for(auto & st: Vec1){
            st.galutinis = Gal_Balas_vid(st);
        }

    }
    else if(pasirinkimas2 == 'm'){
        for(auto & st: Vec1){
            st.galutinis = Gal_Balas_med(st);
        }
    }
    cout << "Pagal ka rusiojama?(1-varda/2-pavarde/3-pazymi): " << endl;
    cin >> pasirinkimas;
    if(pasirinkimas == '1'){
        auto start = std::chrono::high_resolution_clock::now();
        Vec1.sort(comper_by_name);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end-start;
        cout << n <<" irasu rusiavimas su sort funkcija laikas: " << diff.count() << endl;
    }
    else if (pasirinkimas == '2'){
        auto start = std::chrono::high_resolution_clock::now();
        Vec1.sort(comper_by_last_name);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end-start;
        cout << n <<" irasu rusiavimas su sort funkcija laikas: " << diff.count() << endl;
    }
    else{
        auto start = std::chrono::high_resolution_clock::now();
        Vec1.sort(comper_by_mark);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end-start;
        cout << n <<" irasu rusiavimas su sort funkcija laikas: " << diff.count() << endl;
    }

    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 0;i < n;i++){
        Temp = get(Vec1,i);
        priskirti_grupej(Temp,nuskriaustukai,galvociai);
    }
    Vec1.clear();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start;
    cout << n <<" irasu dalijimo i 2 grupes laikas: " << diff.count() << endl;


    isvedimas(galvociai,nuskriaustukai, pasirinkimas2);

    system("pause");
    return 0;
    }
}

