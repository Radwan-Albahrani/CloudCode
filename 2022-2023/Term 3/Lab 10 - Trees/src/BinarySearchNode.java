public class BinarySearchNode
{
    private BinarySearchNode left;
    private BinarySearchNode right;
    private BinarySearchNode parent;
    private int data;

    public BinarySearchNode getLeft()
    {
        return left;
    }

    public void setLeft(BinarySearchNode left)
    {
        this.left = left;
    }

    public BinarySearchNode getRight()
    {
        return right;
    }

    public void setRight(BinarySearchNode right)
    {
        this.right = right;
    }

    public BinarySearchNode getParent()
    {
        return parent;
    }

    public void setParent(BinarySearchNode parent)
    {
        this.parent = parent;
    }

    public int getData()
    {
        return data;
    }

    public BinarySearchNode(BinarySearchNode left, BinarySearchNode right, BinarySearchNode parent, int data)
    {
        this.left = left;
        this.right = right;
        this.parent = parent;
        this.data = data;
    }

    public void setData(int data)
    {
        this.data = data;
    }
}