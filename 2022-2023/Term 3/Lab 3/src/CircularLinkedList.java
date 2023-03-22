import java.lang.reflect.Field;

public class CircularLinkedList<E>
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
                tail.next = head;
                return 1;
            }
            else
            {
                Node newNode = new Node(value, head);
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
                Node newNode = new Node(value, null);
                head = tail = newNode;
                return 1;
            }
            else
            {
                Node newNode = new Node(value, null);
                tail.next = newNode;
                tail = newNode;
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
                Node temp = head;
                while (temp.next != tail)
                {
                    temp = temp.next;
                }
                temp.next = null;
                tail = temp;
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
                if (data instanceof Class)
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

    public void printList()
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

    public static void main(String[] args)
    {
        CircularLinkedList<Object> list = new CircularLinkedList<>();
        list.addFirst("Hello");
        list.addFirst("World");
        list.addLast("!");
        list.addAtPosition("Hey", 2);
        list.addAtPosition("Hi", 1);
        System.out.println("List after adding elements: ");
        list.printList();
        System.out.println("Size: " + list.size);
        System.out.println("Is list empty: " + list.isEmpty());
        System.out.println("Find node with roll number 10: " + list.findNode("Hello"));
        list.removeFirst();
        list.printList();
        System.out.println("Size: " + list.size);
        System.out.println("Is list empty: " + list.isEmpty());
        list.removeLast();
        list.printList();
        System.out.println("Size: " + list.size);
        System.out.println("Is list empty: " + list.isEmpty());
        list.removeAtPosition(1);
        list.printList();
        System.out.println("Size: " + list.size);
    }
}