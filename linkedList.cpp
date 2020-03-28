#include<iostream>

using namespace std;


struct Node
{
    int value;
    Node* next{nullptr};
    Node(int v):value{v}{}
};

ostream& operator<<(ostream& os, Node* nd)
{
    while(nd)
    {
        os<<"("<<nd->value<<")->";
        nd=nd->next;
    }
    return os;
}
void InsertAtFront(Node* head, int value)
{
    //insert at front of list
    Node&& tmp (value);
    tmp.next = head->next;
    *head = tmp;
    cout<<head<<'\n';
}

void InsertAtFront(Node** head_ref, int value)
{
    //insert at front of list
    Node* hd = new Node(value);
    hd->next = *head_ref;
    *head_ref = hd;
}
void CreateListHead(Node* head, int val)
{
    head->next = new Node(val);
}
void CreateListTail(Node* head, int val)
{
    while(head->next)
    {
        head = head->next;
    }
    head->next = new Node(val);
}
void DeleteList(Node* head)
{
    Node* p=head, *r;
    while(p)
    {
        r=head->next;
        free(p);
        p=r;
    }

}
int main()
{


    Node head(0);
    CreateListHead(&head,1);
    InsertAtFront(&head,6);
    CreateListTail(&head,10);
    // cout<<head.value<<"->"<<head.next->value;

    cout<<&head;


}
