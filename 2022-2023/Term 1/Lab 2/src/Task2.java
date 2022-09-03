import java.util.Scanner;

public class Task2 
{
    public static void main(String[] args) 
    {
        // Input object
        Scanner input = new Scanner(System.in);

        int month;
        System.out.print("Enter Month Number: ");
        month = input.nextInt();
        String monthName;
        switch (month) 
        {
            case 1:
                monthName = "January"; 
                System.out.printf("Name: %s\nThis month has 31 Days", monthName);
                break;
            case 3:
                monthName = "March"; 
                System.out.printf("Name: %s\nThis month has 31 Days", monthName);
                break; 
            case 5:
                monthName = "May"; 
                System.out.printf("Name: %s\nThis month has 31 Days", monthName);
                break; 
            case 7: 
                monthName = "July"; 
                System.out.printf("Name: %s\nThis month has 31 Days", monthName);
                break;
            case 8: 
                monthName = "August"; 
                System.out.printf("Name: %s\nThis month has 31 Days", monthName);
                break;
            case 10: 
                monthName = "October"; 
                System.out.printf("Name: %s\nThis month has 31 Days", monthName);
                break;
            case 12:
                monthName = "December"; 
                System.out.printf("Name: %s\nThis month has 31 Days", monthName);
                break;
            case 4: 
            monthName = "April"; 
                System.out.printf("Name: %s\nThis month has 30 Days", monthName);
                break;
            case 6: 
            monthName = "June"; 
                System.out.printf("Name: %s\nThis month has 30 Days", monthName);
                break;
            case 9: 
            monthName = "September"; 
                System.out.printf("Name: %s\nThis month has 30 Days", monthName);
                break;
            case 11:
                monthName = "November"; 
                System.out.printf("Name: %s\nThis month has 30 Days", monthName);
                break;
            case 2:
                monthName = "February"; 
                System.out.printf("Name: %s\nThis month has 28 Days", monthName);
                break;
        
            default:
                System.out.println("Not a month within the calender year");
                break;
        }
        input.close();
    }
}
