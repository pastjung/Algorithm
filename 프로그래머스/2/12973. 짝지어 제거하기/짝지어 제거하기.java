import java.util.*;

class Solution{
    public int solution(String s){
        int answer = 0;

        LinkedList<Character> list = new LinkedList<>();
        for(int i = 0; i < s.length(); i++){
            if(list.isEmpty() || list.peek() != s.charAt(i)){
                list.push(s.charAt(i));
            } else{
                list.pop();
            }
        }
        
        if(list.isEmpty()){
            answer = 1;
        }

        return answer;
    }
}