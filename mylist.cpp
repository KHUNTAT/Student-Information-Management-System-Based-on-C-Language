#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "mylist.h"

//����һ���б�ͷ����
struct Node *creatList()
{
	//�б�ͷ������һ����㲻�������
	//�ޱ�ͷ������һ�����������
	//����һ���ṹ�����
	struct Node *StudentListhead;
	//Ϊ�䶯̬�����ڴ�
	//���������ϵͳ�Զ�����
	StudentListhead=(struct Node*)malloc(sizeof(struct Node));
	//��ʼ��
	StudentListhead->next =NULL;

	return StudentListhead;
}
//����һ���½��
struct Node *creatnode(struct student data)
{
	//�½�㶯̬�����ڴ�
	//���������ϵͳ�Զ�����
	struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));

	newnode->data = data;
	newnode->next=NULL;

	return newnode;
}
//�����½��:¼����Ϣ
void insertnode(struct Node *StudentListhead,struct student data)
{
	//����creatnode()����ֵ
	struct Node *newnode=creatnode(data);

	//ʹ��ͷ�巨���½�����������
	newnode->next=StudentListhead->next;
	StudentListhead->next=newnode;
}
//��ѧ��ɾ��ѧ����Ϣ
void Deletenode_byid(struct Node *StudentListhead,char *id)
{
	//����ǰ�ý�㲢ָ��ͷ���
	struct Node *posFrontNode=StudentListhead;
	//����һ��λ�ý�㲢ָ��ͷ������һ�����
	struct Node *posNode=StudentListhead->next;

	if(posNode==NULL)//��λ�ý��ΪNULL��������Ϊ��ʱ
	{
		printf("\n\t\t\t\t��������ݣ��޷�ɾ��!\n");
		return;
	}
	else
	{
		//������Ϊ�գ�ѭ����������Ҫɾ����ѧ��
		while(strcmp(posNode->data.id,id))
		{
			posFrontNode=posNode;
			posNode= posFrontNode->next;

			if(posNode == NULL)//δ�ҵ����ѧ��
			{
				printf("\n\t\t\t\t��������ݣ��޷�ɾ��!\n");
				return;
			}
		}
		//���ҵ�����ɾ�����ѧ��
		posFrontNode->next=posNode->next;
		free(posNode);
		printf("\n\t\t\t\tɾ���ɹ���\n");
	}
}
//������ɾ��ѧ����Ϣ
void Deletenode_byname(struct Node *StudentListhead,char *name)
{
	//����ǰ�ý�㲢ָ��ͷ���
	struct Node *posFrontNode=StudentListhead;
	//����һ��λ�ý�㲢ָ��ͷ������һ�����
	struct Node *posNode=StudentListhead->next;

	if(posNode==NULL)//��λ�ý��ΪNULL��������Ϊ��ʱ
	{
		printf("\n\t\t\t\t��������ݣ��޷�ɾ��!\n");
		return;
	}
	else
	{
		while(strcmp(posNode->data.name,name))
		{
			posFrontNode=posNode;
			posNode= posFrontNode->next;
			if(posNode == NULL)
			{
				printf("\n\t\t\t\t��������ݣ��޷�ɾ��!\n");
				return;
			}
		}
		posFrontNode->next=posNode->next;
		free(posNode);
		printf("\n\t\t\t\tɾ���ɹ���\n");
	}
}
//��ѧ�Ų���ѧ��
struct Node *searchnode_byid(struct Node *StudentListhead,char *id)
{
	//�����ƶ���㲢ָ��ͷ������һ�����
	struct Node *pmove=StudentListhead->next;

