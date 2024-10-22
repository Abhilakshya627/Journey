#include<stdio.h>
#include<stdlib.h>

void enq(int *,int *,int *,int);
void deq(int *,int *,int *,int);
void display(int *,int *,int *,int);
void peek(int *,int *);

void main(){
    int n,ch=0,*a,i,front=-1,rear=-1,*f=&front,*r=&rear;
    printf("Enter size of queue : ");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    do{
        printf("1. Enqueue\t2. Dequeue\t3. Display\t4. Peek\t5. Exit\nEnter Choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            enq(a,f,r,n);
            break;
            case 2:
            deq(a,f,r,n);
            break;
            case 3:
            display(a,f,r,n);
            break;
            case 4:
            peek(a,f);
            break;
            case 5:
            printf("Exiting...\n");
            break;
            default:
            printf("Invalid choice...\n");
        }
    }while(ch!=5);
}

void enq(int *a,int *f,int *r,int n){
    if((*f==0 && *r==n-1) || (*f>0 && *r==*(f)-1))
    printf("Queue is full...\n");
    else{
        *r=(*(r)+1)%n;
        printf("Enter element to be inserted : ");
        scanf("%d",&a[*r]);
        if(*f==-1)
        *f=0;
    }
}

void deq(int *a,int *f,int *r,int n){
    if(*f==-1)
    printf("Queue is empty...\n");
    else{
        printf("Deleted element : %d\n",a[*f]);
        if(*f==*r)
        *f=-1;
        else
        *f=(*(f)+1)%n;
    }
}

void display(int *a,int *f,int *r,int n){
    if(*f==-1)
    printf("Queue is empty...\n");
    else{
        int i=*f;
        printf("Queue is : ");
        while(i!=*r){
            printf("%d ",a[i]);
            i=(i+1)%n;
        }
        printf("%d\n",a[*r]);
    }
}

void peek(int *a,int *f){
    if(*f==-1)
    printf("Queue is empty...\n");
    else
    printf("Front element : %d\n",a[*f]);
}