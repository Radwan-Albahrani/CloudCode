public abstract class BinarySearchTreeAbstract
{
    BinarySearchNode root;

    public abstract void insert(int value);

    public abstract BinarySearchNode find(int value);

    public abstract void preOrder(BinarySearchNode root);

    public abstract void inOrder(BinarySearchNode root);

    public abstract void postOrder(BinarySearchNode root);

    public abstract BinarySearchNode findMin(BinarySearchNode root);

    public abstract BinarySearchNode findMax(BinarySearchNode root);

    public abstract void deleteNode(int value);

    public abstract int findDepth(BinarySearchNode node);

    public abstract int findHeight(BinarySearchNode node);

}
