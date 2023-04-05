
/**
 *
 * @author nmaIbrahim
 */

/**
 * License part
 * Imam Abdulrahman University, College of Computer Science and Information Technology
 * This file for lab quiz-1, CS310 data structure course, third semester 2022/2023
 * Prepared by the Instructor: Dr. Nehad Mohamed Ibrahim
 * Description Part
 * This class to manage a circular linked list class that has the following rules:
 * 1. The linked list can add a node by adding to the first or to the last.
 * 2. Can not accept to add more than five nodes
 * 3. All values must be integers only
 * 4. All values must be odd numbers
 * 5. The linked list can remove node by remove from the first or from the last
 * 6. The linked list can be locked by method lock() and unlocked by method unlock()
 * 7. Locked meaning that, you can not add to or remove from the linked list until calling unlocking by unlock()
 * 8. The linked list by default is unlocked.
 */

public class CircularLL3
{
    private Node head = null;
    private Node tail = null;
    private int size = 0;
    private final int MAX_SIZE = 5;
    private boolean lock = false;

    private class Node
    {

        int data;
        Node next;

        public Node(int data, Node next)
        {
            this.data = data;
            this.next = next;
        }

        public void setData(int data)
        {
            this.data = data;
        }

        public void setNext(Node next)
        {
            this.next = next;
        }

        public int getData()
        {
            return data;
        }

        public Node getNext()
        {
            return next;
        }
    }

    public CircularLL3()
    {
    }

    private void lock(boolean bLock)
    {
        lock = bLock;
    }

    private boolean isLocked()
    {
        return lock;
    }

    // Access Methods
    public int size()
    {
        return size;
    }

    public boolean isEmpty()
    {
        return size == 0;
    }

    public void display()
    {
        if (isEmpty())
        {
            System.out.println("Empty List..");
        }
        Node current = head;
        int i = 1;
        do
        {
            System.out.println("Node " + (i++) + ": " + current.getData());
            current = current.getNext();
        } while (current != head);
    }

    public void find(int value)
    {
        if (isEmpty())
        {
            System.out.println("Empty List..");
            return;
        }
        int counter = 1;
        boolean flag = false;
        Node current = head;
        do
        {
            if (current.getData() == value)
            {
                flag = true;
                System.out.println("Found in Node# " + counter);
                break;
            }
            counter++;
            current = current.getNext();
        } while (current != head);
        if (flag == false)
        {
            System.out.println("No record found");
        }

    }

    void deleteFirst()
    {
        if (isLocked())
        {
            System.out.println("\nThe linked list is locked, you must remove the locking before deleting.");
            return;
        }
        if (isEmpty())
        {
            System.out.println("Empty list");
            return;
        }
        head = head.getNext();
        tail.setNext(head);
        size--;
        // if this was the last and only node.. fix tail
        if (size == 0)
        {
            head = null;
            tail = null;
        }
        System.out.println("\nThe head value successfully removed.");
    }

    public void deleteElement(int value)
    {
        if (isLocked())
        {
            System.out.println("\nThe linked list is locked, you must remove the locking before deleting.");
            return;
        }

        if (isEmpty())
        {
            System.out.println("Empty List..");
            return;
        }

        if (head.getData() == value)
        {
            deleteFirst();
            return;
        }
        Node current = head;
        Node previous = head;

        while (current.getData() != value)
        {
            if (current.next == head)
            {
                System.out.println("No record found");
                return;
            }
            else
            {
                previous = current;
                current = current.getNext();
            }
        }
        if (previous.getNext() == tail)
        {
            tail = previous;
        }
        previous.setNext(current.getNext());
        size--;

    }

    // Q-1 Implement the following method
    public void addFirst(int value)
    {
        if (isLocked())
        {
            System.out.println("\nThe linked list is locked, you must remove the locking before adding.");
            return;
        }
        if (size == MAX_SIZE)
        {
            System.out.println("\nThe linked list cannot accept more than five nodes.");
            return;
        }
        if (value % 2 == 0)
        {
            System.out.printf("\nThe linked list cannot accept even values(%d).\n", value);
            return;
        }
        Node newNode = new Node(value, null);
        if (isEmpty())
        {
            head = newNode;
            tail = newNode;
            newNode.setNext(head);
            size++;
        }
        else
        {
            newNode.setNext(head);
            head = newNode;
            tail.setNext(head);
            size++;
        }
    }

    // Q-2 Implement the following method
    public static int calculateFactorial(int n)
    {
        if (n == 0)
            return 1;
        else
            return n * calculateFactorial(n - 1);
    }

    public static void main(String[] args)
    {
        // Test for Q-1
        CircularLL3 list = new CircularLL3();
        for (int i = 1; i < 11; i++)
            list.addFirst(i);

        list.display();
        list.lock(true);
        list.deleteFirst();
        list.addFirst(11);
        list.lock(false);
        list.deleteFirst();
        list.addFirst(11);
        list.display();
        ///////////////////////////////////////
        // Test for Q-2
        int n = 5;
        int factorial = calculateFactorial(n);
        System.out.println(n + "! = " + factorial);
    }
}