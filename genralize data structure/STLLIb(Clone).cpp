///////////////////////////////////////////////////////
///////Generalised Data Structure Library(Project)////
///////////////////////////////////////////////////////
/*
-----------------------------------------------------------------------------------------------------------------
  Name Of class for Node      |        Name of class for Functionality         |               Type
---- - --------------------------------------------------------------------------------------------------------
  (Done) SinglyLLLnode        |               SinglyLLL                        |        SinglyLinear LinkedList  
  (Done) SinglyCLLnode        |                SinglyCLL                       |        SinglyCircular Linked List  
   (Done)DoublyLLLnode        |                 DoublyLLL                      |        DoublyLinear LinkedList       
   (Done)DoublyCLLnode        |                 DoublyCLL                      |         DoublyCircular LinkedList           
   (Done)StackNode            |                  Stack                         |               Stack          
   (Done)QueueNode            |                  Queue                         |                Queue                 
--------------------------------------------------------------------------------------------------------------    

*/


 #include<iostream>
using namespace std;
//////////////////////////////////////////////////////
// Singly Linear Linked List Using Generic Approach
///////////////////////////////////////////////////////
#pragma pack(1)
template<class T>
class SinglyLLLnode
{
   public:
    T data;
    SinglyLLLnode <T> * next;
    SinglyLLLnode(T No)
    {
      this->data=No;
      this->next=NULL;
    }

};

template<class T>
class SinglyLLL
{
   private:             
     SinglyLLLnode <T> * first;
     int iCount;


  public:
     SinglyLLL();
   

     void insertFirst(T);
    
    void insertLast(T );
    
        
     
     void deleteFirst();
    
      void deleteLast();
    
      
     void display();
    
     int Count();
    
     void deleteAtPos(int );
    
      void insertAtPos(T,int );
     
};



template<class T>
SinglyLLL <T> ::SinglyLLL()
{
   cout<<"Object of SinglyLL gets Created"<<endl;
   this->first=NULL;
   this->iCount=0;
}


/////////////////////////////////////////////////////////////////////////
////  Function Name: insertFirst()
////   Input:        Data Of Node
///    Output:       Nothing  
////   Description:  ussed to insert node toLinked List
////   Author:       Atharva Vasant Kandhare
////   Date:         06/01/2026
//////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLLL <T> ::insertFirst(T no)
{
SinglyLLLnode <T>  * newn =NULL;
newn = new SinglyLLLnode <T> (no);

newn->next= this->first;
   this->first=newn;
   this->iCount++;
}

template<class T>
void SinglyLLL <T> :: insertLast(T no)
{
SinglyLLLnode  <T> * temp=NULL;
   SinglyLLLnode  <T> * newn =NULL;
newn = new SinglyLLLnode <T> (no);

if( this->iCount==0)
{
   this->first=newn;
}
else
{
   
   temp= this->first;
   while(temp->next!=NULL)
   {

         temp=temp->next;

   }
      temp->next=newn;
}
   this->iCount++;
   
}

template<class T>
void SinglyLLL <T> ::deleteFirst()
{
SinglyLLLnode  <T> * temp =NULL;
   if( this->first==NULL)
   {
   return;
   }
   else if( this->first->next==NULL)
   {
      delete  this->first;
         this->first=NULL;
   }
   else
   {
      temp= this->first;
      this-> first= this->first->next;
      delete temp;
      }
      this->iCount--;
}

template<class T>
void SinglyLLL <T> :: deleteLast()
{
SinglyLLLnode  <T> * temp=NULL;
   if( this->first==NULL)
   {
   return;
   }
   else if( this->first->next==NULL)
   {
      delete  this->first;
         this->first=NULL;
   }
   else
   {
      temp= this->first;
      while(temp->next->next!=NULL)
      {
         temp=temp->next;
         
      }
         delete temp->next;
         temp->next=NULL;
   }
      this->iCount--;

}

template<class T>
void SinglyLLL <T> ::display()
{
SinglyLLLnode <T>  * temp=NULL;
int iCnt=0;
temp= this->first;
for(iCnt=1;iCnt<= this->iCount;iCnt++)
{
   cout<<"| "<<temp->data<<" |->";
   temp=temp->next;
}
cout<<"NULL\n";

}

template<class T>
int SinglyLLL <T> :: Count()
{
   return  this->iCount;
}

