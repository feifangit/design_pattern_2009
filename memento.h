#pragma once

typedef struct _GameData
{
	int hp; //ÑªÁ¿
	int mp; //Ä§·¨Öµ
	_GameData& operator=(const _GameData& other)
	{
		this->hp = other.hp;
		this->mp = other.mp;
		return *this;
	}
}GameData;

class CGame
{


public :
	int m_hp;
	int m_mp;
	GameData save_game_data()
	{
		GameData data;
		data.hp = m_hp;
		data.mp = m_mp;
		return data;
	}
	void load_game_data(const GameData& data )
	{
		m_hp = data.hp;
		m_mp = data.mp;
	}
	void start_game()
	{
		cout << "game start! hp: " << m_hp << " mp: " << m_mp << endl;
	}
	void restart_game()
	{
		m_hp = 0;
		m_mp = 0;
	}
};

void egMemento();