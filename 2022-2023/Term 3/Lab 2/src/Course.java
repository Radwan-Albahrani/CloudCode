public class Course
{
    int courseId;
    String courseName;
    int creditHours;
    String instructor;

    public Course(int courseId, String courseName, int creditHours, String instructor)
    {
        this.courseId = courseId;
        this.courseName = courseName;
        this.creditHours = creditHours;
        this.instructor = instructor;
    }

    @Override
    public String toString()
    {
        String toPrint = "";
        toPrint += "Course ID: " + courseId + "\n";
        toPrint += "Course Name: " + courseName + "\n";
        toPrint += "Credit Hours: " + creditHours + "\n";
        toPrint += "Instructor: " + instructor + "";
        return toPrint;

    }
}
