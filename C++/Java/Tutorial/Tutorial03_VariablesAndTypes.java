public class VariablesAndTypes {

	public static void main(String[] args) {
		/* 
		 * VARIOUS TYPES OF VARIABLES
		 * byte (integer, 1 byte)
		 * short (integer, 2 bytes)
		 * int (integer, 4 bytes)
		 * long (integer, 8 bytes)
		 * float (floating-point number, 4 bytes)
		 * double (floating-point number, 8 bytes)
		 * char (ASCII character, 2 bytes)
		 * boolean (true or false, 1 byte)
		 */
		
		short my_short = 10;
		float my_decimal = (float)4.5; // type casting the default double value as a float
		double my_double = 11.56;
		char my_char = 'A';
		boolean is_true = true;
		
		System.out.println(my_short);
		System.out.println(my_decimal);
		System.out.println(my_double);
		System.out.println(my_char);
		System.out.println(is_true);
	}

}