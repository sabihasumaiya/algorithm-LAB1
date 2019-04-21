#include<stdio.h>
#include<conio.h>
int a[20] [20], reach[20],n;
void dfs (int v)
 {
     int i;
     reach [v]= 1;
     for (i=1; i<=n; i++)
        if (a[v][i] && !reach [i])
     {
         printf("\n %d->%d",v,i);
         dfs (i);
     }
 }
 void main()
 {
     int i, j, count=0;
     printf("\n Enter number of vrtices:");
     scannf("%d", &n);
     for(i=1;i<=n; i++){
        reach [i]=0;
     for(j=1;j<=n; j++)
        a[i][j]=0;
     }

 printf("\nEnter graph data in matrix form:\n");
 for(i=1;i<=n; i++)
     for(j=1;j<=n; j++)
     scanf("%d", &a[i][j]);
 printf("\n Nodes DFS path is :");
 dfs(1);
 printf("\n");
 for(i=1;i<=n; i++)
    {
    if(reach[i])
    count++;
   }
 if (count==0)
    printf("\n Graph is not connected");
 }



