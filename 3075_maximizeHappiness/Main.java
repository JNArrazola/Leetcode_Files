import java.util.Arrays;

class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        long answ = 0;
        int ctr = 0;

        Arrays.sort(happiness);

        for (int i = happiness.length - 1; i >= 0; i--) {
            answ+= ((happiness[i] - ctr >= 0) ? happiness[i] - ctr: 0);
            ctr++;
            
            if(ctr == k)
                return answ;
        }

        return answ;
    }
}

public class Main{
    public static void main(String[] args) {
        
    }
}