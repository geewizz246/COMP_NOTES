public class Tutorial17_KeywordStatic {
	
	// What does the 'static' keyword do in a class?
	public static void main(String[] args) {
		// static members belong to the class instead of a specific instance
		
		// To access a static method, you must use the class name with the dot operator
				// In this case, Student.GetNumOfStudents()
		System.out.println(Student.GetNumOfStudents());
		
		Student mark = new Student("Mark", 12);
		Student ken = new Student("Ken", 13);
		Student bob = new Student("Bob", 16);
		
		System.out.println(mark.getName() + " " + mark.getAge());
		System.out.println(ken.getName() + " " + ken.getAge());
		System.out.println(bob.getName() + " " + bob.getAge());
		
		System.out.println(Student.GetNumOfStudents());
	}

}
