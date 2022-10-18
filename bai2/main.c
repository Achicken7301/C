#include <stdio.h>

int kiemTra(int ngay, int thang, int nam){
	if(ngay < 1 || ngay > 31){
		printf("Ngay %d khong hop le!!!\n", ngay);
		return 0;
	}else if(thang < 1 || thang > 12){
		printf("Thang %d khong hop le!!!\n", thang);
		return 0;
	}else if(nam > 2022){
		printf("Nam %d khong hop le!!!\n", nam);
		return 0;
	}else{
		return 1;
	}
	
}



int main()
{
	int ngay, thang, nam;
	do{
		printf("Ngay sinh: ");
		scanf("%d", &ngay);
		printf("Thang sinh: ");
		scanf("%d", &thang);
		printf("Nam sinh: ");
		scanf("%d", &nam);
	}while(kiemTra(ngay, thang, nam) == 0);

		
		
	printf("Ban %d tuoi", 2022 - nam);
	return 0;
}

