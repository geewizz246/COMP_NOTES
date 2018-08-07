package Tutorial21_PolymorphismAndMethodOverriding;

public class Ellipse extends Shape {
    Ellipse(double semimajor_axis_A, double semimajor_axis_B) {
        // Shape(double, double)
        super(semimajor_axis_A, semimajor_axis_B);
    }
    
    public double Area() {
        return PI * width * height;
    }

}
