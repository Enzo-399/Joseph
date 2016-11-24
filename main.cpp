#include <iostream>
#include <malloc.h>

using namespace std;

struct node{
    int num;                     //编号结点数据
    int password;                //密码结点数据
    node *next;
};

int main() {
    int m,n;
    node *p, *q, *first;
    cout << "请输入m的初始值: ";
    cin >> m;
    cout << "请输入人数 n:";
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
        cout << "请输入第 " << i << " 个人的密码：";
        cin >> p->password;
        p->num = i;
    }
    p->next = first;            //将表尾指向表头形成循环链表
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