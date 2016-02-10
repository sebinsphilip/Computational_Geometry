#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
struct vlist
{
int x;
int y;
struct vlist *next;

}*vroot;
struct dcel
{
int x1;
int y1;
int x2;
int y2;
int f1;
int f2;
int p1;
int p2;
}*root;
struct dcel * d[20];
int n,n1,HF[10];
void dcel_input()
{
FILE *fp = fopen("input1.txt","r+");
//if input1.txt n=16
//if input2.txt n=10
int i,ip1,ip2;
printf("\nEnter y-sorted edge list:");
printf("Enter no. of edges");
scanf("%d",&n);
for(i=0;i<n&& ! feof(fp);i++)
{
 d[i]= (struct dcel*)malloc(sizeof(struct dcel));
 fscanf(fp,"%d%d%d%d%d%d%d%d",&d[i]->x1,&d[i]->y1,&d[i]->x2,&d[i]->y2,&d[i]->f1,&d[i]->f2,&ip1,&ip2);

 d[i]->p1 = ip1-1; d[i]->p2 = ip2-1;
}
root = d[0];
printf("DCEL\n");
       setcolor(YELLOW);
       setbkcolor(BLACK);
for(i=0;i<n;i++)
   line(d[i]->x1, d[i]->y1,d[i]->x2,d[i]->y2);
    fclose(fp);
}
void monotoneSubPoly()
{
  FILE *fpOut = fopen("monotonePolygons.txt","w+");
  struct vlist *subP[10],*temp,*p ;
  int i,a,a0,poly[20],j,k;
  n1=0;
  for(i=0;i<n;i++)
  {
       if((d[i]->f1)>n1)
	n1 = d[i]->f1;
       if((d[i]->f2)>n1)
	n1= d[i]->f2;
  }
  for(i=0;i<n1;i++)
   HF[i]=-1;
  for(i=0;i<n;i++)
  {
      if(HF[(d[i]->f1)-1]==-1)  HF[(d[i]->f1)-1]= i;
       if(HF[(d[i]->f2)-1]==-1) HF[(d[i]->f2)-1] = i;
  }
  for(i=0;i<n1;i++)
   printf("%d:",HF[i]);
   for(i=1;i<n1;i++)
   {
   a=HF[i];
   a0 = a;
   temp = (struct vlist*)malloc(sizeof(struct vlist));
   subP[i] = temp;
   temp->next = NULL;
   if(d[a]->f1==i+1)
   {temp->x = d[a]->x1; temp->y = d[a]->y1;}
   else if(d[a]->f2==i+1)
   {temp->x = d[a]->x2; temp->y = d[a]->y2;}

   if(d[a]->f1 == i+1)
    a= d[a]->p1;
   else
    a= d[a]->p2;
   while(a!=a0)
   {

    temp = (struct vlist*)malloc(sizeof(struct vlist));
   if(d[a]->f1 == i+1)
    {temp->x = d[a]->x1; temp->y = d[a]->y1; }
   else
    {temp->x = d[a]->x2; temp->y = d[a]->y2;   }

    temp->next = subP[i];
    subP[i]= temp;
    if(d[a]->f1 ==i+1)
      a= d[a]->p1;
    else
     a= d[a]->p2;

   }
     p = subP[i];j=0;

 while(p!=NULL)
  {
  poly[j]=p->x;poly[j+1]=p->y;
  j+=2;
  fprintf(fpOut,"%d %d ",p->x,p->y);
  p = p->next;
  }
   fprintf(fpOut,"\n");
       setcolor(YELLOW);
       setbkcolor(BLACK);
   for(k=0;k<n;k++)
     line(d[k]->x1, d[k]->y1,d[k]->x2,d[k]->y2);
   setfillstyle(1,YELLOW);
   fillpoly((j/2),poly);
   getch();
   cleardevice();
   }
   fclose(fpOut);
}
void main()
{

int gdriver = DETECT,gmode;
initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
dcel_input();
getch();
monotoneSubPoly();
getch();
}