import java.util.Arrays;

public class Lab1ArrayTasks
{
    public static void main(String[] args) throws Exception
    {
        // Declare an array of 6 random integers
        int array1d[] = new int[6];
        // Fill the array with random integers positive or negative
        for (int i = 0; i < array1d.length; i++)
        {
            array1d[i] = (int) (Math.random() * 100) - 50;
        }

        // Declare 2D array of 3 rows and 4 columns
        int array2d[][] = new int[3][4];
        // Fill the array with random integers
        for (int i = 0; i < array2d.length; i++)
        {
            for (int j = 0; j < array2d[i].length; j++)
            {
                array2d[i][j] = (int) (Math.random() * 100) - 50;
            }
        }

        // Print the 1D array
        System.out.println("1D Array: " + Arrays.toString(array1d));

        // Print the 2D array
        System.out.println("2D Array: " + Arrays.deepToString(array2d));

        // Task 1 Part 1: Print the maximum value in the 1D array
        System.out.println("Task 1:\n\tMaximum value in 1D array: " + maximum1D(array1d));

        // Task 1 Part 2: Print the maximum value in the 2D array
        System.out.println("\tMaximum value in 2D array: " + maximum2D(array2d));

        // Task 2 Part 1: Print the minimum value in the 1D array
        System.out.println("Task 2:\n\tMinimum value in 1D array: " + minimum1D(array1d));

        // Task 2 Part 2: Print the minimum value in the 2D array
        System.out.println("\tMinimum value in 2D array: " + minimum2D(array2d));

        // Task 3 Part 1: Print the average value in the 1D array
        System.out.println("Task 3:\n\tAverage value in 1D array: " + average1D(array1d));

        // Task 3 Part 2: Print the average value in the 2D array
        System.out.println("\tAverage value in 2D array: " + average2D(array2d));

        // Task 4 Part 1: Print the sum of all values in the 1D array
        System.out.println("Task 4:\n\tSum of all values in 1D array: " + sum1D(array1d));

        // Task 4 Part 2: Print the sum of all values in the 2D array
        System.out.println("\tSum of all values in 2D array: " + sum2D(array2d));

        // Task 5 Part 1: Print the even numbers inside the 1D array
        System.out.println("Task 6:\n\tEven numbers in 1D array: " + Arrays.toString(even1D(array1d)));

        // Task 5 Part 2: Print the even numbers inside the 2D array
        System.out.println("\tEven numbers in 2D array: " + Arrays.toString(even2D(array2d)));

        // Task 6 Part 1: Print the odd numbers inside the 1D array
        System.out.println("Task 7:\n\tOdd numbers in 1D array: " + Arrays.toString(odd1D(array1d)));

        // Task 6 Part 2: Print the odd numbers inside the 2D array
        System.out.println("\tOdd numbers in 2D array: " + Arrays.toString(odd2D(array2d)));

        // Task 7 Part 1: Print the Square numbers inside the 1D array
        System.out.println("Task 8:\n\tSquare numbers of 1D array: " + Arrays.toString(square1D(array1d)));

        // Task 7 Part 2: Print the Square numbers inside the 2D array
        System.out.println("\tSquare numbers of 2D array: " + Arrays.deepToString(square2D(array2d)));

        // Task 8: Sum of two arrays 1D
        System.out.println("Task 9:\n\tSum of two arrays 1D: " + Arrays.toString(sumOf2Arrays1D(array1d)));

        // Task 9: multiplication of two arrays 2D
        System.out.println("\tSum of two arrays 2D: " + Arrays.deepToString(multiplicationOf2DArrays(array2d)));

        // Bonus Task: find the maximum sub array
        int array2dTest[][] = {{1, 2, -1, -4, -20}, {-8, -3, 4, 2, 1}, {3, 8, 10, 1, 3}, {-4, -1, 1, 7, -6}};
        System.out.println("Bonus Task:\n\tMaximum sub array: " + Arrays.toString(maximumSubArrayOf2DArray(array2dTest)));
    }

    private static int maximum1D(int[] array)
    {
        // Task 1 Part 1. Find the maximum value in the 1D array
        int max = array[0];
        for (int i = 1; i < array.length; i++)
        {
            if (array[i] > max)
            {
                max = array[i];
            }
        }
        return max;
    }

