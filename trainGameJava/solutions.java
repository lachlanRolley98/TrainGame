import java.util.ArrayList;

public class solutions {
    
    public ArrayList<String> strings; 

    public solutions(){
        this.strings = new ArrayList<>();
    }

    
    
    
    public void addpair(nodeP ab, nodeP cd, int i, int j, int k){
        double a, b, c, d;
        char c1, c2, c3;
        a = ab.val_1;
        b = ab.val_2;
        c = cd.val_1;
        d = cd.val_2;
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

        //printf("(%f %c %f) %c (%f %c %f)                %d %d %d\n",a,c1,b,c2,c,c3,d,i,j,k);
        String buffer = new String();
        buffer = String.format("(%f %c %f) %c (%f %c %f)\n",a,c1,b,c2,c,c3,d); 
        strings.add(buffer);
    }
    
    
    
    public void addString(String buffer){
        strings.add(buffer);
    }

    public void printAllStrings(){
        for(int i = 0; i<this.strings.size(); i++){
            System.out.println(strings.get(i));
        }
    }

    public void printOneAnswer(){
        if(strings.size() == 0){
            System.out.println("No Answers");
        }else{
            System.out.println(strings.get(0));
        }
    }

    public void numAnswers(){
        System.out.println(strings.size());
    }
}
