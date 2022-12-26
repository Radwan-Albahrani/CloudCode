package main.java;

import javax.swing.JFrame;

import main.java.components.LoginFrame;

public class Main
{
    public static void main(String[] args)
    {
        LoginFrame myLoginFrame = new LoginFrame();
        myLoginFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        myLoginFrame.setLocationRelativeTo(null);
    }

}
