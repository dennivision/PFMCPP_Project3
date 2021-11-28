/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to EACH of your types. 
 
 2) inside these new member functions, use while() and for() loops to do something interesting 
         a) example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
    Your code should produce a lot of console output now.
 
 5) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //1), 2c) 
    {
        Bar bar(startingVal);                //2a)
        while( bar.num < threshold )         //2a) 
        { 
            bar.num += 1;                    //2a)
            std::cout << "  increasing bar.num: " << bar.num << std::endl; //4)
            if( bar.num >= threshold )       //2b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //3) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //4) 
    return 0;
}
}

//call Example::main() in main()





#include <iomanip>
#include <vector>
struct AquariumTank
{
    float waterCapacity = 10.f;
    float pHLevel = 7.f;
    float currentWaterLevel = 0.7f;
    float evaporationRate = 0.005f;
    int fishLivingIn = 0;
    struct Fish
    {
        std::string name, breed;
        float maxSalinity, age, maxAge;
        Fish() : name("new fish"), breed("betta"), maxSalinity(0.75f), age(0.f), maxAge(3.f)
        { 
            std::cout << "AquariumTank::Fish '" <<  name << "' was created" << std::endl;
            std::cout << "    it is a '" <<  breed << "'" <<std::endl;
            std::cout << "    and can live in water with a salinity level of up to " << maxSalinity << std::endl;
            std::cout << std::endl;
        }

        bool canLiveInThisWater(float waterPH, float waterSalinity)
        {
            if((waterPH >= 6.f && waterPH <= 8.f) && (waterSalinity < maxSalinity))
            {
                std::cout << "a fish named '" <<  name << "' can live in water with a pH of " << waterPH << " and a salintiy of " << waterSalinity << std::endl;
                return true;
            }
            std::cout << "a fish named '" <<  name << "' can NOT live in water with a pH of " << waterPH << " and a salintiy of " << waterSalinity << std::endl;
            return false;
        }
        void ageFish(float amountOfTime)
        { 
            age += amountOfTime;
            std::cout << "AquariumTank::Fish " <<  name << " is this old: " << age << std::endl;
        }
        bool isStillAlive(float waterPH, float waterSalinity)
        {
            return (canLiveInThisWater(waterPH, waterSalinity) && (age < maxAge));
        }
    };

    AquariumTank();

    void addFish(Fish fish, int quantity);
    void addWater(float amountOfWater);
    void adjustPH(float phAdjustment);


    void ageTank(int days);
};

AquariumTank::AquariumTank() :
waterCapacity(15.f),
pHLevel(7.f),
currentWaterLevel(0.8f),
evaporationRate(0.25f),
fishLivingIn(0)
{
    std::cout << "an AquariumTank was created" << std::endl; 
}

void AquariumTank::addFish(AquariumTank::Fish fish, int quantity)
{
    if( fish.canLiveInThisWater(pHLevel, 0.f) )
    {
        std::cout << "AquariumTank::addFish() addding " << quantity << " fish" << std::endl; 
        fishLivingIn += quantity;
    }
    else
    {
        std::cout << "AquariumTank::addFish() just killed " << quantity << " fish" << std::endl; 
    }
}

void AquariumTank::addWater(float amountOfWater)
{
    float currentWaterAmount = waterCapacity * currentWaterLevel;
    std::cout   << "AquariumTank::addWater() trying to add " << std::defaultfloat << amountOfWater << " gallons of water to a "
                << waterCapacity << " gallon tank"
                << " that's filled to " << std::fixed << (100 * currentWaterLevel) << "% of its capacity" << std::endl; 
    currentWaterAmount += amountOfWater;
    if(currentWaterAmount > waterCapacity)
    {
        std::cout << "AquariumTank::addWater() just spilled " << std::defaultfloat << currentWaterAmount - waterCapacity << " gallons!" << std::endl; 
        currentWaterAmount = waterCapacity;
    }

    currentWaterLevel = currentWaterAmount / waterCapacity;
    std::cout   << "AquariumTank::addWater() new water level: " << std::fixed << (100 * currentWaterLevel)
                << "% of " << std::defaultfloat <<  waterCapacity << " gallons" << std::endl; 
}

void AquariumTank::adjustPH(float phAdjustment)
{
    pHLevel += phAdjustment;
    if(pHLevel > 14.f)
        pHLevel = 14.f;

    if(pHLevel < 0.f)
        pHLevel = 0.f;

    std::cout << "AquariumTank::adjustPH() new pH level: " << pHLevel << std::endl; 
}

