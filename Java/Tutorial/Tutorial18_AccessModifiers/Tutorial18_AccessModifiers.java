/* Access Levels:

 	Modifier	| Class | Package | Subclass | Subclass | World
	            |       |         |(same pkg)|(diff pkg)|
				|		|		  |			 |			|
	============================================================
	public      |   +   |    +    |    +     |     +    |   +     
				|		|		  |			 |			|			
	protected   |   +   |    +    |    +     |     +    |         
				|		|		  |			 |			|
	no modifier |   +   |    +    |    +     |          |    
				|		|		  |			 |			|			
	private     |   +   |         |          |          |    
	
	+ : accessible
	blank : not accessible
 */

// A package is a namespace that organises a set of related classes and interfaces.
// Packages consists of different files being grouped together in the same folder.

package Tutorial18_AccessModifiers;

public class Tutorial18_AccessModifiers {
	
	public static void main(String[] args) {
		Student s1 = new Student();
		
		// Since the variable name is public, it can be accessed
		// by all files
		s1.name = "Mark";
		
		s1.age = 12;
		// Can be directly accessed since this file and class Student are
		// part of the same package.
		
		s1.year_level = "1st form";
		// Can be directly accessed since this file and class Student are
		// part of the same package.
		
		// s1.grade = 80;
		// This would cause an error since grade is only directly accessible 
		// within the class
	}

}
