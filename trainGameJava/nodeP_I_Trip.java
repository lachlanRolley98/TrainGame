import java.util.ArrayList;
import java.util.List;

public class nodeP_I_Trip {
    
    public double val_1;
    public double val_2;
    public double val_3;
    public double results[];
    public List<String> strings; 


    public nodeP_I_Trip(nodeP yz, double x){
        this.val_1 = x;
        this.val_2 = yz.val_1;
        this.val_3 = yz.val_2;
        this.results = new double[169];
        this.strings = new ArrayList<>();

        

        //printf("maybe here too ?\n");
     for(int i = 0; i < 13 ; i++){ 
          
        double a, b;
        a = yz.val_1;
        b = yz.val_2;
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
            default:
            c1 = 'f';                 
        }
        
        String buffer = new String();
        
        this.results[0 + (13*i)] = yz.results[i] + x;
        buffer = String.format("((%f %c %f) + %f)",a, c1, b, x );    
        this.strings.add(0 + (13*i), buffer);

        this.results[1 + (13*i)] = yz.results[i] - x;
        buffer = String.format("((%f %c %f) - %f)",a, c1, b, x );    
        this.strings.add(1 + (13*i), buffer);

        this.results[2 + (13*i)] = yz.results[i] * x;
        buffer = String.format("((%f %c %f) * %f)",a, c1, b, x );    
        this.strings.add(2 +(13*i), buffer);


        this.results[3 + (13*i)] = yz.results[i] / x;
        buffer = String.format("((%f %c %f) / %f)",a, c1, b, x );    
        this.strings.add(3 + (13*i), buffer);

        this.results[4 + (13*i)] = Math.pow(yz.results[i],x);         //x ^ y;
        buffer = String.format("((%f %c %f) ^ %f)",a, c1, b, x );    
        this.strings.add(4 + (13*i), buffer);

        this.results[5 + (13*i)] = Math.pow(yz.results[i],(-x));      //x ^ (-y)
        buffer = String.format("((%f %c %f) ^ (-%f))",a, c1, b, x );    
        this.strings.add(5 + (13*i), buffer);

        this.results[6 + (13*i)] = -yz.results[i] + x;
        buffer = String.format("(-(%f %c %f) + %f)",a, c1, b, x );    
        this.strings.add(6 + (13*i), buffer);

        this.results[7 + (13*i)] = -yz.results[i] - x;
        buffer = String.format("(-(%f %c %f) - %f)",a, c1, b, x );    
        this.strings.add(7 + (13*i), buffer);

        this.results[8 + (13*i)] = -yz.results[i] * x ;
        buffer = String.format("(-(%f %c %f) * %f)",a, c1, b, x );    
        this.strings.add(8 + (13*i), buffer);

        this.results[9 + (13*i)] = -yz.results[i] / x ;
        buffer = String.format("(-(%f %c %f) / %f)",a, c1, b, x );    
        this.strings.add(9 + (13*i), buffer);

        this.results[10 + (13*i)] = Math.pow((-yz.results[i]),x);     //-x ^ y
        buffer = String.format("(-(%f %c %f) ^ %f)",a, c1, b, x );    
        this.strings.add(10 + (13*i), buffer);

        this.results[11 + (13*i)] = -yz.results[i] + (-x);
        buffer = String.format("(-(%f %c %f) + (-%f))",a, c1, b, x );    
        this.strings.add(11 + (13*i), buffer);

        this.results[12 + (13*i)] = Math.pow((-yz.results[i]),(-x));  //-x ^ (-y);
        buffer = String.format("(-(%f %c %f) ^ (-%f))",a, c1, b, x );    
        this.strings.add(12 + (13*i), buffer);
        
        }
    }
}
