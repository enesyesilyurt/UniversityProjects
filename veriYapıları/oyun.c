#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct n{
	int data;
	int xk;//x koordinatý
	int yk;//y koordinatý
	struct n *x;
	struct n *y;
}node;
void engel(node *r);//oyuna engelleri ekliyor. engeller 0 olan verileri 1 yapýyor.Eðer zaten engel varsa recursive olarak tekrar çalýþýyor.
void push(node *r);//matris þeklinde tablo oluþturuyor. her adýmda bir x bir y ve bir de +x+y konumuna node açýp 0 verisi ekliyor.
node *pop(node *r);//oyun bittiðinde hafýzayý temizlemek için node'larý serbest býrakýyor.
void enqu(node *r,int veri,int xk,int yk);//oyundaki adýmlarý ekrana yazdýrmak için sýraya ekliyor.
node *dequ(node *r);// baþtan sýrayla adýmlarý ekrana yazýyor.
void yazdir(node *r);//tabloyu yazdýrýyor.
node *hareket(node *r,node *s,node *son);//oyunda 0,0 dan baþlayýp ilerleyen fonksiyon.
int kapi(node *r,int a);//Kapý anahtar bulunursa oluþturuluyor bu yüzden ilk haritada gözükmüyor. kapý ulaþýlabilir olmasý için anahtarýn saðýnda oluþuyor.
int anahtar(node *r);//Anahtarý oluþturuyor.
int a,k;
int main(){	
	srand(time(NULL));//yeniden baþlatýldýðýnda engellerin ayný yerde olmamasýný saðlýyor.
	node *root=(node*)malloc(sizeof(node));
	node *que=(node*)malloc(sizeof(node));
	que->x=NULL;
	que->y=NULL;que->xk=0;que->yk=0;
	que->data=10;
	root->x=NULL;
	root->y=NULL;
	root->data=0; root->xk=0; root->yk=0;
	node *iter=root,*temp=root,*konum=root,*son=root;
	printf("\n");
	int i,j,a,d=0;
	for(i=0;i<100;i++){
		for(j=0;j<50;j++){
			push(iter);
			iter=iter->y;
		}
		temp=temp->x;
		iter=temp;
	}
	while(son->x!=NULL)
		son=son->x;
	while(son->y!=NULL)
		son=son->y;
		
	while(d!=30){
	engel(root);
	d++;
	}
	a=anahtar(root);
	yazdir(root);
	printf("\n\n\t1: Engel\t0:Bos\n\n");
	while(konum!=son)
		konum=hareket(konum,que,son);
	while(que!=NULL)
		que=dequ(que);
	root=pop(root);
	getch();
	return 0;
}
void push(node *r){
	if(r->x==NULL){
	r->x=(node*)malloc(sizeof(node));
	r->x->x=NULL;
	r->x->data=0;
	r->x->xk=r->xk+1;
	
	}
	if(r->y==NULL){
	r->y=(node*)malloc(sizeof(node));
	r->y->y=NULL;
	r->y->data=0;
	r->y->yk=r->yk+1;
	}
	r->x->y=(node*)malloc(sizeof(node));
	r->x->y->data=0;
	r->y->x=r->x->y;
	r->x->y->x=NULL;
	r->y->x->y=NULL;
	r->y->x->yk=r->y->yk;
	r->x->y->xk=r->x->xk;
}
node *pop(node *r){
	node *iter=r;int x=0;
	node *temp=r->x;
	while(r!=NULL){
		while(r!=NULL){
			iter=r;
			r=r->y;
			free(iter);
		}
		r=temp;
		if(temp!=NULL)
			temp=temp->x;
	}
}
void enqu(node *que,int veri,int xk,int yk){
	node *temp=que;
	while(que->x!=NULL)
		que=que->x;
	que->x=(node*)malloc(sizeof(node));
	que->x->x=NULL;
	que->y=NULL;
	que->x->xk=xk;
	que->x->yk=yk;
	que->x->data=veri;
}
node *dequ(node *que){
	if(que==NULL)
		return NULL;
	node *temp=que->x;
		if(que->data==1)
			printf("%d,%d   \nmavi\t(0)\tgeldi +2x\t",que->xk,que->yk);
		else if(que->data==2)
			printf("%d,%d   \nENGEL!\tilk hamlede   -x\t",que->xk,que->yk);
		else if(que->data==3)
			printf("%d,%d   \nENGEL!\tikinci hamlede   -2x\t",que->xk,que->yk);
		else if(que->data==4)
			printf("%d,%d   \nkirmizi\t(1)\tgeldi +2y\t",que->xk,que->yk);
		else if(que->data==5)
			printf("%d,%d   \nENGEL!\tilk hamlede   -y\t",que->xk,que->yk);
		else if(que->data==6)
			printf("%d,%d   \nENGEL!\tikinci hamlede   -2y\t",que->xk,que->yk);
		else if(que->data==7)
			printf("%d,%d   \nbeyaz\t(2)\tgeldi +x +y\t",que->xk,que->yk);
		else if(que->data==8)
			printf("%d,%d   \nENGEL!\tilk hamlede   -x\t",que->xk,que->yk);
		else if(que->data==9)
			printf("%d,%d   \nENGEL!\tikinci hamlede\t-x -y\t",que->xk,que->yk);
		else if(que->data==11)
			printf("%d,%d\nKapiyi Bulamadin...\nSON\n",que->xk,que->yk);
		else if(que->data==10)
			printf("Basliyor ");
		else if(que->data==12)
			printf("%d,%d   \nAnahtari Buldun !!!\nKapi(%d,50) konumunda\t\t",que->xk,que->yk,k);
		else if(que->data==13)
			printf("%d,%d   \nOYUNU KAZANDIN TEBRIKLER!!!  %d,50",que->xk,que->yk,k);
	free(que);
	return temp;
}
void yazdir(node *r){
	node *temp=r;
	node *iter=r; int x=1,y=1;
	printf(" X\t");
	while(y!=11){
			printf("---------%d",y);
			y++;
		}
		printf("\nY\n",x);
	while(x!=51){
		y=1;
		printf("\n%d\t",x);
		while(y!=101){
			printf("%d",iter->data);
			iter=iter->x;
			y++;
		}
		temp=temp->y;
		iter=temp;
		x++;
		y=1;
	}
	printf(" (100,50)");
}
void engel(node *r){
	int i,j,x,y;
	
		x=rand()%100;
		y=rand()%50;
		for(i=0;i<x;i++)
			r=r->x;
		for(j=0;j<y;j++)
			r=r->y;
		if(r->data==0)
			r->data=1;
		else{
			engel(r);
		}
}
int anahtar(node *r){
	int i,j,x,y;
		x=rand()%2;
		y=rand()%2;
		for(i=0;i<x;i++)
			r=r->x;
		for(j=0;j<y;j++)
			r=r->y;
		if(r->data==0||r->data==1)
			r->data=2;
		else
			anahtar(r);
		return r->xk+1;
}
int kapi(node *r,int a){
	int i,x;
		x=rand()%(99-a);
		x=x+a;
		while(r->y!=NULL)
			r=r->y;
		for(i=0;i<x;i++)
			r=r->x;
		r->data=3;
		return r->xk+1;
}
node *hareket(node *r,node *que,node *son){
	node *temp=r;
	int x=rand()%3;
	if(x==0){
		enqu(que,1,r->xk,r->yk);
		if(r->x!=NULL){
			r=r->x;
			if(r->data==1){
				enqu(que,2,r->xk,r->yk);
				return temp;
			}
			else if(r->data==2){
			k=kapi(r,a);
			enqu(que,12,r->xk,r->yk);
			}
			else if(r->data==3){
				enqu(que,13,r->xk,r->yk);
				return son;
			}
		}
		if(r->x!=NULL){
			r=r->x;
			if(r->data==1){
				enqu(que,3,r->xk,r->yk);
				return temp;
			}
			else if(r->data==2){
			k=kapi(r,a);
			enqu(que,12,r->xk,r->yk);
			}
			else if(r->data==3){
				enqu(que,13,r->xk,r->yk);
				return son;
			}
		}
		temp=r;
	}
	else if(x==1){
		enqu(que,4,r->xk,r->yk);
		if(r->y!=NULL){
			r=r->y;
			if(r->data==1){
				enqu(que,5,r->xk,r->yk);
				return temp;
			}
			else if(r->data==2){
			k=kapi(r,a);
			enqu(que,12,r->xk,r->yk);
			}
			else if(r->data==3){
				enqu(que,13,r->xk,r->yk);
				return son;
			}
		}
		if(r->y!=NULL){
			r=r->y;
			if(r->data==1){
				(que,6,r->xk,r->yk);
				return temp;
			}
			else if(r->data==2){
			k=kapi(r,a);
			enqu(que,12,r->xk,r->yk);
			}
			else if(r->data==3){
				enqu(que,13,r->xk,r->yk);
				return son;
			}
		}
		temp=r;
	}
	else{
		enqu(que,7,r->xk,r->yk);
		if(r->x!=NULL){
			r=r->x;
			if(r->data==1){
				enqu(que,8,r->xk,r->yk);
				return temp;
			}
			else if(r->data==2){
			k=kapi(r,a);
			enqu(que,12,r->xk,r->yk);
			}
			else if(r->data==3){
				enqu(que,13,r->xk,r->yk);
				return son;
			}
		}
		if(r->y!=NULL){
			r=r->y;
			if(r->data==1){
				enqu(que,9,r->xk,r->yk);
				return temp;
			}
			else if(r->data==2){
			k=kapi(r,a);
			enqu(que,12,r->xk,r->yk);
			}
			else if(r->data==3){
				enqu(que,13,r->xk,r->yk);
				return son;
			}
		}
		temp=r;
	}
	if(r->xk==100&&r->yk==50)
		enqu(que,11,r->xk,r->yk);
	return temp;
}
