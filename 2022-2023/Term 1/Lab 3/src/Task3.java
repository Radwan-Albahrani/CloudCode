import java.util.Scanner;

public class Task3
{
    public static void main(String[] args)
    {
        // Get input Object
        Scanner in = new Scanner(System.in);

        // Get a string
        String str;
        System.out.print("Enter a String: ");
        str = in.nextLine();

        // Remove the first 3 instances of M
        int removed = 0;
        String removedString = "";

        // Loop through the string and remove the first three Ms
        for (int i = 0; i < str.length(); i++)
        {
            if (removed == 3)
            {
                removedString += str.substring(i);
                break;
            }

            if (str.charAt(i) == 'm' || str.charAt(i) == 'M')
            {
                removed++;
                continue;
            }
            removedString += str.charAt(i);

        }

        // Print out new string
        System.out.println("New string: " + removedString);

        in.close();
    }
}
