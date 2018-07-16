
public class MathAndArithmeticOperators {

	public static void main(String[] args) {
		/* 
		 * MATH OPERATORS :
		 * + ===> Addition
		 * - ===> Subtraction
		 * * ===> Multiplication
		 * / ===> Division
		 * % ===> Modulus (returns remainder)
		 */
		
		int x = 20,
			y = 30;
		
		// Add x and y
		int AddAns = x + y;
		System.out.println(x + " + " + y + " = " + AddAns);
		
		// Subtract y from x
		int SubAns = x - y;
		System.out.println(x + " - " + y + " = " + SubAns);
		
		// Divide x by y
		// The real answer would be 0.666... but since DivAns is an int,
		// the .666... is truncated and the answer is 0
		int DivAns = x / y;
		System.out.println(x + " / " + y + " = " + DivAns);
		
		// Multiply x by y
		int MultAns = x * y;
		System.out.println(x + " * " + y + " = " + MultAns);
		
	}

}
