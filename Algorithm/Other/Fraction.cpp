struct Fraction{
    long long int x, y;
    Fraction(long long int xx = 0, long long int yy = 0):x(xx), y(yy){}
    bool check(){
        if(!this->y)
            return false;
        return true;
    }
    Fraction operator + (const Fraction &sec){
        long long int temx = sec.y * this->x + sec.x * this->y;
        long long int temy = sec.y * this->y;
        return Fraction(temx/gcd(temx, temy), temy/gcd(temx, temy));
    }
    Fraction operator * (const Fraction &sec){
        long long int temx = sec.x * this->x;
        long long int temy = sec.y * this->y;
        return Fraction(temx/gcd(temx, temy), temy/gcd(temx, temy));
    }
}
