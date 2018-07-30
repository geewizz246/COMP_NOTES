public class Tutorial16_MethodOverloading {

	public static void main(String[] args) {
		/* The compiler automatically knows which version of the add method
		 * to use based what values are passed into the function
		 */
		
		System.out.println(Add(27, 52));
		System.out.println(Add(5.656, 7.8));
		System.out.println(Add("Ya ", "mudda"));
	}
	
	// Add two integers
	public static int Add(int a, int b) {
		return a + b;
	}
	
	// Add two floating-point numbers
	public static double Add(double a, double b) {
		return a + b;
	}
	
	// Add two strings
	public static String Add(String a, String b) {
		return a + b;
	}
	
}