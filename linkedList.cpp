
#include <iostream>
typedef int ElemType;
const int MAXSIZE = 20;
enum Status{
    ERROR=0,
    OK,
};

using namespace std;

struct SqList
{
    ElemType data[MAXSIZE];
    ElemType alter[MAXSIZE];
    int Length;//current length
};

struct LinkedList
{
    int value,index=0;
    LinkedList* next;
    LinkedList(int v,int i):value{v},index{i},next{nullptr}{}

};

ostream& operator<<(ostream& os,const SqList& sql)
{
    for(auto i:sql.data)
        os<<i<<" ";
    os<<"\n";

     for(auto i:sql.alter)
        os<<i<<" ";
    os<<"\n";
    return os;
}

ostream& operator<<(ostream& os, LinkedList* lst)
{
    LinkedList* tmp = lst;
    while(tmp->next)
    {
        os<<"("<<tmp->value<<")->";
        tmp = tmp->next;
    }
    os<<"("<<tmp->value<<")\n";

}
namespace ListOperation
{
    //insert data at position
    Status insert(SqList& d, int pos, int val)
    {
        //check position range
        if(pos>MAXSIZE || pos<0 || pos >d.Length)
            return Status::ERROR;
        //shift all data if pos is not at end
        if(pos<=d.Length)
        {
            for(int i=d.Length;i>=pos;--i)
            {
                d.data[i+1] = d.data[i];
            }
        }
        //insert the val at pos
        d.data[pos] = val;
        return Status::OK;
    }
    Status insert(LinkedList* lst,int pos,int val)
    {
        LinkedList* tmp = lst;
        while(tmp->next && pos!=0)
        {
            tmp=tmp->next;
            --pos;
        }
        if (pos==0 && tmp)
        {
            tmp->value = val;   
            return Status::OK;
        }else{
            return Status::ERROR;
        }
    }
};


int main()
{

    LinkedList*  ls = new LinkedList(1,1);
    ls->next = new LinkedList(2,2);
    
    cout<<ls;
}
