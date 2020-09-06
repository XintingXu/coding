#include <stdio.h>
#include <stdlib.h>

#define bool short
#define true 1
#define false 0

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int nodes[1000];
int nodes_end;

void travelMiddle(struct TreeNode *root)
{
    if (!root) {
        return;
    }

    travelMiddle(root->left);

    nodes[nodes_end] = root->val;
    ++nodes_end;

    travelMiddle(root->right);
}

bool judge(int k)
{
    int nodes_begin = 0;
    --nodes_end;
    while (nodes_end > 0 && nodes_begin < nodes_end) {
        if (nodes[nodes_begin] + nodes[nodes_end] == k) {
            return true;
        }

        if (nodes[nodes_begin] + nodes[nodes_end] > k) {
            --nodes_end;
            continue;
        }

        ++nodes_begin;
    }
    return false;
}

bool findTarget (struct TreeNode *root, int k)
{
    memset(nodes, 0, sizeof(nodes));
    nodes_end = 0;

    travelMiddle(root);

    qsort(nodes, nodes_end, sizeof(int), cmp);

    return judge(k);
}

int main()
{
    printf("Hello World!\n");
    return 0;
}
