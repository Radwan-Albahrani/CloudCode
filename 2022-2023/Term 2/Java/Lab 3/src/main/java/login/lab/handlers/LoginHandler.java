package login.lab.handlers;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;

import javax.swing.JOptionPane;

import login.lab.models.*;
import login.lab.screens.*;

public class LoginHandler implements ActionListener
{
    User users[] = {
            new User("TestUser", "1234", "Radwan", "Albahrani", "2252"),
            new User("TestUser2", "12345", "Ahmad", "Ali", "2252"),
    };
    JTextField usernameField;
    JPasswordField passwordField;
    LoginFrame loginFrame;
    WelcomeScreen welcomeScreen;

    public LoginHandler(JTextField Username, JPasswordField Password, LoginFrame loginFrame)
    {
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
}
