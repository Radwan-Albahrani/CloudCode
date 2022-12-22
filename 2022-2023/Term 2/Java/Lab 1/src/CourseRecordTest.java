
import java.util.*;

public class CourseRecordTest
{
    // Level counters and input
    static int level1_Counter = 0, level2_Counter = 0, level3_Counter = 0;
    static Scanner input = new Scanner(System.in);

    public static void main(String[] args)
    {
        // Creating an array of courses
        CourseRecord[][] courseRecords = new CourseRecord[3][5];
        int choice = menu();

        // Menu and validation
        while (choice != 4)
        {
            switch (choice)
            {
                case 1:
                    addCourse(courseRecords);
                    break;
                case 2:
                    printCourseRecords(courseRecords);
                    break;
                case 3:
                    searchCourseRecord(courseRecords);
                    break;

            }
            input.nextLine();
            choice = menu();

        }

    }

    // Menu
    static int menu()
    {

        System.out.println("\n\nMenu:");
        System.out.println("1- Add Course");
        System.out.println("2- Print all course records");
        System.out.println("3- Search");
        System.out.println("4- Exit");
        System.out.print("Enter your choice: ");
        return input.nextInt();
    }

    // Function to add course
    static void addCourse(CourseRecord[][] courseRecords)
    {

        // Start with level 0
        int level = 0;

        // Try to get level from user and make sure its int and within parameters
        try
        {

            System.out.println("Adding New Course:");
            System.out.println("-------------------------");
            System.out.print("Please enter level number: ");

            level = input.nextInt();

            if (level < 1 || level > 3)
                System.out.println("Available levels are: 1, 2 and 3");
            // If level is valid, get course info
            else
            {
                System.out.print("Please enter course information:\nCourse Code: ");
                String code = input.next(); // ** string

                input.nextLine();
                System.out.print("Course Title: ");
                String title = input.nextLine();

                System.out.print("Instructor Name: ");
                String name = input.nextLine();

                System.out.print("Credit Hours: ");
                double hours = input.nextDouble();

                System.out.print("Room Number: ");
                int room = input.nextInt();

                switch (level)
                {
                    case 1:
                        courseRecords[0][level1_Counter++] = new CourseRecord(code, title, name, room, hours);
                        break;
                    case 2:
                        courseRecords[1][level2_Counter++] = new CourseRecord(code, title, name, room, hours);
                        break;
                    case 3:
                        courseRecords[2][level3_Counter++] = new CourseRecord(code, title, name, room, hours);
                        break;

                }
            }
        }
        // Catch any exception in getting course info
        catch (ArrayIndexOutOfBoundsException ex)
        {
            System.err.println("Level [" + level + "] has 5 courses."
                    + "You cannot add more courses to this level..");
        }
        catch (InputMismatchException ex)
        {
            System.err.println("Input Mismatch Exception");
            input.nextLine();
        }
        catch (Exception ex)
        {
            System.err.println(ex.getMessage());
            input.nextLine();
        }

    }

    // Function to print all available courses
    static void printCourseRecords(CourseRecord[][] courseRecords)
    {
        System.out.println("Printing All Available Courses");
        System.out.println("--------------------------------");

        // Loop through all levels
        for (int i = 0; i < courseRecords.length; i++)
        {
            // Loop through all courses in each level
            for (int j = 0; j < courseRecords[i].length; j++)
            {
                try
                {
                    // Print course info
                    System.out.println(courseRecords[i][j].toString());
                }
                catch (NullPointerException ex)
                {
                    System.err.printf("No more courses found in level: %d\n", i + 1);
                    break;
                }
                catch (Exception ex)
                {
                    System.err.println(ex.getMessage());
                }
            }
        }
    }

    // Search courses
    static void searchCourseRecord(CourseRecord[][] courseRecords)
    {
        // Initialize
        int level = 0;
        System.out.println("Updating Course Record");
        System.out.println("-------------------------");

        // Try to get level from user and make sure its int and within parameters
        try
        {
            System.out.print("Please enter level number: ");
            level = input.nextInt() - 1;
            if (level < 1 || level > 3)
            {
                System.out.println("Available levels are: 1, 2 and 3");
                return;
            }
            if (level1_Counter == 0 && level2_Counter == 0 && level3_Counter == 0)
            {
                System.out.println("No courses available to search");
                return;
            }

        }
        catch (InputMismatchException ex)
        {
            System.err.println("Input Mismatch Exception");
            input.nextLine();
        }
        catch (Exception ex)
        {
            System.err.println(ex.getMessage());
            input.nextLine();
        }

        // Check if there are any courses in this level
        if (courseRecords[level][0] == null)
        {
            System.out.println("No courses available to search");
            return;
        }

        // Get course code from user
        System.out.print("Please enter course code: ");
        String code = input.next();
        int found = -1;

        // Loop through all courses in this level and find the course
        for (int i = 0; i < courseRecords[level].length; i++)
        {
            try
            {
                if (courseRecords[level][i].getCourseCode().equals(code))
                {
                    found = i;
                    break;
                }
            }
            catch (NullPointerException ex)
            {
                System.err.println("No course found in this level");
                break;
            }
            catch (Exception ex)
            {
                System.err.println(ex.getMessage());
            }
        }

        // Print course info if found
        if (found > -1)
        {
            System.out.println("Found");
            System.out.println("Course Info\n\n" + courseRecords[level][found].toString());
        }
        else
        {
            System.out.println("Not Found");
        }
    }
}
