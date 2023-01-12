#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>
/*
   RULES:
       you get 4 numbers a b c d
       you must make 10 out of these numbers 
       all numbers are alowed to be used as possitive or negative.
       you have to use the numbers in order (cant do a*d + b + c)
       you can use bodmas so can go a + ((b+c)*d)
       goodluck

     https://www.javatpoint.com/return-an-array-in-c         bottom one
   */    
//node for individuals
typedef struct nodeI {

     double val_1;
     double results[2];
     struct node* next;

} nodeI;

//node for Pairs
typedef struct nodeP {

     double val_1;
     double val_2;
     double results[13];
     struct node* next;

} nodeP; 

//node for tripple I then P
//node for Pairs
typedef struct nodeI_P_Trip {

     
     double results[169];
     struct node* next;

} nodeI_P_Trip; 

typedef struct nodeP_I_Trip {

     
     double results[130];
     struct node* next;

} nodeP_I_Trip; 
     
nodeP* twoTooThirteen(double x, double y);
nodeI* oneTooTwo(double x);
nodeI_P_Trip* I_PtooTrip(double x, nodeP* yz);
nodeP_I_Trip* P_ItooTrip(nodeP* yz, double x);

int main(int argc, char* argv[]){
      /*
                         a    b    c    d
     indivividuals  I    +- a b c d
     pairs          P    ab bc cd   (-+*^/)                      keep all these indi, pairs, tripplets in there own struct
     tripplets      T    a(bc)  (ab)c  b(cd)  (bc)d     NOTE THESE ARE JUST GROUPS  (the first one can be a+(b*c) we are just saying we are calculating bc first)
     then have a function that can use all the individuals pair and tripplets to find 10
     */
     
     
     double a ,b ,c ,d ;
     a = 2;
     b = 4;
     c = 6;
     d = 1;

     //create all individual combos
     nodeI* I_a = oneTooTwo(a);
     nodeI* I_b = oneTooTwo(b);
     nodeI* I_c = oneTooTwo(c);
     nodeI* I_d = oneTooTwo(d);
     //create all the pair combos
     nodeP* P_ab = twoTooThirteen(a,b);
     nodeP* P_bc = twoTooThirteen(b,c);
     nodeP* P_cd = twoTooThirteen(c,d); 
     //create tripple from Individual then pair
     nodeI_P_Trip* T_a_bc = I_PtooTrip(a,P_bc);
     nodeI_P_Trip* T_b_cd = I_PtooTrip(b,P_cd);
     //create tripple from pair then individual

     nodeP_I_Trip* T_ab_c = P_ItooTrip(P_ab, c);
     nodeP_I_Trip* T_bc_d = P_ItooTrip(P_bc, d);

     free(I_a);
     free(I_b);
     free(I_c);
     free(I_d);
     free(P_ab);
     free(P_bc);
     free(P_cd);
     free(T_a_bc);
     free(T_b_cd);
     free(T_ab_c);
     free(T_bc_d);

     return 0;
}


//oneTooTwo simply creates the same node structure for the first elemebt that can either be pos or neg
nodeI* oneTooTwo(double x){

     
     nodeI* body = NULL;
     body = (nodeI*) malloc(sizeof(nodeI));
     if(body == NULL){
          printf("Yo we couldnt make the malloc !\n");
          return NULL;
     }
     body->val_1 = x;
    
     body->results[0] = x  ;
     body->results[1] = -x ;

     return body;

}

