/**---------------------------------------------------------------------------*/
/**--------------------------DO NOT MODIFY THIS FILE--------------------------*/
/**---------------------------------------------------------------------------*/
/*~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
                                                      Author:  Jeremy Cruz
                                                      Date:    5, September 2016
                                 table.h
--------------------------------------------------------------------------------
Purpose: Define the class for a hash table as well as its functions to implement
         along for creating an instance of itself and destroying it.
*=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=*/

#ifndef TABLE_H
#define TABLE_H

#include "person.h"

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Name:       table

Purpose:    Define a hash table structure and create function signitures for 
            what a hash table would be capable of doing.

Methods:    alloc:         allocate memory for this deque

            dealloc:       delete this deque from memory

            insert:        add person to table

            Remove:        remove person from table

            search:        search a person from table

            full_table:    state whether table is full

            empty_table:   state whether table is empty

            print_table:   print elements on the table

Datafields: table:         array of person objects

            occupancy:     current amount of persons

            cap:           max amount of persons to hold

            is_full:       status of cap reached

            is_empty:      status of 0 occupancy
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
struct table
{
   /* datafields */
   prsn ** table;
   unsigned int cap;
   unsigned int occupancy;
   long is_full;
   long is_empty;
};

/* create type definition to reference a table */
typedef struct table tbl;

/* functions */
tbl * alloc(unsigned int);

void dealloc(tbl *);

long insert(tbl *, char *, int);

long Remove(tbl *, char *, int);

int search(tbl *, char *, int);

long full_table(tbl *);

long empty_table(tbl *);

void print_table(tbl *);

#endif