void AquariumTank::ageTank(int days)
    {
        float currentWaterAmount = waterCapacity * currentWaterLevel;
        float waterEvaporated = 0;
        int i = 0;
        bool exitFlag = false;
        while (i < days)
        {
            ++i;
            waterEvaporated += evaporationRate;
            currentWaterAmount -= evaporationRate;
            if ( currentWaterAmount <= 0.f)
            {
                exitFlag = true;
                currentWaterAmount = 0.f;
            }
            currentWaterLevel = currentWaterAmount / waterCapacity;
            std::cout << "AquariumTank::ageTank() day " << std::defaultfloat << i << " water level: " << std::setprecision(4) << std::fixed << (100 * currentWaterLevel) << "%" << std::endl; 
            if (exitFlag)
            {
                std::cout << "AquariumTank::ageTank() managed to kill " << std::defaultfloat << fishLivingIn << " fish " << std::endl;
                fishLivingIn = 0;
                break;
            }
        }
        std::cout << "AquariumTank::ageTank() after " << std::defaultfloat << i << " days a total of " << std::setprecision(2) << waterEvaporated << " gallons of water evaporated" << std::endl; 
    }

struct Museum
{
    int exhibitCount = 5;
    int employeeCount = 0;
    float UtilityCost = 3500.f;
    float monthlyRetailIncome = 5000.f;
    float monthlyGovernmentSubsidy = 15000;

    float balance = 0.f;
    float averageSalary = 3000.f;
    float entranceFee = 25.f;

    struct Visitor
    {
        std::string name, nationality;
        int timesVisited, age;
        float satisfaction = 0.5f;

        Visitor() : name("visitor"), nationality("unknown"), timesVisited(0), age(0), satisfaction(0.5f)
        {
            std::cout << "a Museum::Visitor named '" << name << "' from the country '" << nationality << "' was created" << std::endl; 
        }

        float payAdmissionFee(float feeAmount)
        {
            ++timesVisited; // bit confused why this doesn't appear to update the timesVisited int
            std::cout   << "Museum::Vistor:payAdmissionFee() - A visitor named '" << name << "' payed an admmission fee of $"
                        << std::fixed << feeAmount << " and has now visited " << timesVisited << " times" << std::endl;
            return feeAmount;
        }
        
        void viewExhibit(int exhibitNum);
        void payVendor(int vendorID, float amount);
    };

    Museum();

    float chargeVisitor(float amountToCharge, Visitor visitor) ;
    void addOrRemoveEmployees(int numberOfEmployees) { employeeCount += numberOfEmployees; }
    void lobbyPoliticians(float bribeAmount);

    void simulateMonths(int months);
};

Museum::Museum()
{
    std::cout << "a Museum object was created" << std::endl; 
}

float Museum::chargeVisitor(float amountToCharge, Museum::Visitor visitor)
{
    std::cout << "Museum::chargeVisitor() a vistor named '" << visitor.name << "' was charged $" << amountToCharge << std::endl; 
    return visitor.payAdmissionFee(amountToCharge);
}

void Museum::lobbyPoliticians(float bribeAmount)
{
    if(bribeAmount > 10000.f)
    {
        std::cout << "Museum::lobbyPoliticians() success! $" << std::fixed << bribeAmount << " dollars was a large enough bribe!" << std::endl;std::cout << std::defaultfloat; // reset the io stream to clear formatting 
        monthlyGovernmentSubsidy += 2500;
        return;
    }
    std::cout << "Museum::lobbyPoliticians() sad trombone sound. Better luck next time cheapskate." << std::endl; 
}

void Museum::Visitor::viewExhibit(int exhibitNum)
{
    std::cout << "Museum::Vistor:viewExhibit() - A visitor named '" << name << "' viewed exhibit # " << exhibitNum << std::endl;
}

void Museum::Visitor::payVendor(int vendorID, float amount)
{
    std::cout   << "Museum::Vistor:payVendor() - A visitor named '" << name << "' payed vendor # " << vendorID
                << " $" << std::fixed << std::setprecision(2) << amount << std::endl;
}

void Museum::simulateMonths(int months)
{
    
    int visitors = 0;
    float startingBalance = balance;
    int month = 0;
    while(month < months)
    {
        ++month;
        int visitorsThisMonth = monthlyRetailIncome / entranceFee;
        int deviation = visitorsThisMonth * 20 / 100;
        visitorsThisMonth = (rand() % deviation) + (visitorsThisMonth - (deviation / 2));
        std::cout << "In month " << month << " there were " << visitorsThisMonth << " visitors" << std::endl;
        int lastVisitor = visitors + visitorsThisMonth;
        while(visitors <= lastVisitor)
        {
            ++visitors;
            /*
            Visitor x;
            balance += chargeVisitor(entranceFee, x);
            */
            balance += entranceFee; // just to save output lines here
        }
        balance += monthlyGovernmentSubsidy;
        if(balance < (employeeCount * averageSalary))
        {
            std::cout << "Museum cant pay " << employeeCount << " employees. Max it can pay is " << (balance / averageSalary) << std::endl;
            int employeesToFire = employeeCount - (balance / averageSalary);
            employeeCount -= employeesToFire;
            std::cout << "Had to fire " << employeesToFire << " employees" << std::endl;
        }
        balance -= employeeCount * averageSalary;

        std::cout << "Month " << month << " balance is  $" << std::fixed << std::setprecision(2) << balance << std::endl;
    }
    monthlyRetailIncome = ((balance - (monthlyGovernmentSubsidy * month) + (employeeCount * averageSalary * month) - startingBalance) /  month);
    std::cout    << "After " << month << " months the musuem had " << visitors << " visitors and now has a balance of $"
                << std::fixed << balance << " and the average monthly retail income is now $"
                << monthlyRetailIncome << std::endl;

}

