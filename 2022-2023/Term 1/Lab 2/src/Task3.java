import java.util.Scanner;

public class Task3 
{
    public static void main(String[] args) 
    {
        // Start input object
        Scanner input = new Scanner(System.in);

        // Array of 3 names
        String[] names = new String[3];

        // Get all names
        for (int i = 0; i < names.length; i++) 
        {
            System.out.print("Enter name " + (i+1) +": ");
            names[i] = input.next();
        }

        // Set max to 0 and index to 0
        int max = 0;
        int index = 0;

        // Find longest name
        for (int i = 0; i < names.length; i++) 
        {
            if(names[i].length() > max)
            {
                index = i;
                max = names[i].length();
            }
        }
        
        // Print longest name and number of characters
        System.out.println("Longest Name: " + names[index] +"\nNumber of Characters: " + max);
        input.close();
    }
}
