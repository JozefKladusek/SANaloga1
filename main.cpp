#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

ofstream out;

string inputText(const string &pot) {
    ifstream input(pot);
    stringstream sstream;

    if (!input.is_open()) {
        return string();
    }

    sstream << input.rdbuf();
    return sstream.str();
}

void izpis_KMPnext(const int* polje, int len) {
    for (int i = 0; i < len; ++i) {
        out << polje[i] << ' ';
    }
    out << endl;
}


void KMP(const string& text, const string& vzorec) {
    /*
     * implementacija algoritma KMP
     * za izpis polja KMPnext lahko uporabite funkcijo izpis_KMPnext
     * Za izpis navidezne spremenljivke index uporabite: out << index << ' ';
     */
    int len = vzorec.length();
    int kmpNext[len];
    int counter;
    int counter1;
    string tempstring="";
    kmpNext[0]=-1;
    kmpNext[1]=0;
    string najdeni;

    for (int i = 2; i < len; ++i) {
        string stringarray1[i-1];
        string stringarray2[i-1];
        string stringreverse="";
        int stringarraycounter1=0;
        int stringarraycounter2=0;
        counter = 0;
        counter1=i-1;
        int vrednostkmp=0;

        while(counter<i-1){
            for (int j = 0; j < counter1; ++j) {
                tempstring=vzorec[j];
                stringarray1[stringarraycounter1].append(tempstring);
            }
            stringarraycounter1++;
            counter++;
            counter1--;
        }


        counter = 0;
        counter1 = i-1;
        while(counter1>0){
            for (int j = i-1; j > counter; --j) {
                tempstring=vzorec[j];

                stringarray2[stringarraycounter2].append(tempstring);
            }
            stringarraycounter2++;
            counter++;
            counter1--;
        }


}


int main(int argc, const char *const argv[]) {
    if (argc != 4) {
        return -1;
    }

    string text = inputText(argv[3]);
    string vzorec = argv[2];
    out.open("out.txt");

    if (!out) {
        return -2;
    }

    if (argv[1][0] == '0') {
        KMP(text, vzorec);
    }
    else {
        //sunday
    }


    return 0;
}