struct SubwooferFactory
{
    float plywoodInStock = 0.f;
    int subwooferDriversInStock = 20;
    int numberOfEmpoyees = 0;
    float averageNumberOfSubwoofersCompletedEachDay = 0;
    int completedSubwoofers = 0;

    SubwooferFactory();
    bool assembleSubwoofer(float plywoodAmount, int driverAmount);
    void purchasePlywood(int sheets, float thickness);
    bool sellSubwoofer(float price);

    void makeAFewSubwoofers();
};

SubwooferFactory::SubwooferFactory()
{
    std::cout << "a SubwooferFactory object was created" << std::endl;
}

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
        std::cout << "SubwooferFactory::purchasePlywood() Success! There is now " << plywoodInStock << " feet of plywood in stock" << std::endl;
        return;
    }
    std::cout << "SubwooferFactory::purchasePlywood() 3/4\" plywood is needed! " << thickness << " is not a valid thickness." << std::endl;
}

bool SubwooferFactory::sellSubwoofer(float price)
{
    if(completedSubwoofers > 0 && price > 1.f)
    {
        --completedSubwoofers;
        std::cout << "SubwooferFactory::sellSubwoofer() success! There are " << completedSubwoofers << " completed subwoofers in stock." << std::endl; 
        return true;
    }
    return false;
}

void SubwooferFactory::makeAFewSubwoofers()
{
     int r = rand() % 10 + 1;
     int i = 0;
     while(i < r)
     {
         ++i;
         if(!assembleSubwoofer(3.f, 1))
            break;
     }
     std::cout << "SubwooferFactory::makeAFewSubwoofers() made " << i << " subwoofers out of " << r << " attempts" << std::endl;
}

struct FreightTrain
{
    int numberOfLocomotives = 1;
    int numberOfFreightCars = 1;
    float maxCargoWeight { numberOfLocomotives * 8000.f };
    float grossCargoWeight { numberOfFreightCars * 110.f };
    std::string conductorName = "conductor";

    FreightTrain();

    void proceedToNextStop();
    void pickupOrDropoffCars(int numOfCars);
    void blowAirHorn(float durationInSeconds);

    //void proceedSomeStops(unsigned int stops, int pickupDropOffList[]);
    void proceedSomeStops(unsigned int stops, std::vector<int> pickupDropOffList);
};

FreightTrain::FreightTrain()
{
    std::cout << "FreightTrain constructor called - a FreightTrain object was created" << std::endl;
}

void FreightTrain::proceedToNextStop()
{
    blowAirHorn(5.f);
    std::cout << "FreightTrain::proceedToNextStop() - the train proceeds to the next stop" << std::endl;
}

void FreightTrain::pickupOrDropoffCars(int numOfCars)
{
    numberOfFreightCars += numOfCars;
    if (numberOfFreightCars < 0)
        numberOfFreightCars = 0;

    std::cout << "FreightTrain::pickupOrDropoffCars() called - train now has " << numberOfFreightCars << " cars" << std::endl; 
}

void FreightTrain::blowAirHorn(float durationInSeconds)
{
    if (durationInSeconds > 0.f)
    {
        std::cout << "FreightTrain::blowAirHorn() called - the horn toots for " << durationInSeconds << " seconds." << std::endl; 
    }
}

/*
void FreightTrain::proceedSomeStops(unsigned int stops, int pickupDropoffList[])
{
    unsigned int stopsTraveled = 0;
    int freightCarDelta = 0;
    while(stopsTraveled < stops)
    {
        proceedToNextStop();
        if(stopsTraveled < sizeof pickupDropoffList )
        {
            pickupOrDropoffCars(pickupDropoffList[stopsTraveled]);
            freightCarDelta += pickupDropoffList[stopsTraveled];
        }
        ++stopsTraveled;
    }
    std::cout << "Train Traveled a total of " << stopsTraveled << " out of " << stops << " and the car count changed by " << freightCarDelta << std::endl;
}
*/

void FreightTrain::proceedSomeStops(unsigned int stops, std::vector<int> pickupDropoffList)
{
    unsigned int stopsTraveled = 0;
    int freightCarDelta = 0;
    while(stopsTraveled < stops)
    {
        proceedToNextStop();
        if(stopsTraveled < pickupDropoffList.size() )
        {
            pickupOrDropoffCars(pickupDropoffList[stopsTraveled]);
            freightCarDelta += pickupDropoffList[stopsTraveled];
        }
        ++stopsTraveled;
    }
    std::cout << "Train Traveled a total of " << stopsTraveled << " out of " << stops << " and the car count changed by " << freightCarDelta << std::endl;
}

