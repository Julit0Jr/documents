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
    final String TEMPERATURE = "32C";
    public String temps, converted;
    private double stemp;
    private char sunit;
    public int dot = 0;
    DerivedTemCon(){
        setStringTemp(TEMPERATURE);
    }
    DerivedTemCon(String tem){
        setStringTemp(tem);
    }
    public void setDoubleTemp(String tem){
        for(int i = 0; tem.charAt(i)!= '\0' ; i++){
            switch(tem.charAt(i)){
            case '.' :
                dot++;
                if(dot > 1)
                    throw new IllegalArgumentException("Invalid Temperature");
                break;
            case '0' :
                break;
            case '1' :
                break;
            case '2' :      
                break;
            case '3' :
                break;
            case '4' :
                break;
            case '5' :
                break;
            case '6' :
                break;
            case '7' :
                break;
            case '8' :
                break;
            case '9' :
                break;
            default :
                throw new IllegalArgumentException("Invalid Temperature");
            }
        }
    }
    public final void setStringTemp(String tem){
        int len = tem.length();
        sunit = tem.charAt(len-1);
        tem = tem.substring(0, len-1);
        //System.out.println("double: "+ stemp);
        //System.out.println("len: "+len);
        try{
            setDoubleTemp(tem);
            setUnit(sunit);
        }
        catch(Exception m){
            System.out.println(m.getMessage());
            //setStringTemp(TEMPERATURE);
        }
        stemp = Double.parseDouble(tem);
        this.dot = 0;
    }
    //Methods
    public String toCel(String tem){
        setStringTemp(tem);
        if(this.unit == 'F'){
            setTemp(FtoC(this.temp));
        }
        else if(this.unit == 'K')
            setTemp(KtoC(this.temp));
        
        setUnit('C');
        converted = Double.toString(temp);
        return converted + sunit;
    }
    public String toFar(String tem){
        setStringTemp(tem);
        if(this.unit == 'C'){
            setTemp(CtoF(this.temp));
        }
        else if(this.unit == 'K')
            setTemp(KtoF(this.temp));
        
        setUnit('F');
        converted = Double.toString(temp);
        return converted + sunit;
    }
    public String toKal(String tem){
        setStringTemp(tem);
        if(this.unit == 'C'){
            setTemp(CtoK(this.temp));
        }
        else if(this.unit == 'F')
            setTemp(FtoK(this.temp));
        
        setUnit('K');
        converted = Double.toString(temp);
        return converted + sunit;
    }
    public String getSTemp(){
        return Double.toString(temp);
    } 
}