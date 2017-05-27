/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab05;

/**
 *
 * @author Asus-PC
 */

class X {
    public static final int CONSTANT_INT = 30;  //for part 3
    int x;
    
    public void Method(int i, int j){
        //for part 2
        System.out.println("Super Class");
    }
}
class Y extends X implements Z{
    int y;
    public void Method (int i){
        System.out.println("Sub Class");
    }
    
}
public class Test5{
    public static void main(String[] args){
        X[] xa = null;
        Y[] ya = null;

        //Part 1 - assignments and casting (Coding)
        //(a)assign xa to ya, and vise versa

        //ya = xa;      // Compile-time error it wont work as expected since xa belongs to a higher class.
         ya = (Y[])xa; 	// Casting is applied, so xa can succesfully be assigned to ya.

        /*
        Casting is applied when ?
        */

        //(b)if ya references an array of Y's, can we assign it to xa? Can we then assign it back to ya?

        xa = ya; 	// This would work since xa belongs to a higher class.
        //ya = xa; 	// Compile-time error, it wont work as expected since xa belongs to a higher class.
        ya = (Y[])xa;	// Casting is applied, so xa can succesfully be assigned to ya.

        //(c)

        //ya = xa;	// Compile-time error since xa belongs to a higher class. it would work by casting. 

        /*
            1st point : Of course, we wont have a chance to assign ya back to xa since at the first place, we cant assign xa to ya (ya = xa).
            2nd point : If we happen assign xa to ya successfully through casting, we then can assign it back from ya to xa.
        */

        //Part 2 - Conflicting Declarations (Not Coding)

        //Answers:
        /*
            (a)	Yes, it would compile since Java interface cannot implement any methods, nor can it   include any fields except "final static" constants. It only contains method 
                prototypes and constants.
            (b) It would not compile unless you change one the return types to make them the same.
            (c) It will generate an error specifically, compile-time error.
            (d) It would work no matter what names of their variable is as long as their number of parameter(s), parameter type, method name, method prototype and return type as the same.
        */
        //Part 3 - More Conflicting Declarations (Coding)

            //Answers: 
            /*
                    (a)	Its okay, it won't print or say any error(run-time or compile-time).
                    (b) Coding
                    (c) Coding
            */
        //Part 4 - Method Overriding (Coding)    
        Y ay = new Y();
            // ((X)ay).Method(10);  //(a)calls sub class
        X ax = new X();
            //   ((Y)ax).Method(10);//(b)Run-time error because ax is not Y
        Y xx = new Y();
            xx.Method(1,4);         //(c)calls super class
            xx.Method(1);           //calls subclass

            //(a)
            //(b)It would yield a run-time error though it wont yield compile-time error though. The computer would trust that ax is an object and type of x, but it was casted to its subclass which is, obviously, not possible. 
            //(c)During overriding and calling of methods, java would look for the closest there is in the object that called it. During calling, java considers the type and number of (prototype)parameters there is in the method. In this situation, the super class' was called because it calls a method that has that parameter.

    }
}
