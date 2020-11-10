class node:
    def __init__(self,data):
        self.data=data
        self.next=None

class SingleLinkedList:
    def __init__(self):
        self.start=None
        
    def viewList(self):
        if self.start==None:
            print("list is empty")
        else:
            temp=self.start
            while temp!=None:
                print(temp.data,end=" ")
                temp=temp.next
                
    def deleteLast(self):
        if self.start==None:
            print("list is empty")
        else:
            temp=self.start
            while temp.next.next!=None:
                temp=temp.next
            temp.next=None
        
    def insertLast(self,value):
        newNode=node(value)
        if(self.start==None):
            self.start=newNode
        else:
            temp=self.start
            while temp.next!=None:
                temp=temp.next
            temp.next=newNode
            
mylist=SingleLinkedList()
mylist.insertLast(10)
mylist.insertLast(20)
mylist.insertLast(30)
mylist.insertLast(40)
mylist.insertLast(50)
mylist.viewList()
mylist.deleteLast()
print('\n')
mylist.viewList()