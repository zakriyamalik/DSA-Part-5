#include <iostream>
using namespace std;
template <typename K, typename V>
class Node 
{
public:
    K key;
    V value;
};
template <typename K, typename V>
class Heap 
{
public:
    Node<K, V>* arr;
    int cap;
    int total;
    Heap()
    {
        arr = nullptr;
        cap = 0;
        total = 0;
    }
    Heap(int capacity)
    {
        arr = new Node<K, V>[capacity];
        cap = capacity;
        total = 0;
    }
    void swap(Node<K, V>& a, Node<K, V>& b) 
    {
        Node<K, V> temp = a;
        a = b;
        b = temp;
    }
    int parent(int index)
    {
        return (index - 1) / 2;
    }
    int leftChild(int index)
    {
        return 2 * index + 1;
    }

    int rightChild(int index) 
    {
        return 2 * index + 2;
    }
    void heap_up(int ind) 
    {
        while (ind > 0 && arr[ind].key < arr[parent(ind)].key)
        {
            swap(arr[ind], arr[parent(ind)]);
            ind = parent(ind);
        }
    }
    void heap_down(int ind) 
    {
        int smallest = ind;
        int l_ind = leftChild(ind);
        int r_ind = rightChild(ind);

        if (l_ind < total && arr[l_ind].key < arr[smallest].key) 
        {
            smallest = l_ind;
        }

        if (r_ind < total && arr[r_ind].key < arr[smallest].key) 
        {
            smallest = r_ind;
        }

        if (smallest != ind)
        {
            swap(arr[ind], arr[smallest]);
            heap_down(smallest);
        }
    }
    void resize()
    {
        int new_cap = cap * 2;
        Node<K, V>* new_arr = new Node<K, V>[new_cap];
        for (int i = 0; i < total; ++i) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        cap = new_cap;
    }
    void insert(K key, V value)
    {
        if (total == cap)
        {
            resize();
        }
        arr[total].key = key;
        arr[total].value = value;
        heap_up(total);
        total++;
    }
    void decreaseKey(K key, V val)
    {
        int ind = -1;
        for (int i = 0; i < total; ++i)
        {
            if (arr[i].key == key)
            {
                arr[i].value = val;
                ind = i;
                break;
            }
        }

        if (ind != -1)
        {
          heap_up(ind);
        }
    }


  bool deleteKey(K key) 
  {
      int ind = -1;
      for (int i = 0; i < total; ++i) 
      {
          if (arr[i].key == key)
          {
              ind = i;
              break;
          }
      }
      if (ind == -1) 
      {
          return false;
      }
      swap(arr[ind], arr[total - 1]);
      total--;
      heap_down(ind);
      return true;
  }

  bool getMin(V& val) 
  {
      if (total == 0)
      {
          return false;
      }
      val = arr[0].value;
      return true;
  }

  bool deleteMin() 
  {
      if (total == 0)
      {
          return false;
      }
      swap(arr[0], arr[total - 1]);
      total--;
      heap_down(0);
      return true;
  }
    bool isEmpty()
    {
        return total == 0;
    }
    ~Heap() {
        delete[] arr;
    }
};

int main() {
  Heap<int, string> minHeap(5);

    minHeap.insert(1, "One");
    minHeap.insert(2, "Two");
    minHeap.insert(3, "three");
    minHeap.insert(4, "Four");
    string minimum_value;
    if (minHeap.getMin(minimum_value)) 
    {
        cout << "Min Value: " << minimum_value << endl;
    }

    minHeap.decreaseKey(2, "Zero");

    if (minHeap.deleteKey(4))
    {
        cout << "Key 4 deleted." << endl;
    }

    while (!minHeap.isEmpty()) 
    {
        string extractedValue;
       minHeap.getMin(extractedValue);
        if (minHeap.deleteMin()) 
        {
            cout << "Min Value Extracted: " << extractedValue << endl;
        }
    }
    return 0;
}
