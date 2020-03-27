
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

int main()
{
    SqList s{{1,2,3,4,5},{0,1,2,3,4,5,6,7,8,9}};
    s.Length = 5;
    cout<<s;

    Status status = insert(s,2,9);
    cout<<"operation:"<<status<<'\n';
    cout<<s;
}
