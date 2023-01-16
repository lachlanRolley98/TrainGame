#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>

//usually more stuff in this
typedef struct nodeP {
     struct node* next;
} nodeP; 

typedef struct nodeP_I_Trip {

     double val_1;
     double val_2;
     double val_3;
     double results[130];
     struct node* next;

} nodeP_I_Trip; 

nodeP_I_Trip* P_ItooTrip(nodeP* yz, double x);

int main(void){

    double c = 0, d = 0 ;
    nodeP* P_ab = NULL; //usually has stuff in them
    nodeP* P_bc = NULL; //usually has stuff in them


    //create tripple from pair then individual
    nodeP_I_Trip* T_ab_c = P_ItooTrip(P_ab, c);        // THIS ONE WORKS
    printf("we got here\n");                           // THIS PRINTS                        
    nodeP_I_Trip* T_bc_d = P_ItooTrip(P_bc, d);        // HANGS IN THIS
    printf("we passed it !\n");                        // DOESNT PRINT



}


nodeP_I_Trip* P_ItooTrip(nodeP* yz, double x){
     //printf("we got in \n");
     nodeP_I_Trip* body = NULL;
     //printf("we got in \n");

     body = (nodeP_I_Trip*) malloc(sizeof(nodeP_I_Trip) + 10);            // THE CODE HANGS HERE
     printf("did we get here\n");
     fflush(stdout);
     fflush(stdout);
     
     if(body == NULL){
          printf("Yo we couldnt make the malloc !\n");
          return NULL;
     }

     return body;
}