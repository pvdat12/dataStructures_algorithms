#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SV {
    char hoTen[50];
    unsigned int mssv;
    int namSinh;
    float cpa;
} SV;

typedef struct node {
    SV data;
    struct node *next;
} node;

node* makeNode(SV x) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void pushFront(node **head, SV x) {
    node *newNode = makeNode(x);
    newNode->next = *head;
    *head = newNode;
}

void pushBack(node **head, SV x) {
    node *newNode = makeNode(x);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    node *temp = *head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

void duyet(node *head) {
    while (head != NULL) {
        printf("\n--- Sinh Vien ---\n");
        printf("Ho Ten : %s", head->data.hoTen);
        printf("MSSV   : %u\n", head->data.mssv);
        printf("Nam sinh: %d\n", head->data.namSinh);
        printf("CPA    : %.2f\n", head->data.cpa);
        head = head->next;
    }
}

int size(node *head) {
    int cnt = 0;
    while (head != NULL) {
        cnt++;
        head = head->next;
    }
    return cnt;
}

int svCPA32(node *head) {
    int cnt = 0;
    while (head != NULL) {
        if (head->data.cpa > 3.2)
            cnt++;
        head = head->next;
    }
    return cnt;
}

void sortCPA(node *head) {
    if (head == NULL) return;

    for (node *p = head; p->next != NULL; p = p->next) {
        for (node *q = p->next; q != NULL; q = q->next) {
            if (p->data.cpa > q->data.cpa) {
                SV temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
        }
    }
}

SV nhapSV() {
    SV x;
    getchar();
    printf("Nhap ho ten: ");
    fgets(x.hoTen, sizeof(x.hoTen), stdin);
    printf("Nhap MSSV: "); scanf("%u", &x.mssv);
    printf("Nhap nam sinh: "); scanf("%d", &x.namSinh);
    printf("Nhap CPA: "); scanf("%f", &x.cpa);
    return x;
}

int main() {
    node *head = NULL;
    int lc;

    while (1) {
        printf("\n===== MENU =====\n");
        printf("1. Them SV vao cuoi danh sach\n");
        printf("2. In danh sach\n");
        printf("3. Dem so luong SV GPA > 3.2\n");
        printf("4. Sap xep tang dan theo GPA\n");
        printf("5. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &lc);

        if (lc == 1) {
            SV x = nhapSV();
            pushBack(&head, x);
        }
        else if (lc == 2) {
            duyet(head);
        }
        else if (lc == 3) {
            printf("So SV co GPA > 3.2: %d\n", svCPA32(head));
        }
        else if (lc == 4) {
            sortCPA(head);
            printf("Da sap xep!\n");
        }
        else break;
    }

    return 0;
}
