#pragma once
#ifndef CONNECT4HPP
#define CONNECT4HPP
#include <iostream>
#include <iomanip>
#include <string>
#define COLS_SIZE 6
#define ROWS_SIZE 7
#define EMPTY '_'

class Connect4
{
public:
    Connect4();
    ~Connect4();

private:
    bool PlayerDrop(int dropChoice, char activePLayer);//input of tile
    void DisplayBoard();//Display board
    void ResetBoard();
    bool WinCheck(char activePlayer);
    bool FullBoard();
    char static const PLAYER1 = 'X';
    char static const PLAYER2 = 'O';
public:
    struct Tile {
        Tile() {
            OwnerOfTile = 0;
            turnOfTile = 0;
            locOfTile = 0;
        }

        char ToactivePlayer() {
            if (this->OwnerOfTile == 1)
                return PLAYER1;
            if (this->OwnerOfTile == 2)
                return PLAYER2;
            //   if (this->OwnerOfTile == 0)
            return EMPTY;

        }

        void ToOwnerOfTile(char activePlayer) {
            if (activePlayer == PLAYER1)
                OwnerOfTile = 1;
            if (activePlayer == PLAYER2)
                OwnerOfTile = 2;
            if (activePlayer == EMPTY)
                OwnerOfTile = 0;
        }
        void SetLocation(int colmn,int row) {
            std::string strR,strC;
            strR=std::to_string(row);
            strC=std::to_string(colmn);
            strR=strR+strC;
            this->locOfTile=std::stoi(strR);
        }
        int GetLocation(){
            return locOfTile;
        }

        int locOfTile;
        int OwnerOfTile;
        int turnOfTile;
        //int winRatioOfTile;for expansion for more info on board **1
    };

private:
    Tile Board[COLS_SIZE][ROWS_SIZE];
    char static ToactivePlayer(Tile tile);
    friend class ML;
    typedef int defalut;
    int winner = -1;
    int turn = 1;

public:
    void SetTile(Tile New_tile, int col, int row);
    Tile GetTile(int col, int row);
    void SetWinner(int New_Winner);
    int  GetWinner();
    void SetTurn(int New_Turn);
    int  GetTurn();

    Connect4 play();
};
#endif
