#include <stdio.h>

char word[110];
int n = 0;
int m = 0;
char characters[25][25];
int search_flags[25][25];

int search_dfs(char *word, const int i, const int j) {
    search_flags[i][j] = 1;
    ++word;
    if (!(*word)) {
        return 1;
    }

    int result = 0;
    if (i + 1 < n && search_flags[i + 1][j] == 0 && characters[i + 1][j] == *word) {
        result |= search_dfs(word, i + 1, j);
    }
    if (result) {
        return result;
    }

    if (i - 1 >=0 && search_flags[i - 1][j] == 0 && characters[i - 1][j] == *word) {
        result |= search_dfs(word, i - 1, j);
    }
    if (result) {
        return result;
    }

    if (j + 1 < m && search_flags[i][j + 1] == 0 && characters[i][j + 1] == *word) {
        result |= search_dfs(word, i, j + 1);
    }
    if (result) {
        return result;
    }

    if (j - 1 >= 0 && search_flags[i][j - 1] == 0 && characters[i][j - 1] == *word) {
        result |= search_dfs(word, i, j - 1);
    }
    if (result) {
        return result;
    }

    search_flags[i][j] = 0;
    return 0;
}

int main() {
    scanf("%d%d", &n, &m);
    scanf("%s", word);
    for (int i = 0 ; i < n ; ++i) {
        scanf("%s", characters[i]);
    }

    memset(search_flags, 0, sizeof(search_flags) / sizeof(int));

    for (int i = 0 ; i < n ; ++i) {
        for (int j = 0 ; j < m ; ++j) {
            if (characters[i][j] == word[0] && search_dfs(word, i, j)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}
