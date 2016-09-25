/*~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
                                                      Author:  Jeremy Cruz 
                                                      Date:    5, September 2016
                                 equals.h
--------------------------------------------------------------------------------
Purpose: Define type boolean and an equals function to be implemented.
*=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=*/

/* define a typedef boolean with long back end; 1 is true, 0 is false */
typedef long boolean;
#define true 1
#define false 0

/* test string equality by value */
boolean equals(char *, char *);
