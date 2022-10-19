import java.util.Scanner;

public class Application
{
    private static String subSystemMenu = "1. Teacher SubSystem\n2. Student SubSystem\n3. Exit\n\n";
    private static String studentMenu = "1. New Student\n2. Add Course\n3. Print Grades\n4. Get the Average\n5. Print Information\n6. Exit\n\n";
    private static String teacherMenu = "1. New Teacher\n2. Add Course\n3. Remove Course\n4. Print Information\n5. Exit\n\n";
    public static Scanner keyboard = new Scanner(System.in);
    public static Teacher teacher = null;
    public static Student student = null;

    public static void main(String[] args) throws Exception
    {
        boolean inMenu = true;
        // Print main menu
        while (inMenu)
        {
            System.out.println(subSystemMenu);
            System.out.print("Enter your choice: ");

            switch (keyboard.nextInt())
            {
                case 1:
                    teacherSubSystem();
                    break;
                case 2:
                    studentSubSystem();
                    break;
                case 3:
                    inMenu = false;
                    break;
                default:
                    break;
            }
        }
    }

    public static void teacherSubSystem() throws Exception
    {

        boolean inMenu = true;

        // Print teacher menu
        while (inMenu)
        {

            // Print menu
            System.out.println(teacherMenu);

            // Get user input
            System.out.print("Enter your choice: ");

            // Switch case
            switch (keyboard.nextInt())
            {
                // New teacher
                case 1:
                    System.out.print("Enter Name: ");
                    String name = keyboard.next();
                    System.out.print("Enter Address: ");
                    String address = keyboard.next();
                    teacher = new Teacher(name, address);
                    break;

                // Add course
                case 2:
                    // Validation
                    if (teacher == null)
                    {
                        System.out.println("No teacher created yet.");
                        break;
                    }
                    // If valid, add course
                    else
                    {
                        System.out.print("Enter Course Name: ");
                        String courseName = keyboard.next();
                        boolean check = teacher.addCourse(courseName);

                        // Check if course was added
                        if (check)
                        {
                            System.out.print("Course added successfully.");
                        }
                        else
                        {
                            System.out.print("Course already exists.");
                        }
                    }
                    break;
                case 3:
                    // Validation
                    if (teacher == null)
                    {
                        System.out.println("No teacher created yet.");
                        break;
                    }

                    // Get course name
                    System.out.print("Enter Course Name: ");
                    String courseName = keyboard.next();

                    // Remove course
                    boolean check = teacher.removeCourse(courseName);

                    // Check if course was removed
                    if (check)
                    {
                        System.out.println("Course removed successfully.");
                    }
                    else
                    {
                        System.out.println("Course not found.");
                    }
                    break;
                // Print information
                case 4:
                    // Validation
                    if (teacher == null)
                    {
                        System.out.println("No teacher created yet.");
                        break;
                    }
                    else
                    {
                        System.out.println(teacher.toString());
                    }
                    break;

                // Exit
                case 5:
                    inMenu = false;
                    break;
                default:
                    System.out.println("Invalid choice.");
                    break;
            }
        }
    }

    public static void studentSubSystem()
    {
        boolean inMenu = true;

        // Print student menu
        while (inMenu)
        {

            // Print menu
            System.out.println(studentMenu);

            // Get user input
            System.out.print("Enter your choice: ");

            // Switch case
            switch (keyboard.nextInt())
            {
                // New student
                case 1:
                    System.out.print("Enter Name: ");
                    String name = keyboard.next();
                    System.out.print("Enter Address: ");
                    String address = keyboard.next();
                    student = new Student(name, address);
                    break;

                // Add course
                case 2:
                    // Validation
                    if (student == null)
                    {
                        System.out.println("No student created yet.");
                        break;
                    }
                    // If valid, add course
                    else
                    {
                        System.out.print("Enter Course Name: ");
                        String courseName = keyboard.next();
                        System.out.print("Enter Grade: ");
                        int grade = keyboard.nextInt();
                        student.addCourseGrade(courseName, grade);

                    }
                    break;
                case 3:
                    // Validation
                    if (student == null)
                    {
                        System.out.println("No student created yet.");
                        break;
                    }
                    else
                    {
                        student.printGrades();
                    }
                    break;
                // Get Average
                case 4:
                    // Validation
                    if (student == null)
                    {
                        System.out.println("No student created yet.");
                        break;
                    }
                    else
                    {
                        System.out.println("Average: " + student.getAverageGrade());
                    }
                    break;

                // Print Information
                case 5:
                    // Validation
                    if (student == null)
                    {
                        System.out.println("No student created yet.");
                        break;
                    }
                    else
                    {
                        System.out.println(student.toString());
                    }
                    break;
                // Exit
                case 6:
                    inMenu = false;
                    break;
                default:
                    System.out.println("Invalid choice.");
                    break;
            }
        }
    }
}
