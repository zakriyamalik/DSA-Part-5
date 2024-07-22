//#include <iostream>
//using namespace std;
//
//template <class H>
//struct hash_i
//{
//public:
//    int key;
//    H value;
//    int status;
//
//    hash_i()
//    {
//        key = 0;
//        value = H();
//        ststus = 0;
//    }
//};
//
//template <class H>
//class hash_map
//{
//private:
//    hash_i<H>* hash_arr;
//    int cap;
//    int current_size;
//
//    int getNextCandidateIndex(int key, int i) 
//    {
//        return (hashFunction(key) + i) % cap;
//    }
//
//public:
//    hash_map(int capacity) 
//    {
//        cap = capacity;
//        current_size = 0;
//        hash_arr = new hash_i<H>[cap];
//    }
//
//    void insert(hash_i<H> i_)
//    {
//        if (current_size == cap) {
//            cout << "Hash table is full. Cannot insert more elements." << endl;
//            return;
//        }
//
//        int i = 0;
//        int ind = hashFunction(i_.key);
//        while (hash_arr[ind].status == 2) 
//        {
//            i++;
//            ind = getNextCandidateIndex(i_.key, i);
//        }
//        hash_arr[ind] = i_;
//        hash_arr[ind].status = 2;
//        current_size++;
//    }
//
//    bool deletei_(hash_i<H> curr_i_)
//    {
//        int i = 0;
//        int ind = hashFunction(curr_i_.key);
//
//        while (hash_arr[ind].status != 0) 
//        {
//            if (hash_arr[ind].status == 2 && hash_arr[ind].key == curr_i_.key)
//            {
//                hash_arr[ind].status = 1;
//                current_size--;
//                return true;
//            }
//
//            i++;
//            ind = getNextCandidateIndex(curr_i_.key, i);
//        }
//        return false;
//    }
//
//    bool search(hash_i<H> obj, int& iter) 
//    {
//        int i = 0;
//        int index = hashFunction(obj.key);
//
//        while (hash_arr[index].status != 0)
//        {
//            iter++;
//            if (hash_arr[index].status == 2 && hash_arr[index].key == obj.key) 
//            {
//                return true;
//            }
//            i++;
//            index = getNextCandidateIndex(obj.key, i);
//        }
//        return false;
//    }
//    int hashFunction(int key)
//    {
//        return key % cap;
//    }
//    void printHashTable() 
//    {
//        cout << "hash table: ";
//        for (int i = 0; i < cap; ++i) {
//            if (hash_arr[i].status == 2) {
//                cout << "[" << hash_arr[i].key << ":" << hash_arr[i].value << "] ";
//            }
//            else {
//                cout << "empty ";
//            }
//        }
//        cout << endl;
//    }
//    ~hash_map()
//    {
//        delete[] hash_arr;
//    }
//};
//
//int main() {
//   
//    hash_map<string> h_Table(12);
//    hash_i<string> i_2, i_4, i_6, i_8, i_10, i_12, i_14, i_16, i_18, i_48, i_24;
//    i_2.key = 2;
//    i_2.value = "Value2";
//    h_Table.insert(i_2);
//    i_4.key = 4;
//    i_4.value = "Value4";
//    h_Table.insert(i_4);
//    i_6.key = 6;
//    i_6.value = "Value6";
//    h_Table.insert(i_6);
//    i_8.key = 8;
//    i_8.value = "Value8";
//    h_Table.insert(i_8);
//    i_10.key = 10;
//    i_10.value = "Value10";
//    h_Table.insert(i_10);
//    i_12.key = 12;
//    i_12.value = "Value12";
//    h_Table.insert(i_12);
//    i_14.key = 14;
//    i_14.value = "Value14";
//    h_Table.insert(i_14);
//    i_16.key = 16;
//    i_16.value = "Value16";
//    h_Table.insert(i_16);
//    i_18.key = 18;
//    i_18.value = "Value18";
//    h_Table.insert(i_18);
//    i_48.key = 48;
//    i_48.value = "Value48";
//    h_Table.insert(i_48);
//    i_24.key = 24;
//    i_24.value = "Value24";
//    h_Table.insert(i_24);
//    h_Table.printHashTable();
//    int searchIterations = 0;
//    if (h_Table.search(i_48, searchIterations)) 
//    {
//        cout << "Key 48 found. Search iterations: " << searchIterations << endl;
//    }
//    else 
//    {
//        cout << "Key 48 not found." << endl;
//    }
//
//    int deleteIterations48 = 0;
//    if (h_Table.deletei_(i_48)) 
//    {
//        cout << "Key 48 deleted. Deletion iterations: " << deleteIterations48 << endl;
//    }
//    else 
//    {
//        cout << "Key 48 not found for deletion." << endl;
//    }
//
//    int deleteIterations4 = 0;
//    if (h_Table.deletei_(i_4)) 
//    {
//        cout << "Key 4 deleted. Deletion iterations: " << deleteIterations4 << endl;
//    }
//    else 
//    {
//        cout << "Key 4 not found for deletion." << endl;
//    }
//   h_Table.printHashTable();
//  hash_map<string> hashTable2(24);
//    hashTable2.insert(i_2);
//    hashTable2.insert(i_4);
//    hashTable2.insert(i_6);
//    hashTable2.insert(i_8);
//    hashTable2.insert(i_10);
//    hashTable2.insert(i_12);
//    hashTable2.insert(i_14);
//    hashTable2.insert(i_16);
//    hashTable2.insert(i_18);
//    hashTable2.insert(i_48);
//    hashTable2.insert(i_24);
//
//    cout << "New Hash Table with double capacity: ";
//    hashTable2.printHashTable();
//
//    return 0;
//}