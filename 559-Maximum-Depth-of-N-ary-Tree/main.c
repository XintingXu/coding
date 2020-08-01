#include <stdio.h>

struct Node {
    int val;
    int numChildren;
    struct Node** children;
};

struct Node *nodes[10010];

int maxDepth(struct Node* root) {
    if (!root) {
        return 0;
    }

    int layer_begin = 0;
    int layer_end = 0;
    int layer_count = 0;

    nodes[layer_end] = root;
    ++ layer_end;

    while (layer_begin != layer_end) {
        int current_layer_end = layer_end;

        while (layer_begin < layer_end) {
            for (int i = 0 ; i < nodes[layer_begin]->numChildren ; ++ i) {
                nodes[current_layer_end] = *(nodes[layer_begin]->children + i);
                ++ current_layer_end;
            }
            ++ layer_begin;
        }

        layer_end = current_layer_end;
        ++ layer_count;
    }

    return layer_count;
}

int main() {
    return 0;
}
