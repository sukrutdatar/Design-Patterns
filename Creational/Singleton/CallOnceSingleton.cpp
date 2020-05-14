// This design is thread safe.
// To make it thread safe, we have implemented Meyers Singleton Pattern.

#include <iostream>
#include <mutex>

class MySingleton 
{
    private:
        static MySingleton* s_pInstance;
        static std::once_flag s_initInstanceFlag;

	public:
		// The GetInstance() is thread safe as we have used the "call_once" feature of C++.
		// std::call_once ensures that that the Callable object is executed exactly once,
        // even if called concurrently from several threads.
		
		// See: https://en.cppreference.com/w/cpp/thread/call_once

		static MySingleton& GetInstance()
		{
			std::call_once(s_initInstanceFlag, &MySingleton::InitSingleton);
			return *s_pInstance;
		}

		void Print()
		{
			std::cout << std::endl << "This is an example of thread-safe Singleton Pattern using std::call_once.";
		}

	private:
		MySingleton() = default;
		~MySingleton() = default;
		MySingleton(const MySingleton&) = delete;
		MySingleton& operator =(const MySingleton&) = delete;

        static void InitSingleton()
        {
            s_pInstance = new MySingleton();
        }
};

MySingleton* MySingleton::s_pInstance = nullptr;
std::once_flag MySingleton::s_initInstanceFlag;

int main()
{
	MySingleton::GetInstance().Print();
	std::cout << std::endl;
	return 0;
}

