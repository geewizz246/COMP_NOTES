public class Tutorial13_IntroToMethods {
	
	public static void main(String[] args) {
		Introduction("John");
		int result = Add(25, 30);
		System.out.println("Result = " + result);
	}
	
	// Prints a greeting to the user
	public static void Introduction(String name) {
		System.out.println("Hi " + name + ", how are you?");
		Add(25, 15);
		Add(100, 69);
	}
	
	// Adds two values and returns the result
	public static int Add(int num1, int num2) {
		// System.out.println(num1 + " + " + num2 + " = " + (num1 + num2));
		return num1 + num2;
	}
	
	// Subtracts two values and returns the result
	public static int Subtract(int num1, int num2) {
		return num1 - num2;
	}
	
	// Multiplies two values and returns the result
	public static int Multiply(int num1, int num2) {
		return num1 * num2;
	}
	
	// Divides two values and returns the result
	public static int Divide(int num1, int num2) {
		return num1 / num2;
	}

}
