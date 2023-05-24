
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import static java.lang.Integer.max;

/**
 * @author nmaIbrahim
 */
public class TreeFormA
{

    class BinaryTreeNode
    {

        private int value;
        private BinaryTreeNode leftChild;
        private BinaryTreeNode rightChild;
        private BinaryTreeNode parent;

        public BinaryTreeNode(int value, BinaryTreeNode leftChild,
                BinaryTreeNode rightChild, BinaryTreeNode parent)
        {
            this.value = value;
            this.leftChild = leftChild;
            this.rightChild = rightChild;
            this.parent = parent;
        }

        // Setters and Getters
        public int getValue()
        {
            return value;
        }

        public BinaryTreeNode getLeftChild()
        {
            return leftChild;
        }

        public BinaryTreeNode getRightChild()
        {
            return rightChild;
        }

        public BinaryTreeNode getParent()
        {
            return parent;
        }

        public void setValue(int value)
        {
            this.value = value;
        }

        public void setLeftChild(BinaryTreeNode leftChild)
        {
            this.leftChild = leftChild;
        }

        public void setRightChild(BinaryTreeNode rightChild)
        {
            this.rightChild = rightChild;
        }

        public void setParent(BinaryTreeNode parent)
        {
            this.parent = parent;
        }

    }

    private BinaryTreeNode root; // root of BST
    private int size; // number of nodes in BST

    TreeFormA()
    {
        root = null;
        size = 0;
    }

    BinaryTreeNode getRoot()
    {
        return root;
    }

    int getSize()
    {
        return size;
    }

    boolean isEmpty()
    {
        return (size == 0);
    }

    void insert(int keyVal)
    {
        BinaryTreeNode newNode = new BinaryTreeNode(keyVal, null, null, null);
        if (isEmpty())
        {
            root = newNode;
            size++;
            return;
        }
        BinaryTreeNode current = root;
        BinaryTreeNode parent;
        while (true)
        {
            parent = current;
            if (keyVal == current.value)
            {
                System.out.println("Duplicate Found");
                return;
            }
            else if (keyVal < current.value)
            {
                current = current.leftChild;
                if (current == null)
                {
                    parent.leftChild = newNode;
                    break;
                }
            }
            else
            {
                current = current.rightChild;
                if (current == null)
                {
                    parent.rightChild = newNode;
                    break;
                }
            }
        } // end loop
        newNode.parent = parent;
        size++;
    }

    BinaryTreeNode find(BinaryTreeNode node, int keyVal)
    {
        if (node == null)
        {
            System.out.println("Searching fail");
            return null;
        }
        if (node.value == keyVal)
        {
            return node; // found
        }
        if (keyVal < node.value)
        {
            return find(node.leftChild, keyVal);
        }
        else
        {
            return find(node.rightChild, keyVal);
        }
    }

    // Answer
    // Traversal Methods: InOrder, PostOrder, PreOrder
    void inOrderTraversal(BinaryTreeNode node)
    {
        if (node != null)
        {
            inOrderTraversal(node.leftChild);
            // if(node.value % 2 != 0)
            System.out.println(node.value);
            inOrderTraversal(node.rightChild);
        }
    }

    void postOrderTraversal(BinaryTreeNode node)
    {
        if (node != null)
        {
            postOrderTraversal(node.leftChild);
            postOrderTraversal(node.rightChild);
            // if(node.value % 2 == 0)
            System.out.println(node.value);
        }
    }

    BinaryTreeNode findMax(BinaryTreeNode node)
    {
        if (isEmpty())
        {
            return null;
        }
        if (node.rightChild == null)
            return node;
        else
            return findMax(node.rightChild);

    }

    int Depth(BinaryTreeNode node)
    {
        if (node.parent == null)
            return 0;
        return Depth(node.parent) + 1;
    }

    public static int getX(BinaryTreeNode bt)
    {
        if (bt == null)
            return 0;
        return 1 + max(getX(bt.leftChild), getX(bt.rightChild));
    }

    public static void main(String[] args)
    {
        TreeFormA bst = new TreeFormA();
        // add (10, 20, 30, 11, 12, 13, 40)
        bst.insert(10);
        bst.insert(20);
        bst.insert(30);
        bst.insert(11);
        bst.insert(12);
        bst.insert(13);
        bst.insert(40);
        bst.inOrderTraversal(bst.getRoot());
        int result = bst.Depth(bst.find(bst.getRoot(), 40));
        System.out.println(result);
        bst.postOrderTraversal(bst.getRoot());
    }

}
