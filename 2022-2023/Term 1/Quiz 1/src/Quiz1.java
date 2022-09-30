import java.util.Scanner;

public class Quiz1
{

    // Function to generate shape
    public static String generateStr()
    {
        // Get height of stairs
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the height of the stairs: ");
        int rows = input.nextInt();

        // Prepare string
        String shape = "";

        // Prepare columns
        int columns = 1;

        // Loop through rows
        for (int i = 0; i < rows; i++)
        {
            // Print required stars for this column
            for (int j = 0; j < columns; j++)
            {
                shape += "*";
            }

            // Add spaces for counting
            for (int j = 0; j < rows - columns; j++)
            {
                shape += " ";
            }

            // Increase columns, go to next line
            columns++;
            shape += "\n";
        }
        input.close();

        // Return shape
        return shape;
    }

    // Function to count spaces in said shape
    public static int CountSpaces(String str)
    {
        // Start a counter
        int spaceCounter = 0;

        // Loop through string
        for (int i = 0; i < str.length(); i++)
        {
            // If character is a space, add to counter
            if (str.charAt(i) == ' ')
            {
                spaceCounter++;
            }
        }
        // Return count
        return spaceCounter;
    }

    public static void main(String[] args) throws Exception
    {
        // Get shape
        String shape = generateStr();

        // Print shape
        System.out.println(shape);

        // Get spaces
        int spaces = CountSpaces(shape);

        // Print Spaces
        System.err.println("Number of spaces: " + spaces);

    }
}
