package Screens;

import javax.swing.*;
import java.awt.*;
import java.sql.*;

public class Frame extends JFrame
{
    public Frame()
    {
        super("Add and Delete");
        this.setLayout(new FlowLayout());

        // Create employee ID, name, and salary
        JLabel employeeID = new JLabel("Employee ID: ");
        JTextField employeeIDField = new JTextField(10);
        JLabel employeeName = new JLabel("Employee Name: ");
        JTextField employeeNameField = new JTextField(10);
        JLabel employeeSalary = new JLabel("Employee Salary: ");
        JTextField employeeSalaryField = new JTextField(10);

        // Create add and update buttons
        JButton add = new JButton("Add");
        JButton update = new JButton("Update");

        // Add all to frame
        this.add(employeeID);
        this.add(employeeIDField);
        this.add(employeeName);
        this.add(employeeNameField);
        this.add(employeeSalary);
        this.add(employeeSalaryField);
        this.add(add);
        this.add(update);

        setSize(175, 250);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);

        // Add action listener to add button
        add.addActionListener(
                e -> addEmployee(employeeIDField.getText(), employeeNameField.getText(), employeeSalaryField.getText()));
        update.addActionListener(
                e -> updateEmployee());
    }

    private void addEmployee(String ID, String name, String salary)
    {
        if (ID.isEmpty() || name.isEmpty() || salary.isEmpty())
        {
            JOptionPane.showMessageDialog(this, "Please fill in all fields!", "Error", JOptionPane.ERROR_MESSAGE);
            return;
        }

        if (!ID.matches("[0-9]+"))
        {
            JOptionPane.showMessageDialog(this, "Employee ID must be a number!", "Error", JOptionPane.ERROR_MESSAGE);
            return;
        }

        if (!salary.matches("[0-9]+"))
        {
            JOptionPane.showMessageDialog(this, "Employee salary must be a number!", "Error", JOptionPane.ERROR_MESSAGE);
            return;
        }
        String query = "INSERT INTO Employee (Employee_ID, Name, Salary) VALUES (?, ?, ?);";
        try (Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/Company", "JavaQuiz", "root");
                PreparedStatement stmt = con.prepareStatement(query);)
        {

            stmt.setString(1, ID);
            stmt.setString(2, name);
            stmt.setString(3, salary);

            stmt.executeUpdate();
            JOptionPane.showMessageDialog(this, "Employee added successfully!", "Success", JOptionPane.INFORMATION_MESSAGE);
        }
        catch (SQLException e)
        {
            JOptionPane.showMessageDialog(this, "Error: " + e.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    private void updateEmployee()
    {
        String name = JOptionPane.showInputDialog(this, "Enter Employee Name: ", "Update Salary",
                JOptionPane.QUESTION_MESSAGE);
        if (name.isEmpty())
        {
            JOptionPane.showMessageDialog(this, "Must Enter a Name.", "Error", JOptionPane.ERROR_MESSAGE);
            return;
        }
        String salary = JOptionPane.showInputDialog(this, "Enter Salary: ", "Update Salary", JOptionPane.QUESTION_MESSAGE);
        if (!salary.matches("[0-9]+"))
        {
            JOptionPane.showMessageDialog(this, "Employee salary must be a number!", "Error", JOptionPane.ERROR_MESSAGE);
            return;
        }
        int salaryInt = Integer.parseInt(salary);
        String query = "UPDATE Employee SET Salary = Salary + ? WHERE name = ?;";
        try (Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/Company", "JavaQuiz", "root");
                PreparedStatement stmt = con.prepareStatement(query);)
        {
            stmt.setInt(1, salaryInt);
            stmt.setString(2, name);
            int result = stmt.executeUpdate();
            if (result == 0)
            {
                JOptionPane.showMessageDialog(this, "Employee not found!", "Error", JOptionPane.ERROR_MESSAGE);
                return;
            }
            JOptionPane.showMessageDialog(this, "Salary updated successfully!", "Success",
                    JOptionPane.INFORMATION_MESSAGE);
        }
        catch (SQLException e)
        {
            JOptionPane.showMessageDialog(this, "Error: " + e.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

}
