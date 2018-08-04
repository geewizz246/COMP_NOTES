package Tutorial19_KeywordFinal;

/* Final keyword has a number of uses:
 *  - a final class cannot be subclassed
 *  - a final method cannot be overridden by subclasses
 *  - Making constants:- a final variable can only be initialised once
 */

public class Tutorial19_KeywordFinal {
    
    public static void main(String[] args) {
        Circle c = new Circle();
        
        // The following code will an error:
        //      c.PI = 3.32;
        //      "The final field Circle.PI cannot be assigned"
        
        c.setRadius(12);
        
        System.out.println(c.Area());
    }

}
