# compile and test the equals function
equals:
	gcc -g equals.c driver1.c -o driver1

# compile and test person object
person:
	gcc -g person.c driver2.c -o driver2

# compile hash table data structure including the persons it will store
table:
	gcc -g equals.c person.c table.c driver3.c -o driver3

# remove the executables
clean:
	rm driver1 driver2 driver3
