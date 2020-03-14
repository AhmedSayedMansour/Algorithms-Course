import java.sql.Array;
import java.util.*;

public class Main {

    public static void main (String[] args)
    {
        int C,S,Q;
        Scanner input = new Scanner(System.in);
        C = input.nextInt();
        S = input.nextInt();
        Q = input.nextInt();
        Graph graph = new Graph(C, S);
        for (int i=0; i<S; i++){
            graph.edge[i].src = input.nextInt()-1;
            graph.edge[i].dest = input.nextInt()-1;
            graph.edge[i].weight = input.nextInt();
        }
        ArrayList<Integer>Queries = new ArrayList<Integer>();
        for (int i=0; i<Q; i++){
            Queries.add(input.nextInt());
            Queries.add(input.nextInt());
        }
        Arrays.sort(graph.edge,new Comparator<Graph.Edge>() {
            public int compare(Graph.Edge b1, Graph.Edge b2) {
                if (b1.weight>b2.weight)return +1;
                if (b1.weight<b2.weight) return -1;
                else return 0;
            }
        });
        Graph graphCheck = new Graph(C,C-1);
        int current = 0;
        graphCheck.E = 1;
        for (Graph.Edge i : graph.edge){
            graphCheck.edge[current].src = i.src;
            graphCheck.edge[current].dest = i.dest;
            graphCheck.edge[current].weight = i.weight;
            if (graphCheck.isCycle(graphCheck)==0){
                graphCheck.E++;
                current++;
            }
            else{
                graphCheck.edge[current].src = -1;
                graphCheck.edge[current].dest = -1;
                graphCheck.edge[current].weight = -1;
            }
            if (C-current==1)break;
        }
        int [][] Matrix = new int [C+1][C+1];
        Graphs print = new Graphs(C+1);
        for (int i =0; i<graphCheck.edge.length; i++){
            graphCheck.edge[i].src++;
            graphCheck.edge[i].dest++;
            Matrix[graphCheck.edge[i].src][graphCheck.edge[i].dest] = graphCheck.edge[i].weight;
            Matrix[graphCheck.edge[i].dest][graphCheck.edge[i].src] = graphCheck.edge[i].weight;
            print.addEdge(graphCheck.edge[i].src,graphCheck.edge[i].dest);
            print.addEdge(graphCheck.edge[i].dest,graphCheck.edge[i].src);
        }
        for (int i=0; i<Queries.size(); i+=2){
            print.printAllPaths(Queries.get(i),Queries.get(i+1),Matrix);
        }
    }
}
