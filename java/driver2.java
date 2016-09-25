/**---------------------------------------------------------------------------*/
/**-------------------------DO NOT MODIFY THIS FILE---------------------------*/
/**---------------------------------------------------------------------------*/
/*~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
                                                      Author:  Jeremy Cruz
                                                      Date:    5, September 2016
                                 driver2.java
--------------------------------------------------------------------------------
Purpose: This driver file will test the functions
*=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=*/

import java.util.Scanner; // used for user input

/**
 * Name:       driver2
 *
 * Purpose:    test the hash table functions
 *
 * Methods:    main: tester
 *
 * Datafields: none
 */
public class driver2
{
   /**
    * Name:       main
    *
    * Purpose:    test the functions implemented by a hash table; tests are
    *             decided by input of user commands
    *
    * Parameters: args: list of command line arguments to determine size of 
    *             hash table
    */
   public static void main(String[] args)
   {
      String command;      // user command
      String name;         // name of person
      int age;             // age of person
      boolean cont = true; // determine whether to terminate loop

      // invalid input
      if(args.length != 1)
      {
         System.out.print("usage: java driver2 <size of table>\n");
         return;
      }
      
      // allocate memory for hash table
      table this_table = new table(Integer.parseInt(args[0]));

      // create scanner object for user input from keyboard
      Scanner stdin = new Scanner(System.in);

      // output verification of hash table creation
      System.out.print("A table of size " + Integer.parseInt(args[0]) + 
                       " has been created.\n\n");
      
      // test hash table functions
      while(cont)
      {
         // user prompt
         System.out.print("Commands:\n" +
                          "i = insert\n" +
                          "r = remove\n" +
                          "s = search\n" +
                          "f = full_table\n" +
                          "e = empty_table\n" +
                          "p = print_table\n" +
                          "d = dealloc\n" +
                          "\nPlease enter a command: ");
      
         // input command
         command = stdin.next();

         // determine test based on command
         switch(command)
         {
            // test insert
            case "i":
               System.out.print("\nEnter name and age of a person to insert " +
                                "into the table: ");
               name = stdin.next();
               age = stdin.nextInt();
               
               if(this_table.insert(name, age))
                  System.out.print("\n" + name + " with age " + age + 
                                   " has been inserted into the " +
                                   "table.\n\n");
               else
                  System.out.print("\nInsertion failure, table not updated\n\n"
                                    );
            break;

            // test remove
            case "r":
               System.out.print("\nEnter name and age of a person to remove " +
                                "from the table: "); 
               name = stdin.next();
               age = stdin.nextInt();

               if(this_table.remove(name, age))
                  System.out.print("\n" + name + " with age " 
                  + age + " has been removed from the " +
                  "table.\n\n");
               else
                  System.out.print("\nRemoval failure, table not updated.\n\n");
            break;

            // test search
            case "s":
               System.out.print("\nEnter name and age of a person to search " +
                                "in the table: ");
               name = stdin.next();
               age = stdin.nextInt();

               int index = this_table.search(name, age);

               if(index != -1)
                  System.out.print("\n" + name + " with " +
                  "age " + age + " is located in index " + 
                  index + " of the table.\n\n");
               else
                  System.out.print("\n" + name + " with " +
                  "age " + age + " is not in the table.\n\n");
            break;

            // test full_table
            case "f":
               if(this_table.full_table())
                  System.out.print("\nThe table is full.\n\n");
               else
                  System.out.print("\nThe table is not full.\n\n");
            break;

            // test empty_table
            case "e":
               if(this_table.empty_table())
                  System.out.print("\nThe table is empty.\n\n");
               else
                  System.out.print("\nThe table is not empty.\n\n");
            break;

            // test print_table
            case "p":
               System.out.print("\n");
               this_table.print_table();
               System.out.print("\n");
            break;

            // terminate the program
            case "d":
               cont = false;
            break;

            // invalid command
            default:
               System.out.print("\n" + command + " is not a valid " + 
                                "command.\n\n");
            break;
         }
      }
   }
}
