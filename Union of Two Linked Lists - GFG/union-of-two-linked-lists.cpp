// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

struct Node* makeUnion(struct Node* head1, struct Node* head2);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        
        printList(makeUnion(first,second));
    }
    return 0;
}
// } Driver Code Ends


/*
// structure of the node is as follows

struct node
{
	int data;
	struct node* next;
	
	node(int x){
	    data = x;
	    next = NULL;
	}
	
};

*/

struct Node* makeUnion(struct Node* head1, struct Node* head2)
{
    Node* temp1 = head1;
    map<int,int> hmap;
    while (temp1) {              // I actually did temp1-> next != NULL which is WRONG>
        hmap[temp1->data]++;
        temp1 = temp1 -> next;
    }
    temp1 = head2;
    while (temp1) {
        hmap[temp1->data]++;
        temp1 = temp1 -> next;
    }
    
    vector<int> vec;
    for (auto& x : hmap) {
        vec.push_back(x.first);
        // cout << x.first;
    }
    
    sort(vec.begin(), vec.end());
    Node* curr = NULL;
    Node* res = NULL;
    for (int i = 0; i < vec.size(); i++)    {
        Node* newNode = new Node(vec[i]);
        if (i == 0) res = newNode;
        if (i > 0) curr -> next = newNode;
        curr = newNode;
    }
    

    return res;
}
