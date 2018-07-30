public class Tutorial14_ClassesAndObjects {
	
	public static void main(String[] args) {
		// Creating a new instance of Student
		Student Mark = new Student(); // Mark -> object or instance
		
		// Assigning values to object member variables
		Mark.setID(1);
		Mark.setName("Mark");
		Mark.setAge(22);
		
		System.out.println(Mark.getName() + " is " + Mark.getAge() + " and his student ID is " + Mark.getID());
		
		Student Tom = new Student();
		Tom.setID(2);
		Tom.setName("Tom");
		Tom.setAge(19);
		System.out.println(Tom.getName() + " is " + Tom.getAge() + " and his student ID is " + Tom.getID());
	}

}
