#define _CRT_SECURE_NO_WARNINGS 1

// template<class T1, class T2>
// T1 Add(const T1& left, const T2& right)
// {
// 	return left + right;
// }

#if 0
class Complex
{
public:
	Complex(double real, double image)
		: _real(real)
		, _image(image)
	{}

	// 	Complex operator+(const Complex& c)const
	// 	{
	// 		Complex ret(_real+c._real, _image+c._image);
	// 		return ret;
	// 	}

	Complex operator+(const Complex& c)const
	{
		// 无名对象
		return Complex(_real + c._real, _image + c._image);
	}

private:
	double _real;
	double _image;
};

template<class T>
T Add(const T& left, const T& right)
{
	return left + right;
}


int main()
{
	// 隐式实例化：没有直接指明T的实际类型，T的类型需要进行参数推演才可以确定
	// 编译器不会对参数推演的结果进行隐式类型转化
	Add(1, 2);  // Add<int>
	Add(1.0, 2.0); // Add<double>
	Add('1', '2'); // Add<char>
	Add(1, (int)2.0);

	// 显式实例化：明确指定T的实际类型， 参数不匹配时，可能会发生隐式类型转化
	Add<int>(1, 2.0);
	//Add<int>(1, "123");

	Complex c1(1.0, 2.0);
	Complex c2(3.0, 4.0);

	Add(c1, c2);
	return 0;
}
#endif


#if 0
int Add(int left, int right)
{
	return left + right;
}

template<class T1, class T2>
T1 Add(T1 left, T2 right)
{
	return left + right;
}

int main()
{
	Add(1, 2);

	// 对函数模板隐式实例化
	//Add<>(1, 2);  // Add<int>
	Add(1, 2.0);
	return 0;
}
#endif

#if 0
#include <assert.h>


template<class T>
class SeqList
{
public:
	SeqList(size_t capacity = 10)
		: _array(new T[capacity])
		, _capacity(capacity)
		, _size(0)
	{}

	SeqList(size_t n, const T& data = T())
		: _array(new T[n])
		, _capacity(n)
		, _size(n)
	{
		for (size_t i = 0; i < _capacity; ++i)
			_array[i] = data;
	}

	~SeqList()
	{
		if (_array)
		{
			delete[] _array;
			_array = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}

	void PushBack(const T& data);
	void PopBack();

	size_t Size()const
	{
		return _size;
	}

	size_t Capacity()const
	{
		return _capacity;
	}

	bool Empty()const
	{
		return 0 == _size;
	}

	T& operator[](size_t index)
	{
		assert(index < _size);
		return _array[index];
	}

	const T& operator[](size_t index)const
	{
		assert(index < _size);
		return _array[index];
	}

	void PrintSeqList()
	{
		for (size_t i = 0; i < _size; ++i)
		{
			cout << _array[i] << " ";
		}
		cout << endl;
	}

private:
	T* _array;
	size_t _capacity;
	size_t _size;
};


template<class T>
void SeqList<T>::PushBack(const T& data)
{
	// _CheckCapacity();
	_array[_size++] = data;
}

template<class T>
void SeqList<T>::PopBack()
{
	if (0 == _size)
		return;

	--_size;
}


int main()
{
	SeqList<int> s1;
	s1.PushBack(1);
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);
	s1.PushBack(4);

	s1.PrintSeqList();

	s1[0] = 0;
	s1.PrintSeqList();
	cout << s1.Size() << endl;
	cout << s1.Capacity() << endl;
	cout << s1[3] << endl;

	// 一段连续空间---可以支持随即访问



	SeqList<double> s2;
	s2.PushBack(1.0);
	s2.PushBack(2.0);
	s2.PushBack(3.0);
	s2.PushBack(4.0);


	const SeqList<int> s3(10, 5);
	cout << s3[5] << endl;

	s3[5] = 10;

	return 0;
}
#endif

int main()
{
	return 0;
}
