import java.util.Scanner;

public class Task4
{
    public static void main(String[] args)
    {
        // Input
        Scanner in = new Scanner(System.in);

        // Get string
        System.out.print("Enter a String: ");
        String line;
        line = in.nextLine();

        // Split into words
        String[] words = line.split(" ");

        // Print number of words
        System.out.println("The number of words you have entered is: " + words.length);
        in.close();
    }
}
