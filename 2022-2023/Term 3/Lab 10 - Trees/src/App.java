public class App
{
    public static void main(String[] args) throws Exception
    {
        // Test the BinarySearchTree class
        BinarySearchTree bst = new BinarySearchTree();
        bst.insert(10);
        bst.insert(5);
        bst.insert(15);
        bst.insert(3);
        bst.insert(7);
        bst.insert(13);
        bst.insert(17);
        bst.insert(1);

        System.out.println("InOrder Traversal");
        bst.inOrder(bst.getRoot());

        System.out.println("PreOrder Traversal");
        bst.preOrder(bst.getRoot());

        System.out.println("PostOrder Traversal");
        bst.postOrder(bst.getRoot());

        System.out.println("Find Min");
        System.out.println(bst.findMin(bst.getRoot()).getData());

        System.out.println("Find Max");
        System.out.println(bst.findMax(bst.getRoot()).getData());

        System.out.println("Find 13");
        System.out.println(bst.find(13).getData());

        System.out.println("Find 20");
        System.out.println(bst.find(20));

        System.out.println("Delete 13");
        bst.deleteNode(13);

        System.out.println("InOrder Traversal");
        bst.inOrder(bst.getRoot());

        System.out.println("Find Height");
        System.out.println(bst.findHeight(bst.getRoot()));

        System.out.println("Find depth of 5");
        BinarySearchNode node = bst.find(5);
        System.out.println(bst.findDepth(node));

    }
}
