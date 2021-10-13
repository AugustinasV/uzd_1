#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
using namespace std;


int linecount = 0;
vector <string> lineread;

void readStr(string a, vector <string> &k) 
{
    string word;
    stringstream str(a);
    while (str >> word) {
        k.push_back(word);
    }    
};

void readLine(string filename)
{
    string qwer;
    ifstream file;
    try {
        file.open(filename);
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