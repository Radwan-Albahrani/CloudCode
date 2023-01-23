/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import javax.swing.JFrame;
import javax.swing.JTextField;
import javax.swing.JLabel;
import javax.swing.JButton;
import javax.swing.JOptionPane;

public class AddBookProject
{

    /*
     * 1. Create a database in the `services tab with the same name,username and password
     * 2. Check Libraries in your project ( Java DB Driver should be there )
     */
    public static void main(String[] args)
    {
        NewBook obj = new NewBook();
        obj.setSize(300, 300);
        obj.setVisible(true);
    }

}

class NewBook extends JFrame
{

    private final JLabel JlableBookTitle;
    private final JTextField JtextBookTitle;

    private final JLabel JlableBookISBN;
    private final JTextField JtextBookISBN;

    private final JLabel JlableBookCopyRight;
    private final JTextField JtextBookCopyRight;

    private final JLabel JlableBookEditionNumber;
    private final JTextField JtextBookEditionNumber;

    private final JLabel JlableAuthorsFirstName;
    private final JTextField JtextAuthorsFirstName;

    private final JLabel JlableAuthorsLastName;
    private final JTextField JtextAuthorsLastName;

    private final JButton JButtonAdd;
    private final JButton JButtonExit;

    public NewBook()
    {
        super(" Add New Book");

        setLayout(new GridLayout(7, 2));

        // Box boxNorth= new Box.createVerticalBox();
        JlableBookTitle = new JLabel("Book Title");
        JtextBookTitle = new JTextField(10);

        add(JlableBookTitle);
        add(JtextBookTitle);

        JlableBookISBN = new JLabel("Book ISBN");
        JtextBookISBN = new JTextField(10);

        add(JlableBookISBN);
        add(JtextBookISBN);

        JlableBookCopyRight = new JLabel("Book CopyRight");
        JtextBookCopyRight = new JTextField(10);

        add(JlableBookCopyRight);
        add(JtextBookCopyRight);

        JlableBookEditionNumber = new JLabel("Book Edtition Number ");
        JtextBookEditionNumber = new JTextField(10);

        add(JlableBookEditionNumber);
        add(JtextBookEditionNumber);

        JlableAuthorsFirstName = new JLabel("Authors First Name");
        JtextAuthorsFirstName = new JTextField(10);

        add(JlableAuthorsFirstName);
        add(JtextAuthorsFirstName);

        JlableAuthorsLastName = new JLabel("Authors Last Name");
        JtextAuthorsLastName = new JTextField(10);

        add(JlableAuthorsLastName);
        add(JtextAuthorsLastName);

        JButtonAdd = new JButton("Add");
        JButtonExit = new JButton("Exit");

        add(JButtonAdd);
        add(JButtonExit);

        ButtonHandelr H = new ButtonHandelr();
        JButtonAdd.addActionListener(H);
        JButtonExit.addActionListener(H);

    }// end of constructor

    private class ButtonHandelr implements ActionListener
    {

        public void actionPerformed(ActionEvent e)
        {

            if (e.getSource() == JButtonAdd)
            {
                String FName = JtextAuthorsFirstName.getText();
                String LName = JtextAuthorsLastName.getText();
                String INSERT_1 = "INSERT INTO AUTHORS (FIRSTNAME,LASTNAME) VALUES ('" + FName + "','" + LName + "')";

                String BookTitle = JtextBookTitle.getText();
                String BookISBN = JtextBookISBN.getText();
                String BookCopyRight = JtextBookCopyRight.getText();
                String BookEditonNum = JtextBookEditionNumber.getText();

                int BookEdNum = Integer.parseInt(BookEditonNum);
                String INSERT_2 = "INSERT INTO TITLES (ISBN,TITLE,EDITIONNUMBER,COPYRIGHT) VALUES ('" + BookISBN + "','"
                        + BookTitle + "'," + BookEdNum + ",'" + BookCopyRight + "')";

                try (
                        // use try-with-resources to connect to and query the database
                        Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/books", "root",
                                "root");
                        Statement st = con.createStatement())
                {

                    int INSERT2_Status = st.executeUpdate(INSERT_2);
                    int INSERT1_Status = st.executeUpdate(INSERT_1);

                    // my addition:
                    ResultSet rs = st.executeQuery("SELECT authorID FROM Authors as A WHERE A.FIRSTNAME='" + FName
                            + "' AND A.Lastname='" + LName + "'");

                    rs.next();
                    int ID = rs.getInt(1); // JOptionPane.showMessageDialog(null, ""+ID);

                    String INSERT_3 = "INSERT INTO AUTHORISBN (ISBN,AUTHORID) VALUES ('" + BookISBN + "'," + ID + ")";
                    int INSERT3_Status = st.executeUpdate(INSERT_3);

                    if (INSERT1_Status == 1 && INSERT2_Status == 1 && INSERT3_Status == 1)
                        JOptionPane.showMessageDialog(null, "The book and author details have been added successfully!");

                    rs.close();

                }
                catch (SQLException ex)
                {
                    // ex.printStackTrace();
                    JOptionPane.showMessageDialog(null, ex.getMessage(), "Error in INSERT", JOptionPane.ERROR_MESSAGE);
                } // end try-catch

            } // end if
            else if (e.getSource() == JButtonExit)
            {// pressing exit button
                JOptionPane.showMessageDialog(null, "Thank you ... Bye");
                System.exit(0);

            }
        }// end method

    }// end listener

}// end class
