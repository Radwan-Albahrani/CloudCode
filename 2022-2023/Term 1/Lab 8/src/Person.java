public class Person
{
    private String name, address;

    // Setters
    public void setName(String name)
    {
        this.name = name;
    }

    public void setAddress(String address)
    {
        this.address = address;
    }

    // Getters
    public String getName()
    {
        return name;
    }

    public String getAddress()
    {
        return address;
    }

    // Constructor
    public Person(String name, String address)
    {
        this.name = name;
        this.address = address;
    }

    // Print information
    @Override
    public String toString()
    {
        return "\tName: " + this.getName() + "\n\tAddress: " + this.getAddress() + "\n";
    }

}
