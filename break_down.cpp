#include <iostream>
#include <fstream>
#include <string>
#include<dirent.h>
using namespace std;

void break_down(){
    string line;
    int count = 0;
    string outdir = "./seperate_html/";
    string indir = "./input_files/";
    ifstream fin;

    DIR *pDIR;
    struct dirent *entry;
        if( pDIR=opendir(indir.c_str()) ){
            while(entry = readdir(pDIR)){
                if( entry->d_name != "." && entry->d_name !="..") {
                    cout << entry->d_name << "\n";
                    fin.open((indir + entry->d_name).c_str());
                    while(getline(fin, line)){
                        ofstream fout;
                        fout.open((outdir+to_string(count)).c_str());

                        cout << line << endl;
                        fout << line << endl;
                        if(fout.is_open()){
                            while(line != "</DOC>" && getline(fin, line)){
                                cout << line << endl;
                                fout << line << endl;
                            }
                            fout.close();
                            count ++;
                        }else{
                            cerr << "Output file cannot open." << endl;
                        }
                    }
                    fin.close();
                }
            }
            closedir(pDIR);
        }

}

int main(){
    break_down();

    return 0;
}
