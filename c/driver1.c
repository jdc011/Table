/**---------------------------------------------------------------------------*/
/**-------------------------DO NOT MODIFY THIS FILE---------------------------*/
/**---------------------------------------------------------------------------*/
/*~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
                                                      Author:  Jeremy Cruz
                                                      Date:    5, September 2016
                                  driver1.c
--------------------------------------------------------------------------------
Purpose: Test validity of the equals function on 2 character pointers input from
         the command line.
*=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=*/
#include <stdio.h>
#include "equals.h"

static const int VALID_ARGUMENTS = 3; /* number of valid arguments */

/*------------------------------------------------------------------------------
Name:       main

Purpose:    Test the equals function.

Parameters: argc: amount of arguments from the command line

            argv: values of each command line argument

Return:     Exit codes; 1 for failure, 0 for sucess
------------------------------------------------------------------------------*/
int main(int argc, char * argv[])
{
   /* invalid input */
   if(argc != VALID_ARGUMENTS)
   {
      printf("usage: ./driver1 <string 1> <string 2>\n");
      
      /* exit code failure */
      return 1;
   }

   /* test true and false cases for equals */
   if(equals(argv[1], argv[1 + 1]))
      printf("%s and %s are equal.\n", argv[1], argv[1 + 1]);
   else
      printf("%s and %s are not equal.\n", argv[1], argv[1 + 1]);

   /* exit code sucess */
   return 0;
}