struct PowerSupply
{
    float mainsInputVoltage, mainOutputVoltage, heaterOutputVoltage, maximumCurrentInAmps;
    bool fuseState;

    PowerSupply();

    void setPowerState(bool powerState);
    void setStandbyState(bool standbyState);
    void blowFuse(); //{ fuseState = false;}

    bool powerState = false;
    bool standbyState = false;
    float powerTransformerMainRatio = 4.f;
    float powerTransformerHeaterRatio = 0.055f;

    void randomlyFlipSwitches(int cycles);
};

PowerSupply::PowerSupply() : mainsInputVoltage(115.f), mainOutputVoltage(0.f), heaterOutputVoltage(0.f), maximumCurrentInAmps(.4f), fuseState(true)
{
    std::cout   << "a PowerSupply object was created with a mains input voltage of " << std::fixed << mainsInputVoltage 
                << " that can supply " << maximumCurrentInAmps << std::defaultfloat << "A current"  << std::endl;
}

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
    std::cout << "PowerSupply::setPowerState() Power switch is in " << ( (powerState) ? "ON" : "OFF" ) << " position" << std::endl; 
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
    std::cout << "PowerSupply::setStandbyState() Standby switch is in " << ( (standbyState) ? "ON" : "STANDBY" ) << " position" << std::endl; 
}

void PowerSupply::blowFuse()
{
    fuseState = false;
    mainOutputVoltage = 0;
    heaterOutputVoltage = 0;
    std::cout << "PowerSupply::blowFuse() Poof! the fuse has blown" << std::endl;
}

void PowerSupply::randomlyFlipSwitches(int cycles)
{
    for(int i = 0; i<cycles; ++i)
    {
        setPowerState((rand() % 2) == 1);
        setStandbyState((rand() % 2) == 1);
    }
    std::cout   << "PowerSupply::randomlyFlipSwitches() Results:" << std::endl << "  Power is " << ( (powerState) ? "ON" : "OFF" )
                << " and Standby is " << ( (standbyState) ? "ON" : "STANDBY" ) << std::endl; 
}

struct OutputSection
{
    int numberOfOutputTubes = 2;
    float gridBiasVoltage = -50.f;
    double outputTransformerPrimaryImpedance { 2600 };
    float outputTransformerSecondaryImpedance = 8.f;
    float maxOutputPower = 50.f;

    OutputSection();

    void warmUpTubes(float timeInMSTillWarm);
    void adjustMasterOutputVolume(float newVolume);
    float amplifyLineLevelAudioToSpeakerLevel(float inputSignal);

    bool tubesAreWarm = false;
    float masterOutputGain = 0.5f;
    float gainFactor = numberOfOutputTubes * 24.f;

    void randomNoise(float maxLevel, int cycles);
};

OutputSection::OutputSection()
{
    std::cout << "an OutputSection object was created" << std::endl;
}

void OutputSection::warmUpTubes(float timeInMSTillWarm)
{
    tubesAreWarm = true;
    std::cout << "OutputSection::warmUpTubes() It took " << timeInMSTillWarm << " milliseconds to warm up the output tubes." << std::endl; 
}

void OutputSection::adjustMasterOutputVolume(float newVolume)
{
    masterOutputGain = newVolume;
    std::cout << "OutputSection::adjustMasterOutputVolume() The master output volume is now " << masterOutputGain << std::endl; 
}

float OutputSection::amplifyLineLevelAudioToSpeakerLevel(float inputSignal)
{
    if(tubesAreWarm)
    {
        std::cout << "OutputSection::amplifyLineLevelAudioToSpeakerLevel() makes some sound" << std::endl; 
        return (inputSignal * gainFactor * masterOutputGain); 
    }
    std::cout << "OutputSection::amplifyLineLevelAudioToSpeakerLevel() does nothing because the tubes arent warm" << std::endl; 
    return 0.f;
}

void OutputSection::randomNoise(float maxLevel, int cycles)
{
    for (int i = 0; i < cycles; ++i)
    {
        float x = rand() / (RAND_MAX / maxLevel);
        float n = amplifyLineLevelAudioToSpeakerLevel(x);
        std::cout   << "OutputSection produces voltage of " << std::fixed << n << "V"
                << " from a " << x << "V noise input signal" << std::defaultfloat << std::endl;
    }
}

struct PreampSection
{
    int numberOfPreampTubes = 2;
    float channelOneGain = 0.33f;
    float channelTwoGain = 0.33f;
    int activeChannel = 0;
    int stageTwoBiasResistorValue = 820;

    PreampSection();

    void warmUpTubes(float timeInMSTillWarm);
    void adjustChannelGain(int channel, float gain);
    float amplifyGuitarSignalToLineLevel(float inputSignal);

    bool tubesAreWarm = false;
    float gainFactor = numberOfPreampTubes * 10.f;

    void randomNoise(float maxLevel, int cycles);
};

