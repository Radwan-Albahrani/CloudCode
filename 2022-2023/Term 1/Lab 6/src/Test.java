public class Test
{
    public static void main(String[] args)
    {
        // Create array of orders with 2 orders
        Order orders[] = new Order[2];
        // Fill it with Specified values
        orders[0] = new Order("Rice", 30);
        orders[1] = new Order("Pasta", 40);

        // Print out orders
        for (int i = 0; i < orders.length; i++)
        {
            System.out.printf("Order number %d\n\tName: %s\n\tPrice: %.2f\n", i + 1, orders[i].getOrderName(), orders[i].getOrderPrice());
        }

        // Print out bill and total orders
        System.out.printf("Total orders: %d\n Total Bill: %.2f\n", Order.NumberOfOrders, Bill.getBill(orders));

    }
}
