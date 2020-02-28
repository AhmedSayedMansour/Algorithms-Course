import java.util.ArrayList;

public class Symetric {

    public static void  printInorder(Tree<Integer>node, ArrayList<Integer> elements)
    {
        if (node == null)
            return;
        if (node.left != null && node.right == null)node.right = new Tree<Integer>(null);
        else if (node.right != null && node.left == null)node.left = new Tree<Integer>(null);
        /* first recur on left child */
        printInorder(node.left,elements);

        /* then print the data of node */
        elements.add(node.value);

        /* now recur on right child */
        printInorder(node.right,elements);
    }

    public static boolean isSymetric(Tree<Integer> tree){
        ArrayList<Integer> elements = new ArrayList<Integer>();
        printInorder(tree,elements);
        for (int i=0; i<Math.ceil(elements.size()/2.0); i++){
            if (elements.get(i) != elements.get(elements.size()-i-1)){
                return false;
            }
        }
        return true;
    }
}