PreampSection::PreampSection()
{
    std::cout << "a PreampSection object was created" << std::endl;
}

void PreampSection::warmUpTubes(float timeInMSTillWarm)
{
    tubesAreWarm = true;
    std::cout << "PreampSection::warmUpTubes() It took " << timeInMSTillWarm << " milliseconds to warm up the preamp tubes." << std::endl;
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
    
    std::cout << "PreampSection::adjustChannelGain() Set channel " << ( (channel == 0) ? "one" : "two" ) << " gain to " << gain << std::endl;
}

float PreampSection::amplifyGuitarSignalToLineLevel(float inputSignal)
{
    if(tubesAreWarm)
    {
        float s = inputSignal * gainFactor;
        if(activeChannel == 0)
        {
            std::cout << "PreampSection::amplifyGuitarSignalToLineLevel() channel one makes some sound" << std::endl;
            return (s * channelOneGain);
        }
        else if(activeChannel == 1)
        {
            std::cout << "PreampSection::amplifyGuitarSignalToLineLevel() channel two makes some sound" << std::endl;
            return (s * channelTwoGain);
        }
        else
            return 0.f;
    }
    return 0.f;
}

void PreampSection::randomNoise(float maxLevel, int cycles)
{
    for (int i = 0; i < cycles; ++i)
    {
        float x = rand() / (RAND_MAX / maxLevel);
        float n = amplifyGuitarSignalToLineLevel(x);
        std::cout   << "PreampSection produces voltage of " << std::fixed << n << "V"
                << " from a " << x << "V noise input signal" << std::defaultfloat << std::endl;
    }
}

struct EQControls
{
    float trebleSetting = 0.5f;
    float midrangeSetting = 0.5f;
    float lowSetting = 0.5f;
    float presenceSetting { 0.5f };
    bool isBypassed = false;

    EQControls();

    void adjustTrebleSetting(float value);
    void adjustBassSetting(float value);
    void setBypass(bool value);

    void randomlyTurnKnobs(int cycles);
};

EQControls::EQControls()
{
    std::cout << "an EQControls object was created" << std::endl;
}

void EQControls::adjustTrebleSetting(float value)
{
    trebleSetting = value;
    std::cout << "EQControls::adjustTrebleSetting() trebleSetting is now: " << trebleSetting << std::endl;
}

void EQControls::adjustBassSetting(float value)
{
    lowSetting = value;
    std::cout << "EQControls::adjustBassSetting() lowSetting is now: " << lowSetting << std::endl;
}

void EQControls::setBypass(bool value)
{
    isBypassed = value;
    std::cout << "EQControls::setBypass() EQ control bypass setting is " << ( (isBypassed) ? "ON" : "OFF" ) << std::endl;
}

void EQControls::randomlyTurnKnobs(int turns)
{
    for(int i = 0; i < turns ; ++i)
    {
        int knobToTurn = rand() % 3;
        if(knobToTurn == 0)
        {
            trebleSetting = rand() / RAND_MAX;
            std::cout << "Randomly set treble knob to " << std::fixed << (100 * trebleSetting) << "%" << std::endl;
        }
        else if (knobToTurn == 1)
        {
            midrangeSetting = rand() / RAND_MAX;
            std::cout << "Randomly set midrange knob to " << std::fixed << (100 * midrangeSetting) << "%" << std::endl;
        }
        else if (knobToTurn == 2)
        {
            lowSetting = rand() / RAND_MAX;
            std::cout << "Randomly set bass knob to " << std::fixed << (100 * lowSetting) << "%" << std::endl;
        }
        else if (knobToTurn == 3)
        {
            presenceSetting = rand() / RAND_MAX;
            std::cout << "Randomly set presence knob to " << std::fixed << (100 * presenceSetting) << "%" << std::endl;
        }

    }
}

struct SpeakerCabinet
{
    int numberOfSpeakers = 1;
    int speakerDiameter = 12;
    int maxWattage = 70;
    float impedance = 8.f;
    float maxFrequency = 6000.f;

    SpeakerCabinet();

    float convertPowerToSound( float inputVoltage );
    void setAttenuatorValue( float value );
    void releaseMagicSmoke();

    bool speakersNotBlown = true;
    float attenuation = 1.f;

    void randomlySetAttenuator(int cycles);
};

SpeakerCabinet::SpeakerCabinet()
{
    std::cout << "a SpeakerCabinet object was created" << std::endl;
}

float SpeakerCabinet::convertPowerToSound(float inputVoltage)
{
    if(speakersNotBlown)
    {
        float wattageRequsted = inputVoltage * (inputVoltage / impedance) * attenuation;
        float pascalsPerWatt = 2; // - using pascals because dB logarithmic stuff hard without framework to do math for me
        if(wattageRequsted <= maxWattage * 1.1f)
        {
            std::cout << "SpeakerCabinet::convertPowerToSound() speaker cabinet makes some sound" << std::endl;
            // convert votage to assuming 2 pascals per watt 
            return(inputVoltage * (pascalsPerWatt * wattageRequsted));
        }
        releaseMagicSmoke();
    }
    return 0;
}

