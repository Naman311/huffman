#include<iostream>
#include <vector>
using namespace std;


struct node
{
    char data;
    int fre;
    std::vector<int> v ;
    node *left,*right,*next;
}*temp,*head,*t1,*t2,*ptr,*heap;
void show()
{
    ptr=head;
    cout<<"\nThe list is :\n";
    while(ptr!=NULL)
    {
        cout<<ptr->data<<"  "<<ptr->fre<<endl;
        ptr=ptr->next;
    }
}
void listinsert(node *temp)
{
    if(head==NULL)
    {
        head=temp;
        head->next=NULL;
    }
    else
    {
        ptr=head;
        if(ptr->fre>temp->fre)
        {
            temp->next=ptr;
            head=temp;
        }
        else
        {
            while( (ptr->next) !=NULL && ((ptr->next->fre)<temp->fre)  )
            {
                ptr=ptr->next;
            }
            if((ptr->next)==NULL)
            {
                ptr->next=temp;
            }
            else
            {
                temp->next=ptr->next;
                ptr->next=temp;
            }
        }
    }
}

void poplist()
{
    while((head->next)!=NULL)
    {
        heap= new node;
        t1=head;
        head=t1->next;
        t2=head;
        head=t2->next;
        heap->data='/';
        heap->fre=((t1->fre)+(t2->fre));
        heap->left=t1;
        heap->right=t2;
        listinsert(heap);
    }
}
void showtree(node *temp)
{
    cout<<"   "<<temp->data<<"  "<<temp->fre<<endl;
    if((temp->left)!=NULL)
    {
        cout<<" 0 ";
        showtree(temp->left);
    }
    if((temp->right)!=NULL)
    {
        cout<<" 1 ";
        showtree(temp->right);
    }


}
void binarylist(node *temp)
{
    if(temp->data!='/')
    {
        cout<<temp->data<<"  ";
        for (std::vector<int>::iterator it = temp->v.begin() ; it != temp->v.end(); ++it)
            std::cout << *it;
        cout<<endl;
    }
    else
    {
        if((temp->left)!=NULL)
        {
            temp->left->v=temp->v;
            temp->left->v.push_back(0);
            binarylist(temp->left);
        }
        if((temp->right)!=NULL)
        {
            temp->right->v=temp->v;
            temp->right->v.push_back(1);
            binarylist(temp->right);
        }
    }

}
int main()
{
    int fre,n;
    char data;
    cout<<"Enter number of characters :";
    cin>>n;
    cout<<"Enter char and frequency :"<<endl;
    for(int i=0;i<n;i++)
    {
        temp = new node;
        cin>>temp->data;
        cin>>temp->fre;
        temp->next=NULL;
        temp->right=NULL;
        temp->left=NULL;
        listinsert(temp);
    }
    //show();
    poplist();
    cout<<"\n",
    //showtree(head);
    binarylist(head);
    return 0;
}
