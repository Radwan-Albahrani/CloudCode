import java.util.Scanner;

public class Task2
{
    public static void main(String[] args)
    {
        // Create Input Object
        Scanner input = new Scanner(System.in);
        int[] array = {1, 2, 3, 4};

        // Create Variables
        float Fahren, Celsius;

        // Get Input from user
        System.out.print("Please Input Temperature in Fahrenheit: ");
        Fahren = input.nextFloat();

        // Calculate Celsius
        Celsius = (5.0f / 9.0f) * (Fahren - 32.0f);

        // Print Celsius Temperature
        System.out.printf("Temperature in Fahrenheit: %.1f\n YTemperature in Celsius: %.2f", Fahren, Celsius);
        input.close();
    }
}
