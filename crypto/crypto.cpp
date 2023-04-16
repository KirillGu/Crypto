#include <fstream>
#include <iostream>
#include <cstdio>
using namespace std;

class encdec {
    int key;
    
    string file;
    char c;

public:
    void encrypt();
    void decrypt();
};

void encdec::encrypt()
{
    cout << "Your file: ";
    cin >> file;

    cout << "Your key: ";
    cin >> key;

    fstream fin, fout;

    fin.open(file, fstream::in);
    fout.open("encrypt.txt", fstream::out);

    while (fin >> noskipws >> c) {
        int temp = (c + key);
        fout << (char)temp;
    }
    fin.close();
    fout.close();
}

void encdec::decrypt(){
    cout << "File: ";
    cin >> file;

    cout << "Key: ";
    cin >> key;

    fstream fin;
    fstream fout;
    fin.open(file, fstream::in);
    fout.open("decrypt.txt", fstream::out);

    while (fin >> noskipws >> c) {
        int temp = (c - key);
        fout << (char)temp;
    }

    fin.close();
    fout.close();
}

int main()
{
    encdec enc;
    char c;
    cout << "\n";
    cout << "Choice: \n";
    cout << "1. Encrypt \n";
    cout << "2. Decrypt \n";
    cin >> c;
    cin.ignore();

    switch (c) {
        case '1': {
            enc.encrypt();
            break;
        }
        case '2': {
            enc.decrypt();
            break;
        }
    }
}