public class five_Ten {
    
    public five_Ten(nodeP_I_Trip abc, nodeI d, solutions s){
        
        String buffer = new String(); 
        for(int i = 0; i < 169; i++){
            for(int j = 0; j < 2; j++){          
                 
                if(abc.results[i] + d.results[j] == 10){
                   buffer = String.format("%s + %d\n", abc.strings.get(i), (int)d.results[j]);
                   s.addString(buffer); 
                }
        
                if(abc.results[i] - d.results[j] == 10){
                   buffer = String.format("%s - %d\n", abc.strings.get(i), (int)d.results[j]);
                   s.addString(buffer);      
                }
                if(abc.results[i] * d.results[j] == 10){
                   buffer = String.format("%s * %d\n", abc.strings.get(i), (int)d.results[j]);
                   s.addString(buffer); 
                }
                if(abc.results[i] / d.results[j] == 10){
                   buffer = String.format("%s / %d\n", abc.strings.get(i), (int)d.results[j]);
                   s.addString(buffer); 
                }
                if(Math.pow((abc.results[i]),(d.results[j])) == 10){
                   buffer = String.format("%s ^ %d\n", abc.strings.get(i), (int)d.results[j]);
                   s.addString(buffer); 
                }
            }
       }
    }
}
