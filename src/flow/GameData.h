/********************************************************************
	created:	2011/05/09
	created:	9:5:2011   23:11
	filename: 	e:\Dev\c_plus_plus\cardgame\branches\axb\GameData\GameData\GameData.h
	file path:	e:\Dev\c_plus_plus\cardgame\branches\axb\GameData\GameData
	file base:	GameData
	file ext:	h
	author:		axb
	
	purpose:	������Ϸ����ʹ�õĳ���������
	��String��Float��Integer���ͽ����˰�װ��ÿ�������ȡ�ӽڵ㣬�ô� '.'�ָ����ַ�������ȡֵ�͸�ֵ
*********************************************************************/
#pragma once
#include <string>
#include <map>
#include <sstream>
#include "Commondef.h"

using namespace std;
enum GameDataType{
	Empty,Integer,Float,String//Ĭ������Ϊempty,��ѡ����ΪInteger,Float,String
};
class GameData
{
public:
	GameData(void);//���캯��
	~GameData(void);//��������
	GameData(GameData &d);
	GameData* getValue(wstring data);//ȡֵ
	GameDataType getType();//ȡ���
	int toInt();//ת��Ϊint
	float toFloat();//ת��Ϊfloat
	wstring toString();//ת��Ϊstring
	int SetValue(int value);//����intֵ
	int SetValue(float value);//����floatֵ
	int SetValue(wstring value);//����stringֵ
	void Clear();//�����ǰ�ڵ�ֵ
	int SetValue(int value,wstring path);//����ĳ·���ڵ��intֵ
	int SetValue(float value,wstring path);//����ĳ·���ڵ��floatֵ
	int SetValue(wstring value,wstring path);//����ĳ·���ڵ��stringֵ
	int SetValue(GameData d);
	void init(wstring path);
	GameData* GetChild(wstring key);//ȡ�ӽڵ�
	GameData GameData::operator +(GameData& d);
	GameData GameData::operator +(int d);
	GameData GameData::operator +(float d);
	GameData GameData::operator +(wstring d);
	GameData GameData::operator -(GameData d);
	GameData GameData::operator -(int d);
	GameData GameData::operator -(void);
	GameData GameData::operator -(float d);
	GameData GameData::operator -(wstring d);
	GameData GameData::operator =(GameData d);
	GameData GameData::operator =(int d);
	GameData GameData::operator =(float d);
	GameData GameData::operator =(wstring d);
	int GameData::compareTo(GameData& d);

private:
	void *value;//����ڵ�ֵ
	GameDataType type;//��������
	map<wstring,GameData*> child;//�ӽڵ�ӳ��map
};
