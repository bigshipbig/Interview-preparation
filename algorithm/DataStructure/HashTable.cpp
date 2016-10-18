typedef long long LL;

const int MAXN=1000010;  
const int HASH=1000007;  

class HashTable{
private:
    LL a[maxn];
    int head[maxn],next[maxn],size;
public;
    HashTable(){
        memset(head,-1,sizeof(head));
        size = 0;
    }
    bool Find(int val){
        int tmp = (val%HASH + HASH)%HASH;
        for(int i = head[tmp]; i != -1; i = next[i]){
            if(val == a[i])
                return true;
        }
        return false;
    }
    void Insert(int val){
        int tmp = (val%HASH + HASH)%HASH;
        if(Find(val)) return;
        a[size] = val;
        next[size] = head[tmp];
        head[tmp] = size++;
    }
};
