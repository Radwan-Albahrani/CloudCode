import java.util.Arrays;

public class Student extends Person
{
    // Variables
    private int numCourses = 0;
    private String courses[];
    private int grades[];
    private static final int MAX_COURSES = 30;

    // Constructor
    public Student(String name, String address)
    {
        super(name, address);
        courses = new String[MAX_COURSES];
        grades = new int[MAX_COURSES];
    }

    // Add course and its grade
    public void addCourseGrade(String name, int grade)
    {
        if(numCourses != MAX_COURSES - 1)
        {
            courses[numCourses] = name;
            grades[numCourses] = grade;
            numCourses++;
        }

    }

    public void printGrades()
    {
        // Validation
        if (numCourses == 0)
        {
            System.out.println("No Courses added to this student.");
        }

        // Print all courses
        for (int i = 0; i < courses.length; i++)
        {
            System.out.println("Course name: " + courses[i] + " Grade: " + grades[i]);
        }
    }

    public double getAverageGrade()
    {
        // Validation
        if (numCourses == 0)
        {
            System.out.println("No courses added to this student.");
        }

        // Get average
        double average = 0, sum = 0;
        for (int i = 0; i < grades.length; i++)
        {
            sum += grades[i];
        }

        // Return Average
        average = sum / courses.length;
        return average;
    }

    // Print student information
    @Override
    public String toString()
    {
        return super.toString() + "\tNumber of Courses: " + numCourses + "\n\tCourses: " + Arrays.toString(courses) + "\n\tGrades: " + Arrays.toString(grades);
    }

}
