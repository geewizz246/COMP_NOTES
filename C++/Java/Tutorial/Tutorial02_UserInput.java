import java.util.Scanner; // import class
						  // necessary for Scanner
// Scanner is a class in java.util package used for obtaining the input 
// of the primitive types like int, double etc. and strings

public class UserInput {

	public static void main(String[] args) {
		// To create an object of Scanner class, we usually pass the predefined 
		// object System.in, which represents the standard input stream
		Scanner scan = new Scanner (System.in); // create a Scanner object
		
		// print ===> same as println except no line-break
        // is added after the printed string
		System.out.print("Enter some number : ");
		
		// Scanner s.nextInt() ===> receive an integer as input
		int user_input_int = scan.nextInt();
		System.out.print("The entered value is: ");
		System.out.println(user_input_int); 
		
		
		System.out.print("\nEnter some decimal : ");
		
		// Scanner s.nextInt() ===> receive a double as input
		double user_input_double = scan.nextDouble();
		System.out.print("The entered value is: ");
		System.out.println(user_input_double);
		
		
		System.out.print("\nEnter some string : ");
		
		// Scanner s.nextLine() ===> receive a string as input
		String user_input_string = scan.nextLine();
		System.out.print("The entered string is: ");
		System.out.println(user_input_string);
	}

}
