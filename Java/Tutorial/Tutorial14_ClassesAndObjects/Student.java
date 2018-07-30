public class Student {
	// Member Variables / Attributes
	// When these are declared as private, only the class' own member functions can
	// access them. They cannot be directly accessed by functions outside the class.
	private int ID; // ID of student
	private String name; // Name of student
	private int age; // Age of student
	
	// Get & Set Member Functions
	public int getID() {
		return ID;
	}
	
	public void setID(int ID) {
		this.ID = ID;
	}
	
	public String getName() {
		return name;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public int getAge() {
		return age;
	}
	
	public void setAge(int age) {
		this.age = age;
	}
}
