#include <stdlib.h>
#include <stdio.h>

struct Event 
{
    int parameter;
};

typedef EventDescription int;
typedef RandomVariable int;
typedef PFunction int; 
typedef Mapping int;
typedef Anything int;

typedef Space int;
typedef Set int;

#define Typeof(a) 1
#define Motivation(a) 1

int Ex3_1() 
{
    // Definition of Mapping 
    RandomVariable r1;

    // Is Mapping? 
    // FLow? 
    Anything observation1; 
    Motivation(observation1);

    Motivation(observation1);
    EventDescription e1; // x>=1 


    // Dice definition 
    RandomVariable dice1;
    RandomVariable dice2;

    dice1.Distribution = { 0.5, 0.5 };
    dice2.Distribution = dice1.Distribution;

    // 
    // Following: Theory of 
    // 
    // Invent new formula.
    Transformation? 

    // Calculating P of an Event? 

    typedef AvailableOutput int;
    AvailableOutput av1;
    AvailableOutput av2;




    // P(Event=)=? RandomVariable
    // Mapping between (real-world) & ()

    int nSumDot = 0;
    // Two (identical) dices 
    //  P(count=6 | count % 2 = 0) = ?    
    // 
    Event e1;
    Event e2;

    // 
    // Describle exactly 
    // Automatically resolving 
    // 

    //
    // Describle 
    //
    // Definition of a dice? 
    // Definition 
    // Dice: 1 process mà có 6 kết quả.
    // 
    // System 
    //      Dice. 
    //

    typedef Process int;
    typedef RandomVariable int;

    Process a;
    Process b;
    WholeEco p1;
    WholeEco p2;

    a.depends(b);
    b.depends(c);

    Event twoDice = 0;

    RandomVariable dice1;
    RandomVariable dice2;

    Event evenSum((dice1 + dice2) % 2 == 0);
    Event count6((dice1+dice2)==6);

    a.independent(b);
    p1.run();
    p1.Probability(count6, evenSum);
    double p = p1.Probability(count6, evenSum);

    a.independent(b);

    Completed(Equal(a,b));
    // Number Only 

}