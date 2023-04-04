#include<string>
using namespace std;

template<typename V>
class MapNode
{
    public:
    string key;
    V value;
    MapNode * next;

    MapNode(string key,V value)
    {
        this->key=key;
        this->value=value;
        next=NULL;
    }
    ~MapNode()
    {
        delete next;
    }
};

template <typename V>
class ourMap
{
    MapNode<V>** buckets; //LL k head ka array
    int count;
    int numBuckets;

    public:
    ourMap()
    {
        count=0;
        numBuckets=5;
        buckets=new MapNode<V>*[numBuckets];
        for(int i=0;i<numBuckets;i++)
        {
            buckets[i]=NULL;
        }
    }

    ~ourMap()
    {
        for(int i=0;i<numBuckets;i++)
        {
            delete buckets[i]; // first delete the LL so as to avoid losing address of LL stored in array
        }
        delete [] buckets;//now, delete array
    }

int size()
{
    return count;
}

V getValue(string key)
{
    int bucketIndex=getBucketIndex(key);
    MapNode<V>* head=buckets[bucketIndex];
    while(head!=NULL)
    {
        if(head->key==key)
        return head->value;

        head=head->next;
    
    }
    return 0;
}

//abc=a*p^2+b*p^1+c*p^0  (p is base, taking a prime no.)
private:
int getBucketIndex(string key)
{
    int hashcode=0;
    int currCoeff=1;
    for(int i=key.length()-1;i>=0;i--)
    {
        hashcode+=key[i]*currCoeff;
        hashcode=hashcode%numBuckets;
        currCoeff*=37;//37 is p(prime no.)
        currCoeff=currCoeff%numBuckets;//doing this to mmake it short... in case, currCoeff goes out of index
    }
    return hashcode % numBuckets;
}

void rehash()
{
    MapNode<V>** temp=buckets;
    buckets=new MapNode<V>*[2*numBuckets];
    for(int i=0;i<2*numBuckets;i++)
    {
        buckets[i]=NULL;
    }
    int oldBucketCount=numBuckets;
    numBuckets*=2;
    count=0;

    for(int i=0;i<oldBucketCount;i++)
    {
        MapNode<V>* head=temp[i];
        while(head!=NULL)
        {
            string key=head->key;
            V value=head->value;
            insert(key,value);
            head=head->next;
        }
    }
    for(int i=0;i<oldBucketCount;i++)
    {
        MapNode<V>* head=temp[i];
        delete head;
    }
    delete[]temp;
}
public:
double getLoadFactor()
{
    return (1.0*count)/numBuckets;
}

void insert(string key,V value)
{
    int bucketIndex=getBucketIndex(key);
    MapNode<V>* head=buckets[bucketIndex];
    while(head!=NULL)
    {
        if(head->key==key){
        head->value=value;
        return;
        }
        head=head->next;
    
    }
    head=buckets[bucketIndex];
    MapNode<V>* node=new MapNode<V>(key,value);
    node->next=head;
    buckets[bucketIndex]=node;
    count++;
    double loadFactor=(1.0*count)/numBuckets;
    if(loadFactor>0.7)
    rehash();

}

V remove(string key)
{
    int bucketIndex=getBucketIndex(key);
    MapNode<V>*head=buckets[bucketIndex];
    MapNode<V>*prev=NULL;
    while(head!=NULL)
    {
        if(head->key==key)
        {
            if(prev==NULL)
            buckets[bucketIndex]=head->next;
            else
            prev->next=head->next;

            V value=head->value;
            head->next=NULL;
            delete head;
            count--;
            return value;
        }
        prev=head;
        head=head->next;
    }
    return 0;

}

};