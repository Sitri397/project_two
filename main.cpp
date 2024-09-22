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

int main(){
    vector<Student> Vec1;
    Student Temp;
    cout << "Kiek studentu?: " << endl;
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        cout << "Iveskite studento duomenis: " << endl;
        ived(Temp);
        Vec1.push_back(Temp);
        valymas(Temp);
    }
    return 0;
}

