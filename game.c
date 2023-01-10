#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/*
   RULES:
        use all 4 numbers in order (bodmas) to create 10 (has to be in order)
        there are only -, +, *, /, ^, and brackets ( )
        1) use if and loops to run through all combinations then print it out
        2) use recursion to run through all combos then print
        3) linked lists so can create heaps long arrays (or just have heaps long arrays)
        4) might have to do the table shit on search trees to remember how the code got to that number
   */    
     


int main(int argc, char* argv[]){

     
     int sNum[4] = {1 , 2 , 3, 4}; // sNum = start num 
     
     //idea -> find every number that can be made between 0 and 1, then find every number that can be found when you add the next number, than the next
     // gota be careful of 1 3 3 0 , you gota do 1 + (3*3) + 0 and if you just use 1 + 3  * 3 + 0 ,or whatever, you are screwed so gota get all the bracket values
     // also stuf like 1+((1+2))*3)

     /*
     BRUTE FORCE BABY
     
                         a    b    c    d


     indivividuals  I    +- a b c d
     pairs          p    ab bc cd   (-+*^/)

     
     so i wana make a function that takes two numbers then returns an array of 10 numbers coresponding to all the options the twho numbers can create
     twoTooTen()
     
     ///////////////////////////////////////////
     this funtion will return a struct which will have the array of all 10 options. It will also hold how it got all each to numbers o it is easier to print out later
     https://www.javatpoint.com/return-an-array-in-c         bottom one
     ///////////////////////////////////////////

     
     
     
     */



     //start with each number realising it can be pos or neg
     int pn_0[2];  
     int pn_1[2];
     int pn_2[2];
     int pn_3[2];
     // of the two numbers in pos neg, the next number can be -, +, *, /, ^,
     int pairs_01[50];  // possible nums that can be made between 0 and 1




     //printf("%d\n", argc);

     /* a pointer to an int */
     int *p;
     int i;

     p = getRandom();
          
     for ( i = 0; i < 10; i++ ) {
          printf( "*(p + %d) : %d\n", i, *(p + i));
     }


     return 0;
}


int *twoTooTen() {

   
}