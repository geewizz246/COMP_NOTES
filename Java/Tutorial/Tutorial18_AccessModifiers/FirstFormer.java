package Tutorial18_AccessModifiers;

// FirstFormer = Subclass of Student
public class FirstFormer extends Student {
	public void setYearLevel(int grade) {
		this.year_level = "First form";
		// Can be directly accessed since class FirstFormer is a subclass
		// of Student
	}
}
