public class Tutorial11_ForLoops {

	public static void main(String[] args) {
		int[] myIntArray = {100, 24, 83, 69, 51};
		
		/* Basic for loop :
		 * for (init; boolean expression; in/decrement)
		 */
		
		for (int i = 0; i < 5; i++)
		{
			System.out.println("[" + i + "] = "
					+ myIntArray[i]);
		}
		
		System.out.println("\n------------------\n");
		/* Range-based for loop (for-each loop) : 
		 * for (range_declaration : range_expression)
		 *  - 	range_declaration ===> a declaration of a named variable, whose type 
		 * 		is the type of the element of the sequence represented by range_expression, 
		 * 		or a reference to that type.
		 *  -	range_expression ===> 	any expression that represents a suitable sequence.
		 * 		It's commonly used to iterate over an array or a Collections class (eg, ArrayList)
		 * 
		 * Please note:
		 *  +	Only access - Elements can not be assigned to, eg, not to increment each element in a collection.
		 *  +	Only single structure - It's not possible to traverse two structures at once, eg, to compare two arrays.
		 *  +	Only single element - Use only for single element access, eg, not to compare successive elements.
		 *  +	Only forward - It's possible to iterate only forward by single steps.
		 */
		
		for (int element : myIntArray)
		{
			System.out.println(element);
		}
	}
}
