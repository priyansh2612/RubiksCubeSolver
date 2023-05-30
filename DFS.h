//
// Created by Dell on 30-05-2023.
//

#ifndef RUBIKSCUBESOLVER_DFS_H
#define RUBIKSCUBESOLVER_DFS_H
#include<bits/stdc++.h>
#include "GenCube.h"


// Typename T: RubiksCube Representation used (3d, 1d, Bitboard)
// Typename H: Corresponding Hash function

template<typename T, typename H>
class DFSSolver {
private:

    vector<GenCube::MOVE> moves;
    int max_search_depth;

//    DFS code to find the solution (helper function)
    bool dfs(int dep) {
        if (rubiksCube.isSolved()) return true;
        if (dep > max_search_depth) return false;
        for (int i = 0; i < 18; i++) {
            rubiksCube.move(GenCube::MOVE(i));
            moves.push_back(GenCube::MOVE(i));
            if (dfs(dep + 1)) return true;
            moves.pop_back();
            rubiksCube.invert(GenCube::MOVE(i));
        }
        return false;
    }

public:
    T rubiksCube;

    DFSSolver(T _rubiksCube, int _max_search_depth = 8) {
        rubiksCube = _rubiksCube;
        max_search_depth = _max_search_depth;
    }

    vector<GenCube::MOVE> solve() {
        dfs(1);
        return moves;
    }

};
#endif //RUBIKSCUBESOLVER_DFS_H
