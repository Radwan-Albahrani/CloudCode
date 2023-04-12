
public class Tasks
{
    // Bracket check
    public static boolean bracketCheck(String str)
    {
        // Create a new linked list stack
        LinkedListStack<Character> stack = new LinkedListStack<>();

        // Loop through the given string
        for (int i = 0; i < str.length(); i++)
        {
            // Get the character at the current index
            char ch = str.charAt(i);

            // If the character is an opening bracket, push it into the stack
            if (ch == '(' || ch == '{' || ch == '[')
            {
                stack.push(ch);
            }

            // if the character is a closing bracket
            else if (ch == ')' || ch == '}' || ch == ']')
            {
                // Check if the stack is empty. if it is, return false
                if (stack.isEmpty())
                {
                    return false;
                }

                // Get the latest open bracket from the stack
                char top = stack.pop();

                // Check if the closing bracket matches the open bracket
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
        // once the loop is complete, return the state of the stack. if empty, it would be balanced. if not empty, it would not be balanced.
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
