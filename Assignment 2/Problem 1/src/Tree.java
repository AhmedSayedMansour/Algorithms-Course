public class Tree <T>{
    Tree(T x){
        value = x;
    }
    T value;
    Tree<T> left;
    Tree<T> right;
}
