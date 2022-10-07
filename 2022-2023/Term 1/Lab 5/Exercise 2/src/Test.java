public class Test
{
    public static void main(String[] args)
    {
        // Start account
        Account testAccount = new Account(1122, 20000);
        Account.setAnnualInterestRate(4.5);

        // Deposit money
        testAccount.deposit(3000);

        // Print stats
        System.out.printf("Current Balance: %.2f\nMonthly Interest: %.2f\nDate Created: %s", testAccount.getBalance(), testAccount.getMonthlyInterest(),
                testAccount.getDateCreated());
    }
}
