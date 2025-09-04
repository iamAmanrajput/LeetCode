class Solution {
public:
    int findClosest(int x, int y, int z) {
        
        int person1dist = abs(z-x);
         
        int person2dist = abs(z-y);

        if(person1dist == person2dist){
            return 0;
        }

        if(person1dist < person2dist){
            return 1;
        }else {
            return 2;
        }
    }
};