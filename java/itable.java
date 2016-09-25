/**---------------------------------------------------------------------------*/
/**--------------------------DO NOT MODIFY THIS FILE--------------------------*/
/**---------------------------------------------------------------------------*/
/*~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
                                                      Author:  Jeremy Cruz
                                                      Date:    5, September 2016
                                 itable.java
--------------------------------------------------------------------------------
Purpose: Define the class for a hash table as well as its functions to implement
         along for creating an instance of itself and destroying it.
*=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=*/

/**
 * Name:       itable
 *
 * Purpose:    define a hash table structure and create function signitures for 
 *             what a hash table would be capable of doing
 *
 * Methods:    insert:        add person to table
 *
 *             remove:        remove person from table
 *
 *             search:        search a person from table
 *
 *             full_table:    state whether table is full
 *
 *             empty_table:   state whether table is empty
 *
 *             print_table:   print elements in the table
 *
 * Datafields: HOPS: amount of indeces in table to probe
 */
public interface itable
{
   // functions for table
   boolean insert(String name, int age);

   boolean remove(String name, int age);

   int search(String name, int age);

   boolean full_table();

   boolean empty_table();

   void print_table();
}
