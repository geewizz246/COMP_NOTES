public class Tutorial15_ClassConstructors {
	
	public static void main(String[] args) {
		Cube cube1 = new Cube();  // Call the default constructor		
		System.out.println("Volume of cube1 = " + cube1.Volume());
		
		Cube cube2 = new Cube(15, 10, 12); // Call the overloaded constructor
		System.out.println("Volume of cube2 = " + cube2.Volume());
	}

}