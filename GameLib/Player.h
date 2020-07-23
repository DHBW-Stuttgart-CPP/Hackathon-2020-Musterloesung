//
// Created by bened on 23.07.2020.
//

#ifndef HACKATHON_PLAYER_H
#define HACKATHON_PLAYER_H

#include <string>
#include "GameDecision.h"
#include <memory>

class GameField;

class Player {
public:
	Player(const std::string &name, const int &id, const BoardSides &startSide);

	std::string getName() const;
	int getID() const;
    BoardSides getStartSide() const;

	virtual std::shared_ptr<GameDecision> getGameDecision(std::shared_ptr<GameField const> gameField) = 0;

private:
	std::string name;
	int id;
    BoardSides startSide;
};


#endif //HACKATHON_PLAYER_H
