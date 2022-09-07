import java.util.Calendar;
import java.util.Scanner;
public class Task1
{
    public static void main(String[] args) throws Exception
    {
        // Create Input object
        Scanner input = new Scanner(System.in);

        // Prepare Variables
        int birthYear, currentYear = Calendar.getInstance().get(Calendar.YEAR), age;

        // Get Birth Year and make sure its not bigger than current year
        do
        {
            System.out.print("Please Enter your Birth Year: ");
            birthYear = input.nextInt();
            if(birthYear > currentYear)
            {
                System.out.println("Birth Year cannot be bigger than current Year.");
            }
        } while(birthYear > currentYear);

        // Calculate age
        age = currentYear - birthYear;

        // Print age
        System.out.println("Your Age is " + age + " Years");
        input.close();
    }
}
