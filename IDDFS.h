//
// Created by Dell on 30-06-2023.
//

#ifndef RUBIKSCUBESOLVER_IDDFS_H
#define RUBIKSCUBESOLVER_IDDFS_H


#include<bits/stdc++.h>
#include "GenCube.h"
#include "DFS.h"



template<typename T, typename H>
class IDDFSSolver {

private:
    int max_search_depth;
    vector<GenCube::MOVE> moves;

public:
    T rubiksCube;

    IDDFSSolver(T _rubiksCube, int _max_search_depth = 7) {
        rubiksCube = _rubiksCube;
        max_search_depth = _max_search_depth;
    }

//    Used DFSSolver with increasing max_search_depth
    vector<GenCube::MOVE> solve() {
        for (int i = 1; i <= max_search_depth; i++) {
            DFSSolver<T, H> dfsSolver(rubiksCube, i);
            moves = dfsSolver.solve();
            if (dfsSolver.rubiksCube.isSolved()) {
                rubiksCube = dfsSolver.rubiksCube;
                break;
            }
        }
        return moves;
    }


};
#endif //RUBIKSCUBESOLVER_IDDFS_H
