
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>



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

     double val_1;
     double val_2;
     double val_3;
     double results[169];
     char strings[169][51];
     struct node* next;

} nodeI_P_Trip; 

typedef struct nodeP_I_Trip {

     double val_1;
     double val_2;
     double val_3;
     double results[169];
     char strings[169][51];  // cant malloc this then dymanically give it different lengths in the code
     struct node* next;

} nodeP_I_Trip; 
     



nodeP* twoTooThirteen(double x, double y);
nodeI* oneTooTwo(double x);
nodeI_P_Trip* I_PtooTrip(double x, nodeP* yz);
nodeP_I_Trip* P_ItooTrip(nodeP* yz, double x);
void P_ItooTripArray(nodeP* yz, double x, double *arrayPtr);
void pairToTen(nodeP* ab, nodeP* cd);
void printPair(nodeP* ab, nodeP* cd, int i, int j, int k);

void twoTooTen(nodeI* a,  nodeI_P_Trip* bcd);




int main(int argc, char* argv[]){
      
     //                    a    b    c    d
     //indivividuals  I    +- a b c d
     //pairs          P    ab bc cd   (-+*^/)                      keep all these indi, pairs, tripplets in there own struct
     //tripplets      T    a(bc)  (ab)c  b(cd)  (bc)d     NOTE THESE ARE JUST GROUPS  (the first one can be a+(b*c) we are just saying we are calculating bc first)
     //then have a function that can use all the individuals pair and tripplets to find 10
     
     double a ,b ,c ,d ;
     a = 1;
     b = 2;
     c = 3;
     d = 4;

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
     nodeP_I_Trip* T_bc_d = P_ItooTrip(P_ab, c);       
    


/*
     1-5 can go into pairToTen, the number is added to tell print function what format

     0   a (bc) d       custom
     1   (ab)(cd)       pair done
     2   a(b(cd))       pair
     3   a((bc)d)       pair
     4   (a(bc))d       pair
     5   ((ab)c)d       pair
*/

     pairToTen(P_ab,P_cd); //(ab)(cd)       pair done

    
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

     printf("Starting\n\n");
     
     nodeI_P_Trip* body = NULL;
     body = (nodeI_P_Trip*) malloc(sizeof(nodeI_P_Trip));
     if(body == NULL){
          printf("Yo we couldnt make the malloc !\n");
          return NULL;
     }
     body->val_1 = x;
     body->val_2 = yz->val_1;
     body->val_3 = yz->val_2;

     
     for(int i = 0; i < 13 ; i++){ 
          double a, b;
          a = yz->val_1;
          b = yz->val_2;
          char c1;
          //this switch figures out what in the smaller bracket
          switch(i){
               case 0:
                    c1 = '+';
                    break;
               case 1:
                    c1 = '-';
                    break; 
               case 2:
                    c1 = '*';
                    break;
               case 3:
                    c1 = '/';
                    break; 
               case 4:
                    c1 = '^';
                    break;
               case 5:
                    c1 = '^';
                    b = -b;
                    break; 
               case 6:
                    c1 = '+';
                    a = -a;
                    break;
               case 7:
                    c1 = '-';
                    a = -a;
                    break;     
               case 8:
                    c1 = '*';
                    a = -a;
                    break;
               case 9:
                    c1 = '/';
                    a = -a;
                    break; 
               case 10:
                    c1 = '^';
                    a = -a;
                    break;
               case 11:
                    c1 = '-';
                    a = -a;
                    b = -b;
                    break; 
               case 12:     
                    c1 = '^';
                    a = -a;
                    b = -b; 
                    break;             
          }

          char buffer[50]; // im gona use sprintf to first put it in this buffer then copy the buffer over to the struct string cos asprintf isnt working (undefined)
          // find the results and also save a string of the equation
          body->results[0 + (13*i)] = x + yz->results[i];
          sprintf(buffer, "(%lf +(%lf %c %lf))",x, a, c1, b );    // im thihnking this shit wont work cos we are mallocing the big boy and it has no idea how long these strings are gona be
          strcpy(body->strings[0 + (13*i)], buffer);
          
          body->results[1 + (13*i)] = x - yz->results[i];
          sprintf(buffer, "(%lf -(%lf %c %lf))",x, a, c1, b );
          strcpy(body->strings[1 + (13*i)], buffer);


          body->results[2 + (13*i)] = x * yz->results[i];
          sprintf(buffer, "(%lf *(%lf %c %lf))",x, a, c1, b );
          strcpy(body->strings[2 + (13*i)], buffer);


          body->results[3 + (13*i)] = x / yz->results[i];
          sprintf(buffer, "(%lf /(%lf %c %lf))",x, a, c1, b );
          strcpy(body->strings[3 + (13*i)], buffer);


          body->results[4 + (13*i)] = pow(x,yz->results[i]);         //x ^ y;
          sprintf(buffer, "(%lf ^(%lf %c %lf))",x, a, c1, b );
          strcpy(body->strings[4 + (13*i)], buffer);


          body->results[5 + (13*i)] = pow(x,(-yz->results[i]));      //x ^ (-y)
          sprintf(buffer, "(%lf ^(-(%lf %c %lf)))",x, a, c1, b );
          strcpy(body->strings[5 + (13*i)], buffer);


          body->results[6 + (13*i)] = -x + yz->results[i];
          sprintf(buffer, "(%lf +(%lf %c %lf))",-x, a, c1, b );
          strcpy(body->strings[6 + (13*i)], buffer);


          body->results[7 + (13*i)] = -x - yz->results[i];
          sprintf(buffer, "(%lf -(%lf %c %lf))",-x, a, c1, b );
          strcpy(body->strings[7 + (13*i)], buffer);


          body->results[8 + (13*i)] = -x * yz->results[i] ;
          sprintf(buffer, "(%lf *(%lf %c %lf))",-x, a, c1, b );
          strcpy(body->strings[8 + (13*i)], buffer);


          body->results[9 + (13*i)] = -x / yz->results[i] ;
          sprintf(buffer, "(%lf /(%lf %c %lf))",-x, a, c1, b );
          strcpy(body->strings[9 + (13*i)], buffer);


          body->results[10 + (13*i)] = pow((-x),yz->results[i]);     //-x ^ y
          sprintf(buffer, "(%lf ^(%lf %c %lf))",-x, a, c1, b );
          strcpy(body->strings[10 + (13*i)], buffer);


          body->results[11 + (13*i)] = -x + (-yz->results[i]);
          sprintf(buffer, "(%lf -(%lf %c %lf))",-x, a, c1, b );
          strcpy(body->strings[11 + (13*i)], buffer);


          body->results[12 + (13*i)] = pow((-x),(-yz->results[i]));  //-x ^ (-y);
          sprintf(buffer, "(%lf ^(-(%lf %c %lf)))",-x, a, c1, b );
          strcpy(body->strings[12 + (13*i)], buffer);


     }
     
     for(int i = 0; i < 169; i++){
          printf("%s\n",body->strings[i]);
     }


     return NULL;
}

