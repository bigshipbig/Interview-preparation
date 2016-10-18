#include "cache.h"

LRUCACHE::LRUCACHE(int x){
    MaxSize = x;
    CurrentSize = 0;
}

void LRUCACHE::MoveToHead(list<record>::iterator it){
    record NewRecord = *it;
    CacheList.erase(it);
    CacheList.push_front(NewRecord);
    return;
}

void LRUCACHE::RemoveLast(){
    Records.erase(CacheList.back().key);
    CacheList.pop_back();
    CurrentSize--;
    return;
}

T2 LRUCACHE::Get(T1 key){
    unordered_map<T1,list<record>::iterator > loc = Records.find(key);
    if(loc == Records.end()){
        return "No such record!"
    }
    else{
        list<record>::iterator it = Records[key];
        MoveToHead(it);
        Records[key] = CacheList.begin();
    }
    return CacheList.begin()->value;
};

void LRUCACHE::Set(T1 key,T2 value){
    unordered_map<T1,list<record>::iterator > loc = Records.find(key);
    if(loc == Records.end()){
        if(CurrentSize == MaxSize){
            RemoveLast();
        }
        CurrentSize++;
        record NewRecord=record(key,value);
        CacheList.push_front(NewRecord);
        Records[key]=CacheList.begin();
    }
    else{
        list<record>::iterator it = Records[key];
        MoveToHead(it);
        Records[key] = CacheList.begin();
    }
};

void LRUCACHE::ClearCache(){
    CurrentSize = 0;
    Records.clear();
    CacheList.clear();
};

