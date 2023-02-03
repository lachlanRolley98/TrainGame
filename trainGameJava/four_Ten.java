public class four_Ten {
    
    
    
    
    public four_Ten(nodeI_P_Trip abc, nodeI d, solutions s){
        
        String buffer = new String(); 

        for(int i = 0; i < 169; i++){
            for(int j = 0; j < 2; j++){          
                 
                if(abc.results[i] + d.results[j] == 10){
                    buffer = String.format("%s + %f\n", abc.strings.get(i), d.results[j]);
                    s.addString(buffer);
                }
        
                if(abc.results[i] - d.results[j] == 10){
                    buffer = String.format("%s - %f\n", abc.strings.get(i), d.results[j]);
                    s.addString(buffer);     
                }
                if(abc.results[i] * d.results[j] == 10){
                    buffer = String.format("%s * %f\n", abc.strings.get(i), d.results[j]);
                    s.addString(buffer);
                }
                if(abc.results[i] / d.results[j] == 10){
                    buffer = String.format("%s / %f\n", abc.strings.get(i), d.results[j]);
                    s.addString(buffer);
                }
                if(Math.pow((abc.results[i]),(d.results[j])) == 10){
                    buffer = String.format("%s ^ %f\n", abc.strings.get(i), d.results[j]);
                    s.addString(buffer);
                }
            }
       }


    }    
}
