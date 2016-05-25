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
    //Instanzen Gegner und Held werden erstellt
    Gegner *gegner = new Gegner;
    Held *held= new Held;
    //Attribute Lebenskraft und Kraft für Gegner werden gesetzt
    gegner->setzeLebenskraft( 100 );
    gegner->setzeKraft( 100 );
    //Ausgabe zur Kontrolle
    cout << "Der Gegner hat " << gegner->holeLebenskraft() << " Lebenspunkte.\n";
    cout << "Der Gegner hat " << gegner->holeKraft() << " Kraftpunkte.\n";

    //Attribute Lebenskraft und Kraft für Held werden gesetzt
    held->setzeLebenskraft( 100 );
    held->setzeKraft( 100 );
    //Ausgabe zu Kontrolle
    cout << "Der Held hat " << held->holeLebenskraft() << " Lebenspunkte.\n";
    cout << "Der Held hat " << held->holeKraft() << " Kraftpunkte.\n";
    //Instanz für den Kampf erstellen
    Fight *fight=new Fight;
    int weiter=1;
    int runde=0; //Rundenzähler
while(weiter!=0){
        runde++;
        cout<<"Runde: "<<runde<<endl;
        //Methode Kämpfen der Klasse fight wird aufgerufen
        fight->Kaempfen();
        //In der Methode

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
