/*~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
                                                      Author:  Jeremy Cruz  
                                                      Date:    25 August, 2016
                                   table.c
--------------------------------------------------------------------------------
Purpose: Functions for a hash table are implemented here. We find basic insert,
         remove, and find functions along with the ability to print the table
         contents and return some status datafields.
*=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=*/

#include <stdio.h>
#include <stdlib.h>
#include "equals.h"
#include "table.h"

/*------------------------------------------------------------------------------
Name:       alloc

Purpose:    intialize datafields

Parameters: capacity:   size of table

Return:     this_table: pointer to created table
------------------------------------------------------------------------------*/
tbl * alloc(unsigned int capacity)
{
   /* initialize datafields */
   tbl * this_table = malloc(sizeof(tbl));
   this_table->table = malloc(sizeof(prsn) * capacity);
   this_table->cap = capacity;
   this_table->occupancy = 0;
   this_table->is_empty = 1;
   this_table->is_full = 0;

   /* return the table */
   return this_table;
}

/*------------------------------------------------------------------------------
Name:       dealloc

Purpose:    delete memory associated to the table

Parameters: this_table: table do delete

Return:     void
------------------------------------------------------------------------------*/
void dealloc(tbl * this_table)
{
   int index;  /* current index */
   
   /* delete all people in the table */
   for(index = 0; index < this_table->cap; ++index)
   {
      if(this_table->table[index])
         delete_person(this_table->table[index]);
   }

   /* free memory based on the table */
   free(this_table->table);
   free(this_table);
}

/*------------------------------------------------------------------------------
Name:       insert

Purpose:    insert people into the table

Parameters: this_table: table to insert into

            name:       name of person

            age:        age of person

Return:     is_inserted:   status of sucessful insertion
------------------------------------------------------------------------------*/
long insert(tbl * this_table, char * name, int age)
{
   /* create instance of person to insert */
   prsn * new_person = create_person(name, age, this_table->cap);
   /* probe sequence of person */
   unsigned int * probes = get_sequence(new_person, this_table->cap);
   long is_inserted = 0;   /* status of sucessful insert */
   int index;              /* current index */

   /* loop through the table by person's probe sequence */
   for(index = 0; index < this_table->cap; ++index)
   {
      /* current probe location */
      unsigned int current = probes[index];

      /* fail if the table is empty */
      if(this_table->occupancy == this_table->cap)
      {
         delete_person(new_person);
         return is_inserted;
      }
      
      /* place in empty spot */
      if(!this_table->table[current])
      {
         this_table->table[current] = new_person;
         new_person->probes = index;
         ++this_table->occupancy;
         is_inserted = 1;
         break;
      }
      
      /* case of equal names */
      else if(equals(this_table->table[current]->name, name))
      {
         /* fail if age is also equal */
         if(this_table->table[current]->age == age)
         {   
            delete_person(new_person);
            return is_inserted;
         }

         /* continue if age or amount of probes is less */
         else if(this_table->table[current]->age > age ||
                 this_table->table[current]->probes > 0)
            continue;
         
         /* placement in equal case */
         else
         {
            /* temp person for swap */
            prsn * temp = this_table->table[current];

            /* loop through the table for placement of temp */
            for(index += 1; index < this_table->cap; ++index)
            {
               /* current probe location */
               unsigned int probe = temp->probe_sequence[index];

               /* not yet found */
               if(this_table->table[probe])
                  continue;

               /* placement found */
               else
               {
                  this_table->table[probe] = temp;
                  temp->probes = index;
                  break;
               }
            }

            /* case of placement never found */
            if(index == this_table->cap)
               break;

            /* insert person */
            else
            {
               this_table->table[current] = new_person;
               new_person->probes = index;
               ++this_table->occupancy;
               is_inserted = 1;
               break;
            }
         }
      }

      /* placement in nonequal case */
      else
      {
         /* temp person for swap */
         prsn * temp = this_table->table[current];

         /* loop through table for placement of temp */
         for(index += 1; index < this_table->cap; ++index)
         {
            /* current probe location */
            unsigned int probe = temp->probe_sequence[index];

            /* not yet found */
            if(this_table->table[probe])
               continue;

            /* placement found */
            else
            {
               this_table->table[probe] = temp;
               temp->probes = index;
               break;
            }
            
            /* case of palcement never found */
            if(index == this_table->cap)
               break;

            /* insert person */
            else
            {
               this_table->table[current] = new_person;
               new_person->probes = index;
               ++this_table->occupancy;
               is_inserted = 1;
               break;
            }
         }
      }
   }

   /* update status flags */
   if(this_table->occupancy != 0)
      this_table->is_empty = 0;
   if(this_table->occupancy == this_table->cap)
      this_table->is_full = 1;

   /* return status */
   return is_inserted;
}

