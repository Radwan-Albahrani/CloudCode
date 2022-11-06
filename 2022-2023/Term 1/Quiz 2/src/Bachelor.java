public class Bachelor extends Student
{
    // Method to check if a bachelor student graduated. Needed hours 170
    @Override
    void checkGraduate()
    {
        if (this.getHours() >= 170)
        {
            this.graduate();
        }
    }
}
