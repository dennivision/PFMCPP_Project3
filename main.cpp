/*
Project 3 - Part 1e / 5
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

Convert your 10 Plain-english UDTs into code.

I recommend compiling after finishing each one and making sure it compiles 
without errors or warnings before moving on to writing the next UDT. 

1) define an empty struct below your plain-english UDT. i.e.:

Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#if false //ignore these #if #endif lines. they're just here to prevent compiler errors.
struct CarWash
{

};
#endif
/*
    - Do this for all 10 UDTs

2) Below your plain-english UDT, Copy your 5 properties & 3 actions into the empty struct body.
    - comment them out.
    - Do this for all 10 UDTs
    
3) declare your member variables and member functions underneath each plain-english comment in your struct's body.
    - give the member variables relevant data types
    - Do this for all 10 UDTs
 
4) make the function parameter list for those member functions use some of your User-Defined Types
    - You'll write definitions/implementations for these functions in Project3 Part2
    - you'll call each of these functions in Project3 part3
    - Do this for all 10 UDTs
 
5) make 2 of the 10 user-defined types have a nested class.  
    - this nested class also needs 5 properties and 3 actions.
    - these nested classes are not considered one of your 10 UDTs.
    - this nested class must be related to the class it is nested inside
 
6) your 10th UDT's properties should be instances of your #5-#9 UDTs.   
    - No primitives allowed!
 
7) After you finish defining each type, click the [run] button.  
    Clear up any errors or warnings as best you can. 
    if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

/*
 example:  

Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>

struct CarWash //                                   1) define an empty struct for each of your 10 types.       
{
    //number of vacuum cleaners                     2) copied and commented-out plain-english property
    int numVacuumCleaners = 3; //                   3) member variables with relevant data types.
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car //5)                                 Note that the nested type 'Car' is related to the 'CarWash' 
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        //3) a member function whose parameter has a default value.
        //the parameter name is related to the work the function will perform.
        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar(Car carA); //4) a member function whose parameter is a UDT.
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior(Car carB);
    
    //5) a member variable whose type is a UDT.
    Car carBeingServiced;  

    /*
    Pay attention to the member functions that take an instance of 'Car'
    Notice that there is a member variable of the same type.

    It makes sense to pass a Car to the function 'washAndWaxCar' because car washes service MANY cars
    However, they only service ONE car at a time.
    the carBeingServiced's value would change every time you wash and wax the car. 

    I see many students who write code emulating this format, but their usage does not make logical sense.  
    Consider the following snippet:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        // train their skills
        void trainPlayerSkills(Manager managerA);
    
        Manager teamManager;
    };

    It does not make sense to pass in a new Manager whenever you are going to train your team players.
    Soccer teams have ONE manager.

    a much more relevant usage would be adding a member function that hires a new manager:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        void hireNewManager(Manager newManager);
    
        Manager teamManager;
    };

    We can safely assume that the 'Manager' instance that is being passed in will be replacing the current 'teamManager' variable without looking at any other code.
    This is because the function name and function argument clearly indicate what they are/what they do.

    Your function names and parameter names should make LOGICAL SENSE.
    Readers of your code should be able to INTUITIVELY understand what your function implementations will do without actually seeing the implementations.

    Keep this in mind when you define your UDTs in this project part.
    */
};


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

 struct AquariumTank
 {
    //1) the capacity of water it holds (float)
    float waterCapacity = 10.f;
    //2) the pH level of the water (float)
    float pHLevel = 7.f;
    //3) the current water level (float)
    float currentWaterLevel = 0.7f;
    //4) the amount of water that evaporates each day (double)
    double evaporationRate = 0.0000005;
    //5) the number of fish living in it (int)
    int fishLivingIn = 0;

    struct Fish
    {
      std::string Name = "new fish";
      std::string Breed = "Goldfish";
      float maxSalinity = 0.5f;
      float age = 0.f;
      float maxAge = 3.f;

      //
      bool canLiveInThisWater(float waterPH, float waterSalinity);
      void ageFish(float amountOfTime);
      bool isStillAlive(float waterPH, float waterSalinity)
      {
          return (canLiveInThisWater(waterPH, waterSalinity) && (age < maxAge));
      }
    };
    // 1) add fish
    void addFish(Fish fish, int Quantity);
    // 2) add water
    void addWater(float amountOfWater);
    // 3) adjust pH
    void adjustPH(float phAdjustment);
    
 };

