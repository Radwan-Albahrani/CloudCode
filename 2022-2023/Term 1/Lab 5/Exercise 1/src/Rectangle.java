public class Rectangle
{
    // Width and height of class
    private double height;
    private double width;

    public double getHeight()
    {
        return height;
    }

    public double getWidth()
    {
        return width;
    }

    // Default constructor
    public Rectangle()
    {
        height = 1;
        width = 1;
    }

    // Constructor for class with arguments
    public Rectangle(double height, double width)
    {
        this.height = height;
        this.width = width;
    }

    public double getArea()
    {
        return this.height * this.width;
    }

    public double getParameter()
    {
        return (this.height * 2) + (this.width * 2);
    }

}
