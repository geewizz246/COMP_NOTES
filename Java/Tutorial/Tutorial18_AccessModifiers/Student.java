package Tutorial18_AccessModifiers;

public class Student {
	/********************
	 * MEMBER VARIABLES *
	 ********************/
	public String name = "";
	int age = 0;
	protected String year_level = "n/a";
	private int grade = 0;
	
	static int num_of_students = 0;
	
	/********************
	 * MEMBER FUNCTIONS *
	 ********************/
	// Default constructor
	Student() {
		num_of_students++;
	}
	
	// Overloaded constructor
	Student(String name, int age, String year_level, int grade) {
		this.name = name;
		this.age = age;
		this.year_level = year_level;
		this.grade = grade;
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
	
	public void setYearLevel(String year_level) {
		this.year_level = year_level;
	}
	
	public String getYearLevel() {
		return year_level;
	}
	
	public void setGrade(int grade) {
		this.grade = grade;
	}

	public int getGrade() {
		return grade;
	}
	
	public static int GetNumOfStudents() {
		return num_of_students;
	}
	
}