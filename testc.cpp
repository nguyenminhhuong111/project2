#include<stdio.h>
struct danso{
	int nam;
	int so_nguoi_sinh_ra;
};
void nhap(struct danso A[], int n){//ham nhap thong tin cac nam
	for(int i = 0; i < n; i++){
		scanf("%d%d", &A[i].nam, &A[i].so_nguoi_sinh_ra);
	}
}
//request_1: so nam co so luong nguoi sinh ra bang nhau
int request_1(struct danso A[], int n){
	int count[1000] = {0};
	for(int i = 0; i < n; i++){
		count[A[i].so_nguoi_sinh_ra]++;
	}
	int check = 0;
	for(int i = 0; i < n; i++){
		if(count[A[i].so_nguoi_sinh_ra] > 1){
			check++;
			count[A[i].so_nguoi_sinh_ra] = 0;
		}
	}
	return check;
}
//request_2: in ra cac nam co so luong  nguoi sinh ra lon nhat va be nhat
void in_request_2(struct danso A[], int n){
	int min = A[0].so_nguoi_sinh_ra;
	for(int i = 1; i < n; i++){
		if(A[i].so_nguoi_sinh_ra < min) min = A[i].so_nguoi_sinh_ra;
	}
	printf("Cac nam co so luong nguoi sinh ra be nhat la : ");
	for(int i = 0; i < n; i++){
		if(A[i].so_nguoi_sinh_ra == min) printf("%d ", A[i].nam);
	}
	int max = A[0].so_nguoi_sinh_ra;
	for(int i = 1; i < n; i++){
		if(A[i].so_nguoi_sinh_ra > max) max = A[i].so_nguoi_sinh_ra;
	}
	printf("\nCac nam co so luong nguoi sinh ra lon nhat la : ");
	for(int i = 0; i < n; i++){
		if(A[i].so_nguoi_sinh_ra == max) printf("%d ", A[i].nam);
	}
}
int main(){
	int n;
	printf("Nhap so nam :");
	scanf("%d", &n);
	struct danso A[n];
	printf("Nhap thong tin cua cac nam: \n");
	nhap(A, n);
	printf("So nam co cung so luong nguoi sinh ra la %d\n", request_1(A, n));
	in_request_2(A, n);
	return 0;
}