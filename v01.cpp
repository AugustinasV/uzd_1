#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

int n=0 ;
string m="" ;
const int arrs = 3; /// nd_paz array size

struct Student
{
    string vardas;
    string pavarde;
    
    int nd_paz[arrs]; 

    int egz_paz;
    float galutinis_paz;
};

/// cin = int only;
int intHandle() { 
    cin >> m;
    while ((any_of(m.begin(), m.end(), ::isalpha)) || m=="0") {
        cout <<"again"<<endl;
        cin>> m;
    };
    while (std::stoi(m)>10 || std::stoi(m)<0) {
        cout <<"again"<<endl;
        cin>> m;
    }
    return std::stoi(m);
};

/// cin = text string only
string stringHandle() {   
    cin >> m;    
    while ((any_of(m.begin(), m.end(), ::isdigit)) || m.find_first_of(",./<>?;:[]{}-=_+`~!@#$%^&*()") != std::string::npos) {
        cin.clear();                        
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout <<"again"<<endl;
        cin>> m;
    };
    return m;
};

/// cin = y/n only;
string ynHandle() {
    cin >> m;    
    while (m != "y" && m != "Y" && m != "n" && m != "N") {
        cin.clear();                        
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout <<"again"<<endl;
        cin>> m;
    };
    return m;
};

int main() {
    
    float galutinis =0.0;
    string m = "";

    cout <<"studentu skaicius"<<endl;

    n = intHandle();
    
    Student grupe[n];
    
    for (int i=0; i < n; i++) {
        galutinis = 0.0;
        cout<<"ivesti random pazymius "<<i+1<<"-ajam studentui? (y/n)"<<endl;
        m = ynHandle();

        cout<<i+1<<"-ojo studento vardas"<<endl;
        grupe[i].vardas = stringHandle();


        cout<<i+1<<"-ojo studento pavarde"<<endl;
        grupe[i].pavarde = stringHandle();
    
        if (m == "n" || m == "N") {
            cout<<i+1<<"-ojo studento egzamino paz"<<endl;
            grupe[i].egz_paz = intHandle();

            for (int j=0; j<arrs; j++) {
                cout<<j+1<<"-asis nd paz"<<endl;
                grupe[i].nd_paz[j] = intHandle();
            };
            for (auto x : grupe[i].nd_paz) {
                galutinis += x;
            };
            grupe[i].galutinis_paz= ((galutinis) / arrs )*0.4+grupe[i].egz_paz*0.6;              
        } else {
        
            grupe[i].egz_paz = rand() % 10 + 1;
            cout << grupe[i].egz_paz << endl;
        
            for (int j=0; j<arrs; j++) {
                grupe[i].nd_paz[j] = rand() % 10 + 1;
                cout << grupe[i].nd_paz[j] << endl;
            };
            for (auto x : grupe[i].nd_paz) {
                galutinis += x;
            };
        
            grupe[i].galutinis_paz= ((galutinis) / arrs )*0.4+grupe[i].egz_paz*0.6;      
        };
    };
    cout <<setw(12)<<left<< "Vardas" <<setw(12)<<left<< "Pavarde" <<left<< "Galutinis (vid.)\n"<<endl;
    for (int i=0; i<n; i++) {
        cout <<setw(12)<<left<< grupe[i].vardas <<setw(12)<<left<< grupe[i].pavarde <<left<<setprecision(3)<<grupe[i].galutinis_paz<<"\n"<<endl;
    };
};
