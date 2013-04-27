#include "StdAfx.h"
#include "GameData.h"


GameData::GameData(void)
{
	this->type=Empty;
}

GameData::~GameData(void)
{
}
GameData::GameData(GameData& d)
{
	GameDataType type=d.getType();
	if(type==Integer)
	{
		this->SetValue(d.toInt());
	}
	else if(type==Float)
	{
		this->SetValue(d.toFloat());
	}
	else if(type==String)
	{
		this->SetValue(d.toString());
	}	
	
}

GameData* GameData::getValue(wstring data)
{
	//递归出口
	//todo 可简化判断
	if(data.length()==0)
		return this;
	int i=data.find_first_of('.',0);
	if(i==-1)
	{
		map<std::wstring, GameData*>::iterator iter;
		iter=child.find(data);
		if(iter != child.end())
		{
			GameData* tmp=iter->second;
			return tmp->getValue(L"");
		}
	}
	else
	{
		wstring head=data.substr(0,i);
		wstring tail=data.substr(i+1,data.length());
		map<std::wstring, GameData*>::iterator iter;
		iter=child.find(head);
		if(iter != child.end())
		{
			GameData* tmp=iter->second;
			return tmp->getValue(tail);
		}
	}
	return NULL;

}

GameDataType GameData::getType()
{
	return this->type;
}

int GameData::toInt()
{
	//todo 空值的判断
	if(value==NULL)
		return NULL;
	if(type==Float)
		return (int)(*(float*) value);
	//todo 把可以转为int的string进行转换,如"123"
	else if(type==String)
	{
		wstring temp(*(wstring*)value);
		int i=_wtoi(temp.c_str());
		return i;
	}
	else
		return *(int*) value;
}
float GameData::toFloat()
{
	if(value==NULL)
		return NULL;
	//todo 空值的判断
	if(type==Integer)
		return (float)*(int*) value;
	//todo 把可以转为float的string进行转换,如"123.45"
	else if(type==String)
	{
		wstring temp(*(wstring*)value);
		float f=_wtof(temp.c_str());
		return f;
	}
	else
		return *(float*) value;
}
wstring GameData::toString()
{
	//todo 空值的判断
	if(value==NULL)
		return NULL;
	//todo 优化转换string算法，目前算法有可能造成内存泄露（未测试）
	if(type==Integer)
	{
		wstring str;
		wstringstream buffer;
		buffer<<*(int*)value;
		buffer>>str;
		return str;
	}
	else if(type==Float)
	{
		wstring str;
		wstringstream buffer;
		buffer<<*(float*)value;
		buffer>>str;
		return str;
	}
	else if(type==String)
		return *(wstring*)value;
	else
		return L"";
}
int GameData::SetValue(wstring value)
{
	Clear();
	this->value=new wstring(value);
	wstring* tmp=(wstring*) this->value;
	this->type=String;
	return RETURN_SUCCESS;
}
int GameData::SetValue(float value)
{
	Clear();
	this->value=(float*)malloc(sizeof(float));
	memcpy(this->value,&value,sizeof(float));
	this->type=Float;
	return RETURN_SUCCESS;
}
int GameData::SetValue(int value)
{
	Clear();
	this->value=malloc(sizeof(int));
	memcpy(this->value,&value,sizeof(int));
	this->type=Integer;
	return RETURN_SUCCESS;
}
void GameData::Clear()
{
	if(this->value==NULL)
		return;
	switch(type)
	{
	case Integer:{
		delete((int*)value);
		break;
				 }
	case Float:{
		delete((float*)value);
		break;}
	case String:{
		wstring* str=(wstring*)value;
		str->clear();
		free(str);
		break;}

	}
	this->type=Empty;
}

//todo 所有setvalue重载的优化,可考虑使用template或macro

int GameData::SetValue(int value,wstring path)
{
	if(path.length()==0)
	{	
		SetValue(value);
		return RETURN_SUCCESS;
	}
	int i=path.find_first_of('.',0);

	if(i==-1)
	{
		GameData* child=GetChild(path);
		if(child==NULL)
		{
			child=new GameData();
			this->child.insert(pair<wstring, GameData*>(path,child));

		}
		child->SetValue(value,L"");
	}
	else
	{
		wstring head=path.substr(0,i);
		wstring tail=path.substr(i+1,path.length());
		GameData* child=GetChild(head);
		if(child==NULL)
		{
			child=new GameData();
			this->child.insert(pair<wstring, GameData*>(head,child));

		}
		child->SetValue(value,tail);

	}
	return 0;
}
//todo 所有setvalue重载的优化,可考虑使用template或macro
int GameData::SetValue(float value,wstring path)
{
	if(path.length()==0)
	{	
		SetValue(value);
		return RETURN_SUCCESS;
	}
	int i=path.find_first_of('.',0);

	if(i==-1)
	{
		GameData* child=GetChild(path);
		if(child==NULL)
		{
			child=new GameData();
			this->child.insert(pair<wstring, GameData*>(path,child));

		}
		child->SetValue(value,L"");
	}
	else
	{
		wstring head=path.substr(0,i);
		wstring tail=path.substr(i+1,path.length());
		GameData* child=GetChild(head);
		if(child==NULL)
		{
			child=new GameData();
			this->child.insert(pair<wstring, GameData*>(head,child));

		}
		child->SetValue(value,tail);

	}
	return 0;
}
//todo 所有setvalue重载的优化,可考虑使用template或macro
int GameData::SetValue(wstring value,wstring path)
{
	if(path.length()==0)
	{	
		SetValue(value);
		return RETURN_SUCCESS;
	}
	int i=path.find_first_of('.',0);

	if(i==-1)
	{
		GameData* child=GetChild(path);
		if(child==NULL)
		{
			child=new GameData();
			this->child.insert(pair<wstring, GameData*>(path,child));

		}
		child->SetValue(value,L"");
	}
	else
	{
		wstring head=path.substr(0,i);
		wstring tail=path.substr(i+1,path.length());
		GameData* child=GetChild(head);
		if(child==NULL)
		{
			child=new GameData();
			this->child.insert(pair<wstring, GameData*>(head,child));

		}
		child->SetValue(value,tail);

	}
	return 0;
}
GameData* GameData::GetChild(wstring key)
{
	map<std::wstring, GameData*>::iterator iter;
	iter=child.find(key);
	if(iter != child.end())
		return iter->second;
	else return NULL;
}

