
public class BinaryClass{
    private String bin;
    private char sign;
    
    public BinaryClass(){
       setBin("0");
       setSign('+');
    }
    
    public BinaryClass(String bin){
        try{
            if(isValid(bin)){
                if(bin.charAt(0) == '0' || bin.charAt(0) == '1' || bin.charAt(0) == '+'){
                    setSign('+');
                } else {
                     setSign('-');
                }
                setBin(bin.substring(1,bin.length()));  
            } 
        } catch(IllegalArgumentException e){
            setBin("0");
            setSign('+');
            System.err.println(e);
        }
        
    }
    
    public BinaryClass(long bin) {
      try{
         if(isInRange(bin)){
             setBin(DecimalToBinary(bin));
         } 
      } catch(IllegalArgumentException e){
          setBin("0");
          setSign('+');
          System.err.println(e);
      }
        
    }
    
    public void setBin(String bin){
        this.bin = bin;
    }
    
    public void setSign(char sign){
        this.sign = sign;
    }
    
    public String getBin(){
        return bin;
    }
    
    public char getSign(){
        return sign;
    }
    
    public String DecimalToBinary(Long bin) throws IllegalArgumentException{
      String sign = "";
      String binString = "";
      int x = 0;
        try{
             if(isInRange(bin)){ 
                if(bin < 0)
                   sign = "-";
                   bin = Math.abs(bin);
                }

                while(bin != 0){
                  binString = String.valueOf(bin % 2) + binString;
                  bin = bin / 2;
                  x++;
                }

                binString = sign + binString;
                return binString;
                   
             } 
        } catch(IllegalArgumentException e){
            System.err.println(e);
        }
        return "0";
    }
    
    public long BinaryToDecimal(String bin){
      int i = bin.length() - 1;
      long result = 0;
      long num = 1;
      boolean isPos = true;
        try{
          if(isValid(bin)){
            while(i >= 0){
              if(i == 0 && bin.charAt(i) == '-'){
                  isPos = false;
              } else {
                  if(bin.charAt(i) == '1'){
                      result += num;
                  }
                  
                  num = num * 2;
              }
              i--;
            }
            
            if(!isPos){
                result = result * -1;
            }
            return result;   
          }
        } catch(IllegalArgumentException e){
            System.err.println(e);
            throw new IllegalArgumentException("Error: Invalid Entry");
        }
        return -1;
    }
    
    public long getDecimalEquivalent(){
        return BinaryToDecimal(getSign() + getBin());
    }
    
    public boolean isValid(String temp) throws IllegalArgumentException{
        char curr;
        
        for(int i = 0; i < temp.length(); i++){
            curr = temp.charAt(i);
            if(i == 0){
                if(curr != '0' && curr != '1' && curr != '-' && curr != '+'){
                    throw new IllegalArgumentException("Error: Invalid Characters On the Input: " + temp);
                }
            } else {
                if(curr != '0' && curr != '1'){
                   throw new IllegalArgumentException("Error: Invalid Characters On the Input: " + temp); 
                }
            }
        }
        
        return true;
    }
    
    public boolean isInRange(long temp) throws IllegalArgumentException {
        if(temp >= (long) Math.pow(-2,63) && temp <= (long)Math.pow(2,62)){
            return true;
        } else {
            throw new IllegalArgumentException ("Error: Entry is Out Range: " + Long.toString(temp));
        }
    }
    
    public String toString(){
        return getSign() + getBin();
    }
}


