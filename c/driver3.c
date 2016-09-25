/**---------------------------------------------------------------------------*/
/**----------------DO NOT MODIFY THIS FILE EXCEPT FOR LINE 187----------------*/
/**---------------------------------------------------------------------------*/
/*~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
                                                      Author:  Jeremy Cruz
                                                      Date:    5, September 2016
                                 driver3.c
--------------------------------------------------------------------------------
Purpose: This driver file will test the functions
*=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"

#define BUFF_SIZE 100 /* size of string */

static const int VALID_ARGS = 2;

/*------------------------------------------------------------------------------
Name:       main

Purpose:    Test the functions implemented by a hash table. Tests are decided by
            input of user commands.

Parameters: argc: amount of arguments from the command line

            argv: values of each command line argument

Return:     Exit codes; 1 for failure, 0 for sucess
------------------------------------------------------------------------------*/
int main(int argc, char * argv[])
{
   int occupancy = 0;         /* current occupants */
   int index;                 /* current index in table traversal */
   unsigned int table_size;   /* size of table */
   char command;              /* user command */
   char name[BUFF_SIZE];      /* name of person */
   char * temp;               /* place holder for name */
   int age;                   /* age of person */
   long cont = 1;             /* determine whether to terminate the loop */

   /* invalid input */
   if(argc != VALID_ARGS)
   {
      printf("Usage: ./driver3 <size of table>\n");
      return 1;
   }

   /* allocate memory for hash table */
   else
      table_size = (unsigned int) atoi(argv[1]);
   
   /* paralell test driver table */
   prsn * table[table_size];
   memset(table, 0, sizeof(prsn *) * table_size); 

   tbl * this_table = alloc(table_size);

   /* output verification of hash table creation */
   printf("A hash table of size %d has been created.\n\n", table_size);

   /* test hash table functions */
   while(cont)
   {
      /* clean buffer for command input */
      command = 0;

      /* user prompt */
      printf("Commands:\n"
             "i = insert\n"
             "r = remove\n"
             "s = search\n"
             "f = full_table\n"
             "e = empty_table\n"
             "p = print_table\n"
             "d = dealloc\n"
             "\nPlease enter a command: ");

      /* input command */
      command = fgetc(stdin);

      /* determine test based on command */
      switch(command)
      {
         /* test insert */
         case 'i':
            printf("\nEnter name and age of a person to insert into table: ");
            scanf("%s", name);
            scanf("%d", &age);
            temp = strdup(name);
            
            if(insert(this_table, temp, age))
            {
               table[occupancy++] = create_person(temp, age, table_size);
               printf("\n%s with age %d has been inserted into the table.\n\n"
                      , name, age);
            }
            else
               printf("\nInsertion failure, table not updated.\n\n");
            
            free(temp);
         break;

         /* test remove */
         case 'r':
            printf("\nEnter the name and age of a person to remove from "
                   "the table: ");
            scanf("%s", name);
            scanf("%d", &age);
            temp = strdup(name);

            if(Remove(this_table, temp, age))
            {
               printf("\n%s with age %d has been removed from the table.\n\n"
                      , name, age);
               delete_person(table[--occupancy]);
            }
            else
               printf("\nRemoval failure, table not updated.\n\n");

            free(temp);
         break;

         /* test search */
         case 's':
            printf("\nEnter the name and age of a person to search in the "
                   "table: ");
            scanf("%s", name);
            scanf("%d", &age);
            temp = strdup(name);
            
            int index = search(this_table, temp, age);

            if(index != -1)
               printf("\n%s with age %d is located in index %d of the "
                      "table.\n\n", name, age, index);
            else
               printf("\n%s with age %d is not in the table.\n\n", name, age);

            free(temp);
         break;

         /* test full_table */
         case 'f':
            if(full_table(this_table))
               printf("\nThe table is full.\n\n");
            else
               printf("\nThe table is not full.\n\n");
         break;

         /* test empty_table */
         case 'e':
            if(empty_table(this_table))
               printf("\nThe table is empty.\n\n");
            else
               printf("\nThe table is not empty.\n\n");
         break;

         /* test print_table */
         case 'p':
            printf("\n");
            print_table(this_table);
            printf("\n");
         break;

         /* terminate the program */
         case 'd':
            cont = 0;
            
            for(index = 0; index < occupancy; ++index)
                  delete_person(table[index]);
         break;

         /* invalid command */
         default:
            printf("\n%c is not a valid command.\n\n", command);
         break;
      }

      /* clean the buffer */
      while(command != '\n')
         command = getchar();
   }

   /* delete something else to stop memory leaks */
   dealloc(this_table);

   /* exit code sucess */
   return 0;
}
