import java.lang.reflect.Field;

public class SingleLinkedList<E>
{
    private class Node
    {
        private E data;

        private Node next;

        // ========================== Constructor ==========================
        public Node(E data, Node next)
        {
            this.data = data;
            this.next = next;
        }
    }

    Node head = null;
    Node tail = null;
    int size = 0;

    public boolean isEmpty()
    {
        if (head == null && tail == null && size == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    public int addFirst(E value)
    {
        try
        {
            if (value == null)
            {
                throw new Exception("Adding a null value to the list is not allowed.");
            }

            if (isEmpty())
            {
                Node newNode = new Node(value, null);
                head = tail = newNode;
                return 1;
            }
            else
            {
                Node newNode = new Node(value, head);
                head = newNode;
            }
            return 1;
        }
        catch (Exception e)
        {
            System.out.println("Exception: " + e.getMessage());
            return 0;
        }
    }

    public int addLast(E value)
    {
        try
        {
            if (value == null)
            {
                throw new Exception("Adding a null value to the list is not allowed.");
            }

            if (isEmpty())
            {
                Node newNode = new Node(value, null);
                head = tail = newNode;
                return 1;
            }
            else
            {
                Node newNode = new Node(value, null);
                tail.next = newNode;
                tail = newNode;
            }
            return 1;
        }
        catch (Exception e)
        {
            System.out.println("Exception: " + e.getMessage());
            return 0;
        }
    }

    public int addAtPosition(E value, int position)
    {
        try
        {
            if (value == null)
            {
                throw new Exception("Adding a null value to the list is not allowed.");
            }

            if (position == 0)
            {
                throw new Exception("Position cannot be 0.");
            }

            if (position == 1)
            {
                addFirst(value);
            }
            else if (position == size)
            {
                addLast(value);
            }
            else
            {
                Node newNode = new Node(value, null);
                Node temp = head;
                for (int i = 1; i < position - 1; i++)
                {
                    temp = temp.next;
                }
                newNode.next = temp.next;
                temp.next = newNode;
            }
            return 1;
        }
        catch (Exception e)
        {
            System.out.println("Exception: " + e.getMessage());
            return 0;
        }
    }

    public int removeFirst()
    {
        try
        {
            if (isEmpty())
            {
                throw new Exception("List is empty.");
            }

            if (head == tail)
            {
                head = tail = null;
            }
            else
            {
                head = head.next;
            }
            return 1;
        }
        catch (Exception e)
        {
            System.out.println("Exception: " + e.getMessage());
            return 0;
        }
    }

    public int removeLast()
    {
        try
        {
            if (isEmpty())
            {
                throw new Exception("List is empty.");
            }

            if (head == tail)
            {
                head = tail = null;
            }
            else
            {
                Node temp = head;
                while (temp.next != tail)
                {
                    temp = temp.next;
                }
                temp.next = null;
                tail = temp;
            }
            return 1;
        }
        catch (Exception e)
        {
            System.out.println("Exception: " + e.getMessage());
            return 0;
        }
    }

    public int removeAtPosition(int position)
    {
        try
        {
            if (isEmpty())
            {
                throw new Exception("List is empty.");
            }

            if (position == 0)
            {
                throw new Exception("Position cannot be 0.");
            }

            if (position == 1)
            {
                removeFirst();
            }
            else if (position == size)
            {
                removeLast();
            }
            else
            {
                Node temp = head;
                for (int i = 1; i < position - 1; i++)
                {
                    temp = temp.next;
                }
                temp.next = temp.next.next;
            }
            return 1;
        }
        catch (Exception e)
        {
            System.out.println("Exception: " + e.getMessage());
            return 0;
        }
    }

    public E findNode(Object value)
    {
        try
        {
            if (isEmpty())
            {
                throw new Exception("List is empty.");
            }

            Node temp = head;
            while (temp != null)
            {
                E data = temp.data;
                Field[] fields = data.getClass().getDeclaredFields();
                for (Field field : fields)
                {
                    field.setAccessible(true);
                    if (field.get(data).equals(value))
                    {
                        return data;
                    }
                }
                temp = temp.next;
            }
            return null;
        }
        catch (Exception e)
        {
            System.out.println("Exception: " + e.getMessage());
            return null;
        }
    }

    public void printList()
    {
        Node temp = head;
        while (temp != null)
        {
            System.out.println("\n---------------------------------------------------------------");
            System.out.print(temp.data.toString());
            temp = temp.next;
        }
        System.out.println("\n---------------------------------------------------------------");
        System.out.println();
    }

    public static void main(String[] args)
    {
        SingleLinkedList<Course> list = new SingleLinkedList<Course>();
        list.addFirst(new Course(111, "Math", 4, "Me"));
        list.addFirst(new Course(222, "Science", 1, "Me"));
        list.addFirst(new Course(333, "English", 2, "Me"));
        list.addFirst(new Course(444, "History", 3, "Me"));

        System.out.println("List after adding 4 courses at the beginning:");
        list.printList();
        list.removeAtPosition(2);
        System.out.println("List after removing the course at position 2:");
        list.printList();
        Course found = list.findNode("Math");
        if (found != null)
        {
            System.out.println("----------------------------------------");
            System.out.println("Course found: \n" + found.toString());
            System.out.println("----------------------------------------");
        }
        else
        {
            System.out.println("Course not found.");
        }
    }
}