/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package cmsc22.exam;

/**
 *
 * @author Asus-PC
 */
class DerivedTemCon extends TemperatureConversions implements TemperartureConverter{
    final String DEF_TEMPERATURE = "32C";
    
    DerivedTemCon(){
        SetStringTemp(DEF_TEMPERATURE);
    }
    DerivedTemCon(String temp){
        SetStringTemp(temp);
    }
    public String checkString(String tempval){
        int dot = 0;
        String checker = tempval.substring(0, tempval.length()-1);
        
        for(int i= 0; i < checker.length(); i++){
            if(checker.charAt(i) == '.')
                dot++;
            else if(checker.charAt(i) < '0' || checker.charAt(i) > '9' || dot > 1)
                return DEF_TEMPERATURE;
        }
        return tempval;
    }
    public String checkTemp(String tempt){
        int dot = 0;
        char uchecker = tempt.charAt(tempt.length()-1);
        String checker = tempt.substring(0, tempt.length());
        
        try{
            if(uchecker != 'K' && uchecker != 'k' && uchecker != 'F' && uchecker != 'f' && uchecker != 'C' && uchecker != 'c' ){
              throw new IllegalArgumentException("Invalid Temperature!");
            }
            for(int i= 0; i < checker.length(); i++){
                if(checker.charAt(i) == '.')
                    dot++;
                else if(checker.charAt(i) != '-' && checker.charAt(i) < '0' || checker.charAt(i) > '9' && dot > 1){
                    throw new IllegalArgumentException("Invalid Temperature!");
                }
            }
        }
        catch(Exception e){
            return checker;
        }
        return checker;
    }
    public void SetStringTemp(String temp){
      char c = temp.charAt(temp.length()-1);
      temp = checkString(temp.substring(0, temp.length()));
      double d = Double.parseDouble(temp.substring(0, temp.length()-1));
      
       try{
            setTemp(d);
            setUnit(c);
        }
        catch(Exception m){
            System.out.println(m.getMessage());
            setTemp(Double.parseDouble(DEF_TEMPERATURE.substring(0, DEF_TEMPERATURE.length()-1)));
            setUnit(DEF_TEMPERATURE.charAt(DEF_TEMPERATURE.length()-1));
            System.out.println("The default temperature: "+ getTemp() + " " + getUnit());
        }
    }
    public String toCel(String temp){
        double str = 0.0;
        temp = checkTemp(temp);
        if(temp.charAt(temp.length()-1)!='f' && temp.charAt(temp.length()-1)!='F' && temp.charAt(temp.length()-1)!='K' && temp.charAt(temp.length()-1)!='k'){
            System.out.println("Oops! Invalid.");
            return temp;
        }
        if(temp.charAt(temp.length()-1)=='f' || temp.charAt(temp.length()-1) == 'F'){
            str = FtoC(Double.parseDouble(temp.substring(0, temp.length()-1)));
        }
        else if(temp.charAt(temp.length()-1)=='k' || temp.charAt(temp.length()-1) == 'K')
            str = KtoC(Double.parseDouble(temp.substring(0, temp.length()-1)));
        else 
            str = (Double.parseDouble(temp.substring(0, temp.length()-1)));
        
        return Double.toString(str) +" "+ 'C';
    }
    public String toFar(String temp){
        double str = 0.0;
        temp = checkTemp(temp);
        if(temp.charAt(temp.length()-1)!='c' && temp.charAt(temp.length()-1)!='C' && temp.charAt(temp.length()-1)!='k' && temp.charAt(temp.length()-1)!='K'){
            System.out.println("Oops! Invalid.");
            return temp;
        }
        if(temp.charAt(temp.length()-1)=='c' || temp.charAt(temp.length()-1) == 'C'){
            str = CtoF(Double.parseDouble(temp.substring(0, temp.length()-1)));
        }
        else if(temp.charAt(temp.length()-1)=='k' || temp.charAt(temp.length()-1) == 'K')
            str = KtoF(Double.parseDouble(temp.substring(0, temp.length()-1)));
        else 
            str = (Double.parseDouble(temp.substring(0, temp.length()-1)));
        
        return Double.toString(str) +" "+ 'F';
    }
    public String toKel(String temp){
        double str = 0.0;
        temp = checkTemp(temp);
        if(temp.charAt(temp.length()-1)!='c' && temp.charAt(temp.length()-1)!='C' && temp.charAt(temp.length()-1)!='f' && temp.charAt(temp.length()-1)!='F'){
            System.out.println("Oops! Invalid.");
            return temp;
        }
        if(temp.charAt(temp.length()-1)=='c' || temp.charAt(temp.length()-1) == 'C'){
            str = CtoK(Double.parseDouble(temp.substring(0, temp.length()-1)));
        }
        else if(temp.charAt(temp.length()-1)=='f' || temp.charAt(temp.length()-1) == 'F')
            str = FtoK(Double.parseDouble(temp.substring(0, temp.length()-1)));
        else 
            str = (Double.parseDouble(temp.substring(0, temp.length()-1)));
        
        return Double.toString(str) +" "+ 'K';
    }
}