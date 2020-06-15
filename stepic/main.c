#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#pragma warning(disable:4996)

struct node {
    int val;
    struct node* next;
};

struct list {
    struct node* first;
    struct node* last;
    int size;
};

struct node* make_node(int v) {
    struct node *r = (struct node*)malloc(sizeof(struct node));
    r->val = v;
    r->next = NULL;
    return r;
};

struct list make_list() {
    struct list res;
    res.size = 0;
    res.first = NULL;
    res.last = NULL;
    return res;
};

void append(struct list* l, int v) {
    if (l->first == NULL) {
        l->first = make_node(v);
        l->last = l->first;
    }
    else {
        l->last->next = make_node(v);
        l->last = l->last->next;
    }
    l->size++;
}

void display(struct list l) {
    struct node* tmp = l.first;
    if (tmp == NULL) {
        return;
    }
    do  {
        printf("%d ", tmp->val);
        tmp = tmp->next;
    } while (tmp != NULL);
}

void get_properties(int* array, int* min, int* max, int* num) {
    int ptrsize, MIN, MAX;
    ptrsize = 0;
    MAX = 0;
    while (array[ptrsize] != -987654) {
        ptrsize++;
    }
    *num= ptrsize - 1;
    for (int i = 0; i < ptrsize-1; i++) {
        if (MAX < array[i]) {
            MAX = array[i];
        }
    }
    *max = MAX;
    MIN = array[0];
    for (int i = 0; i < ptrsize-1; i++) {
        if (MIN > array[i]) {
            MIN = array[i];
        }
    }
    *min = MIN;
}


int main() {
    /*
    int n;
    scanf("%d", &n);
    struct list l = make_list();
    while (n != 0) {
        append(&l, n);
        scanf("%d", &n);
    }
    printf("%d\n", l.size);
    display(l);
    */
    int mas[1000];
    int *min = 0, *max = 0, *num = 0, ptr, i = 0;
    scanf("%d", &ptr);
    while (ptr) {
        mas[i] = ptr;
        i++;
        scanf("%d", &ptr);
    }
    mas[i + 1] = -987654;
    get_properties(mas, &min, &max, &num);
    printf("min:%d, max:%d, num:%d", min, max, num);
    return 0;
}