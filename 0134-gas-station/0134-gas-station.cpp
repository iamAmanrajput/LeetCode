class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // kitna petrol kam pad gya 
        int deficit = 0;
        // kitna petrol bacha huaa hai
        int balance = 0;
        // circut kaha se start huaa hai
        int start = 0;

        for(int i =0;i<gas.size();i++){
            balance += gas[i] - cost[i];
            if(balance < 0){
                deficit += balance; 
                start = i+1;
                balance = 0;
            }
        }

        if(deficit + balance >= 0){
            return start;
        }else{
            return -1;
        }
    }
};