template<class T>
void SinglyLLL <T> ::deleteAtPos(int Pos)
{
   SinglyLLLnode <T>  * target=NULL;
   SinglyLLLnode <T>  * temp =NULL;

int iCnt=0;

if(Pos<1||Pos> this->iCount) 
{
   cout<<"Invalid Position\n";
   return;
}
else if(Pos==1)
{
   this-> deleteFirst();
}
else if(Pos== this->iCount)
{
      this->deleteLast();
}
else
{
   temp= this->first;
   for(iCnt=1;iCnt<Pos-1;iCnt++)
   {
      temp=temp->next;
   }
   target=temp->next;
   temp->next=target->next;
   delete target;
      this-> iCount--;
}

}

template<class T>
void SinglyLLL <T> :: insertAtPos(T no,int Pos)
{
SinglyLLLnode  <T> * temp=NULL;
   SinglyLLLnode <T>  * newn =NULL;
newn = new SinglyLLLnode <T> (no);

int iCnt=0;

if(Pos<1||Pos> this->iCount+1) 
{
   cout<<"Invalid Position\n";
   return;
}
else if(Pos==1)
{
   this->insertFirst(no);
}
else if(Pos== this->iCount+1)
{
   this-> insertLast(no);
}
else
{
   temp= this->first;
   for(iCnt=1;iCnt<Pos-1;iCnt++)
   {
      temp=temp->next;
   }
   newn->next=temp->next;
   temp->next=newn;
      this->iCount++;
}

   
}


////////////////////////////////////////////////////////
// DoublyLinearLinkedList using Generic Approach
///////////////////////////////////////////////////////
#pragma pack(1)
template <class T>
class DoublyLLLnode
{
    public:
    T data;
   DoublyLLLnode * next;
   DoublyLLLnode * prev;

    DoublyLLLnode(T no)
    {
        this->data=no;
        this->next=NULL;
        this->prev=NULL;

    } 
};
template <class T>
class DoublyLLL
{
    private:
      int iCount;
       DoublyLLLnode <T> * first;

    
  public:

        DoublyLLL();
       
        void insertFirst(T );
         void insertLast(T );
          void insertAtPos(T ,int );
          void deleteFirst();
           void deleteLast();
            void deleteAtPos(int);
            void display();
            int count();
    };

template <class T>
DoublyLLL<T>::DoublyLLL()
{
    cout<<"Linkedlist gets created";
    this->first=NULL;
    this->iCount=0;

}

template <class T>
void DoublyLLL<T>:: insertFirst(T No)
{
    DoublyLLLnode <T> * newn=NULL;
    newn = new DoublyLLLnode <T>(No);
    if(this->first==NULL)
    {
       this->first=newn;
    }
    else
    {
        newn->next=this->first;
        this->first->prev=newn;
        this->first=newn;


    }
    this->iCount++;

}

template <class T>
void DoublyLLL<T>:: insertLast(T No )
{
    DoublyLLLnode <T> * newn=NULL;
    DoublyLLLnode  <T> * temp=NULL;
    newn = new DoublyLLLnode <T>(No);
    if(this->first==NULL)
    {
       this->first=newn;
    }
    else
    {
        temp=this->first;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
        newn->prev=temp;
       

    }
    this->iCount++;

}

