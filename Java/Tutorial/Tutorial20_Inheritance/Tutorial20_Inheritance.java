package Tutorial20_Inheritance;

/* INHERITANCE:
 * Classes in Java can be extended, creating new classes (or subclasses).
 * These new classes retain or inherit the characteristics of the base class.
 * Some of these characteristics can be overridden to suit the individual needs of each subclasses.
 */

public class Tutorial20_Inheritance {
    
    public static void main(String[] args) {
        Rectangle rec = new Rectangle();
        Triangle tri = new Triangle();
        
        // The setValues(float, float) method is inherited from the base class
        // so both Rectangle and Triangle objects can access it
        rec.setValues(12, 36);
        tri.setValues(8, 6);
        
        System.out.println("Area of Rectangle : " + rec.Area());
        System.out.println("Area of Triangle : " + tri.Area());
    }

}
