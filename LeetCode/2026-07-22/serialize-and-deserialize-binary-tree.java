/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */


public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
      StringBuilder out = new StringBuilder();
      serialize(out, root);
      return out.toString();
    }

    public void serialize(StringBuilder out, TreeNode node) {
      if (node == null) {
        out.append("null");
        out.append(" ");
        return;
      }
      out.append(node.val);
      out.append(" ");
      serialize(out, node.left);
      serialize(out, node.right);
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
      Scanner in = new Scanner(data);
      return deserialize(in);
    }

    public TreeNode deserialize(Scanner in) {
      String next = in.next();
      if (next.equals("null")) return null;
      TreeNode ret = new TreeNode(Integer.parseInt(next));
      ret.left = deserialize(in);
      ret.right = deserialize(in);
      return ret;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));
