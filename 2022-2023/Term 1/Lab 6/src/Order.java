public class Order
{
    public static int NumberOfOrders;

    private String orderName;
    private double orderPrice;

    // Constructor
    public Order(String orderName, double orderPrice)
    {
        this.orderName = orderName;
        this.orderPrice = orderPrice;
        NumberOfOrders++;
    }

    // Getters
    public String getOrderName()
    {
        return orderName;
    }

    public double getOrderPrice()
    {
        return orderPrice;
    }

    public static int getNumberOfOrders()
    {
        return NumberOfOrders;
    }

}
