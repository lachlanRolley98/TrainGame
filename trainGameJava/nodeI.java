public class nodeI {
    
    public double val_1;
    public double results[];

    public nodeI(double x){
        
        this.val_1 = x;
        
        this.results = new double[2];
        
        this.results[0] = x;
        this.results[1] = -x;
    }

}
