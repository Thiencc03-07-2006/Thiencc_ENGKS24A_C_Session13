#include <stdio.h>

void addItem(int arr[],int *n){
    int i=0;
    printf("Vui long nhap so phan tu trong mang: ");
    scanf("%d",n);
    while(i<*n){
        printf("Nhap gia tri cho phan tu [%d]: ",i);
        scanf("%d",&arr[i]);
        i++;
    }
}

void showItem(int arr[],int n){
    int i=0;
    printf("\nCac phan tu trong mang: ");
    while(i<n){
        printf("[%d] ",arr[i]);
        i++;
    }
    printf("\n");
}

void addOneItem(int arr[],int *n){
    int index,num,i=*n;
    printf("Vui long nhap vi tri muon them: ");
    scanf("%d",&index);
    if(index<0||index>*n){
        printf("Vi tri khong hop le\n");
        return;
    }
    printf("Vui long nhap gia tri muon them: ");
    scanf("%d",&num);
    while(i>index){
        arr[i]=arr[i-1];
        i--;
    }
    arr[index]=num;
    (*n)++;
}

void updateItem(int arr[],int n){
    int index,num;
    printf("Vui long nhap vi tri muon sua: ");
    scanf("%d",&index);
    if(index<0||index>=n){
        printf("Vi tri khong hop le\n");
        return;
    }
    printf("Vui long nhap gia tri moi: ");
    scanf("%d",&num);
    arr[index]=num;
}

void deleteItem(int arr[],int *n){
    int index,i;
    printf("Vui long nhap vi tri muon xoa: ");
    scanf("%d",&index);
    if(index<0||index>=*n){
        printf("Vi tri khong hop le\n");
        return;
    }
    i=index;
    while(i<*n-1){
        arr[i]=arr[i+1];
        i++;
    }
    (*n)--;
}

void sortAscending(int arr[],int n){
    int i=0,j;
    while(i<n-1){
        j=i+1;
        while(j<n){
            if(arr[i]>arr[j]){
                int save=arr[i];
                arr[i]=arr[j];
                arr[j]=save;
            }
            j++;
        }
        i++;
    }
}

void sortDescending(int arr[],int n){
    int i=0,j;
    while(i<n-1){
        j=i+1;
        while(j<n){
            if(arr[i]<arr[j]){
                int save=arr[i];
                arr[i]=arr[j];
                arr[j]=save;
            }
            j++;
        }
        i++;
    }
}

void linearSearch(int arr[],int n){
    int num,found=0,i=0;
    printf("Vui long nhap gia tri can tim: ");
    scanf("%d",&num);
    while(i<n){
        if(arr[i]==num){
            printf("Gia tri %d duoc tim thay tai vi tri [%d]\n",num,i);
            found=1;
        }
        i++;
    }
    if(!found){
        printf("Khong tim thay gia tri %d trong mang.\n",num);
    }
}

void binarySearch(int arr[],int n){
    int num,left=0,right=n-1,mid;
    printf("Vui long nhap gia tri can tim: ");
    scanf("%d",&num);
    sortAscending(arr,n);
    while(left<=right){
        mid=(left+right)/2;
        if(arr[mid]==num){
            printf("Gia tri %d duoc tim thay tai vi tri [%d]\n",num,mid);
            return;
        }else if(arr[mid]<num){
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    printf("Khong tim thay gia tri %d trong mang.\n",num);
}

int main(){
    int arr[100],n=0,type,subChoice;;
    do{
        printf("\nMENU\n");
        printf("1. Nhap so phan tu can nhap va gia tri cac phan tu\n");
        printf("2. In ra gia tri cac phan tu dang quan ly\n");
        printf("3. Them mot phan tu vao vi tri chi dinh\n");
        printf("4. Sua mot phan tu o vi tri chi dinh\n");
        printf("5. Xoa mot phan tu o vi tri chi dinh\n");
        printf("6. Sap xep cac phan tu\n");
        printf("7. Tim kiem phan tu nhap vao\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d",&type);
        switch(type){
            case 1:
                addItem(arr,&n);
                break;
            case 2:
                showItem(arr,n);
                break;
            case 3:
                addOneItem(arr,&n);
                break;
            case 4:
                updateItem(arr,n);
                break;
            case 5:
                deleteItem(arr,&n);
                break;
            case 6:
                printf("\n6. Sap xep cac phan tu\n");
                printf("a. Giam dan (Nhap 1)\n");
                printf("b. Tang dan (Nhap 2)\n");
                printf("Lua chon cua ban: ");
                scanf("%d",&subChoice);
                if(subChoice==1){
                    sortDescending(arr,n);
                }else if(subChoice==2){
                    sortAscending(arr,n);
                }else{
                    printf("Lua chon khong hop le!\n");
                }
                break;
            case 7:
                printf("\n7. Tim kiem phan tu\n");
                printf("a. Tuyen tinh (Nhap 1)\n");
                printf("b. Nhi phan (Nhap 2)\n");
                printf("Lua chon cua ban: ");
                scanf("%d",&subChoice);
                if(subChoice==1){
                    linearSearch(arr,n);
                }else if(subChoice==2){
                    binarySearch(arr,n);
                }else{
                    printf("Lua chon khong hop le!\n");
                }
                break;
        }
    }while(type!=8);
    return 0;
}
