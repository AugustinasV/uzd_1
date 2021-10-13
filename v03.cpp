#include "v03functions.h"
#include "v03studentStruct.h"

string filename = "studentai10000 (with errors).txt";
const int columncount = 23;
int errorcount = 0;

int main() {
    readLine(filename);
    vector <Student> grupe(linecount-1);
    for (int y=1; y<linecount; y++)
    {
        grupe[y-1].assignedline = lineread[y];
        readStr(grupe[y-1].assignedline, grupe[y-1].wordread);
        try {
            grupe[y-1].assign(columncount);
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
    
    cout << "\nstudentu kiekis: " << linecount-1-errorcount<<"\n"<< endl;
    
    for (int i = 0; i < errorcount; i++) {
        grupe.erase(grupe.begin());
    }
    cout <<setw(15)<<left<< "Vardas" <<setw(15)<<left<< "Pavarde" <<setw(20)<<left<<"Galutinis (vid.)" <<setw(20)<<left<<"Galutinis (med.) \n"  << endl;
        for (auto x: grupe) {
            cout <<setw(15)<<left<< x.vardas <<setw(15)<<left<< x.pavarde <<setw(20)<<left<<setprecision(3)<<x.galutinis_paz <<setw(20)<<left<<setprecision(3)<<x.mediana<<endl;
        }   
};