/*~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
                                                      Author:  Jeremy Cruz   
                                                      Date:    25, August 2016
                                 person.c
--------------------------------------------------------------------------------
Purpose: This file implements a person, the item we will be storing in the hash
         table. A person is defined by name and age. Functions for returning the
         hash code and probe sequence are available within the person and 
         require knowledge of the size of the table it will be stored in.
*=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=*/

#include <stdlib.h>
#include "person.h"

unsigned int name_length(prsn *);   /* prototype used by create_person */

/*------------------------------------------------------------------------------
Name:       create_person

Purpose:    Allocate memory for a person and initialize its datafields.

Parameters: name:       name of person

            age:        age of person

            table_size: size of table

Return:     this_person:   person structure
------------------------------------------------------------------------------*/
prsn * create_person(char * name, unsigned int age, unsigned int table_size)
{
   /* allocate memory for struct and its probe array */
   prsn * this_person = malloc(sizeof(prsn));
   this_person->probe_sequence = malloc(sizeof(unsigned int) * table_size);

   /* initialize datafields */
   this_person->probes = 0;
   this_person->name = name;
   this_person->age = age;
   this_person->length = name_length(this_person);
   
   /* return person structure */
   return this_person;
}

/*------------------------------------------------------------------------------
Name:       delete_person

Purpose:    Deallocate memory for a person.

Parameters: this_person:   person to be deleted

Return:     void
------------------------------------------------------------------------------*/
void delete_person(prsn * this_person)
{
   /* deallocate memory for the probe array */
   free(this_person->probe_sequence);

   /* deallocate memory for a person */
   free(this_person);
}

/*------------------------------------------------------------------------------
Name:       name_length

Purpose:    return length of name

Parameters: this_person:   person's name length to return

Return:     index:   overall length of name
------------------------------------------------------------------------------*/
unsigned int name_length(prsn * this_person)
{
   /* current index in name */
   unsigned int index = 0;

   /* increment index as name gets traversed */
   while(this_person->name[index])
      ++index;

   /* return the length */
   return index;
}

/*------------------------------------------------------------------------------
Name:       hash_code

Purpose:    return the hashcode of this person based on name length and size of
            table being inserted into

Parameters: this_person:   person to get hashcode of

            table_size:    size of table to be inserted into

Return:     hash code for the person's name
------------------------------------------------------------------------------*/
unsigned int hash_code(prsn * this_person, unsigned int table_size)
{
   unsigned int ascii_sum = 0;   /* current sum */
   unsigned int index = 0;       /* current index */

   /* loop through name gaining ASCII sum */
   for(index = 0; index < name_length(this_person); ++index)
      ascii_sum += (unsigned int) this_person->name[index];

   /* get integer average of sum */
   ascii_sum /= name_length(this_person);

   /* mod sum by the size of the table */
   return ascii_sum % table_size;
}

/*------------------------------------------------------------------------------
Name:       get_sequence

Purpose:    generate and return the probe sequence for the person

Parameters: this_person:   person to get probe sequence of
      
            table_size:    size of table

Return:     probe_sequence:   sequence of where this person probes in the table
------------------------------------------------------------------------------*/
unsigned int * get_sequence(prsn * this_person, unsigned int table_size)
{
   unsigned int index;                                      /* curren index */

   /* start at the hashcode */
   unsigned int current_probe = hash_code(this_person, table_size);

   /* loop through the sequence to generate it */
   for(index = 0; index < table_size; ++index)
   {
      /* assign current index to the current probe number */
      this_person->probe_sequence[index] = current_probe;

      /* avoid overflowing the table */
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

      /* add HOPS to current_probe */
      else
         current_probe += HOPS;
   }

   /* return the pointer to the probe sequence */
   return this_person->probe_sequence;
}
