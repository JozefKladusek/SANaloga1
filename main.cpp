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

string reverseString(std::string& str) {
    int n = str.length();
    for (int i = 0; i < n / 2; ++i) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
    return str;
}
void Izpis_Stevil(string* polje, unsigned int velikost) {
    ofstream output("out.txt");

    for (int i = 0; i<velikost; i++)
        output << polje[i] << ' ';
}

int cifra(int &a){
  a = a+1;
  return a;
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

        for (int j = 0; j < stringarray2->length(); ++j) {
            reverseString(stringarray2[j]);
        }

        int temp1 = i-1;
        while(temp1>0)
        {
            int vrednosttemp=i-1;
            for (int j = 0; j < temp1; ++j) {
                string t1 = stringarray1[j];
                string t2 = stringarray2[j];
                //cout<<"\n1"<<t1<<"\n2"<<t2;
                if(t1 == t2) {
                    vrednostkmp=vrednosttemp;
                    break;
                }
                vrednosttemp--;
            }

            temp1--;
        }

        kmpNext[i]=vrednostkmp;

        /*cout<<"\nstringarray1\n";
        for (int j = 0; j < stringarray1->length(); ++j) {
            cout<<"\n"<<j<<"\n";
            cout<<stringarray1[j];

        }
        cout<<"\nstringarray2\n";
        for (int j = 0; j < stringarray2->length(); ++j) {
            cout<<"\n"<<j<<"\n";
            cout<<stringarray2[j];
        }*/

    }
    for (int i = 0; i < len; ++i) {
        cout<<kmpNext[i];
    }
    int premik=0;
    int d=0;
    for (int i = 0; i < text.length(); i=i+premik) {
        d=0;
        for (int j = 0; j < len; ++j) {
            if(vzorec[j] != text[i+j]){
                premik = j - kmpNext[j];
                d++;
                break;
            }
        }
        if(d==0){
            najdeni.append(to_string(i)+" ");
            premik = vzorec.length();
        }

    }
    Izpis_Stevil(&najdeni, 1);

}
void Sunday(const string& text, const string& vzorec){
    string carachters="";

    for (int i = 0; i < vzorec.length(); ++i) {
        bool found = false;
        for (int j = 0; j < carachters.length(); ++j) {
            if (carachters[j] == vzorec[i]) {
                found = true;
                break;
            }
        }
        if (!found) {
            carachters += vzorec[i];
        }
    }
    for (int i = 0; i < text.length(); ++i) {
        bool found = false;
        for (int j = 0; j < carachters.length(); ++j) {
            if (carachters[j] == text[i]) {
                found = true;
                break;
            }
        }
        if (!found) {
            carachters += text[i];
        }
    }
    cout<<carachters;
    int BHC[carachters.length()];
    for (int i = 0; i < carachters.length(); ++i) {
        bool found = false;
        int counter = 1;
        for (int j = vzorec.length()-1; j >= 0; --j) {

            if(vzorec[j]==carachters[i]){
                BHC[i]=counter;
                found = true;
                break;
            }
            counter++;
        }
        if(found == false){
            BHC[i]=vzorec.length()+1;
        }
    }
    for (int i = 0; i <  carachters.length(); ++i) {
        cout<<BHC[i];
    }

    int premik=0;
    bool found = true;
    bool premiknajden = false;
    string najdeni="";
    for (int i = 0; i < text.length()-vzorec.length(); i=i+premik) {
        found = true;
        premiknajden = false;
        for (int j = 0; j < vzorec.length(); ++j) {
            if(vzorec[j]!=text[i+j]){
                found = false;
                for (int k = 0; k < carachters.size(); ++k) {
                    if(text[i+j+1]==carachters[i]){
                        premik=BHC[k];
                        premiknajden=true;
                        break;
                    }
                }

            }
        }
        if(!premiknajden){
            premik = vzorec.size();
        }
        if(found == true){
            najdeni.append(to_string(i)+" ");
        }
    }
    
    Izpis_Stevil(&najdeni, 1);

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
        Sunday(text,vzorec);
    }


    return 0;
}
