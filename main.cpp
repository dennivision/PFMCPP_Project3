 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
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
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */





 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have warnings about 'unused parameter', you aren't using one of your function parameters in your implementation.
    use the parameter in your implementation.
    If you have warnings about 'overshadow', a local variable in the function has the same name as a class member.
    change the name of your local variable so it is different from the class member's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
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