//get all the values that can be made with a tripple pair (ab) c 
nodeP_I_Trip* P_ItooTrip(nodeP* yz, double x){
     //printf("we got in \n");
     nodeP_I_Trip* body = NULL;
     //printf("we got in \n");

     body = (nodeP_I_Trip*) malloc(sizeof(nodeP_I_Trip) + 10);            // THE CODE HANGS HERE
    
     if(body == NULL){
          printf("Yo we couldnt make the malloc !\n");
          return NULL;
     }
     //printf("we got here too\n");
     body->val_1 = yz->val_1;
     body->val_2 = yz->val_2;
     body->val_3 = x;
     //printf("maybe here too ?\n");
     for(int i = 0; i < 13 ; i++){ 
          //printf("%d is, yz is %lf, x is %lf\n",i, yz->results, x);
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

     //for(int i = 0; i < 169; i++){
     //     printf("%d is : %lf\n",i, body->results[i]);
     //}


     return body;
}


// 1   (ab)(cd)       pair done
void pairToTen(nodeP* ab, nodeP* cd){
     
     size_t a = sizeof(ab->results)/sizeof(ab->results[0]);
     size_t c = sizeof(cd->results)/sizeof(cd->results[0]);
     int ab_length = (int)(a);
     int cd_length = (int)(c);
     
     for(int i = 0; i < ab_length; i++){
          for(int j = 0; j < cd_length; j++){          
               //printf("ab cd : %lf %lf", ab->results[i], cd->results[j]);
               if(ab->results[i] + cd->results[j] == 10){printPair(ab,cd,i,j,0);}
               if(ab->results[i] - cd->results[j] == 10){printPair(ab,cd,i,j,1);}
               if(ab->results[i] * cd->results[j] == 10){printPair(ab,cd,i,j,2);}
               if(ab->results[i] / cd->results[j] == 10){printPair(ab,cd,i,j,3);}
               if(pow((ab->results[i]),(cd->results[j])) == 10){printPair(ab,cd,i,j,4);}
          }
     }
}
void printPair(nodeP* ab, nodeP* cd, int i, int j, int k){
    
     double a, b, c, d;
     char c1, c2, c3;
     a = ab->val_1;
     b = ab->val_2;
     c = cd->val_1;
     d = cd->val_2;
     c1 = '+';
     c2 = '+';
     c3 = '+';
     switch(i){
          case 0:
               c1 = '+';
               break;
          case 1:
               c1 = '-';
               break; 
          case 2:
               c1 = '*';
               break;
          case 3:
               c1 = '/';
               break; 
          case 4:
               c1 = '^';
               break;
          case 5:
               c1 = '^';
               b = -b;
               break; 
          case 6:
               c1 = '+';
               a = -a;
               break;
          case 7:
               c1 = '-';
               a = -a;
               break;     
          case 8:
               c1 = '*';
               a = -a;
               break;
          case 9:
               c1 = '/';
               a = -a;
               break; 
          case 10:
               c1 = '^';
               a = -a;
               break;
          case 11:
               c1 = '-';
               a = -a;
               b = -b;
               break; 
          case 12:     
               c1 = '^';
               a = -a;
               b = -b; 
               break;             
     }
     switch(j){
          case 0:
               c3 = '+';
               break;
          case 1:
               c3 = '-';
               break; 
          case 2:
               c3 = '*';
               break;
          case 3:
               c3 = '/';
               break; 
          case 4:
               c3 = '^';
               break;
          case 5:
               c3 = '^';
               c = -c;
               break; 
          case 6:
               c3 = '+';
               c = -c;
               break;
          case 7:
               c3 = '-';
               c = -c;
               break;     
          case 8:
               c3 = '*';
               c = -c;
               break;
          case 9:
               c3 = '/';
               c = -c;
               break; 
          case 10:
               c3 = '^';
               c = -c;
               break;
          case 11:
               c3 = '+';
               c = -c;
               d = -d;
               break; 
          case 12:     
               c3 = '^';
               c = -c;
               d = -d; 
               break;             
     }
     switch(k){
          case 0:
               c2 = '+';
               break;
          case 1:
               c2 = '-';
               break; 
          case 2:
               c2 = '*';
               break;
          case 3:
               c2 = '/';
               break; 
          case 4:
               c2 = '^';
               break;
                  
     }
    
     //printf("(%lf %c %lf) %c (%lf %c %lf)                %d %d %d\n",a,c1,b,c2,c,c3,d,i,j,k);
     printf("(%lf %c %lf) %c (%lf %c %lf)\n",a,c1,b,c2,c,c3,d);
     
}

// 2   a(b(cd))       pair
void twoTooTen(nodeI* a,  nodeI_P_Trip* bcd){
     size_t a1 = sizeof(a->results)/sizeof(a->results[0]);
     size_t c1 = sizeof(bcd->results)/sizeof(bcd->results[0]);
     int ab_length = (int)(a1);
     int cd_length = (int)(c1);
     
     for(int i = 0; i < ab_length; i++){
          for(int j = 0; j < cd_length; j++){          
               //printf("ab cd : %lf %lf", ab->results[i], cd->results[j]);
               if(a->results[i] + bcd->results[j] == 10){;}
               if(a->results[i] - bcd->results[j] == 10){;}
               if(a->results[i] * bcd->results[j] == 10){;}
               if(a->results[i] / bcd->results[j] == 10){;}
               if(pow((a->results[i]),(bcd->results[j])) == 10){;}
          }
     }
}















