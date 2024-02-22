/*
Code is giving correct result for sample test case.. but timeout happening
So, non-optimal solution.. needs to improve

Leetcode link - https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
*/

class Solution {
public:
    int getMax(vector<int>& weights, int sIndex, int eIndex){
        int curr_max = weights[sIndex];
        for(int i = sIndex + 1; i <= eIndex; ++i){
            if(weights[i] > curr_max){
                curr_max = weights[i];
            }
        }
        //cout<<curr_max<<endl;
        return curr_max;
    }

    int getSum(vector<int>& weights, int sIndex, int eIndex){
        int curr_sum = weights[sIndex];
        for(int i = sIndex + 1; i <= eIndex; ++i){
            curr_sum += weights[i];
        }
        return curr_sum;
    }

    int minCapacity(vector<int>& weights, int sIndex, int eIndex, int days){
        //check for sIndex out of bound
        //cout<<" sIndex="<<sIndex<<" eIndex="<<eIndex<<" days="<<days<<endl;
        if(days == 1){
            return getSum(weights, sIndex, eIndex);
        }
        if(sIndex == eIndex){
            return weights[sIndex];
        }else if(eIndex - sIndex < days){//number of items is same as number of days
            return getMax(weights, sIndex, eIndex);
        }

        int weight = 0; 
        int curr_min = INT_MAX;
        int iteration_min = 0;
        int remaining_days = days - 1;
        for(int i = sIndex; (i < eIndex) && (eIndex -i) >= remaining_days; ++i){
            weight += weights[i];
            iteration_min = minCapacity(weights, i+1, eIndex, remaining_days);
            if(iteration_min < weight){
                iteration_min = weight;
            }
            if(curr_min > iteration_min){
                curr_min = iteration_min;
            }
            //cout<<" weight="<<weight<<" iteration_min="<<iteration_min<<" curr_min="<<curr_min<<endl;
        }
        return curr_min;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int size = weights.size();
        if(size == 0){
            return 0;
        }
        return minCapacity(weights, 0, size-1, days);
    }
};