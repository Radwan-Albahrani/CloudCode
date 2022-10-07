import java.util.Scanner;

public class Task3
{
    public static void main(String[] args)
    {
        // Prepare variables and scanners
        String mainString, character;
        Scanner in = new Scanner(System.in);

        // Get String and letter from user
        System.out.print("Enter a string: ");
        mainString = in.nextLine();
        System.out.print("Enter a character you want to remove: ");
        character = in.next();

        // Get new string after removing a character
        String newString = removeCharacter(mainString, character);

        // Print out new string
        System.out.printf("New string: %s", newString);
        in.close();
    }

    public static String removeCharacter(String string, String character)
    {
        // Start with empty string
        String removed = "";

        // Loop through string and add letters to new string except if the character matches the character the user wants to delete
        for (int i = 0; i < string.length(); i++)
        {
            if (Character.toLowerCase(string.charAt(i)) != Character.toLowerCase(character.charAt(0)))
            {
                removed += string.charAt(i);
            }
        }

        return removed;
    }
}
