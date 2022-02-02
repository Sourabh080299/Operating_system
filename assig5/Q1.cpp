#include <bits/stdc++.h>
using namespace std;
struct node //vacant linked list
{
 int startAddress;
 int endAddress;
 struct node *next;
 struct node *pre;
};
struct node1 //allocated linked list
{
 int startAddress;
 int endAddress;
 int processId;
 struct node1 *next;
 struct node1 *pre;
};
struct node *head, *tail;
struct node1 *head1 = NULL, *tail1;
struct node *createnode()
{
 struct node *t;
 t = (struct node *)malloc(sizeof(struct node));
 return (t);
}
struct node1 *createnode1()
{
 struct node1 *t;
 t = (struct node1 *)malloc(sizeof(struct node1));
 return (t);
}
void memory()
{
 struct node *o, *p, *pre = NULL, *ptr;
 o = createnode();
 o->startAddress = 10;
 o->endAddress = 90;
 o->pre = NULL;
 head = o;
 pre = o;
 for (int i = 1; i < 10; i++)
 {
 p = createnode();
 pre->next = p;
 p->pre = pre;
 p->next = NULL;
 p->startAddress = pre->endAddress + i * 10;
 p->endAddress = p->startAddress + (i * 50) + i * i;
 pre = p;
 }
 p = createnode();
 p->endAddress = 3150;
 p->startAddress = 3000;
 p->next = NULL;
 p->pre = pre;
 pre->next = p;
 ptr = head;
 tail = p;
 /*
while(ptr->next!=NULL)
{
cout<<ptr->endAddress<<" - "<<ptr->startAddress<<" = "<<ptr->endAddress-ptr-
>startAddress<<endl;
ptr=ptr->next;
}
cout<<ptr->endAddress<<" - "<<ptr->startAddress<<" = "<<ptr->endAddress-ptr-
>startAddress<<endl;
*/
 return;
}
void first_fit()
{
 int n, left, alloc = 0;
 cout << "\nEnter the no. of process you want to take :- ";
 cin >> n;
 vector<vector<int>> a(n, vector<int>(2));
 cout << "\nEnter\nPro.Id Size\n";
 for (int i = 0; i < n; i++)
 {
 cin >> a[i][0] >> a[i][1];
 }
 struct node *ptr;
 struct node1 *ptr1, *pre = NULL;
 ptr = head;
 int size = 0;
 for (int i = 0; i < n; i++)
 {
 ptr = head;
 while (ptr->next != NULL && (ptr->endAddress - ptr-
>startAddress) < a[i][1])
 {
 ptr = ptr->next;
 }
 if (ptr->pre == NULL)
 {
 ptr1 = createnode1();
 if (head1 != NULL)
 {
 pre->next = ptr1;
 }
 ptr1->pre = pre;
 ptr1->next = NULL;
 if (head1 == NULL)
 {
 head1 = ptr1;
 }
 ptr1->startAddress = ptr->startAddress;
 ptr1->endAddress = ptr->endAddress;
 ptr1->processId = a[i][0];
 head = ptr->next;
 head->pre = NULL;
 pre = ptr1;
 alloc++;
 }
 else if (ptr->next == NULL && (ptr->endAddress - ptr-
>startAddress) >= a[i][1])
 {
 ptr1 = createnode1();
 if (head1 != NULL)
 {
 pre->next = ptr1;
 }
 ptr1->pre = pre;
 ptr1->next = NULL;
 if (head1 == NULL)
 {
 head1 = ptr1;
 }
 ptr1->startAddress = ptr->startAddress;
 ptr1->endAddress = ptr->endAddress;
 ptr1->processId = a[i][0];
 tail = ptr->pre;
 tail->next = NULL;
 pre = ptr1;
 alloc++;
 }
 else if (ptr->next == NULL)
 {
 continue;
 }
 else
 {
 ptr1 = createnode1();
 if (head1 != NULL)
 {
 pre->next = ptr1;
 }
 ptr1->pre = pre;
 ptr1->next = NULL;
 if (head1 == NULL)
 {
 head1 = ptr1;
 }
 ptr1->startAddress = ptr->startAddress;
 ptr1->endAddress = ptr->endAddress;
 ptr1->processId = a[i][0];
 (ptr->pre)->next = ptr->next;
 (ptr->next)->pre = ptr->pre;
 pre = ptr1;
 alloc++;
 }
 }
 cout << "\n======== For First fit algorithm ========\n";
 cout << "\n Total " << alloc << " processes allocate memory and " << n - a
lloc << " processes memory allocation not possible\n";
 ptr = head;
 ptr1 = head1;
 cout << "\nAllocate slots are\nStart Add. End Add. Proc. Id\n";
 while (ptr1->next != NULL)
 {
 cout << ptr1->startAddress << "\t" << ptr1-
>endAddress << "\t" << ptr1->processId << "\t" << ptr1->endAddress - ptr1-
>startAddress << endl;
 ptr1 = ptr1->next;
 }
 cout << ptr1->startAddress << "\t" << ptr1->endAddress << "\t" << ptr1-
>processId << "\t" << ptr1->endAddress - ptr1->startAddress << endl;
 ptr = head;
 cout << "\nEmpty slots are\nStart Add. End Add.\n";
 while (ptr->next != NULL)
 {
 cout << ptr->endAddress << "\t" << ptr->startAddress << "\t" << ptr-
>endAddress - ptr->startAddress << endl;
 ptr = ptr->next;
 }
 cout << ptr->endAddress << "\t" << ptr->startAddress << "\t" << ptr-
>endAddress - ptr->startAddress << endl;
 cout << "\n======== For First fit algorithm Ends ========\n";
}
void best_fit()
{
 int n, left, alloc = 0;
 cout << "\nEnter the no. of process you want to take :- ";
 cin >> n;
 vector<vector<int>> a(n, vector<int>(2));
 cout << "\nEnter\nPro.Id Size\n";
 for (int i = 0; i < n; i++)
 {
 cin >> a[i][0] >> a[i][1];
 }
 struct node *ptr, *ptrr = NULL;
 struct node1 *ptr1, *pre = NULL;
 ptr = head;
 int size = INT_MAX;
 for (int i = 0; i < n; i++)
 {
 size = INT_MAX;
 ptr = head;
 ptrr = NULL;
 while (ptr->next != NULL)
 {
 if ((ptr->endAddress - ptr->startAddress) >= a[i][1])
 {
 if (size > (ptr->endAddress - ptr->startAddress))
 {
 size = (ptr->endAddress - ptr->startAddress);
 ptrr = ptr;
 }
 }
 ptr = ptr->next;
 }
 if ((ptr->endAddress - ptr->startAddress) >= a[i][1])
 {
 if (size > (ptr->endAddress - ptr->startAddress))
 {
 size = (ptr->endAddress - ptr->startAddress);
 ptrr = ptr;
 }
 }
 ptr = ptrr;
 if (ptr == NULL)
 {
 continue;
 }
 if (ptr->pre == NULL)
 {
 ptr1 = createnode1();
 if (head1 != NULL)
 {
 pre->next = ptr1;
 }
 ptr1->pre = pre;
 ptr1->next = NULL;
 if (head1 == NULL)
 {
 head1 = ptr1;
 }
 ptr1->startAddress = ptr->startAddress;
 ptr1->endAddress = ptr->endAddress;
 ptr1->processId = a[i][0];
 head = ptr->next;
 head->pre = NULL;
 pre = ptr1;
 alloc++;
 }
 else if (ptr->next == NULL)
 {
 ptr1 = createnode1();
 if (head1 != NULL)
 {
 pre->next = ptr1;
 }
 ptr1->pre = pre;
 ptr1->next = NULL;
 if (head1 == NULL)
 {
 head1 = ptr1;
 }
 ptr1->startAddress = ptr->startAddress;
 ptr1->endAddress = ptr->endAddress;
 ptr1->processId = a[i][0];
 tail = ptr->pre;
 tail->next = NULL;
 pre = ptr1;
 alloc++;
 }
 else
 {
 ptr1 = createnode1();
 if (head1 != NULL)
 {
 pre->next = ptr1;
 }
 ptr1->pre = pre;
 ptr1->next = NULL;
 if (head1 == NULL)
 {
 head1 = ptr1;
 }
 ptr1->startAddress = ptr->startAddress;
 ptr1->endAddress = ptr->endAddress;
 ptr1->processId = a[i][0];
 (ptr->pre)->next = ptr->next;
 (ptr->next)->pre = ptr->pre;
 pre = ptr1;
 alloc++;
 }
 }
 cout << "\n======== For Best fit algorithm ========\n";
 cout << "\n Total " << alloc << " processes allocate memory and " << n - a
lloc << " processes memory allocation not possible\n";
 ptr = head;
 ptr1 = head1;
 cout << "\nAllocate slots are\nStart Add. End Add. Proc. Id\n";
 while (ptr1->next != NULL)
 {
 cout << ptr1->startAddress << "\t" << ptr1-
>endAddress << "\t" << ptr1->processId << "\t" << ptr1->endAddress - ptr1-
>startAddress << endl;
 ptr1 = ptr1->next;
 }
 cout << ptr1->startAddress << "\t" << ptr1->endAddress << "\t" << ptr1-
>processId << "\t" << ptr1->endAddress - ptr1->startAddress << endl;
 ptr = head;
 cout << "\nEmpty slots are\nStart Add. End Add.\n";
 while (ptr->next != NULL)
 {
 cout << ptr->endAddress << "\t" << ptr->startAddress << "\t" << ptr-
>endAddress - ptr->startAddress << endl;
 ptr = ptr->next;
 }
 cout << ptr->endAddress << "\t" << ptr->startAddress << "\t" << ptr-
>endAddress - ptr->startAddress << endl;
 cout << "\n======== For Best fit algorithm Ends ========\n";
}
void worst_fit()
{
 int n, left, alloc = 0;
 cout << "\nEnter the no. of process you want to take :- ";
 cin >> n;
 vector<vector<int>> a(n, vector<int>(2));
 cout << "\nEnter\nPro.Id Size\n";
 for (int i = 0; i < n; i++)
 {
 cin >> a[i][0] >> a[i][1];
 }
 struct node *ptr, *ptrr = NULL;
 struct node1 *ptr1, *pre = NULL;
 ptr = head;
 int size = INT_MAX;
 for (int i = 0; i < n; i++)
 {
 size = INT_MIN;
 ptr = head;
 ptrr = NULL;
 while (ptr->next != NULL)
 {
 if ((ptr->endAddress - ptr->startAddress) >= a[i][1])
 {
 if (size < (ptr->endAddress - ptr->startAddress))
 {
 size = (ptr->endAddress - ptr->startAddress);
 ptrr = ptr;
 }
 }
 ptr = ptr->next;
 }
 if ((ptr->endAddress - ptr->startAddress) >= a[i][1])
 {
 if (size < (ptr->endAddress - ptr->startAddress))
 {
 size = (ptr->endAddress - ptr->startAddress);
 ptrr = ptr;
 }
 }
 ptr = ptrr;
 if (ptr == NULL)
 {
 continue;
 }
 if (ptr->pre == NULL)
 {
 ptr1 = createnode1();
 if (head1 != NULL)
 {
 pre->next = ptr1;
 }
 ptr1->pre = pre;
 ptr1->next = NULL;
 if (head1 == NULL)
 {
 head1 = ptr1;
 }
 ptr1->startAddress = ptr->startAddress;
 ptr1->endAddress = ptr->endAddress;
 ptr1->processId = a[i][0];
 head = ptr->next;
 head->pre = NULL;
 pre = ptr1;
 alloc++;
 }
 else if (ptr->next == NULL)
 {
 ptr1 = createnode1();
 if (head1 != NULL)
 {
 pre->next = ptr1;
 }
 ptr1->pre = pre;
 ptr1->next = NULL;
 if (head1 == NULL)
 {
 head1 = ptr1;
 }
 ptr1->startAddress = ptr->startAddress;
 ptr1->endAddress = ptr->endAddress;
 ptr1->processId = a[i][0];
 tail = ptr->pre;
 tail->next = NULL;
 pre = ptr1;
 alloc++;
 }
 else
 {
 ptr1 = createnode1();
 if (head1 != NULL)
 {
 pre->next = ptr1;
 }
 ptr1->pre = pre;
 ptr1->next = NULL;
 if (head1 == NULL)
 {
 head1 = ptr1;
 }
 ptr1->startAddress = ptr->startAddress;
 ptr1->endAddress = ptr->endAddress;
 ptr1->processId = a[i][0];
 (ptr->pre)->next = ptr->next;
 (ptr->next)->pre = ptr->pre;
 pre = ptr1;
 alloc++;
 }
 }
 cout << "\n======== For worst fit algorithm ========\n";
 cout << "\n Total " << alloc << " processes allocate memory and " << n - a
lloc << " processes memory allocation not possible\n";
 ptr = head;
 ptr1 = head1;
 cout << "\nAllocate slots are\nStart Add. End Add. Proc. Id\n";
 while (ptr1->next != NULL)
 {
 cout << ptr1->startAddress << "\t" << ptr1-
>endAddress << "\t" << ptr1->processId << "\t" << ptr1->endAddress - ptr1-
>startAddress << endl;
 ptr1 = ptr1->next;
 }
 cout << ptr1->startAddress << "\t" << ptr1->endAddress << "\t" << ptr1-
>processId << "\t" << ptr1->endAddress - ptr1->startAddress << endl;
 ptr = head;
 cout << "\nEmpty slots are\nStart Add. End Add.\n";
 while (ptr->next != NULL)
 {
 cout << ptr->endAddress << "\t" << ptr->startAddress << "\t" << ptr-
>endAddress - ptr->startAddress << endl;
 ptr = ptr->next;
 }
 cout << ptr->endAddress << "\t" << ptr->startAddress << "\t" << ptr-
>endAddress - ptr->startAddress << endl;
 cout << "\n======== For worst fit algorithm Ends ========\n";
}
int main()
{
 int n, x, p, q;
 memory();
joy:
 cout << "\n======== Choose the appropriate fit algorithm ========\n";
 cout << "\n1. for first fit\n2. for best fit\n3. for worst fit\n";
 cin >> x;
 if (x == 1)
 {
 first_fit();
 }
 else if (x == 2)
 {
 best_fit();
 }
 else if (x == 3)
 {
 worst_fit();
 }
 else
 {
 cout << "\nerror145 : Wrong input Try Again\n";
 goto joy;
 }
 return 0;
}
Initially Empty Slots are
Start_Add End_Add Block_Size
90 - 10 = 80
151 - 100 = 51
275 - 171 = 104
464 - 305 = 159
720 - 504 = 216
1045 - 770 = 275
1441 - 1105 = 336
1910 - 1511 = 399
2454 - 1990 = 464
3075 - 2544 = 531
3150 - 3000 = 150
