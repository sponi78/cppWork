void Fight::Kaempfen(void){



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
