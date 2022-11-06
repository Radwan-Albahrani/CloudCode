public class Diploma extends Student
{

    // Method to check if diploma student Graduated. Needed hours 120
    @Override
    void checkGraduate()
    {

        if (this.getHours() >= 150)
        {
            this.graduate();
        }
    }

}
