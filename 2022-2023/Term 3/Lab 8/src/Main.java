public class Main
{
    public static void main(String[] args)
    {
        TestLinearQueue();
        TestCircularQueue();
    }

    private static void TestLinearQueue()
    {
        LinearArrayQueue queue = new LinearArrayQueue(5);
        queue.enqueue("Hello");
        queue.enqueue("Hey");
        queue.enqueue("Whats up");
        queue.enqueue("Number 4");
        queue.enqueue("Number 5");

        queue.display();
        System.out.println("First element in queue: " + queue.dequeue());
        queue.display();
        queue.enqueue("Won't get in");
    }

    private static void TestCircularQueue()
    {
        CircularArrayQueue queue = new CircularArrayQueue(5);
        queue.enqueue("Hello");
        queue.enqueue("Hey");
        queue.enqueue("Whats up");
        queue.enqueue("Number 4");
        queue.enqueue("Number 5");

        System.out.println("======================== queued 5 items ========================");

        queue.display();
        System.out.println("======================== dequeuing 3 items ========================");
        for (int i = 0; i < 3; i++)
        {
            System.out.println("Dequeueing element: " + queue.dequeue());
        }
        queue.display();

        System.out.println("======================== queueing last item ========================");
        queue.enqueue("Won't get in");
        queue.display();
    }

}
