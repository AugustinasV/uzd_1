#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

int n=0;
string m="" ;
const int defsize = 4; /// nd_paz vector size

struct Student
{
int arrinp;
string vardas;
string pavarde;
float galutinis_paz;
int egz_paz;
float mediana;
float galutinis;
vector <int> nd_paz;

Student()
{
    arrinp = 1;
}

float vectorMedian(vector <int> vec) 
{
    int q = 0;
    sort(vec.begin(), vec.end());
    if (vec.size() % 2 == 0) {
        return float(((vec[vec.size()/2-1]) + (vec[vec.size()/2]))/2.0);
    } 
    q = vec.size()/2+0.5;
    return float(vec[q]);
};
};

/// cin = int only;
int intHandle() { 
    cin >> m;
    while ((any_of(m.begin(), m.end(), ::isalpha) || m.find_first_of(",./<>?;:[]{}-=_+`~!@#$%^&*()") != std::string::npos)) {
        cout <<"again"<<endl;
        cin>> m;
    };
    while (std::stoi(m)>11 || std::stoi(m)<0) {
        cout <<"again"<<endl;
        cin>> m;
    }
    return std::stoi(m);
};

/// cin = text string only
string stringHandle() {   
    cin >> m;    
    while ((any_of(m.begin(), m.end(), ::isdigit)) || m.find_first_of(",./<>?;:[]{}-=_+`'~!@#$%^&*()") != std::string::npos) {
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

    cout <<"studentu skaicius"<<endl;

    n = intHandle();

    vector <Student> grupe(n);

    for (int i=0; i < n; i++) {
        
        std::cout<<i+1<<"-ojo studento vardas"<<endl;
        grupe[i].vardas = stringHandle();

        cout<<i+1<<"-ojo studento pavarde"<<endl;
        grupe[i].pavarde = stringHandle();  

        cout<<"ivesti random pazymius "<<i+1<<"-ajam studentui? (y/n)"<<endl;
        m = ynHandle();
        
        if (m == "n" || m == "N") {
            cout<<i+1<<"-ojo studento egzamino paz"<<endl;
            grupe[i].egz_paz = intHandle();

            cout<<"zinomas nd kiekis "<<i+1<<"-ajam studentui? (y/n)"<<endl;
            m = ynHandle();
            
            if (m == "n" || m == "N") {
                cout<< "(norint uzbaigti ivedima ivesti 0)"<<endl;
                while (grupe[i].arrinp != 0)
                {
                    cout<<grupe[i].nd_paz.size() +1 <<"-asis nd paz"<<endl;
                    grupe[i].arrinp = intHandle();
                    if (grupe[i].arrinp!=0) 
                    {
                        grupe[i].nd_paz.push_back(grupe[i].arrinp);
                    }
                };   
                for (int x=0; x<grupe[i].nd_paz.size(); x++)
                {
                    grupe[i].galutinis += grupe[i].nd_paz[x];
                }
                grupe[i].galutinis_paz= ((grupe[i].galutinis) / grupe[i].nd_paz.size() )*0.4+grupe[i].egz_paz*0.6;   
                grupe[i].mediana = grupe[i].vectorMedian(grupe[i].nd_paz);
                cout << "----------------" << endl;
            }
            else {
                for (int j=0; j<defsize; j++) {
                    cout<<j+1<<"-asis nd paz"<<endl;
                    grupe[i].nd_paz.push_back(intHandle());
                };
                for (auto x : grupe[i].nd_paz) {
                    grupe[i].galutinis += x;
                };
                grupe[i].galutinis_paz= ((grupe[i].galutinis) / grupe[i].nd_paz.size() )*0.4+grupe[i].egz_paz*0.6;   
                grupe[i].mediana = grupe[i].vectorMedian(grupe[i].nd_paz);
                cout << "----------------" << endl;
                };
        } 
        else { 
            grupe[i].egz_paz = rand() % 10 + 1;
            for (int j=0; j<defsize; j++) {
                grupe[i].nd_paz.push_back(rand() % 10 + 1);
            };
            for (auto x : grupe[i].nd_paz) {
                grupe[i].galutinis += x;
            };
            grupe[i].galutinis_paz= ((grupe[i].galutinis) / grupe[i].nd_paz.size() )*0.4+grupe[i].egz_paz*0.6;   
            grupe[i].mediana = grupe[i].vectorMedian(grupe[i].nd_paz);
            cout << "----------------" << endl; 
        }; 
    }; 
    
    cout<<"isvesti galutini pazymi (y) ar mediana (n) ? " << endl;
    m = ynHandle();

    if (m == "y" || m == "y") {
        cout <<setw(12)<<left<< "Vardas" <<setw(12)<<left<< "Pavarde" <<setw(20)<<left<<"Galutinis (vid.)"<<endl;
        for (int i=0; i<n; i++) {
            cout <<setw(12)<<left<< grupe[i].vardas <<setw(12)<<left<< grupe[i].pavarde <<setw(20)<<left<<setprecision(3)<<grupe[i].galutinis_paz<<"\n"<<endl;
        };
    } 
    else {
        cout <<setw(12)<<left<< "Vardas" <<setw(12)<<left<< "Pavarde" <<setw(20)<<left<<"Galutinis (med.)"<<endl;
        for (int i=0; i<n; i++) {
            cout <<setw(12)<<left<< grupe[i].vardas <<setw(12)<<left<< grupe[i].pavarde <<setw(20)<<left<<setprecision(3)<<grupe[i].mediana<<"\n"<<endl;
        } 
    };
};