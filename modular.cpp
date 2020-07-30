/* ================================= MODULAR ================================= */

template< class T , T MOD >
class Modular {
private :
    T value;
public:
    using modular = Modular < T , MOD >;
    Modular < T , MOD > () : value(0){}

    explicit Modular< T , MOD > (const T &new_value) : value(new_value % MOD){ if(value < 0){ value += MOD; } }

    modular& operator = (const modular &other) { value = other.value; return *this; }

    bool operator < (const modular &other) const { return value < other.value; }

    bool operator > (const modular &other) const { return value > other.value; }
    
    bool operator == (const modular &other) const { return !(*this < other) && !(*this > other);}

    bool operator != (const modular &other) const { return !(*this == other); }
    
    bool operator <= (const modular &other) const { return !(*this > other); }

    bool operator >= (const modular &other) const { return !(*this < other); }

    friend ostream& operator << (ostream &out, const modular &other) { return out << other.value; }

    friend istream& operator >> (istream &inp, modular &other) { return inp >> other.value; }

    modular& operator += (const modular &x) { value = (value % MOD + x.value % MOD + MOD) % MOD; return *this; }

    modular& operator -= (const modular &x) { value = (value % MOD - x.value % MOD + MOD) % MOD; return *this; }

    modular operator - () const { return modular(0) - *this; }

    modular& operator ++ () { return (*this += modular(1)); }

    modular& operator -- () { return (*this -= modular(1)); }

    modular& operator *= (const modular &x) { value = (long long) (value % MOD) * (x.value % MOD) % MOD; return *this; }
    
    modular operator * (const modular &x){ return (modular(*this) *= x); }

    modular operator + (const modular &x) { return (modular(*this) += x); }

    modular operator - (const modular &x) { return (modular(*this) -= x); }
    
    T powerValue(T h) const {
        T ret = (T)1;
        T tmp_value = value;
        while(h > (T)0){
            if(h % (T)2){
                ret = (ret % MOD) * (tmp_value % MOD) % MOD;
            }
            tmp_value = (tmp_value % MOD) * (tmp_value % MOD);
            h /= (T)2;
        }
        return ret;
    }
    
    T inverseValue() const { return powerValue(MOD - 2); }
    
    modular toPower(T h) const { return modular(powerValue(h)); }
   
    modular toInverse(T h) const { return modular(inverseValue()); }
    
    T getValue() const { return value; }
};
using mod_type = long long;
const mod_type base = (mod_type)1000000007;
using Mint = Modular<mod_type,base>;

/* ================================= MODULAR ================================= */
