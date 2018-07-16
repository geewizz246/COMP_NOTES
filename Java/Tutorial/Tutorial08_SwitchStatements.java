
public class Tutorial08_SwitchStatements {

	public static void main(String[] args) {
		int score = 50;
		
		/*
		 * SWITCH STATEMENT FORMAT :
		 * 	// expressions must be one of the following variable types:
		 * 	// 	- byte
		 * 	//	- short
		 * 	//	- char
		 * 	//	- int
		 * 	switch (expression)
		 * 	{
		 * 		// case statements
		 * 		// values must be of same type of expression
		 * 		case value1 :
		 * 		// Statements
		 * 		break; // break is optional
		 * 
		 * 		case value2 :
		 * 		// Statements
		 * 		break; // break is optional
		 * 
		 * 		// We can have any number of case statements.
		 * 		// Below is default statement, used when none of the cases is true.
		 * 		// No break is needed in the default case.
		 * 		default :
		 * 			// Statements
		 * 	}
		 */
		
		switch (score)
		{
			case 90 :
				System.out.println("Very good");
				break;
				
			case 75 :
				System.out.println("Good");
				break;
				
			case 60 :
				System.out.println("Alright");
				break;
			
			case 50 :
				System.out.println("Average");
				break;
				
			case 20 :
				System.out.println("Poor");
				break;
				
			default :
				System.out.println("The grade is not defined");
				break;
		}
	}
}