/*
Thing 2) Museum
5 properties:
    1) the number of exhibits (int)
    2) the number of employees (int)
    3) the total cost of utilities used each month (float)
    4) the monthly retail income amount (float)
    5) the amount of government subsidy recieved each month (double)
3 things it can do:
    1) charge visitor
    2) add or remove employees
    3) lobby politicians for more government funding
 */
struct Museum
{
  // 1) the number of exhibits (int)
  int exhibitCount = 5;
  // 2) the number of employees (int)
  int employeeCount = 0;
  // 3) the total cost of utilities used each month (float)
  float UtilityCost = 3500.f;
  // 4) the monthly retail income amount (float)
  float monthlyRetailIncome = 5000.f;
  //5) the amount of government subsidy recieved each month (double)
  double monthlyGovernmentSubsidy = 15000;

  struct Visitor
  {
    std::string name = "visitor";
    std::string nationality = "visitorsNationality";
    int timesVisited = 0;
    int age = 0;
    float satisfaction = 0.5f;

    float payAdmissionFee(float feeAmount);
    void viewExhibit(int exhibitNum);
    void payVendor(int vendorID, float amount);
  };

  // 1) charge visitor
  void chargeVisitor(float amountToCharge, Visitor visitor) ;
  // 2) add or remove employees
  void addOrRemoveEmployees(int numberOfEmployees) { employeeCount += numberOfEmployees; }
  // 3) lobby politicians for more government funding
  void lobbyPoliticians(float bribeAmount);
};
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
struct SubwooferFactory
{
  // 1) amount of plywood in stock in boardfeet (float)
  float plywoodInStock = 0.f;
  // 2) number of subwoofer drivers in stock (int)
  int subwwoferDriversInStock = 0;
  // 3) number of employees (int)
  int numberOfEmpoyees = 0;
  // 4) average number of subwoofers completed each day (float)
  float averageNumberOfSubwoofersCompletedEachDay = 0;
  // 5) inventory of completed subwoofers (int)
  int completedSubwoofers = 0;

  // 1) assemble a subwoofer
  bool assembleSubwoofer(float plywoodAmount, int driverAmount);
  // 2) purchase plywood for subwoofers
  void purchasePlywood(int sheets, float thickness);
  // 3) sell a subwoofer
  bool sellSubwoofer(float price);
};
/*
Thing 4) Freight Train
5 properties:
    1) the number of locomotives (int)
    2) the number of freight cars (int)
    3) the maximum cargo weight able to be pulled (float)
    4) the gross cargo weight in tons (float)
    5) the conductors name (std::string)
3 things it can do:
    1) proceed to next stop
    2) pickup / dropoff cars
    3) blow airhorn
 */
struct FreightTrain
{
  // 1) the number of locomotives (int)
  int numberOfLocomotives = 1;
  // 2) the number of freight cars (int)
  int numberOfFreightCars = 1;
  // 3) the maximum cargo weight able to be pulled (float)
  float maxCargoWeight { numberOfLocomotives * 8000.f };
  // 4) the gross cargo weight in tons (float)
  float grossCargoWeight { numberOfFreightCars * 110.f };
  // 5) the conductors name (std::string)
  std::string conductorName = "conductor";
  
  // 1) proceed to next stop
  void proceedToNextStop();
  // 2) pickup / dropoff cars
  void pickupOrDropoffCars(int numOfCars)
  {
    numberOfFreightCars += numOfCars;
  }
  // 3) blow airhorn
  void blowAirHorn(float durationInSeconds);
};
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
struct PowerSupply
{
  // 1) Mains Input voltage (float)
  float mainsInputVoltage = 110.f;
  // 2) Main Output Voltage (Vcc) (float)
  float mainOutputVoltage = 450.f;
  // 3) Heater Output Voltage (float)
  float heaterOutputVoltage = 6.3f;
  // 4) Maximum Current (float)
  float maximumCurrentInAmps = 1.f;
  // 5) Fuse state (bool)
  bool fuseState { true };

