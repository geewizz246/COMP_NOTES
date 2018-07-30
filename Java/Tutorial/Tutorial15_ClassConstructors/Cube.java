// CLASS FOR CUBE OBJECTS
public class Cube {
	int length; // Length of Cube
	int breadth; // Breadth of Cube
	int height; // Height of Cube
	
	/* Constructors intialise an object's member variables
	 * when the object is first created. Please note:
	 * 		- constructors have the same name as the class
	 * 		- constructors never return any values
	 */
	
	// Default Constructor
	// Called when no variables are passed in to initialise the object
	Cube() {
		// In this example, we initialise all the member variables to 1
		System.out.println("You just called the default constructor");
		this.length = 1;
		this.breadth = 1;
		this.height = 1;
	}
	
	// Overloaded Constructor
	// Called when variables are passed in to initialise the object
	Cube(int l, int b, int h) {
		System.out.println("You just called the overloaded constructor");
		this.length = l;
		this.breadth = b;
		this.height = h;
	}
	
	// Get & Set Functions
	public int getLength() {
		return length;
	}
	
	public void setLength(int length) {
		this.length = length;
	}
	
	public int getBreadth() {
		return breadth;
	}
	
	public void setBreadth(int breadth) {
		this.breadth = breadth;
	}
	
	public int getHeight() {
		return height;
	}
	
	public void setHeight(int height) {
		this.height = height;
	}
	
	// Returns the volume of the cube
	public int Volume() {
		return (length * breadth * height);
	}
}