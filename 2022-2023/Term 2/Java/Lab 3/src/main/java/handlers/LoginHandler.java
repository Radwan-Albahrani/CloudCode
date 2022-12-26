package main.java.handlers;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;

import javax.swing.JOptionPane;

import main.resources.models.User;

public class LoginHandler implements ActionListener
{
    User users[] = {
            new User("TestUser", "1234", "Radwan", "Albahrani", "2252"),
            new User("TestUser2", "12345", "Ahmad", "Ali", "2252"),
    };
    JTextField username;
    JPasswordField password;

    public LoginHandler(JTextField Username, JPasswordField Password)
    {
        username = Username;
        password = Password;
    }

    @Override
    public void actionPerformed(ActionEvent e)
    {
        String username = this.username.getText();
        String password = new String(this.password.getPassword());
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
                JOptionPane.showMessageDialog(null,
                        "Welcome " + currentUser.getFirstName() + " " + currentUser.getLastName(), "Welcome",
                        JOptionPane.INFORMATION_MESSAGE);
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
