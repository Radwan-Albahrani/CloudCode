import java.util.Arrays;

public class Teacher extends Person
{
    private int numCourses = 0;
    private String courses[];
    private static final int MAX_COURSES = 5;

    // Constructor
    public Teacher(String name, String address)
    {
        super(name, address);
        courses = new String[MAX_COURSES];
    }

    // Add course if it doesn't exist
    public Boolean addCourse(String name)
    {
        // If no courses added, add course immediately
        if (numCourses == 0)
        {
            courses[numCourses] = name;
            numCourses++;
            return true;
        }

        // Look for course
        else
        {
            // If possible to add course
            if (numCourses != MAX_COURSES - 1)
            {
                // If found, return false
                for (int i = 0; i < courses.length; i++)
                {
                    if (courses[i].equalsIgnoreCase(name))
                    {
                        return false;
                    }
                }

                // If not found, add it.
                courses[numCourses] = name;
                numCourses++;
                return true;
            }

            // No more space
            else
            {
                return false;
            }
        }
    }

    // Remove courses
    public boolean removeCourse(String name)
    {
        // Set index
        int index = -1;

        // Look four course
        for (int i = 0; i < courses.length; i++)
        {
            if (courses[i].equalsIgnoreCase(name))
            {
                index = i;
                break;
            }
        }

        // If course not found, return false
        if (index == -1)
        {
            return false;
        }

        // If course found, shift array to remove course
        else
        {
            for (int i = index; i < courses.length - 1; i++)
            {
                courses[i] = courses[i + 1];

            }
            numCourses--;
            return true;
        }
    }

    // Print all courses
    public void getCourses()
    {
        System.out.println("List of Courses: ");
        for (int i = 0; i < courses.length; i++)
        {
            System.out.println((i + 1) + ". " + courses[i]);
        }
    }

    // Print teacher information
    @Override
    public String toString()
    {
        return super.toString() + "\tNumber of Courses: " + numCourses + "\n\tCourses: " + Arrays.toString(courses);
    }
}