    private static int maximum2D(int[][] array)
    {
        // Task 1 Part 2. Find the maximum value in the 2D array
        int max = array[0][0];
        for (int i = 0; i < array.length; i++)
        {
            for (int j = 0; j < array[i].length; j++)
            {
                if (array[i][j] > max)
                {
                    max = array[i][j];
                }
            }
        }
        return max;
    }

    private static int minimum1D(int[] array)
    {
        // Task 2 Part 1. Find the minimum value in the 1D array
        int min = array[0];
        for (int i = 1; i < array.length; i++)
        {
            if (array[i] < min)
            {
                min = array[i];
            }
        }
        return min;
    }

    private static int minimum2D(int[][] array)
    {
        // Task 2 Part 2. Find the minimum value in the 2D array
        int min = array[0][0];
        for (int i = 0; i < array.length; i++)
        {
            for (int j = 0; j < array[i].length; j++)
            {
                if (array[i][j] < min)
                {
                    min = array[i][j];
                }
            }
        }
        return min;
    }

    private static double average1D(int[] array)
    {
        // Task 3 Part 1. Find the average value in the 1D array
        int sum = 0;
        for (int i = 0; i < array.length; i++)
        {
            sum += array[i];
        }
        return (double) sum / array.length;
    }

    private static double average2D(int[][] array)
    {
        // Task 3 Part 2. Find the average value in the 2D array
        int sum = 0;
        for (int i = 0; i < array.length; i++)
        {
            for (int j = 0; j < array[i].length; j++)
            {
                sum += array[i][j];
            }
        }
        return (double) sum / (array.length * array[0].length);
    }

    private static int sum1D(int array[])
    {
        // Task 4 Part 1. Find the sum of all values in the 1D array
        int sum = 0;
        for (int i = 0; i < array.length; i++)
        {
            sum += array[i];
        }
        return sum;
    }

    private static int sum2D(int array[][])
    {
        // Task 4 Part 2. Find the sum of all values in the 2D array
        int sum = 0;
        for (int i = 0; i < array.length; i++)
        {
            for (int j = 0; j < array[i].length; j++)
            {
                sum += array[i][j];
            }
        }
        return sum;
    }

    private static int[] even1D(int array[])
    {
        // Task 5 Part 1. Find the number of even values in the 1D array
        int count = 0;
        for (int i = 0; i < array.length; i++)
        {
            if (array[i] % 2 == 0)
            {
                count++;
            }
        }
        // Create a new 1D array of the size of the number of even values
        int[] even = new int[count];
        // Fill the new array with the even values
        int index = 0;
        for (int i = 0; i < array.length; i++)
        {
            if (array[i] % 2 == 0)
            {
                even[index] = array[i];
                index++;
            }
        }
        return even;
    }

    private static int[] even2D(int array[][])
    {
        // Task 5 Part 2. Find the number of even values in the 2D array
        int count = 0;
        for (int i = 0; i < array.length; i++)
        {
            for (int j = 0; j < array[i].length; j++)
            {
                if (array[i][j] % 2 == 0)
                {
                    count++;
                }
            }
        }
        // Create a new 1D array of the size of the number of even values
        int[] even = new int[count];
        // Fill the new array with the even values
        int index = 0;
        for (int i = 0; i < array.length; i++)
        {
            for (int j = 0; j < array[i].length; j++)
            {
                if (array[i][j] % 2 == 0)
                {
                    even[index] = array[i][j];
                    index++;
                }
            }
        }
        return even;
    }

    private static int[] odd1D(int array[])
    {
        // Task 6 Part 1. Find the number of odd values in the 1D array
        int count = 0;
        for (int i = 0; i < array.length; i++)
        {
            if (array[i] % 2 != 0)
            {
                count++;
            }
        }
        // Create a new 1D array of the size of the number of odd values
        int[] odd = new int[count];
        // Fill the new array with the odd values
        int index = 0;
        for (int i = 0; i < array.length; i++)
        {
            if (array[i] % 2 != 0)
            {
                odd[index] = array[i];
                index++;
            }
        }
        return odd;
    }