	if(pmove==NULL)//����Ϊ��
	{
		return pmove;
	}
	else
	{
		//������Ϊ�գ�ѭ����������ѧ��
		while(strcmp(pmove->data.id,id))
		{
			pmove=pmove->next;
			
			//��δ�鵽
			if(pmove==NULL)
			{
				break;
			}
		}
		return pmove;
	}
}
//����������ѧ��
struct Node *searchnode_byname(struct Node *StudentListhead,char *name)
{
	struct Node *pmove=StudentListhead->next;
	if(pmove==NULL)
	{
		return pmove;
	}
	else
	{
		while(strcmp(pmove->data.name,name))
		{
			pmove=pmove->next;
			if(pmove==NULL)
			{
				break;
			}
		}
		return pmove;
	}
}
//��ӡ���ҵ�ѧ����Ϣ
void printsearch(struct Node *curnode/*��ǰ���*/)
{
	printf("\tѧ��\t\t����\t�Ա�\t����\t�����ɼ�\tӢ��ɼ�\t�ɼ��ܺ�\n");
	printf("\t%-10s\t%-4s\t%-6s\t%-3d\t%.1f\t\t%.1f\t\t%.1f\n",curnode->data.id,curnode->data.name,curnode->data.gender,curnode->data.age,curnode->data.math,curnode->data.english,curnode->data.sumscore);
}
//��ӡѧ����Ϣ
void printList(struct Node *StudentListhead)
{
	struct Node *pmove=StudentListhead->next;

	//����ʽ��ӡ
	printf("\tѧ��\t\t����\t�Ա�\t����\t�����ɼ�\tӢ��ɼ�\t�ɼ��ܺ�\n");

	while(pmove)//pmoveΪNULLʱ���˳�ѭ��
	{
		//��ʽ�������ӡ
		printf("\t%-10s\t%-4s\t%-6s\t%-3d\t%.1f\t\t%.1f\t\t%.1f\n",pmove->data.id,pmove->data.name,pmove->data.gender,pmove->data.age,pmove->data.math,pmove->data.english,pmove->data.sumscore);
		//pmoveָ����һ����㣬�Դ˱�������
		pmove=pmove->next;
	}
	printf("\n");
}
//����ѧ������
void sortList_byid(struct Node *StudentListhead)
{
	//������ʱ�ṹ�����
	struct student temp;
	//����ǰ�ý�㲢ָ��ͷ���
	struct Node *posFrontNode=StudentListhead;
	//����һ��λ�ý�㲢ָ��ͷ������һ�����
	struct Node *posNode=StudentListhead->next;

	if(posNode==NULL)//��λ�ý��ΪNULL��������Ϊ��ʱ
	{
		printf("\n\t\t\t\t��������ݣ��޷�����!\n");
		return;
	}
	//��������
	while(posNode!=NULL)
	{
		while(posNode->next != NULL)
		{
			if(strcmp(posNode->data.id,posNode->next->data.id) > 0)//��ѧ�Ŵӵ͵�������
			{
				temp=posNode->data;
				posNode->data=posNode->next->data;
				posNode->next->data=temp;
			}
			posNode=posNode->next;
		}
		posNode=posFrontNode->next;
		posFrontNode=posNode;
	}

}
//������ѧ�ɼ�����
void sortList_bymath(struct Node *StudentListhead)
{
	struct student temp;
	struct Node *posFrontNode=StudentListhead;
	struct Node *posNode=StudentListhead->next;
	if(posNode==NULL)
	{
		printf("\n\t\t\t\t��������ݣ��޷�����!\n");
		return;
	}
	while(posNode!=NULL)
	{
		while(posNode->next != NULL)
		{
			if(posNode->data.math < posNode->next->data.math)
			{
				temp=posNode->data;
				posNode->data=posNode->next->data;
				posNode->next->data=temp;
			}
			posNode=posNode->next;
		}
		posNode=posFrontNode->next;
		posFrontNode=posNode;
	}

}
//����Ӣ��ɼ�����
void sortList_byenglish(struct Node *StudentListhead)
{
	struct student temp;
	struct Node *posFrontNode=StudentListhead;
	struct Node *posNode=StudentListhead->next;
	if(posNode==NULL)
	{
		printf("\n\t\t\t\t��������ݣ��޷�����!\n");
		return;
	}
	while(posNode!=NULL)
	{
		while(posNode->next != NULL)
		{
			if(posNode->data.english < posNode->next->data.english)
			{
				temp=posNode->data;
				posNode->data=posNode->next->data;
				posNode->next->data=temp;
			}
			posNode=posNode->next;
		}
		posNode=posFrontNode->next;
		posFrontNode=posNode;
	}

}
//�����ܳɼ�����
void sortList_bysumscore(struct Node *StudentListhead)
{
	struct student temp;
	struct Node *posFrontNode=StudentListhead;
	struct Node *posNode=StudentListhead->next;
	if(posNode==NULL)
	{
		printf("\n\t\t\t\t��������ݣ��޷�����!\n");
		return;
	}
	while(posNode!=NULL)
	{
		while(posNode->next != NULL)
		{
			if(posNode->data.sumscore < posNode->next->data.sumscore)
			{
				temp=posNode->data;
				posNode->data=posNode->next->data;
				posNode->next->data=temp;
			}
			posNode=posNode->next;
		}
		posNode=posFrontNode->next;
		posFrontNode=posNode;
	}

}
//���ļ��ж�ȡѧ����Ϣ
void readFromFile(char *File_student,struct Node *StudentListhead)
{
	//�����ļ�ָ�벢ָ��һ���ļ�
	FILE *fpstu=fopen(File_student,"r");
	//��������ڸ��ļ������´���
	if(fpstu==NULL)
	{
		fpstu=fopen(File_student,"w");
	}

	//��ʱ����
	struct student tempData = {"0","0","0",0,0.0,0.0,0.0};

	//�����ļ�
	while(fscanf(fpstu,"%s\t%s\t%s\t%d\t%f\t\t%f\t\t%f\n",tempData.id,
		tempData.name,tempData.gender,&tempData.age,&tempData.math,&tempData.english,&tempData.sumscore)!=EOF)
	{
		//��ѧ����Ϣ���뵽����
		insertnode(StudentListhead,tempData);
	}
	//�ر��ļ�
	fclose(fpstu);
}
//��ѧ����Ϣ�����ļ�
void saveToFile(char *File_student,struct Node *StudentListhead)
{
	//�����ļ�ָ�벢ָ��һ���ļ�
	FILE *fpstu=fopen(File_student,"w");
	//������ʱ���ָ��
	struct Node *pmove=StudentListhead->next;

	while(pmove)//��������
	{
		//��������ѧ����Ϣ�洢���ļ���
		fprintf(fpstu,"%s\t%s\t%s\t%d\t%.1f\t\t%.1f\t\t%.1f\n",pmove->data.id,
			pmove->data.name,pmove->data.gender,pmove->data.age,pmove->data.math,pmove->data.english,pmove->data.sumscore);
		pmove=pmove->next;
	}
	//�ر��ļ�
	fclose(fpstu);
}