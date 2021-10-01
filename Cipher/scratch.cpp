//
// Created by Christopher Morrissey on 10/1/21.
// this program will read a file line by line
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string line;
    fstream myfile("mytext.txt", ios::in);
    if(myfile.is_open()){
        while( getline(myfile,line)){
            cout << line << endl;
        }
        myfile.close();
    }
    else
        cout << "Unable to open file";
    return 0;
}
