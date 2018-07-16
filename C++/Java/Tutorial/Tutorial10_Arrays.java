public class Tutorial10_Arrays {
	
	public static void main(String[] args) {
		// Multiple ways of declaring arrays
		
		// First way of declaring arrays (PREFERABLE)
		int[] myIntArray = {1, 3, 2, 5, 4};
		
		// Second way
		int myIntArray2[] = {1, 2, 3, 4, 5};
		
		/* Other Declarations
		 *	- int[] myIntArray = new int[3];
		 *	- int[10] myIntArray;
		 *	- int[] myIntArray = new int[]{1, 2, 3};
		 */
		
		/* NB - the keyword "new"
		 * new is a Java keyword. It creates a Java object and allocates memory for it on the heap. 
		 * new is also used for array creation, as arrays are also objects.
		 * Syntax:
		 * 		<JavaType> <variable> = new <JavaObject>();
		 */
		
		// Recall that array indexes start at 0
		System.out.println(myIntArray[1] + 
				"\n\n------------------\n"); // Output = 3
		
		int index = 0;
		while (index < 5) {
			System.out.println(myIntArray[index]);
			index++;
		}
	}

}
