template<class T>
class Iterator;

template<class T>
class Aggregate
{
public:
    friend class Iterator<T>;
    Aggregate()
    {
        pos = 0;
        size = 10; 
        lista = new T[size];
    }

    void add(T element)
    {
        if(pos < size)            
            lista[pos++] = element; 
    }

    Iterator<T>* getIterator()
    {
        return new Iterator<T>(this);
    }
    
    ~Aggregate()
    {
        delete [] lista;
    }

    T getElementAt(int pos){
        return lista[pos];
    }

    int getPos()
    {
        return pos;
    }  

private:
    T* lista;
    int size;
    int pos;
};
