#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

bool IsValidSudoku(const vector<vector<int> >& partial_assignment) {

	for (int i = 0; i < size(partial_assignment); i++) {
		if (HasDuplicate(partial_assignment, i, i + 1, 0, size(partial_assignment)) {
			return false;
		}
	}

	for (int j = 0; j < size(partial_assignment); j++) {
		if (HasDuplicate(partial_assignment, 0, size(partial_assignment), j, j + 1)) {
			return false;
		}
	}

	int region_size = sqrt(size(partial_assignment));
	for (int I = 0; I < region_size; I++) {
		for (int J = 0; J < region_size; J++) {
			if (HasDuplicate(partial_assignment, region_size * I, region_size * (I + 1), region_size * J, region_size * (J + 1))) {
				return false;
			}
		}
	}
	return true;
}

bool HasDuplicate(const vector<vector<int> >& partial_assignment, int start_row, int end_row, int start_col, int end_col) {
	deque<bool> is_present(size(partial_assignment) + 1, false);
	for (int i = start_row; i < end_row; i++) {
		for (int j = start_col; j < end_col; j++) {
			if (partial_assignment[i][j] != 0 &&
				is_present[partial_assignment[i][j]]) {
				return true;
			}
			is_present[partial_assignment[i][j]] = true;
		}
	}
	return false;
}