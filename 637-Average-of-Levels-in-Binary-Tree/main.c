#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 * 二叉树的层次遍历，每层记录节点数量和节点之和
 */
double* averageOfLevels(struct TreeNode *root, int *returnSize){
    double *result = (double *)malloc(sizeof(double) * 1000);
    *returnSize = 0;

    struct TreeNode *nodes[10000];
    int nodes_begin = 0;
    int nodes_end = 0;
    nodes[nodes_end ++] = root;

    while (nodes_begin < nodes_end) {
        int layer_end = nodes_end;
        double layer_sum = 0.0;
        int layer_count = nodes_end - nodes_begin;
        while (nodes_begin < nodes_end) {
            if (nodes[nodes_begin]->left) {
                nodes[layer_end ++] = nodes[nodes_begin]->left;
            }
            if (nodes[nodes_begin]->right) {
                nodes[layer_end ++] = nodes[nodes_begin]->right;
            }

            layer_sum += nodes[nodes_begin]->val;
            ++ nodes_begin;
        }

        result[(*returnSize) ++] = layer_sum / (double)layer_count;
        nodes_begin = nodes_end;
        nodes_end = layer_end;
    }

    return result;
}

int main() {
    return 0;
}
