package Tutorial20_Inheritance;

// Rectangle class inherits the properties of the Polygon Class
public class Rectangle extends Polygon {
    // Overriding Area() method from the Polygon Class
    public double Area() {
        return (height * width);
    }

}
