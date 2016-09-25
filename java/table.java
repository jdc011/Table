/*~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
                                                      Author:  Jeremy Cruz  
                                                      Date:    25 August, 2016
                                 table.java
--------------------------------------------------------------------------------
Purpose: Functions for a hash table are implemented here. We find basic insert,
         remove, and find functions along with the ability to print the table
         contents and return some status datafields.
*=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=*/

/**
 * Name:          table
 *
 * Purpose:       implement functions defined for a hash table
 *
 * Methods:       table:         constructor initailizing datafields
 *
 *                insert:        insert person
 *
 *                remove:        remove person
 *
 *                search:        find a person
 *
 *                full_table:    return status of full table
 *
 *                empty_table:   return status of emoty table
 *
 *                print_table:   print contents of table
 *
 * Data fields:   table:      array of persons
 *
 *                cap:        size of table
 *
 *                occupancy:  amount of persons in table
 *
 *                is_full:    status of full table
 *
 *                is_empty:   status of empty table
 */
public class table implements itable
{
   private person[] table;    // array of persons to create hash table
   private int cap;           // max amount of items to hold
   private int occupancy;     // amount of elements in table
   private boolean is_full;   // status of full table
   private boolean is_empty;  // status of empty table

   /**
    * Name:       table
    *
    * Purpose:    constructor, initalize datafields
    *
    * Parameters: capacity:   size of table
    *
    * Return:     none
    */
   public table(int capacity)
   {
      // initialize datafields
      table = new person[capacity];
      this.cap = capacity;
      this.occupancy = 0;
      this.is_empty = true;
      this.is_full = false;
   }

   /**
    * Name:       insert
    *
    * Purpose:    insert people into the table
    *
    * Parameters: name: name of person
    *
    *             age:  age of person
    *
    * Return:     is_inserted:   status of sucessful insertion
    */
   public boolean insert(String name, int age)
   {
      // create instance of person to insert 
      person new_person = new person(name, age, this.cap);
      // probe sequence of person 
      int[] probes = new_person.get_sequence(this.cap);
      boolean is_inserted = false;  // status of sucessful insert

      // loop through the table by person's probe sequence
      for(int index = 0; index < this.cap; ++index)
      {
         // current probe location
         int current = probes[index];

         // fail if the table is empty
         if(this.occupancy == this.cap)
            return is_inserted;

         // place in empty spot
         if(this.table[current] == null)
         {
            this.table[current] = new_person;
            new_person.set_probes(index);
            ++this.occupancy;
            is_inserted = true;
            break;
         }

         // case of equal names
         else if(this.table[current].get_name().equals(name))
         {
            // fail if age is also equal
            if(this.table[current].get_age() == age)
               return is_inserted;

            // continue if age or amount of probes is less
            else if(this.table[current].get_age() > age ||
                    this.table[current].get_probes() > 0)
               continue;

            // placement in equal case
            else
            {
               // temp person for swap
               person temp = this.table[current];

               // loop through table for placement of temp
               for(index += 1; index < this.cap; ++index)
               {
                  // current probe location
                  int probe = temp.get_sequence(this.cap)[index];
                  
                  // not yet found
                  if(this.table[probe] != null)
                     continue;

                  // placement found
                  else
                  {
                     this.table[probe] = temp;
                     temp.set_probes(index);
                     break;
                  }
               }

               // case of placement never found
               if(index == this.cap)
                  break;

               // insert person
               else
               {
                  this.table[current] = new_person;
                  new_person.set_probes(index);
                  ++this.occupancy;
                  is_inserted = true;
                  break;
               }
            }
         }

         // placement in nonequal case
         else
         {
            // temp person for swap
            person temp = this.table[current];

            // loop through table for placement of temp
            for(index += 1; index < this.cap; ++index)
            {
               // current probe location
               int probe = temp.get_sequence(this.cap)[index];

               // not yet found
               if(this.table[probe] != null)
                  continue;
               
               // placement found
               else
               {
                  this.table[probe] = temp;
                  temp.set_probes(index);
                  break;
               }
            }

            // case of placement never found
            if(index == this.cap)
               break;

            // insert person
            else
            {
               this.table[current] = new_person;
               new_person.set_probes(index);
               ++this.occupancy;
               is_inserted = true;
               break;
            }
         }
      }

      // update status flags
      if(this.occupancy != 0)
         this.is_empty = false;
      if(this.occupancy == this.cap)
         this.is_full = true;

      // return status
      return is_inserted;
   }

   /**
    * Name:       remove
    *
    * Purpose:    remove people from the table
    *
    * Parameters: name: name of person
    *
    *             age:  age of person
    *
    * Return:     removed: status of sucessful removal
    */
   public boolean remove(String name, int age)
   {
      boolean removed = false;   // status of removal
      // create instance of person to remove
      person temp = new person(name, age, this.cap);
      // use probe sequence of person
      int[] probes = temp.get_sequence(this.cap);

      // loop through the table by probe sequence of person
      for(int index = 0; index < this.cap; ++index)
      {
         // current probe location
         int current = probes[index];

         // fail if table is empty
         if(this.occupancy == 0)
            return removed;

         // person found so remove it
         if(this.table[current] != null &&
            this.table[current].get_name().equals(name) &&
            this.table[current].get_age() == age)
         {
            this.table[current] = null;
            removed = true;
            --this.occupancy;
            break;
         }

         // not yet found
         else
            continue;
      }

      // update status flags
      if(this.occupancy == 0)
         this.is_empty = true;
      if(this.occupancy != this.cap)
         this.is_full = false;

      // return status
      return removed;
   }

   /**
    * Name:       search
    *
    * Purpose:    search for people in the table
    *
    * Parameters: name: name of person
    *
    *             age:  age of person
    *
    * Return:     found:   index of found person; -1 if not found
    */
   public int search(String name, int age)
   {
      int found = -1;   // location of person 
      // create instance of person to find in table 
      person temp = new person(name, age, this.cap);
      // use probe sequence of person
      int[] probes = temp.get_sequence(this.cap);

      // loop through the table by probe sequence of person
      for(int index = 0; index < this.cap; ++index)
      {
         // current probe location
         int current = probes[index];
         
         // fail if table is empty
         if(this.occupancy == 0)
            return found;

         // person found
         if(this.table[current] != null &&
            this.table[current].get_name().equals(name) &&
            this.table[current].get_age() == age)
            return current;

         // not yet found
         else
            continue;
      }

      // return location of person
      return found;
   }

   /**
    * Name:       full_table
    *
    * Purpose:    return full table status
    *
    * Parameters: none
    *
    * Return:     is_full: full status
    */
   public boolean full_table()
   {
      // full table status
      return this.is_full;
   }

   /**
    * Name:       empty_table
    *
    * Purpose:    return empty table status
    *
    * Parameters: none
    *
    * Return:     is_empty: empty status
    */
   public boolean empty_table()
   {
      // empty table status
      return this.is_empty;
   }

   /**
    * Name:       print_table
    *
    * Purpose:    print elements in the table
    *
    * Parameters: none
    *
    * Return:     void
    */
   public void print_table()
   {
      int index;  // current index in the table

      // output table's occupancy
      System.out.print("There are " + this.occupancy + " people in this " +  
                       "table:\n");

      // print each element in the table
      for(index = 0; index < this.cap; ++index)
      {
         if(this.table[index] != null)
            System.out.print(index + ". Name: " + this.table[index].get_name() +
                             "         Age: " + this.table[index].get_age() + 
                             "\n");
      }
   }
}
