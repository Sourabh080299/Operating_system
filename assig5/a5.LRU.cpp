#include <bits/stdc++.h>
using namespace std;
void lru()
{
 int w, n, fault = 0;
 cout << "\nEnter the window size :- ";
 cin >> w;
 cout << "\nEnter the number of process you want to execute :- ";
 cin >> n;
 vector<int> a(n);
 cout << "\nEnter the processes numbers :- ";
 for (int i = 0; i < n; i++)
 {
 cin >> a[i];
 }
 if (w >= n)
 {
 cout << "\nNo page fault occurs\n";
 return;
 }
 vector<int> b(w);
 for (int i = 0; i < w; i++)
 {
 b[i] = a[i];
 }
 int ptr = 0;
 for (int i = w; i < n; i++)
 {
 auto itr = find(b.begin(), b.end(), a[i]);
 if (itr == b.end())
 {
 //cout<<b[0]<<" "<<b[1]<<" "<<b[2]<<" "<<a[i]<<" "<<fault<<endl;
 b[ptr] = a[i];
 ptr = (ptr + 1) % w;
 fault++;
 //cout<<b[0]<<" "<<b[1]<<" "<<b[2]<<" "<<a[i]<<" "<<fault<<endl<<endl;
 }
 }
 cout << "\nTotal " << fault << " Faults happent in the LPU of given process\nAt the end these processes are left in window\n";
 for (int i = 0; i < w; i++)
 {
 cout << b[i] << " ";
 }
 return;
}
void opr()
{
 int w, n, fault = 0;
 cout << "\nEnter the window size :- ";
 cin >> w;
 cout << "\nEnter the number of process you want to execute :- ";
 cin >> n;
 vector<int> a(n);
 cout << "\nEnter the processes numbers :- ";
 for (int i = 0; i < n; i++)
 {
 cin >> a[i];
 }
 if (w >= n)
 {
 cout << "\nNo page fault occurs\n";
 return;
 }
 vector<int> b(w);
 for (int i = 0; i < w; i++)
 {
 b[i] = a[i];
 }
 int ptr = 0;
 for (int i = w; i < n; i++)
 {
 auto itr = find(b.begin(), b.end(), a[i]);
 if (itr == b.end())
 {
 int p = INT_MIN;
 for (int j = 0; j < w; j++)
 {
 int q = int(find(a.begin() + i + 1, a.begin() + n, b[j]) - (a.
begin() + i));
 if (q > p)
 {
 p = q;
 ptr = j;
 }
 }
 b[ptr] = a[i];
 ptr = (ptr + 1) % w;
 fault++;
 }
 }
 cout << "\nTotal " << fault << " Faults happent in the LPU of given process\nAt the end these processes are left in window\n";
 for (int i = 0; i < w; i++)
 {
 cout << b[i] << " ";
 }
 return;
}
int main()
{
 int n;
joy:
 cout << "select the algorithm you want for page replacement\n\t1. for LRU\n\t2. for Optimal Page replacement\n";
 cin >> n;
 if (n == 1)
 {
 lru();
 }
 else if (n == 2)
 {
 opr();
 }
 else
 {
 cout << "Wrong input try again";
 goto joy;
 }
 cout << "\n\n0. for exit\n1. for replacement again\n";
 cin >> n;
 if (n == 1)
 {
 goto joy;
 }
 return 0;
}
