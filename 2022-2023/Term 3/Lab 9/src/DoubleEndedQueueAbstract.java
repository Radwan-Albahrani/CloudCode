public abstract class DoubleEndedQueueAbstract
{
    // Variables
    int front, back, count, size;

    // queue
    String queue[];

    // All abstract methods

    public abstract void enqueueFront(String word);

    public abstract void enqueueBack(String word);

    public abstract String dequeueFront();

    public abstract String dequeueBack();

    public abstract String getFront();

    public abstract String getBack();

    public abstract boolean isEmpty();

    public abstract void display();

}
