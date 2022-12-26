
// Imports
import java.util.Scanner;

// Class to test the exception
public class ExceptionTest
{
    public static void main(String[] args) throws LengthException
    {
        // Get a scanner
        Scanner input = new Scanner(System.in);
        // Try to get a string
        try
        {
            System.out.print("Enter a string: ");
            String str = input.nextLine();
            // Throw an exception if the string is too long
            if (str.length() > 5)
            {
                input.close();
                throw new LengthException("Invalid Length");
            }
            System.out.println("String Accepted");
        }
        // Catch the exception
        catch (LengthException e)
        {
            System.out.println(e);
        }
        input.close();
    }
}
