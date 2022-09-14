import java.util.Scanner;

public class Task2
{
    public static void main(String[] args)
    {
        // Prepare input
        Scanner in = new Scanner(System.in);

        // Get user's full name
        String name;
        System.out.print("Enter your First, Middle, And Last name: ");
        name = in.nextLine();

        // Split the name by spaces
        String fmlname[] = name.split(" ");

        // Get user age
        int age;
        System.out.print("Enter your age: ");
        age = in.nextInt();

        // Create password
        String password = fmlname[0].charAt(0) + "" + fmlname[1].charAt(fmlname[1].length() / 2) + fmlname[2].charAt(fmlname[2].length() - 1);
        password = password.toUpperCase() + "" + (age * 100);
        System.out.println("Your Password is: " + password);
        in.close();

    }

}
