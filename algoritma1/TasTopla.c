#include<stdio.h>
int main(){
	int n,m,K,B;
	char i;
	printf("TAS TOPLAMA OYUNUNA HOSGELDINIZ...\n");
	printf("Oyunda kac tas olsun?: ");
	scanf("%d",&n);
	printf("En fazla kac tas toplanabilsin?: ");
	scanf("%d",&m);
	printf("kim baslasin (B - K) :");
	fflush(stdin);
	scanf("%c",&i);
	
	if(i!='K'||i!='B'){
		while(i!='K'&&i!='B'){
			printf("kimin baslayacagini B veya K olarak girin: ");
			fflush(stdin);
			scanf("%c",&i);
		}
	}
	if(i=='K'){
		printf("K: ");
		scanf("%d",&K);
		if(K>m||K<=0){
			while(K>m||K<=0){
				printf("Uygun deger girilmedi, tekrar: ");
				fflush(stdin);
				scanf("%d",&K);
			}
		}
		n=n-K;
	}
	for(;;){
		B=(n-1)%(m+1);
		if(B<=0){
			B=1;
		}
		n=n-B;
		printf("B: %d\t%d\n",B,n);
		if(n==1){
			printf("\nBilgisayar Kazandi...\n\n");
			system("pause");
			return 0;
		}
		printf("K: ");
		scanf("%d",&K);
		if(K>m||K<=0){
			while(K>m||K<=0){
				printf("Uygun deger girilmedi, tekrar: ");
				fflush(stdin);
				scanf("%d",&K);
			}
		}
			n=n-K;
				if(n==1){
					printf("\nKullanici Kazandi...\n\n");
					system("pause");
					return 0;
				}
	}
}