//twoTooThirteen() 
//There are only 13 outputs that two numbers can make.
//we can deduce what maths symbols was used by its array index 0 ++, 1 +-, 2+*, 3 +/ ........
//This function will take two doubles and return all the values those two numbers can make in a struct (gives back pointer but makes struct inside). 
//Note the numbers must be passed in order as b/a is not in order or a legal move in the train game yet a/b is fine
nodeP* twoTooThirteen(double x, double y){

     nodeP* body = NULL;
     body = (nodeP*) malloc(sizeof(nodeP));
     if(body == NULL){
          printf("Yo we couldnt make the malloc !\n");
          return NULL;
     }
     body->val_1 = x;
     body->val_2 = y;
     
     body->results[0] = x + y;
     body->results[1] = x - y;
     body->results[2] = x * y;
     body->results[3] = x / y;
     body->results[4] = pow(x,y);         //x ^ y;
     body->results[5] = pow(x,(-y));      //x ^ (-y)
     body->results[6] = -x + y;
     body->results[7] = -x - y;
     body->results[8] = -x * y ;
     body->results[9] = -x / y ;
     body->results[10] = pow((-x),y);     //-x ^ y
     body->results[11] = -x + (-y);
     body->results[12] = pow((-x),(-y));  //-x ^ (-y);

     //print checks :)
     //printf("x is %lf, y is %lf\n",x,y);
     //for(int i=0; i<13; i++){
     //     printf("%lf\n",body->results[i]);
     //}

     return body;

}

//get all the values that can be made with a tripple pair a (bc)
nodeI_P_Trip* I_PtooTrip(double x, nodeP* yz){

     nodeI_P_Trip* body = NULL;
     body = (nodeI_P_Trip*) malloc(sizeof(nodeI_P_Trip));
     if(body == NULL){
          printf("Yo we couldnt make the malloc !\n");
          return NULL;
     }

     for(int i = 0; i < 13 ; i++){ 
          //printf("x is %lf, yz is %lf\n\n",x,yz->results[i]);
          body->results[0 + (13*i)] = x + yz->results[i];
          body->results[1 + (13*i)] = x - yz->results[i];
          body->results[2 + (13*i)] = x * yz->results[i];
          body->results[3 + (13*i)] = x / yz->results[i];
          body->results[4 + (13*i)] = pow(x,yz->results[i]);         //x ^ y;
          body->results[5 + (13*i)] = pow(x,(-yz->results[i]));      //x ^ (-y)
          body->results[6 + (13*i)] = -x + yz->results[i];
          body->results[7 + (13*i)] = -x - yz->results[i];
          body->results[8 + (13*i)] = -x * yz->results[i] ;
          body->results[9 + (13*i)] = -x / yz->results[i] ;
          body->results[10 + (13*i)] = pow((-x),yz->results[i]);     //-x ^ y
          body->results[11 + (13*i)] = -x + (-yz->results[i]);
          body->results[12 + (13*i)] = pow((-x),(-yz->results[i]));  //-x ^ (-y);
     }

     //for(int i = 0; i < 169; i++){
     //     printf("%d is : %lf\n",i, body->results[i]);
     //}


     return NULL;
}

//get all the values that can be made with a tripple pair (ab) c 
//MAYBE CHANGE BACK TO 169 logic instead of 130 ??????????????????????????????????????????????
nodeP_I_Trip* P_ItooTrip(nodeP* yz, double x){

     nodeP_I_Trip* body = NULL;
     body = (nodeP_I_Trip*) malloc(sizeof(nodeP_I_Trip));
     if(body == NULL){
          printf("Yo we couldnt make the malloc !\n");
          return NULL;
     }


     for(int i = 0; i < 13 ; i++){ 

         


          body->results[0 + (13*i)] = yz->results[i] + x;
          body->results[1 + (13*i)] = yz->results[i] - x;
          body->results[2 + (13*i)] = yz->results[i] * x;
          body->results[3 + (13*i)] = yz->results[i] / x;
          body->results[4 + (13*i)] = pow(yz->results[i],x);         //x ^ y;
          body->results[5 + (13*i)] = pow(yz->results[i],(-x));      //x ^ (-y)
          body->results[6 + (13*i)] = -yz->results[i] + x;
          body->results[7 + (13*i)] = -yz->results[i] - x;
          body->results[8 + (13*i)] = -yz->results[i] * x ;
          body->results[9 + (13*i)] = -yz->results[i] / x ;
          body->results[10 + (13*i)] = pow((-yz->results[i]),x);     //-x ^ y
          body->results[11 + (13*i)] = -yz->results[i] + (-x);
          body->results[12 + (13*i)] = pow((-yz->results[i]),(-x));  //-x ^ (-y);
          
     }

     for(int i = 0; i < 169; i++){
          printf("%d is : %lf\n",i, body->results[i]);
     }


     return NULL;
}


















