
class Solution {
    public boolean isDigit(char c){
        return (c>='1'&&c<='9')||c==0;
    }
    
    public boolean strongPasswordCheckerII(String password) {
        /**
         * It has at least 8 characters.
         * It contains at least one lowercase letter.
         * It contains at least one uppercase letter.
         * It contains at least one digit.
         * It contains at least one special character. The special characters are the
         * characters in the following string: "!@#$%^&*()-+".
         * It does not contain 2 of the same character in adjacent positions (i.e.,
         * "aab" violates this condition, but "aba" does not).
         */

        if(password.length()<8) return false;

        boolean hasLower = false, hasUpper = false, hasDigit = false, hasSpecial = false;
        String special = "!@#$%^&*()-+";

        
        for (int i = 0; i < password.length(); i++) {
            if(i>=1)
                if(password.charAt(i)==password.charAt(i-1))
                    return false;

            if(Character.isLowerCase(password.charAt(i))) hasLower = true;
            if(Character.isUpperCase(password.charAt(i))) hasUpper = true;
            if(Character.isDigit(password.charAt(i))) hasDigit = true;
            if(special.indexOf(password.charAt(i))!=-1) hasSpecial = true;
        }

        if(!hasLower || !hasUpper || !hasDigit || !hasSpecial) return false;

        return true;
    }
}
