package Tutorial21_PolymorphismAndMethodOverriding;

/* PLEASE NOTE
 *      Keyword super:
 *      -   a reference variable that is used to refer parent class objects
 *      -   used to access variables and methods from the base (or super) class
 *      e.g. super.Area() would call Shape's Area function
 */
public class Triangle extends Shape {
    
    Triangle(double height, double width) {
        // calls the base class constructor with matching signature
        super(height, width); // Shape(double, double)
    }
    
    // Overriding Area()
    // To override Area(), the method's signature must remain the same.
    // i.e. return type - double
    //      method name - Area
    //      parameters - none
    public double Area() {
        return height * (width / 2);
    }

}