    private static int[] odd2D(int array[][])
    {
        // Task 6 Part 2. Find the number of odd values in the 2D array
        int count = 0;
        for (int i = 0; i < array.length; i++)
        {
            for (int j = 0; j < array[i].length; j++)
            {
                if (array[i][j] % 2 != 0)
                {
                    count++;
                }
            }
        }
        // Create a new 1D array of the size of the number of odd values
        int[] odd = new int[count];
        // Fill the new array with the odd values
        int index = 0;
        for (int i = 0; i < array.length; i++)
        {
            for (int j = 0; j < array[i].length; j++)
            {
                if (array[i][j] % 2 != 0)
                {
                    odd[index] = array[i][j];
                    index++;
                }
            }
        }
        return odd;
    }

    private static int[] square1D(int array[])
    {
        // Task 7 Part 1. Find the number of square values in the 1D array
        int[] square = new int[array.length];
        // Fill the new array with the square values
        int index = 0;
        for (int i = 0; i < array.length; i++)
        {
            square[index] = array[i] * array[i];
        }
        return square;
    }

    private static int[][] square2D(int array[][])
    {
        // Task 7 Part 2. Find the number of square values in the 2D array
        int[][] square = new int[array.length][array[0].length];
        // Fill the new array with the square values
        for (int i = 0; i < array.length; i++)
        {
            for (int j = 0; j < array[i].length; j++)
            {
                square[i][j] = array[i][j] * array[i][j];
            }
        }
        return square;
    }

    private static int[] sumOf2Arrays1D(int array[])
    {
        // Task 8. Create array (arr3={10,10,20,5,100,2}). Then, find the ADDITION of this array and given array.
        int[] arr3 = {10, 10, 20, 5, 100, 2};
        int[] sum = new int[array.length];
        // Fill the new array with the sum of the two arrays
        for (int i = 0; i < array.length; i++)
        {
            sum[i] = array[i] + arr3[i];
        }
        return sum;
    }

    private static int[][] multiplicationOf2DArrays(int array[][])
    {
        // Task 9. (arr5={{1,1,2},{2,5,2}, {4,4,4},{3,0,0}}). Then, find the matrix multiplication of given array and arr5.
        int[][] arr5 = {{1, 1, 2}, {2, 5, 2}, {4, 4, 4}, {3, 0, 0}};
        int[][] multiplication = new int[array.length][arr5[1].length];

        // Fill the new array with the matrix multiplication of the two arrays
        for (int i = 0; i < array.length; i++)
        {
            for (int j = 0; j < arr5[1].length; j++)
            {
                for (int k = 0; k < arr5.length; k++)
                {
                    multiplication[i][j] += array[i][k] * arr5[k][j];
                }
            }
        }
        return multiplication;
    }

    private static String[] maximumSubArrayOf2DArray(int array[][])
    {
        // Bonus Task: Find the maximum continuous sub-array of the 2D array
        int[] max;
        int maxSum = 0;
        int currentSum = 0;
        int start = 0;
        int end = 0;
        int startLoop = 0;

        // convert 2d array into 1d array
        int arr[] = new int[array.length * array[0].length];
        int index = 0;
        for (int i = 0; i < array.length; i++)
        {
            for (int j = 0; j < array[i].length; j++)
            {
                arr[index] = array[i][j];
                index++;
            }
        }

        // find the maximum continuous sub-array of the 1D array
        for (int i = 0; i < arr.length; i++)
        {
            currentSum += arr[i];
            if (currentSum < 0)
            {
                currentSum = 0;
                startLoop = i + 1;
            }
            else if (currentSum > maxSum)
            {
                maxSum = currentSum;
                start = startLoop;
                end = i;
            }
        }

        // fill the new array with the maximum continuous sub-array of the 2D array
        index = 0;
        max = new int[end - start + 1];
        for (int i = start; i <= end; i++)
        {
            max[index] = arr[i];
            index++;
        }

        String sumStartEnd[] = new String[3];

        // find start2D
        int count = 0;
        String start2DString = "";
        String end2DString = "";
        for (int i = 0; i < array.length; i++)
        {
            for (int j = 0; j < array[i].length; j++)
            {
                if (count == start)
                {
                    start2DString = start2DString + i + "," + (j - 1);
                }
                if (count == end)
                {
                    end2DString = end2DString + i + "," + (j + 1);
                }
                count++;
            }
        }

        // fill the new array with the maximum continuous sub-array of the 2D array
        sumStartEnd[0] = start2DString + " to " + end2DString;
        sumStartEnd[1] = Integer.toString(maxSum);
        sumStartEnd[2] = Arrays.toString(max);
        return sumStartEnd;
    }
}
