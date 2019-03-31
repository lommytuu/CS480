/*
Name:               Tommy Luu
WSU ID:             P476T774
Course:             CS 400
Program Number:     1

*/

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <array>

using namespace std;

//Sort function
void insertionSort(int a[], int size) {
	for (int i = 1; i < size; i++) {
		int key = a[i];
		int j = i - 1;
		for (; j >= 0 && a[j] > key; j--) {
			a[j + 1] = a[j];
		}
		a[j + 1] = key;
	}
}

int main(void)
{
    //Variable Declarations
    int input, size = 50001;
    int * list = new int[size];
    ofstream writeFile;
    string inFile;

    inFile = "sorted.txt";

    //Add random numbers
     for(int i = 0; i < size; i++)
     {
         list[i] = (rand() * rand()) % 50000000 + 1;
     }
            
     //sort
     insertionSort(list, size);

     //write numbers to file
     writeFile.open(inFile);
     for (int i = 1; i < size; i++)
     {     
         writeFile << list[i] << endl;
     }           
     writeFile.close();
       
     //delete list
     delete [] list;
     list = 0;

     return 0;
}

