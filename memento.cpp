#include "stdafx.h"
#include "memento.h"

void egMemento()
{
	CGame game;
	game.m_hp = 80;
	game.m_mp = 30;
	game.start_game();

	GameData save1 = game.save_game_data(); //��������
	game.restart_game(); 
	game.start_game();
	game.load_game_data(save1); //���뱣��Ľ���(����)
	game.start_game();

}