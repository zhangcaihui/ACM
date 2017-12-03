#include<cstdio>
#include<vector>
#include<iostream>
#include<string>
using namespace std;

struct BigInteger{
    static const int BASE = 100000000;
    static const int WIDTH = 8;
    vector<int> s;

    BigInteger(long long int num = 0) {*this = num;}
    BigInteger operator = (long long int num){
        s.clear();
        do {
            s.push_back( num % BASE);
            num /= BASE;
        }while(num > 0);
        return *this;
    }
    BigInteger operator = (const string& str){
        s.clear();
        int x, len = (str.length() - 1) / WIDTH + 1;
        for(int i = 0; i < len; i ++){
            int end = str.length() - i * WIDTH;
            int start = max(0, end - WIDTH);
            sscanf(str.substr(start, end - start).c_str(), "%d", &x);
            s.push_back(x);
        }
        return *this;
    }

    BigInteger operator + (const BigInteger& b) const {
        BigInteger c;
        c.s.clear();
        for(int i = 0, g= 0; ; i ++){
            if(g == 0 && i >= s.size() && i >= b.s.size()) break;
            int x = g;
            if(i < s.size()) x += s[i];
            if(i < b.s.size())
                x += b.s[i];
            c.s.push_back(x % BASE);
            g = x / BASE;    
        }
        return c;
    }
    BigInteger operator += (const BigInteger& b){
        *this = *this + b;
        return *this;
    }
    bool operator < (const BigInteger& b) const {
        if(s.size() != b.s.size()) return s.size() < b.s.size();
        for(int i = s.size() - 1; i >= 0; i --){
            if(s[i] != b.s[i]) return s[i] < b.s[i];
        }
        return false;
    }
    bool operator > (const BigInteger& b) const {
        return b < *this;
    }
    bool operator <= (const BigInteger& b) const {
        return !(b < *this);
    }
    bool operator >= (const BigInteger& b) const {
        return !(*this < b);
    }
    bool operator != (const BigInteger& b) const {
        return (b < *this) || (*this < b);
    }
    bool operator == (const BigInteger& b) const {
        return !(b < *this || *this < b);
    }
    void print(const string& b){
        for(int i = s.size()-1; i >= 0; i --)
            printf("%d", s[i]);
        cout << b;
    }
};
