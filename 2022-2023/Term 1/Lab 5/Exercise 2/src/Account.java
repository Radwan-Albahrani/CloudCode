import java.text.SimpleDateFormat;
import java.util.Date;

public class Account
{
    // Formate date
    SimpleDateFormat formatter = new SimpleDateFormat("dd/mm/yyyy h:mma");

    // Variables
    private int id;
    private double balance;
    private static double annualInterestRate = 0;
    private Date dateCreated;

    // Setters
    public void setId(int id)
    {
        this.id = id;
    }

    public void setBalance(double balance)
    {
        this.balance = balance;
    }

    public static void setAnnualInterestRate(double annualInterestRate)
    {
        Account.annualInterestRate = annualInterestRate;
    }

    // Getters
    public int getId()
    {
        return id;
    }

    public double getBalance()
    {
        return balance;
    }

    public static double getAnnualInterestRate()
    {
        return annualInterestRate;
    }

    public String getDateCreated()
    {
        return formatter.format(dateCreated);
    }

    // Constructors
    public Account(int id, double balance)
    {
        this.id = id;
        this.balance = balance;
        this.dateCreated = new Date();
    }

    public Account()
    {
        id = 0;
        balance = 0;
        annualInterestRate = 0;
        dateCreated = new Date();
    }

    // Methods
    // Get monthly interest rate
    public double getMonthlyInterestRate()
    {
        return ((Account.annualInterestRate / 100) / 12);
    }

    // Get monthly interest and apply it
    public double getMonthlyInterest()
    {
        this.balance = this.balance * ((Account.annualInterestRate / 100) / 12);
        return this.balance;
    }

    // Withdraw money
    public void withdraw(double withdrawAmount)
    {
        if (withdrawAmount > this.balance)
        {
            this.balance -= withdrawAmount;
            System.out.printf("Amount Withdrawn: %.2f\nCurrent Balance: %.2f\n\n", withdrawAmount, this.balance);
        }
        else
        {
            System.out.println("Not enough money");
        }
    }

    // Deposit money
    public void deposit(double depositAmount)
    {
        this.balance += depositAmount;
        System.out.printf("Amount Deposited: %.2f\nCurrent Balance: %.2f\n\n", depositAmount, this.balance);
    }
}