void SpeakerCabinet::setAttenuatorValue(float value)
{
    attenuation = value;
    std::cout << "SpeakerCabinet::setAttenuatorValue() attenuation value is now: " << attenuation << std::endl;

}

void SpeakerCabinet::releaseMagicSmoke()
{
    std::cout << "SpeakerCabinet::releaseMagicSmoke() pfffft!" << std::endl;
    speakersNotBlown = false;
}

void SpeakerCabinet::randomlySetAttenuator(int cycles)
{
    for(int i = 0; i < cycles ; ++i)
    {
        setAttenuatorValue(rand() / RAND_MAX);
    }
    std::cout << "SpeakerCabinet::randomlySetAttenuator final value: " << attenuation << " after " << cycles << " cycles " << std::endl;
}

struct TubeGuitarAmpCombo
{
    PowerSupply ps;
    OutputSection outputSection;
    PreampSection preampSection;
    EQControls eq;
    SpeakerCabinet cabinet;

    TubeGuitarAmpCombo();

    void setPowerState( bool value );
    void adjustEQ( int band, float value );
    float amplifyGuitarSound( float guitarSignal );

    void amplifyRandomNoise(float maxLevel, int cycles);
};

TubeGuitarAmpCombo::TubeGuitarAmpCombo()
{
    std::cout << "a TubeGuitarAmpCombo object was created" << std::endl;
}

