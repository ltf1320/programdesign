#include <stdio.h>
#include <stdlib.h>
struct Student
{
    char name[20];
    int age;
    int score;
    Student *next;
};
    poj.org/
    acm.hdu.edu.cn
    acm.dlmu.edu.cn/

int main()
{
   Student stu;
   Student *p=&stu;
   int i;
   while(~scanf())
   for(i=0;i<3;i++)
   {
       p->next=(Student*)malloc(sizeof(Student));
       p=p->next;
       scanf("%s%d%d",p->name,&p->age,&p->score);
//       scanf("%s%d%d",stu[i].name,&stu[i].age,&stu[i].score);
   }
   p->next=NULL;
    return 0;
}





