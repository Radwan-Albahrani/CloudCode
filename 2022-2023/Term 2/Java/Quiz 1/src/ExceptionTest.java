import java.util.Scanner;

public class ExceptionTest
{
    public static void main(String[] args) throws LengthException
    {
        Scanner input = new Scanner(System.in);
        try
        {
            System.out.print("Enter a string: ");
            String str = input.nextLine();
            if (str.length() > 5)
            {
                input.close();
                throw new LengthException("Invalid Length");
            }
            System.out.println("String Accepted");
        }
        catch (LengthException e)
        {
            System.out.println(e);
        }
        input.close();
    }
}
