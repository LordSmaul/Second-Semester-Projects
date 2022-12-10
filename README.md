# Second-Semester-Projects

This folder contains all of the coding labs and assignments from my second semester in a second introductory Computer Science course at my college. I decided it would be a good idea to post all the files online to preserve them in case I get a new computer.

There are two types of assignments here: Labs and Projects. The labs were given weekly to help the students practice what they had learned in the lectures. The projects were assigned every couple of weeks; they were generally more comprehensive in their scope and supposed to be harder than the labs, and we were given more time to complete them.

All projects have been edited from their original forms: I have taken the liberty of removing personal information (since this folder is public) and reduced the assignments to the source files, executables, and any text files that the programs use.

Here's a quick rundown of the assignments and their goals:

Lab 1: Practice with classes and pointers; sort of a re-cap of the last things we did in the previous semester.
 - Creates a structure called "Course", with mutiple attributes
 - Includes functions for constructing the object, a destructor, and printing the attributes
 
 Lab 2: practice with function recursion
 - constrcuted multiple functions that use recursive tactics to iterate through data
 - Functions include: summing up numbers from 1 to the user input number, checking if a number is a part of an array, reversing a string, checking if a string is a palindrome, and multiplying two numbers
 
 Lab 3: Basic sorting algorithm practice and checking the runtime of each function
 - program sorts through a list of all the words used by the playwright Shakespeare, using the Reverse Bubble Sort, Insertion sort, and the Quicksort sorting algorithms.
 - the program also keeps track of the time that each algorithm takes to sort through the list, and prints it out.
 
Lab 4: Introduction to Abstract Data Types: The List - List of monster names
 - Creates a List object using pointers to connect the individual data points together; instead of using the built-in ADT List structure in C++, we were shown how to do so using pointers as a way of giving us insight into how the ADT works on the back-end.
 - The main function appends a number of monster names into the list alphabetically, inserting some and deleting others.
  
Lab 5: Abstract Data Type: The Stack - Inventory Management
 - Builds a Stack object using the same tactics as the user-defined List.
 - User can create items to add to an inventory, as well as taking off the top item
 - Contains functions for pushing and popping variables
 - the pop() function uses a pass-by-reference variable to pull the top item off the stack
  
Lab 6: Abstract Data Type: The Queue - Managing multiple queues at a them park ride
 - Builds a Queue object using the same tactics as the user-defined list and stack objects from previous labs
 - The program has the user manainging two queues of a ride at a theme park. One queue is for InstantPass holders, who are allowed to go on the ride first, and the other queue is for normal pass holders, who go only when the InstantPass queue is empty.
 -  Contains functions for enqueueing and dequeueing elements, as well as a destructor
 - If elements exist in the queues after the destructor is called, the rider's names are displayed, saying the park is closed and they cannot ride.
 
Lab 7: Introduction to Hash Tables - Costume inventory
 - Creates a HashTable object that holds a pointer array of HashEntry objects
 - Each Hashentry object is composed of a key and a Costume object
 - Includes functions for putting values into the HashTable and printing its values
 - Uses linear probing to handle bucket collisions
 - User creates Costumes from input and place them into the HashTable; the table is then printed out, showing all the attributes.

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
