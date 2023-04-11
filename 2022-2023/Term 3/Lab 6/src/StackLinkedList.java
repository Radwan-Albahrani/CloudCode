public class StackLinkedList
{

    // declare the top of the stack
    private Node top;

    // constructor
    public StackLinkedList()
    {
        top = null;
    }

    // inner class for the node
    private class Node
    {

        private int value;
        private Node next;

        public Node(int value)
        {
            this.value = value;
            next = null;
        }
    }

    // push a value into the stack
    public void push(int value)
    {
        Node newNode = new Node(value);
        newNode.next = top;
        top = newNode;
    }

    // pop a value from the stack
    public int pop()
    {
        if (isEmpty())
        {
            System.out.println("Stack is empty");
            return -1;
        }
        else
        {
            int value = top.value;
            top = top.next;
            return value;
        }
    }

    // peek the top of the stack without removing it
    public int peek()
    {
        if (top == null)
        {
            System.out.println("Stack is empty");
            return -1;
        }
        else
        {
            return top.value;
        }
    }

    // check if the stack is empty
    public boolean isEmpty()
    {
        return top == null;
    }

    // display the stack
    public void display()
    {
        if (isEmpty())
        {
            System.out.println("Stack is empty");
        }
        else
        {
            Node current = top;
            while (current != null)
            {
                System.out.print(current.value + " ");
                current = current.next;
            }
            System.out.println();
        }
    }

    public void makeEmpty()
    {
        top = null;
    }

    public static void main(String[] args)
    {
        testingMethod();

    }

    private static void testingMethod()
    {
        StackLinkedList stack = new StackLinkedList();
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);
        stack.push(5);
        stack.display();
        System.out.println("Peek: " + stack.peek());
        System.out.println("Pop: " + stack.pop());

        System.out.println("Displaying Stack 1: ");
        stack.display();

        StackLinkedList stack2 = new StackLinkedList();
        while (!stack.isEmpty())
        {
            stack2.push(stack.pop());
        }
        System.out.println("Displaying Stack 2: ");
        stack2.display();
    }

}
