#ifndef SCHEDULE_PERST_H
#define SCHEDULE_PERST_H
#include "Schedule_Srv.h"

//�������� �����ݳ��ƻ������ļ���������ָ����Ŀ�������ݳ��ƻ���Ϣ����������list��
int Schedule_Perst_SelectByPlay(schedule_list_t list, int play_id);


//�������� �����ݳ��ƻ��ļ�Schedule.dat��ĩβ���һ���µ��ݳ��ƻ�
int Schedule_Perst_Insert(schedule_t* data);


//�������� : �����ݳ��ƻ������ļ�Schedule.dat�е�һ���ݳ��ƻ���Ϣ��
int Schedule_Perst_Update(const schedule_t* data);


//�������� ��ȥ���ݳ��ƻ������ļ�Schedule.dat��ָ��ID���ݳ��ƻ�
int Schedule_Perst_RemByID(int id);


//�������ݳ��ƻ���Ϣ��������
int Schedule_Perst_SelectAll(schedule_list_t list);


//ͨ�����ƽ����������ľ�Ŀ��Ϣ������һ������
int Play_Perst_SelectByName(play_list_t list, char condt[]);

#endif // SCHEDULE_PERSIST_H
