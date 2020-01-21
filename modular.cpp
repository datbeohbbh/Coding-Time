template <class T>
struct Modular{
    const T base = (T)(1e9 + 7);
    T val;
    Modular(){
        val = 0;
    }
    Modular(const T &new_val){
        val = new_val % base;
        val = (val >= base ? val - base : (val < 0 ? val + base : val));
    }
    void operator = (const Modular <T> &x){
        val = x.val % base;
    }
    friend bool operator == (const Modular <T> &x,const Modular <T> &y){
        return x.val == y.val;
    }
    friend bool operator != (const Modular <T> &x,const Modular <T> &y){
        return !(x == y);
    }
    friend bool operator < (const Modular <T> &x,const Modular <T> &y){
        return x.val < y.val;
    }
    friend bool operator > (const Modular <T> &x,const Modular <T> &y){
        return x.val > y.val;
    }
    friend bool operator <= (const Modular <T> &x,const Modular <T> &y){
        return (x < y) or (x == y);
    }
    friend bool operator >= (const Modular <T> &x,const Modular <T> &y){
        return (x > y) or (x == y);
    }
    friend ostream& operator << (ostream &out,const Modular <T> &x){
        return out << x.val;
    }
    friend istream& operator >> (istream &in,Modular <T> &x){
        return in >> x.val;
    }
    Modular <T> operator += (const Modular <T> &x){
        val = (val % base + x.val % base);
        val -= (val > base ? base : 0);
        return *this;
    }
    Modular <T> operator -= (const Modular <T> &x){
        val =(val % base - x.val % base);
        val += (val < 0 ? base : 0);
        return *this;
    }
    Modular <T> operator + (const Modular <T> &x){
        return (*this += x);
    }
    Modular <T> operator - (const Modular <T> &x){
        return (*this -= x);
    }
    Modular <T> operator - () const {
        return Modular <T> (0) - *this;
    }
    Modular <T> operator ++ (){
        return (*this += Modular <T> (1));
    }
    Modular <T> operator -- (){
        return (*this -= Modular <T> (1));
    }
    Modular <T> operator *= (const Modular <T> &x){
        val = ((val % base) * (x.val % base)) % base;
        return *this;
    }
    Modular <T> operator * (const Modular <T> &x){
        return (*this *= x);
    }
    Modular <T> operator ^= (T h){
        Modular <T> res = Modular <T> (1);
        Modular <T> x = *this;
        for(;h > 0;x =x * x,h /= (T)2){
            if(h & 1){
                res *= x;
            }
        }
        *this = res;
        return res;
    }
    Modular <T> operator ^ (T h){
        return (*this ^= h);
    }
    Modular <T> operator ^= (Modular <T> h){
        return (*this ^= h.val);
    }
    Modular <T> operator ^ (Modular <T> h){
        return (*this ^= h.val);
    }
    Modular <T> operator /= (Modular <T> &x){
        return (*this *= (x ^ (base - 2)));
    }
    Modular <T> operator / (Modular <T> x){
        return (*this /= x);
    }
};
