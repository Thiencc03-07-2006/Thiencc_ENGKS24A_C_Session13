#include <stdio.h>

void inputMatrix(int arr[100][100],int *n,int *m) {
    printf("Vui long nhap so hang: ");
    scanf("%d",n);
    printf("Vui long nhap so cot: ");
    scanf("%d",m);
    int i=0;
    while (i<*n){
        int j=0;
        while(j<*m) {
            printf("Nhap gia tri cho phan tu [%d][%d]: ",i,j);
            scanf("%d",&arr[i][j]);
            j++;
        }
        i++;
    }
}

void printMatrix(int arr[100][100],int n,int m) {
    printf("\nMa tran:\n");
    int i=0;
    while(i<n){
        int j=0;
        while (j<m) {
            printf("%d ",arr[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

void printCorners(int arr[100][100],int n,int m) {
    printf("\nCac phan tu o goc:\n");
    int i=0;
    while(i<n){
        int j=0;
        while(j<m){
            if((i==0&&j==0)||(i==0&&j==m-1)|| 
                (i==n-1&&j==0)||(i==n-1&&j==m-1)){
                printf("%d ",arr[i][j]);
            } else {
                printf("0 ");
            }
            j++;
        }
        printf("\n");
        i++;
    }
}

void printBorders(int arr[100][100],int n,int m) {
    printf("\nCac phan tu tren duong bien:\n");
    int i=0;
    while(i<n) {
        int j=0;
        while(j<m){
            if (i==0||i==n-1||j==0||j==m-1){
                printf("%d ",arr[i][j]);
            }else{
                printf("0 ");
            }
            j++;
        }
        printf("\n");
        i++;
    }
}
 
void printDiagonals(int arr[100][100],int n,int m) {
    printf("\nCac phan tu tren duong cheo chinh va cheo phu:\n");
    int i=0;
    while(i<n){
        int j=0;
        while(j<m){
            if(i==j||i+j==m-1){
                printf("%d ",arr[i][j]);
            }else{
                printf("0 ");
            }
            j++;
        }
        printf("\n");
        i++;
    }
}

int isPrime(int num) {
    if(num<2){
    	return 0;
	}
	int i=2;
    while(i<(num)){
        if(num%i==0){
        	return 0;
		}
		i++;
    }
    return 1;
}

void printPrimes(int arr[100][100],int n,int m) {
    printf("\nCac phan tu la so nguyen to:\n");
    int i=0;
    while (i<n) {
        int j=0;
        while (j<m) {
            if (isPrime(arr[i][j])) {
                printf("%d ",arr[i][j]);
            } else {
                printf("0 ");
            }
            j++;
        }
        printf("\n");
        i++;
    }
}

int main() {
    int arr[100][100],n,m,type;
    do{
        printf("\nMENU\n");
        printf("1. Nhap gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
        printf("3. In ra cac phan tu o goc theo ma tran\n");
        printf("4. In ra cac phan tu nam tren duong bien theo ma tran\n");
        printf("5. In ra cac phan tu nam tren duong cheo chinh va cheo phu theo ma tran\n");
        printf("6. In ra cac phan tu la so nguyen to theo ma tran\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d",&type);
        switch(type){
            case 1:
                inputMatrix(arr,&n,&m);
                break;
            case 2:
                printMatrix(arr,n,m);
                break;
            case 3:
                printCorners(arr,n,m);
                break;
            case 4:
                printBorders(arr,n,m);
                break;
            case 5:
                printDiagonals(arr,n,m);
                break;
            case 6:
                printPrimes(arr,n,m);
                break;
        }
    } while (type != 7);
    return 0;
}

