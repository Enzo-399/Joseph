#include <iostream>
#include <malloc.h>

using namespace std;

struct node{
    int num;                     //��Ž������
    int password;                //����������
    node *next;
};

int main() {
    int m,n;
    node *p, *q, *first;
    cout << "������m�ĳ�ʼֵ: ";
    cin >> m;
    cout << "���������� n:";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            first = p = (node *) malloc(sizeof(node));
            if (p == 0) {
                return 0;
            }
        } else {
            q = (node *) malloc(sizeof(node));
            if (q == 0) {
                return 0;
            }
            p->next = q;
            p = p->next;
        }
        cout << "������� " << i << " ���˵����룺";
        cin >> p->password;
        p->num = i;
    }
    p->next = first;            //����βָ���ͷ�γ�ѭ������
    p = first;
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i < m; i++, p = p->next) ;
        m = p->password;
        cout << p->num << " ";
        p->num = p->next->num;
        p->password = p->next->password;
        q = p->next;
        p->next = p->next->next;
        free(q);
    }
    cout << endl;
    return 0;
}