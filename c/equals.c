/*~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
                                                      Author:  Jeremy Cruz 
                                                      Date:    2016, August 25
                                  equals.h
--------------------------------------------------------------------------------
Purpose: This file implements an equals function for 2 char pointers parsing
         them character by character to check equality.
*=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=*/

#include "equals.h"

/*------------------------------------------------------------------------------
Name:       equals

Purpose:    Test equality of two char pointers implementing arrays of chars.

Parameters: lhs:  char pointer comparison
            rhs:  char pointer comparison

Return:     is_equal:   status of whether the two char pointers are equal in
                        string sequence
------------------------------------------------------------------------------*/
boolean equals(char * lhs, char * rhs)
{
   boolean is_equal = true;   /* status of equality */
   int index = 0;             /* current index in traversal of pointers */

   /* loop through both pointers so long as there are characters */
   while(lhs[index] || rhs[index])
   {
      /* terminate when inequlity is founs */
      if(lhs[index] != rhs[index])
         return !is_equal;
      /* case of unequal length */
      if(!rhs[index] && lhs[index] || rhs[index] && !lhs[index])
         return !is_equal;

      /* continue incrementing current index for check */
      ++index;
   }

   /* return status */
   return is_equal;
}
