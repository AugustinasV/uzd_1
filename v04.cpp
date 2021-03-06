#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <fstream>
#include <chrono>
using namespace std;

int linecount = 0;
int errorcount = 0;
const int columncount = 10; /// file column count
const int size = 10000000; /// file entry count
float totaltime=0;

vector <string> lineread;
class timer {
    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> start;
    public:
        timer() : start{std::chrono::high_resolution_clock::now()} {}
        void reset() {
            start = std::chrono::high_resolution_clock::now();
        }
        double elapsed() const {
            return std::chrono::duration<double, milli>(std::chrono::high_resolution_clock::now() - start).count();
        }
};
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
void assign() 
{
    wordreadlenght = wordread.size();
    if(wordreadlenght == columncount)           
    {
        for (int x =2; x<wordreadlenght-1; x++) 
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

void readLine()
{
    string qwer;
    ifstream file;
    try {
        file.open(std::to_string(size)+".txt");
        if (!file.is_open()) {
            throw 403;
            }
        }

    catch (int asd) {
        cout <<"ERROR: missing file"<<endl;
        std::terminate();
    }

    while (getline(file, qwer)) {
        if (qwer=="") {                 /// check for empty lines, skip to next line if empty found
            continue;
        }
        lineread.push_back(qwer);
        linecount ++;
    }
    file.close();

}

void fileGenerator() 
{
string s ="vardas pavarde nd() egz \n";
    ofstream file0(std::to_string(size)+".txt");
    file0 << s;
    for (int x=1; x<size+1; x++) {
        file0 << ("vardas" + std::to_string(x)) << " " << ("pavarde" + std::to_string(x)) << " ";
        for (int y=0; y<columncount-2; y++) {
            file0 << to_string(rand() % 10 + 1) << " ";
        }
        file0 << "\n";    
    }
    file0.close();
}

int main(){

    timer a;
    fileGenerator();
    cout << std::to_string(size)+".txt generation: "  << a.elapsed() << "ms"<< endl;
    totaltime +=a.elapsed();
    
    timer b;
    readLine();
    
    vector <Student> grupe(linecount-1);
    
    for (int y=1; y<linecount; y++)
    {
        ///grupe[y-1].assignedline = lineread[y];
        readStr(lineread[y], grupe[y-1].wordread);
        
        try {
            grupe[y-1].assign();
        }
        catch (int qwe) {
            cout << "ERROR: corrupt data on line " << (y+1) << endl;
            errorcount ++;
        }
        catch (char const* zxc) {
            cout << "ERROR: bad int on line " << (y+1) << endl;
            errorcount ++;
        }
    };

    sort(grupe.begin(), grupe.end(), compar);

    for (int i = 0; i < errorcount; i++) {
        grupe.erase(grupe.begin());
    }
    
    cout << std::to_string(size)+".txt handle: "  << b.elapsed() << "ms"<< endl;
    totaltime +=b.elapsed();
    
    timer d;
    
    ofstream file1(std::to_string(size)+"<5.txt");
    ofstream file2(std::to_string(size)+">=5.txt");

    for (int i=0;i < grupe.size(); i++) {
        if (grupe[i].galutinis_paz < 5) { 
            file1 << lineread[i+1] << "\n";
        }
        else {
            file2 << lineread[i+1] << "\n";
        }
    }
    file1.close();
    file2.close();
    cout << std::to_string(size)+".txt sort + write: "  << d.elapsed() << "ms"<< endl;  
    totaltime +=d.elapsed();
    cout << "=================================" << endl;
    cout <<std::to_string(size)+".txt total: " << totaltime<< "ms" << endl;
}