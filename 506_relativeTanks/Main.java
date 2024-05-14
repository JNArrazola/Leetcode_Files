import java.util.Arrays;
import java.util.HashMap;

class Solution {
    public String[] findRelativeRanks(int[] score) {
        String[] answ = new String[score.length];
        HashMap<Integer, String> mp = new HashMap<>();

        int[] copy = Arrays.copyOf(score, score.length);
        Arrays.sort(copy);

        int ctr = 1;
        for (int i = copy.length - 1; i >= 0; i--) {
            switch (ctr) {
                case 1:
                    mp.put(copy[i], "Gold Medal");
                    break;
                case 2:
                    mp.put(copy[i], "Silver Medal");
                    break;
                case 3:
                    mp.put(copy[i], "Bronze Medal");
                    break;
                default:
                    mp.put(copy[i], String.valueOf(ctr));
            }
            ctr++;
        }

        for (int i = 0; i < score.length; i++) 
            answ[i] = mp.get(score[i]);

        return answ;
    }
}

public class Main{
    public static void main(String[] args) {
        
    }
}
