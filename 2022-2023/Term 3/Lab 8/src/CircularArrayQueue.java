public class CircularArrayQueue extends QueueAbstract
{
    int front, back, count, size;
    String[] queue;

    CircularArrayQueue(int size)
    {
        this.size = size;
        queue = new String[size];
    }

    @Override
    public void enqueue(String word)
    {
        if (isFull())
        {
            System.out.println("Queue is full");
            return;
        }
        queue[back++ % size] = word;
        count++;
    }

    @Override
    public String dequeue()
    {
        if (isEmpty())
        {
            System.out.println("No elements in queue");
        }
        count--;
        return queue[front++ % size];
    }

    @Override
    public String getFront()
    {
        if (isEmpty())
        {
            System.out.println("No elements in queue");
            return null;
        }
        return queue[front % size];
    }

    @Override
    public String getBack()
    {
        if (isEmpty())
        {
            System.out.println("No elements in queue");
            return null;
        }
        return queue[back % size];
    }

    @Override
    public boolean isFull()
    {
        if (count == size)
        {
            return true;
        }
        return false;
    }

    @Override
    public boolean isEmpty()
    {
        if (count == 0)
        {
            return true;
        }
        return false;
    }

    @Override
    public void display()
    {
        if (isEmpty())
        {
            System.out.println("Empty Queue");
            return;
        }

        int counter = 0;
        for (int i = front; i < back; i++)
        {
            System.out.println("Element in position " + ++counter + " is: " + queue[i % size]);
        }
    }

}
