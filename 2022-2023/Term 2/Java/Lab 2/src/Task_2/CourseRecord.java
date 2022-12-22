/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Task_2;

import java.util.regex.Pattern;

public class CourseRecord
{

    private String courseCode;
    private String courseTitle, instructorName;
    private int classRoom;
    private double creditHours;

    public CourseRecord(String courseCode, String courseTitle, String instructorName, int classRoom, double creditHours)
            throws Exception
    {
        if (!Pattern.matches("CS\\d{3}|CIS\\d{3}", courseCode.toUpperCase()))
            throw new Exception("Invalid Course Code. Must start with CS or CIS followed by 3 digits.");

        if (classRoom < 0)
            throw new Exception("Invalid Class room number. Can't have a negative number.");

        if (creditHours < 1.0 || creditHours > 3.0)
            throw new Exception("Invalid Course Credit Hours. Must be between 1 and 3");

        this.courseCode = courseCode.toUpperCase();
        this.courseTitle = courseTitle;
        this.instructorName = instructorName;
        this.classRoom = classRoom;
        this.creditHours = creditHours;
    }

    @Override
    public String toString()
    {
        return "Course Code: " + courseCode + "\nTitle: " + courseTitle + "\nInstructor: " + instructorName + "\nClass Room:"
                + classRoom + "\nCredit Hours: " + creditHours + "\n\n";
    }

    public String getCourseTitle()
    {
        return courseTitle;
    }

    public String getInstructorName()
    {
        return instructorName;
    }

    public String getCourseCode()
    {
        return courseCode;
    }

    public int getClassRoom()
    {
        return classRoom;
    }

    public double getCreditHours()
    {
        return creditHours;
    }

    public void setCourseTitle(String courseTitle)
    {
        this.courseTitle = courseTitle;
    }

    public void setInstructorName(String instructorName)
    {
        this.instructorName = instructorName;
    }

    public void setClassRoom(int classRoom)
    {
        this.classRoom = classRoom;
    }

    public void setCourseCode(String courseCode)
    {
        this.courseCode = courseCode;
    }

    public void setCreditHours(double creditHours)
    {
        this.creditHours = creditHours;
    }

}
