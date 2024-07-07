
class Solution {
    public String truncateSentence(String s, int k) {
        String answ = "";

        String[] words = s.split(" ");

        for (int i = 0; i < k; i++) 
            answ += words[i] + " ";
        
        return answ.trim();
    }
}       