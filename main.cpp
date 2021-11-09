/*
Project 3 - Part 1c / 5
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

1) write the 10th UDT
    come up with an object that is made of 5 smaller parts.
    These parts will not be defined using Primitives, but instead will be their own UDTs you'll define in Part 1d
    
    Here is an example:
    Cell Phone

    A Cell Phone is made up of the following 5 properties:
        Display
        Memory
        CPU
        Radio
        Applications

    A Cell Phone has 3 things it can do:
        make a call
        send a text
        run an application.

    Notice that I did not use "has a display" or "Has memory" or "has a cpu" as one of the properties of the CellPhone
    
    Writing 'has a ___" checks whether or not your object **has the ability to do something**.
    Instead, I wrote "Display" or "CPU".  These are specific objects or amounts. 
    
    In C++ terms, this means to I want you to avoid using 'bool' (has a) as a member variable type.
    Instead, prefer the other primitive types.

    When you choose your 5 smaller parts, remember that each of these 5 Sub Objects will need 
    to be defined with 5 primitive properties and 3 actions EACH.  

2) write the name of the primitive type you'll be using after each property in UDTs 1-4:
    pick properties that can be represented with 'int float double bool char std::string'
    example: 
        Display:
            Number of Pixels (int)
            Amount of Power consumed (milliwatt-hours) (float)
            Brightness (double)
            area in cm2 (int)
            brand (std::string)

3) Move the Thing 10 pseudo-code to after your Thing1-4 in the project.
*/

/*
Thing 10) Tube Guitar Amp Combo
5 properties:
    1) Power Supply
    2) Output Section
    3) Preamp Section
    4) EQ Controls (or Tone Stack)
    5) Speaker Cabinet
3 things it can do:
    1) Turn on / off
    2) Adjust guitar EQ
    3) Amplify guitar sound
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
