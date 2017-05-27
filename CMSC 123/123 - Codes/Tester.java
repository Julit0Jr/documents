public class Tester{
    public static void main(String[] args){
      //  System.out.println("hello");
       /* long result = BinaryAdd.addAsDec("1","1");
        System.out.println(result);*/
        BinaryClass b = new BinaryClass();
       // System.out.println(b.isValid("1"));
        System.out.println(b.DecimalToBinary((long)(-1234565678676767)));
       // System.out.println(b.BinaryToDecimal("1000"));
        System.out.println(BinaryAdd.addAsDec("11111111111111111111111111111111111111111111111111111111111111111111111111111111111111", "1000000000"));
        System.out.println(BinaryAdd.addAsBinary("100","100"));
        BinaryClass bc = new BinaryClass();
        BinaryClass bc2 = new BinaryClass("100");
        BinaryClass bc3 = new BinaryClass(8);
        
        //System.out.println(bc);
        //System.out.println(bc2);
        //System.out.println(bc3);
    }
}