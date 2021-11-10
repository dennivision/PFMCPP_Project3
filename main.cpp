/*
Project 3 - Part 1d / 5
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

    The goal of this step is to get you to think about breaking down an object into smaller and smaller objects, 
    until the smallest object is made of up only C++ primitives and std::string. 

    Continuing the previous example:  Cell Phone

    A Cell Phone is made up of the following 5 properties/sub-objects and 3 actions:
        Display
        Memory
        CPU
        Radio
        Applications
    3 actions:
        make a call
        send a text
        run an application.

    These 5 properties can be broken down into their own sub-objects and properties. 

    If we break down the first property 'Display' into its 5 properties we get:
        brightness
        amount of power consumed.
        pixels
        width in cm
        height in cm

    the Display's brightness can be represented with a Primitive, such as a double. 

    The amount of power consumed can also be represented with a Primitive, such as a float or integer (i.e. 250mWa)
    
    The 'pixels' property must be represented with an array of Pixel instances, as the screen has more than 1 row of pixels.
        Arrays have not been discussed and can't be used in this project.
        Instead, we can use an Integer primitive to store the Number of Pixels:

    Display:
        Number of Pixels
        Amount of Power consumed (milliwatt-hours)
        Brightness
        width in cm
        height in cm
************************

1) Fill in #5 - #9 with plain-english UDTs for the 5 properties you created for UDT #10
    example: 
        If #10's first property was 'Engine', then your `Thing 5)` will be `Engine`
        you will need to provide 5 properties and 3 member functions of that Engine object in plain English
        Remember to pick properties that can be represented with 'int float double bool char std::string'
2) write the name of the primitive type you'll be using after each property
    pick properties that can be represented with 'int float double bool char std::string'
    example: 
        Display:
            Number of Pixels (int)
            Amount of Power consumed (milliwatt-hours) (float)
            Brightness (double)
            width in cm (int)
            height in cm (int)

3) move Thing 5-9 to between your Thing 4 and Thing 10.
*/

/*
Thing 1) Aquarium Tank
5 properties:
    1) the capacity of water it holds (float)
    2) the pH level of the water (float)
    3) the current water level (float)
    4) the amount of water that evaporates each day (float)
    5) the number of fish living in it (int)
3 things it can do:
    1) add fish
    2) add water
    3) adjust pH
 */

/*
Thing 2) Museum
5 properties:
    1) the number of exhibits (int)
    2) the number of employees (int)
    3) the total cost of utilities used each month (float)
    4) the monthly retail income amount (float)
    5) the amount of government subsidy recieved each month (float)
3 things it can do:
    1) charge visitor
    2) add or remove employees
    3) lobby politicians for more government funding
 */

/*
Thing 3) Subwoofer Factory
5 properties:
    1) amount of plywood in stock in boardfeet (float)
    2) number of subwoofer drivers in stock (int)
    3) number of employees (int)
    4) average number of subwoofers completed each day (float)
    5) inventory of completed subwoofers (int)
3 things it can do:
    1) assemble a subwoofer
    2) purchase materials for subwoofers
    3) sell a subwoofer
 */

/*
Thing 4) Freight Train
5 properties:
    1) the number of locomotives (int)
    2) the number of freight cars (int)
    3) the maximum cargo weight able to be pulled (float)
    4) the gross cargo weight in tons (float)
    5) the trains speed in miles per hour (float)
3 things it can do:
    1) proceed to next stop
    2) pickup / dropoff cars
    3) blow airhorn
 */

/*
Thing 5) Power Supply
5 properties:
    1) Mains Input voltage (float)
    2) Main Output Voltage (Vcc) (float)
    3) Heater Output Voltage (float)
    4) Maximum Current (float)
    5) Fuse state (bool)
3 things it can do:
    1) The mains input voltage can be switched on / off
    2) the Main output voltage can be switched on independently (standby)
    3) The mains fuse can blow
 */

/*
Thing 6)
5 properties:
    1) the number of output tubes (int)
    2) the grid bias voltage (float)
    3) the output transformers primary impedance in  (double)
    4) the output transformers secondary impedance in Ohms (float)
    5) the maximum output power in watts (float)
3 things it can do:
    1) Warm up tubes
    2) Admust master output volume
    3) Amplify line level audio to a speaker level signal
 */

/*
Thing 7) Preamp Section
5 properties:
    1) the number of preamp tubes (int)
    2) the gain setting for channel 1 (float)
    3) the gain setting for channel 2 (float)
    4) the active channel (int)
    5) the grid bias resistor value for the second gain stage (int)
3 things it can do:
    1) warm up tubes
    2) Adjust channel gain setting
    3) Amplify guitar level signal to line voltage level
 */

/*
Thing 8) EQ Controls
5 properties:
    1) The high cut (or treble) setting (float)
    2) The midrange cut setting (float)
    3) The low frequency (or bass) cut setting (float)
    4) the amount of out of phase post power amp feedback signal to mix in (presence) (float)
    5) is the EQ tone stack bypassed? (bool)
3 things it can do:
    1) Adjust Treble control knob
    2) Adjust Bass control knob
    3) Turn bypass on/off
 */

/*
Thing 9) Speaker Cabinet
5 properties:
    1) the number of speakers (int)
    2) the speaker diameter (int)
    3) the cabinets max wattage (int)
    4) the cabinet impedance in ohms (float)
    5) the cabinets maximum reproduceable frequency (float)
3 things it can do:
    1) convert voltage and current to sound
    2) adjust load attenuator
    3) release magic smoke
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
