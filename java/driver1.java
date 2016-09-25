/**---------------------------------------------------------------------------*/
/**-------------------------DO NOT MODIFY THIS FILE---------------------------*/
/**---------------------------------------------------------------------------*/
/*~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
                                                      Author:  Jeremy Cruz
                                                      Date:    5, September 2016
                                 driver1.java
--------------------------------------------------------------------------------
Purpose: This driver file will simply test the person object. It will print to
         standard output the hashcode and probe sequence of dynamically created
         person objects. These function calls will depend on the length of the
         person name.
*=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=*/

/**
 * Name:       driver1
 *
 * Purpose:    test the person object
 *
 * Methods:    main: tester
 *
 * Datafields: SIZE: size of test table and parallel arrays
 */
public class driver1
{
   public static final int SIZE = 8;

   /**
    * Name:       main
    *
    * Purpose:    test the hashcode accuracy of the person object by calling
    *             functions it implements
    *
    * Parameters: args: command line arguments not used
    *
    * Return:     none
    */
   public static void main(String[] args)
   {
      int index;  // current index in test arrays
      int probe;  // current probe index
      person[] people = new person[SIZE]; // store persons in here
      String[] names = {"Joe", "Bob", "Steve", "Rolf", "Ashley", "Lin", 
                        "Ellie", "Jane"}; // test parallel array of names
      int[] ages = {17, 15, 19, 21, 16, 23, 20, 21};  // test parallel array of 
                                                      // ages

      // test output
      System.out.print("Testing person struct...\n\n");

      // loop through each persons
      for(index = 0; index < SIZE; ++index)
      {
         // create a person
         people[index] = new person(names[index], ages[index], SIZE);
         System.out.print(index + 1 + ". Name: " + names[index] + 
                          "         Age: " + ages[index] + "       Hashcode: " +
                          people[index].hash_code(SIZE) + "\nProbe Sequence: ");

         // output probe sequence of each person
         for(probe = 0; probe < SIZE; ++probe)
            System.out.print(people[index].get_sequence(SIZE)[probe] + " ");

         System.out.print("\n\n");
      }
   }
}
