/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Task_2;

import java.util.InputMismatchException;
import java.util.Scanner;

public class CourseRecordTest
{

    /**
     * @param args the command line arguments
     */

    static int level1_Counter = 0, level2_Counter = 0, level3_Counter = 0;
    static Scanner input = new Scanner(System.in);

    public static void main(String[] args)
    {
        CourseRecord[][] courseRecords = new CourseRecord[3][5];
        int choice = menu();

        while (choice != 5)
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
                    updateCourseRecord(courseRecords);
                    break;
                case 4:
                    printRecord(courseRecords);
                    break;
            }

            choice = menu();

        }

    }

    static int menu()
    {

        System.out.println("\n\nMenu:");
        System.out.println("1- Add Course");
        System.out.println("2- Print all course records");
        System.out.println("3- Update course record");
        System.out.println("4- Print a course records");
        System.out.println("5- Exit");
        System.out.println("Enter your choice: ");
        return input.nextInt();
    }

    static void addCourse(CourseRecord[][] courseRecords)
    {

        int level = 0;
        try
        {

            System.out.println("Adding New Course:");
            System.out.println("-------------------------");
            System.out.println("Please enter level number: ");
            level = input.nextInt();

            if (level < 0 || level > 2)
                System.out.println("Available levels are: 1, 2 and 3");
            else
            {

                System.out.print("Please enter course information:\nCourse Code: ");
                String code = input.next();

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
        catch (IndexOutOfBoundsException ex)
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

    static void updateCourseRecord(CourseRecord[][] courseRecords)
    {
        System.out.println("Updating Course Record");
        System.out.println("-------------------------");
        System.out.println("Please enter level number:");
        int level = input.nextInt();
        System.out.println("Please enter course code:");
        String code = input.next();
        int found = -1;

        switch (level)
        {
            case 1:
                for (int i = 0; i < level1_Counter; i++)
                {
                    if (courseRecords[0][i] != null && courseRecords[0][i].getCourseCode().equals(code))
                    {
                        found = i;
                        break;
                    }
                }

                break;
            case 2:
                for (int i = 0; i < level2_Counter; i++)
                {
                    if (courseRecords[1][i] != null && courseRecords[1][i].getCourseCode().equals(code))
                    {
                        found = i;
                        break;
                    }
                }
                break;
            case 3:
                for (int i = 0; i < level2_Counter; i++)
                {
                    if (courseRecords[2][i] != null && courseRecords[2][i].getCourseCode().equals(code))
                    {
                        found = i;
                        break;
                    }
                }
                break;
        }

        if (found == -1)
        {
            System.out.println("Course Not Found!");
        }
        else
        {
            System.out.println("Course number (" + (found + 1) + ") in level ( " + level + ")");

            System.out.println("Update Course:");
            System.out.println("-------------------------");

            System.out.println("Please enter course information:\nCourse Code: ");
            String newCode = input.next();

            courseRecords[level - 1][found].setCourseCode(newCode);

            input.nextLine();
            System.out.println("Course Title: ");
            String title = input.nextLine();
            courseRecords[level - 1][found].setCourseTitle(title);

            System.out.println("Instructor Name: ");
            String name = input.nextLine();
            courseRecords[level - 1][found].setInstructorName(name);
            System.out.println("Credit Hours: ");
            double hours = input.nextDouble();
            courseRecords[level - 1][found].setCreditHours(hours);
            System.out.println("Room Number: ");
            int room = input.nextInt();
            courseRecords[level - 1][found].setClassRoom(room);

        }

    }

    static void printRecord(CourseRecord[][] courseRecords)
    {
        System.out.println("Please enter level number:");
        int level = input.nextInt();
        System.out.println("Please enter course number:");
        int no = input.nextInt();

        try
        {
            System.out.println(courseRecords[level - 1][no - 1].toString());
        }
        catch (IndexOutOfBoundsException ex)
        {
            System.out.println("No course to be printed. Exception: " + ex.getMessage());
        }

        catch (NullPointerException ex)
        {
            System.out.println("No course to be printed. Exception: " + ex.getMessage());
        }
        catch (InputMismatchException ex)
        {
            System.out.println("Invalid entry" + ex.getMessage());
        }

    }
}
