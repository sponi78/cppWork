#include "Fight.h"
#include <random>
#include <ctime>
#include <iostream>
void Fight::Kaempfen(void){
    int abwehr[2];
    abwehr[0] = rand()%10+1;
    abwehr[1] = rand()%10+1;

    if(abwehr[0]<=5){
        Stand[0]=0;
        std::cout<<"Abgewehrt"<<std::endl;
    }
    else{
   Stand[0] = rand()%10+1;
    }

    if(abwehr[1]<=5){
        Stand[1]=0;
         std::cout<<"Abgewehrt"<<std::endl;
    }
    else{
   Stand[1] = rand()%10+1;
    }

}
int Fight::VerlustGegner( void )
{
    return Stand[0];
}
int Fight::VerlustHeld( void )
{
    return Stand[1];
}
