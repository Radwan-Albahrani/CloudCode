class Quiz1 {

   public static void main(String [] args)

    {    try {

            method1(); 

            System.out.print("A");}

        catch (Exception e)

            { System.out.print("B"); }

        finally

            {System.out.print("C"); }

        System.out.print("D");

    }

    public static void method1() throws Exception

    {  try {

            System.out.print("E");

            method2(); }

        catch(Exception e)

            {  throw  e; }

    }

   public static void method2()throws Exception 

    {  throw new Exception();  }

}

