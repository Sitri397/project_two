#include "Student.h"

int main() {
    char pasirinkimas, pasirinkimas2, strategija;
    Student temp;
    int n;

    cout << "Naudosime vector arba list? (1 - vector / 2 - list): ";
    cin >> pasirinkimas;

    cout << "Kokia strategija? (1/2/3): ";
    cin >> strategija;

    if (pasirinkimas == '1') {
        vector<Student> Vec1, nuskriaustukai, galvociai;

        cout << "Norite nuskaityti is failo ar ivesti rankiniu budu? (n-nuskaityti / i-ivesti): ";
        cin >> pasirinkimas;

        if (pasirinkimas == 'n') {
            string failo_pavadinimas;
            cout << "Ar sugeneruoti failus? (t/n): ";
            cin >> pasirinkimas;

            if (pasirinkimas == 't') {
                generuotiFaila("stud1000.txt", 1000);
                generuotiFaila("stud10000.txt", 10000);
                generuotiFaila("stud100000.txt", 100000);
                generuotiFaila("stud1000000.txt", 1000000);
                generuotiFaila("stud10000000.txt", 10000000);
                cout << "Failai sugeneruoti sekmingai!" << endl;
            }

            cout << "Iveskite failo pavadinima: ";
            cin >> failo_pavadinimas;
            nuskaitymasIsFailo(Vec1, failo_pavadinimas);
        } else if (pasirinkimas == 'i') {
            cout << "Kiek studentu?: ";
            cin >> n;

            for (int i = 0; i < n; ++i) {
                cout << "Iveskite studento duomenis: " << endl;
                ived(temp);
                Vec1.push_back(temp);
                temp.clear();
            }
        }

        cout << "Pasirinkite galutinio balo skaiciavimo buda (v-vidurkis / m-mediana): ";
        cin >> pasirinkimas2;

        if (pasirinkimas2 == 'v') {
            for (auto& st : Vec1) {
                st.setGalutinis(st.calcGalBalasVid());
            }
        } else if (pasirinkimas2 == 'm') {
            for (auto& st : Vec1) {
                st.setGalutinis(st.calcGalBalasMed());
            }
        }

        cout << "Pagal ka rusiojama? (1-varda / 2-pavarde / 3-pazymi): ";
        cin >> pasirinkimas;

        if (pasirinkimas == '1') {
            sort(Vec1.begin(), Vec1.end(), compareByName);
        } else if (pasirinkimas == '2') {
            sort(Vec1.begin(), Vec1.end(), compareByLastName);
        } else {
            sort(Vec1.begin(), Vec1.end(), compareByMark);
        }

        if (strategija == '1') {
            priskirti_grupej_1(Vec1, nuskriaustukai, galvociai);
        } else if (strategija == '2') {
            priskirti_grupej_2(Vec1, nuskriaustukai);
            swap(Vec1, galvociai);
        } else if (strategija == '3') {
            priskirti_grupej_3(Vec1, nuskriaustukai);
            swap(Vec1, galvociai);
        }

        isvedimas(galvociai, nuskriaustukai, pasirinkimas2);
    } else {
        list<Student> List1, nuskriaustukai, galvociai;

        cout << "Norite nuskaityti is failo ar ivesti rankiniu budu? (n-nuskaityti / i-ivesti): ";
        cin >> pasirinkimas;

        if (pasirinkimas == 'n') {
            string failo_pavadinimas;
            cout << "Ar sugeneruoti failus? (t/n): ";
            cin >> pasirinkimas;

            if (pasirinkimas == 't') {
                generuotiFaila("stud1000.txt", 1000);
                generuotiFaila("stud10000.txt", 10000);
                generuotiFaila("stud100000.txt", 100000);
                generuotiFaila("stud1000000.txt", 1000000);
                generuotiFaila("stud10000000.txt", 10000000);
                cout << "Failai sugeneruoti sekmingai!" << endl;
            }

            cout << "Iveskite failo pavadinima: ";
            cin >> failo_pavadinimas;
            nuskaitymasIsFailo(List1, failo_pavadinimas);
        } else if (pasirinkimas == 'i') {
            cout << "Kiek studentu?: ";
            cin >> n;

            for (int i = 0; i < n; ++i) {
                cout << "Iveskite studento duomenis: " << endl;
                ived(temp);
                List1.push_back(temp);
                temp.clear();
            }
        }

        cout << "Pasirinkite galutinio balo skaiciavimo buda (v-vidurkis / m-mediana): ";
        cin >> pasirinkimas2;

        if (pasirinkimas2 == 'v') {
            for (auto& st : List1) {
                st.setGalutinis(st.calcGalBalasVid());
            }
        } else if (pasirinkimas2 == 'm') {
            for (auto& st : List1) {
                st.setGalutinis(st.calcGalBalasMed());
            }
        }

        if (strategija == '1') {
            priskirti_grupej_1(List1, nuskriaustukai, galvociai);
        } else if (strategija == '2') {
            priskirti_grupej_2(List1, nuskriaustukai);
            swap(List1, galvociai);
        } else if (strategija == '3') {
            priskirti_grupej_3(List1, nuskriaustukai);
            swap(List1, galvociai);
        }

        isvedimas(galvociai, nuskriaustukai, pasirinkimas2);
    }

    return 0;
}
