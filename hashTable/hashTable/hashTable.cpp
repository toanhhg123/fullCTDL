#include <iostream>
using namespace std;
#define class 15
struct Node
{
    int data;
    Node* next;
};
Node* creatNode(int data)
{
    Node* p = new Node;
    p->data = data;
    p->next = NULL;
    return p;
}
struct classTable
{
    Node* head;
    Node* tail;
};
void creatClasstable( classTable &l)
{
    l.head = l.tail = NULL;
}
struct hashTable
{
    classTable *Table;
};
void creatHashTable(hashTable& h)
{
    h.Table = new classTable[class];
    for (int i = 0; i<class; i++)
    {
        creatClasstable(h.Table[i]);
    }
}
int cl(int x)
{
    return x%class;
}
void push(classTable& l, Node* p)
{
    if (l.head == NULL)
        l.head = l.tail = p;
    else
    {
        l.tail->next = p;
        l.tail = p;
    }
}
void addNodeToTable(hashTable& h,int x)
{
    Node* p = creatNode(x);
    int Class = cl(p->data);
    if (Class < class) 
    {
        classTable l = h.Table[Class];
        while (l.head!=NULL)
        {
            if (l.head->data == x)
            {
                cout << "\n" << x << " da co trong table";
                return;
            }
            l.head = l.head->next;
        }
        push(h.Table[Class], p);
    }
    else if(Class>class)
    {
        cout << "\nLoi phan tu ";
        return;
    }
}
void input(hashTable &h) {
    creatHashTable(h);
    int n;
    int x;
    cout << "\nNhap so luong phan tu can add vao Hash table: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap phan tu x: ";
        cin >> x;
        addNodeToTable(h, x);
    }
}
void output(hashTable h)
{
    cout << "\nDanh sach table: ";
    for (int i = 0; i<class; i++)
    {
        cout << "\nclass " << i << " :";
        classTable l = h.Table[i];
        if (l.head != NULL)
        {
            while (l.head != NULL)
            {
                cout <<"\t"<< l.head->data;
                l.head = l.head->next;
            }
        }
        else
            cout << "\t NULL";
    }
}
void sreachX(hashTable h ,int x)
{
    int Class = cl(x);
    classTable l = h.Table[Class];
    if (l.head == NULL)
    {
        cout << "\nphan tu " << x << " khong co trong table";
    }
    else
    {
        while (l.head!=NULL)
        {
            if (l.head->data == x)
            {
                cout << "\nphan tu " << x << " co trong table"<<" class "<<Class;
            }
            l.head = l.head->next;
        }
    }
    
}
int sizeList(classTable l)
{
    int size = 0;
    while (l.head!=NULL)
    {
        size++;
        l.head = l.head->next;
    }
    return size;
}
Node* Node_Index(classTable l,int vitri)
{
    int count = 0;
    while (l.head!=NULL)
    {
        if (count == vitri)
        {
            return l.head;
        }
        l.head = l.head->next;
    }

}
void deleteX(hashTable& h, int x)
{
    int Class = cl(x);
    if (sizeList(h.Table[Class]) == 0)
    {
        cout << "\ndanh sach rong ";
        return;
    }
    classTable l = h.Table[Class];
   
        if (l.head->data == x)
        {
            l.head = l.head->next;
            h.Table[Class] = l;
            return;
        }
        else if (l.tail->data == x)
        {
            Node_Index(l, sizeList(l) - 2)->next=NULL;
            delete l.tail;
            h.Table[Class] = l;
            return;
        }
        else
        {
            while (l.head!=NULL)
            {
                if (l.head->data == x)
                {
                    l.head->data = l.head->next->data;
                    l.head->next = l.head->next->next;
                    delete l.head->next;
                    return;
                }
                l.head = l.head->next;
            }
            
        }
    cout << "\n" << x << " khong co trong table";
}
int main()
{
    hashTable h;
    input(h);
    output(h);
    deleteX(h, 10);
    output(h);
    return 0;
}