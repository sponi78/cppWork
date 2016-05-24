#include <iostream>
#include <random>
#include <ctime>
#include "held.h"
#include "Gegner.h"
#include "Fight.h"

using namespace std;












int main(int argc, char *argv[])
{
srand((unsigned)time(NULL));

    Gegner *gegner = new Gegner;

    Held *held= new Held;

    gegner->setzeLebenskraft( 100 );
    gegner->setzeKraft( 100 );
    cout << "Der Gegner hat " << gegner->holeLebenskraft() << " Lebenspunkte.\n";
     cout << "Der Gegner hat " << gegner->holeKraft() << " Kraftpunkte.\n";


    held->setzeLebenskraft( 100 );
    held->setzeKraft( 100 );
    cout << "Der Held hat " << held->holeLebenskraft() << " Lebenspunkte.\n";
    cout << "Der Held hat " << held->holeKraft() << " Kraftpunkte.\n";
    Fight *fight=new Fight;
    int weiter=1;
    int runde=0;
while(weiter!=0){
        runde++;
        cout<<"Runde: "<<runde<<endl;
        fight->Kaempfen();


        cout<<"Schaden Gegner: "<<fight->VerlustGegner()<<endl;
        cout<<"Schaden Held:"<<fight->VerlustHeld()<<endl;
        held->setzeLebenskraft( held->holeLebenskraft()-fight->VerlustHeld() );
        gegner->setzeLebenskraft( gegner->holeLebenskraft()-fight->VerlustGegner() );
        cout << "Der Gegner hat " << gegner->holeLebenskraft() << " Lebenspunkte.\n";
        cout << "Der Held hat " << held->holeLebenskraft() << " Lebenspunkte.\n";

if(held->holeLebenskraft()<=0){
    cout<<"Held ist tot!"<<endl;
    weiter=0;
}

if(gegner->holeLebenskraft()<=0){

    cout<<"Gegner ist tot!"<<endl;
    weiter=0;
}
cout<<"--------------------------------------------------"<<endl;
}
    delete gegner;
    delete held;
    delete fight;
    return 0;
}
