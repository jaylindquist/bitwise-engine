#pragma once;


namespace BitwiseEngine
{

namespace Utils
{

template<class T>
class Singleton
{
public:
	static T* GetInstance();
protected:
	T();
private:
	static T* instance;
};

template <class T>
T
Singleton::GetInstance()
{
	if(instance == NULL)
	{
		instance = new T();
	}

	return instance;
}

};
};