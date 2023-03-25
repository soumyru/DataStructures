
#include <iostream>
using namespace std;
template <typename T>

class DynamicQueue
{
    T *data;
    int nextIndex;
    int firstIndex;
    int size;
    int cap;

    public:
    DynamicQueue(int s)
    {
        data=new T[s];
        nextIndex=0;
        firstIndex=-1;
        size=0;
        cap=s;
    }
    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size==0;
    }

    //Dynamic Queue
    void enqueue(T element)
    {
        if(size==cap)
        {
            T * newData=new T [2*cap];
            int j=0;
            for(int i=firstIndex;i<cap;i++)
            {
                newData[j]=data[i];
                j++;
            }
            for(int i=0;i<firstIndex;i++)
            {
                newData[j]=data[i];
                j++;
            }
            delete []data;
            data=newData;
            firstIndex=0;
            nextIndex=cap;
            cap*=2;
        }

        data[nextIndex]=element;
        // nextIndex++;
        nextIndex=(nextIndex+1)%cap;
        if(firstIndex==-1)
        {
            firstIndex=0;
        }
        size++; 
    }

    T front()
    {
        if(isEmpty())
        {
            cout<<"Queue is empty"<<endl;
            return 0;
        }
        return data[firstIndex];
    }
    T dequeue()
    {
        if(isEmpty())
        {
            cout<<"Queue is empty"<<endl;
            return 0;
        }
        
        T ans=data[firstIndex];
        firstIndex==(firstIndex+1)%cap;
        size--;
        if(size==0)
        {
            firstIndex=-1;
            nextIndex=0;
        } 
        return ans;
    }

};