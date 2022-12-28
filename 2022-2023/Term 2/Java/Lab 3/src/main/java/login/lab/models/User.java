package login.lab.models;

public class User
{
    private String username, password, firstName, lastName, secondPassword;

    public String getUsername()
    {
        return username;
    }

    public String getPassword()
    {
        return password;
    }

    public String getFirstName()
    {
        return firstName;
    }

    public String getLastName()
    {
        return lastName;
    }

    public String getSecondPassword()
    {
        return secondPassword;
    }

    public User(String username, String password, String firstName, String lastName, String secondPassword)
    {
        this.username = username;
        this.password = password;
        this.firstName = firstName;
        this.lastName = lastName;
        this.secondPassword = secondPassword;
    }

}
