package Tutorial21_PolymorphismAndMethodOverriding;

public class Circle extends Shape {    
    Circle(double radius) {
        // Shape(double)
        super(radius);
    }
    
    public double Area() {
        // Use Java's Math library to access the power function
        //      Math.pow(double num, double pow) = num ^ pow
        return PI * Math.pow(width, 2);
    }

}
