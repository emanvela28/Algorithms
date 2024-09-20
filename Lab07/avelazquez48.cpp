#include <iostream>
#include <list>
#include <vector>
using namespace std;

class HashTable {
    private:
    vector<list<int>> table;
    int hashSize;

    int hash (int key) {
        return key % hashSize;
    }

public: 
    HashTable (int size) : hashSize(size) {
        table.resize(hashSize);
    }

    void insert (int key) {
        int index = hash(key);
        table[index].push_front(key);
    }

    void remove (int key) {
        int index = hash(key);
        bool found = false;

        for (auto it = table[index].begin(); it != table[index].end(); it++) {
            if (*it == key) {
                table[index].erase(it);
                cout << key << ":DELETED;" << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << key << ":DELETE_FAILED;" << endl;
        }
    }

    void search (int key) {
        int index = hash(key);
        int position = 0;
        for (auto it = table[index].begin(); it != table[index].end(); it++, ++position) {
             if (*it == key) {
                cout << key << ":FOUND_AT" << index << "," << position << ";" << endl;
                return;
             }
        }

        cout << key << ":NOT_FOUND;" << endl;
    }

    void output() {
        for (int i = 0; i < hashSize; i++) {
            cout << i << ":";
            for (auto it = table[i].begin(); it != table[i].end(); ++it) {
                cout << *it << "->";
            }

            cout << ";" << endl;
        }
    }
};

int main(int argc, char const *argv[]) {

  int hashSize;
  int number =  0;
  bool repeat = true;

  string input = "";
  cin >> hashSize;
  HashTable ht(hashSize); // Ensure this line is adjusted as per your requirements

  do{
      number = 0;
      cin >> input;
      if (input[0] != 'o' || input[0] != 'e'){
        for (int i = 1; i < input.size(); i++){
          int digit = input[i] - '0';
          number = 10 * number + digit;
        }
      }

      if(input[0] == 'i'){
        ht.insert(number);
      }else if(input[0] == 'd'){
        ht.remove(number);
      }else if(input[0] == 's'){
        ht.search(number);
      }else if(input[0] == 'o'){
        ht.output();
      }else if(input[0] == 'e'){
        repeat = false;
      }else{
        cout << "Wrong input" << endl;
      }
  }while(repeat);

  return 0;
}