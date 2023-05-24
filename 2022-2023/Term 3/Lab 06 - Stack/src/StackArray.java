public class StackArray
{

    // Declare array and top
    int array[];
    int top = -1;

    // Constructor
    StackArray(int size)
    {
        array = new int[size];
    }

    // Function to push a value to the stack
    public void push(int value)
    {
        if (isFull())
        {
            System.out.println("Stack is full");
        }
        else
        {
            array[++top] = value;
        }
    }

    // Function to pop a value from the stack
    public int pop()
    {
        if (top == -1)
        {
            System.out.println("Stack is empty");
            return -1;
        }
        else
        {
            return array[top--];
        }
    }

    // Function to peek the top value of the stack
    public int peek()
    {
        if (top == -1)
        {
            System.out.println("Stack is empty");
            return -1;
        }
        else
        {
            return array[top];
        }
    }

    // Function to check if the stack is empty
    public boolean isEmpty()
    {
        return top == -1;
    }

    // Function to check if the stack is full
    public boolean isFull()
    {
        return top == array.length - 1;
    }

    // Function to display the stack
    public void display()
    {
        if (top == -1)
        {
            System.out.println("Stack is empty");
        }
        else
        {
            for (int i = top; i >= 0; i--)
            {
                System.out.println(array[i]);
            }
        }
    }

    public static void main(String[] args) throws Exception
    {
        testingFunction();
    }

    private static void testingFunction()
    {
        StackArray stack = new StackArray(5);
        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.push(40);
        stack.push(50);
        stack.push(60);
        stack.display();
        System.out.println("Peek: " + stack.peek());
        System.out.println("Pop: " + stack.pop());
        System.out.println("Peek: " + stack.peek());
        stack.display();
    }
}
