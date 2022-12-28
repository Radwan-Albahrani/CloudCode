package login.lab.screens;

import java.awt.*;

import javax.swing.*;

public class WelcomeScreen extends JFrame
{
    public WelcomeScreen(String name)
    {
        super("Welcome Screen");
        setSize(350, 150);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new FlowLayout());
        JLabel welcomeLabel = new JLabel("Welcome " + name);
        add(welcomeLabel);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);
    }
}
