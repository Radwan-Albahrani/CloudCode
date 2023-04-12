public class StackWithMax
{
    // Variables
    int top;
    int size;
    int topMax;
    int[] stack;
    int[] maxStack;

    // ==================== Constructor ====================
    public StackWithMax(int size)
    {
        this.size = size;
        stack = new int[size];
        maxStack = new int[size];
        top = -1;
        topMax = -1;
    }

    // ==================== Methods ====================
    // Push method
    public void push(int data)
    {
        // If stack is full
        if (top == size - 1)
        {
            System.out.println("Stack is full");
        }
        // If stack is not full
        else
        {
            // Push data to stack
            stack[++top] = data;

            // Push data to maxStack
            if (topMax == -1 || data >= maxStack[topMax])
            {
                maxStack[++topMax] = data;
            }
        }
    }

    // method to pop and check max stack if it is equal to the top of stack
    public int pop()
    {
        // If stack is empty
        if (top == -1)
        {
            System.out.println("Stack is empty");
            return -1;
        }

        // If stack is not empty
        else
        {
            // Pop data from maxStack if it is equal to the top of stack
            if (stack[top] == maxStack[topMax])
            {
                topMax--;
            }
            return stack[top--];
        }
    }

    // Get max method
    public int getMax()
    {
        // If stack is empty
        if (topMax == -1)
        {
            System.out.println("Stack is empty");
            return -1;
        }
        // If stack is not empty
        else
        {
            return maxStack[topMax];
        }
    }

    public static void main(String[] args)
    {
        StackWithMax stack = new StackWithMax(5);
        stack.push(3);
        stack.push(7);
        stack.push(1);
        stack.push(9);
        stack.push(2);
        System.out.println(stack.getMax()); // should print 9
        stack.pop();
        System.out.println(stack.getMax()); // should print 9
        stack.pop();
        stack.pop();
        System.out.println(stack.getMax()); // should print 7
    }
}
