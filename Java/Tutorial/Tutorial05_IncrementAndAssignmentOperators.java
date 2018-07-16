
public class Tutorial05_IncrementAndAssignmentOperators {

	public static void main(String[] args) {
		/*
		 * INCREMENT OPERATORS :
		 * a++ ====> Post-Increment : increase by 1 after variable is used
		 * ++a ====> Pre-Increment : increase by 1 before variable is used
		 * a-- ====> Post-Decrement : decrease by 1 after variable is used
		 * --a ====> Pre-Decrement :  decrease by one before variable is used
		 */
		int x = 10;
		
		System.out.println(x++); // Output : 10
		System.out.println(x); // Output : 11
		System.out.println(++x); // Output : 12
		System.out.println(x); // Output : 12
		
		System.out.println(x--); // Output : 12
		System.out.println(x); // Output : 11
		System.out.println(--x); // Output : 10
		System.out.println(x); // Output : 10
		
		System.out.println("\n");
		
		/*
		 * ARITHMETIC OPERATORS :
		 * num += ====> Increase num by given value
		 * num -= ====> Decrease num by given value
		 * num *= ====> Multiply num by given value
		 * num /= ====> Divide num by given value
		 * num %= ====> Get remainder when divided by given value
		 */
		
		int y = 5;
		System.out.println(y += 5); // Output : 10
		System.out.println(y -= 5); // Output : 5
		System.out.println(y *= 5); // Output : 25
		System.out.println(y /= 5); // Output : 5
		System.out.println(y %= 5); // Output : 0
	}
}
