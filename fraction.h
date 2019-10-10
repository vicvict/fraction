#pragma once

#define N 10000

template < class T >
class Fraction
{
private:
    T numerate;
    T denumerate;
protected:
    void reduction ();
public:
    Fraction();
    ~Fraction();
    Fraction (const T &new_numerate, const T &new_denumerate);
    Fraction (const Fraction < T > &new_fraction);
    Fraction (const T &new_fraction);
    Fraction (const double &new_fraction);

    void set_numerate(const T &new_numerate);
    void set_denumerate(const T &new_denumerate);
    T get_numerate() const;
    T get_denumerate() const;

    double todouble();

    template < class V >
    friend std::ostream& operator << (std::ostream &out, const Fraction < V >  &Fraction);
    template < class V >
    friend std::istream& operator >>(std::istream  &in, Fraction < V > &Fraction);

    template < class V >
    friend Fraction < V > operator + (const Fraction < V > &lhs , const Fraction < V > &rhs);
    template < class V >
    friend Fraction < V > operator + (const V &lhs , const Fraction < V > &rhs);
    template < class V >
    friend Fraction < V > operator + (const Fraction < V > &lhs , const V &rhs);

    Fraction < T > &operator = (const Fraction < T > &rhs);
    Fraction < T > &operator = (const T &rhs);

    template < class V >
    friend Fraction < V > operator - (const Fraction < V > &lhs , const Fraction < V > &rhs);
    template < class V >
    friend Fraction < V > operator - (const V &lhs , const Fraction < V > &rhs);
    template < class V >
    friend Fraction < V > operator - (const Fraction < V > &lhs , const V &rhs);

    template < class V >
    friend Fraction < V > operator * (const Fraction < V > &lhs , const Fraction < V > &rhs);
    template < class V >
    friend Fraction < V > operator * (const V &lhs , const Fraction < V > &rhs);
    template < class V >
    friend Fraction < V > operator * (const Fraction < V > &lhs , const V &rhs);

    template < class V >
    friend Fraction < V > operator / (const Fraction < V > &lhs , const Fraction < V > &rhs);
    template < class V >
    friend Fraction < V > operator / (const V &lhs , const Fraction < V > &rhs);
    template < class V >
    friend Fraction < V > operator / (const Fraction < V > &lhs , const V &rhs);

    Fraction < T > operator += (const Fraction < T > &rhs);
    Fraction < T > operator -= (const Fraction < T > &rhs);
    Fraction < T > operator *= (const Fraction < T > &rhs);
    Fraction < T > operator /= (const Fraction < T > &rhs);
    Fraction < T > operator += (const T &rhs);
    Fraction < T > operator -= (const T &rhs);
    Fraction < T > operator *= (const T &rhs);
    Fraction < T > operator /= (const T &rhs);
    Fraction < T > operator -();
    Fraction < T > operator +();
    Fraction < T >& operator --();
    Fraction < T >& operator ++();
    Fraction < T > operator --(int);
    Fraction < T > operator ++(int);

    template < class V >
    friend bool operator == (const Fraction < V > &lhs ,const Fraction < V > &rhs);
    template < class V >
    friend bool operator != (const Fraction < V > &lhs ,const Fraction < V> &rhs);
    template < class V >
    friend bool operator > (const Fraction < V > &lhs ,const Fraction < V> &rhs);
    template < class V >
    friend bool operator < (const Fraction < V > &lhs ,const Fraction < V> &rhs);
    template < class V >
    friend bool operator >= (const Fraction < V > &lhs ,const Fraction < V> &rhs);
    template < class V >
    friend bool operator <= (const Fraction < V > &lhs ,const Fraction < V> &rhs);

    template < class V >
    friend bool operator == (const V &lhs ,const Fraction < V > &rhs);
    template < class V >
    friend bool operator != (const V &lhs ,const Fraction < V> &rhs);
    template < class V >
    friend bool operator > (const V &lhs ,const Fraction < V> &rhs);
    template < class V >
    friend bool operator < (const V &lhs ,const Fraction < V> &rhs);
    template < class V >
    friend bool operator >= (const V &lhs ,const Fraction < V> &rhs);
    template < class V >
    friend bool operator <= (const V &lhs ,const Fraction < V> &rhs);

    template < class V >
    friend bool operator == (const Fraction < V > &lhs , const V &rhs);
    template < class V >
    friend bool operator != (const Fraction < V > &lhs , const V &rhs);
    template < class V >
    friend bool operator > (const Fraction < V > &lhs , const V &rhs);
    template < class V >
    friend bool operator < (const Fraction < V > &lhs , const V &rhs);
    template < class V >
    friend bool operator >= (const Fraction < V > &lhs , const V &rhs);
    template < class V >
    friend bool operator <= (const Fraction < V > &lhs , const V &rhs);

    void square();
    void sqrt();
};

template < class T >
Fraction <T> :: Fraction(): numerate(0), denumerate(1){
}

template < class T >
Fraction <T> :: Fraction(const T &new_numerate, const T &new_denumerate): numerate(new_numerate) , denumerate(new_denumerate){
    reduction();
}

