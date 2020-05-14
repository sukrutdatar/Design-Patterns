// This design is thread safe.
// To make it thread safe, we have implemented Meyers Singleton Pattern.

#include <iostream>

class MySingleton 
{
	public:
		// The GetInstance() is thread safe as we have declared "instance" as static.
		// If multiple threads attempt to initialize the same local static variable
		// concurrently, the initialization occurs exactly once.
		
		// See: https://en.cppreference.com/w/cpp/language/storage_duration

		static MySingleton& GetInstance()
		{
			static MySingleton instance;
			return instance;
		}

		void Print()
		{
			std::cout << std::endl << "This is an example of thread-safe Singleton Pattern, also known as Meyers Singleton.";
		}

	private:
		MySingleton() = default;
		~MySingleton() = default;
		MySingleton(const MySingleton&) = delete;
		MySingleton& operator =(const MySingleton&) = delete;
};


int main()
{
	MySingleton::GetInstance().Print();
	std::cout << std::endl;
	return 0;
}

