package project;

public class Tree<T> {
    Tree(T x) {
        value = x;
    }
    T value;
    Tree<T> left = null;
    Tree<T> right = null;
}