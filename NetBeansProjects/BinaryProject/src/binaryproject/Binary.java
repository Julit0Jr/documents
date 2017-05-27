/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package binaryproject;

/**
 *
 * @author Asus-PC
 */
public class Binary {
    public String binNum;
    public char sign = '+';
    
    Binary(){
        this.binNum = "0";
    }
    Binary(String bin){
        bin = checkerBinary(bin);
        this.binNum = bin;
    }
    Binary(long dec){
        long rem, ans = 0;
        long times = 1;
        
        while(dec != 0){
            rem = dec % 2;
            dec = dec / 2;
            ans = ans + (times * rem);
            times = times * 10;
        }
        this.binNum = Long.toString(ans);
    }
    public void setBinary(String bin){
        this.binNum = bin;
    }
    public void setSign(char s){
        this.sign = s;
    }
    public char getSign(){
        return this.sign;
    }
    public String getBinary(){
        if(this.sign == '-')
            return "-"+this.binNum;
        return this.binNum;
    }
    //Methods
    public long BintoDecimal(String bin){
        int len = bin.length(), exp, ctr = 0;
        long ans = 0, add = 1;
        bin = checkerBinary(bin);
        
        for(int i = len-1; i >= 0; i--, ctr++){
            exp = ctr;
            if(bin.charAt(i) == '0')
                add = 0;
            else{
                while(exp != 0){
                    add = add * 2;
                    exp--;
                }
            }
            ans = ans + add;
            add = 1;
        }
        if(this.sign == '-')
            return ans*-1;
        return ans;
    }
    public String DecimaltoBin(long dec){
        long rem, ans = 0;
        long times = 1;
        
        while(dec != 0){
            rem = dec % 2;
            dec = dec / 2;
            ans = ans + (times * rem);
            times = times * 10;
        }
        return Long.toString(ans);
    }
    public long getDecimalEquivalent(){
        return BintoDecimal(this.binNum);
    }
    public String checkerBinary(String bin){
        int len = bin.length();
        if(len > 65){
            System.out.println("Out of Range! Set to the default value!");
            return "0";
        }
        if(bin.charAt(0) == '-' || bin.charAt(0) == '+'){
            this.sign = bin.charAt(0);
            bin = bin.substring(1, len);
        }
        for(int i = 0; i<=bin.length()-1; i++){
            if(bin.charAt(i) != '0' && bin.charAt(i) != '1' && bin.charAt(0) == '-' && bin.charAt(0) == '+'){
                System.out.println("invalid Input! Set to the default value!");
                return "0";
            }
        }
        return bin;
    }
    public String addAsBin(String bin1, String bin2){
        return DecimaltoBin(BintoDecimal(checkerBinary(bin1)) + BintoDecimal(checkerBinary(bin2)));
    }
    public long addAsDec(String bin1, String bin2){
        return BintoDecimal(checkerBinary(bin1)) + BintoDecimal(checkerBinary(bin2));
    }
    public static void main(String[] args) {
        long dec = 99;
        Binary bin = new Binary();
        Binary bin1 = new Binary("xyz");
        Binary bin2 = new Binary("-10101");
        Binary bin3 = new Binary(dec);
        Binary bin4 = new Binary("+101");
        Binary bin5 = new Binary("1010");
        System.out.println("[6] "+ bin2.getBinary());
        System.out.println("[7] "+ bin5.getBinary());
        System.out.println("[8] "+ bin.BintoDecimal("11111111111111111111111111111111111111111111111111111111111111111"));
        System.out.println("[9] "+ bin.BintoDecimal("11011"));
        System.out.println("[10.1] "+ bin.DecimaltoBin(16));
        System.out.println("[10.2] "+ bin.DecimaltoBin(-16)); 
        System.out.println("[11.1] "+ bin.addAsBin("11011", "-100001")); //27+(-33)
        
        
        /*System.out.println(bin.binNum);
        System.out.println(bin.BintoDecimal("11101010101010101110101"));
        System.out.println(bin.addAsBin("111","111"));
        System.out.println(bin.addAsDec("111","111"));*/
    }
}
