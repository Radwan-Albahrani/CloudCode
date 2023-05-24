// Linked list stack class (Generic)
public class LinkedListStack<E>
{
    // top and size
    private Node top;
    private int size;

    // Node class
    class Node
    {
        E data;
        Node next;

        Node(E data)
        {
            this.data = data;
            this.next = null;
        }
    }

    // ================= Constructor =================
    public LinkedListStack()
    {
        this.top = null;
        this.size = 0;
    }

    // ================= Methods =================
    // push into the stack top of the stack
    public void push(E data)
    {
        Node newNode = new Node(data);
        newNode.next = top;
        top = newNode;
        size++;
    }

    // pop from the stack
    public E pop()
    {
        // if stack is empty, nothing to pop
        if (isEmpty())
        {
            System.out.println("Stack is empty");
            return null;
        }

        // Otherwise, pop from the stack and reduce size
        E data = top.data;
        top = top.next;
        size--;
        return data;
    }

    // peek the top of the stack
    public E peek()
    {
        // if stack is empty, nothing to peek
        if (isEmpty())
        {
            System.out.println("Stack is empty");
            return null;
        }

        // Otherwise, peek the top of the stack
        return top.data;
    }

    // check if the stack is empty
    public boolean isEmpty()
    {
        return top == null;
    }
}
