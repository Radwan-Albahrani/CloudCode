import java.util.Scanner;

public class Task1
{
    public static void main(String[] args) throws Exception
    {
        // Start with a scanner
        Scanner in = new Scanner(System.in);

        // Create array 4 weeks 7 days each
        int weeks[][] = new int[4][7];

        // Loop through array and get all values
        for (int i = 0; i < 4; i++)
        {
            System.out.printf("Week %d: ", i + 1);
            for (int j = 0; j < 7; j++)
            {
                weeks[i][j] = in.nextInt();
            }
            System.out.println();
        }

        // Calculate average for each week
        for (int i = 0; i < 4; i++)
        {
            // Prepare Variables
            int sum = 0;
            double average = 0;

            // Calculate average
            for (int j = 0; j < 7; j++)
            {
                sum += weeks[i][j];
            }
            average = sum / 7.0;

            // Print average and classification
            System.out.printf("Week %d: %.2f ", i + 1, average);
            getClassification(average);
        }

        // Close input
        in.close();
    }

    // Get categorization for the rainfall
    public static void getClassification(double average)
    {
        // Check which Category the rainfall goes into
        if (average >= 6)
        {
            System.out.println("(high)");
        }
        else if (average > 3)
        {
            System.out.println("(medium)");
        }
        else
        {
            System.out.println("(low)");
        }
    }
}
