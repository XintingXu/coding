#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    int numChildren;
    struct Node** children;
};

/*
int *postorder(struct Node *root, int *returnSize) {
    *returnSize = 0;
    if (!root) {
        return NULL;
    }

    int *result = (int *)malloc(sizeof(int) * 10000);
    struct Node **nodes = (struct Node **)malloc(sizeof(struct Node *) * 10000);
    short *nodes_expanded = (short *)malloc(sizeof(short) * 10000);
    memset(nodes_expanded, 0, sizeof(short) * 10000);
    int nodes_top = 0;

    nodes[nodes_top ++] = root;

    while (nodes_top) {
        struct Node *target = nodes[nodes_top - 1];
        if (nodes_expanded[nodes_top - 1]) {
            result[(*returnSize) ++] = target->val;
            -- nodes_top;
            nodes_expanded[nodes_top] = 0;
            continue;
        }

        nodes_expanded[nodes_top - 1] = 1;

        for (int i = target->numChildren - 1 ; i >= 0 ; -- i) {
            nodes[nodes_top ++] = target->children[i];
        }
    }

    return result;
}
*/

int *postorder(struct Node *root, int *returnSize) {
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
        for (int i = 0 ; i < target->numChildren ; ++ i) {
            nodes[nodes_top ++] = target->children[i];
        }
    }

    for (int i = 0 ; i < *returnSize / 2 ; ++ i) {
        int temp = result[i];
        result[i] = result[*returnSize - i - 1];
        result[*returnSize - i - 1] = temp;
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
    root->children[1]->numChildren = 1;
    root->children[1]->val = 122;
    root->children[1]->children = (struct Node **)malloc(sizeof(struct Node *));
    root->children[1]->children[0] = (struct Node *)malloc(sizeof(struct Node));
    root->children[1]->children[0]->numChildren = 1;
    root->children[1]->children[0]->val = 2111;
    root->children[1]->children[0]->children = (struct Node **)malloc(sizeof(struct Node*));
    root->children[1]->children[0]->children[0] = (struct Node *)malloc(sizeof(struct Node));
    root->children[1]->children[0]->children[0]->numChildren = 0;
    root->children[1]->children[0]->children[0]->val = 31111;

    int returnSize = 0;
    int *result = postorder(root, &returnSize);
    for (int i = 0 ; i < returnSize ; ++ i) {
        printf("%d\n", result[i]);
    }

    free(result);
    free(root->children[1]->children[0]->children[0]);
    free(root->children[1]->children[0]->children);
    free(root->children[1]->children[0]);
    free(root->children[1]->children);
    free(root->children[0]);
    free(root->children[1]);
    free(root->children);
    free(root);

    return 0;
}
