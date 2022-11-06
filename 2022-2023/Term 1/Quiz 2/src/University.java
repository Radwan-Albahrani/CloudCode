import java.util.Scanner;

public class University
{
    // ================== Variables ==================
    private static Scanner input = new Scanner(System.in);

    // ================== Main ==================
    public static void main(String[] args) throws InterruptedException
    {
        int choice = 0;
        while (choice != 3)
        {
            // Show menu
            System.out.println("1. Diploma\n2. Bachelor student\n3. Exit\n\n");
            System.out.print("Enter your choice: ");

            // Get Choice from user
            choice = getInt();

            // Switch for menu
            switch (choice)
            {
                // Create Diploma Student
                case 1:
                    Diploma diploma = new Diploma();

                    // Get diploma student info
                    System.out.print("Enter student name: ");
                    diploma.setName(input.nextLine());
                    System.out.print("Enter student address: ");
                    diploma.setAddress(input.nextLine());
                    System.out.print("Enter student ID: ");
                    diploma.setStudentID(input.nextLine());
                    System.out.print("Enter student hours: ");
                    diploma.setHours(getInt());
                    diploma.checkGraduate();


                    // Print Info and if graduated
                    System.out.println("\n\nStudent name: " + diploma.getName());
                    System.out.println("Student address: " + diploma.getAddress());
                    System.out.println("Student ID: " + diploma.getStudentID());
                    System.out.println("Student status: " + diploma.getStatus());
                    System.out.println("Student GPA: " + diploma.calculateGPA() + "\n\n");
                    Thread.sleep(1000);

                    break;
                // Create Bachelor Student
                case 2:
                    Bachelor bachelor = new Bachelor();
                    System.out.print("Enter student name: ");
                    bachelor.setName(input.next());
                    System.out.print("Enter student address: ");
                    bachelor.setAddress(input.next());
                    System.out.print("Enter student ID: ");
                    bachelor.setStudentID(input.next());
                    System.out.print("Enter student hours: ");
                    bachelor.setHours(getInt());
                    bachelor.checkGraduate();
                    System.out.println("\n\nStudent name: " + bachelor.getName());
                    System.out.println("Student address: " + bachelor.getAddress());
                    System.out.println("Student ID: " + bachelor.getStudentID());
                    System.out.println("Student status: " + bachelor.getStatus());
                    System.out.println("Student GPA: " + bachelor.calculateGPA() + "\n\n");
                    Thread.sleep(1000);
                    break;
                default:
                System.out.println("Not a choice!!");
                    break;
            }
        }
    }

    // ================== Methods ==================
    static int getInt()
    {
        int choice = 0;
        boolean notParsed = false;
        do
        {
            try
            {
                choice = Integer.parseInt(University.input.nextLine());
                notParsed = false;
            }
            catch (NumberFormatException e)
            {
                System.out.println("Please enter a valid number!");
                System.out.print("Enter Your Choice: ");
                notParsed = true;
            }
        } while (notParsed);

        return choice;
    }
}
