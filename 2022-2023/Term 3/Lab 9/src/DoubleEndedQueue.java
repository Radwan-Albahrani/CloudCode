public class DoubleEndedQueue extends DoubleEndedQueueAbstract
{
    Node front = null;
    Node back = null;

    class Node
    {
        String data;
        Node next;
        Node prev;

        Node(String data)
        {
            this.data = data;
            this.next = null;
        }
    }

    @Override
    public void enqueueFront(String word)
    {
        Node newNode = new Node(word);
        if (isEmpty())
        {
            front = newNode;
            back = newNode;
            return;
        }
        newNode.next = front;
        front.prev = newNode;
        front = newNode;
    }

    @Override
    public void enqueueBack(String word)
    {
        Node newNode = new Node(word);
        if (isEmpty())
        {
            front = newNode;
            back = newNode;
            return;
        }
        back.next = newNode;
        newNode.prev = back;
        back = newNode;
    }

    @Override
    public String dequeueFront()
    {
        if (isEmpty())
        {
            System.out.println("Queue is empty");
            return null;
        }
        String data = front.data;
        front = front.next;
        if (front == null)
        {
            back = null;
        }
        return data;
    }

    @Override
    public String dequeueBack()
    {
        if (isEmpty())
        {
            System.out.println("Queue is empty");
            return null;
        }
        String data = back.data;
        back = back.prev;
        if (back == null)
        {
            front = null;
        }
        return data;
    }

    @Override
    public String getFront()
    {
        if (isEmpty())
        {
            System.out.println("Queue is empty");
            return null;
        }
        return front.data;
    }

    @Override
    public String getBack()
    {
        if (isEmpty())
        {
            System.out.println("Queue is empty");
            return null;
        }
        return back.data;
    }

    @Override
    public boolean isEmpty()
    {
        return front == null;
    }

    @Override
    public void display()
    {
        if (isEmpty())
        {
            System.out.println("Queue is empty");
            return;
        }
        int counter = 0;
        Node temp = front;
        while (temp != null)
        {
            System.out.println("Element at index " + counter + ": " + temp.data);
            temp = temp.next;
            counter++;
        }
    }

}
