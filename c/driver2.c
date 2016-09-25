/**---------------------------------------------------------------------------*/
/**-------------------------DO NOT MODIFY THIS FILE---------------------------*/
/**---------------------------------------------------------------------------*/
/*~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
                                                      Author:  Jeremy Cruz
                                                      Date:    5, September 2016
                                 driver2.c
--------------------------------------------------------------------------------
Purpose: This driver file will simply test the person object. It will print to
         standard output the hashcode and probe sequence of dynamically created
         person objects. These function calls will depend on the length of the
         person name.
*=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=*/

#include <stdio.h>
#include "person.h"

#define SIZE 8 /* size of arrays to test in this driver */

/*------------------------------------------------------------------------------
Name:       main

Purpose:    Test the hashcode accuracy of the person object by calling functions
            it implements.

Parameters: void

Return:     exit code 0
------------------------------------------------------------------------------*/
int main(void)
{
   int index;  /* current index in test arrays */
   int probe;  /* current probe index */
   prsn * people[SIZE]; /* store persons in here */
   /* test parallel array of names */
   char * names[SIZE] = {"Joe", "Bob", "Steve", "Rolf", "Ashley", "Lin", 
                         "Ellie", "Jane"};
   /* test parallel array of ages */
   int ages[SIZE] = {17, 15, 19, 21, 16, 23, 20, 21};
   
   /* test output */
   printf("Testing person struct...\n\n");

   /* loop through each persons */
   for(index = 0; index < SIZE; ++index)
   {
      /* create a person */
      people[index] = create_person(names[index], ages[index], SIZE);
      printf("%d. Name: %s       Age: %d        Hashcode: %d\nProbe Sequence: ",
             index + 1, names[index], ages[index], hash_code(people[index], 
             SIZE));

      /* output probe sequence of current person */
      for(probe = 0; probe < SIZE; ++probe)
         printf("%d ", get_sequence(people[index], SIZE)[probe]);

      /* free memory allocated by a person */
      printf("\n\n");
      delete_person(people[index]);
   }
   
   /* exit code sucess */
   return 0;
}
