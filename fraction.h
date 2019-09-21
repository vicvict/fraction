template < class T >
class Fraction
{
private:
    T numerate;
    T denumerate;
public:
    Fraction();
    ~Fraction();
    Fraction (const T &new_numerate, const T &new_denumerate);
    Fraction (const Fraction < T > &new_fraction);

    void set_numerate(const T &new_numerate);
    void set_denumerate(const T &new_denumerate);
    T get_numerate() const;
    T get_denumerate() const;

    Fraction < T > reduction (Fraction < T > &rhs);

    template < class V >
    friend std::ostream& operator << (std::ostream &out, const Fraction < V >  &Fraction);
    template < class V >
    friend std::istream& operator >>(std::istream  &in, Fraction < V > &Fraction);

    Fraction < T > operator + (const Fraction < T > &rhs);
    Fraction < T > operator = (const Fraction < T > &rhs);
    Fraction < T > operator - (const Fraction < T > &rhs);
    Fraction < T > operator * (const Fraction < T > &rhs);
    Fraction < T > operator / (const Fraction < T > &rhs);
};

template < class T >
Fraction <T> :: Fraction(){
    numerate = 0;
    denumerate = 1;
}

template < class T >
Fraction <T> :: Fraction(const T &new_numerate, const T &new_denumerate){
    numerate = new_numerate;
    denumerate = new_denumerate;
}

template < class T >
Fraction <T> :: Fraction(const Fraction < T > &new_fraction ){
    numerate = new_fraction.numerate;
    denumerate = new_fraction.denumerate;
}

template < class T >
Fraction < T > :: ~Fraction(){
}

template < class T >
T Fraction < T > ::get_numerate() const {
    return numerate;
}

template < class T >
T Fraction < T > ::get_denumerate() const {
    return denumerate;
}

template < class T >
void Fraction < T > ::set_numerate(const T &new_numerate){
    numerate = new_numerate;
}

template < class T >
void Fraction < T > ::set_denumerate(const T &new_denumerate){
    denumerate = new_denumerate;
}

template < class T >
Fraction <T> Fraction < T > ::reduction ( Fraction < T > &rhs){
    if (rhs.numerate == 0){
        numerate = rhs.numerate;
        denumerate = 1;
    }
    else
    {
        T old_numerate = rhs.numerate;
        T old_denumerate = rhs.denumerate;
        if (old_numerate < 0)
            old_numerate = -old_numerate;
        while (old_numerate != old_denumerate) {
            if (old_numerate > old_denumerate) {
                T tmp = old_numerate;
                old_numerate = old_denumerate;
                old_denumerate = tmp;
            }
            old_denumerate = old_denumerate - old_numerate;
        }
        numerate = rhs.numerate/old_denumerate;
        denumerate = rhs.denumerate/old_numerate;
    }
    return *this;
}

template < class T >
std::istream  & operator >>(std::istream  &in, Fraction <T> &Fraction)
{
    std::cout << "print numerate \n";
    in >> Fraction.numerate;
    std::cout << "print denumerate \n";
    in >> Fraction.denumerate;
    return in;
}

template < class T >
std::ostream& operator << (std::ostream &out, const Fraction <T>  &Fraction)
{
    out  << Fraction.numerate << "/" << Fraction.denumerate << "\n";
    return out;
}

template < class T >
Fraction <T> Fraction <T>::operator = (const Fraction <T> &rhs){
    if (this == &rhs) {
        return *this;
    }
    numerate = rhs.numerate;
    denumerate = rhs.denumerate;
    return *this;
}

template < class T >
Fraction <T> Fraction<T>::operator + (const Fraction <T> &rhs){
    numerate = numerate * rhs.denumerate + denumerate * rhs.numerate;
    denumerate = denumerate * rhs.denumerate;
    this ->reduction(*this);
    return *this;
}

template < class T >
Fraction < T > Fraction < T >::operator - (const Fraction < T > &rhs){
    numerate = numerate * rhs.denumerate - denumerate * rhs.numerate;
    denumerate = denumerate * rhs.denumerate;
    this ->reduction(*this);
    return *this;
}

template < class T >
Fraction < T > Fraction < T >::operator * (const Fraction < T > &rhs){
    numerate = numerate * rhs.numerate;
    denumerate = denumerate * rhs.denumerate;
    this -> reduction(*this);
    return *this;
}

template < class T >
Fraction < T > Fraction < T >::operator / (const Fraction < T > &rhs){
    numerate = numerate * rhs.denumerate;
    denumerate = denumerate * rhs.numerate;
    this -> reduction(*this);
    return *this;
}

