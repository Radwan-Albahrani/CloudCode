import java.util.Scanner;

public class Task1
{
    public static void main(String[] args) throws Exception
    {
        Scanner input = new Scanner(System.in);
        int BirthYear, CurrentYear = 2022, age;

        System.out.print("Please Enter your Birth Year: ");
        BirthYear = input.nextInt();
        age = CurrentYear - BirthYear;

        System.out.println("Your Age is " + age + " Years");
        input.close();
    }
}
