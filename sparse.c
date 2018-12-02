#include<stdio.h>
typedef struct {
	int row;
	int col;
	int val;
}smat;
int n, size;
smat a[100], b[100];
void getdata(smat a[]) {
	int mat[20][20], r, c, i, j;
	printf("\nEnter the size of the matrix (row x col) ");
	scanf("%d%d",&r,&c);
	printf("\nEnter the matrix : ");
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			scanf("%d",&mat[i][j]);
	for(i=0;i<r;i++)
		for(j=0;j<c;j++) {
			if(mat[i][j]!=0)
				n++;
		} 
	a[0].val=n;
	a[0].row=r;
	a[0].col=c;
	size=n;
	int k=1;
	for(i=0;i<r;i++) 
		for(j=0;j<c;j++) {
			if(mat[i][j]!=0) {
				a[k].val=mat[i][j];
				a[k].row=i;
				a[k].col=j;
				k++;
			}
	}
	printf("\nThe sparse matrix (original) is ");
	for(i=0;i<=n;i++) 
		printf("\n Row = %d, Col = %d, Val = %d ",a[i].row,a[i].col,a[i].val);
}
void fastT(smat a[], smat b[]) {
		int rowt[100], stpos[100], numcol, numterm, i, j=0;
		numcol=a[0].col;
		b[0].row=numcol;
		b[0].col=a[0].row;
		numterm=a[0].val;
		b[0].val=numterm;
		if(numterm>0) {
			for(i=0;i<numcol;i++) { 
				rowt[i]=0;
			}
			for(i=1;i<=numterm;i++) {
 				rowt[a[i].col]++;
			}
			stpos[0]=1;
			for(i=1;i<numcol;i++) {
				stpos[i]=stpos[i-1]+rowt[i-1];
		 	}
			for(i=1;i<=numterm;i++) {
				j=stpos[a[i].col]++;
				b[j].row=a[i].col;
				b[j].col=a[i].row;
				b[j].val=a[i].val;
			}
	}
}
void disp(smat b[],int n) {
	int i;
	printf("\nThe transpose matrix is : ");
	printf("%d",b[0].val);
	for(i=0;i<=size;i++) 
		printf("\n Row = %d, Col = %d, Val = %d ",b[i].row,b[i].col,b[i].val);
 	printf("\n");
}
int main() {
	getdata(a);
	fastT(a,b);
	disp(b,n);
	return 0;
} 
