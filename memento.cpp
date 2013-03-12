#include "stdafx.h"
#include "memento.h"

void egMemento()
{
	CGame game;
	game.m_hp = 80;
	game.m_mp = 30;
	game.start_game();

	GameData save1 = game.save_game_data(); //保存数据
	game.restart_game(); 
	game.start_game();
	game.load_game_data(save1); //读入保存的进度(数据)
	game.start_game();

}