/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
    add a std::cout message in the constructor that prints out the name of the class being constructed.  
    When you run your code, you'll see the order that your objects are created in the program output. 
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of each of your user-defined types in the main() function.

 4) For each instantiated UDT: 
        call each of that instance's member functions.
        You're doing this to show that your code doesn't produce warnings when you call the functions that take arguments.
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int a; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    a = 0;
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << a << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'a' equal to 0? " << (foo.a == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.




struct AquariumTank
{
    float waterCapacity = 10.f;
    float pHLevel = 7.f;
    float currentWaterLevel = 0.7f;
    double evaporationRate = 0.0000005;
    int fishLivingIn = 0;
    struct Fish
    {
        std::string Name = "new fish";
        std::string Breed = "Goldfish";
        float maxSalinity = 0.5f;
        float age = 0.f;
        float maxAge = 3.f;
        ~Fish(){}

        bool canLiveInThisWater(float waterPH, float waterSalinity)
        {
            if((waterPH >= 6.f && waterPH <= 8.f) && (waterSalinity < maxSalinity))
                return true;
            return false;
        }
        void ageFish(float amountOfTime);
        bool isStillAlive(float waterPH, float waterSalinity)
        {
            return (canLiveInThisWater(waterPH, waterSalinity) && (age < maxAge));
        }
    };
    void addFish(Fish fish, int quantity);
    void addWater(float amountOfWater);
    void adjustPH(float phAdjustment);
};

void AquariumTank::addFish(AquariumTank::Fish fish, int quantity)
{
    if( fish.canLiveInThisWater(pHLevel, 0.f) )
    {
        fishLivingIn += quantity;
    }
}

void AquariumTank::addWater(float amountOfWater)
{
    float currentWaterAmount = waterCapacity * currentWaterLevel;
    currentWaterAmount += amountOfWater;
    if(currentWaterAmount > waterCapacity)
        currentWaterAmount = waterCapacity;

    currentWaterLevel = currentWaterAmount / waterCapacity;
}

void AquariumTank::adjustPH(float phAdjustment)
{
    pHLevel += phAdjustment;
    if(pHLevel > 14.f)
        pHLevel = 14.f;

    if(pHLevel < 0.f)
        pHLevel = 0.f;
}

struct Museum
{
    int exhibitCount = 5;
    int employeeCount = 0;
    float UtilityCost = 3500.f;
    float monthlyRetailIncome = 5000.f;
    double monthlyGovernmentSubsidy = 15000;

    struct Visitor
    {
        std::string name = "visitor";
        std::string nationality = "visitorsNationality";
        int timesVisited = 0;
        int age = 0;
        float satisfaction = 0.5f;

        float payAdmissionFee(float feeAmount) { return feeAmount; }
        void viewExhibit(int exhibitNum);
        void payVendor(int vendorID, float amount);
    };

    float chargeVisitor(float amountToCharge, Visitor visitor) ;
    void addOrRemoveEmployees(int numberOfEmployees) { employeeCount += numberOfEmployees; }
    void lobbyPoliticians(float bribeAmount);
};

float Museum::chargeVisitor(float amountToCharge, Museum::Visitor visitor)
{
    return visitor.payAdmissionFee(amountToCharge);
}

void Museum::lobbyPoliticians(float bribeAmount)
{
    if(bribeAmount > 10000.f)
    {
        monthlyGovernmentSubsidy += 2500;
    }
}


struct SubwooferFactory
{
    float plywoodInStock = 0.f;
    int subwooferDriversInStock = 0;
    int numberOfEmpoyees = 0;
    float averageNumberOfSubwoofersCompletedEachDay = 0;
    int completedSubwoofers = 0;

    bool assembleSubwoofer(float plywoodAmount, int driverAmount);
    void purchasePlywood(int sheets, float thickness);
    bool sellSubwoofer(float price);
};

bool SubwooferFactory::assembleSubwoofer(float plywoodAmount, int driverAmount)
{
    if (plywoodAmount <= plywoodInStock && driverAmount <= subwooferDriversInStock)
    {
        plywoodInStock -= plywoodAmount;
        subwooferDriversInStock -= driverAmount;
        ++completedSubwoofers;
        return true;
    }
    return false;
}

