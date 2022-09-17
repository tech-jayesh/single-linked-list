#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *next;
}*head,*tail,*newnode,*del,*usernode,*temp;

void createnode(){
  newnode=(struct node *)malloc(sizeof(struct node));
  newnode->next=NULL;
  printf("enter the data:- ");
  scanf("%d",&newnode->data);
}

void insertnode(){
  usernode=(struct node*)malloc(sizeof(struct node));
  printf("enter new element you want to insert:- ");
  usernode->next=NULL;
  scanf("%d",&usernode->data);
}

void traverse(){
  temp=head;
  while(temp!=NULL){
    printf("%d\t",temp->data);
    temp=temp->next;
  }
}

void insertbig(){
  insertnode();
  temp=head;
  head=usernode;
  usernode->next=temp;
  traverse();
}

void insertend(){
  insertnode();
  tail->next=usernode;
  usernode->next=NULL;
  traverse();
}

void randominsert(){
  insertnode();
  int pos;
  printf("enter the position where you want to insert element:- ");
  scanf("%d",&pos);
  int count=0;
  temp=head;
  while(temp!=NULL){             
    count++;
    if(pos==1){
      usernode->next=temp;
      head=usernode;
      break;
    }
    else if(count==pos-1){
      usernode->next=temp->next;
      temp->next=usernode;
      break;
    }
    temp=temp->next;
  }
  if(count<pos-1){
  printf("invalid position");
    return;  //break function is only used in switch case and loops. if you want to terminate the programme use return.
  }
  traverse();
}

void delbig(){
  temp=head;
  head=temp->next;
  free(temp);
  traverse();
}

void dellast(){
  temp=head;
  while(temp->next!=NULL){
    del=temp;
    temp=temp->next;
  }
  del->next=NULL;
  free(tail);
  traverse();
}

void randomdel(){
  int pos;
  printf("enter the position which element you want to del:- ");
  scanf("%d",&pos);
  temp=head;
  int count=0;
  while(temp!=NULL){
    count++;
    del=temp;
    temp=temp->next;
    if(pos==1){
      head=temp;
      free(del);
      break;
    }
    else if(count==pos-1 && temp->next!=NULL){
      del->next=temp->next;
      free(temp);
      break;
    }
    if (count==pos-1 && temp->next==NULL){
      del->next=NULL;
      free(temp);
      break;
    }
  }
  // if (count<pos-1){
  //   printf("invalid position");
  //   return;
  // }
  traverse();
}

void reverse(){
  struct node *cur,*pre;
  temp=cur=head;
  pre=NULL;
  while(cur!=NULL){ // here we can use temp!=NULL;
    temp=cur->next;
    cur->next=pre;
    pre=cur;
    cur=temp;
  }
  head=pre;
  while(pre!=NULL){
    printf("%d\t",pre->data);
    pre=pre->next;
  }
}

void search(){
  int num,flag=0,count=0;
  printf("enter the number you want to search:- ");
  scanf("%d",&num);
  temp=head;
  while(temp!=NULL){
    count++;
    if(num==temp->data){
      printf("given number is persent in %d position\n",count);
      flag=1;
    }
    temp=temp->next;
  }
  if(flag==0){
    printf("given number is not persent in linked list");
  }
}

void update(){
  int pos,num,newnum;
  int choice,count=0;
  temp=head;
  printf("press 1 for update list via pos\npress 2 for update list via number:- ");
  scanf("%d",&choice);
  switch(choice){
    case 1:{
      printf("enter the position which elememt you want to update:- ");
      scanf("%d",&pos);
      printf("enter new number:- ");
      scanf("%d",&newnum);
      while(temp!=NULL){
        count++;
        if(pos==count){
          temp->data=newnum;
        }
        temp=temp->next;
      }
      if(count<pos){
        printf("invalid position\n");
      }
      traverse();
      break;
    }
    case 2:{
      int flag=0;
      printf("enter a number you want to update:- ");
      scanf("%d",&num);
      printf("enter new number:- ");
      scanf("%d",&newnum);
      while(temp!=NULL){
        if(temp->data==num){
          temp->data=newnum;
          flag=1;
        }
        temp=temp->next;
      }
      if(flag==0){
        printf("given number is not persent in linked list\n");
      }
      traverse();
      break;
    }
    default :{
      printf("invalid selection");
    }
  }
}
  
int main(){
  int choice=1;
  head=NULL;
  while(choice==1){
    createnode();
    if(head==NULL){
      head=temp=newnode;
    }
    else{
      temp->next=newnode;
      temp=newnode;
    }
    printf("if you want to enter new data press 1 otherwise press any number:- ");
    scanf("%d",&choice);
  }
  tail=newnode;
  int mainchoice;
  printf("1 for traverse \n2 for insert in biginning \n3 for insert in last \n4 for random insert \n5 for delete in biginning \n6 for del in last \n7 for random delete \n8 for serach \n9 for update \n10 for reverse \n11 for exit:- ");
  scanf("%d",&mainchoice);
  switch(mainchoice){
    case 1:
    traverse();
    break;
    case 2:
    insertbig();
    break;
    case 3:
    insertend();
    break;
    case 4:
    randominsert();
    break;
    case 5:
    delbig();
    break;
    case 6:
    dellast();
    break;
    case 7:
    randomdel();
    break;
    case 8:
    search();
    break;
    case 9:
    update();
    break;
    case 10:
    reverse();
    break;
    case 11:
    exit(0);  // in exit funtion we pass 0 argument for terminate the programme
    break;
    default :
    printf("invalid selection");
  }
  return 0;
}