  // 1) The mains input voltage can be switched on / off
  void setPowerState(bool powerState);
  // 2) the Main output voltage can be switched on independently (standby)
  void setStandbyState(bool standbyState);
  // 3) The mains fuse can blow
  void blowFuse() { fuseState = false;}
};
/*
Thing 6) Output Section
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
struct OutputSection
{
  // 1) the number of output tubes (int)
  int numberOfOutputTubes = 2;
  // 2) the grid bias voltage (float)
  float gridBiasVoltage = -50.f;
  // 3) the output transformers primary impedance in Ohms (double)
  double outputTransformerPrimaryImpedance { 2600 };
  // 4) the output transformers secondary impedance in Ohms (float)
  float outputTransformerSecondaryImpedance = 8.f;
  // 5) the maximum output power in watts (float)
  float maxOutputPower = 50.f;
  
  // 1) Warm up tubes
  void warmUpTubes(float timeInMSTillWarm);
  // 2) Admust master output volume
  void adjustMasterOutputVolume(float newVolume);
  // 3) Amplify line level audio to a speaker level signal
  float amplifyLineLevelAudioToSpeakerLevel(float inputSignal);
};
/*
Thing 7) Preamp Section
5 properties:
    1) the number of preamp tubes (int)
    2) the gain setting for channel 1 (float)
    3) the gain setting for channel 2 (float)
    4) the active channel (int)
    5) the cathode bias resistor value for the second gain stage (int)
3 things it can do:
    1) warm up tubes
    2) Adjust channel gain setting
    3) Amplify guitar level signal to line voltage level
 */
struct PreampSection
{
  // 1) the number of preamp tubes (int)
  int numberOfPreampTubes = 2;
  // 2) the gain setting for channel 1 (float)
  float channelOneGain = 0.33f;
  // 3) the gain setting for channel 2 (float)
  float channelTwoGain = 0.33f;
  // 4) the active channel (int)
  int activeChannel = 0;
  // 5) the cathode bias resistor value for the second gain stage (int)
  int stageTwoBiasResistorValue = 820;
  
  // 1) warm up tubes
  void warmUpTubes(float timeInMSTillWarm);
  // 2) Adjust channel gain setting
  void adjustChannelGain(int channel, float gain);
  // 3) Amplify guitar level signal to line voltage level
  float amplifyGuitarSignalToSpeakerLevel(float inputSignal);
};
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
struct EQControls
{
  // 1) The high cut (or treble) setting (float)
  float trebleSetting = 0.5f;
  // 2) The midrange cut setting (float)
  float midrangeSetting = 0.5f;
  // 3) The low frequency (or bass) cut setting (float)
  float lowSetting = 0.5f;
  // 4) the amount of out of phase post power amp feedback signal to mix in (presence) (float)
  float presenceSetting { 0.5f };
  // 5) is the EQ tone stack bypassed? (bool)
  bool isBypassed = false;

  //1) Adjust Treble control knob
  void adjustTrebleSetting(float value);
  //2) Adjust Bass control knob
  void adjustBassSetting(float value);
  //3) Turn bypass on/off
  void setBypass(bool value);
};
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
struct SpeakerCabinet
{
  // 1) the number of speakers (int)
  int numberOfSpeakers = 1;
  // 2) the speaker diameter (int)
  int speakerDiameter = 12;
  // 3) the cabinets max wattage (int)
  int maxWattage = 70;
  // 4) the cabinet impedance in ohms (float)
  float impedance = 8.f;
  // 5) the cabinets maximum reproduceable frequency (float)
  float maxFrequency = 6000.f;

  // 1) convert voltage and current to sound
  double convertPowerToSound( float inputVoltage );
  // 2) adjust load attenuator
  void setAttenuatorValue( float value );
  // 3) release magic smoke
  void releaseMagicSmoke();
};
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
struct TubeGuitarAmpCombo
{
  // 1) Power Supply
  PowerSupply ps;
  // 2) Output Section
  OutputSection outputSection;
  // 3) Preamp Section
  PreampSection preampSection;
  // 4) EQ Controls (or Tone Stack)
  EQControls eq;
  // 5) Speaker Cabinet
  SpeakerCabinet cabinet;

  // 1) Turn on / off
  void setPowerState( bool value );
  // 2) Adjust guitar EQ
  void adjustEQ( int band, float value );
  //3) Amplify guitar sound
  double amplifyGuitarSound( float guitarSignal );
};
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
