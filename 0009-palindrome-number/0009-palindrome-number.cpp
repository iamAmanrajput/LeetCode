class Solution {
public:
    bool isPalindrome(int x) {

        if(x < 0){
            return false;
        }

        long long int a =0;
        int num = x;

        while(num){
           long long int lastDig = num % 10;
            a = a * 10 + lastDig;
            num = num / 10;
        }

        if(a == x){
            return true;
        }else{
            return false;
        }
        
    }
};