void SubwooferFactory::purchasePlywood(int sheets, float thickness)
{
    if (thickness == 0.75f)
    {
        plywoodInStock += (sheets * 8.f);
    }
}

bool SubwooferFactory::sellSubwoofer(float price)
{
    if(completedSubwoofers > 0 && price > 1.f)
    {
        --completedSubwoofers;
        return true;
    }
    return false;
}

struct FreightTrain
{
    int numberOfLocomotives = 1;
    int numberOfFreightCars = 1;
    float maxCargoWeight { numberOfLocomotives * 8000.f };
    float grossCargoWeight { numberOfFreightCars * 110.f };
    std::string conductorName = "conductor";

    void proceedToNextStop();
    void pickupOrDropoffCars(int numOfCars);
    void blowAirHorn(float durationInSeconds);
};

void FreightTrain::proceedToNextStop()
{
    blowAirHorn(5.f);
}

void FreightTrain::pickupOrDropoffCars(int numOfCars)
{
    numberOfFreightCars += numOfCars;
    if (numberOfFreightCars < 0)
        numberOfFreightCars = 0;
}

void FreightTrain::blowAirHorn(float durationInSeconds)
{
    if (durationInSeconds > 0.f)
    {
        // do something noisy for durationInSeconds
    }
}

struct PowerSupply
{
    float mainsInputVoltage = 115.f;
    float mainOutputVoltage = 0.f;
    float heaterOutputVoltage = 0.f;
    float maximumCurrentInAmps = 1.f;
    bool fuseState { true };

    void setPowerState(bool powerState);
    void setStandbyState(bool standbyState);
    void blowFuse(); //{ fuseState = false;}

    bool powerState = false;
    bool standbyState = false;
    float powerTransformerMainRatio = 4.f;
    float powerTransformerHeaterRatio = 0.055f;
};

void PowerSupply::setPowerState(bool state)
{
    powerState = state;
    if(fuseState)
    {
        if(powerState)
        {
            heaterOutputVoltage = mainsInputVoltage * powerTransformerHeaterRatio;
            if (standbyState)
                mainOutputVoltage = mainsInputVoltage * powerTransformerMainRatio;
        }
        else
        {
            mainOutputVoltage = 0.f;
            heaterOutputVoltage = 0.f;
        }
    }
}

void PowerSupply::setStandbyState(bool state)
{
    standbyState = state;
    if(fuseState)
    {
        if (standbyState)
            mainOutputVoltage = mainsInputVoltage * powerTransformerMainRatio;
        else
            mainOutputVoltage = 0.f;
    }
}

void PowerSupply::blowFuse()
{
    fuseState = false;
    mainOutputVoltage = 0;
    heaterOutputVoltage = 0;
}

struct OutputSection
{
    int numberOfOutputTubes = 2;
    float gridBiasVoltage = -50.f;
    double outputTransformerPrimaryImpedance { 2600 };
    float outputTransformerSecondaryImpedance = 8.f;
    float maxOutputPower = 50.f;

    void warmUpTubes(float timeInMSTillWarm);
    void adjustMasterOutputVolume(float newVolume);
    float amplifyLineLevelAudioToSpeakerLevel(float inputSignal);

    bool tubesAreWarm = false;
    float masterOutputGain = 0.5f;
    float gainFactor = numberOfOutputTubes * 24.f;

};

void OutputSection::warmUpTubes(float timeInMSTillWarm)
{
    if (timeInMSTillWarm < 1000)
    {
        tubesAreWarm = true;
    }
}

void OutputSection::adjustMasterOutputVolume(float newVolume)
{
    masterOutputGain = newVolume;
}

float OutputSection::amplifyLineLevelAudioToSpeakerLevel(float inputSignal)
{
    if(tubesAreWarm)
        return (inputSignal * gainFactor * masterOutputGain);
    return 0.f;
}

struct PreampSection
{
    int numberOfPreampTubes = 2;
    float channelOneGain = 0.33f;
    float channelTwoGain = 0.33f;
    int activeChannel = 0;
    int stageTwoBiasResistorValue = 820;

