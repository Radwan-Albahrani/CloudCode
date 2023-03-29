import java.lang.reflect.Field;
import java.util.ArrayList;
import java.util.List;

public class DoubleCircularLinkedList<E>
{
    private class Node
    {
        private E data;

        private Node next;
        private Node previous;

        // ========================== Constructor ==========================
        public Node(E data, Node next, Node previous)
        {
            this.data = data;
            this.next = next;
            this.previous = previous;
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
                Node newNode = new Node(value, null, null);
                head = tail = newNode;
                tail.next = head;
                head.previous = tail;
            }
            else
            {
                Node newNode = new Node(value, head, tail);
                head.previous = newNode;
                head = newNode;
                tail.next = head;
            }
            size++;
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
                Node newNode = new Node(value, null, null);
                head = tail = newNode;
                tail.next = head;
                head.previous = tail;
                return 1;
            }
            else
            {
                Node newNode = new Node(value, head, tail);
                tail.next = newNode;
                tail = newNode;
            }
            size++;
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
                return 1;
            }
            else if (position == size)
            {
                addLast(value);
                return 1;
            }
            else
            {
                Node newNode = new Node(value, null, null);
                Node temp = head;
                for (int i = 1; i < position - 1; i++)
                {
                    temp = temp.next;
                }
                newNode.next = temp.next;
                newNode.previous = temp;
                temp.next.previous = newNode;
                temp.next = newNode;
            }
            size++;
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
                head.previous = tail;
                tail.next = head;
            }
            size--;
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
                tail = tail.previous;
                tail.next = head;
                head.previous = tail;
            }
            size--;
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
                temp.next.previous = temp;
            }
            size--;
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
            do
            {
                E data = temp.data;
                if ((data.getClass() instanceof Class) == false)
                {
                    Field[] fields = data.getClass().getDeclaredFields();
                    for (Field field : fields)
                    {
                        field.setAccessible(true);
                        if (field.get(data).equals(value))
                        {
                            return data;
                        }
                    }
                }
                else
                {
                    if (data.equals(value))
                    {
                        return data;
                    }
                }

                temp = temp.next;
            } while (temp != head);

            return null;
        }
        catch (Exception e)
        {
            System.out.println("Exception: " + e.getMessage());
            return null;
        }
    }

    public void displayForward()
    {
        Node temp = head;
        if (isEmpty())
        {
            System.out.println("List is empty.");
            return;
        }
        do
        {
            System.out.println("\n---------------------------------------------------------------");
            System.out.print(temp.data.toString());
            temp = temp.next;
        } while (temp != head);

        System.out.println("\n---------------------------------------------------------------");
        System.out.println();
    }

    public void displayBackward()
    {
        Node temp = tail;
        if (isEmpty())
        {
            System.out.println("List is empty.");
            return;
        }
        do
        {
            System.out.println("\n---------------------------------------------------------------");
            System.out.print(temp.data.toString());
            temp = temp.previous;
        } while (temp != tail);

        System.out.println("\n---------------------------------------------------------------");
        System.out.println();
    }

    public void findDuplicate(Object value)
    {
        try
        {
            if (isEmpty())
            {
                throw new Exception("List is empty.");
            }

            Node temp = head;
            List<E> list = new ArrayList<>();
            do
            {
                E data = temp.data;
                if ((data.getClass() instanceof Class) == false)
                {
                    Field[] fields = data.getClass().getDeclaredFields();
                    for (Field field : fields)
                    {
                        field.setAccessible(true);
                        if (field.get(data).equals(value))
                        {
                            list.add(data);
                        }
                    }
                }
                else
                {
                    if (data.equals(value))
                    {
                        list.add(data);
                    }
                }

                temp = temp.next;
            } while (temp != head);

            if (list.isEmpty())
            {
                System.out.println("No duplicate found.");
            }
            else
            {
                System.out.println("Duplicate found: " + list.size());
                System.out.println("\n---------------------------------------------------------------");
                for (E e : list)
                {
                    System.out.println(e.toString());
                    System.out.println("\n---------------------------------------------------------------");
                }
            }
        }
        catch (Exception e)
        {
            System.out.println("Exception: " + e.getMessage());
        }
    }

    public void rotate()
    {
        if (isEmpty())
        {
            System.out.println("List is empty.");
            return;
        }
        head = head.next;
        tail = tail.next;
    }

    public static void testCourse()
    {
        DoubleCircularLinkedList<Course> list = new DoubleCircularLinkedList<>();
        list.addFirst(new Course(111, "Math", 3, "Majid"));
        list.addFirst(new Course(222, "Physics", 3, "Majid"));
        list.addFirst(new Course(555, "Chemistry", 3, "Majid"));
        list.addFirst(new Course(444, "Biology", 3, "Majid"));
        list.addFirst(new Course(555, "English", 3, "Majid"));
        list.addFirst(new Course(111, "Computer", 3, "Majid"));
        list.findDuplicate("Majid");

        System.out.println("List after adding elements (forward): ");
        list.displayForward();
        System.out.println("List after adding elements (backward): ");
        list.displayBackward();

        System.out.println("Size: " + list.size);
        list.removeFirst();

        System.out.println("List after removing first element (forward): ");
        list.displayForward();
        System.out.println("List after removing first element (backward): ");
        list.displayBackward();

        System.out.println("Size: " + list.size);
        System.out.println("Is list empty: " + list.isEmpty());
        list.removeLast();

        System.out.println("List after removing last element (forward): ");
        list.displayForward();
        System.out.println("List after removing last element (backward): ");
        list.displayBackward();

        System.out.println("Size: " + list.size);
        System.out.println("Is list empty: " + list.isEmpty());
        list.removeAtPosition(2);

        System.out.println("List after removing element at position 2 (forward): ");
        list.displayForward();
        System.out.println("List after removing element at position 2 (backward): ");
        list.displayBackward();

        System.out.println("Size: " + list.size);

        list.findDuplicate(555);
    }

    public static void testNormal()
    {
        DoubleCircularLinkedList<Object> list = new DoubleCircularLinkedList<>();
        list.addFirst("Majid");
        list.addFirst("Halim");
        list.addFirst("Yahya");
        list.addFirst("Majid");
        list.addFirst(111);
    }

    public static void main(String[] args)
    {
        testCourse();
        testNormal();
    }
}