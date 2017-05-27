public class BinaryAdd extends BinaryClass{
    public static String addAsBinary(String bin1, String bin2){
       // BinaryClass bc = new BinaryClass();
        String result = "";
        long temp;
        try {
            if(isValid(bin1) && isValid(bin2)){
                temp = BinaryToDecimal(bin1) + BinaryToDecimal(bin2);

                if(isInRange(temp)){
                   result =  result + DecimalToBinary(temp);
                   return result;   
                }    
            }
        } catch(IllegalArgumentException e){
            System.err.println(e);
        }
        return "0";
    }
    
    public static long addAsDec(String bin1, String bin2) throws IllegalArgumentException{
        //BinaryClass bc = new BinaryClass();
        long result;
        try {
          if(isValid(bin1) && isValid(bin2)){
            if(isInRange(BinaryToDecimal(bin1)) && isInRange(BinaryToDecimal(bin2))){
               result = BinaryToDecimal(bin1) + BinaryToDecimal(bin2);
            }
            System.out.println(BinaryToDecimal(bin1));
            System.out.println(BinaryToDecimal(bin2));
            if(isInRange(result)){
               return result; 
            }
            } 
        
        } catch(IllegalArgumentException e){
            System.err.println(e);
        }
        return 0;
        
    }
    
    
}


