import java.util.Scanner;

public class Task2
{

    public static void main(String[] args)
    {
        // Print terms and conditions
        System.out.println(
                "1. A password must have at least eight characters.\n2. A password consists of only letters and digits.\n3. A password must contain at least two digits");

        // Create input object
        Scanner in = new Scanner(System.in);

        // Get password
        System.out.print("Enter your password: ");
        String password = in.nextLine();

        // Check if the password is valid
        int check = passwordChecker(password);

        // Present results of check
        if (check == 0)
        {
            System.out.println("Password is invalid.");
        }
        else
        {
            System.out.printf("Password is valid: %s", password);
        }
        in.close();

    }

    public static int passwordChecker(String password)
    {
        // To check the number of digits
        int noOfDigits = 0;

        // Make sure password is 8 characters
        if (password.length() < 8)
        {
            return 0;
        }

        // Check if password contains anything other than letters and digits
        for (int i = 0; i < password.length(); i++)
        {
            char temp = password.charAt(i);
            if (Character.isDigit(temp))
            {
                noOfDigits++;
            }
            if (!Character.isLetterOrDigit(temp))
            {
                return 0;
            }
        }

        // Check if password has at least 2 digits
        if (noOfDigits < 2)
        {
            return 0;
        }
        return 1;
    }
}
