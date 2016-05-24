#include "Gegner.h"
void Gegner::setzeLebenskraft( int v)
{
    Lebenskraft = v;
}
void Gegner::setzeKraft( int v)
{


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
