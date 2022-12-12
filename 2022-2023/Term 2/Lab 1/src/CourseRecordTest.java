
import java.util.*;

public class CourseRecordTest
{

    /**
     * @param args the command line arguments
     */

    static int level1_Counter = 0, level2_Counter = 0, level3_Counter = 0;
    static Scanner input = new Scanner(System.in);

    public static void main(String[] args)
    {
        // TODO code application logic here
        CourseRecord[][] courseRecords = new CourseRecord[3][5];
        int choice = menu();

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

    static void addCourse(CourseRecord[][] courseRecords)
    {

        int level = 0;

        try
        {

            System.out.println("Adding New Course:");
            System.out.println("-------------------------");
            System.out.print("Please enter level number: ");

            level = input.nextInt();

            if (level < 1 || level > 3)
                System.out.println("Available levels are: 1, 2 and 3");
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

                } // switch
            } // else
        } // try
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

    static void printCourseRecords(CourseRecord[][] courseRecords)
    {
        System.out.println("Printing All Available Courses");
        System.out.println("--------------------------------");

        // printing level1 courses:
        if (level1_Counter != 0)
        {
            System.out.println("Available Courses in Level 1:");

            for (int col = 0; col < level1_Counter; col++)
            {
                System.out.println("Course " + (col + 1) + ":\n" + courseRecords[0][col].toString() + "\n");
            }
        }

        // printing level2 courses:
        if (level2_Counter != 0)
        {
            System.out.println("Available Courses in Level 2:");
            for (int col = 0; col < level2_Counter; col++)
            {
                System.out.println("Course " + (col + 1) + ":\n" + courseRecords[1][col].toString() + "\n");
            }
        }
        // printing level3 courses:
        if (level3_Counter != 0)
        {
            System.out.println("Available Courses in Level 3:");
            for (int col = 0; col < level3_Counter; col++)
            {
                System.out.println("Course " + (col + 1) + ":\n" + courseRecords[2][col].toString() + "\n");
            }
        }
    }

    static void searchCourseRecord(CourseRecord[][] courseRecords)
    {
        int level = 0;
        System.out.println("Updating Course Record");
        System.out.println("-------------------------");
        try
        {
            System.out.print("Please enter level number: ");
            level = input.nextInt() - 1;
            if (level < 0 || level > 2)
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
        if (courseRecords[level][0] == null)
        {
            System.out.println("No courses available to search");
            return;
        }
        System.out.print("Please enter course code: ");
        String code = input.next();
        int found = -1;

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
