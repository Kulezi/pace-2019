/**
 * CliqueSolverAdapter.h
 *
 * Copyright (C) 2019 Demian Hespe <hespe@kit.edu>
 *****************************************************************************/

#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <filesystem>
#include <fstream>
std::vector<int> solveMISInstanceWithCliqueSolver(std::vector<std::vector<int>> &MISInstance, long limit, bool docheck=false) {
    int n = MISInstance.size();
    std::vector<std::vector<int>> g(n, std::vector<int>(n, 1));
    for (int i = 0; i < n; i++) {
        g[i][i] = 0;
        for (auto j : MISInstance[i]) {
            g[i][j] = g[j][i] = 0;
        }
    }
    
    std::ofstream out("complement.lad");
    out << n << "\n";
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if(g[i][j])cnt++;
        }
        out << cnt << " ";
        for (int j = 0; j < n; j++) {
            if (g[i][j]) out << j << " ";
        }
        out << "\n";
    }

    system("./cliquesolver complement.lad > output.clq");

    std::vector<int> solution;

    return solution;
}
