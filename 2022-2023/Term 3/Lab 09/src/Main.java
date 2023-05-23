public class Main
{
    private static void testDoubleEndedQueue()
    {
        DoubleEndedQueue queue = new DoubleEndedQueue();
        queue.enqueueFront("A");
        queue.enqueueFront("B");
        queue.enqueueBack("C");
        queue.enqueueBack("D");
        queue.enqueueFront("E");
        queue.display();
        System.out.println("Front: " + queue.getFront());
        System.out.println("Back: " + queue.getBack());
        System.out.println("Dequeue Front: " + queue.dequeueFront());
        System.out.println("Dequeue Back: " + queue.dequeueBack());
        System.out.println("Front: " + queue.getFront());
        System.out.println("Back: " + queue.getBack());
        queue.display();
    }

    public static void main(String[] args)
    {
        testDoubleEndedQueue();
    }
}
