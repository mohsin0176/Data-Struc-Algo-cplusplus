#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct btnode
{
    int value;
    struct btnode *l;
    struct btnode *r;
}*root=NULL,*temp=NULL,*t1,*t2;
void delete1();
void insert();
void delete();
void inorder(struct btnode *t);
void create();
void search(struct btnode *t);
void preorder(struct btnode *t);
void postoredr(struct btnode *t);
void search1(struct btnode *t,int data);
int smallest(struct btnode *t);
int largest(struct btnode *t);
int flag=1;
void main()
{
    int ch;
    cout<<"OPERATIONS"<<endl;
    cout<<"1.Insert An Element into tree"<<endl;
    cout<<"2.Delete An Element from tree"<<endl;
    cout<<"3.Inorder Traversal"<<endl;
    cout<<"4.Preorder Tarversal"<<endl;
    cout<<"5.Postorder Tarversal"<<endl;
    cout<<"6.Exit"<<endl;
    while(1)
    {
        cout<<"Enter Choice"<<endl;
        cin>>ch;
        switch(ch)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            inorder(root);
            break;
        case 4:
            preorder(root);
            break;
        case 5:
            postorder(root);
            break;
        case 6:
            exit(0);
        default:
            cout<<"Wrong Choice"<<endl;
            break;
        }
    }
}
void insert()
{
    create();
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        search(root);
    }
}
void create()
{
    int data;
    cout<<"Enter Data to be inserted"<<endl;
    cin>>data;
    temp=(struct btnode*)malloc(1*sizeof(struct btnode));
    temp->value=data;
    temp->l=temp->r=NULL:

}
void search(struct btnode *t)
{
    if((temp->value>t->value)&&(t->!=NULL))
        search(t->r);
    else if((temp->value>t->value)&&(t->NULL))
        t->r=temp;
    else if((temp->value<t->value)&&(t->!=NULL))
        search(t->l);
    else if((temp->value<t->value)&&(t->=NULL))
        t->temp;

}
void inorder(struct btnode *t)
{
    if(root==NULL)
    {
        cout<<"No Elements in The Tree"<<endl;
        return;
    }
    if(t->!=NULL)
    {
        inorder(t->l);
        cout<<t->value;
        if(t->r!=NULL)
        inorder(t->r);
    }
}


void delete()
{
    int data;
    if(root==NULL)
    {
        cout<<"NO element to delete"<<endl;
        return;
    }
    cout<<"Enter data to be deleted"<<endl;
    cin>>data;
    t1=root;
    t2=root;
    search1(root,data);
}
void preorder(struct btnode *t)
{
    if(root==NULL)
    {
        cout<<"No Elements in Tree To Display"<<endl;
        return;
    }
    cout<<t->value;
    if(t->r!=NULL)
    postorder(t->r);
    cout<<t->value;
}

void postorder(struct btnode *t)
{
    if(root==NULL)
    {
        cout<<"No Elements in a Tree to display"<<endl;
        return;
    }
    if(t->l!=NULL)
        postorder(t->l);
    if(t->!=NULL)
        postorder(t->r);
         cout<<t->value;
}

void search1(struct btnode *t,int data)
{
    if((data>t->value))
    {
        t1=t;
        search1(t->r,data);
    }
    else if((data<t->value))
    {
        t1=t;
        search1(t->l,data);
    }
    else if((data==t->value))
    {
        delete1(t);
    }
}
void delete1(struct btnode *t)
{
    int k;
    if((t->l==NULL)&&(t->r==NULL))
    {
        if(t1->l==t)
        {
            t1->l==NULL;
        }
        else
        {
            t1->r=NULL;
        }
        t=NULL;
        free(t);
        return;
    }
    else if((t->r==NULL))
    {
        if(t1==t)
        {
            root=t->l;
            t1=root;
        }
        else if(t1->l==t)
        {
            t1->l=t->l;
        }
        else
        {
            t1->r=t->l;
        }
        t=NULL;
        free(t);
        return;
    }
    else if((t1->l!=NULL)&&(t->r!=NULL))
    {
        t2=root;
        if(t->r!=NULL)
        {
            k=smallest(t->r);
            flag=1;
        }
        else
        {
            k=largest(t->l);
            flag=2;
        }
        search1(root,k);
        t->value;

    }
}
int smallest(struct btnode *t)
{
    t2=t;
    if(t->l!=NULL)
    {
        t2=t;
        return (smallest(t->l));
    }
    else
        return (t->value);
}
int largest(struct btnode *t)
{
    if(t->r!=NULL)
    {
        t2=t;
        return(largest(t->r));
    }
    else
        return (t->value);
}
