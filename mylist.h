//��������
#ifndef _MYLIST_H_//���û������ͷ�ļ�mylist.h
	#define _MYLIST_H_//�Ǿ�����ͷ�ļ�mylist.h

struct student//ѧ����Ϣ
{
	char id[15];
	char name[10];
	char gender[10];
	int age;
	float math;
	float english;
	float sumscore;
};
struct Node//������
{
	struct student data;
	struct Node *next;
};
//����һ���б�ͷ����
struct Node *creatList();
//����һ���½��
struct Node *creatnode(struct student data);
//�����½��:¼����Ϣ
void insertnode(struct Node *StudentListhead,struct student data);
//��ѧ��ɾ��ѧ����Ϣ
void Deletenode_byid(struct Node *StudentListhead,char *id);
//������ɾ��ѧ����Ϣ
void Deletenode_byname(struct Node *StudentListhead,char *name);
//��ѧ�Ų���ѧ��
struct Node *searchnode_byid(struct Node *StudentListhead,char *id);
//����������ѧ��
struct Node *searchnode_byname(struct Node *StudentListhead,char *name);
//��ӡ����
void printsearch(struct Node *curnode/*��ǰ���*/);
//��ӡѧ����Ϣ
void printList(struct Node *StudentListhead);
//����ѧ������
void sortList_byid(struct Node *StudentListhead);
//������ѧ�ɼ�����
void sortList_bymath(struct Node *StudentListhead);
//����Ӣ��ɼ�����
void sortList_byenglish(struct Node *StudentListhead);
//�����ܳɼ�����
void sortList_bysumscore(struct Node *StudentListhead);
//���ļ��ж�ȡѧ����Ϣ
void readFromFile(char *File_student,struct Node *StudentListhead);
//��ѧ����Ϣ�����ļ�
void saveToFile(char *File_student,struct Node *StudentListhead);

#endif