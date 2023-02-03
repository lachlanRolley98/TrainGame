public class two_Ten {
    

    public two_Ten(nodeI a,  nodeI_P_Trip bcd, solutions s){

        String buffer = new String(); 
            
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 169; j++){          
                
                if(a.results[i] + bcd.results[j] == 10){
                        buffer = String.format("%f + %s\n", a.results[i], bcd.strings.get(j));
                        s.addString(buffer);
                }
            
                if(a.results[i] - bcd.results[j] == 10){
                        buffer = String.format("%f - %s\n", a.results[i], bcd.strings.get(j));
                        s.addString(buffer);     
                }
                if(a.results[i] * bcd.results[j] == 10){
                        buffer = String.format("%f * %s\n", a.results[i], bcd.strings.get(j));
                        s.addString(buffer);
                }
                if(a.results[i] / bcd.results[j] == 10){
                        buffer = String.format("%f / %s\n", a.results[i], bcd.strings.get(j));
                        s.addString(buffer);
                }
                if(Math.pow((a.results[i]),(bcd.results[j])) == 10){
                        buffer = String.format("%f ^ %s\n", a.results[i], bcd.strings.get(j));
                        s.addString(buffer);
                }
            }
        }

    }

}
