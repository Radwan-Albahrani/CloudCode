public class BinarySearchTree extends BinarySearchTreeAbstract
{
    BinarySearchNode root;

    public BinarySearchNode getRoot()
    {
        return root;
    }

    public BinarySearchTree()
    {
    }

    @Override
    public void insert(int value)
    {
        // Check if value already exists.
        if (find(value) != null)
        {
            System.out.println("Duplicate Found, Cannot insert");
            return;
        }

        // Start at the root. Get the current node
        BinarySearchNode current = root;

        // if current is null, new insert is the root.
        if (current == null)
        {
            BinarySearchNode node = new BinarySearchNode(null, null, null, value);
            root = node;
            return;
        }

        // Start looping through the tree
        while (true)
        {
            // If value is bigger than the current value
            if (value > current.getData())
            {
                // Save parent
                BinarySearchNode parent = current;

                // Go right
                current = current.getRight();

                // If right is empty
                if (current == null)
                {
                    // Make a node
                    BinarySearchNode node = new BinarySearchNode(null, null, parent, value);

                    // Insert the node
                    parent.setRight(node);
                    return;
                }
            }

            // If value is less than the current value
            else
            {
                // Save parent
                BinarySearchNode parent = current;

                // Go left
                current = current.getLeft();

                // If left is empty
                if (current == null)
                {
                    // Make a node
                    BinarySearchNode node = new BinarySearchNode(null, null, parent, value);

                    // Insert it at the left
                    parent.setLeft(node);
                    return;
                }
            }
        }

    }

    @Override
    public BinarySearchNode find(int value)
    {
        // Get root
        BinarySearchNode current = root;

        // Start searching the tree
        while (current != null)
        {
            if (current.getData() < value)
            {
                current = current.getRight();
            }
            else if (current.getData() == value)
            {
                return current;
            }
            else
            {
                current = current.getLeft();
            }
        }
        return null;
    }

    @Override
    public void preOrder(BinarySearchNode root)
    {
        if (root != null)
        {
            preOrder(root.getLeft());
            System.out.println(root.getData());
            preOrder(root.getRight());
        }
    }

    @Override
    public void inOrder(BinarySearchNode root)
    {
        if (root != null)
        {
            System.out.println(root.getData());
            inOrder(root.getLeft());
            inOrder(root.getRight());
        }
    }

    @Override
    public void postOrder(BinarySearchNode root)
    {
        if (root != null)
        {
            postOrder(root.getLeft());
            postOrder(root.getRight());
            System.out.println(root.getData());
        }
    }

    @Override
    public BinarySearchNode findMin(BinarySearchNode node)
    {
        if (node == null)
        {
            return null;
        }
        if (node.getLeft() == null)
        {
            return node;
        }
        return findMin(node.getLeft());

    }

    @Override
    public BinarySearchNode findMax(BinarySearchNode root)
    {
        if (root == null)
        {
            return null;
        }
        if (root.getRight() == null)
        {
            return root;
        }
        return findMax(root.getRight());
    }

    @Override
    public void deleteNode(int value)
    {
        // Case one, node is a leaf
        BinarySearchNode node = find(value);
        if (node.getLeft() == null && node.getRight() == null)
        {
            // If node is root
            if (node == root)
            {
                root = null;
                return;
            }

            // If node is left child
            if (node.getParent().getLeft() == node)
            {
                node.getParent().setLeft(null);
                return;
            }

            // If node is right child
            if (node.getParent().getRight() == node)
            {
                node.getParent().setRight(null);
                return;
            }
        }

        // Case two, node has one child
        if (node.getLeft() == null || node.getRight() == null)
        {
            // If node is root
            if (node == root)
            {
                if (node.getLeft() == null)
                {
                    root = node.getRight();
                    return;
                }
                else
                {
                    root = node.getLeft();
                    return;
                }
            }

            // If node is left child
            if (node.getParent().getLeft() == node)
            {
                if (node.getLeft() == null)
                {
                    node.getParent().setLeft(node.getRight());
                    return;
                }
                else
                {
                    node.getParent().setLeft(node.getLeft());
                    return;
                }
            }

            // If node is right child
            if (node.getParent().getRight() == node)
            {
                if (node.getLeft() == null)
                {
                    node.getParent().setRight(node.getRight());
                    return;
                }
                else
                {
                    node.getParent().setRight(node.getLeft());
                    return;
                }
            }
        }

        // Case three, node has two children
        if (node.getLeft() != null && node.getRight() != null)
        {
            // Find the minimum value in the right subtree
            BinarySearchNode min = findMin(node.getRight());

            // Replace the node with the minimum value
            node.setData(min.getData());

            // Delete the minimum value
            deleteNode(min.getData());
        }

    }

    @Override
    public int findDepth(BinarySearchNode node)
    {
        int depth = 0;
        while (node != root)
        {
            node = node.getParent();
            depth++;
        }
        return depth;
    }

    @Override
    public int findHeight(BinarySearchNode node)
    {
        if (node == null)
        {
            return -1;
        }
        return Math.max(findHeight(node.getLeft()), findHeight(node.getRight())) + 1;
    }

}