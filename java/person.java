/*~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
                                                      Author:  Jeremy Cruz   
                                                      Date:    25, August 2016
                                 person.java
--------------------------------------------------------------------------------
Purpose: This file implements a person, the item we will be storing in the hash
         table. A person is defined by name and age. Functions for returning the
         hash code and probe sequence are available within the person and 
         require knowledge of the size of the table it will be stored in.
*=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=*/

/**
 * Name:          person
 *
 * Purpose:       implement the person object defining name, age, and generating
 *                hashcodes and sequences
 *
 * Methods:       person:        constructor initializes datafields
 *
 *                name_length:   return length of name
 *
 *                hash_code:     return hash code for a person
 *
 *                get_sequence:  return probe sequence
 *
 *                get_name:      return name
 *
 *                get_age:       return age
 *
 *                get_probes:    return amount of probes
 *
 *                set_probes:    initialize amount of probes
 *
 * Data fields:   probe_sequence:   sequence of how person probes in table
 *
 *                probes:           current amount of probes
 *
 *                name:             name of person
 *
 *                age:              age of person
 *
 *                length:           length of person's name
 */
public class person implements iperson
{
   private int[] probe_sequence; // index sequence of probes
   private int probes;           // amount of probes
   private String name;          // name of person
   private int age;              // age of person
   private int length;           // length of name to determine hashcode

   /**
    * Name:       person
    *
    * Purpose:    constructor for a person and initialize its datafields
    *
    * Parameters: name:       name of person
    *
    *             age:        age of person
    *
    *             table_size: size of table
    *
    * Return:     this_person:   person structure
    */
   public person(String name, int age, int table_size)
   {
      // allocate memory for array of probes
      this.probe_sequence = new int[table_size];

      // initialize datafields
      this.probes = 0;
      this.name = name;
      this.age = age;

      // call name_length to initialize this field
      this.length = this.name_length();
   }

   /**
    * Name:       name_length
    *
    * Purpose:    return length of name
    *
    * Parameters: none
    *
    * Return:     quantity representing string length of name
    */
   public int name_length()
   {
      // return length of name
      return this.name.length();
   }

   /**
    * Name:       hash_code
    *
    * Purpose:    return the hashcode of this person based on the length and size
    *             size of the table being inserted into
    *
    * Parameters: table_size: size of the table
    *
    * Return:     hash code for person's name
    */
   public int hash_code(int table_size)
   {
      int ascii_sum = 0;   // current sum
      int index = 0;       // current index

      // loop through name gaining ASCII sum
      for(index = 0; index < this.name_length(); ++index)
         ascii_sum += (int) this.name.charAt(index);

      // get integer average of sum
      ascii_sum /= name_length();

      // mod sum by the size of the table
      return ascii_sum % table_size;
   }

   /**
    * Name:       get_sequence
    *
    * Purpose:    generate and return the probe sequence for the person
    *
    * Parameters: table_size: size of table
    *
    * Return:     probe_sequence:   sequence of where this person probes
    *             in the table
    */
   public int[] get_sequence(int table_size)
   {
      int index;                                      // current index
      int current_probe = this.hash_code(table_size); // start at the hashcode

      // loop through the sequence to generate it
      for(index = 0; index < table_size; ++index)
      {
         // assign current index to the current probe number
         this.probe_sequence[index] = current_probe;

         // avoid overflowing the table
         if(current_probe + HOPS >= table_size)
         {
            int current_hop;

            // hop into place by amount of HOPS
            for(current_hop = 0; current_hop < HOPS; ++current_hop)
            {
               if(current_probe + 1 == table_size)
                  current_probe = 0;
               else
                  ++current_probe;
            }
         }

         // add HOPS to current_probe
         else
            current_probe += HOPS;
      }

      // return the array of probes
      return this.probe_sequence;
   }

   /**
    * Name:       get_name
    *
    * Purpose:    return the person's name
    *
    * Parameters: none
    *
    * Return:     name: name of person
    */
   public String get_name()
   {
      // person's name
      return this.name;
   }

   /**
    * Name:       get_age
    *
    * Purpose:    return the person's age
    *
    * Parameters: none
    *
    * Return:     age:  age of person
    */
   public int get_age()
   {
      // person's age
      return this.age;
   }

   /**
    * Name:       get_probes
    * 
    * Purpose:    return the person's probes
    *
    * Parameters: none
    *
    * Return:     probes:  probes of person
    */
   public int get_probes()
   {
      // person's probes
      return this.probes;
   }

   /**
    * Name:       set_probes
    *
    * Purpose:    set probes to given quantity
    *
    * Parameters: amount:  amount to set probes
    *
    * Return:     void
    */
   public void set_probes(int amount)
   {
      // set the probes to the amount
      this.probes = amount;
   }
}
