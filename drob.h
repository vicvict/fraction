template < class T >
class Drobi
{
private:
    T num;
    T den;
public:
    Drobi();
    ~Drobi();
    Drobi (const T &new_num, const T &new_den);
    Drobi (const Drobi < T > &new_drob);

    void set_num(const T &new_num);
    void set_den(const T &new_den);
    T get_num() const;
    T get_den() const;

    Drobi < T > reduction (Drobi < T > &rhs);

    template < class V >
    friend std::ostream& operator << (std::ostream &out, const Drobi < V >  &drobi);
    template < class V >
    friend std::istream& operator >>(std::istream  &in, Drobi < V > &drobi);

    Drobi < T > operator + (const Drobi < T > &rhs);
    Drobi < T > operator = (const Drobi < T > &rhs);
    Drobi < T > operator - (const Drobi < T > &rhs);
    Drobi < T > operator * (const Drobi < T > &rhs);
    Drobi < T > operator / (const Drobi < T > &rhs);
};

template < class T >
Drobi <T> :: Drobi(){
    num = 0;
    den = 0;
}

template < class T >
Drobi <T> :: Drobi(const T &new_num, const T &new_den){
    num = new_num;
    den = new_den;
}

template < class T >
Drobi <T> :: Drobi(const Drobi < T > &new_drob ){
    num = new_drob.num;
    den = new_drob.den;
}

template < class T >
Drobi < T > :: ~Drobi(){
}

template < class T >
T Drobi < T > ::get_num() const {
    return num;
}

template < class T >
T Drobi < T > ::get_den() const {
    return den;
}

template < class T >
void Drobi < T > ::set_num(const T &new_num){
    num = new_num;
}

template < class T >
void Drobi < T > ::set_den(const T &new_den){
    den = new_den;
}

template < class T >
Drobi <T> Drobi < T > ::reduction ( Drobi < T > &rhs){
    if (rhs.num == 0){
        num = rhs.num;
        den = 1;
    }
    else
    {
        T old_num = rhs.num;
        T old_den = rhs.den;
        if (old_num < 0)
            old_num = -old_num;
        while (old_num != old_den) {
            if (old_num > old_den) {
                T tmp = old_num;
                old_num = old_den;
                old_den = tmp;
            }
            old_den = old_den - old_num;
        }
        num = rhs.num/old_den;
        den = rhs.den/old_num;
    }
    return *this;
}

template < class T >
std::istream  & operator >>(std::istream  &in, Drobi <T> &drobi)
{
    std::cout << "print numerate \n";
    in >> drobi.num;
    std::cout << "print denominator \n";
    in >> drobi.den;
    return in;
}

template < class T >
std::ostream& operator << (std::ostream &out, const Drobi <T>  &drobi)
{
    out  << drobi.num << "/" << drobi.den << "\n";
    return out;
}

template < class T >
Drobi <T> Drobi <T>::operator = (const Drobi <T> &rhs){
    if (this == &rhs) {
        return *this;
    }
    num = rhs.num;
    den = rhs.den;
    return *this;
}

template < class T >
Drobi <T> Drobi<T>::operator + (const Drobi <T> &rhs){
    num = num * rhs.den + den * rhs.num;
    den = den * rhs.den;
    this ->reduction(*this);
    return *this;
}

template < class T >
Drobi < T > Drobi < T >::operator - (const Drobi < T > &rhs){
    num = num * rhs.den - den * rhs.num;
    den = den * rhs.den;
    this ->reduction(*this);
    return *this;
}

template < class T >
Drobi < T > Drobi < T >::operator * (const Drobi < T > &rhs){
    num = num * rhs.num;
    den = den * rhs.den;
    this -> reduction(*this);
    return *this;
}

template < class T >
Drobi < T > Drobi < T >::operator / (const Drobi < T > &rhs){
    num = num * rhs.den;
    den = den * rhs.num;
    this -> reduction(*this);
    return *this;
}

