import java.util.Scanner;

public class Task1
{
    public static void main(String[] args) throws Exception
    {
        // Create input variable
        Scanner in = new Scanner(System.in);

        // get array size and make sure its a number
        int SIZE = 0;
        boolean parsed = false;
        while (!parsed)
        {
            try
            {
                System.out.print("Enter number of students: ");
                SIZE = in.nextInt();
                parsed = true;
            }
            catch (Exception e)
            {
                System.out.println("Must be a Number.");
                in.nextLine(); // Clear Buffer
            }

        }

        // Create arrays with size
        String names[] = new String[SIZE];
        int grades[] = new int[SIZE];

        // Get names and grades:
        for (int i = 0; i < grades.length; i++)
        {
            System.out.print("Enter the name of student number " + (i + 1) + ": ");
            names[i] = in.next();
            parsed = false;

            // Make sure you get a number
            while (!parsed)
            {
                try
                {
                    System.out.print("Enter the grade of " + names[i] + ": ");
                    grades[i] = in.nextInt();
                    parsed = true;
                }
                catch (Exception e)
                {
                    System.out.println("Must be a number");
                    in.nextLine(); // Clear Buffer
                }
            }

        }
        // Create variables for max student and index
        int maxIndex = 0, maxGrade = 0;

        // Get the max grade and index
        for (int i = 0; i < grades.length; i++)
        {
            if (grades[i] > maxGrade)
            {
                maxGrade = grades[i];
                maxIndex = i;
            }
        }

        // Print out answer
        System.out.printf("Student with the highest score is %s with score %d", names[maxIndex], grades[maxIndex]);
        in.close();
    }
}
