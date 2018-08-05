package Tutorial20_Inheritance;

// Triangle class inherits the properties of the Polygon Class
public class Triangle extends Polygon {
    // Overriding Area() method from the Polygon Class
    public double Area() {
        return (height * (width / 2));
    }

}
