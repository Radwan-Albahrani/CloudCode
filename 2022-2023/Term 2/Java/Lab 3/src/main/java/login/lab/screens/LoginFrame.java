package login.lab.screens;

import java.awt.*;
import javax.swing.*;

import login.lab.handlers.LoginHandler;

public class LoginFrame extends JFrame
{
    public LoginFrame()
    {
        super("Online Banking System");
        setSize(350, 150);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new FlowLayout());
        JLabel userLabel = new JLabel("Username: ");
        JTextField userText = new JTextField(20);
        JLabel passwordLabel = new JLabel("Password: ");
        JPasswordField passwordText = new JPasswordField(20);
        JButton loginButton = new JButton("Login");
        loginButton.addActionListener(new LoginHandler(userText, passwordText, this));
        add(userLabel);
        add(userText);
        add(passwordLabel);
        add(passwordText);
        add(loginButton);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);
    }
}
