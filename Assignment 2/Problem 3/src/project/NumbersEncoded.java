package project;

public class NumbersEncoded {
    private String path = "";
    private long result = 0;

    /// Cover to use return (long)
    public long digitSum(Tree<Integer> t)
    {
        paths(t);

        return result;
    }
    /// Get all possible paths
    private void paths(Tree<Integer> t)
    {
        if(t == null) return;

        path += String.valueOf(t.value);

        if(t.left == null & t.right == null)
        {
            result += Long.parseLong(path);
        }

        paths(t.left);
        paths(t.right);

        path = path.substring(0 , path.length()-1);

    }
}
