

public class Calculator{

    public static void main(String[] args){

        nodeP a = new nodeP(1,2);

        nodeI_P_Trip b = new nodeI_P_Trip(3, a);
        nodeP_I_Trip c = new nodeP_I_Trip(a, 3);

        for(int i = 0; i < 169; i++){
            System.out.println(c.results[i] + " ");
            System.out.println(c.strings.get(i));
        }

        
        




    }
}