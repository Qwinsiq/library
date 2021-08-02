// simpleArray.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

class SimpleArray
{
private:
    int* mass;
    size_t _size;
public:
    SimpleArray(size_t _size = 0, int _fillvalue = 0)
    {
        this->_size = _size;
        this->mass = new int[_size];
        for (int i = 0; i < _size; i++)
        {
            this->mass[i] = _fillvalue;
        }
        cout << " the default constructor is called\n";
    }
    ~SimpleArray()
    {
        delete[] mass;
        cout << " the default destructor is called\n";
    }
    SimpleArray(const SimpleArray& other)
    {
        this->_size = other._size;
        this->mass = new int[_size];
        for (int i = 0; i < _size; i++)
        {
            this->mass[i] = other.mass[i];
        }
        cout << " copy constructor called\n";
    } 
    SimpleArray(int* mass, size_t masSize)
    {
        this->_size = masSize;
        this->mass = new int[_size];
        for (int i = 0; i < _size; i++)
        {
            this->mass[i] = mass[i];
        }
        cout << " Copy constructor called \n";
    }
    size_t getSize()
    {
        return _size;
    }
    void reset()
    {
        for (int i = 0; i < _size; i++)
        {
            mass[i] = 0;
        }
    }
    void clear()
    {
        delete[] mass;        
        mass = nullptr;
        _size = 0;
    }
    void print()
    {
        for (int i = 0; i < _size; i++)
        {
            cout << mass[i] << " ";

        }
        cout << endl;
    }
    void fill(int _fillvalue)
    {
        for (int i = 0; i < _size; i++)
        {
            mass[i] = _fillvalue;
        }
    }
    void pushBack(int _newValue)
    {
        int* temp = new int[_size + 1];
        for (int i = 0; i < _size; i++)
        {
            temp[i] = mass[i];
        }
        temp[_size] = _newValue;
        _size++;
        delete[] mass;
        mass = temp;
        }
    void setValue(int n, int m)
    {
        mass[n] = m;
    }
    int getValue(int n)
    {
        return mass[n];
    }
    SimpleArray operator+(SimpleArray a)
    {
        SimpleArray temp;
        temp._size = this->_size + a._size;
        temp.mass = new int[temp._size];
        for (int i = 0; i < this->_size; i++)
        {
            temp.mass[i] = this->mass[i];
        }
        for (int i = 0; i < a._size; i++)
        {
            temp.mass[i + this->_size] = a.mass[i];
        }
        return temp;
    }
    SimpleArray operator+(int b)
    {
        SimpleArray temp;
        temp._size = this->_size;
        temp.mass = new int[_size];
        for (int i = 0; i < _size; i++)
        {
            temp.mass[i] = this->mass[i] + b;
        }
        return temp;
    }
    SimpleArray& operator+=( const SimpleArray& a)
    {
        SimpleArray temp;
        temp._size = this->_size + a._size;
        temp.mass = new int[temp._size];
        for (int i = 0; i < this->_size; i++)
        {
            temp.mass[i] = this->mass[i];
        }
        for (int i = 0; i < a._size; i++)
        {
            temp.mass[i + this->_size] = a.mass[i];
        }
        this->_size= temp._size;
        this->mass = new int[this->_size];
        for (int i = 0; i < _size; i++)
        {
            this->mass[i] = temp.mass[i];
        }
        return *this;
    }
    SimpleArray& operator+=(int b)
    {
        for (int i = 0; i < this->_size; i++)
        {
            this->mass[i] = this->mass[i] + b;
        }
        return *this;
    }
    SimpleArray& operator=(SimpleArray a)
    {
        this->_size = a._size;
        this->mass = new int[_size];
        for (int i = 0; i < _size; i++)
        {
            this->mass[i] = a.mass[i];
        }
        return *this;
    }

};

int main()
{
    /*SimpleArray array1(5, 5);
    cout << "middle\n";
    SimpleArray array2(array1);
    cout << "size of array = " << array2.getSize() << endl;
    array1.reset();
    array1.print();
    cout << "size of array = " << array1.getSize() << endl;
    array1.clear();
    cout << "size of array = " << array1.getSize() << endl;
    array2.fill(3);
    array2.print();
    array2.pushBack(5);
    array2.print();*/
    const int Size = 5;
    int mas1[Size] = { 1,2,3,4,5 };
    int mas2[Size] = { 6,7,8,9,0 };
    SimpleArray sa1(mas1, Size);
    SimpleArray sa2(mas2, Size);
    SimpleArray rez(sa1 + sa2);
    rez.print();
    sa1 += sa2;
    sa1.print();
    sa2 += 5;
    sa2.print();
    sa1 = sa2;
    sa1.print();

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