/*------------------------------------------------------------------------------
Name:       Remove

Purpose:    remove people from the table

Parameters: this_table: table to remove from

            name:       name of person

            age:        age of person

Return:     removed: status of sucessful remove
------------------------------------------------------------------------------*/
long Remove(tbl * this_table, char * name, int age)
{
   long removed = 0; /* status of removal */
   int index;        /* current index */
   /* create instance of person to remove */
   prsn * temp = create_person(name, age, this_table->cap);
   /* use probe sequence of person */
   unsigned int * probes = get_sequence(temp, this_table->cap);

   /* loop through the table by probe sequence of person */
   for(index = 0; index < this_table->cap; ++index)
   {
      /* current probe location */
      unsigned int current = probes[index];
      
      /* fail if table is empty */
      if(this_table->occupancy == 0)
      {
         delete_person(temp);
         return removed;
      }

      /* person found so remove it */
      if(this_table->table[current] &&
         equals(this_table->table[current]->name, name) &&
         this_table->table[current]->age == age)
      {
         delete_person(this_table->table[current]);
         this_table->table[current] = 0;
         removed = 1;
         --this_table->occupancy;
         break;
      }

      /* not yet found */
      else
         continue;
   }

   /* update status flags */
   if(this_table->occupancy == 0)
      this_table->is_empty = 1;
   if(this_table->occupancy != this_table->cap)
      this_table->is_full = 0;

   /* delete person instance */
   delete_person(temp);

   /* return status */
   return removed;
}

/*------------------------------------------------------------------------------
Name:       search

Purpose:    search for people in the table

Parameters: this_table: table to search

            name:       name of person

            age:        age of person

Return:     index of found person; -1 if not found
------------------------------------------------------------------------------*/
int search(tbl * this_table, char * name, int age)
{
   long found = -1;  /* location of person */
   int index;        /* current index */
   /* create instance person to find in table */
   prsn * temp = create_person(name, age, this_table->cap);
   /* use probe sequence of person */
   unsigned int * probes = get_sequence(temp, this_table->cap);
   
   /* loop through the table by probe sequence of person */
   for(index = 0; index < this_table->cap; ++index)
   {
      /* current probe location */
      unsigned int current = probes[index];

      /* fail if table is empty */
      if(this_table->occupancy == 0)
      {
         delete_person(temp);
         return found;
      }

      /* person found */
      if(this_table->table[current] &&
         equals(this_table->table[current]->name, name) &&
         this_table->table[current]->age == age)
      {
         delete_person(temp);
         return current;
      }

      /* not yet found */
      else
         continue;
   }

   /* delete person instance */
   delete_person(temp);

   /* return location of person */
   return found;
}

/*------------------------------------------------------------------------------
Name:       full_table

Purpose:    Return status of full table.

Parameters: this_table: table to check

Return:     is_full: full table status
------------------------------------------------------------------------------*/
long full_table(tbl * this_table)
{
   /* return status */
   return this_table->is_full;
}

/*------------------------------------------------------------------------------
Name:       empty_table

Purpose:    Return status of empty table.

Parameters: this_table: table to check

Return:     is_empty: empty table status
------------------------------------------------------------------------------*/
long empty_table(tbl * this_table)
{
   /* return status */
   return this_table->is_empty;
}

/*------------------------------------------------------------------------------
Name:       print_table

Purpose:    Print elements in the table.

Parameters: this_table: table to print elements of

Return:     void
------------------------------------------------------------------------------*/
void print_table(tbl * this_table)
{
   int index; /* current index place holder */

   /* output occupancy */
   printf("There are %d people in this table:\n", this_table->occupancy);

   /* output name and age of each person */
   for(index = 0; index < this_table->cap; ++index)
   {
      if(this_table->table[index])
         printf("%d. Name: %s       Age: %d\n", index, 
                this_table->table[index]->name, this_table->table[index]->age);
   }
}
