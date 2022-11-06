enum Status
{
    ACTIVE, INACTIVE, GRADUATE
}

public abstract class Student extends User
{
    private String studentID;
    private Status status = Status.ACTIVE;
    private double gpa = 4;
    private int hours;

    // ================================================= Getters =================================================
    public String getStudentID()
    {
        return studentID;
    }

    public void setStudentID(String studentID)
    {
        this.studentID = studentID;
    }

    public Status getStatus()
    {
        return status;
    }

    // ================================================= Setters =================================================
    public void setStatus(Status status)
    {
        this.status = status;
    }

    public double getGpa()
    {
        return gpa;
    }

    public void setGpa(double gpa)
    {
        this.gpa = gpa;
    }

    public int getHours()
    {
        return hours;
    }

    public void setHours(int hours)
    {
        this.hours = hours;
    }

    // ========================================================= Methods =================================================================
    // Abstract Methods
    abstract void checkGraduate();

    // Public Methods
    public double calculateGPA()
    {
        return this.gpa * 100 / 100 + 0.5;
    }

    public void graduate()
    {
        this.status = Status.GRADUATE;
    }

}
