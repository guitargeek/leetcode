/**

226. Invert Binary Tree

Invert a binary tree.

Example:

Input:

```
     4
   /   \
  2     7
 / \   / \
1   3 6   9
```

Output:

```
     4
   /   \
  7     2
 / \   / \
9   6 3   1
```

Trivia:
This problem was inspired by this original tweet by Max Howell:

    Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a
    whiteboard so f*** off.

*/

#include "leet.h"

namespace leet {

    using namespace std;

    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return root;
        if (root->left)
            invertTree(root->left);
        if (root->right)
            invertTree(root->right);
        swap(root->left, root->right);
        return root;
    }

}  // namespace leet
