public class nodeP {
    
    public double val_1;
    public double val_2;
    public double results[];
    

    public nodeP(double x, double y){
        
        this.results = new double[13];
        
        this.val_1 = x;
        this.val_2 = y;
        this.results[0] = x + y;
        this.results[1] = x - y;
        this.results[2] = x * y;
        this.results[3] = x / y;
        this.results[4] = Math.pow(x,y);         //x ^ y;
        this.results[5] = Math.pow(x,(-y));      //x ^ (-y)
        this.results[6] = -x + y;
        this.results[7] = -x - y;
        this.results[8] = -x * y ;
        this.results[9] = -x / y ;
        this.results[10] = Math.pow((-x),y);     //-x ^ y
        this.results[11] = -x + (-y);
        this.results[12] = Math.pow((-x),(-y));  //-x ^ (-y);
    }
    
}
