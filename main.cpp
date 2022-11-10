/*
 Assignment 2: Create a Radix Sort | well-written, efficient, and versatile

 Professor Cook:
 Patrick Shin
 Student ID: 302290287
 
 Read a file and Sort
 */
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <string>
#include <semaphore>
#include <vector>
#include "Entry.hpp"

using namespace std;

int main() {
    // insert code here...
    //Entry<string> file1[30];
    
    Entry<string> file1;
    string h1 = "/Users/mushu/Desktop/CS130/Assignment_2_PS/Assignment_2_PS/years.txt";

    file1.About();
    file1.readFile(h1);
    cout << endl;
     
    /*
    Entry<string> file2;
    string h2 = "/Users/mushu/Desktop/CS130/Assignment_2_PS/Assignment_2_PS/zipcodes_copy.txt";
    
    file2.readFile(h2);
    */
    
    Entry<string> file3;
    string h3 = "/Users/mushu/Desktop/CS130/Assignment_2_PS/Assignment_2_PS/pokemon.txt";
    
    file3.About();
    file3.readFile(h3);
    cout << endl;

    Entry<string> file4;
    string h4 = "/Users/mushu/Desktop/CS130/Assignment_2_PS/Assignment_2_PS/areacode_copy.txt";
    
    file3.About();
    file4.readFile(h4);
    cout << endl;

    Entry<string> file5;
    string h5 = "/Users/mushu/Desktop/CS130/Assignment_2_PS/Assignment_2_PS/stooges_copy.txt";
    
    file5.About();
    file5.readFile(h5);
    cout << endl;

    return 0;
}

