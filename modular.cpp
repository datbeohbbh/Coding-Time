using MOD_TYPE = long long; // or int
const MOD_TYPE MOD = (MOD_TYPE)1000000007;

template<class T> struct Modular {
private :
    T val;
public:
    Modular () {
        val = 0;
    }

    Modular (const T &new_val) {
        val = new_val % MOD;
        val = (val >= MOD ? val - MOD : (val < 0 ? val + MOD : val));
    }

    Modular<T> &operator= (const Modular<T> &x) {
        this -> val = x . val;
        return *this;
    }

    friend bool operator== (const Modular<T> &x, const Modular<T> &y) {
        return x . val == y . val;
    }

    friend bool operator!= (const Modular<T> &x, const Modular<T> &y) {
        return !(x == y);
    }

    friend bool operator< (const Modular<T> &x, const Modular<T> &y) {
        return x . val < y . val;
    }

    friend bool operator> (const Modular<T> &x, const Modular<T> &y) {
        return x . val > y . val;
    }

    friend bool operator<= (const Modular<T> &x, const Modular<T> &y) {
        return !(x > y);
    }

    friend bool operator>= (const Modular<T> &x, const Modular<T> &y) {
        return !(x < y);
    }

    friend ostream &operator<< (ostream &out, const Modular<T> &x) {
        return out << x . val;
    }

    friend istream &operator>> (istream &in, Modular<T> &x) {
        return in >> x . val;
    }

    Modular<T> &operator+= (const Modular<T> &x) {
        val = (val % MOD + x . val % MOD);
        val -= (val > MOD ? MOD : 0);
        return *this;
    }

    Modular<T> &operator-= (const Modular<T> &x) {
        val = (val % MOD - x . val % MOD);
        val += (val < 0 ? MOD : 0);
        return *this;
    }

    Modular<T> operator- () const {
        return Modular<T>(0) - *this;
    }

    Modular<T> &operator++ () {
        return (*this += Modular<T>(1));
    }

    Modular<T> &operator-- () {
        return (*this -= Modular<T>(1));
    }

    Modular<T> &operator*= (const Modular<T> &x) {
        val = (long long) (val % MOD) * (x . val % MOD) % MOD;
        return *this;
    }

    Modular<T> &operator^= (T h) {
        Modular<T> res = Modular<T>(1);
        Modular<T> x = *this;
        for (; h > 0; x = x * x, h /= (T) 2) {
            if (h & 1) {
                res *= x;
            }
        }
        (*this = res);
        return *this;
    }

    Modular<T> &operator^= (Modular<T> h) {
        return (*this ^= h . val);
    }

    Modular<T> operator^ (T h) {
        return (Modular<T>(*this) ^= h);
    }

    Modular<T> operator^ (Modular<T> h) {
        return (Modular<T>(*this) ^= h . val);
    }

    Modular<T> &operator/= (Modular<T> &x) {
        return (*this *= (x ^ (MOD - 2)));
    }

    Modular<T> operator+ (const Modular<T> &x) {
        return (Modular<T>(*this) += x);
    }

    Modular<T> operator- (const Modular<T> &x) {
        return (Modular<T>(*this) -= x);
    }

    Modular<T> operator* (const Modular<T> &x) {
        return (Modular<T>(*this) *= x);
    }

    Modular<T> operator/ (Modular<T> x) {
        return (Modular<T>(*this) /= x);
    }
};

using mod_t = Modular<MOD_TYPE>;
