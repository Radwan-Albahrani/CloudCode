public class Test
{
    public static void main(String[] args)
    {
        // Creating 2 rectangles as specified
        Rectangle rec1 = new Rectangle(40, 4);
        Rectangle rec2 = new Rectangle(39.5, 3.5);

        // Stats for first rectangle
        System.out.println("Rectangle 1: ");
        System.out.printf("\tWidth: %.2f\n", rec1.getWidth());
        System.out.printf("\tHeight: %.2f\n", rec1.getHeight());
        System.out.printf("\tArea: %.2f\n", rec1.getArea());
        System.out.printf("\tParameter: %.2f\n", rec1.getParameter());

        // Stats for second rectangle
        System.out.println("Rectangle 2: ");
        System.out.printf("\tWidth: %.2f\n", rec2.getWidth());
        System.out.printf("\tHeight: %.2f\n", rec2.getHeight());
        System.out.printf("\tArea: %.2f\n", rec2.getArea());
        System.out.printf("\tParameter: %.2f\n", rec2.getParameter());
    }
}
