#ifndef TICKET_PERSIST_H_
#define TICKET_PERSIST_H_

#include"../Service/Ticket_Ser.h"
#include"../Service/Schedule.h"
#include"../Service/Seat.h"
//int Schedule_Perst_SelectByID(int id,schedule_t *buf);   //  ���ļ�������ָ��id���ݳ��ƻ�


int  Ticket_Perst_Insert(seat_list_t list, int schedule_id);      //��Ʊ����Ϣ�ļ�ticket.dat ����������list����������Ʊ����Ϣ


int  Ticket_Perst_Rem(int schedule_id);    //����ɾ���ݳ��ƻ���id��

//int Ticket_Perst_SelBySchID(int ID,ticket_list_t list);


int Ticket_Perst_SelBySchID(int ID, ticket_list_t list);

int Ticket_Perst_SelByticketID(id, buf);

#endif
