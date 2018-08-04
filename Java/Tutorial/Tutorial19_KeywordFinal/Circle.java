package Tutorial19_KeywordFinal;

// No class would be able to extend the Circle class
public final class Circle {
    private double radius = 0;
    public final double PI; // After this value is initialised, it cannot be changed

    Circle () {
        PI = 3.14159;
    }
    
    Circle (double radius) {
        PI = 3.14159;
        this.radius = radius;
    }
    
    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }
    
    // No method of the same signature can override the Area() method
    public final double Area() {
        return (PI * (radius * radius));
    }

}
