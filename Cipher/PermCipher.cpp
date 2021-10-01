//============================================================================
// Name        : csci221-HW02.cpp
// Author      : Christopher Morrissey
// Version     :
// Copyright   :
// Description : Permutation Cipher Program
//============================================================================

#include <iostream>
#include <stdio.h>
#include<fstream>
#include<array>
#include<string>
#include <unistd.h>

using namespace std;


//int getopt();
int printDirections();
void writefile();
void readfile();


int main(int argc, char** argv) {
    int blockSize;
    char* optstring;
    string optionsInput;
    FILE *infile, *outfile;
    int length = 20;
    char messageArray[length][50];

    char opt;  //this could also be int opt=0 if I was using numerical switch
    string inputFile;
    string outputFile;
    int eflag, dflag, iflag, oflag;

    eflag = 0;
    dflag = 0;
    iflag = 0;
    oflag = 0;

    while( (opt = getopt(argc, argv, "i:o:ed")) != -1){
        switch(opt){
            case 'i':
                iflag = 1;
                inputFile = optarg;
                break;
            case 'o':
                oflag = 1;
                outputFile = optarg;
                break;
            case 'e':
                eflag = 1;
                break;
            case 'd':
                dflag = 1;
                break;
            default:
                cout << "Unknown option " << argv[0] << endl;

        }
    }
    printf("i flags=%d; oflag=%d; eflag=%d; dflag=%d optind=%d\n", iflag, oflag, eflag, dflag, optind);

    if(argc != 6 || (iflag == 0) || (oflag == 0) ||
       (eflag == dflag)){
        cout << "Error! Incorrect options selected." << endl;
    }

    printf("name argument = %s\n", argv[argc]);




//call print directions
printDirections();
//writefile();
readfile();


    cout << "Please enter the block size (2-8) and the permutation (e.g., 4 2413): "<<endl;
    cin >> blockSize;
    int* permutation= new int[blockSize];
    int* key= new int[sizeof permutation];
    cout << "Please enter the permutation one number at a time with a space between. Press enter when done: ";
    for (int i=0; i<blockSize; i++){
        //getline(cin,permutation[i]);
        cin >> permutation[i]; // cin reads up to the enter key then sits there
    }
    // this will print the values of the array to the screen in a single line
    for (int i=0; i < blockSize; i++) {
        cout << permutation[i];
       // cout << "\n" <<endl;
    }
   // cout<<"\n" << *key; //print the information stored at the pointer key which is the key to the encryption

    //cout << &permutation;

    //cout << "You entered blocksize: "<< blockSize << ", permutation: "<< permutation[blockSize]<< endl;
    //print out what user enters
    //cout << "Encrypted/Decrypted ciphertext file: " <<endl;


    return 0;
}

int printDirections(){
    string optionsInput;
    cout << "Usage: ./PermCipher option -i InputFileName -o OutputFileName"<<endl;
    // getline("enter options: ");
    //argv[] = cin >> inputFile >> outputFile >> opt >> endl;
    cout << "Options: -e Encrypt -d Decrypt" << endl;
    //write commands to accept input here
    // ()
    printf("Choose an option: ");
    getline(cin, optionsInput);
    cout << "You entered: " << optionsInput;
    // getopt(optionsInput);

    // this should take ./Permcipher -o/-d -i file -o file

    //Welcomes user and outputs the Options
    cout << "Welcome to the Permutation Cipher" <<endl;
    cout << "Selected Mode: " << endl; //user choice for mode either E or D
    cout << "Output File: " <<endl; //put the user choice for output here
    return 0;
}

void writefile()
{
    string line;
    //fstream myfile("mytext2.txt", ios::in);
    /*if(myfile.is_open()){
        while( getline(myfile,line)){
            cout << line << endl;
        }
        myfile.close();
    }
    else
        cout << "Unable to open file";*/
    fstream myFile;
    myFile.open("testText.txt", ios::out); //write
    if(myFile.is_open())
    {
        myFile << "Hello\n";
        myFile << "This is the second line\n";
        myFile.close();
    }
    myFile.open("testText.txt", ios::app); //append to file
    if (myFile.is_open())
    {
        myFile << "This is the append";
        myFile << "Append another line";
        myFile << "append one more";
        myFile.close();
    }

}

/*void readfilebyChar()
{

char* message[]
    ifstream in("testText.txt");
    //myFile.open("testText.txt", ios::in);
    if(in.fail()) {
        cout << "Error.";
    }
    else
    {
        char c;
        while(in.get(c))
        {}
    }
}
*/

void readfile()
{
    fstream myFile;
    myFile.open("testText.txt", ios::in); //read
    if(myFile.is_open())  //access the line, store it to string variable, then repeat
    {
        string line;
        while (getline(myFile, line)) {  //e the line and stores into the variable called line
            //once there are no more lines the loop ends
            cout << line << endl;
        }
        myFile.close();
    }

}

//ofstream - stream class to write on files
//ifstream stream class to read from files
//fstream stream class to both read and write from/to files


//std::skipws and std::noskipws
/*#include <iostream>
#include <sstream>
int main()
{
    char c1, c2, c3;
    std::istringstream("a b c") >> c1 >> c2 >> c3;
    std::cout << "Default  behavior: c1 = " << c1 << " c2 = " << c2 << " c3 = " << c3 << '\n';
    std::istringstream("a b c") >> std::noskipws >> c1 >> c2 >> c3;
    std::cout << "noskipws behavior: c1 = " << c1 << " c2 = " << c2 << " c3 = " << c3 << '\n';
}
Output:
Default  behavior: c1 = a c2 = b c3 = c
noskipws behavior: c1 = a c2 =   c3 = b*/

/*int getopt(int argc, char** argv[], const char *optstring){
    char opt;  //this could also be int opt=0 if I was using numerical switch
    string inputFile;
    string outputFile;
    int eflag, dflag, iflag, oflag;

    eflag = 0;
    dflag = 0;
    iflag = 0;
    oflag = 0;

    while( (opt = getopt(argc, argv, "i:o:ed")) != -1){
        switch(opt){
            case 'i':
                iflag = 1;
                inputFile = optarg;
                break;
            case 'o':
                oflag = 1;
                outputFile = optarg;
                break;
            case 'e':
                eflag = 1;
                break;
            case 'd':
                dflag = 1;
                break;
            default:
                cout << "Unknown option " << argv[0] << endl;

        }
    }
    printf("i flags=%d; oflag=%d; eflag=%d; dflag=%d optind=%d\n", iflag, oflag, eflag, dflag, optind);

    if(argc != 6 || (iflag == 0) || (oflag == 0) ||
       (eflag == dflag)){
        cout << "Error! Incorrect options selected." << endl;
    }

    printf("name argument = %s\n", argv[argc]);
    return 0;
}
*/

/* can use getline to get the whole thing and then loop
 *
 * for(int i=0, i<blocksize; i++)
 * use getlineIinput)
 * permmutation[i] = input[i] may need to cast)
 */
