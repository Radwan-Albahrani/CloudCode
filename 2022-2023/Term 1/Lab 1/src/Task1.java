import java.util.Scanner;
public class Task1
{
    public static void main(String[] args) throws Exception
    {
        // Create Input object
        Scanner input = new Scanner(System.in);

        // Prepare Variables
        int BirthYear, CurrentYear = 2022, age;

        // Get Birth Year and make sure its not bigger than current year
        do
        {
            System.out.print("Please Enter your Birth Year: ");
            BirthYear = input.nextInt();
            if(BirthYear > CurrentYear)
            {
                System.out.println("Birth Year cannot be bigger than current Year.");
            }
        } while(BirthYear > CurrentYear);

        // Calculate age
        age = CurrentYear - BirthYear;

        // Print age
        System.out.println("Your Age is " + age + " Years");
        input.close();
    }
}
