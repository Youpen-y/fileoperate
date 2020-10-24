/* 
** ofstream: class for output(which means program can output something into)
** ifstream: class for input(which means input something into program)
** fstream: class for input/output

** iso_base——ios——ostream——ofstream
**             |__istream——ifstream
*/
#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    //First way to open a file with default mode: ios::out
    ofstream myfile;
    myfile.open("output.txt");
    if(myfile.is_open()){
    myfile << "Write this first sentence into a file.\n";
    myfile.close();
    }else cout << "Error on opening the file!!!"<<endl;

    
    //Get content from a file
    ifstream anotherfile;
    string sentence;
    anotherfile.open("output.txt"); //default mode is ios::in
    anotherfile >> sentence;       //when it comes to a space, it'll end.
    cout << sentence <<endl;       
    getline(anotherfile,sentence);      //get the whole line
    cout << sentence <<endl;

    //Second way to open a file with special mode
    myfile.open("output.txt",ios::ate|ios::trunc);      //auto-add the mode ios::out 
    myfile << "why you cancelled me???"<<endl;
    myfile << "stop";
    myfile.close();

    //Third way to open a file with constructor
    fstream yourfile("output.txt",ios::in);          //default ios::in | ios::out, if there is mode existing, it won't be added.
    string newsentence;
    getline(yourfile,newsentence);
    cout << newsentence << endl;
    yourfile.close();

    //Obtaining file size
    streampos begin, end;               //streampos: a type returned by seekg(), seekp() and no arguments functions tellg(), tellp() 
    yourfile.open("output.txt");
    begin = yourfile.tellg();
    yourfile.seekg(0,ios::end);         //seekg(offset, direction) direction: ios::end, ios::beg, ios::cur
    end = yourfile.tellg();
    yourfile.close();
    cout << "size is: "<<(end-begin) << "characters(space and newline inclued).\n";

    /*//To binary file
    yourfile.open("test.bin",ios::in|ios::out|ios::binary);
    string a = "hello world";
    yourfile.close();*/
    
    return 0;
}