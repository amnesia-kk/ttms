#include "Sale_Perst.h"
#include "../Common/List.h"
#include "../Service/Sale.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/io.h>
#include <string.h>
#include "EntityKey_Persist.h"



//��������ָ�Ķ�����Ϣд����Ʊ�ļ��� 
int Sale_Perst_Insert (sale_t *data)//���Ϻ���Ƶ���������ͼ����Ӧ�����в��ֲ�ͬ���Ұ����ϵ�д�� 
{
	data.id=EntKey_Perst_GetNewKeys("sale");//���� 
	int rtn=0;
	FILE *fp;
	fp=fopen("Sale.dat","ab");
	if(fp==NULL)
	{
	   printf("fail to open file!");//���ļ�ʧ��
	   return 0;

	}
	
	rtn=fwrite(data,sizeof(sale_t),1,fp); 
		fclose(fp);
		return rtn;
}



//ʹ��data��Ʊ��״̬��Ϣ�޸������ļ���Ʊ��״̬ 
int Ticket_Perst_Update (const ticket_t *data){

	assert(NULL!=data);
    FILE *fp = fopen("Ticket.dat","rb+");
	if (NULL == fp) {

		printf("fail to open file!");//���ļ�ʧ��
		return 0;

	}

	ticket_t rec;
	int rtn = 0;

	while (!feof(fp)) {
		
		if (fread(&rec, sizeof(ticket_t), 1, fp)) {

			if (rec.id == data->id) {
				fseek(fp, -sizeof(ticket_t), SEEK_CUR);//fseek�ƶ��ļ��ĵ�ǰλ��ָ�룬SEEK_CUR��1��ʾ��ǰλ�ã���ʾָ�����һ����¼
				fwrite(data, sizeof(ticket_t), 1, fp);
				rtn = 1;
				break;

			}
		}
	}

	fclose(fp);
	return rtn;
}


//�����ݳ��ƻ�ID�����ݳ�Ʊ������ 
int Ticket_Perst_SelBySchID(int id,ticket_list_t list)//list���������ͷ��� 
{  
   int count=0;
   ticket_node_t data;
   List_Init(list,ticket_node_t);
   FILE* fp=fopen("Ticket.dat","rb");
   if(fp==NULL)
   {
   	 printf("fail to open file!");
	 return 0;
   }
   while(fread(data,sizeof(ticket_node_t),1,fp))
   {
   	if(data->schedule_id==id)
   	{  count++;
	   List_AddTail(list,data);
	   }
	} 
	fclose(fp);
	return count;
 } 
 
 
 
 
