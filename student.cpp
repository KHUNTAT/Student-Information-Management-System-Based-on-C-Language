/*  项目：基于C语言的学生管理系统（包含文件）
	工具：Microsoft Visual C++ 2010 学习版
	负责人：瑾年辰良
	时间：2020.1.16-2020.2.2 初步完工
	      2020.4.15-2020.6.25 一次优化
		  2020.7.25-2020.7.30 二次优化
	习得：C语言单链表的创建，打印，查找，删除与排序；文件流的输入与输出；
		  函数模块化；加深对基础的掌握。
*/
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include "mylist.h"

struct Node *List=NULL;//创建链表节点


void menu();//主界面
void function();//功能界面
void login();//登录界面
void login_Second();//登录分界面
void rebackPassword();//找回密码
void addStudent(struct student tempData);//添加学生信息
void searchStudent(struct student tempData);//查找学生信息
void modifyStudent(struct student tempData);//修改学生信息
void modifyStudent_Second(struct student tempData);//修改学生信息功能的部分代码
void deleteStudent(struct student tempData);//删除学生信息
void sortStudent();//排序学生信息


//主函数
int main()
{
	//设置控制台标题，颜色，尺寸
	system("title 学生信息管理系统");
	system("color F0");
	system("mode con cols=90 lines=30");

	//创造一个链表，存储学生信息
	List=creatList();

	//读取student.txt文件信息到链表中
    //student.txt用于存放链表中的学生信息
	readFromFile("student.txt",List);
	//进入主界面
	menu();

	return 0;
}
//主界面
void menu()
{
	printf("\t\t\t----------------------------------------\n");
    printf("\t\t\t|\t欢迎来到三千学生管理系统\t|\n");
    printf("\t\t\t----------------------------------------\n");
    printf("\t\t\t|\t1.登陆\t\t\t\t|\n");
    printf("\t\t\t|\t2.找回密码\t\t\t|\n");
    printf("\t\t\t|\t3.退出系统\t\t\t|\n");
    printf("\t\t\t----------------------------------------\n");
    printf("\t\t\t请选择功能(1-3)(按回车键确认):");

	//获取选择
	int choice = 0;
	scanf("%d",&choice);

	//清除缓冲区
	char ch;
	while((ch = getchar()) != '\n' && ch != EOF);

	switch(choice)//判断选择
	{
	case 1:
		{
			system("cls");//刷新界面
			login();//调用login()函数进行登录
			break;
		}
	case 2:
		{
			system("cls");
			rebackPassword();//调用rebackPassword()函数找回密码
			break;
		}
	case 3:
		{
			printf("\n\t\t\t");
			exit(0);//退出系统
		}
	default:
		{
			//当输入不是指定选项时
			printf("\n\t\t\t输入错误！请重新输入！\n\t\t\t");
			system("pause");//暂停程序
			system("cls");//刷新界面

			menu();//重新调用本函数
			break;
		}
	}
}
//登录界面
void login()
{
	int i = 0;
	char Password[]="123";//登录密码
	char tempPass[10]="0";//从输入端获取的密码

	printf("\t\t\t---------------登陆系统---------------\n\n");
	printf("\t\t\t\t管理员账号:三千\n");
	for(i=1;i<=3;i++)
	{
		printf("\t\t\t\t管理员密码:");
		//获取你所输入的密码
		scanf("%s",tempPass);

		//清除缓冲区
		char ch;
		while((ch = getchar()) != '\n' && ch != EOF);

		//判断登录密码和获取的密码是否相同
        //strcmp()用于字符串比较，两字符串相同时返回0
		if(!strcmp(Password,tempPass))
		{
			printf("\n\t\t\t\t登陆成功!");
			printf("\n\t\t\t\t");
			system("pause");//程序暂停
			system("cls");//刷新界面
			function();//调用fuction()函数进入功能界面
		}else
		{
			//密码错误达到三次
			if(3 == i)
			{
				printf("\n\t\t\t\t密码输入错误3次!请重新选择！\n\n");
				printf("\t\t\t\t");
				system("pause");
			}else
			{
				printf("\n\t\t\t\t密码输入错误%d次!请重新输入!\n",i);
			}
		}
	}
	if(4 == i)
	{
		system("cls");
		//登录密码失败后进入登录分界面
		login_Second();/
	}
}
//登录分界面，解决密码输入错误超过三次后
void login_Second()
{
	printf("\t\t\t-------------------------------------\n");
	printf("\t\t\t|\t    1.找回密码\t\t    |\n");
	printf("\t\t\t|\t    2.重新登录\t\t    |\n");
	printf("\t\t\t|\t    3.退出系统\t\t    |\n");
	printf("\t\t\t-------------------------------------\n");
	printf("\t\t\t\t   请选择(1-3)：");

	//获取选择
	int choice = 0;
	scanf("%d",&choice);

	//清除缓冲区
	char ch;
	while((ch = getchar()) != '\n' && ch != EOF);
	switch(choice)
	{
	case 1:
		{
			system("cls");//刷新界面
			rebackPassword();//调用rebackPassword()函数找回密码
			break;
		}
	case 2:
		{
			system("cls");
			login();//调用login()函数进行登录
			break;
		}
	case 3:
		{
			printf("\n\t\t\t\t");
			exit(0);//退出系统
		}
	default:
		{
			printf("\n\t\t\t\t输入错误！请重新输入！\n\t\t\t\t");
			system("pause");//暂停程序
			system("cls");//刷新界面

			login_Second();//重新调用本函数
			break;
		}
	}
}
//找回密码
void rebackPassword()
{
	int question_one=0;
	int question_two=0;
	int question_three=0;

	printf("\t\t\t    ------------找回密码------------\n\n");
	printf("\t\t\t\t    请输入密保问题：");
	printf("\n\t\t\t\t    1.你小时候生活在哪?");
	printf("\n\t\t\t\t      答案:");

	scanf("%d",&question_one);//获取密保一答案
	char ch;
	while((ch = getchar()) != '\n' && ch != EOF);//清除缓冲区

	printf("\n\t\t\t\t    2.你的未来城市是哪个?");
	printf("\n\t\t\t\t      答案:");

	scanf("%d",&question_two);//获取密保二答案
	while((ch = getchar()) != '\n' && ch != EOF);//清除缓冲区

	printf("\n\t\t\t\t    3.你的愿望是什么?");
	printf("\n\t\t\t\t      答案:");

	scanf("%d",&question_three);//获取密保三答案
	while((ch = getchar()) != '\n' && ch != EOF);//清除缓冲区

	if(1 == question_one && 2 == question_two && 3 == question_three)//判断密保是否正确
	{
		printf("\n\n\t\t\t\t    管理员密码:123\n\n\t\t\t\t    ");
		system("pause");//暂停系统
		system("cls");//刷新界面
	}else
	{
		printf("\n\t\t\t\t     答案错误！\n\n\t\t\t\t    ");
		system("pause");
		system("cls");
	}
	menu();//进入界面
	
}
//功能界面
void function()
{
    printf("\t\t\t-----------------------------------------\n");
    printf("\t\t\t|\t欢迎使用三千学生管理系统\t|\n");
    printf("\t\t\t-----------------------------------------\n");
    printf("\t\t\t|\t1.添加学生信息\t\t\t|\n");
    printf("\t\t\t|\t2.统计学生信息\t\t\t|\n");
    printf("\t\t\t|\t3.查找学生信息\t\t\t|\n");
    printf("\t\t\t|\t4.修改学生信息\t\t\t|\n");
    printf("\t\t\t|\t5.删除学生信息\t\t\t|\n");
    printf("\t\t\t|\t6.排序学生信息\t\t\t|\n");
    printf("\t\t\t|\t7.返回上一级\t\t\t|\n");
	printf("\t\t\t|\t8.退出程序\t\t\t|\n");
    printf("\t\t\t-----------------------------------------\n");
    printf("\t\t\t请选择功能(1-8):");
	
	//存储临时数据
	struct student tempData={"0","0","0",0,0.0,0.0,0.0};

	//获取选择
	int choice = 0;
	scanf("%d",&choice);
	//清除缓冲区
	char ch;
	while((ch = getchar()) != '\n' && ch != EOF);

	switch(choice)
	{
	case 1:
		{
			//调用addStudent()函数添加学生信息
			addStudent(tempData);
			printf("\n\t\t\t\t");
			system("pause");//暂停程序
			system("cls");//刷新界面
			break;
		}
	case 2:
		{
			printf("\n\t\t\t--------------统计学生信息--------------\n");
			//调用printList()函数打印所有学生信息
			printList(List);
			printf("\n\t\t\t\t");
			system("pause");
			system("cls");
			break;
		}
	case 3:
		{
			//调用searchStudent()函数查找学生信息
			searchStudent(tempData);
			printf("\n\t\t\t\t");
			system("pause");
			system("cls");
			break;
		}
	case 4:
		{
			//调用modifyStudent()函数修改学生信息
			modifyStudent(tempData);
			printf("\n\t\t\t\t");
			system("pause");
			system("cls");
			break;
		}
	case 5:
		{
			//调用deleteStudent()函数删除学生信息
			deleteStudent(tempData);
			printf("\n\t\t\t\t");
			system("pause");
			system("cls");
			break;
		}
	case 6:
		{
			//调用sortStudent()函数排序学生信息
			sortStudent();
			printf("\n\t\t\t\t");
			system("pause");
			system("cls");
			break;
		}
	case 7:
		{
			system("cls");
			menu();//返回主界面
			break;
		}
	case 8:
		{
			printf("\n\t\t\t\t");
			exit(0);//退出系统
		}
	default:
		{
			printf("\n\t\t\t\t输入错误！请重新输入！\n");
			printf("\n\t\t\t\t");
			system("pause");//暂停程序
			system("cls");//刷新界面
			break;
		}
	}
	function();//重新调用本函数
}
//添加学生信息
void addStudent(struct student tempData)
{
	printf("\n\t\t\t--------------添加学生信息--------------\n");
	printf("\t\t\t\t学号：");
	scanf("%s",tempData.id);//获取学生学号
	char ch;
	while((ch = getchar()) != '\n' && ch != EOF);//清除缓冲区

	printf("\t\t\t\t姓名：");
	scanf("%s",tempData.name);//获取学生姓名
	while((ch = getchar()) != '\n' && ch != EOF);

	printf("\t\t\t\t性别：");
	scanf("%s",tempData.gender);//获取学生性别
	while((ch = getchar()) != '\n' && ch != EOF);

	printf("\t\t\t\t年龄：");
	scanf("%d",&tempData.age);//获取学生年龄
	while((ch = getchar()) != '\n' && ch != EOF);

	printf("\t\t\t\t数学：");
	scanf("%f",&tempData.math);//获取学生数学成绩
	while((ch = getchar()) != '\n' && ch != EOF);

	printf("\t\t\t\t英语成绩：");
	scanf("%f",&tempData.english);//获取学生英语成绩
	while((ch = getchar()) != '\n' && ch != EOF);

	tempData.sumscore=tempData.math+tempData.english;//计算学生总成绩
	printf("\t\t\t\t总成绩为：%.1f\n",tempData.sumscore);//打印学生总成绩

	insertnode(List,tempData);//向链表中插入学生信息
	saveToFile("student.txt",List);//将链表中的学生信息保存到文件student.txt
	printf("\n\t\t\t\t添加成功！\n");
}
//查找学生信息
void searchStudent(struct student tempData)
{
	printf("\n\t\t\t---------------查找学生信息--------------\n\n");
	printf("\t\t\t\t1.按学号查找\t\t\t\t\n");
	printf("\t\t\t\t2.按姓名查找\t\t\t\t\n");
	printf("\t\t\t\t请选择功能:");

	//获取选择
    int choice = 0;
	scanf("%d",&choice);
	//清除缓冲区
	char ch;
	while((ch = getchar()) != '\n' && ch != EOF);

	switch(choice)
	{
	case 1:
		{
			printf("\n\t\t\t请输入要查找的学生的学号:");
			scanf("%s",tempData.id);//获取学生学号
			while((ch= getchar()) != '\n' && ch != EOF);//清除缓冲区

			//searchnode_byid()返回值为结点指针或NULL
            //返回NULL，说明未查到
			if(searchnode_byid(List,tempData.id) == NULL)
			{
				//若链表中不存在该学号
				printf("\n\t\t\t\t查无此人!\n");	
			}else
			{
				//打印查找的学生信息
				printsearch(searchnode_byid(List,tempData.id));
			}
			break;
		}
	case 2:
		{
			printf("\n\t\t\t请输入要查找的学生的姓名:");
			scanf("%s",tempData.name);//获取学生姓名
			while((ch = getchar()) != '\n' && ch != EOF);//清除缓冲区

			//searchnode_byname()返回值为结点指针或NULL
            //返回NULL，说明未查到
			if(searchnode_byname(List,tempData.name) == NULL)
			{
				//若链表中不存在该姓名
				printf("\n\t\t\t\t查无此人!\n");
			}else
			{
				//打印查找的学生信息
				printsearch(searchnode_byname(List,tempData.name));
			}
			break;
		}
	default:
		{
			printf("\n\t\t\t\t输入错误！请重新输入！\n");
			break;
		}
	}
}
//修改学生信息
void modifyStudent(struct student tempData)
{
	printf("\n\t\t\t--------修改学生信息--------\t\t\t\t\n");
	//先调用printList()函数打印全部学生信息
	printList(List);
	printf("\t\t\t\t1.按学号修改\t\t\t\t\n");
	printf("\t\t\t\t2.按姓名修改\t\t\t\t\n");
	printf("\t\t\t\t请选择功能:");

	//获取选择
	int choice = 0;
	scanf("%d",&choice);
	//清除缓冲区
	char ch;
	while((ch = getchar()) != '\n' && ch != EOF);

	switch(choice)
	{
	case 1:
		{
			printf("\n\t\t\t请输入要修改的学生的学号：");

			scanf("%s",tempData.id);//获取学生的学号
			while((ch = getchar()) != '\n' && ch != EOF);

			if(searchnode_byid(List,tempData.id) == NULL)
			{
				//若链表中不存在该学号
				printf("\n\t\t\t\t查无此人!\n");
			}else
			{
				//修改学生信息的分函数
				modifyStudent_Second(tempData);
			}
			break;
		}
	case 2:
		{
			printf("\n\t\t\t\t请输入要修改的学生的姓名：");
			scanf("%s",tempData.name);//获取学生姓名
			while((ch = getchar()) != '\n' && ch != EOF);

			if(searchnode_byname(List,tempData.name)==NULL)
			{
				//若链表中不存在该姓名
				printf("\n\t\t\t\t查无此人!\n");
			}else
			{
				modifyStudent_Second(tempData);
			}
			break;
		}
	default:
		{
			printf("\t\t\t\t输入错误！请重新输入！\n");
			function();//进入功能界面
			break;
		}
	}
}
void modifyStudent_Second(struct student tempData)
{
	//重新定义一个指针并指向要修改的学生的信息的结点
	struct Node *curnode=searchnode_byid(List,tempData.id);
	//调用printsearch()函数打印要修改学生的信息
	printsearch(searchnode_byid(List,tempData.id));

	printf("\n");
	printf("\t\t\t\t1.学号\t\t\t\t\n");
	printf("\t\t\t\t2.姓名\t\t\t\t\n");
	printf("\t\t\t\t3.性别\t\t\t\t\n");
	printf("\t\t\t\t4.年龄\t\t\t\t\n");
	printf("\t\t\t\t5.高数成绩\t\t\t\t\n");
	printf("\t\t\t\t6.英语成绩\t\t\t\t\n");
	printf("\t\t\t\t请选择要修改的内容：");

	//获取选择
	int choice = 0;
	scanf("%d",&choice);
	//清除缓冲区
	char ch;
	while((ch = getchar()) != '\n' && ch != EOF);

	switch(choice)
	{
		case 1:
		{
			printf("\n\t\t\t\t修改前的学号：%s\n",curnode->data.id);
			printf("\t\t\t\t请输入修改后的学号：");

			scanf("%s",curnode->data.id);
			while((ch = getchar()) != '\n' && ch != EOF);

			//将修改后的信息保存到文件
			saveToFile("student.txt",List);
			printf("\n\t\t\t\t修改成功!\n");
			break;
		}
		case 2:
		{
			printf("\n\t\t\t\t修改前的姓名：%s\n",curnode->data.name);
			printf("\t\t\t\t请输入修改后的姓名：");

			scanf("%s",curnode->data.name);
			while((ch = getchar()) != '\n' && ch != EOF);

			saveToFile("student.txt",List);
			printf("\n\t\t\t\t修改成功!\n");
			break;
		}
		case 3:
		{
			printf("\n\t\t\t\t修改前的性别：%s\n",curnode->data.gender);
			printf("\t\t\t\t请输入修改后的性别：");

			scanf("%s",curnode->data.gender);
			while((ch= getchar()) != '\n' && ch != EOF);

			saveToFile("student.txt",List);
			printf("\n\t\t\t\t修改成功!\n");
			break;
		}
		case 4:
		{
			printf("\n\t\t\t\t修改前的年龄：%d\n",curnode->data.age);
			printf("\t\t\t\t请输入修改后的年龄：");

			scanf("%d",&curnode->data.age);
			while((ch = getchar()) != '\n' && ch != EOF);

			saveToFile("student.txt",List);
			printf("\n\t\t\t\t修改成功!\n");
			break;
		}
		case 5:
		{
			printf("\n\t\t\t\t修改前的高数成绩：%.1f\n",curnode->data.math);
			printf("\t\t\t\t请输入修改后的高数成绩：");

			scanf("%f",&curnode->data.math);
			while((ch = getchar()) != '\n' && ch != EOF);

			//计算总成绩
			curnode->data.sumscore=curnode->data.math+curnode->data.english;

			saveToFile("student.txt",List);
			printf("\n\t\t\t\t修改成功!\n");
			break;
		}
		case 6:
		{
			printf("\n\t\t\t\t修改前的英语成绩：%.1f\n",curnode->data.english);
			printf("\t\t\t\t请输入修改后的英语成绩：");

			scanf("%f",&curnode->data.english);
			while((ch = getchar()) != '\n' && ch != EOF);

			curnode->data.sumscore=curnode->data.math+curnode->data.english;

			saveToFile("student.txt",List);
			printf("\n\t\t\t\t修改成功!\n");
			break;
		}
		default:
		{
			printf("\n\t\t\t\t输入错误！请重新输入！\n");
			break;
		}
	}
}
//删除学生信息
void deleteStudent(struct student tempData)
{
	printf("\n\t\t\t--------------删除学生信息---------------\n");
	//调用printList()函数打印全部学生信息
	printList(List);
	printf("\t\t\t\t1.按学号删除\t\t\t\t\n");
	printf("\t\t\t\t2.按姓名删除\t\t\t\t\n");
	printf("\t\t\t\t请选择功能:");

	//获取选择
	int choice = 0;
	scanf("%d",&choice);
	//清除缓冲区
	char ch;
	while((ch = getchar()) != '\n' && ch != EOF);

	switch(choice)
	{
	case 1:
		{
			printf("\n\t\t\t请输入要删除的学生的学号:");

			scanf("%s",tempData.id);
			while((ch = getchar()) != '\n' && ch != EOF);

			//从链表中删除学生信息
			Deletenode_byid(List,tempData.id);
			//将剩余信息保存到文件
			saveToFile("student.txt",List);
			
			break;
		}
	case 2:
		{
			printf("\n\t\t\t请输入要删除的学生的姓名:");

			scanf("%s",tempData.name);
			while((ch = getchar()) != '\n' && ch != EOF);

			Deletenode_byname(List,tempData.name);
			saveToFile("student.txt",List);
			break;
		}
	default:
		{
			printf("\n\t\t\t\t输入错误！请重新输入！\n");
			break;
		}
	}
}
//排序
void sortStudent()
{
	printf("\n\t\t\t---------------排序学生信息--------------\n");
	printf("\t\t\t\t1.根据学号排序(从低到高)\n");
	printf("\t\t\t\t2.根据数学成绩排序(从高到低)\n");
	printf("\t\t\t\t3.根据英语成绩排序(从高到低)\n");
	printf("\t\t\t\t4.根据总成绩排序(从高到低)\n");
	printf("\t\t\t\t请选择功能(1-4):");

	//获取选择
	int choice = 0;
	scanf("%d",&choice);
	//清除缓冲区
	char ch;
	while((ch = getchar()) != '\n' && ch != EOF);

	switch(choice)
	{
	case 1:
		{
			//按学号从低到高排序链表
			sortList_byid(List);
			//将排序后的信息保存到文件
			saveToFile("student.txt",List);
			//打印链表中的信息
			printList(List);
			break;
		}
	case 2:
		{
			//按数学成绩从高到低排序链表
			sortList_bymath(List);
			printList(List);
			break;
		}
	case 3:
		{
			//按英语成绩从高到低排序链表
			sortList_byenglish(List);
			printList(List);
			break;
		}
	case 4:
		{
			//按总成绩从高到低排序链表
			sortList_bysumscore(List);
			printList(List);
			break;
		}
	default:
		{
			printf("\n\t\t\t\t输入错误！请重新输入！\n");
			break;
		}
	}
}
