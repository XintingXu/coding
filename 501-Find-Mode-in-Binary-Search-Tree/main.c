#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void searchMode(struct TreeNode *root, int *prefix, int *prefixCount, int *MaxMode, int *ModeCount) {
    if (root == NULL) {
        return;
    }

    searchMode(root->left, prefix, prefixCount, MaxMode, ModeCount);

    if (*prefixCount == 0) {
        *prefixCount = 1;
    } else {
        if (*prefix != root->val) {
            if (*prefixCount >= *MaxMode) {
                *ModeCount = *prefixCount == *MaxMode ? *ModeCount + 1 : 1;
            }
            *MaxMode = *prefixCount > *MaxMode ? *prefixCount : *MaxMode;
        }
        *prefixCount = *prefix == root->val ? *prefixCount + 1 : 1;
    }
    *prefix = root->val;

    searchMode(root->right, prefix, prefixCount, MaxMode, ModeCount);
}

void getMode(struct TreeNode *root, int *modes, int Mode, int *ModeCount, int *prefix, int *prefixCount) {
    if (root == NULL) {
        return 0;
    }

    getMode(root->left, modes, Mode, ModeCount, prefix, prefixCount);

    if (*prefixCount == 0) {
        *prefixCount = 1;
    } else {
        if (*prefix != root->val) {
            if (*prefixCount == Mode) {
                *(modes + *ModeCount) = *prefix;
                ++ *ModeCount;
            }
        }
        *prefixCount = *prefix == root->val ? *prefixCount + 1 : 1;
    }
    *prefix = root->val;

    getMode(root->right, modes, Mode, ModeCount, prefix, prefixCount);
}

int *findMode(struct TreeNode *root, int *returnSize) {
    if (root == NULL || returnSize == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int MaxMode = 0;    // 最终得到的Mode值
    int ModeCount = 0;  // 统计Mode的计数
    int prefix = 0;   // 前一个数据值
    int prefixCount = 0;    // 前置值的计数值
    searchMode(root, &prefix, &prefixCount, &MaxMode, &ModeCount);
    if (prefixCount >= MaxMode) {
        ModeCount = MaxMode == prefixCount ? ModeCount + 1 : 1;
        MaxMode = prefixCount;
    }

    int *result = (int *)malloc(sizeof(int) * ModeCount);
    memset(result, 0, sizeof(int) * ModeCount);
    ModeCount = 0;
    prefixCount = 0;

    getMode(root, result, MaxMode, &ModeCount, &prefix, &prefixCount);
    if (prefixCount == MaxMode) {
        *(result + ModeCount) = prefix;
        ++ ModeCount;
    }

    *returnSize = ModeCount;
    return result;
}

int main() {
    return 0;
}
