#include<stdio.h>
#include<stdlib.h>

struct heap{
int c,s,*element;
};
typedef struct heap *pqueue;

pqueue initialize(int max){
pqueue h;
h=(pqueue)malloc(sizeof(struct heap));
h->element=(int*)malloc((max+1)*sizeof(int));
h->c=max;
h->s=0;
h->element[0]=0;
return h;
}

void insert(int x,pqueue h){
int i;
for(i=++h->s;h->element[i/2]>x;i=i/2)
h->element[i]=h->element[i/2];
h->element[i]=x;
}

int deletemin(pqueue h){
int i,child,min,last;
min=h->element[1];
last=h->element[h->s--];

for(i=1;i*2<=h->s;i=child){
child=i*2;
if(child!=h->s && h->element[child+1]<h->element[child])
child++;
if(last>h->element[child])
h->element[i]=h->element[child];
else
break;
}
h->element[i]=last;
return min;
}

void display(pqueue h){
int i;
for(i=1;i<=h->s;i++)
printf("%d ",h->element[i]);
printf("\n");
}

int main(){
int n,ch,x;
pqueue h;

printf("Enter the size: ");
scanf("%d",&n);
h=initialize(n);

do{
printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
printf("Enter choice: ");
scanf("%d",&ch);

switch(ch){
case 1:
printf("Enter element: ");
scanf("%d",&x);
insert(x,h);
break;

case 2:
if(h->s==0)
printf("Heap is empty\n");
else
printf("Deleted element: %d\n",deletemin(h));
break;

case 3:
display(h);
break;

case 4:
break;

default:
printf("Invalid choice\n");
}
}while(ch!=4);

return 0;
}
