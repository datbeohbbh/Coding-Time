template<class T,T MOD>
class Modular {
private :
    T value;
public :
    using modType = Modular <T,MOD>;
public:
    Modular <T,MOD> () {
        value = 0;
    }

    explicit Modular<T,MOD> (const T &new_value) {
        value = new_value % MOD;
        value = (value >= MOD ? value - MOD : (value < 0 ? value + MOD : value));
    }

    modType &operator= (const modType &other) {
        value = other.value;
        return *this;
    }

    bool operator == (const modType &other) const {
        return value == other.value;
    }

    bool operator!= (const modType &other) const {
        return !(value == other.value);
    }

    bool operator< (const modType &other) const {
        return value < other.value;
    }

    bool operator> (const modType &other) const {
        return value > other.value;
    }

    bool operator<= (const modType &other) const {
        return !(value > other.value);
    }

    bool operator>= (const modType &other) const {
        return !(value < other.value);
    }

    friend ostream &operator<< (ostream &out, const modType &other) {
        return out << other.value;
    }

    friend istream &operator>> (istream &in, modType &other) {
        return in >> other.value;
    }

    modType &operator+= (const modType &x) {
        value = (value % MOD + x . value % MOD);
        value -= (value > MOD ? MOD : 0);
        return *this;
    }

    modType &operator-= (const modType &x) {
        value = (value % MOD - x . value % MOD);
        value += (value < 0 ? MOD : 0);
        return *this;
    }

    modType operator- () const {
        return modType(0) - *this;
    }

    modType &operator++ () {
        return (*this += modType(1));
    }

    modType &operator-- () {
        return (*this -= modType(1));
    }

    modType& operator *=(const modType &x) {
        value = (long long) (value % MOD) * (x . value % MOD) % MOD;
        return *this;
    }

    modType& operator^= (T h) {
        modType res = modType(1);
        modType x = *this;
        for (; h > 0; x = x * x, h /= (T) 2) {
            if (h & 1) {
                res *= x;
            }
        }
        (*this = res);
        return *this;
    }

    modType& operator^= (modType h) {
        return (*this ^= h . value);
    }

    modType operator^ (modType h) const {
        return (modType(*this) ^= h . value);
    }

    modType &operator/= (const modType &x) {
        return (*this *= (x ^ modType(MOD - 2)));
    }

    modType operator+ (const modType &x) {
        return (modType(*this) += x);
    }

    modType operator- (const modType &x) {
        return (modType(*this) -= x);
    }

    modType operator* (const modType &x) {
        return (modType(*this) *= x);
    }

    modType operator/ (modType x) {
        return (modType(*this) /= x);
    }
};
using Type = int;
const Type base = (Type)1000000007;
using Mint = Modular<Type,base>;
