public class Main
{
    public static void main(String[] args)
    {
        GraphArray graph = new GraphArray(3);
        graph.addVertex("A");
        graph.addVertex("B");
        graph.addVertex("A");
        graph.addEdge("A", "B", 3);
        System.out.println("InDegree of A is: " + graph.inDegree("A"));
        System.out.println("outDegree of A is: " + graph.outDegree("A"));
        graph.addEdge("A", "A", 5);
        graph.display();
        graph.deleteEdge("B", "A");
    }

}
