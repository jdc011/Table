/**---------------------------------------------------------------------------*/
/**--------------------------DO NOT MODIFY THIS FILE--------------------------*/
/**---------------------------------------------------------------------------*/
/*~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
                                                      Author:  Jeremy Cruz
                                                      Date:    5, September 2016
                                   person.h
--------------------------------------------------------------------------------
Purpose: This represents a person object that we will store dynamically in a
         hash table. A person is determined by name and age. A hashcode function
         is included to hash an instance of the person.
*=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=*/
#ifndef PERSON_H
#define PERSON_H

#define HOPS 5    /* determine probe sequence in table */

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Name:       person

Purpose:    Define an object for a person and define functions involving its
            creation, deletion, and hashcode into a hash table.

Methods:    create_person: allocate memory for this person

            delete_person: delete this person from memory

            name_length:   return length of name

            hash_code:     get the hash index into a table

            get_sequence:  create and return the probe sequence

Datafields: probe_sequence:   array of indeces to probe to

            probes:           amount of probes

            name:             name of person

            age:              age of person

            length:           string length of name
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
struct person
{
   /* datafields */
   unsigned int * probe_sequence;
   unsigned int probes;
   char * name;
   unsigned int age;
   unsigned int length;
};

/* create type definition to reference a person */
typedef struct person prsn;

/* functions */
prsn * create_person(char *, unsigned int, unsigned int);

void delete_person(prsn *);

unsigned int name_length(prsn *);

unsigned int hash_code(prsn *, unsigned int);

unsigned int * get_sequence(prsn *, unsigned int);

#endif
