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
public class Tester22{
    public static void main(String[] args) {
            String convert;
            //TemperatureConversions t = new TemperatureConversions();
            //t.setTemperature(32, 'c');
            //t.ConvertToF();
            //System.out.println(t.toString());
            //t.ConvertToK();
            //System.out.println(t.toString());
            //t.ConvertToC();
            //System.out.println(t.toString());
            DerivedTemCon st1 = new DerivedTemCon("35g");
            //System.out.println("Converted Temperature: " + st.toFar("-20j"));
            DerivedTemCon st2 = new DerivedTemCon("85C");
            DerivedTemCon st = new DerivedTemCon();
            System.out.println("Converted Temperature: " + st.toKel("45f"));
            System.out.println("Converted Temperature: " + st.toCel("45f"));
            System.out.println("Converted Temperature: " + st.toCel("300k"));
            System.out.println("Converted Temperature: " + st.toFar("300k"));
            System.out.println("Temperature: " + st.toCel("20z"));
            System.out.println("Temperature: " + st.toFar("20z"));
            System.out.println("Temperature: " + st.toKel("20z"));
        } 
}
