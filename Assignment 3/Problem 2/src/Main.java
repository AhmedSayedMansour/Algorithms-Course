import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Main {

    static String name = "A";
    static int x = 1;

    static void printParenthesis(int i, int j, int n, int[][] bracket)
    {
        // If only one matrix left in current segment
        if (i == j)
        {
            System.out.print(name+(x++));
            return;
        }

        System.out.print('(');

        // Recursively put brackets around subexpression
        // from i to bracket[j][i].
        // Note that "*((bracket+j*n)+i)" is similar to
        // bracket[i][j]
        printParenthesis(i, bracket[j][i], n, bracket);

        // Recursively put brackets around subexpression
        // from bracket[j][i] + 1 to i.
        printParenthesis(bracket[j][i]+1 , j, n, bracket);
        System.out.print(')');
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while (true){

            int n = input.nextInt();
            if (n==0)break;
            ArrayList<Integer> matrices = new ArrayList<Integer>();

            // Taking one matrices
            for (int i=0; i<n; i++){
                int num = input.nextInt();
                if (i == 0)
                matrices.add(num);
                num = input.nextInt();
                matrices.add(num);
            }
            int [][] inputMatrix  = new int[matrices.size()][matrices.size()];
            int [][] solutionMatrix  = new int[matrices.size()][matrices.size()];

            //Initializing the matrix
            for (int j=0; j<n; j++){
                for (int i=0; i<n; i++){
                    int j2 = i + j;
                    if (j2 >= matrices.size()-1) j2 = matrices.size()-2;
                    if (i==j2){
                        inputMatrix[i][j2]=0;
                        continue;
                    }
                    int min = Integer.MAX_VALUE;
                    int kmin = 0;
                    for (int k=i; k<j2; k++){
                        int tmp = inputMatrix[i][k] + inputMatrix[k+1][j2] + matrices.get(i)*matrices.get(k+1)*matrices.get(j2+1);
                        //0 0 + 1 1 + 5*10*20
                        if (tmp<min) {
                            min = tmp;
                            kmin = k;
                        }
                    }
                    inputMatrix[i][j2] = min;
                    solutionMatrix[j2][i] = kmin;
                }
            }
            System.out.println("");
            printParenthesis(0,n-1,n,solutionMatrix);
            System.out.println("");
            x = 1;
        }
    }
}
