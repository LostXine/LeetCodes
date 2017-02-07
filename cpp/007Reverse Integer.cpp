/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/

//8ms
class Solution {
public:
    int reverse(int x) {
        long k = x;
        bool isNegtive = false;        
        if(k < 0){
            k = 0 - k;
            isNegtive = true;
        }

        long result = 0;
        while(k != 0){
            result *= 10;
            result += k % 10;
            k /= 10;
        }

        if(result > 2147483647) return 0;
        return isNegtive  ? 0 - ((int)result) : (int)result;
    }
};

//12ms
class Solution {
public:
    int reverse(int x) {
        int dst = 0;
        bool negative = (x<0);
        int src = abs(x);
        int odst = dst;
        while(src>9)
        {
            dst = dst*10 + src%10;
            if((dst-src%10)/10!=odst){return 0;}
            src = src/10;
            odst = dst;
        }
        dst = dst*10 + src;
        if((dst-src%10)/10!=odst){return 0;}
        if(negative){dst = -dst;if(dst >=0){return 0;}}
        
        return dst;
    }
};