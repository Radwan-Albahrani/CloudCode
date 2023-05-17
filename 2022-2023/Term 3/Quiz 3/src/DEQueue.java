public class DEQueue
{
    private class Node
    {
        int data;
        Node next;
        Node prev;

        public Node(int data, DEQueue.Node next, DEQueue.Node prev)
        {
            this.data = data;
            this.next = next;
            this.prev = prev;
        }
    }

    Node front;
    Node rear;

    public DEQueue()
    {
        front = null;
        rear = null;
    }

    public void enqueueRear(int data)
    {
        Node newNode = new Node(data, null, null);

        if (front == null)
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear.next = newNode;
            newNode.prev = rear;
            rear = newNode;
        }
    }

    public int[] dequeueFrontTwice()
    {
        int[] arr = new int[2];

        if (front == null || front.next == null)
        {
            arr[0] = -1;
            arr[1] = -1;
        }
        else
        {
            arr[0] = front.data;
            arr[1] = front.next.data;
            front = front.next.next;
            front.prev = null;
        }

        return arr;
    }

    public void display()
    {
        Node temp = front;

        while (temp != null)
        {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
    }

    public static void main(String[] args)
    {
        DEQueue queue = new DEQueue();
        String universityID = "2200003819";
        for (int i = 0; i < universityID.length(); i++)
        {
            queue.enqueueRear(Integer.parseInt(String.valueOf(universityID.charAt(i))));
        }
        for (int i = 0; i < 3; i++)
        {
            int[] arr = queue.dequeueFrontTwice();
            System.out.println("Dequeuing front twice: " + arr[0] + " " + arr[1]);
        }
        System.out.println("The remaining elements in the queue are: ");
        queue.display();
    }
}