    void warmUpTubes(float timeInMSTillWarm);
    void adjustChannelGain(int channel, float gain);
    float amplifyGuitarSignalToLineLevel(float inputSignal);

    bool tubesAreWarm = false;
    float gainFactor = numberOfPreampTubes * 50.f;
};

void PreampSection::warmUpTubes(float timeInMSTillWarm)
{
    if (timeInMSTillWarm < 1000)
    {
        tubesAreWarm = true;
    }
}

void PreampSection::adjustChannelGain(int channel, float gain)
{
    if(channel == 0)
    {
        channelOneGain = gain;
    }
    else
    {
        channelTwoGain = gain;
    }
}

float PreampSection::amplifyGuitarSignalToLineLevel(float inputSignal)
{
    if(tubesAreWarm)
    {
        float s = inputSignal * gainFactor;
        if(activeChannel == 0)
            return (s * channelOneGain);
        else if(activeChannel == 1)
            return (s * channelTwoGain);
        else
            return 0.f;
    }
    return 0.f;
}

struct EQControls
{
    float trebleSetting = 0.5f;
    float midrangeSetting = 0.5f;
    float lowSetting = 0.5f;
    float presenceSetting { 0.5f };
    bool isBypassed = false;

    void adjustTrebleSetting(float value);
    void adjustBassSetting(float value);
    void setBypass(bool value);
};

void EQControls::adjustTrebleSetting(float value)
{
    trebleSetting = value;
}

void EQControls::adjustBassSetting(float value)
{
    lowSetting = value;
}

void EQControls::setBypass(bool value)
{
    isBypassed = value;
}

struct SpeakerCabinet
{
    int numberOfSpeakers = 1;
    int speakerDiameter = 12;
    int maxWattage = 70;
    float impedance = 8.f;
    float maxFrequency = 6000.f;

    double convertPowerToSound( float inputVoltage );
    void setAttenuatorValue( float value );
    void releaseMagicSmoke();

    bool speakersNotBlown = true;
};

double SpeakerCabinet::convertPowerToSound(float inputVoltage)
{
    if(speakersNotBlown)
    {
        float wattageRequsted = inputVoltage * (inputVoltage / impedance);
        double pascalsPerWatt = 2; // - using pascals because dB logarithmic stuff hard without framework to do math for me
        if(wattageRequsted <= maxWattage * 1.1f)
        {
            // convert votage to assuming 2 pascals per watt 
            return(static_cast<double>(inputVoltage) * (pascalsPerWatt * static_cast<double>(wattageRequsted)));
        }
        releaseMagicSmoke();
    }
    return 0;
}

void SpeakerCabinet::releaseMagicSmoke()
{
    speakersNotBlown = false;
}

struct TubeGuitarAmpCombo
{
    PowerSupply ps;
    OutputSection outputSection;
    PreampSection preampSection;
    EQControls eq;
    SpeakerCabinet cabinet;

    void setPowerState( bool value );
    void adjustEQ( int band, float value );
    double amplifyGuitarSound( float guitarSignal );
};

void TubeGuitarAmpCombo::setPowerState(bool value)
{
    ps.setPowerState(value);
    if(ps.heaterOutputVoltage > 0.f)
    {
        outputSection.warmUpTubes(200.f);
        preampSection.warmUpTubes(100.f);
    }
}

void TubeGuitarAmpCombo::adjustEQ(int band, float value)
{
    if (band == 0) // lowSetting
    {
        eq.adjustBassSetting(value);
    }
    else if (band == 2) // trebleSetting
    {
        eq.adjustTrebleSetting(value);
    }
}

double TubeGuitarAmpCombo::amplifyGuitarSound(float guitarSignal)
{
    if (ps.fuseState && ps.powerState && ps.standbyState)
    {
        float preampOutput = preampSection.amplifyGuitarSignalToLineLevel(guitarSignal);
        float powerAmpOutput = outputSection.amplifyLineLevelAudioToSpeakerLevel(preampOutput);
        return cabinet.convertPowerToSound(powerAmpOutput);
    }
    return 0;
}
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
    Example::main();
    
    
    std::cout << "good to go!" << std::endl;
}
