/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hexadecimalproject;

/**
 *
 * @author Asus-PC
 */
public class Hexadecimal{
    public String hexNum;
    
    Hexadecimal(){
        this.hexNum = "0";
    }
    Hexadecimal(String hex){
        hex = checkerHexadecimal(hex);
        this.hexNum = hex;
    }
    Hexadecimal(long dec){
        long rem;
        long times = 1;
        String con = "", ans;
        String hex[]= {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
        
        while(dec != 0){
            rem = dec % 16;
            dec = dec / 16;
            ans = hex[(int)rem];
            con = ans + con;
        }
        this.hexNum = con;
    }
    public void setHexadecimal(String hex){
        this.hexNum = hex;
    }
    public String getHexadecimal(){
        return this.hexNum;
    }
    //Methods
    public long HextoDecimal(String hex){
        int len = hex.length(), exp, ctr = 0;
        long ans = 0, add = 1, val;
        hex = checkerHexadecimal(hex);
        if(hex == "0")
            return 0;
        for(int i = len-1; i >= 0; i--, ctr++){
            exp = ctr;
            if(hex.charAt(i) == '0')
                add = 0;
            else{
                while(exp != 0){
                    add = add * 16;
                    exp--;
                }
            }
            if(hex.charAt(i) >= 'A' && hex.charAt(i) <= 'F'){
                val = hex.charAt(i) - 'A' + 10;
            }
            else if(hex.charAt(i) >= 'a' && hex.charAt(i) <= 'f'){
                val = hex.charAt(i) - 'a' + 10;
            }
            else 
                val = hex.charAt(i) - '0';
            add = val* add;
            ans = ans + add;
            add = 1;
        }
        return ans;
    }
    public String DecimaltoHex(long dec){
        long rem;
        long times = 1;
        String con = "", ans;
        String hex[]= {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
        
        while(dec != 0){
            rem = dec % 16;
            dec = dec / 16;
            ans = hex[(int)rem];
            con = ans + con;
        }
        return con;
    }
    //public String getHexadecimal(){
    //    return this.hexNum;
    //}
    public long getDecimalEquivalent(){
        return HextoDecimal(this.hexNum);
    }
    public String checkerHexadecimal(String hex){
        int len = hex.length(), f=0;
        if(len-1 > 16){
            System.out.println("HAHAHHA! Out of Range! Set to the default value!");
            return "0";
        }
        
        for(int i = 0; i<=hex.length()-1; i++){
            if((hex.charAt(i) < 'a' || hex.charAt(i) > 'f') && (hex.charAt(i) < 'A' || hex.charAt(i) > 'F') && (hex.charAt(i) < '0' || hex.charAt(i) > '9')){
                System.out.println("invalid Input! Set to the default value!");
                return "0";
            }
            if(hex.charAt(i) < 'F'){
                f++;
            }
            if(f > 15){
                System.out.println(f);
                System.out.println("Out of Range! Set to the default value!");
                return "0";
            }
        }
        return hex;
    }
    public String addAsHex(String hex1, String hex2){
        return DecimaltoHex(HextoDecimal(checkerHexadecimal(hex1)) + HextoDecimal(checkerHexadecimal(hex2)));
    }
    public long addAsDec(String hex1, String hex2){
        return HextoDecimal(checkerHexadecimal(hex1)) + HextoDecimal(checkerHexadecimal(hex2));
    }
    public String toString(){
        return this.hexNum;
    }
    public static void main(String[] args) {
        long dec = 99;
        Hexadecimal hex = new Hexadecimal("xyz");
        System.out.println(hex );
        Hexadecimal hx = new Hexadecimal("ABCD10");
        Hexadecimal h = new Hexadecimal(dec);
        System.out.println("[3] "+h.DecimaltoHex(dec));
        System.out.println("[4] "+hx.HextoDecimal(hx.hexNum));
        System.out.println("[5] "+hex.HextoDecimal("FFFFFFFFFFFFFFFF"));
        System.out.println("[6] "+hex.HextoDecimal("AA"));
        System.out.println("[7] "+hex.DecimaltoHex(16l));
        System.out.println("[8] "+hex.addAsDec("bA","aB"));
        System.out.println("[9] "+hex.addAsHex("6f","7BC"));
    }
    
}
