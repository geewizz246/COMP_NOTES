public class Tutorial09_WhileStatements {
	
	public static void main(String[] args) {		
		/* While Loops
		 *	- Evaluates the boolean condition first
		 * 	- If true, execute the code in the body of the loop
		 * 	- Code is repeatedly executed until the condition is false
		 */
		// WHILE LOOP EXAMPLE
		int a = 0;
		while (a < 10)
		{
			System.out.println(a);
			a++;
		}
		
		System.out.println("---------------------------");
		
		/* Do-While Loops
		 * 	- Executes the code in the body of the loop first
		 * 	- Afterwards, evaluates the boolean codition
		 * 	- Code is repeatedly executed until the condition is false
		 * 	- NOTE THAT DO-WHILE LOOPS EXECUTE AT LEAST ONE TIME
		 */
		// DO-WHILE LOOP EXAMPLE
		int b = 10;
		do {
			System.out.println(b);
			b++;
		} while (b >= 0;
		
		
	}

}