//重載運算符
//重載"+"運算
GameData GameData::operator +(GameData &d)
{
	GameData gd;
	if(getType()==Integer)
		gd.SetValue(getValue(L"")->toInt()+d.getValue(L"")->toInt());	
	if(getType()==Float)
		gd.SetValue(getValue(L"")->toFloat()+d.getValue(L"")->toFloat());		
	if(getType()==String)
		gd.SetValue(getValue(L"")->toString()+d.getValue(L"")->toString());		
	return gd;
}

GameData GameData::operator +(int d)
{
	GameData gd;
	gd.SetValue(getValue(L"")->toInt()+d);	
	return gd;
}

GameData GameData::operator +(float d)
{
	GameData gd;
	gd.SetValue(getValue(L"")->toFloat()+d);	
	return gd;
}

GameData GameData::operator +(wstring d)
{
	GameData gd;
	gd.SetValue(getValue(L"")->toString()+d);	
	return gd;
}

//重載"-"運算
GameData GameData::operator -(GameData d)
{
	GameData gd;
	if(getType()==Integer)
		gd.SetValue(getValue(L"")->toInt()-d.getValue(L"")->toInt());	
	if(getType()==Float)
		gd.SetValue(getValue(L"")->toFloat()-d.getValue(L"")->toFloat());		
	if(getType()==String)
		gd.SetValue(getValue(L"")->toString());		
	return gd;
}

GameData GameData::operator -(int d)
{
	GameData gd;
	gd.SetValue(getValue(L"")->toInt()+d);	
	return gd;
}

GameData GameData::operator -(float d)
{
	GameData gd;
	gd.SetValue(getValue(L"")->toFloat()+d);	
	return gd;
}

GameData GameData::operator -(wstring d)
{
	GameData gd;
	gd.SetValue(d);	
	return gd;
}
GameData GameData::operator -(void)
{
	GameData tmp;
	tmp.SetValue(0);
	SetValue(tmp-*this);
	return tmp;
}

//重載"="運算
GameData GameData::operator =(GameData d)
{
	if(d.getType()==Integer)
		this->SetValue(d.getValue(L"")->toInt());
	if(d.getType()==Float)
		this->SetValue(d.getValue(L"")->toFloat());
	if(d.getType()==String)
		this->SetValue(d.getValue(L"")->toString());
	return *this;
}

GameData GameData::operator =(int d)
{
	this->SetValue(d);
	return *this;
}

GameData GameData::operator =(float d)
{
	this->SetValue(d);
	return *this;
}

GameData GameData::operator =(wstring d)
{
	this->SetValue(d);
	return *this;
}

int GameData::SetValue(GameData d)
{
	GameDataType type=d.getType();
	if(type==Integer)
		SetValue(d.toInt());
	else if(type==Float)
		SetValue(d.toFloat());
	else if(type==String)
		SetValue(d.toString());
	else if(type==Empty)
		return 0;

	return RETURN_SUCCESS;
}
int GameData::compareTo(GameData& d)			//GameData类之间的比较
{
	GameDataType type=this->getType();
	GameDataType typed=d.getType();

	if(type==Empty||typed==Empty)			//如果要比较的个值任何一个为空类型,则返回不相等
	{
		return -1;
	}
	else if((type==Integer||type==Float)&&(typed==Integer||typed==Float))			//如果个值都是int或者float,则转化为float之后进行比较
	{
		int t=this->toFloat()-d.toFloat();
		if(t>0)
			return 1;
		else if(t==0)
			return 0;
		else
			return -1;
	}
	else									//如果个值其中至少一个为string型,则另一个也转为string型进行比较
	{
		if(this->toString().compare(d.toString())==0)	
			return 0;
		else 
			return -1;
	}

}

void GameData::init( wstring path )
{
	if(path.length()==0)
	{	
		return ;
	}
	int i=path.find_first_of('.',0);

	if(i==-1)
	{
		GameData* child=GetChild(path);
		if(child==NULL)
		{
			child=new GameData();
			this->child.insert(pair<wstring, GameData*>(path,child));

		}
		child->init(L"");
	}
	else
	{
		wstring head=path.substr(0,i);
		wstring tail=path.substr(i+1,path.length());
		GameData* child=GetChild(head);
		if(child==NULL)
		{
			child=new GameData();
			this->child.insert(pair<wstring, GameData*>(head,child));

		}
		child->init(tail);

	}
}



