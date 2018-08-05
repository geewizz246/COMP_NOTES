package Tutorial20_Inheritance;

// Base class Polygon
public class Polygon {
    protected float height;
    protected float width;
    
    public void setValues(float height, float width) {
        this.height = height;
        this.width = width;
    }
    
    // Default Area() method in base class
    public double Area() {
        return 0.0;
    }
}
