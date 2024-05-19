class DynamicArray
{
public:
    int capacity;
    int *arr;
    int length;

    DynamicArray(int capacity) : capacity(capacity), length(0)
    {
        arr = new int[capacity];
    }

    int get(int i)
    {
        return arr[i];
    }

    void set(int i, int n)
    {
        arr[i] = n;
    }

    void pushback(int n)
    {
        if (capacity == length)
            resize();
        arr[length++] = n;
    }

    int popback()
    {
        return arr[--length];
    }

    void resize()
    {
        capacity *= 2;

        int *new_arr = new int[capacity];
        for (int num = 0; num < length; num++)
        {
            new_arr[num] = arr[num];
        }
        arr = new_arr;
    }

    int getSize()
    {
        return length;
    }

    int getCapacity()
    {
        return capacity;
    }
};
