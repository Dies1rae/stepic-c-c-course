#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#pragma warning(disable:4996)
/*
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
char* itob(int i) {
    static char bits[8] = { '0','0','0','0','0','0','0','0' };
    int bits_index = 7;
    while (i > 0) {
        bits[bits_index--] = (i & 1) + '0';
        i = (i >> 1);
    }
    return bits;
}
int sum_digits(int i) {
    if (i == 0) {
        return 0;
    }
    else {
        return (i % 10 + sum_digits(i / 10));
    }
}
int res = 0;
void convert(int n) {
    for (unsigned bit = 1u << 4; bit != 0; bit >>= 1) {
        putchar((n & bit) ? '1' : '0');
        res *= 10;
        res += n & bit ? 1 : 0;
    }
}
void removeDuplicates(char* S) {
    if (S[0] == '\0') {
        return;
    }
    if (S[0] == S[1]) {
        int i = 0;
        while (S[i] != '\0') {
            S[i] = S[i + 1];
            i++;
        }
        removeDuplicates(S);
    }
    removeDuplicates(S + 1);
}
void my_strrev(char* array) {
    int size = 0, ptr = 0;
    while (array[size] != '\0') {
        size++;
    }
    while (size > ptr) {
        char tmp = array[--size];
        array[size] = array[ptr];
        array[ptr++] = tmp;
    }
}
char* make_copy(char* array) {
    char* strcp;
    strcp = (char*)malloc(strlen(array) * sizeof(char));
    strcpy(strcp, array);
    return strcp;
}
char* concat(char* s, char* t) {
    char* strcp = (char*)malloc(1 + strlen(s) + strlen(t));
    strcpy(strcp, s);
    strcat(strcp, t);
    return strcp;
}
struct person {
    char* name;
    int age;
};
struct person make_person(char* s, int age) {
    struct person A;
    A.name = (char*)malloc(strlen(s) * sizeof(char));
    strcpy(A.name, s);
    A.age = age;
    return A;
}
void sort(struct person* array, int n) {
    for (int ptr = 0; ptr < n; ptr++) {
        for (int ptr1 = 0; ptr1 < n; ptr1++) {
            if (array[ptr1].age > array[ptr].age) {
                struct person tmp = array[ptr];
                array[ptr] = array[ptr1];
                array[ptr1] = tmp;
            }
            else if (array[ptr1].age == array[ptr].age) {
                if (array[ptr1].name[0] > array[ptr].name[0]) {
                    struct person tmp = array[ptr];
                    array[ptr] = array[ptr1];
                    array[ptr1] = tmp;
                }
            }
        }
    }
}
void get_properties(int* array, int* min, int* max, int* num) {
    *min = array[0];
    while (array[*num] != 0) {
        (*num)++;
    }
    for (int i = 0; i < *num; i++) {
        if (*max <= array[i]) {
            *max = array[i];
        }
    }
    for (int i = 0; i < *num; i++) {
        if (*min >= array[i]) {
            *min = array[i];
        }
    }
}
*/