template <class T>
void DoublyLLL<T>:: insertAtPos(T No ,int Pos )
{
    DoublyLLLnode <T> * temp=NULL;
   
    int iCnt=0;
    if(Pos<1||Pos>this->iCount+1)
    {
        cout<<"Invalid Position"<<endl;                  
        return;
    }
    if(Pos==1)
    {
        this->insertFirst(No);
    }
    if(Pos==iCount+1)
    {
       this->insertLast(No);
    }
    else
    {
         DoublyLLLnode <T> * newn=NULL;
       newn = new DoublyLLLnode <T>(No);
        temp=first;
        for(iCnt=1;iCnt<Pos-1;iCnt++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        newn->prev=temp;
        temp->next=newn;
        temp->next->prev=newn;
        

        this->iCount++;
    }

}

template <class T>
void DoublyLLL<T>::deleteFirst()
{
    
    
    if(this->first==NULL)
    {
        cout<<"Linkedlist is Empty";      
        return;
    }
    else if(this->first->next==NULL)
    {
        delete this->first;                      
        first=NULL;
    }
    else
    {
       
       this->first=this->first->next;
       delete this->first->prev;
       this->first->prev=NULL;                                         
    }
     this->iCount--;
}

template <class T>
void DoublyLLL<T>:: deleteLast()
{
     DoublyLLLnode <T> * temp=NULL;
    if(this->first==NULL)
    {
        cout<<"Linkedlist is Empty";      
        return;
    }
    else if(this->first->next==NULL)
    {
        delete this->first;                      
        first=NULL;
    }
    else
    {
         temp=first;
         while(temp->next->next!=NULL)
         {
            temp=temp->next;
         }
         delete temp->next;
         temp->next=NULL;                                         
    }
     this->iCount--;

}

template <class T>
void DoublyLLL<T>:: deleteAtPos(int Pos)
{
    DoublyLLLnode <T> * temp=NULL;
    int iCnt=0;
    if(Pos<1||Pos>this->iCount)
    {
        cout<<"Invalid Position"<<endl;                  
        return;
    }
    if(Pos==1)
    {
        this->deleteFirst();
    }
    if(Pos==iCount)
    {
       this->deleteLast();
    }
    else
    {
          temp=first;
        for(iCnt=1;iCnt<Pos-1;iCnt++)
        {
            temp=temp->next;
        }
        temp->next=temp->next->next;
        delete temp->next->prev;
        temp->next->prev=temp;
         this->iCount--;

    }

}

template <class T>
void DoublyLLL<T>:: display()
{
    DoublyLLLnode <T> * temp=NULL;
    temp=this->first;
    cout<<"\nNULL<=>";
    while(temp!=NULL)
    {
        cout<<"<-|"<<temp->data<<"|->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;

}

template <class T>
int DoublyLLL<T>:: count()
{
    return this->iCount;
}
//////////////////////////////////////////////////////
// Stack using Generic Approach
///////////////////////////////////////////////////////
#pragma pack(1)
template<class T>
class StackNode
{
public:
T data;
StackNode <T> * next;
StackNode(T No)
{
   this->data=No;
   this->next=NULL;
}

};
template<class T>
class Stack
{
private :
StackNode <T> * first;
int iCount;

public :

Stack();
void Push(T);
T Pop();
T Peep();
void Display();
int Count();

};

template<class T>
Stack<T>::Stack()
{
cout<<"Stack Gets Created Sucessfully"<<endl;
this->first=NULL;
this->iCount=0;

}

template<class T>
void Stack<T>::Push(T No)
{
StackNode <T> * newn =NULL;
newn = new StackNode<T>(No);
newn->next=this->first;
this->first=newn;
iCount++;


}

template<class T>
T Stack<T>:: Pop()
{
T Value=0;
StackNode <T> * temp=NULL;
if(this->first==NULL)
{
cout<<"Stack is Empty"<<endl;
return -1;
}
Value=this->first->data;
temp=this->first;
this->first=this->first->next;
delete temp;
this->iCount--;
return Value;

}

template<class T>
T Stack<T>:: Peep()
{
T Value=0;

if(this->first==NULL)
{
cout<<"Stack is Empty"<<endl;
return -1;
}
Value=this->first->data;
return Value;
}

template<class T>
void  Stack<T>:: Display()
{
StackNode <T> * temp=NULL;
temp=this->first;
if(this->first==NULL)
{
cout<<"Stack is Empty"<<endl;
return;
}
while(temp!=NULL)
{
cout<<"|\t"<<temp->data<<"\t|"<<endl;
cout<<"-----------------"<<endl;
temp=temp->next;
}

}

template<class T>
int Stack<T>::Count()
{
return this->iCount;

}
//////////////////////////////////////////////////////
// Queue using Generic Approach
///////////////////////////////////////////////////////
#pragma pack(1)
template<class T>
class QueueNode
{
public:
T data;
   QueueNode <T> * next;
   QueueNode(T No)
{
   this->data=No;
   this->next=NULL;
}

};

template<class T>
class Queue
{
private :
QueueNode <T>* first;
QueueNode <T>* last;
int iCount;

public :

Queue();

void Enqueue(T);
T  Dequeue();
void Display();
int Count();

};


template<class T>
Queue<T>::Queue()
{
cout<<"Queue Gets Created Sucessfully"<<endl;
this->first=NULL;
this->last=NULL;
this->iCount=0;

}

template<class T>
void Queue<T>::Enqueue(T No)
{
QueueNode<T> * newn =NULL;

newn = new  QueueNode<T>(No);

if((this->first==NULL)&&(this->last==NULL))
{
this->first=newn;
this->last=newn;

}
else
{
this->last->next=newn;
this->last=newn;

}
this->iCount++;
}

template<class T>
T Queue<T>:: Dequeue()
{
T Value=0;
QueueNode <T> * temp=NULL;
if((this->first==NULL)&&(this->last==NULL))
{
cout<<"Queue is Empty"<<endl;
return -1;
}
Value=this->first->data;
temp=this->first;
this->first=this->first->next;
delete temp;
this->iCount--;
return Value;

}

template<class T>
void  Queue<T>:: Display()
{
QueueNode <T>* temp=NULL;
temp=this->first;
if((this->first==NULL)&&(this->last==NULL))
{
cout<<"Queue is Empty"<<endl;
return;
}
while(temp!=NULL)
{
cout<<"-| "<<temp->data<<" |-";
temp=temp->next;
}
cout<<"\n";

}

template<class T>
int Queue<T>::Count()
{
return this->iCount;

}
//////////////////////////////////////////////////////
// SinglyCircularLinkedList using Generic Appraoch
///////////////////////////////////////////////////////
#pragma pack(1)
template <class T>
class SinglyCLL
{
    public:

     T data;
     SinglyCLL<T>* next;
     SinglyCLL(T no)
     {
        this->data=no;
        this->next=NULL;
     }
};

template <class T>
class SinglyCircular
{
    private:

    SinglyCLL <T> * first;
    SinglyCLL <T> * last;
    int iCount;

   
    public:

    SinglyCircular();
    void insertFirst(T );
    void insertLast(T);
    void deleteFirst();
    void deleteLast();
    void display();
    int count();
    void insertAtPos(T,int );
    void deleteAtPos(int );
   
};
 
template <class T>
SinglyCircular<T>::SinglyCircular()
{
this->first=NULL;
this->last=NULL;
this->iCount=0;
}

template <class T>
void SinglyCircular<T>::insertFirst(T No)
{
    SinglyCLL <T> * newn =NULL;
newn = new  SinglyCLL<T>(No);

if((this->first==NULL)&&(this->last==NULL))
{
this->first=newn;
this->last=newn;

}
else
{
newn->next=this->first;
this->first=newn;


}
this->last->next=this->first;
this->iCount++;

}

template <class T>
void SinglyCircular<T>::insertLast(T No)
{
    SinglyCLL<T> * newn=NULL;
    SinglyCLL <T> * temp=NULL;
newn = new  SinglyCLL<T>(No);

if((this->first==NULL)&&(this->last==NULL))
{
this->first=newn;
this->last=newn;

}
else
{
this->last->next=newn;
this->last=newn;
}
this->last->next=this->first;
this->iCount++;


}


template <class T>
void SinglyCircular<T>::deleteFirst()
{
    SinglyCLL <T> * temp=NULL;
if(this->first==NULL&&this->last==NULL)
{
    cout<<"LinkedList is Empty";
    return;
}
else if(this->first==this->last)
{
    delete this->first;
    this->first=NULL;
        this->last=NULL;
    
}
else
{
    
    temp= this->first;
        this->first= this->first->next;
    delete temp;
    

}
    this->last->next= this->first;
    this->iCount--;

}

template <class T>
void SinglyCircular<T>:: deleteLast()
{
    SinglyCLL<T> * temp=NULL;
int iCnt=0;

    if( this->first==NULL&& this->last==NULL)
{
    cout<<"LinkedList is Empty";
    return;
}
else if( this->first== this->last)
{
    delete  this->first;
        this->first=NULL;
        this->last=NULL;
    
}
else
{
    temp= this->first;
    do
    {
        temp=temp->next;
    } while (temp->next!= this->last);
    delete temp->next;
    temp->next= this->first;
        this->last=temp;

}

    this->iCount--;


}

template <class T>
void SinglyCircular<T>:: display()
{
SinglyCLL <T> * temp=NULL;
temp= this->first;
int iCnt=0;
for(iCnt=1;iCnt<=iCount;iCnt++)
{
    cout<<"|"<<temp->data<<"|->";
    temp=temp->next;
}
cout<<"(end)----------->|"<< this->first->data<<"|(start)";

}

template <class T>
int SinglyCircular<T>:: count()
{
return this->iCount;
}

template <class T>
void SinglyCircular<T>:: insertAtPos(T No,int Pos)
{

SinglyCLL <T> * temp=NULL;
SinglyCLL <T> * newn =NULL;

int iCnt=0;

if(Pos<1||Pos> this->iCount+1) //filter
{
    cout<<"Invalid Position\n";
    return;
}
else if(Pos==1)
{
    this->insertFirst(No);
}
else if(Pos== this->iCount+1)
{
    this-> insertLast(No);
}
else
{
newn = new  SinglyCLL(No);

    temp= this->first;
    for(iCnt=1;iCnt<Pos-1;iCnt++)
    {
    temp=temp->next;
    }
    newn->next=temp->next;
    temp->next=newn;
    
    this->iCount++;
}

}

template <class T>
void SinglyCircular <T>::deleteAtPos(int Pos)
{

SinglyCLL <T> * target=NULL;
SinglyCLL <T> * temp =NULL;

int iCnt=0;

if(Pos<1||Pos> this->iCount) //filter
{
    cout<<"Invalid Position\n";
    return;
}
else if(Pos==1)
{
this-> deleteFirst();
}
else if(Pos== this->iCount)
{
    this->deleteLast();
}
else
{
    temp= this->first;
    for(iCnt=1;iCnt<Pos-1;iCnt++)
    {
    temp=temp->next;
    }
    target=temp->next;
    temp->next=target->next;
    delete target;
    this-> iCount--;
}

}
////////////////////////////////////////////////
///DoublyCircularLinkedList using Generic Approach
/////////////////////////////////////////////////
#pragma pack(1)
template <class T>
class DoublyCLL
{
public:
T data;
DoublyCLL<T>* next;
DoublyCLL<T>* prev;

DoublyCLL(T no);
};

template <class T>
class DoublyCircular
{
private:
DoublyCLL<T>* first;
DoublyCLL<T>* last;
int iCount;

public:
DoublyCircular();

void insertFirst(T No);
void insertLast(T No);
void deleteFirst();
void deleteLast();
void display();
int count();
void insertAtPos(T No, int Pos);
void deleteAtPos(int Pos);
};

template <class T>
DoublyCLL<T>::DoublyCLL(T no)
{
this->data = no;
this->next = NULL;
this->prev = NULL;
}

template <class T>
DoublyCircular<T>::DoublyCircular()
{
this->first = NULL;
this->last = NULL;
this->iCount = 0;
}

template <class T>
void DoublyCircular<T>::insertFirst(T No)
{
DoublyCLL<T>* newn = new DoublyCLL<T>(No);

if(this->first == NULL && this->last == NULL)
{
this->first = this->last = newn;
this->last->next = this->first;
this->first->prev = this->last;
}
else
{
newn->next = this->first;
newn->prev = this->last;
this->first->prev = newn;
this->last->next = newn;
this->first = newn;
}
this->iCount++;
}

template <class T>
void DoublyCircular<T>::insertLast(T No)
{
DoublyCLL<T>* newn = new DoublyCLL<T>(No);

if(this->first == NULL)
{
this->first = this->last = newn;
this->first->next = this->first;
this-> first->prev = this->first;
}
else
{
newn->prev = this->last;
newn->next = this->first;
this->last->next = newn;
this->first->prev = newn;
this->last = newn;
}
this->iCount++;
}

template <class T>
void DoublyCircular<T>::deleteFirst()
{
if(this->first == NULL)
return;

if(this->first == this->last)
{
delete this-> first;
this-> first = this->last = NULL;
}
else
{
DoublyCLL<T>* temp = this->first;
this->first = this->first->next;
this->first->prev = this->last;
this-> last->next = this->first;
delete temp;
}
this->iCount--;
}

template <class T>
void DoublyCircular<T>::deleteLast()
{
if(this->first == NULL)
return;

if(this->first == this->last)
{
delete this->first;
this->first = this->last = NULL;
}
else
{
DoublyCLL<T>* temp = this->last;
this->last = this->last->prev;
this->last->next = this->first;
this->first->prev = this->last;
delete temp;
}
this->iCount--;
}

template <class T>
void DoublyCircular<T>::display()
{
if(this->first == NULL)
return;

DoublyCLL<T>* temp = this->first;
do
{
cout << "|" << temp->data << "|<->";
temp = temp->next;
} while(temp !=this-> first);

cout << "(end)------>(start)\n";
}

template <class T>
int DoublyCircular<T>::count()
{
return this->iCount;
}

template <class T>
void DoublyCircular<T>::insertAtPos(T No, int Pos)
{
if(Pos < 1 || Pos > this->iCount + 1)
{
cout << "Invalid Position\n";
return;
}

if(Pos == 1)
this->insertFirst(No);
else if(Pos == this->iCount + 1)
this->insertLast(No);
else
{
DoublyCLL<T>* newn = new DoublyCLL<T>(No);
DoublyCLL<T>* temp = this->first;

for(int i = 1; i < Pos - 1; i++)
    temp = temp->next;

newn->next = temp->next;
newn->prev = temp;
temp->next->prev = newn;
temp->next = newn;

this->iCount++;
}
}

template <class T>
void DoublyCircular<T>::deleteAtPos(int Pos)
{
if(Pos < 1 || Pos > this->iCount)
{
cout << "Invalid Position\n";
return;
}

if(Pos == 1)
this->deleteFirst();
else if(Pos == this->iCount)
this->deleteLast();
else
{
DoublyCLL<T>* temp = this->first;

for(int i = 1; i < Pos; i++)
    temp = temp->next;

temp->prev->next = temp->next;
temp->next->prev = temp->prev;
delete temp;
this->iCount--;
}
}




//////////////////////////////////////////End Of Library////////////////////////////////////////////////////////
int main()
{

    int iRet=0;
    SinglyLLL <int>  * obj = new SinglyLLL <int> ();
    obj->insertFirst(51);
    obj->insertFirst(21);
    obj->insertFirst(11);
   

    
     obj->insertLast(101);
     obj->insertLast(111);
      obj->insertLast(121);
      iRet=obj->Count();
    cout<<"No of Nodes Are:"<<iRet<<endl;
    obj->display();
obj->deleteFirst();
iRet=obj->Count();
    cout<<"No of Nodes Are:"<<iRet<<endl;
    obj->display();
       obj->deleteLast();    
iRet=obj->Count();
    cout<<"No of Nodes Are:"<<iRet<<endl;
    obj->display();
    
    obj->insertAtPos(105,4);
    iRet=obj->Count();
    cout<<"No of Nodes Are:"<<iRet<<endl;
    obj->display();
    obj->deleteAtPos(4);
    iRet=obj->Count();
    cout<<"No of Nodes Are:"<<iRet<<endl;
    obj->display();

delete obj;
cout<<endl;

//--------------------------------------------------------------------------------------------
DoublyLLL <char> * dobj = new DoublyLLL<char>();
dobj->insertFirst('A');
dobj->insertFirst('B');
 dobj->insertFirst('C');
 dobj->insertLast('X');
dobj->insertLast('Y');
 dobj->insertLast('Z');
 dobj->deleteFirst();
 dobj->deleteLast();
 dobj->display();
cout<<"No of Nodes Are:"<<dobj->count()<<endl;
dobj->deleteAtPos(4);
dobj->insertAtPos('$',4);
dobj->display();
cout<<"No of Nodes Are:"<<dobj->count()<<endl;



delete dobj;
//----------------------------------------------------------------------------------------------------
 Stack <char> * sobj = new Stack<char>();
    sobj->Push('A');
    sobj->Push('B');
    sobj->Push('C');
    sobj->Push('D');
    sobj->Display();
    cout<<"No Of Elements in Stack:"<<sobj->Count()<<endl;
    cout<<"return value of peep is:"<<sobj->Peep()<<endl;
     sobj->Display();
    cout<<"No Of Elements in Stack:"<<sobj->Count()<<endl;
    cout<<"Poped Element Is:"<<sobj->Pop()<<endl;
    sobj->Display();
    cout<<"No Of Elements in Stack:"<<sobj->Count()<<endl;
    cout<<"Poped Element Is:"<<sobj->Pop()<<endl;
    sobj->Display();
    cout<<"No Of Elements in Stack:"<<sobj->Count()<<endl;
    sobj->Push('E');
     sobj->Display();
    cout<<"No Of Elements in Stack:"<<sobj->Count()<<endl;
    


    delete sobj;
  //---------------------------------------------------------------------------------------------
    Stack <int> * isobj = new Stack<int>();
    isobj->Push(11);
    isobj->Push(21);
    isobj->Push(51);
    isobj->Push(101);
    isobj->Display();
    cout<<"No Of Elements in Stack:"<<isobj->Count()<<endl;
    cout<<"return value of peep is:"<<isobj->Peep()<<endl;
     isobj->Display();
    cout<<"No Of Elements in Stack:"<<isobj->Count()<<endl;
    cout<<"Poped Element Is:"<<isobj->Pop()<<endl;
    isobj->Display();
    cout<<"No Of Elements in Stack:"<<isobj->Count()<<endl;
    cout<<"Poped Element Is:"<<isobj->Pop()<<endl;
    isobj->Display();
    cout<<"No Of Elements in Stack:"<<isobj->Count()<<endl;
    isobj->Push(121);
     isobj->Display();
     delete isobj;
    cout<<"No Of Elements in Stack:"<<isobj->Count()<<endl;
    //---------------------------------------------------------------------------------------------
    Queue <double> * qobj = new Queue<double>();
    qobj->Enqueue(11.56789);
    qobj->Enqueue(21.56789);
    qobj->Enqueue(51.56789);
    qobj->Enqueue(101.56789);
    qobj->Display();
   cout<<"Removed Element Is:"<<qobj->Dequeue()<<endl;
    qobj->Display();
    cout<<"No Of Elements in Queue:"<<qobj->Count()<<endl;
    cout<<"Removed Element Is:"<<qobj->Dequeue()<<endl;
    qobj->Display();
    cout<<"No Of Elements in Queue:"<<qobj->Count()<<endl;
    qobj->Enqueue(121.56789);
     qobj->Display();
    cout<<"No Of Elements in Queue:"<<qobj->Count()<<endl;
    


    delete qobj;
    //------------------------------------------------------------------------------------------------
     Queue <int> * iqobj = new Queue<int>();
    iqobj->Enqueue(11);
    iqobj->Enqueue(21);
    iqobj->Enqueue(51);
    iqobj->Enqueue(101);
    iqobj->Display();
   cout<<"Removed Element Is:"<<iqobj->Dequeue()<<endl;
    iqobj->Display();
    cout<<"No Of Elements in Queue:"<<iqobj->Count()<<endl;
    cout<<"Removed Element Is:"<<iqobj->Dequeue()<<endl;
    iqobj->Display();
    cout<<"No Of Elements in Queue:"<<iqobj->Count()<<endl;
    iqobj->Enqueue(121);
     iqobj->Display();
    cout<<"No Of Elements in Queue:"<<iqobj->Count()<<endl;
    


    delete qobj;
    //-----------------------------------------------------------------------------------------------
    
    SinglyCircular<float> * Sobj = new SinglyCircular<float>();
    Sobj->insertFirst(1.0f);
    Sobj->insertFirst(11.0f);
    Sobj->insertFirst(21.0f);
    Sobj->insertFirst(51.0f);
    Sobj->insertFirst(101.0f);
   Sobj->deleteFirst();
    Sobj->deleteLast();
    Sobj->insertAtPos(101.0f,2);
    Sobj->deleteAtPos(3);
    
    cout<<"No of Nodes:"<<Sobj->count()<<endl;
    Sobj->display();
    
    delete  Sobj;

    //------------------------------------------------------------------------------------------------------
    DoublyCircular<int> * iobj= new DoublyCircular<int>();

iobj->insertFirst(1);
iobj->insertFirst(11);
iobj->insertFirst(21);
iobj->insertLast(51);
iobj->insertLast(101);

iobj->display();

iobj->insertAtPos(99, 3);
iobj->display();

iobj->deleteAtPos(3);
iobj->display();

cout << "Count: " << iobj->count() << endl;
delete iobj;

DoublyCircular<char> * cobj = new DoublyCircular<char>();
cobj->insertFirst('A');
cobj->insertLast('B');
cobj->insertLast('C');
cobj->display();
 delete cobj;   
 
    return 0;
}
/////////////////////////////////End/////////////////////////////////////////////////////////////