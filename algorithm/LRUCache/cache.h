#ifndef CACHE_H_
#define CACHE_H_

#include <iostream>
#include <map>
#include <list>
#include <string>
#include <unordered_map>

using namespace std;

template<typename T1>;

template<typename T2>;

struct record{
    T1 key;
    T2 value;
    record(){}
    record(T1 k1, T2 v1):key(k1),value(v1){}
};

class LRUCACHE{
private:
    int MaxSize;
    int CurrentSize;
    list<record> CacheList;
    unordered_map<T1, list<record>::iterator> Records;
    void MoveToHead(list<record>::iterator it){};
    void RemoveLast(list<record>::iterator it){};
public:
    LRUCACHE(int x){};
    T2 Get(T1 key){};
    void ClearCache(){};
    void Set(T1 key, T2 value){};
};

#endif
