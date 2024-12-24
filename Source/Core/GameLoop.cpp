#include "../../Header/Core/GameLoop.h"

using namespace Core;

void GameLoop::initialize()
{
	game_window_manager = new GameWindowManager();
	event_manager = new EventManager();

	game_window_manager->initialize();

	gameplay_manager = new GameplayManager();
}

bool GameLoop::isGameRunning()
{
	return game_window_manager->isGameRunning();
}

void GameLoop::pollEvent()
{
	event_manager->pollEvents(game_window_manager->getGameWindow());
}

void GameLoop::update()
{
}

void GameLoop::render()
{
	game_window_manager->clearWindow();
	gameplay_manager->render(game_window_manager->getGameWindow());
	game_window_manager->displayWindow();
}
