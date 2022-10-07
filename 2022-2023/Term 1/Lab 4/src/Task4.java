import java.util.Scanner;

public class Task4
{
    // Define machine
    enum Machine
    {
        ON, OFF, START, IN_PROGRESS, DONE
    };

    public static void main(String[] args)
    {
        // Start Scanner
        Scanner in = new Scanner(System.in);

        // Get input from user
        System.out.print("Press a button on the machine: ");
        String Status = in.next().toUpperCase();

        // Check status of machine and make sure it is within parameters
        try
        {
            check(Machine.valueOf(Status));
        }
        catch (Exception e)
        {
            System.out.println("Not a choice");
        }
        in.close();

    }

    public static void check(Machine choice)
    {
        // Validate machine button
        switch (choice)
        {
            case ON:
                System.out.println("Machine is ON");
                break;
            case OFF:
                System.out.println("Machine is OFF");
                break;
            case IN_PROGRESS:
                System.out.println("Machine is IN_PROGRESS");
                break;
            case START:
                System.out.println("Machine is STARTING");
                break;
            case DONE:
                System.out.println("Machine is DONE");
            default:
                System.out.println("Not a button.");
                break;
        }
    }
}
