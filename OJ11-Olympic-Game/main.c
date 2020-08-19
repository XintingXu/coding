#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct country{
    char name[25];
    int gold;
    int silver;
    int bronze;
} country_t;

#define CHANGE 1
#define KEEP 0

int cmp(const void *a, const void *b) {
    const country_t *a_c = (const country_t *)a;
    const country_t *b_c = (const country_t *)b;

    if (a_c->gold > b_c->gold) {
        return KEEP;
    } else if (a_c->gold < b_c->gold) {
        return CHANGE;
    }

    if (a_c->silver > b_c->silver) {
        return KEEP;
    } else if (a_c->silver < b_c->silver) {
        return CHANGE;
    }

    if (a_c->bronze > b_c->bronze) {
        return KEEP;
    } else if (a_c->bronze < b_c->bronze) {
        return CHANGE;
    }

    if (strcmp(a_c->name, b_c->name) < 0) {
        return KEEP;
    }

    return CHANGE;
}

int main() {
    country_t countries[20];
    memset(countries, 0, sizeof(countries));

    int count = 0;
    scanf("%d", &count);

    for (int i = 0 ; i < count ; ++i) {
        scanf("%s", countries[i].name);
        scanf("%d%d%d", &countries[i].gold, &countries[i].silver, &countries[i].bronze);
    }

    qsort(countries, count, sizeof(country_t), cmp);

    for (int i = 0 ; i < count ; ++i) {
        printf("%s\n", countries[i].name);
    }

    return 0;
}
