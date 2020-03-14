// JAVA program to print all
// paths from a source to
// destination.
import java.util.ArrayList;
import java.util.List;

// A directed graph using
// adjacency list representation
public class Graphs {

    // No. of vertices in graph
    private int v;

    // adjacency list
    private ArrayList<Integer>[] adjList;

    //Constructor
    public Graphs(int vertices){

        //initialise vertex count
        this.v = vertices;

        // initialise adjacency list
        initAdjList();
    }

    // utility method to initialise
    // adjacency list
    @SuppressWarnings("unchecked")
    private void initAdjList()
    {
        adjList = new ArrayList[v];

        for(int i = 0; i < v; i++)
        {
            adjList[i] = new ArrayList<>();
        }
    }

    // add edge from u to v
    public void addEdge(int u, int v)
    {
        // Add v to u's list.
        adjList[u].add(v);
    }

    // Prints all paths from
    // 's' to 'd'
    public void printAllPaths(int s, int d,int[][]ans)
    {
        boolean[] isVisited = new boolean[v];
        ArrayList<Integer>path =new ArrayList<Integer>();
        //add source to path[]
        path.add(s);
        //Call recursive utility
        printAllPathsUtil(s, d, isVisited, path,ans);
        path.remove(0);
        if (path.size()==0) System.out.println("No path");
    }

    // A recursive function to print
    // all paths from 'u' to 'd'.
    // isVisited[] keeps track of
    // vertices in current path.
    // localPathList<> stores actual
    // vertices in the current path
    public void printAllPathsUtil(Integer u, Integer d,
                                                 boolean[] isVisited,
                                                 ArrayList<Integer> localPathList,int[][]ans) {

        // Mark the current node
        isVisited[u] = true;
        if (u.equals(d))
        {
            int max = -1;
            ArrayList<Integer>x = new ArrayList<Integer>();
            for (int i=0; i<localPathList.size()-1; i++){
                max = Math.max(ans[localPathList.get(i)][localPathList.get(i+1)],max);
            }
            System.out.println(max);
            localPathList.addAll(localPathList);
            // if match found then no need to traverse more till depth
            isVisited[u]= false;
            return ;
        }
        // Recur for all the vertices
        // adjacent to current vertex
        for (Integer i : adjList[u])
        {
            if (!isVisited[i])
            {
                // store current node
                // in path[]
                localPathList.add(i);
                printAllPathsUtil(i, d, isVisited, localPathList,ans);

                // remove current node
                // in path[]
                localPathList.remove(i);
            }
        }

        // Mark the current node
        isVisited[u] = false;
    }

}