template < class T >
Fraction <T> :: Fraction(const Fraction < T > &new_fraction ) : numerate(new_fraction.numerate) ,denumerate(new_fraction.denumerate){
    reduction();
}

template < class T >
Fraction < T > :: Fraction(const T &new_fraction) : numerate(new_fraction) , denumerate(1){
    reduction();
}

template < class T >
Fraction < T > :: Fraction(const double &new_fraction) : numerate(new_fraction*N) , denumerate(N){
    reduction();
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
void Fraction < T > ::reduction (){
    if (denumerate == 0)
    {
        throw -1;
    }
    if (numerate == 0){
        denumerate = 1;
    }
    else
    {
        T old_numerate = numerate;
        T old_denumerate = denumerate;
        while (old_denumerate){
            old_numerate %= old_denumerate;
            std::swap (old_numerate, old_denumerate);
        }
        numerate = numerate/old_numerate;
        denumerate = denumerate/old_numerate;
    }
    if (denumerate < 0){
        numerate = -numerate;
        denumerate = -denumerate;
    }
}

template < class T >
double Fraction < T >::todouble(){
    double double_numerate = numerate;
    return (double_numerate / denumerate);
}

/*template < class T >
pair < int , Fraction < T > > Fraction < T >::tot(){
    int full = numerate / denumerate;
    return (full , Fraction (numerate % denumerate, denumerate));
}*/

template < class T >
std::istream  & operator >>(std::istream  &in, Fraction <T> &Fraction)
{
    std::cout << "enter numerate \n";
    in >> Fraction.numerate;
    std::cout << "enter denumerate \n";
    in >> Fraction.denumerate;
    Fraction.reduction();
    return in;
}

template < class T >
std::ostream& operator << (std::ostream &out, const Fraction <T>  &Fraction)
{
    out  << Fraction.numerate << "/" << Fraction.denumerate << "\n";
    return out;
}

template < class T >
Fraction <T> &Fraction <T>::operator = (const Fraction <T> &rhs){
    if (this == &rhs) {
        return *this;
    }
    numerate = rhs.numerate;
    denumerate = rhs.denumerate;
    return *this;
}

template < class T >
Fraction <T> &Fraction <T>::operator = (const T &rhs){
    numerate = rhs;
    denumerate = 1;
    return *this;
}

template < class T >
Fraction <T> operator + (const Fraction < T > &lhs ,const Fraction <T> &rhs){
    return Fraction < T >(lhs.numerate * rhs.denumerate + lhs.denumerate * rhs.numerate,lhs.denumerate * rhs.denumerate);
}

template < class T >
Fraction <T> operator + (const T &lhs ,const Fraction <T> &rhs){
    return  Fraction < T > (lhs) + rhs;
}

template < class T >
Fraction <T> operator + (const Fraction <T> &lhs ,const T &rhs){
    return  Fraction < T > (rhs) + lhs;
}

template < class T >
Fraction < T > operator - (const Fraction <T> &lhs , const Fraction < T > &rhs){
    return Fraction < T >(lhs.numerate * rhs.denumerate - lhs.denumerate * rhs.numerate,lhs.denumerate * rhs.denumerate);
}

template < class T >
Fraction <T> operator - (const T &lhs ,const Fraction <T> &rhs){
    return  Fraction < T > (lhs) - rhs;
}

template < class T >
Fraction <T> operator - (const Fraction <T> &lhs ,const T &rhs){
    return  lhs - Fraction < int > (rhs);
}

template < class T >
Fraction < T > operator * (const Fraction <T> &lhs , const Fraction < T > &rhs){
    return Fraction < T > (lhs.numerate * rhs.numerate,lhs.denumerate * rhs.denumerate);
}

template < class T >
Fraction <T> operator * (const T &lhs ,const Fraction <T> &rhs){
    return  Fraction < T > (lhs) * rhs;
}

template < class T >
Fraction <T> operator * (const Fraction <T> &lhs ,const T &rhs){
    return  lhs * Fraction < T > (rhs);
}

template < class T >
Fraction < T > operator / (const Fraction < T > &lhs , const Fraction < T > &rhs){
    return Fraction < T >(lhs.numerate * rhs.denumerate,lhs.denumerate * rhs.numerate);
}

template < class T >
Fraction <T> operator / (const T &lhs ,const Fraction <T> &rhs){
    return  Fraction < T > (lhs) / rhs;
}

template < class T >
Fraction <T> operator / (const Fraction <T> &lhs ,const T &rhs){
    return  lhs / Fraction < T > (rhs);
}

template < class T >
Fraction < T > Fraction < T >::operator -(){
    numerate = -numerate;
    return *this;
}

template < class T >
Fraction < T > Fraction < T >::operator +(){
    return *this;
}

template < class T >
Fraction < T > Fraction < T >::operator += (const Fraction < T > &rhs){
    return *this = *this + rhs;
}

template < class T >
Fraction < T > Fraction < T >::operator += (const T &rhs){
    return *this += Fraction < T > (rhs);
}


template < class T >
Fraction < T > Fraction < T >::operator -= (const Fraction < T > &rhs){
  //  numerate = numerate * rhs.denumerate - denumerate * rhs.numerate;
   // denumerate = denumerate * rhs.denumerate;
  //  reduction();
    return *this = *this - rhs;
}

template < class T >
Fraction < T > Fraction < T >::operator -= (const T &rhs){
    return *this -= Fraction < T > (rhs);
}

template < class T >
Fraction < T > Fraction < T >::operator *= (const Fraction < T > &rhs){
   // numerate = numerate * rhs.numerate;
   // denumerate = denumerate * rhs.denumerate;
   // reduction();
    return *this = *this * rhs;
}

template < class T >
Fraction < T > Fraction < T >::operator *= (const T &rhs){
    return *this *= Fraction < T > (rhs);
}

template < class T >
Fraction < T > Fraction < T >::operator /= (const Fraction < T > &rhs){
        //numerate = numerate * rhs.denumerate;
        //denumerate = denumerate * rhs.numerate;
        //reduction();
        return *this = *this/rhs;
}

template < class T >
Fraction < T > Fraction < T >::operator /= (const T &rhs){
    return *this /= Fraction < T > (rhs);
}

template < class T >
Fraction < T >& Fraction < T >::operator --(){
    numerate = numerate - denumerate;
    return *this;
}

template < class T >
Fraction < T >& Fraction < T >::operator ++(){
    numerate = numerate + denumerate;
    return *this;
}

template < class T >
Fraction < T > Fraction < T >::operator ++(int){
    Fraction < T > temp(*this);
    numerate = numerate + denumerate;
    return temp;
}

template < class T >
Fraction < T > Fraction < T >::operator --(int){
    Fraction < T > temp(*this);
    numerate = numerate - denumerate;
    return temp;
}

template < class T >
bool operator == (const Fraction < T > &lhs,const Fraction < T > & rhs){
    bool result = false;
    if ((lhs.numerate == rhs.numerate) && (lhs.denumerate == rhs.denumerate))
        result = true;
    return result;
}

template < class T >
bool operator == (const T &lhs,const Fraction < T > & rhs){
    return (Fraction < T > (lhs) == rhs);
}

template < class T >
bool operator == (const Fraction < T > & lhs, const T &rhs){
    return (Fraction < T > (rhs) == lhs);
}

template < class T >
bool operator != (const Fraction < T > &lhs, const Fraction < T > & rhs){
    return !(lhs == rhs);
}

template < class T >
bool operator != (const T &lhs,const Fraction < T > & rhs){
    return (Fraction < T > (lhs) != rhs);
}

template < class T >
bool operator != (const Fraction < T > & lhs, const T &rhs){
    return (Fraction < T > (rhs) != lhs);
}

template < class T >
bool operator > (const Fraction < T > &lhs,const Fraction < T > & rhs){
    bool result = false;
    if (lhs.numerate * rhs.denumerate > rhs.numerate * lhs.denumerate)
        result = true;
    return result;
}

template < class T >
bool operator > (const T &lhs,const Fraction < T > & rhs){
    return (Fraction < T > (lhs) > rhs);
}

template < class T >
bool operator > (const Fraction < T > & lhs, const T &rhs){
    return (lhs > Fraction < T > (rhs));
}

template < class T >
bool operator < (const Fraction < T > &lhs,const Fraction < T > & rhs){
    bool result = false;
    if (lhs.numerate * rhs.denumerate < rhs.numerate * lhs.denumerate)
        result = true;
    return result;
}

template < class T >
bool operator < (const T &lhs, const Fraction < T > &rhs){
    return (Fraction < T > (lhs) < rhs);
}

template < class T >
bool operator < (const Fraction < T > &lhs, const T &rhs){
    return (lhs < Fraction < T > (rhs));
}

template < class T >
bool operator >= (const Fraction < T > &lhs, const Fraction < T > & rhs){
    return !(lhs < rhs);
}

template < class T >
bool operator >= (const T &lhs,const Fraction < T > & rhs){
    return (Fraction < T > (lhs) >= rhs);
}

template < class T >
bool operator >= (const Fraction < T > & lhs, const T &rhs){
    return (lhs >= Fraction < T > (rhs));
}

template < class T >
bool operator <= (const Fraction < T > &lhs, const Fraction < T > & rhs){
    return !(lhs > rhs);
}

template < class T >
bool operator <= (const T &lhs,const Fraction < T > & rhs){
    return (Fraction < T > (lhs) <= rhs);
}

template < class T >
bool operator <= (const Fraction < T > & lhs, const T &rhs){
    return (lhs <= Fraction < T > (rhs));
}

template < class T >
void Fraction < T > :: square(){
    *this *= *this;
    return;
}

template < class T >
void Fraction < T > :: sqrt() {
    double a = std::sqrt(numerate);
    double b = std::sqrt(denumerate);
    Fraction < int > frac1(a),frac2(b);
    *this = frac1/frac2;
    return;
}

