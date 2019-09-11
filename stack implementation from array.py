from sys import maxsize

def createStack():
     Stack=[]
     return Stack
def isEmpty(Stack):
   return len(Stack) == 0
def push(Stack,item):
     Stack.append(item)
     print(item +"pushed to stack")

def pop(Stack):
     if (isEmpty(Stack)):
          return str(-maxsize -1)
     return Stack.pop()
def peek(Stack):
    if(isEmpty(Stack)):
          return str(-maxsize -1)
    return Stack[ len(Stack) -1]
Stack=createStack()
push(Stack,str(10))
push(Stack,str(20))
push(Stack,str(30))
print(pop(Stack) +"popped from stack")
     
