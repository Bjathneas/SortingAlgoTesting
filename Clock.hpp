#include <chrono>

class Clock {
	public:
		inline Clock() {
			start_time = sys_clock::now();
		}

		inline double getTime() {
			return std::chrono::duration_cast<std::chrono::nanoseconds>(sys_clock::now() - start_time).count() * 1e-6;
		}

		inline void reset() {
			start_time = sys_clock::now();
		}
	private:
		typedef std::chrono::high_resolution_clock sys_clock;
		sys_clock::time_point start_time;
};
