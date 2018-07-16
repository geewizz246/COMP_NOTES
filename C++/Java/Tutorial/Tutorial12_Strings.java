public class Tutorial12_Strings {

	public static void main(String[] args) {
		// Declaration and Initialisation of a String
		String myString = "Hello World";
		System.out.println(myString);
		
		/* SOME STRING METHODS :
		 *  -	int length() ===> returns string length
		 *  -	boolean isEmpty() ===> checks if string is empty
		 *  -	String toLowerCase() ===> returns string in lowercase
		 *  -	String toUpperCase() ===> returns string in uppercase
		 *  -	boolean contains(CharSequence s) ===> returns true or false after matching the 
		 *  	sequence of char value
		 *  - 	String substring(int beginIndex, int endIndex) ===> returns substring for given 
		 *  	begin index and end index
		 *  -	String substring(int beginIndex) ===> returns substring for given begin index
		 *  -	String replace(CharSequence old, CharSequence new) ===> replaces all occurrences 
		 *  	of specified CharSequence
		 *  	ALSO String replace(char old, char new) does the same but with single character values
		 *  -	int indexOf(int ch) ===> returns specified char value index; returns -1 if not found
		 *  
		 *  You can find more string methods here : https://www.javatpoint.com/java-string
		 */
		
		// Let's mess around with our created string
		System.out.println("Uppercase : " + myString.toUpperCase());
		System.out.println("Lowercase : " + myString.toLowerCase());
		System.out.println("Is the string empty? : " + myString.isEmpty());
		System.out.println("Length of string : " + myString.length());
		System.out.println("Does the string contain \"hello\"? : "
				+ myString.contains("hello"));
		System.out.println("What about \"Hello\"? : "
				+ myString.contains("Hello"));
		
		System.out.println("----------------------------------------------");
		
		String myString2 = "Bonjour, " + "monseir";
		System.out.println("myString2 = " + myString2);
		System.out.println("Replace all o\'s with a\'s : "
				+ myString2.replace('o', 'a'));
		System.out.println("Index of \'m\' : " + myString2.indexOf('m'));
	}
	
}
