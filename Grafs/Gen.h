#pragma once
#include "pch.h"
std::vector<std::pair<int, int>> gen(int amount);


void createR(std::vector<std::pair<int, int>> & relations, int nodes);
bool createN(std::vector<std::pair<int, int>> & relations, int node1, int node2);

bool exCheck(int value, const std::vector<int> & searched);

bool cycleCheckF(const std::vector<std::pair<int, int>> & relations);
bool cycleCheck(const std::vector<std::pair<int, int>> & relations, std::pair<int, int> first);
bool _cycleCheck(const std::vector<std::pair<int, int>> & relations, std::vector <int> searched, std::pair<int, int> first);

std::vector<std::pair<int, int>> cycleFind(const std::vector<std::pair<int, int>> & relations, int first);
std::vector<std::pair<int, int>> cycleSearch(const std::vector<std::pair<int, int>> & relations);

bool cycleExist(const std::vector<std::pair<int, int>> & relations, const std::vector<std::pair<int, int>> & nSearched, const std::vector <int> & searched);

std::vector<std::pair<int, int>> loadGraf(size_t & number);