void TubeGuitarAmpCombo::setPowerState(bool value)
{
    ps.setPowerState(value);
    if(ps.heaterOutputVoltage > 0.f)
    {
        outputSection.warmUpTubes(200.f);
        preampSection.warmUpTubes(100.f);
    }
    std::cout << "TubeGuitarAmpCombo::setPowerState() ps.powerState = " << ps.powerState << std::endl;
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

float TubeGuitarAmpCombo::amplifyGuitarSound(float guitarSignal)
{
    if (ps.fuseState && ps.powerState && ps.standbyState)
    {
        std::cout << "TubeGuitarAmpCombo::amplifyGuitarSound() amp is about to make sound\r";
        float preampOutput = preampSection.amplifyGuitarSignalToLineLevel(guitarSignal);
        float powerAmpOutput = outputSection.amplifyLineLevelAudioToSpeakerLevel(preampOutput);
        return cabinet.convertPowerToSound(powerAmpOutput);
    }
    std::cout << "TubeGuitarAmpCombo::amplifyGuitarSound() cant amplify sound because of one or more of the following: \n";
    std::cout << "Power is " << ( (ps.powerState) ? "ON" : "OFF" ) << std::endl;
    std::cout << "Standby is " << ( (ps.standbyState) ? "ON" : "STANDBY" ) << std::endl;
    std::cout << "Fuse is " << ( (ps.fuseState) ? "GOOD" : "BLOWN" ) << std::endl;
    return 0;
}

void TubeGuitarAmpCombo::amplifyRandomNoise(float maxLevel, int cycles)
{
    for (int i = 0; i < cycles; ++i)
    {
        float x = rand() / (RAND_MAX/maxLevel);
        float n = amplifyGuitarSound(x);
        std::cout << "TubeGuitarAmpCombo noise " << std::fixed << n << " Pascals "
                << "from a " << x << "V noise signal" << std::defaultfloat << std::endl;
    }
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
void printSpacer(std::string msg)
{
    std::cout << std::endl;
    std::cout << "-------- " << msg << " --------" << std::endl;
    std::cout << std::endl;
}

void printEmptyLine()
{
    std::cout << std::endl;
}

#include <iostream>
int main()
{
    Example::main();

    std::cout << std::setprecision(2);

    srand(  time( nullptr ) );

    printSpacer("AquariumTank object testing");

    AquariumTank::Fish fish1,fish2;

    printEmptyLine();

    fish1.name = "uno";
    fish2.name = "due";

    fish1.ageFish(1.f);
    fish2.ageFish(1.f);

    printEmptyLine();;

    AquariumTank tank1, tank2;

    printEmptyLine();

    tank1.waterCapacity = 55.f;
    tank1.currentWaterLevel = .5f;
    tank1.addWater(20.f);
    tank1.addFish(fish1, 10);
    tank1.adjustPH(-.5f);

    tank1.ageTank(10);

    printEmptyLine();

    tank2.addWater(5.f);
    tank2.adjustPH(1.5f);
    tank2.addFish(fish2, 5);
    tank2.adjustPH(-1.f);
    tank2.addFish(fish2, 4);

    tank2.ageTank(120);

    printSpacer("Museum Object Testing");

    Museum::Visitor visitor1, visitor2;

    printEmptyLine();

    visitor1.name = "Bert";
    visitor2.name = "Ernie";

    Museum m1, m2;
    m1.exhibitCount = 5;
    m2.exhibitCount = 10;

    printEmptyLine();

    m1.addOrRemoveEmployees(10);
    std::cout << "Museum m1 now has " << m1.employeeCount << " employees" << std::endl;
    m1.addOrRemoveEmployees(-8);
    std::cout << "Museum m1 now has " << m1.employeeCount << " employees" << std::endl;
    float m1Revenue = m1.chargeVisitor(10.f, visitor1);
    m1Revenue += m1.chargeVisitor(20.f, visitor2);
    std::cout << "Museum m1 extracted $" << std::fixed << m1Revenue << " from vistors" << std::defaultfloat << std::endl;
    m1.lobbyPoliticians(20000);

    
    m1.simulateMonths(6);

    printEmptyLine();

    m2.addOrRemoveEmployees(40);
    std::cout << "Museum m2 now has " << m2.employeeCount << " employees" << std::endl;
    float m2Revenue = m2.chargeVisitor(25, visitor2);
    m2Revenue += m2.chargeVisitor(10.f, visitor1);
    std::cout << "Museum m2 extracted $" << std::fixed << m2Revenue << " from vistors" << std::defaultfloat << std::endl;
    m2.lobbyPoliticians(4999.5);
    m2.monthlyRetailIncome = 100000.f;
    m2.simulateMonths(12);
    m2.addOrRemoveEmployees(10);
    m2.simulateMonths(12);

    printEmptyLine();

    visitor1.viewExhibit(1);
    visitor1.viewExhibit(4);
    visitor1.payAdmissionFee(25.f);
    visitor1.payVendor(4, 4.99f);

    printSpacer("SubwooferFactory object testing");
    SubwooferFactory factory1, factory2;
    factory1.purchasePlywood(10, .5f);
    factory1.purchasePlywood(10, .75f);

    bool result = factory1.sellSubwoofer(500.f);
    std::cout   << "SubwooferFactory::sellSubwoofer() result = " << ((result) ? "Success" : "No Sale")
                << " There are " << factory1.completedSubwoofers << " completed subwoofers in stock." << std::endl; 

    result = factory1.assembleSubwoofer(5.f,2);

    std::cout   << "SubwooferFactory::assembleSubwoofer() result = " << ((result) ? "Assembly Completed" : "Couldn't Assemble")
                << " There are " << factory1.completedSubwoofers << " completed subwoofers in stock." << std::endl; 

    printEmptyLine();

    factory2.purchasePlywood(3, .75f);
    
    result = factory2.assembleSubwoofer(5.f,2);

    std::cout   << "SubwooferFactory::assembleSubwoofer() result = " << ((result) ? "Assembly Completed" : "Couldn't Assemble")
                << " There are " << factory1.completedSubwoofers << " completed subwoofers in stock." << std::endl;

    result = factory2.sellSubwoofer(500.f);
    std::cout   << "SubwooferFactory::sellSubwoofer() result = " << ((result) ? "Success" : "No Sale")
                << " There are " << factory1.completedSubwoofers << " completed subwoofers in stock." << std::endl;

    printEmptyLine();



    factory2.purchasePlywood(10,.75f);
    factory2.subwooferDriversInStock += 20;
    factory2.makeAFewSubwoofers();
    printEmptyLine();
    factory2.makeAFewSubwoofers();
    printEmptyLine();
    factory2.makeAFewSubwoofers();

    std::cout   << "SubwooferFactory after makeAFewSubwoofers()  was excuted 3 times "
                << " there are " << factory1.completedSubwoofers << " completed subwoofers in stock." << std::endl;

    printSpacer("FreightTrain object testing");

    FreightTrain train1;
    train1.pickupOrDropoffCars(50);
    train1.proceedToNextStop();
    train1.blowAirHorn(1.f);

    printEmptyLine();

    FreightTrain train2;
    train2.pickupOrDropoffCars(80);
    train2.proceedToNextStop();
    train2.pickupOrDropoffCars(-40);
    train2.blowAirHorn(1.f);

    printEmptyLine();
    //int dropofflist[]{5,-1,4,-4,3}; 
    std::vector<int> dropofflist{5,-1,4,-4,3};
    train2.proceedSomeStops(5, dropofflist);

    printSpacer("PowerSupply object testing");

    PowerSupply ps1;
    ps1.setStandbyState(false);
    ps1.setPowerState(true);
    ps1.setStandbyState(true);
    ps1.setStandbyState(false);
    ps1.blowFuse();

    printEmptyLine();

    PowerSupply ps2;
    ps2.setPowerState(true);
    ps2.setStandbyState(true);
    ps2.blowFuse();
    ps2.setPowerState(false);
    
    printEmptyLine();

    ps2.randomlyFlipSwitches(10); // new roadie

    printSpacer("OutputSection object testing");
    
    OutputSection outputSection;
    outputSection.warmUpTubes(200.f);
    outputSection.adjustMasterOutputVolume(0.5f);
    float inV = 1;
    float outV = outputSection.amplifyLineLevelAudioToSpeakerLevel(inV);
    std::cout   << "outputSection produces voltage of " << std::fixed << outV << "V"
                << " from a " << inV << "V input" << std::defaultfloat << std::endl;
    inV = .5;
    outV = outputSection.amplifyLineLevelAudioToSpeakerLevel(inV);
    std::cout   << "outputSection produces voltage of " << std::fixed << outV << "V"
                << " from a " << inV << "V input" << std::defaultfloat << std::endl;

    outputSection.randomNoise(0.01f, 10);
    printSpacer("PreampSection object testing");
    
    PreampSection preampSection;
    
    preampSection.adjustChannelGain(0, .9f);
    float preampInV = 0.05f;
    float preampOutV = preampSection.amplifyGuitarSignalToLineLevel(preampInV);
    std::cout   << "preampSection produces voltage of " << std::fixed << preampOutV << "V"
                << " from a " << preampInV << "V input" << std::defaultfloat << std::endl;
    preampSection.warmUpTubes(100.f);
    preampOutV = preampSection.amplifyGuitarSignalToLineLevel(preampInV);
    std::cout   << "preampSection produces voltage of " << std::fixed << preampOutV << "V"
                << " from a " << preampInV << "V input" << std::defaultfloat << std::endl;

    preampSection.randomNoise(0.01f, 20);

    printSpacer("EQControls object testing");

    EQControls eq;
    eq.adjustTrebleSetting(.75f);
    eq.adjustBassSetting(.8f);
    eq.setBypass(true);

    eq.randomlyTurnKnobs(8);

    printSpacer("SpeakerCabinet object testing");

    SpeakerCabinet spkr;
    spkr.setAttenuatorValue(.9f);
    float speakerLevelVoltage = 10.f;
    float cabinetOutput = spkr.convertPowerToSound(speakerLevelVoltage);
    std::cout   << "SpeakerCabinet produces acoustic output of " << std::fixed << cabinetOutput << " Pascals "
                << "from a " << speakerLevelVoltage << "V input voltage" << std::defaultfloat << std::endl;
    speakerLevelVoltage = 30.f;
    cabinetOutput = spkr.convertPowerToSound(speakerLevelVoltage);
    std::cout   << "SpeakerCabinet produces acoustic output of " << std::fixed << cabinetOutput << " Pascals "
                << "from a " << speakerLevelVoltage << "V input voltage" << std::defaultfloat << std::endl;

    spkr.randomlySetAttenuator(5);

    printSpacer("TubeGuitarAmpCombo object testing");
    TubeGuitarAmpCombo amp;
    amp.setPowerState(true);
    amp.adjustEQ(0, 1.f);
    float guitarSignal = 0.04f;
    float ampOutput = amp.amplifyGuitarSound(guitarSignal);
    std::cout   << "TubeGuitarAmpCombo produces acoustic output of " << std::fixed << ampOutput << " Pascals "
                << "from a " << guitarSignal << "V guitar input voltage" << std::defaultfloat << std::endl;
    
    printEmptyLine();

    amp.ps.setStandbyState(true);
    ampOutput = amp.amplifyGuitarSound(guitarSignal);
    std::cout   << "TubeGuitarAmpCombo produces acoustic output of " << std::fixed << ampOutput << " Pascals "
                << "from a " << guitarSignal << "V guitar input voltage" << std::defaultfloat << std::endl;
    printEmptyLine();
    guitarSignal = 0.06f;
    ampOutput = amp.amplifyGuitarSound(guitarSignal);
    std::cout   << "TubeGuitarAmpCombo produces acoustic output of " << std::fixed << ampOutput << " Pascals "
                << "from a " << guitarSignal << "V guitar input voltage" << std::defaultfloat << std::endl;
    printEmptyLine();
    guitarSignal = 0.1f;
    ampOutput = amp.amplifyGuitarSound(guitarSignal);
    std::cout   << "TubeGuitarAmpCombo produces acoustic output of " << std::fixed << ampOutput << " Pascals "
                << "from a " << guitarSignal << "V guitar input voltage" << std::defaultfloat << std::endl;
    printEmptyLine();
    guitarSignal = 0.15f;
    ampOutput = amp.amplifyGuitarSound(guitarSignal);
    std::cout   << "TubeGuitarAmpCombo produces acoustic output of " << std::fixed << ampOutput << " Pascals "
                << "from a " << guitarSignal << "V guitar input voltage" << std::defaultfloat << std::endl;
    printEmptyLine();
    guitarSignal = 0.2f;
    ampOutput = amp.amplifyGuitarSound(guitarSignal);
    std::cout   << "TubeGuitarAmpCombo produces acoustic output of " << std::fixed << ampOutput << " Pascals "
                << "from a " << guitarSignal << "V guitar input voltage" << std::defaultfloat << std::endl;
    printEmptyLine();

    TubeGuitarAmpCombo amp2;
    amp2.setPowerState(true);
    amp2.ps.setStandbyState(true);
    amp2.amplifyRandomNoise(.15f, 10);
                
  
    std::cout << "good to go!" << std::endl;
}
