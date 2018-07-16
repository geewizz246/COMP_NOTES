
public class Tutorial07_LogicalOperators {
	
	public static void main(String[] args) {
		/*
		 * LOGICAL OPERATORS:
		 * && ====> AND (both conditions must be true)
		 * || ====> OR (at least one condition must be true)
		 */
		int subject1 = 40;
		int subject2 = 60;
		
		if ((subject1 >= 35) && (subject2 <= 50))
			System.out.println("The condition is true");
		else
			System.out.println("The condition is false");
		
		if ((subject1 == 40) || (subject2 != 60))
			System.out.println("This one is true");
		else
			System.out.println("Nope this one is false");
		
	}

}
