interface GraphArrayAbstract
{

    // Methods
    public abstract boolean isEmptyVertex();

    public abstract boolean isEmptyEdge();

    public abstract boolean isFullVertex();

    public abstract boolean isFullEdge();

    public abstract int findVertex(String vertexName);

    public abstract boolean addVertex(String vertexName);

    public abstract boolean deleteVertex(String vertexName);

    public abstract boolean addEdge(String vertex1, String vertex2, int weight);

    public abstract boolean deleteEdge(String vertex1, String vertex2);

    public abstract int inDegree(String vertex);

    public abstract int outDegree(String vertex);

    public abstract void display();

}