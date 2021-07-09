/*
* Clayton Bradford
* CS372 - Fall 2020
* 5th Program 
* Triangle Program from PDF
*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

ofstream out("triangle.out");

//Prototypes
void space(char);
void line(char, char, char);
void triangle(char, char, char); 

//Functions 
void space(char s) //function to add spaces 
{
     if (s <= 0)
          return;
     out << " ";
     space(s - 1);
}

void line(char st, char en, char sp)
{
     if (st != en)
     {
          out << st;   //to print in order
          line(st + 1, en, sp - 1);
          out << st;  //to print in reverse order 
     }
     //else, go to a newline 
     else
          out << en;
}

void triangle(char st, char en, char sp)
{
     ++sp;
     if (st != en)
     {
          triangle(st, en - 1, sp);
     }

     space(sp); //print a space in order
     line(st, en, sp);
     space(sp);  //print a space in reverse order 
     out << endl;
}

int main()
{
     //Start/Stop range is based off the pdf triangle 
     // includes all letters and symbols between A-m
     char st = 'A';
     char en = 'm';
     char sp = 0;
     triangle(st, en, sp);
     out.close();
     return 0;
}