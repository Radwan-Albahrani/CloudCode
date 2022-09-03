import java.util.Scanner;

public class Task2
{
    public static void main(String[] args)
    {
        // Create Input Object
        Scanner input = new Scanner(System.in);

        // Create Variables
        float Fehren, Celsius;

        // Get Input from user
        System.out.print("Please Input Temperature in Fahrenheit: ");
        Fehren = input.nextFloat();

        // Calculate Celsius
        Celsius = (5.0f / 9.0f) * (Fehren - 32.0f);

        // Print Celsius Temperature
        System.out.printf("Temperature in Fehrennheit: %.1f\n YTemperature in Celsius: %.2f", Fehren, Celsius);
        input.close();
    }
}
