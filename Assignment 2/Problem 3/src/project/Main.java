package project;

public class Main {

    public static void main(String[] args) {

        Tree<Integer> initialTree = new Tree<>(1);

        initialTree.right = new Tree<>(4);
        initialTree.left = new Tree<>(0);
        initialTree.left.left = new Tree<>(3);
        initialTree.left.right = new Tree<>(1);

        NumbersEncoded numbers = new NumbersEncoded();

        System.out.println(numbers.digitSum(initialTree));


    }
}
