/*
Project 3 - Part 1b / 5
Video:  Chapter 2 Part 5
User-Defined Types

Continue your work on branch Part1

Purpose: The entire purpose of this 5-part project is to get you writing C++ code that compiles and to 
reinforce the syntax habits that C++ requires.  
What you create in this project will be used as the basis of Project 5 in the course.   

************************
Part1 purpose:  Learn to write UDTs

You are going to write 10 UDTs in project3.  
Part1 will be broken up into 5 separate steps
    Part 1a: you will learn to think about an object in terms of its sub-objects.
    Part 1b: you will write 4 un-related UDTs in plain english
    Part 1c: you will write 1 UDT in plain english that will be made of 5 related sub-objects
    Part 1d: you will write plain-english UDTs for the 5 sub-objects that form the UDT defined in Part 1c
    Part 1e: you will convert those 10 plain-english UDTs into code that runs.
************************

1)  Fill in #1 - 4 with a random UDT in plain english
    These 4 UDTs do not need to be related.
        a) For each plain-english UDT, write out 5 traits or properties and 3 things it can do
        b) remember: these properties will eventually become primitives.
        pick properties that can be represented with 'int float double bool char std::string'
*/

/*
 example:  
 
Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - the amount of water used per week.
        - amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior

    Notice that I did not use "has a vacuum cleaner" or "Has eco-friendly cleaning supplies" as one of the properties
    
    Writing 'has a ___" checks whether or not your object **has the ability to do something**.
    Instead, I wrote "number of vacuum cleaners" and "number of eco-friendly cleaning supplies".  
    
    These are specific objects or amounts. 
    
    In C++ terms, this means to I want you to avoid using 'bool' (has a) as a member variable type.
    Instead, prefer the other primitive types.

    In addition to the usual primitives (covered in Project 2), you can use 'std::string' to represent strings in this project.
 */

/*
Thing 1) Aquarium Tank
5 properties:
    1) the capacity of water it holds
    2) the pH level of the water
    3) the current water level
    4) the amount of water that evaporates each day
    5) the number of fish living in it
3 things it can do:
    1) add fish
    2) add water
    3) adjust pH
 */

/*
Thing 2) Museum
5 properties:
    1) the number of exhibits
    2) the number of employees
    3) the total cost of utilities used each month
    4) the monthly retail income amount
    5) the amount of government subsidy recieved each month
3 things it can do:
    1) charge visitor
    2) add or remove employees
    3) lobby politicians for more government funding
 */

/*
Thing 3) Subwoofer Factory
5 properties:
    1) amount of plywood in stock
    2) number of subwoofer drivers in stock
    3) number of employees
    4) average number of subwoofers completed each day
    5) inventory of completed subwoofers
3 things it can do:
    1) assemble a subwoofer
    2) purchase materials for subwoofers
    3) sell a subwoofer
 */

/*
Thing 4) Freight Train
5 properties:
    1) the number of locomotives
    2) the number of freight cars
    3) the maximum cargo weight able to be pulled
    4) the gross cargo weight in tons
    5) the trains speed in miles per hour
3 things it can do:
    1) proceed to next stop
    2) pickup / dropoff cars
    3) blow airhorn
 */



/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
