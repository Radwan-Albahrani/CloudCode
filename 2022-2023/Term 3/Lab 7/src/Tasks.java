
public class Tasks
{
    // Bracket check
    public static boolean bracketCheck(String str)
    {
        LinkedListStack<Character> stack = new LinkedListStack<>();
        for (int i = 0; i < str.length(); i++)
        {
            char ch = str.charAt(i);
            if (ch == '(' || ch == '{' || ch == '[')
            {
                stack.push(ch);
            }
            else if (ch == ')' || ch == '}' || ch == ']')
            {
                if (stack.isEmpty())
                {
                    return false;
                }
                char top = stack.pop();
                if (ch == ')' && top != '(')
                {
                    return false;
                }
                if (ch == '}' && top != '{')
                {
                    return false;
                }
                if (ch == ']' && top != '[')
                {
                    return false;
                }
            }
        }
        return stack.isEmpty();
    }

    // Decimal to Binary
    public static String decimalToBinary(int num)
    {
        LinkedListStack<Integer> stack = new LinkedListStack<>();
        while (num > 0)
        {
            stack.push(num % 2);
            num /= 2;
        }
        String str = "";
        while (!stack.isEmpty())
        {
            str += stack.pop();
        }
        return str;
    }

    // Test methods
    private static void TestBracketCheck()
    {
        String str = "((a+b)*(c-d))";
        System.out.println("The string: " + str + "\nBalance state: " + bracketCheck(str)); // true

        str = "((a+b)*(c-d)";
        System.out.println("The string: " + str + "\nBalance state: " + bracketCheck(str)); // false
    }

    private static void TestDecimalToBinary()
    {
        int num = 10;
        System.out.println("The number " + num + "\nIn binary is " + decimalToBinary(num)); // 1010

        num = 100;
        System.out.println("The number " + num + "\nIn binary is " + decimalToBinary(num)); // 1100100
    }

    public static void main(String[] args)
    {
        TestBracketCheck();
        TestDecimalToBinary();
    }
}
