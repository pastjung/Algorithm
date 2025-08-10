import java.util.*;

class Solution {
    public int[] solution(int[] numbers) {
        int[] answer = {};
        
        int n = numbers.length;
        TreeSet<Integer> set = new TreeSet<>();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                
                set.add(numbers[i] + numbers[j]);
            }
        }
        
        answer = set.stream().mapToInt(Integer::intValue).toArray();
        return answer;
    }
}