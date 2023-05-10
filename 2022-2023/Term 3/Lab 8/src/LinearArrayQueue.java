public class LinearArrayQueue extends QueueAbstract
{
    // Variables
    int front, back, count, size;

    // Queue
    String[] queue;

    // ================================ Constructor ================================
    LinearArrayQueue(int size)
    {
        queue = new String[size];
        this.size = size;
    }

    // add element to back of queue
    public void enqueue(String word)
    {
        if (isFull())
        {
            System.out.println("Queue is full");
            return;

        }
        queue[back++] = word;
        count++;

    }

    // remove element from front of queue
    public String dequeue()
    {
        if (isEmpty())
        {
            System.out.println("Queue is Empty");
            return null;

        }
        count--;
        return queue[front++];

    }

    // check if is full.
    public boolean isFull()
    {
        if (count == size || back == size)
        {
            return true;
        }
        return false;
    }

    // check if empty
    public boolean isEmpty()
    {
        if (count == 0 && back != size)
        {
            return true;
        }
        return false;
    }

    // display queue
    public void display()
    {
        for (int i = front; i < back; i++)
        {
            System.out.println("Item " + i + ": " + queue[i]);
        }
    }

    @Override
    public String getFront()
    {
        if (isEmpty())
        {
            System.out.println("empty queue");
            return null;
        }
        return queue[front];
    }

    @Override
    public String getBack()
    {
        if (isEmpty())
        {
            System.out.println("empty queue");
            return null;
        }
        return queue[back];
    }
}
