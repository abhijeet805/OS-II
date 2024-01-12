#include<stdio.h>
#include<stdlib.h>

int allocation[20][20],max[20][20],available[20],need[20][20],safe[20],s=0;
int finish[10],work[10],cnt=0,flag=0,temp=0;
int p,r,i,j,ind,req[10],ch;

void check(){

    temp=0;
    s=0;
    for(i=0;i<p;i++)//Calculate need=max-allocation
       for(j=0;j<r;j++)
          need[i][j]=max[i][j]-allocation[i][j];
          
    printf("\n Need Table is:\n");
    
     for(i=0;i<p;i++){
       for(j=0;j<r;j++) 
         printf("%d\t",need[i][j]);
         
       printf("\n");
    
    }
    
    
    for(i=0;i<p;i++)
     finish[i]=0; //false
     
    for(i=0;i<r;i++)
       work[i]=available[i];
       
     while(temp<2){
         for(i=0;i<p;i++){
             for(j=0;j<r;j++){
                if(finish[i]==0 && need[i][j]<=work[j])
                   flag=1;
                  else{
                    flag=0;break;
                  }
               
             }
             
             if(flag==1){
                 for(j=0;j<r;j++)
                    work[j]=work[j]+allocation[i][j];
                    finish[i]=1;
                    safe[s++]=i;
             }
             temp++;
         }
         
         flag=0;
         for(i=0;i<p;i++){
             if(finish[i]==0){
                flag=1;
                break;
             }
         }
         
         if(flag==1)
           printf("\nSystem is in Deadlock state");
         else 
         {
            printf("\nSystem is in Safe State");
            printf("\nSafe Sequence is:");
            for(i=0;i<p;i++){
               printf("P%d\t",safe[i]);
            }
            
         }
     }   
}

int main(){
  system("clear");
  printf("\n~~~~~~~~~~Bankers Algorithm~~~~~~~~~~~~~~");
  printf("Enter the no of resources and processes:");
  scanf("%d%d",&r,&p);
 
       printf("Enter Allocation Table"); 
       for(i=0;i<p;i++) //Accept the Allocation Table
          for(j=0;j<r;j++)
             scanf("%d",&allocation[i][j]);
         
       printf("Enter Max Table"); 
       for(i=0;i<p;i++) //Accept the Max Table
          for(j=0;j<r;j++)
             scanf("%d",&max[i][j]);
         
         printf("Enter Vector Avilable:");
         for(i=0;i<r;i++)
           scanf("%d",&available[i]);
           
         check();// safety algo
         printf("\nDo UWant to add request:(0/1)");//resource request algorithm
         scanf("%d",&ch);
         
         if(ch==0)
            exit(0);
            
           printf("\nEnter the Process no");
             scanf("%d",&ind);
           
           printf("\nEnter the request:");
             for(i=0;i<r;i++)
               scanf("%d",&req[i]);
           
           flag=0;
           for(i=0;i<r;i++)
             if(req[i]<=need[ind][i])
                flag=1;
             else
                flag=0;
                
           if(flag==0){
             printf("\nRequest can not be satisfied...");
             exit(1);
           }
           
           for(i=0;i<r;i++)
            if(req[i]<=available[i])
               flag=1;
             else 
               flag=0;
           
           if(flag==0){
            printf("\nRequest can not be satisfied...");
            exit(1);
           }
           
           for(i=0;i<r;i++){
              allocation[ind][i]=allocation[ind][i]+req[i];
              available[i]=available[i]-req[i];
           }
          check();//safety algo
          return 0;
       
}  
