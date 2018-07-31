public class Student {
	/********************
	 * MEMBER VARIABLES *
	 ********************/
	String name = "";
	int age = 0;
	
	// The value of this variable is consistent across all instances
	static int num_of_students = 0;
	
	/********************
	 * MEMBER FUNCTIONS *
	 ********************/
	// Default constructor
	Student() {
		num_of_students++;
	}
	
	// Overloaded constructor
	Student(String name, int age) {
		this.name = name;
		this.age = age;
		num_of_students++;
	}
	
	// ---------------------------
	// GET & SET METHODS
	// ----------------------------
	public void setName(String name) {
		this.name = name;
	}
	
	public String getName() {
		return name;
	}
	
	public void setAge(int age) {
		this.age = age;
	}
	
	public int getAge() {
		return age;
	}

	public static int GetNumOfStudents() {
		return num_of_students;
	}
}
