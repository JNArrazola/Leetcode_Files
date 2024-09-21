import java.util.ArrayList;

enum TokenType {
    DECIMAL, INTEGER, E, EOF
}

class Token {
    TokenType type;

    Token(TokenType type){
        this.type = type;
    }

    public TokenType getType() {
        return type;
    }
}

class Lexer {
    ArrayList<Token> tokens;
    int pos = 0;
    String str;

    boolean isPartOfNumber(char c){
        return c == '+' || c == '-' || c>='0' && c<='9' || c == '.';
    }

    boolean isAtEnd(){
        return pos == str.length(); 
    }

    ArrayList<Token> lexer(String s){
        boolean alreadyGotE = false;
        tokens = new ArrayList<>();
        str = s;

        while (!isAtEnd()) {
            switch (s.charAt(pos)) {
                case '+':
                case '-':
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                case '.':
                    if(!consumeNumber(s))
                        return null;
                    break;
                case 'e':
                case 'E':
                    if(!alreadyGotE)
                        alreadyGotE = true;
                    else 
                        return null;
                    
                    tokens.add(new Token(TokenType.E));
                    pos++;
                    break;
                    default:
                    return null;
                }
        }
        tokens.add(new Token(TokenType.EOF));
        return tokens;
    }

    boolean consumeNumber(String s){  
        boolean hasDecimalPoint = false;
        boolean hasNumber = false;
        boolean hasSign = false;

        if(s.charAt(pos) == '+' || s.charAt(pos) == '-'){
            pos++;
            hasSign = true;
        }

        while (!isAtEnd()&&isPartOfNumber(str.charAt(pos))) {
            if(s.charAt(pos) == '.'){
                if(!hasDecimalPoint){
                    hasDecimalPoint = true;
                    pos++;
                }
                else 
                    return false;
                continue;
            }
            if(s.charAt(pos) == '+' || s.charAt(pos) == '-')
                return false;
                
            hasNumber = true;
            pos++;
        }

        if((hasDecimalPoint || hasSign)&&!hasNumber)
            return false;
        

        if(hasDecimalPoint)
            tokens.add(new Token(TokenType.DECIMAL)); 
        else 
            tokens.add(new Token(TokenType.INTEGER));
        
        return true;
    }
}

class Parser {
    int pos = 0;
    ArrayList<Token> tks;

    boolean isAtEnd(){
        return tks.get(pos).getType() == TokenType.EOF;
    }

    TokenType peek(){
        return tks.get(pos + 1).getType();
    }

    void advance(){
        pos++;
    }

    boolean parse(ArrayList<Token> tokens){
        this.tks = tokens;
        TokenType lastToken = null;
        

        while (!isAtEnd()) {
            switch (tks.get(pos).getType()) {
                case DECIMAL:
                    lastToken = TokenType.DECIMAL; 
                    advance(); 
                    break;
                    case INTEGER: 
                    lastToken = TokenType.INTEGER;
                    advance(); 
                    break;
                case E:
                    if(lastToken == null)
                        return false;
                    if(peek() == TokenType.DECIMAL || peek() == TokenType.EOF || peek() == TokenType.E)
                        return false;
                    advance();
                default:
                    break;
            }
            
        }

        return true;
    }


}

class Solution {
    public boolean isNumber(String s) {
        Lexer lex = new Lexer();

        ArrayList<Token> t = lex.lexer(s);

        if(t == null)
            return false;
        
        Parser par = new Parser();
        return par.parse(t);
    }
}

