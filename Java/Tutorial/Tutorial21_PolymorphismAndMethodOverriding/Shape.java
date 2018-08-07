package Tutorial21_PolymorphismAndMethodOverriding;

public class Shape {
    // Constants
    protected final double PI = 3.14159;
    
    // Member Variables
    protected double height;
    protected double width;
    
    Shape() {
        height = 0;
        width = 0;
    }
    
    Shape(double length) {
        height = length;
        width = length;
    }
    
    Shape(double height, double width) {
        this.height = height;
        this.width = width;
    }
    
    // Default Area() method
    public double Area() {
        return height * width;
    }

}
