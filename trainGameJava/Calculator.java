

public class Calculator{

    public static void main(String[] args){

        nodeP a = new nodeP(1,2);

        nodeI_P_Trip b = new nodeI_P_Trip(3, a);

        for(int i = 0; i < 169; i++){

            System.out.println("yo");

            System.out.println(b.results[i] + " ");
            
            System.out.println("yo2");

            System.out.println(b.strings.get(i));

        }

        




    }
}