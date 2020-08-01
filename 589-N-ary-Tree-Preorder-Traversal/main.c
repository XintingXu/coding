#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    int numChildren;
    struct Node** children;
};

int *preorder(struct Node *root, int *returnSize) {
    *returnSize = 0;
    if (!root) {
        return NULL;
    }

    int *result = (int *)malloc(sizeof(int) * 10000);
    struct Node **nodes = (struct Node **)malloc(sizeof(struct Node *) * 10000);
    int nodes_top = 0;

    nodes[nodes_top ++] = root;

    while (nodes_top) {
        struct Node *target = nodes[-- nodes_top];
        result[(*returnSize) ++] = target->val;
        for (int i = target->numChildren - 1 ; i >= 0 ; -- i) {
            nodes[nodes_top ++] = target->children[i];
        }
    }

    return result;
}

int main() {
    struct Node *root = (struct Node *)malloc(sizeof(struct Node));
    root->val = 66;
    root->numChildren = 2;
    root->children = (struct Node **)malloc(sizeof(struct Node *) * root->numChildren);
    root->children[0] = (struct Node *)malloc(sizeof(struct Node));
    root->children[1] = (struct Node *)malloc(sizeof(struct Node));
    root->children[0]->numChildren = 0;
    root->children[0]->val = 111;
    root->children[1]->numChildren = 0;
    root->children[1]->val = 122;

    int returnSize = 0;
    int *result = preorder(root, &returnSize);
    for (int i = 0 ; i < returnSize ; ++ i) {
        printf("%d\n", result[i]);
    }

    free(result);
    free(root->children[0]);
    free(root->children[1]);
    free(root->children);
    free(root);
    return 0;
}
