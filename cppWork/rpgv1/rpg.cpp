#include <iostream>
#include <random>
#include <ctime>
using namespace std;

class Fight
{
public:
    void Kaempfen(void);
int VerlustGegner( void );
int VerlustHeld( void );

    private:
    int  Lebenskraft;
    int  Kraft;
    int Stand[2];
    int vGegner;
    int vHeld;
};
void Fight::Kaempfen(void){

 int zufall=0;
 //  srand((unsigned)time(NULL));

   Stand[0] = rand()%6+1;
   Stand[1] = rand()%6+1;

}
int Fight::VerlustGegner( void )
{
    return Stand[0];
}
int Fight::VerlustHeld( void )
{
    return Stand[1];
}

class Gegner
{
public:
    void setzeLebenskraft (int v );
    int  holeLebenskraft( void );

    void  setzeKraft(int v);
    int  holeKraft(void);
private:
    int Kraft;
    int Lebenskraft;
};

void Gegner::setzeLebenskraft( int v)
{
    Lebenskraft = v;
}
void Gegner::setzeKraft( int v)
{

 int zufall=0;
 //  srand((unsigned)time(NULL));
  zufall= rand()%6+1;
   Kraft = v;
}
int Gegner::holeLebenskraft( void )
{
    return Lebenskraft;
}
int Gegner::holeKraft( void )
{
    return Kraft;
}







class Held
{
public:
    void setzeLebenskraft (int v );
    int  holeLebenskraft( void );

    void  setzeKraft(int v);
    int  holeKraft(void);
private:
    int Kraft;
    int Lebenskraft;
};

void Held::setzeLebenskraft( int v)
{
    Lebenskraft = v;
}
void Held::setzeKraft( int v)
{
int zufall=0;
 //  srand((unsigned)time(NULL));
  zufall= rand()%6+1;
   Kraft = v;
}
int Held::holeLebenskraft( void )
{
    return Lebenskraft;
}
int Held::holeKraft( void )
{
    return Kraft;
}


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
