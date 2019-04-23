#include <stdio.h>

 void mergesort(int score[],int Time[],int l,int m,int r)
    {
        int i=0;
        int j=0;
        int k=0;
        int n1=m-l+1;
        int n2=r-m;
        int Lscore[n1],Ltime[n1],Rscore[n2],Rtime[n2];

        for(i=0;i<n1;i++)
        {
            Lscore[i]=score[l+i];
            Ltime[i]=Time[l+i];
        }
        for(i=0;i<n2;i++)
        {
        	Rscore[i]=score[i+m+1];
        	Rtime[i]=Time[i+m+1];
        }
        i=0;
        j=0;
        k=l;
        while(i<n1&&j<n2)
        {
            if(Lscore[i]>Rscore[j])
            {
                score[k]=Lscore[i];
                Time[k]=Ltime[i];
                i++;
            }

            else
            {
            	 score[k]=Rscore[j];
                 Time[k]=Rtime[j];
                 j++;
            }
            k++;
        }
        while(i<n1)
        {
        	score[k]=Lscore[i];
            Time[k]=Ltime[i];
            k++;
            i++;
        }
        while(j<n2)
        {
        	score[k]=Rscore[j];
            Time[k]=Rtime[j];
            k++;
            j++;
        }
    }
   void merge(int score[],int Time[],int l,int r)
    {
       if(l<r)
        {
            int m=l+(r-l)/2;
            merge(score,Time,l,m);
            merge(score,Time,m+1,r);

            mergesort(score,Time,l,m,r);
        }
    }
int main(){
	int n,Q;
	printf("ENTER NUMBER QUESTION :");
	scanf("%d", &n);
	printf("ENTER NUMBER OF QUERIES :");
	scanf("%d", &Q);
	int Time[n],score[n];
	int i=0;
	printf("ENTER TIME ALLOCATED FOR EACH QUESTION \n");
	for(i=0;i<n;i++)
	{
	   scanf("%d",&Time[i]);
	}
	printf("ENTER SCORE ALLOCATED FOR EACH QUESTION \n");
	for(i=0;i<n;i++)
	{
	   scanf("%d",&score[i]);
	}
	merge(score,Time,0,n-1);
	printf("\n-------------\n");

	while(Q>0)
	{
	    int num;
        int q;
	    int sum=0;

      printf("\nHOW MANY QUESTION DO YOU WANT TO ANSWER : ");
	    scanf("%d",&num);
	    for(i=0;i<num;i++)
	    {
	        sum=sum+Time[i];
	    }

	    printf("\nyou need %d minutes\n ",sum);

	    Q--;
	}

}
