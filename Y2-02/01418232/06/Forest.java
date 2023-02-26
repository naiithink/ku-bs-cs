import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.PriorityQueue;
import java.util.Scanner;

class Node implements Comparable<Node> {
    private int vertex;
    private int distance;

    public Node(int vertex, int distance) {
        this.vertex = vertex;
        this.distance = distance;
    }

    public int getVertex() {
        return vertex;
    }

    @Override
    public int compareTo(Node other) {
        return this.distance - other.distance;
    }
}

public class Forest {
    private static final int INF = 99999999;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        try {
            int n = scanner.nextInt();
            int m = scanner.nextInt();
            int startNode;

            if (n <= 0 || m < 0)  {
                System.out.println("What did you expect?");
                System.exit(0);
            }

            if ((startNode = scanner.nextInt()) < 1 || startNode > n)  {
                System.out.println("What did you expect?");
                System.exit(0);
            }

            int[][] graph = new int[n + 1][n + 1];
            boolean[] visited = new boolean[n + 1];
            int[] distance = new int[n + 1];

            for (int i = 1; i <= n; i++) {
                Arrays.fill(graph[i], INF);
                distance[i] = INF;
            }

            if (m <= 0) {
                System.out.println(0);
                System.exit(0);
            }

            for (int i = 0; i < m; i++) {
                int u = scanner.nextInt();
                int v = scanner.nextInt();
                int w = scanner.nextInt();

                if (u < 1 || u > n || v < 1 || v > n || w <= 0) {
                    System.out.println("What did you expect?");
                    System.exit(0);
                }

                graph[u][v] = w;
                graph[v][u] = w;
            }

            PriorityQueue<Node> pq = new PriorityQueue<>();
            pq.offer(new Node(startNode, 0));
            distance[startNode] = 0;

            while (!pq.isEmpty()) {
                Node node = pq.poll();
                int u = node.getVertex();
                visited[u] = true;

                for (int v = 1; v <= n; v++) {
                    if (!visited[v] && graph[u][v] != INF && graph[u][v] < distance[v]) {
                        distance[v] = graph[u][v];
                        pq.offer(new Node(v, distance[v]));
                    }
                }
            }

            int totalCost = 0;

            for (int i = 1; i <= n; i++) {
                if (distance[i] == INF) {
                    System.out.println("What did you expect?");
                    System.exit(0);
                }

                totalCost += distance[i];
            }

            System.out.println(totalCost);
        } catch (InputMismatchException e) {
            System.out.println("What did you expect?");
            System.exit(0);
        }
    }
}
