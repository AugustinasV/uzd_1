#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <fstream>
#include <chrono>
#include <list>

using namespace std;

int linecount = 0;
int errorcount = 0;
const int columncount = 8; /// file column count
const int size = 10000; /// file entry count
float listtotaltime=0;
float vectortotaltime=0;


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
            return std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - start).count();
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

Student () {
    nd_paz.reserve(columncount-3);
    wordread.reserve(columncount);

    galutinis, mediana, galutinis_paz = 0;
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
}
void assign() 
{
    wordreadlenght = wordread.size();
    if(wordreadlenght == columncount)           
    {   
        for (int x =2; x<wordreadlenght-1; x++) 
        {
                nd_paz.push_back(std::stoi(wordread[x]));
                galutinis += std::stoi(wordread[x]);
        }        
        vardas = wordread[0];
        pavarde = wordread[1];
        egz_paz = std::stoi(wordread[wordreadlenght-1]);
        galutinis_paz= (((galutinis) / nd_paz.size())*0.4 + egz_paz*0.6);   
        ///mediana = vectorMedian(nd_paz);
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
    ofstream file0(std::to_string(size)+".txt");
    for (int x=1; x<size+1; x++) {
        file0 << ("vardas" + std::to_string(x)) << " " << ("pavarde" + std::to_string(x)) << " ";
        for (int y=0; y<columncount-2; y++) 
        {
            file0 << to_string(rand() % 10 + 1) << " ";
        }
        file0 << "\n";    
    }
    file0.close();
}

int main(){

    lineread.reserve(size);

    timer a;
    fileGenerator();
    cout << std::to_string(size)+".txt generation: "  << a.elapsed() << "s"<< endl;
    
    readLine();

    timer b;
    
    list <Student> grupe(linecount);

    int y=0;
    std::list<Student>::iterator it;
    for (it = grupe.begin(); it != grupe.end(); it++)           /// list handle   
    {
        readStr(lineread[y], it->wordread);
        try 
        {
            (*it).assign();
        }
        catch (int qwe) 
        {
            cout << "ERROR: corrupt data on line " << (y+1) << endl;
            errorcount ++;
        }
        catch (char const* zxc) 
        {
            cout << "ERROR: bad int on line " << (y+1) << endl;
            errorcount ++;
        }
        y++;
    }
    cout << "" << endl;
    cout << std::to_string(size)+".txt list handle: "  << b.elapsed() << "s"<< endl;
    listtotaltime +=b.elapsed(); 
    

    list <Student> grupe_v;
    list <Student> grupe_k;      
   

    timer d;

    ofstream file11("list str 1 "+std::to_string(size)+"<5.txt");
    ofstream file22("list str 1 "+std::to_string(size)+">=5.txt");

    int i=0;
    std::list<Student>::iterator ur;
    for (ur = grupe.begin(); ur != grupe.end(); ur++)           /// list str 1
    {
        if (ur->galutinis_paz < 5) { 
            grupe_v.push_back(*ur);
            file11 << lineread[i]<< "\n";
        }
        else {
            grupe_k.push_back(*ur);
            file22 << lineread[i]<< "\n";
        }
        i++;
    }
    
    grupe_v.clear(); 
    file11.close();
    file22.close();    
    
    cout << "list str 1 : "<< d.elapsed() << "s" << endl; 
    listtotaltime +=d.elapsed(); 


    timer dd;
    
    ofstream file1("list str 2 "+std::to_string(size)+"<5.txt");
    ofstream file2("list str 2 "+std::to_string(size)+">=5.txt");
   
    ur = grupe.begin();
    i = 0;                                  
    for (ur = grupe.begin(); ur != grupe.end(); )           /// list str 2
    {
        if (ur -> galutinis_paz <5) 
        {
            file1 << lineread[i] <<endl;
            grupe_v.push_back(*ur);
            ur = grupe.erase(ur);          
        }
        else
        {
            file2 << lineread[i] <<endl;
            ur ++;
        }
        i ++;
    }

    file1.close();
    file2.close();

    cout << "list str 2 : "<< dd.elapsed() << "s" << endl; 
    listtotaltime +=dd.elapsed(); 


    timer bb;

    vector <Student> grupedu;
    grupedu.resize(linecount);
    vector <Student> testgrupedu;
    testgrupedu.resize(linecount);


    for (int x=0; x<linecount; x++)             /// vector handle   
    {
        readStr(lineread[x], grupedu[x].wordread);
        try 
        {
            grupedu[x].assign();
        }
        catch (int qwe) 
        {
            cout << "ERROR: corrupt data on line " << (x+1) << endl;
            errorcount ++;
        }
        catch (char const* zxc) 
        {
            cout << "ERROR: bad int on line " << (x+1) << endl;
            errorcount ++;
        }
    
    }
    cout << "" << endl;
    cout << std::to_string(size)+".txt vector handle: "  << bb.elapsed() << "s"<< endl;
    vectortotaltime +=bb.elapsed();
  
    copy(grupedu.begin(), grupedu.end(), testgrupedu.begin());

    vector <Student> grupedu_v;
    vector <Student> grupedu_k;

    timer ddd;   
   
    ofstream file33("vector str 1 "+std::to_string(size)+"<5.txt");
    ofstream file44("vector str 1 "+std::to_string(size)+">=5.txt");

    std::vector<Student>::iterator lp;
    int ii=0;
    for (lp = grupedu.begin(); lp != grupedu.end(); )           /// vector str 1
    {
        if (lp->galutinis_paz < 5) { 
            grupedu_v.push_back(*lp);
            file33 << lineread[ii]<< "\n";
        }
        else {
            grupedu_k.push_back(*lp);
            file44 << lineread[ii]<< "\n";
        }
        ii++;
        lp++;
    }
    
    file33.close();
    file44.close();   
   
    cout << "vector str 1 : "<< ddd.elapsed() << "s" << endl; 
    vectortotaltime +=ddd.elapsed();     

    grupedu_v.clear();
    grupedu_v.shrink_to_fit();


    timer dddd;

    ofstream file3("vector str 2 "+std::to_string(size)+"<5.txt");
    ofstream file4("vector str 2 "+std::to_string(size)+">=5.txt");

    lp= grupedu.begin();

    ii = 0;
    for (lp = grupedu.begin(); lp != grupedu.end();)            /// vector str 2            
    {
        if (lp -> galutinis_paz <5) 
        {   
            file3 << lineread[ii] <<endl;
            grupedu_v.push_back(*lp);
            grupedu.erase(lp);
        }
        else
        {
            file4 << lineread[ii] <<endl;
            lp ++;           
        }
        ii ++;
    }
    
    cout << "vector str 2 : "<< dddd.elapsed() << "s" << endl; 
    vectortotaltime +=dddd.elapsed();      


    file3.close();
    file4.close();  
    
    cout << "" << endl; 
    cout <<std::to_string(size)+".txt list total: " << listtotaltime<< "s" << endl;
    cout <<std::to_string(size)+".txt vector total: " << vectortotaltime<< "s" << endl;
    cout << "" << endl;

    vector <Student> testgrupedu_v;
        
        
    timer ddddd;

    lp= testgrupedu.begin();

    ii = 0;
    for (lp = testgrupedu.begin(); lp != testgrupedu.end();)            
    {
        if (lp -> galutinis_paz <5) 
        {  
            testgrupedu_v.push_back(*lp);
        }
        lp ++;
        ii ++;
    }

    testgrupedu.erase( remove_if(testgrupedu.begin(), testgrupedu.end(), [](const Student & c){return c.galutinis_paz <5;}),     testgrupedu.end());

    cout << std::to_string(size)+".txt vector erase(remove) : "<< ddddd.elapsed() << "s" << endl; 
}


