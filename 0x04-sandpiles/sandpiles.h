#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdio.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void print_grid_v2(int grid[3][3]);
void grid_3x3_sum(int grid1[3][3], int grid2[3][3]);
int check_stability(int grid[3][3]);
void distributes_grains(int grid1[3][3], int grid2[3][3]);

#endif /* SANDPILES_H */
