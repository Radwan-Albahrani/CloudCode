public class Recursion
{
    public static int sumDigits(int n)
    {
        if (n < 0)
        {
            return -1;
        }
        if (n < 10)
        {
            return n;
        }
        else
        {
            return n % 10 + sumDigits(n / 10);
        }
    }

    public static void main(String[] args) throws Exception
    {
        System.out.println(sumDigits(123));
    }
}
