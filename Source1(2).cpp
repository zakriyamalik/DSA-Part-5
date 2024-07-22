//#include <iostream>
//#include <vector>
//#include <ctime>
//
//using namespace std;
//vector<vector<int>> initialize2DVector(int rows, int cols, int initialValue) {
//    return vector<vector<int>>(rows, vector<int>(cols, initialValue));
//}
//
//void insertValueInto2DVector(vector<vector<int>>& my2DVector, int row, int col, int value) {
//    if (row >= 0 && row < my2DVector.size() && col >= 0 && col < my2DVector[0].size()) {
//        my2DVector[row][col] = value;
//    }
//    else {
//        cerr << "Error: Invalid row or column index." << endl;
//    }
//}
//
//void bubbleSort2DVector(vector<vector<int>>& my2DVector) {
//    clock_t start_time = clock();
//    int rows = my2DVector.size();
//    int cols = my2DVector[0].size();
//
//    for (int r = 0; r < rows; ++r) {
//        for (int i = 0; i < cols - 1; ++i) {
//            for (int j = 0; j < cols - i - 1; ++j) {
//                if (my2DVector[r][j] > my2DVector[r][j + 1]) {
//                 
//                    int temp = my2DVector[r][j];
//                    my2DVector[r][j] = my2DVector[r][j + 1];
//                    my2DVector[r][j + 1] = temp;
//                }
//            }
//        }
//    }
//
//    clock_t end_time = clock();
//    double elapsed_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
//    cout << "Sorting time: " << elapsed_time << " seconds" << endl;
//}
//
//void display2DVector(vector<vector<int>>& my2DVector) {
//    int rows = my2DVector.size();
//    int cols = my2DVector[0].size();
//
//    for (int r = 0; r < rows; ++r) {
//        for (int c = 0; c < cols; ++c) {
//            cout << my2DVector[r][c] << " ";
//        }
//        cout << endl;
//    }
//}
//int Search(vector<vector<int>>& my2DVector, int value) {
//    clock_t start_time = clock();
//    int rows = my2DVector.size();
//    int cols = my2DVector[0].size();
//
//    for (int r = 0; r < rows; ++r) {
//        for (int c = 0; c < cols; ++c) {
//            if (my2DVector[r][c] == value) {
//                clock_t end_time = clock();
//                double elapsed_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
//                cout << "Search time: " << elapsed_time << " seconds" << endl;
//                return value;
//            }
//        }
//    }
//
//    clock_t end_time = clock();
//    double elapsed_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
//    cout << "Search time: " << elapsed_time << " seconds" << endl;
//    return -1; 
//}
//
//int main() {
//    int rows = 3;
//    int cols = 4;
//    int initialValue = 0;
//    vector<vector<int>> my2DVector = initialize2DVector(rows, cols, initialValue);
//
//    insertValueInto2DVector(my2DVector, 1, 2, 42);
//    insertValueInto2DVector(my2DVector, 2, 3, 5);
//
//    cout << "2D Vector contents before sorting:" << endl;
//    display2DVector(my2DVector);
//
//    bubbleSort2DVector(my2DVector);
//
//    cout << "2D Vector contents after sorting:" << endl;
//    display2DVector(my2DVector);
//
//    int search_value = 42;
//    int result = Search(my2DVector, search_value);
//    if (result != -1) {
//        cout << "Found " << search_value << " in the 2D Vector." << endl;
//    }
//    else {
//        cout << search_value << " not found in the 2D Vector." << endl;
//    }
//
//    return 0;
//}
