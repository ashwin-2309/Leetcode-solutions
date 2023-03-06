class Solution {
public:
    bool canMeasureWater(int j1, int j2, int k)
    {
        // water jug problem
        // if k is a multiple of gcd(j1,j2) then it is possible to measure k litres of water
        // if k is greater than the sum of j1 and j2 then it is not possible to measure k litres of water
        // if k is less than the sum of j1 and j2 then it is possible to measure k litres of water
        // else it is not possible to measure k litres of water

        if (k > j1 + j2)
            return false;

        if (k % gcd(j1, j2) == 0)
            return true;

        return false;
    }
};