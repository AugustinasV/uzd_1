#include <string>
#include <algorithm>
#include <vector>
using namespace std;

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
}
void assign(int col) 
{
    wordreadlenght = wordread.size();
    if(wordreadlenght == col)           
    {
        for (int x =2; x<wordreadlenght; x++) 
        {
            if ((any_of(wordread[x].begin(), wordread[x].end(), ::isalpha) || wordread[x].find_first_of(",./<>?;:[]{}-=_+`~!@#$%^&*()") != std::string::npos)) {
                throw "401";
            }
            else {
                nd_paz.push_back(std::stoi(wordread[x]));
                galutinis += std::stoi(wordread[x]);
            }
        }        
        vardas = wordread[0];
        pavarde = wordread[1];

        egz_paz = std::stoi(wordread[wordreadlenght-1]);
        galutinis_paz= ((galutinis) / nd_paz.size())*0.4 + egz_paz*0.6;   
        mediana = vectorMedian(nd_paz);
    }
    else {
        throw 402;
    }
}
};
static bool compar(Student &a, Student &b) {   
    return (a.vardas<b.vardas);
};