
public class Tutorial06_IfStatementsAndRelationalOperators {

	public static void main(String[] args) {
		/* IF ELSE STATEMENT FORMAT : 
		 * if (boolean_expression)
		 * {
		 * 		execute code if boolean expression is true
		 * }
		 * else if (boolean_expression)
		 * {
		 * 		execute code if boolean expression is true
		 * }
		 * else
		 * {
		 * 		default; execute if other expressions are false
		 * }
		 */
		
		int x = 16;
		
		if (x == 25) // == is used to represent equality
		{
			System.out.println("x is  25");
		}
		else if (x > 25)
		{
			System.out.println("x is more than 25");
		}
		else // if code to be executed is only one line, no curly braces are necessary
			System.out.println("x is less than 25");
		
		/*
		 * RELATIONAL OPERATORS : 
		 * == 	is equal to
		 * !=	is not equal to
		 * >	is greater than
		 * <	is less than
		 * >=	is greater than or equal to
		 * <=	is less than or equal to
		 */
	}
}
