/********************************************************************
	created:	2011/05/09
	created:	9:5:2011   23:11
	filename: 	e:\Dev\c_plus_plus\cardgame\branches\axb\GameData\GameData\GameData.h
	file path:	e:\Dev\c_plus_plus\cardgame\branches\axb\GameData\GameData
	file base:	GameData
	file ext:	h
	author:		axb
	
	purpose:	保存游戏数据使用的抽象数据类
	对String，Float，Integer类型进行了包装，每个对象可取子节点，用带 '.'分隔的字符串进行取值和赋值
*********************************************************************/
#pragma once
#include <string>
#include <map>
#include <sstream>
#include "Commondef.h"

using namespace std;
enum GameDataType{
	Empty,Integer,Float,String//默认类型为empty,可选类型为Integer,Float,String
};
class GameData
{
public:
	GameData(void);//构造函数
	~GameData(void);//析构函数
	GameData(GameData &d);
	GameData* getValue(wstring data);//取值
	GameDataType getType();//取類型
	int toInt();//转换为int
	float toFloat();//转换为float
	wstring toString();//转换为string
	int SetValue(int value);//设置int值
	int SetValue(float value);//设置float值
	int SetValue(wstring value);//设置string值
	void Clear();//清除当前节点值
	int SetValue(int value,wstring path);//设置某路径节点的int值
	int SetValue(float value,wstring path);//设置某路径节点的float值
	int SetValue(wstring value,wstring path);//设置某路径节点的string值
	int SetValue(GameData d);
	void init(wstring path);
	GameData* GetChild(wstring key);//取子节点
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
	void *value;//保存节点值
	GameDataType type;//保存类型
	map<wstring,GameData*> child;//子节点映射map
};
