#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define max 10000
int undg[max][max];
int psudoRandom(int x){
  int z = (7*x+4)%9;
  return z;

}
int main()
{
    int sum=0,edge=0,degA=0,degB=0,n;
    double total_time;
    clock_t start,end;
    printf("\n Enter the number vertices: ");
    scanf("%d",&n);
    int x = 3;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int val = psudoRandom(x);
            x = val;
            undg[i][j]=val%2;
            undg[j][i]=val%2;
        }
    }
    start = clock();
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
    printf("\n Number of degrees of all Vertices: %d\n",sum);
    printf("\n Number of Edge: %d\n",edge);
    printf("\n The total number of edges is(using handshaking theorem): \n");
    printf(" Edge = (sum of degree/2) = (%d/2) = %d\n",sum,sum/2);
    end =clock();
    total_time = ((double)(end-start)/CLOCKS_PER_SEC)*1000;
    printf("\n Time to execute: %lf ms\n",total_time);
    return 0;
}
