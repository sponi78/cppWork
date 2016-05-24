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
