
#ifndef HACKATHON_GAMEFIELD_H
#define HACKATHON_GAMEFIELD_H

#include "../Graph/Graph.h"
#include "Position.h"

#include <array>
#include <list>
#include <map>
#include <memory>
#include <string>

class PlayerData;

enum class BoardSides
{
    Left,
    Right,
    Top,
    Bottom,
};

class GameField
{
  public:
    GameField();
    virtual ~GameField();

    int getHeight() const;
    int getWidth() const;
    const Position &getPosition(Coordinate const &coordinates) const;
    bool isOpenBelowCoordinate(Coordinate const &coordinate) const;
    bool isOpenLeftOfCoordinate(Coordinate const &coordinate) const;
    bool isValidCoordinate(Coordinate const &coordinate) const;

    std::vector<std::shared_ptr<const PlayerData>> getAllPlayersOnField() const;

    std::shared_ptr<Coordinate const> getPlayerPosition(std::shared_ptr<PlayerData const> const &player) const;
    void setPlayerPosition(std::shared_ptr<PlayerData const> player, std::shared_ptr<Coordinate const> position);

    bool noBorderBetweenCoordinates(Coordinate const &a, Coordinate const &b) const;
    void setBorderBetweenCoordinates(Coordinate const &a, Coordinate const &b);

    const Combinatorics::Graph& getGraph() const;

  private:
    std::map<std::shared_ptr<PlayerData const>, std::shared_ptr<Coordinate const>> m_playerPositions;

    Position &getPosition(Coordinate const &coordinates);
    // Returns corresponding EdgeId and Graph::INVALID_EDGE_ID if edge is already removed
    Combinatorics::EdgeId getEdgeIdBetweenCoordinates(Coordinate const &a,
                                                      Coordinate const &b) const;
    Combinatorics::Edge const &getEdgeBetweenCoordinates(Coordinate const &a,
                                                         Coordinate const &b) const;
    Combinatorics::Edge &getEdgeBetweenCoordinates(Coordinate const &a, Coordinate const &b);

    //////////////////
    /// Most likely you do not have to touch this
    Combinatorics::Graph m_graph;
    static constexpr int s_width{9};
    static constexpr int s_height{9};
    std::array<std::array<std::unique_ptr<Position>, s_height>, s_width> m_field;

    const Position &at(int x, int y) const;
};

#endif
