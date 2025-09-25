import java.util.*;
import java.lang.*;
import java.io.*;

class Pair{
    int first;
    int second;

    public Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}

class Main {
    public static void Dijkstra(final List<List<Pair>> weight, ArrayList<Integer> distance, final int K){
        int n = weight.size();
        PriorityQueue<Pair> pq = new PriorityQueue<>(new Comparator<Pair>() {
            @Override
            public int compare(Pair p1, Pair p2) {
                // 누적 가중치(weight)가 작은 순으로 정렬
                return Integer.compare(p1.first, p2.first);
            }
        });
        // PriorityQueue<Pair> pq = new PriorityQueue<>(Comparator.comparingInt(p -> p.first));  // {누적 가중치, 도착 정점}

        // 초기 세팅
        distance.set(K, 0);
        pq.add(new Pair(0, K));

        while(!pq.isEmpty()){
            Pair current = pq.poll();
            int wSum = current.first;
            int start = current.second;

            // 현재 경로가 기존에 찾은 경로보다 가중치가 작은 경우 패스
            if(wSum > distance.get(start)){
                continue;
            }

            // 인근 경로 탐색
            for(Pair pair : weight.get(start)){
                int end = pair.first;
                int w = pair.second;
                int cost = distance.get(start) + w;
                if(cost < distance.get(end)){
                    distance.set(end, cost);
                    pq.offer(new Pair(cost, end));
                }
            }
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // 입력 데이터
        int V = sc.nextInt();  // 정점의 개수
        int E = sc.nextInt();  // 간선의 개수
        int K = sc.nextInt() - 1;  // 시작 정점 (0-based index)


        // 가중치 리스트 초기화
        List<List<Pair>> weight = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            weight.add(new ArrayList<>());
        }

        // 간선 정보 입력
        for (int e = 0; e < E; e++) {
            int start = sc.nextInt() - 1;  // 시작 정점 (0-based index)
            int end = sc.nextInt() - 1;    // 끝 정점 (0-based index)
            int w = sc.nextInt();          // 가중치
            weight.get(start).add(new Pair(end, w));
        }

        // K부터 각 정점의 최단 경로 계산
        ArrayList<Integer> distance = new ArrayList<>(Collections.nCopies(V, Integer.MAX_VALUE));  // 각 정점의 최단 경로 (초기값은 INF)
        distance.set(K, 0);  // 시작 정점의 거리 초기화
        Dijkstra(weight, distance, K);

        // 모든 최단 경로 출력
        for (int w : distance) {
            if (w == Integer.MAX_VALUE) {
                System.out.println("INF");
            } else {
                System.out.println(w);
            }
        }
        
        sc.close();
    }
}