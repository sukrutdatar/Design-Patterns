#include <iostream>

template <typename T>
class Singleton
{
    public:
        static T& GetInstance()
        {
            static T instance;
            return instance;
        }

    protected:
		Singleton() = default;
		~Singleton() = default;
		Singleton(const Singleton&) = delete;
		Singleton& operator =(const Singleton&) = delete;
};

class MySingleton : public Singleton<MySingleton>
{
    friend class Singleton<MySingleton>;

    public:
        void Print()
		{
			std::cout << std::endl << "This is an example of thread-safe Singleton Pattern using templates.";
		}

    private:
        MySingleton() = default;
        ~MySingleton() = default;
        MySingleton(const MySingleton&) = delete;
        MySingleton& operator = (const MySingleton&) = delete;
};

int main()
{
	Singleton<MySingleton>::GetInstance().Print();
	std::cout << std::endl;
	return 0;
}