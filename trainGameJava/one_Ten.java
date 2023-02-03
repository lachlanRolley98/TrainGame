
public class one_Ten {
    
    public one_Ten(nodeP ab, nodeP cd, solutions s){
        for(int i = 0; i < 13; i++){
            for(int j = 0; j < 13; j++){          
                 //printf("ab cd : %lf %lf", ab.results[i], cd.results[j]);
                 if(ab.results[i] + cd.results[j] == 10){s.addpair(ab,cd,i,j,0);}
                 if(ab.results[i] - cd.results[j] == 10){s.addpair(ab,cd,i,j,1);}
                 if(ab.results[i] * cd.results[j] == 10){s.addpair(ab,cd,i,j,2);}
                 if(ab.results[i] / cd.results[j] == 10){s.addpair(ab,cd,i,j,3);}
                 if(Math.pow((ab.results[i]),(cd.results[j])) == 10){s.addpair(ab,cd,i,j,4);}
            }
       }
    }


}
