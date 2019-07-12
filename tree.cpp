#include<bits/stdc++.h>
using namespace std;
    
class Node 
{
    public:
        int data; 
        Node *left;
        Node *right;
        Node(int d) 
        {
            data = d;
            left = NULL;
            right = NULL;
        }
};



int main() {
    Node* array[1000005];
    long long n,t;
    long long a,b,c,x=0,y=0,z=0,ans;
    cin>>t;
    while(t--)
    {
    cin>>n;
    for(int i=1;i<=n;i++)
        array[i]=new Node(i);
    for(int i=1;i<=n;i++) 
    {
        cin>>a>>b>>c;
        if(b!=-1)
        array[a]->left = array[b];
        if(c!=-1)
        array[a]->right = array[c];
    }
    return 0;
}
