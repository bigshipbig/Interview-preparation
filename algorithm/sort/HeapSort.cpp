const int maxn = 1e5+10;

class Heap{
private:
    int heap[maxn];
    int SortedHeap[maxn];
    int size=0,cnt;
public:
    void shift_up(int t){
        bool done = 0;
        if(t == 0)
            return;
        while(t && !done){
            if(heap[t] > head[(t-1)>>1])
                swap(head[t],head[(t-1)>>1]);
            else
                done = 1;
            t = (t-1)>>1;
        }
    }
    void shift_down(int t){
        bool done = 0;
        if(2*t+1 > size) return;
        while(t<<1|1 < size && !done){
            t = t<<1|1;
            if(t+1 < size && head[t+1] > head[t]) t++;
            if(heap[(t-1)/2]<heap[t])
                swap(heap[t],heap[(t-1)/2]);
            else
                done = 1;
        }
    }
    void Insert(int x){
        if(size >= maxn) return;
        heap[size] = x;
        shift_up(size++);
    }
    void Delete(int t){
        if(t > size) return;
        int last = heap[size-1];
        size--;
        heap[t] = last;
        shift_down(t);
    }
    void Sort(){
        cnt = size;
        for(int i = 0; i < cnt; i++){
            SortedHeap[i]=heap[0];
            Delete(0);
        }
    }
};
