//#include <iostream>
//#include <string>
//using namespace std;
//template <class H>
//struct HashI
//{
//    int key;
//    H value;
//    int status;
//    HashI()
//    {
//        key = 0;
//        value = H();
//        status = 0;
//    }
//};
//
//template <class H>
//class hash_map 
//{
//private:
//    HashI<H>* h_arr;
//    int cap_arr;
//    int current_size;
//
//    int getNextCandidateIndex(int key, int i) 
//    {
//        return (hashFunction(key) + i) % cap_arr;
//    }
//
//public:
//    hash_map()
//    {
//        cap_arr = 10;
//        current_size = 0;
//        h_arr = new HashI<H>[cap_arr];
//    }
//
//    hash_map(int const cap)
//    {
//        cap_arr = cap;
//        current_size = 0;
//        h_arr = new HashI<H>[cap_arr];
//    }
//
//    
//    void insert(HashI<H> I)
//    {
//        if (current_size == cap_arr) 
//        {
//            cout << "Hash table is full. Cannot insert more elements." << endl;
//            return;
//        }
//
//        int i = 0;
//        int ind = hashFunction(I.key);
//
//        while (h_arr[ind].status == 2) 
//        {
//            i++;
//            ind = getNextCandidateIndex(I.key, i);
//        }
//
//        h_arr[ind] = I;
//        h_arr[ind].status = 2;
//        current_size++;
//    }
//
//    bool deleteI(HashI<H> I) 
//    {
//        int i = 0;
//        int ind = hashFunction(I.key);
//
//        while (h_arr[ind].status != 0) 
//        {
//            if (h_arr[ind].status == 2 && h_arr[ind].key == I.key) 
//            {
//                h_arr[ind].status = 1;
//                current_size--;
//                return true;
//            }
//
//            i++;
//            ind = getNextCandidateIndex(I.key, i);
//        }
//
//        return false; 
//    }
//
//    bool search(HashI<H> obj) 
//    {
//        int i = 0;
//        int ind = hashFunction(obj.key);
//
//        while (h_arr[ind].status != 0) 
//        {
//            if (h_arr[ind].status == 2 && h_arr[ind].key == obj.key) 
//            {
//                return true;
//            }
//            i++;
//            ind = getNextCandidateIndex(obj.key, i);
//        }
//
//        return false;
//    }
//
//    int hashFunction(int key)
//    {
//        return key % cap_arr;
//    }
//
//    void printHashTable() 
//    {
//        cout << "table is";
//        for (int i = 0; i < cap_arr; ++i) 
//        {
//            if (h_arr[i].status == 2) {
//               cout << "[" << h_arr[i].key << ":" << h_arr[i].value << "] ";
//            }
//            else {
//               cout << "empty";
//            }
//        }
//        cout << endl;
//    }
//    ~hash_map()
//    {
//        delete[] h_arr;
//    }
//};
//
//int main() 
//{
//
//    hash_map<string> HT(10);
//    HashI<string> I1;
//    HashI<string> I2;
//    HashI<string> I3;
//    HashI<string> I4;
//    HashI<string> I5;
//    HashI<string> I6;
//    HashI<string> I7;
//
//    I1.key = 1;
//    I1.value = "you";
//    HT.insert(I1);
//    I2.key = 11;
//    I2.value = "me";
//    HT.insert(I2);
//    I3.key = 21;
//    I3.value = "its";
//    HT.insert(I3);
//    HT.printHashTable();
//    I4.key = 2;
//    I4.value = "do";
//    HT.insert(I4);
//    I5.key = 12;
//    I5.value = "view";
//    HT.insert(I5);
//    HT.printHashTable();
//    I6.key = 11;
//    HT.deleteI(I6);
//    HT.printHashTable();
//    I7.key = 21;
//    if (HT.search(I7)) 
//    {
//        cout << "Found!" << endl;
//    }
//    else 
//    {
//        cout << "Not Found!" << endl;
//    }
//    return 0;
//}
