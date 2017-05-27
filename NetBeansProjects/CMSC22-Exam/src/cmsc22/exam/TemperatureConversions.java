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

public class TemperatureConversions{
    final double DEFAULT_TEMP = 30.0;
    final char DEFAULT_UNIT = 'C';
    final double FIVE_OVER_NINE = 5.0/9;
    final double NINE_OVER_FIVE = 9.0/5;
    final double KELVIN_NUM = 273.15;
    final double THIRTY_TWO = 32.0;
    public double temp;
    public char unit;
    
    //Constructors 
    TemperatureConversions(){
        setTemperature(DEFAULT_TEMP, DEFAULT_UNIT);
    } 
    TemperatureConversions(double temp, char unit){
        setTemperature(temp, unit);
    }
    public void setTemp(double temp) {
        this.temp = temp;
    }
    public void setUnit(char unit)throws IllegalArgumentException{
        switch(unit){
            case 'k' :
                this.unit = 'K';
                break;
            case 'c' :
                this.unit = 'C';
                break;
            case 'f' :
                this.unit = 'F';
                break;
            case 'K' :
                this.unit = 'K';
                break;
            case 'C' :
                this.unit = 'C';
                break;
            case 'F' :
                this.unit = 'F';
                break;
            default :
                throw new IllegalArgumentException("Invalid Temperature");
        }
    }
    public void setTemperature(double temp, char unit){
        try{
            setTemp(temp);
            setUnit(unit);
        }
        catch(Exception m){
            System.out.println(m.getMessage());
            setTemp(DEFAULT_TEMP);
            setUnit(DEFAULT_UNIT);
            System.out.println("The default temperature: "+ getTemp() + " " + getUnit());
        }
    }
    public double CtoF(double temp){
        return (NINE_OVER_FIVE * temp) + THIRTY_TWO;
    }
    public double CtoK(double temp){
        return temp + KELVIN_NUM;
    }
    public double FtoC(double temp){
        return FIVE_OVER_NINE * (temp - THIRTY_TWO);
    }
    public double FtoK(double temp){
        return CtoK(FtoC(temp));
    }
    public double KtoC(double temp){
        return temp - KELVIN_NUM;
    }
    public double KtoF(double temp){
        return CtoF(KtoC(temp));
    }
    //Mutators
    public void ConvertToC(){
        if(this.unit == 'F'){
            setTemp(FtoC(this.temp));
        }
        else if(this.unit == 'K')
            setTemp(KtoC(this.temp));
        setUnit('C');
    }
    public void ConvertToF(){
        if(this.unit == 'C'){
            setTemp(CtoF(this.temp));
        }
        else if(this.unit == 'K')
            setTemp(KtoF(this.temp));
        setUnit('F');
    }
    public void ConvertToK(){
        if(this.unit == 'C'){
            setTemp(CtoK(this.temp));
        }
        else if(this.unit == 'F')
            setTemp(FtoK(this.temp));
        setUnit('K');
    }
    public double getTemp(){
        return this.temp;
    }
    public char getUnit(){
        return this.unit;
    }
    public String toString(){
        return "Converted Temperature: " + getTemp() + " " + getUnit();
    }
}