struct node {
    int* val;
    struct node* next;
};
struct list {
    struct node* first;
    struct node* last;
    int size;
};
struct person {
    int age;
    char* name;
};
struct node* make_node(int v) {
    struct node* r = (struct node*)malloc(sizeof(struct node));
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
struct person make_person(char* s, int age) {
    struct person A;
    A.name = (char*)malloc(strlen(s) * sizeof(char));
    strcpy(A.name, s);
    A.age = age;
    return A;
}

struct node* make_node(void* v, void* (*pfun)(void*)) {

}

void append(struct list* l, void* v, void* (*pfun)(void*)) {

}

void display(struct list l, void (*pfun)(void*)) {

}

void* copy_person(void* p) {

}

void display_person(void* p) {

}
int main() {
    /*
        int size = 0;
        int summ = 0;
        int mas[4];
        for (int ptr = 0; ptr < 4; ptr++) {
            scanf("%d", &mas[ptr]);
        }
        for (int ptr = 0; ptr < 4; ptr++) {
            if (mas[ptr] > 0) {
                size++;
                summ += mas[ptr];
            }
        }
        float res;
        if (size > 0) {
            res = (float)summ / size;
            printf("%.2f", res);
        }
        else {
            printf("%d", 0);
        }
        int res;
        res = getchar();
        printf("%d", res);
        int num;
        scanf("%d", &num);
        char *eng[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten" };
        char *rom[] = { "zero", "unu", "doi", "trei", "patru", "cinci", "șase", "șapte", "opt", "nouă", "zece" };
        printf("%d\n%s\n%s", num, eng[num], rom[num]);
        //a<b<c≤20
        int c, b, a = 1, ptr10 = 0;
        int arr[6][3];
        for (; a < 19; a++) {
            for (b = a + 1; b < 20; b++) {
                for (c = b + 1; c <= 20; c++) {
                    if (((a+b) >= c) && ((a*a)+(b*b) == c*c)) {
                        arr[ptr10][0] = a;
                        arr[ptr10][1] = b;
                        arr[ptr10][2] = c;
                        ptr10++;
                    }
                }
            }
        }
        for (int ptr0 = 0; ptr0 < 6; ptr0++) {
            for (int ptr1 = 0; ptr1 < 6; ptr1++) {
                if (arr[ptr1][2] > arr[ptr0][2]) {
                    int tmp0 = arr[ptr0][0];
                    int tmp1 = arr[ptr0][1];
                    int tmp2 = arr[ptr0][2];
                    arr[ptr0][2] = arr[ptr1][2];
                    arr[ptr0][1] = arr[ptr1][1];
                    arr[ptr0][0] = arr[ptr1][0];
                    arr[ptr1][2] = tmp2;
                    arr[ptr1][1] = tmp1;
                    arr[ptr1][0] = tmp0;
                }
            }
        }
        for (int ptr0 = 0; ptr0 < 6; ptr0++) {
            printf("%d %d %d\n", arr[ptr0][0], arr[ptr0][1], arr[ptr0][2]);
        }
        int num, ptr1, ptr2 = 0;
        scanf("%d", &num);
        ptr1 = num;
        while (ptr1) {

            ptr2 = ptr2 * 10;
            ptr2 = ptr2 + ptr1 % 10;
            ptr1 /= 10;
        }
        if (num == ptr2) {
            printf("%s","true");
        }
        else {
            printf("%s", "false");
        }
        int count = 0,n;
        scanf("%d", &n);
        while (!(n % 2)) {
            n >>= 1;
            count++;
        }
        if (count) {
            printf("%d %d\n", 2, count);
        }
        for (int i = 3; i <= sqrt(n); i += 2) {
            count = 0;
            while (n % i == 0) {
                count++;
                n = n / i;
            }
            if (count)
                printf("%d %d\n", i, count);
        }
        if (n > 2){
            printf("%d %d\n", n, 1);
        }
        char coffe[3][20];
        unsigned int A;
        int tmp;
        scanf("%u", &A);
        tmp = A;
        int BITS[8] = {0,0,0,0,0,0,0,0};
        char bits[8] = { '0','0','0','0','0','0','0','0' };
        int bits_index = 7;
        while (tmp > 0) {
            bits[bits_index] = (tmp & 1) + '0';
            tmp = (tmp >> 1);
            BITS[bits_index] = bits[bits_index] -'0';
            bits_index--;
        }

        for (int i = 3; i > 0; i--) {
            if (i == 3) {
                if (BITS[6] == 0 && BITS[7] == 0) {
                    strcpy(coffe[0],"Espresso");
                }
                if (BITS[6] == 0 && BITS[7] == 1) {
                    strcpy(coffe[0], "Long Coffee");
                }
                if (BITS[6] == 1 && BITS[7] == 0) {
                    strcpy(coffe[0], "Cappucino");
                }
                if (BITS[6] == 1 && BITS[7] == 1) {
                    strcpy(coffe[0], "Americano");
                }
            }
            if (i == 2) {
                if (BITS[3] == 0 && BITS[4] == 0 && BITS[5] == 0) {
                    strcpy(coffe[1], "no sugar");
                }
                if (BITS[3] == 0 && BITS[4] == 0 && BITS[5] == 1) {
                    strcpy(coffe[1], "1 sugar");
                }
                if (BITS[3] == 0 && BITS[4] == 1 && BITS[5] == 0) {
                    strcpy(coffe[1], "2 sugar");
                }
                if (BITS[3] == 0 && BITS[4] == 1 && BITS[5] == 1) {
                    strcpy(coffe[1], "3 sugar");
                }
                if (BITS[3] == 1 && BITS[4] == 0 && BITS[5] == 1) {
                    strcpy(coffe[1], "4 sugar");
                }
                if (BITS[3] == 1 && BITS[4] == 0 && BITS[5] == 0) {
                    strcpy(coffe[1], "5 sugar");
                }
                if (BITS[3] == 1 && BITS[4] == 1 && BITS[5] == 0) {
                    strcpy(coffe[1], "6 sugar");
                }
                if (BITS[3] == 1 && BITS[4] == 1 && BITS[5] == 1) {
                    strcpy(coffe[1], "7 sugar");
                }
            }
            if (i == 1) {
                if (BITS[2]) {
                    strcpy(coffe[2], "with lid");
                }
                else {
                    strcpy(coffe[2], "no lid");
                }
            }
        }
        printf("%s, %s, %s", coffe[0], coffe[1], coffe[2]);
                int n, i = 0, max = 0;
                scanf("%d", &n);
                while (n) {
                    int D;
                    scanf("%d", &D);
                    if (max < sum_digits(D)) {
                        max = sum_digits(D);
                    }
                    i++;
                    n--;
                }
                printf("%d", max);
                    int a;
                    scanf("%d", &a);
                    convert(a);
                    printf("\n%d", res);
                        int* arr;
                        int n, i = 0, found = 0;
                        scanf("%d",&n);
                        arr = (int*)malloc(n * sizeof(int));
                        while (n) {
                            int tmp;
                            scanf("%d", &tmp);
                            arr[i] = tmp;
                            i++;
                            n--;
                        }
                        scanf("%d", &found);
                        for (int ptr = 0; ptr < i; ptr++) {
                            if (found == arr[ptr]) {
                                printf("%d", ptr);
                                return 0;
                            }
                        }
                        printf("%d", -1);
                    int ptra = 0, h = 0, R = 0;
                    char str[129];
                    gets(str);
                    int* reps;
                    reps = (int*)malloc(strlen(str) * sizeof(int));
                    //tolower
                    for (int ptr = 0; ptr < strlen(str); ptr++) {
                        str[ptr] = tolower(str[ptr]);
                    }
                    //sort
                    for (; ptra < strlen(str) - 1;) {
                        if (str[ptra] > str[ptra + 1]) {
                            char tmp = str[ptra];
                            str[ptra] = str[ptra + 1];
                            str[ptra + 1] = tmp;
                            ptra = 0;
                        }
                        else {
                            ptra++;
                        }
                    }
                    //count reps
                    for (; h < strlen(str);) {
                        int count = 0;
                        for (int ptrj = h; ptrj < strlen(str); ptrj++) {
                            if (str[h] == str[ptrj]) {
                                count++;
                            }
                        }
                        reps[R] = count;
                        R++;
                        h += count;
                    }
                    //del reps
                    removeDuplicates(str);
                    //print
                    for (int ptr = 0; ptr < strlen(str); ptr++) {
                        printf("%c %d\n", str[ptr], reps[ptr]);
                    }
                int arr[10] = { 1,5,10,22,100,0,-8,6,7,3 };
                char str[] = "sky";
                get_properties(arr, arr[6], arr[4], 10);
                my_strrev(str);
                printf("%s", str);
                char res[] = "TY";
                char res1[] = "PIDOR";
                printf("%s", concat(res, res1));
             int main() {
                 int n;
                 scanf("%d", &n);
                 struct list l = make_list();
                 while (n != 0) {
                     append(&l, n);
                     scanf("%d", &n);
                 }
                 printf("%d\n", l.size);
                 display(l);

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
    char s[50];
    int age, i, n;
    struct person* p;
    scanf("%d", &n);
    p = (struct person*)malloc(n * sizeof(struct person));
    for (int ptr = 0; ptr < n; ptr++) {
        scanf("%s %d", s, &age);
        p[ptr] = make_person(s, age);
    }
    sort(p, n);
    for (int ptr = 0; ptr < n; ptr++) {
        printf("%s : %d\n", p[ptr].name, p[ptr].age);
    }
    
    int arr[8] = { 1,2,3,4,5,44,-257,0 };
    int min = 0, max = 0, num = 0; 
    int* ARR = &arr, M = &min, MX = &max, N = &num;
    get_properties(ARR, M, MX, N);
    printf("%d %d %d", min, max, num);
    */
    char s[50];
    int age, i, n;
    struct list l = make_list();
    struct person p;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s", s);
        scanf("%d", &age);
        p = make_person(s, age);
        append(&l, &p, copy_person);
        p.name[0] = '\0';
    }
    display(l, display_person);
    
    return 0;
}

