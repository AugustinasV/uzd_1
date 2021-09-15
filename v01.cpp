#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

int n=0 ;
string m="" ;

struct Student
{
    string vardas;
    string pavarde;
    
    int nd_paz[2]; /// nd paz sarasas is [n] elem
   
    int egz_paz;
    float galutinis_paz;
};

/// cin = int only;
int intHandle() { 
    cin >> m;
    while ((any_of(m.begin(), m.end(), ::isalpha)) ) {
        cout <<"again"<<endl;
        cin>> m;
    };
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

int main() {
    
    float galutinis =0.0;

    cout <<"studentu skaicius"<<endl;
    ///cin >> m;
    ///intHandle(m);

    n = intHandle();
    
    Student grupe[n];
    
    for (int i=0; i < n; i++) {

        cout<<i+1<<"-ojo studento vardas"<<endl;
        grupe[i].vardas = stringHandle();


        cout<<i+1<<"-ojo studento pavarde"<<endl;
        grupe[i].pavarde = stringHandle();
    

        cout<<i+1<<"-ojo studento egzamino paz"<<endl;
        grupe[i].egz_paz = intHandle();

        int a=0;
        for (int j=0; j<2; j++) {
            
            cout<<j+1<<"-asis nd paz"<<endl;
            grupe[i].nd_paz[j] = intHandle();
    
        };
        for (auto x : grupe[i].nd_paz) {
            galutinis += x;
        }
        cout << galutinis<< endl;
        grupe[i].galutinis_paz= ((galutinis) / 2 )*0.4+grupe[i].egz_paz*0.6;      
        galutinis = 0.0;
    };
    
    cout <<setw(12)<<left<< "Vardas" <<setw(12)<<left<< "Pavarde" <<left<< "Galutinis (vid.)\n"<<endl;
    for (int i=0; i<n; i++) {
        cout <<setw(12)<<left<< grupe[i].vardas <<setw(12)<<left<< grupe[i].pavarde <<left<<setprecision(4)<<grupe[i].galutinis_paz<<"\n"<<endl;
    };
};
