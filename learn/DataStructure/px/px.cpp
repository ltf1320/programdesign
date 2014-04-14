# include<stdio.h>
struct student{
	int num;
	char name[10];
	int point1;
	int point2;
	int point3;
	float ave;
};
void Input(student t){
	printf("请输入学生的信息：学号，姓名，语文成绩，数学成绩，英语成绩\n");
	scanf("%d,%s,%d,%d,&d",&t.num,t.name,&t.point1,&t.point2,&t.point3);
	t.ave=(float)(t.point1+t.point2+t.point3)/3;
}
void Output(student t){
	//printf("所要求的学生的信息如下：\n");
	printf("学号\t姓名\t语文\t数学\t英语\t平均成绩\n");
	printf("%d\t%s\t%d\t%d\t%d\t%d\n",t.num,t.name,t.point1,t.point2,t.point3,t.ave);
}
void averal(student t[10]){
	int i,j;
	student m;
	for(i=0;i<10;i++){
		for(j=0;j<i;j++){
			if(t[j].ave<t[j-1].ave){
				m=t[j];
				t[j]=t[j-1];
				t[j-1]=m;
			}
		}
	}
	printf("学号\t姓名\t语文\t数学\t英语\t平均成绩\n");
	for(i=0;i<10;i++){
		printf("%d\t%s\t%d\t%d\t%d\t%d\n",t[i].num,t[i].name,t[i].point1,t[i].point2,t[i].point3,t[i].ave);
	}
}
void max1(student t[10]){
	int i,max;
	 student maxt=t[0];
	 max=t[0].point1;
	for(i=1;i<10;i++){
		if(t[i].point1>max){
			max=t[i].point1;
			maxt=t[i];
		}
	}
	Output(maxt);
}
void max2(student t[10]){
	int max,i;
	student maxt=t[0];
	max=t[0].point2;
	for(i=1;i<10;i++){
		if(t[i].point2>max){
			max=t[i].point2;
			maxt=t[i];
		}
	}
Output(maxt);
}

void max3(student t[10]){
	int max,i;	 
	student maxt=t[0];
	max=t[0].point3;
	for(i=1;i<10;i++){
		if(t[i].point3>max){
			max=t[i].point3;
		    maxt=t[i];
	}
	}
		Output(maxt);
}
void main(){
	int i;
	student stu[10];
	for(i=0;i<10;i++)
		Input(stu[i]);
	printf("对学生平均成绩排序后如下：\n");
	averal(stu[10]);
	printf("语文成绩最高的学生信息如下\n");
	max1(stu[10]);
	printf("数学成绩最高的学生信息如下\n");
	max2(stu[10]);
	printf("英语成绩最高的学生信息如下\n");
	max3(stu[10]);

}