package main.java.components;

import java.awt.*;
import javax.swing.*;

import main.java.handlers.LoginHandler;

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
        loginButton.addActionListener(new LoginHandler(userText, passwordText));
        add(userLabel);
        add(userText);
        add(passwordLabel);
        add(passwordText);
        add(loginButton);
        setVisible(true);
    }
}
