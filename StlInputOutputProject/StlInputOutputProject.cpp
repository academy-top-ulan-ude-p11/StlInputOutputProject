#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void FileWrite();
void FileRead();

struct Pair
{
    string key;
    int value;
};

int main()
{
    // FileWrite();
    // FileRead();

    ofstream fileTxt;
    ofstream fileBin;

    fileTxt.open("file02.txt", ios::out);
    fileBin.open("file02.dat", ios::binary);

    int number = 100;
    char str[] = "100";

    fileTxt << str;
    fileBin << number;
    
    fileTxt.close();
    fileBin.close();

    FILE* fileBinC = fopen("file03.dat", "wb");
    fwrite(&number, sizeof(number), 1, fileBinC);
    fclose(fileBinC);

    /*fileBin.open("file02.dat", ios::in | ios::binary);
    fileBin >> number;
    cout << "number = " << number << "\n";*/
}


void FileWrite()
{
    srand(time(nullptr));
    int matrix[4][5];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
            matrix[i][j] = rand();


    ofstream wfile;
    wfile.open("file01.txt", ios::out);

    //string str1 = "Hello world";
   /* wfile.write(str1.c_str(), str1.length());
    wfile.put('!');*/
    //wfile << setw(20) << str1 << '!';


    //string str2 = "Hello poeple";
    /*wfile.put('\n');
    wfile.write(str2.c_str(), str2.length());
    wfile.put('!');*/
    //wfile << "\n" << str2 << '!';

    //cout << wfile.tellp() << "\n";
    //wfile.seekp(-8, ios_base::end);
    //cout << wfile.tellp() << "\n";
    ////wfile.put('#');
    //wfile << "#";

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << setw(8) << matrix[i][j] << " ";
            wfile << setw(8) << matrix[i][j] << " ";
        }
        cout << "\n";
        wfile << "\n";
    }

    wfile.close();
}

void FileRead()
{
    ifstream rfile;
    rfile.open("file01.txt", ios::in);

    /*rfile.seekg(0, ios::end);
    int size = rfile.tellg();

    cout << "size of file " << size << " bytes\n";
    string buffer(size, '\0');

    rfile.seekg(0, ios::beg);
    rfile.read(&buffer[0], size);

    cout << buffer;*/

    //string buffer(1024, '\0');
    string buffer;

    while (!rfile.eof())
    {
        //cout << (char)rfile.get();
        /*rfile.getline(&buffer[0], buffer.length());
        cout << buffer << "\n";*/
        /*rfile >> buffer;
        cout << buffer;*/
    }

    rfile.close();
}