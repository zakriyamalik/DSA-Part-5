//#include <iostream>
//
//using namespace std;
//
//template <typename T>
//class Array {
//private:
//    T* arr;
//    int size;
//
//public:
//    Array(int size) {
//        this->size = size;
//        arr = new T[size];
//    }
//    Array(const Array& obj) {
//        size = obj.size;
//        arr = new T[size];
//        for (int i = 0; i < size; ++i) {
//            arr[i] = obj.arr[i];
//        }
//    }
//    void InsertElement(T value) {
//        for (int i = 0; i < size; ++i) {
//            if (arr[i] == 0) {
//                arr[i] = value;
//                return;
//            }
//        }
//    }
//    void BubbleSort(char mode = 'asc') {
//        for (int i = 0; i < size - 1; ++i) {
//            for (int j = 0; j < size - i - 1; ++j) {
//                if ((mode == 'asc' && arr[j] > arr[j + 1]) || (mode == 'desc' && arr[j] < arr[j + 1])) {
//                    T temp = arr[j];
//                    arr[j] = arr[j + 1];
//                    arr[j + 1] = temp;
//                }
//            }
//        }
//    }
//    Array<T> operator+(const Array& obj) {
//        if (size != obj.size) {
//            cerr << "Error: Arrays have mismatched sizes." << endl;
//            exit(1);
//        }
//        Array<T> result(size);
//        for (int i = 0; i < size; ++i) {
//            result.arr[i] = arr[i] + obj.arr[i];
//        }
//        return result;
//    }
//    T Search(T value) {
//        int left = 0;
//        int right = size - 1;
//        while (left <= right) {
//            int mid = left + (right - left) / 2;
//            if (arr[mid] == value) {
//                return arr[mid];
//            }
//            if (arr[mid] < value) {
//                left = mid + 1;
//            }
//            else {
//                right = mid - 1;
//            }
//        }
//        return static_cast<T>(-1);
//    }
//    ~Array() {
//        delete[] arr;
//    }
//    T& operator[](int index) {
//        if (index < 0 || index >= size) {
//            cerr << "Error: Index out of bounds." << endl;
//            exit(1);
//        }
//        return arr[index];
//    }
//};
//
//int main() {
//    int size = 5;
//    Array<int> arr1(size);
//    Array<int> arr2(size);
//
//    for (int i = 0; i < size; ++i) {
//        arr1.InsertElement(size - i);
//        arr2.InsertElement(i + 1);
//    }
//
//    cout << "Array 1 before sorting:" << endl;
//    for (int i = 0; i < size; ++i) {
//        cout << arr1[i] << " ";
//    }
//    cout << endl;
//
//    cout << "Array 2 before sorting:" << endl;
//    for (int i = 0; i < size; ++i) {
//        cout << arr2[i] << " ";
//    }
//    cout << endl;
//
//    arr1.BubbleSort('asc');
//    arr2.BubbleSort('desc');
//
//    cout << "Array 1 after sorting in ascending order:" << endl;
//    for (int i = 0; i < size; ++i) {
//        cout << arr1[i] << " ";
//    }
//    cout << endl;
//
//    cout << "Array 2 after sorting in descending order:" << endl;
//    for (int i = 0; i < size; ++i) {
//        cout << arr2[i] << " ";
//    }
//    cout << endl;
//
//    Array<int> arr3 = arr1 + arr2;
//
//    cout << "Array 3 (sum of Array 1 and Array 2):" << endl;
//    for (int i = 0; i < size; ++i) {
//        cout << arr3[i] << " ";
//    }
//    cout << endl;
//
//    int search_value = 3;
//    int result = arr1.Search(search_value);
//    if (result != -1) {
//        cout << "Found " << search_value << " in Array 1." << endl;
//    }
//    else {
//        cout << search_value << " not found in Array 1." << endl;
//    }
//
//    return 0;
//}
