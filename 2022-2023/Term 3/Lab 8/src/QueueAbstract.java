public abstract class QueueAbstract
{
    // Variables
    int front, back, count, size;

    // queue
    String queue[];

    // All abstract methods

    public abstract void enqueue(String word);

    public abstract String dequeue();

    public abstract String getFront();

    public abstract String getBack();

    public abstract boolean isFull();

    public abstract boolean isEmpty();

    public abstract void display();

}
