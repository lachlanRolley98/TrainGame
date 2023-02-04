

public class Calculator{

    public static void main(String[] args){


        solutions sols = new solutions();
        double a ,b ,c ,d ;
        a = 9;
        b = 9;
        c = 3;
        d = 4;

        //create all individual combos
        nodeI I_a = new nodeI(a);
        nodeI I_b = new nodeI(b);
        nodeI I_c = new nodeI(c);
        nodeI I_d = new nodeI(d);    
        //create all the pair combos
        nodeP P_ab = new nodeP(a,b);
        nodeP P_bc = new nodeP(b,c);
        nodeP P_cd = new nodeP(c,d);     
        
        //create tripple from Individual then pair
        nodeI_P_Trip T_a_bc = new nodeI_P_Trip(a,P_bc);
        nodeI_P_Trip T_b_cd = new nodeI_P_Trip(b,P_cd);    
        //create tripple from pair then individual
        nodeP_I_Trip T_ab_c = new nodeP_I_Trip(P_ab, c);                        
        nodeP_I_Trip T_bc_d = new nodeP_I_Trip(P_bc, d); 

/*
        1-5 can go into pairToTen, the number is added to tell print function what format

        1   (ab)(cd)       pair done
        2   a(b(cd))       pair done
        3   a((bc)d)       pair
        4   (a(bc))d       pair
        5   ((ab)c)d       pair
*/

        one_Ten i = new one_Ten(P_ab, P_cd, sols);
        two_Ten j = new two_Ten(I_a,T_b_cd,sols);
        three_Ten k = new three_Ten(I_a, T_bc_d, sols);
        four_Ten l = new four_Ten(T_a_bc, I_d, sols);
        five_Ten m = new five_Ten(T_ab_c, I_d, sols);

        //sols.printAllStrings();
        //sols.numAnswers();
        sols.printOneAnswer();           
    }

    
}