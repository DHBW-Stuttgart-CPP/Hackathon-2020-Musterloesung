//
// Created by bened on 24.07.2020.
//

#ifndef HACKATHON_CONSOLEUI_H
#define HACKATHON_CONSOLEUI_H

#include "GameField.h"
#include "Ui.h"
#include <string>

enum class ConsoleColor
{
    Black,
    Red,
    Green,
    Yellow,
    Blue,
    Magenta,
    Cyan,
    White,
    Gray
};

class GamePrintTile
{
  public:
    std::string character = " ";
    ConsoleColor foregroundColor = ConsoleColor::Gray;

    void print();
};

class ConsoleUi : public Ui
{
  public:
    void drawGame(std::shared_ptr<const GameField> gameField) const override;
    void showWinnerMessage(std::shared_ptr<const PlayerData> player) const override;
    void showMessage(const std::string &message) const override;
    int showMultipleChoice(const std::string &message,
                           const std::vector<std::string> &answers) const override;
    int showMultipleIntChoice(const std::string &message, int minValue,
                              int maxValue) const override;

  private:
    void clearScreen() const;

    void drawGameRowColumnNumbers(std::shared_ptr<const GameField> gameField,
                                  std::vector<std::vector<GamePrintTile>> &output) const;

    void drawGameGrid(const std::shared_ptr<const GameField> &gameField,
                      std::vector<std::vector<GamePrintTile>> &output) const;

    void drawGamePlayers(const std::shared_ptr<const GameField> &gameField,
                         std::vector<std::vector<GamePrintTile>> &output) const;

    void drawGameHorizontalBorders(const std::shared_ptr<const GameField> &gameField,
                                   std::vector<std::vector<GamePrintTile>> &output) const;

    void drawGameVerticalBorders(const std::shared_ptr<const GameField> &gameField,
                                 std::vector<std::vector<GamePrintTile>> &output) const;

    void drawGameOutputToCout(std::vector<std::vector<GamePrintTile>> &output) const;

    std::vector<std::vector<GamePrintTile>> buildOutputBuffer(
        const std::shared_ptr<const GameField> &gameField) const;

    int fieldHeight = 1;
    int fieldWidth = 3;
    int firstColumnWidth = 4;
    int firstRowHeight = 2;
};

#endif // HACKATHON_CONSOLEUI_H
