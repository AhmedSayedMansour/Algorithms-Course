import java.util.ArrayList;

public class Main {
    public static void  printInorder(Tree<Integer>node, ArrayList<Integer> elements)
    {

        if (node == null)
            return;

        if (node.left != null && node.right == null)node.right = new Tree<Integer>(null);

        else if (node.right != null && node.left == null)node.left = new Tree<Integer>(null);

        printInorder(node.left,elements);

        elements.add(node.value);

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

    public static void main(String[] args) {
        Tree  <Integer> root = new Tree<Integer>(1);
        ///PRINT THE ACTION OF THE TREE
        System.out.println(Symetric.isSymetric(root));
    }
}
