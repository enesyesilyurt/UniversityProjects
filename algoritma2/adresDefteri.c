#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct n{
	char isim[15];
	char soyisim[15];
	char adres[25];
	int yas;
	char tel[15];
	struct n *next;
}node;

node *yenikisi(node* r){
	if(r==NULL){
		r=(node*)malloc(sizeof(node));
		printf("\nisim : "); gets(r->isim); fflush(stdin); 
		printf("soyisim : "); gets(r->soyisim); fflush(stdin);
		printf("adres : "); gets(r->adres); fflush(stdin);
		printf("yas : "); scanf("%d",&r->yas);  fflush(stdin);
		printf("telefon : "); gets(r->tel); fflush(stdin);
		r->next=NULL; printf("\n");
		return r;
	}
	else{
		node* iter;
		iter=r;
		while(r->next!=NULL)
			r=r->next;
		r->next=(node*)malloc(sizeof(node)); r=r->next;
		printf("\nisim : "); gets(r->isim); fflush(stdin); 
		printf("soyisim : "); gets(r->soyisim); fflush(stdin);
		printf("adres : "); gets(r->adres); fflush(stdin);
		printf("yas : "); scanf("%d",&r->yas);  fflush(stdin);
		printf("telefon : "); gets(r->tel); fflush(stdin);
		r->next=NULL; printf("\n");
		return iter;
	}
}

void yazdir(node *r){
	if(r==NULL){
		printf("\n Henuz kayit yok.\n\n");
		return;
	}
	while(r!=NULL){
		printf("\n%s %s",r->isim,r->soyisim);
		r=r->next;
	}
	printf("\n\n");
}

void kisiyazdir(node* r){
	if(r==NULL){
		printf("\n Henuz kayit yok.\n\n");
		return;
	}
	char i[15],si[15];
	printf("\nisim : "); gets(i); fflush(stdin); 
	printf("soyisim : "); gets(si); fflush(stdin);
	while(r!=NULL){
		if(!strcmp(r->isim,i)&&!strcmp(r->soyisim,si)){
			printf("\nadres : %s\ntelefon : %s\nyas : %d\n\n",r->adres,r->tel,r->yas);
			return;
		}
		r=r->next;
	}
	if(r==NULL){
		printf("\nbulunamadi...\n\n");
	}
}

node* kayitsil(node* r){
	if(r==NULL){
		printf("\n Henuz kayit yok.\n\n");
		return r;
	}
	char i[15],si[15];
	node *iter=r,*temp=r;
	printf("\nisim : "); gets(i); fflush(stdin); 
	printf("soyisim : "); gets(si); fflush(stdin);
	if(!strcmp(r->isim,i)&&!strcmp(r->soyisim,si)){
		printf("\n%s %s adli kisinin bilgileri silindi...\n\n",r->isim,r->soyisim);
		r=r->next;
		free(temp);
		return r;
	}
	else{
	while(r!=NULL){
		if(!strcmp(r->isim,i)&&!strcmp(r->soyisim,si)){
			printf("\n%s %s adli kisinin bilgileri silindi...\n\n",r->isim,r->soyisim);
			iter->next=r->next;
			free(r);
			return temp;
		}
		iter=r;
		r=r->next;
	}
	if(r==NULL){
		printf("\nbulunamadi...\n\n");
	}
	return temp;
	}
}
void guncelle(node *r){
	if(r==NULL){
		printf("\n Henuz kayit yok.\n\n");
		return;
	}
	char i[15],si[15];
	printf("\ndegistirilecek kisinin ismi : "); gets(i); fflush(stdin); 
	printf("soyismi : "); gets(si); fflush(stdin);
	while(r!=NULL){
		if(!strcmp(r->isim,i)&&!strcmp(r->soyisim,si)){
			printf("\nyeni isim : "); gets(r->isim); fflush(stdin); 
			printf("yeni soyisim : "); gets(r->soyisim); fflush(stdin);
			printf("degistirildi..\n\n");
			return;
		}
		r=r->next;
	}
		if(r==NULL){
		printf("\nbulunamadi...\n\n");
	}
}

int main(){
	node *root=NULL;
	FILE *dosya;
	dosya=fopen("kayit.txt","r");
	int x;
	while(1){
		printf("1 : yeni kisi kaydet\n2 : kisi sil\n3 : kisilerin listesi\n4 : bir kisinin bilgilerini yazdir\n5 : kisinin ismini soyismini guncelle\n6 : programi kapat\n7 : dosyadan oku\tgirilen: ");
		scanf("%d",&x);fflush(stdin);
		if(x==1)
			root=yenikisi(root);
		else if(x==2)
			root=kayitsil(root);
		else if(x==3)
			yazdir(root);
		else if(x==4)
			kisiyazdir(root);
		else if(x==5)
			guncelle(root);
		else if(x==6)
			return 0;
		else if(x==7){
				node* iter=root;
			while(!feof(dosya)){
				if(iter==NULL){
					iter=(node*)malloc(sizeof(node));
					iter->next=NULL;
					fscanf(dosya,"%s%s%d%s%s",iter->isim,iter->soyisim,iter->yas,iter->adres,iter->tel);
					}
				while(iter->next!=NULL)
					iter=iter->next;
				iter->next=(node*)malloc(sizeof(node));
				iter->next->next=NULL;
				fscanf(dosya,"%s%s%d%s%s",iter->isim,iter->soyisim,iter->yas,iter->adres,iter->tel);
			}
		}	
		else 
			printf("gecerli sayi girin\n");
	}
	return 0;
}
