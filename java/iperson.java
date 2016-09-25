/**---------------------------------------------------------------------------*/
/**--------------------------DO NOT MODIFY THIS FILE--------------------------*/
/**---------------------------------------------------------------------------*/
/*~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
                                                      Author:  Jeremy Cruz
                                                      Date:    5, September 2016
                                iperson.java
--------------------------------------------------------------------------------
Purpose: This represents a person object that we will store dynamically in a
         hash table. A person is determined by name and age. A hashcode function
         is included to hash an instance of the person.
*=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=*/

/**
 * Name:       iperson
 *
 * Purpose:    define an object for a person and define functions involving its
 *             creation, deletion, and hashcode into a hash table
 *
 * Methods:    name_length:      return length of name
 *
 *             hash_code:        get the hash index into a table
 *
 *             get_sequence:     create and return the probe sequence
 *
 *             get_name:         return name of person
 *
 *             get_age:          return age of person
 *
 *             increment_probes: increment amount of probes
 *
 * Datafields: none
 */
public interface iperson
{
   // datafields
   final int HOPS = 5;     // amount of indeces to probe
   
   // functions for person
   int name_length();

   int hash_code(int table_size);

   int[] get_sequence(int table_size);

   String get_name();

   int get_age();

   int get_probes();
   
   void set_probes(int amount);
}
