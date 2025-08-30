#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define max 5000
int undg[max][max];
int main()
{
    int sum=0,edge=0,degA=0,degB=0,n;
    double total_time;
    clock_t start,end;
    start = clock();
    printf("Enter the number vertices: ");
    scanf("%d",&n);
    srand(2);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int val = rand()%2;
            undg[i][j]=val;
            undg[j][i]=val;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(undg[i][j]==1){
                degA++;
            }
            if(undg[i][j]==1 && i==j){
                degB++;
            }
            if(undg[i][j]==1 && i>=j){
                edge++;
            }
        }
    }
    sum = degA+degB;
    printf("Number of Vertices: %d\n",sum);
    printf("Number of Edge: %d\n",edge);
    printf("The total number of edges is(using handshaking theorem):(sum of degree/2=(%d/2)=%d\n",sum,sum/2);
    end =clock();
    total_time = ((double)(end-start)/CLOCKS_PER_SEC)*1000;
    printf("Time to execute: %lf ms",total_time);
    return 0;
}

