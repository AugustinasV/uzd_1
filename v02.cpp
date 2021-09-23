#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

int linecount = 0;
vector <string> lineread;

struct Student
{
string vardas;
string pavarde;
float galutinis_paz;
int egz_paz;
float mediana;
float galutinis;

int wordreadlenght;

vector <int> nd_paz;
vector <string> wordread;

string assignedline;


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

bool compar(Student &a, Student &b) {
    return (a.vardas<b.vardas);
}

void readStr(string a, vector <string> &k) 
{
    string word;
    stringstream str(a);
    while (str >> word) {
        k.push_back(word);
    }
};

void assign(Student &a)
{
    a.wordreadlenght = a.wordread.size();
    a.vardas = a.wordread[0];
    a.pavarde = a.wordread[1];
    for (int x =2; x<a.wordreadlenght; x++) 
    {
        a.nd_paz.push_back(std::stoi(a.wordread[x]));
        a.galutinis += std::stoi(a.wordread[x]);
    }
    a.egz_paz = std::stoi(a.wordread[a.wordreadlenght-1]);
    
}
void readLine()
{
    string qwer;
    std::ifstream reading("studentai10000.txt");
    while (getline(reading, qwer)) {
        if (qwer=="") {                 /// check for empty lines, skip to next line if empty found
            continue;
        }
        lineread.push_back(qwer);
        linecount ++;
    }

}
int main(){
    
    readLine();

    vector <Student> grupe(linecount-1);
    
    for (int y=1; y<linecount; y++)
    {
        grupe[y-1].assignedline = lineread[y];
        
        readStr(grupe[y-1].assignedline, grupe[y-1].wordread);
        assign(grupe[y-1]);

        grupe[y-1].galutinis_paz= ((grupe[y-1].galutinis) / grupe[y-1].nd_paz.size() )*0.4+grupe[y-1].egz_paz*0.6;   
        grupe[y-1].mediana = grupe[y-1].vectorMedian(grupe[y-1].nd_paz);
    };
    cout << "studentu kiekis: " << linecount << endl;
    
    sort(grupe.begin(), grupe.end(), compar);

    cout <<setw(15)<<left<< "Vardas" <<setw(15)<<left<< "Pavarde" <<setw(20)<<left<<"Galutinis (vid.)" <<setw(20)<<left<<"Galutinis (med.) \n"  << endl;
        for (int i=0; i<linecount; i++) {
            cout <<setw(15)<<left<< grupe[i].vardas <<setw(15)<<left<< grupe[i].pavarde <<setw(20)<<left<<setprecision(3)<<grupe[i].galutinis_paz <<setw(20)<<left<<setprecision(3)<<grupe[i].mediana<<"\n"<<endl;
        }

};