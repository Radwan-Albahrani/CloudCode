package login.lab.handlers;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;

import login.lab.models.*;
import login.lab.screens.*;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

import java.util.ArrayList;
import java.util.List;

public class LoginHandler implements ActionListener
{
    // Read users from resources
    private List<User> users = new ArrayList<User>();

    JTextField usernameField;
    JPasswordField passwordField;
    LoginFrame loginFrame;
    WelcomeScreen welcomeScreen;

    public LoginHandler(JTextField Username, JPasswordField Password, LoginFrame loginFrame)
    {
        readUsers();
        this.usernameField = Username;
        this.passwordField = Password;
        this.loginFrame = loginFrame;
    }

    @Override
    public void actionPerformed(ActionEvent e)
    {
        String username = this.usernameField.getText();
        String password = new String(this.passwordField.getPassword());
        User currentUser = null;
        for (User user : users)
        {
            if (user.getUsername().equals(username) && user.getPassword().equals(password))
            {
                currentUser = user;
                break;
            }
        }
        // Show input dialog to check the second password
        if (currentUser != null)
        {
            String secondPassword = JOptionPane.showInputDialog(null, "Enter your second password: ", "Second Password",
                    JOptionPane.QUESTION_MESSAGE);
            if (secondPassword.equals(currentUser.getSecondPassword()))
            {
                // Show welcome screen
                this.loginFrame.dispose();
                this.welcomeScreen = new WelcomeScreen(currentUser.getFirstName() + " " + currentUser.getLastName());
            }
            else
            {
                // Show warning dialog
                JOptionPane.showMessageDialog(null, "Wrong second password!", "Warning", JOptionPane.WARNING_MESSAGE);
            }
        }
        else
        {
            JOptionPane.showMessageDialog(null, "Wrong username or password!", "Authentication Error",
                    JOptionPane.ERROR_MESSAGE);
        }
    }

    private void readUsers()
    {
        try
        {
            File file = new File("src/main/resources/users.txt");
            Scanner scanner = new Scanner(file);
            while (scanner.hasNextLine())
            {
                String line = scanner.nextLine();
                String[] data = line.split(",");
                User user = new User(data[0].trim(), data[1].trim(), data[2].trim(), data[3].trim(), data[4].trim());
                users.add(user);
            }
            scanner.close();
        }
        catch (FileNotFoundException e)
        {
            e.printStackTrace();
        }
    }
}
