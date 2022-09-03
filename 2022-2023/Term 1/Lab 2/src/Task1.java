import java.util.Scanner;

public class Task1
{
    public static void main(String[] args)
    {
        // Create input Object
        Scanner input = new Scanner(System.in);

        // Prepare Variables
        int[] nums = new int[3];

        // Get numbers
        for (int i = 0; i < 3; i++)
        {
            System.out.printf("Enter Number %d: ", i + 1);
            nums[i] = input.nextInt();
        }

        // Calculate Average
        float Average = (nums[0] + nums[1] + nums[2]) / 3.0f;

        // Get minimum and maximum
        int min = 999999999;
        int max = -999999999;
        for (int i = 0; i < 3; i++)
        {
            if (nums[i] < min)
            {
                min = nums[i];
            }
            if (nums[i] > max)
            {
                max = nums[i];
            }
        }

        // Print out everything
        System.out.printf("The Average of the values is %.2f\nThe Maximum number is: %d\nThe Minimum Number is: %d",
                Average, max, min);
        input.close();

    }
}
