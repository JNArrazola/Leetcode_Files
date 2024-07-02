class Solution {
    public int prefixCount(String[] words, String pref) {
        int answ = 0;

        for(String s : words)
            if(s.startsWith(pref))
                answ++;

        return answ;
    }
}