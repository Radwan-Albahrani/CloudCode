public class Bill
{
    // Calculate the bill
    public static double getBill(Order orders[])
    {
        double sum = 0;
        for (Order order : orders) {
            sum += order.getOrderPrice();
        }

        return sum;
    }
}
