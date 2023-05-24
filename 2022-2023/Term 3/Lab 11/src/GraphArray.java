import java.util.Hashtable;
import java.util.Map;

public class GraphArray implements GraphArrayAbstract
{

    private String[] vertices;
    private int[][] edges;

    private int numVertices;
    private int numEdges;

    public GraphArray(int capacity)
    {
        this.vertices = new String[capacity];
        this.edges = new int[capacity][capacity];
    }

    // Check if graph is empty
    @Override
    public boolean isEmptyVertex()
    {
        if (numVertices == 0)
        {
            return true;
        }
        return false;
    }

    @Override
    public boolean isEmptyEdge()
    {
        if (numEdges == 0)
        {
            return true;
        }
        return false;
    }

    // Check if graph is full
    @Override
    public boolean isFullVertex()
    {
        if (numVertices == vertices.length)
        {
            return true;
        }
        return false;
    }

    @Override
    public boolean isFullEdge()
    {
        if (numEdges == edges.length * edges.length)
        {
            return true;
        }
        return false;
    }

    @Override
    public int findVertex(String vertexName)
    {
        for (int i = 0; i < numVertices; i++)
        {
            if (vertices[i].equals(vertexName))
            {
                return i;
            }
        }
        return -1;
    }

    @Override
    public boolean addVertex(String vertexName)
    {
        if (isFullVertex())
        {
            System.out.println("Graph is full, Cannot add.");
            return false;
        }
        if (findVertex(vertexName) != -1)
        {
            System.out.println("Vertex already exists");
            return false;
        }
        vertices[numVertices++] = vertexName;
        System.out.println("Vertex Added Successfully");
        return true;
    }

    @Override
    public boolean deleteVertex(String vertexName)
    {
        if (isEmptyVertex())
        {
            System.out.println("Graph has no vertices.");
            return false;
        }
        int index = findVertex(vertexName);
        if (index == -1)
        {
            System.out.println("Vertex not found. Try again");
            return false;
        }

        for (int i = 0; i < edges.length; i++)
        {
            if (edges[index][i] != 0)
            {
                edges[index][i] = edges[index + 1][i];
                numEdges--;
            }
            if (edges[i][index] != 0)
            {
                edges[i][index] = edges[i][index + 1];
                numEdges--;
            }
        }

        for (int i = index; i < vertices.length; i++)
        {
            vertices[i] = vertices[i + 1];
        }
        numVertices--;
        return true;
    }

    @Override
    public boolean addEdge(String vertex1, String vertex2, int weight)
    {
        if (isFullEdge())
        {
            System.out.println("Cannot add any edge");
            return false;
        }
        int index1 = findVertex(vertex1);
        int index2 = findVertex(vertex2);
        if (edges[index1][index2] > 0)
        {
            System.out.println("Edge Already exists");
            return false;
        }
        edges[index1][index2] = weight;
        System.out.println("Edge Added Successfully");
        numEdges++;
        return true;
    }

    @Override
    public boolean deleteEdge(String vertex1, String vertex2)
    {
        if (isEmptyEdge())
        {
            System.out.println("No Edges found");
            return false;
        }
        int index1 = findVertex(vertex1);
        int index2 = findVertex(vertex2);
        if (edges[index1][index2] == 0)
        {
            System.out.println("Edge does not exist");
            return false;
        }
        edges[index1][index2] = 0;
        System.out.println("Edge Deleted Successfully");
        numEdges--;
        return true;
    }

    @Override
    public int inDegree(String vertex)
    {
        int index = findVertex(vertex);
        int inDegree = 0;
        for (int i = index; i < edges.length; i++)
        {
            if (edges[i][index] > 0)
            {
                inDegree++;
            }
        }
        return inDegree;

    }

    @Override
    public int outDegree(String vertex)
    {
        int index = findVertex(vertex);
        int outDegree = 0;
        for (int i = index; i < edges.length; i++)
        {
            if (edges[index][i] > 0)
            {
                outDegree++;
            }
        }
        return outDegree;
    }

    @Override
    public void display()
    {
        for (int i = 0; i < numVertices; i++)
        {
            System.out.println("Vertex: " + vertices[i]);
            System.out.println("Edges to: ");
            Map<String, Integer> edgesTo = new Hashtable<>();
            for (int j = 0; j < edges.length; j++)
            {
                if (edges[i][j] > 0)
                {
                    edgesTo.put(vertices[j], edges[i][j]);
                }
            }
            System.out.println(edgesTo.toString());
            edgesTo.clear();
        }
    }

}
