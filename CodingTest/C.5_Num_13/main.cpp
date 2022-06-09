#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

std::vector<int> OnlineRandomSample(std::vector<int>::const_iterator stream_begin,
									const std::vector<int>::const_iterator stream_end,
									int k) {
	std::vector<int> running_sample;
	for (int i = 0; i < k; i++) {
		running_sample.emplace_back(*stream_begin++);
	}

	std::default_random_engine seed((std::random_device())());
	int num_seen_so_far = k;
	while (stream_begin != stream_end) {
		int x = *stream_begin++;
		num_seen_so_far++;
		const int idx_to_replace = std::uniform_int_distribution<int>{ 0, num_seen_so_far - 1 }(seed);
		
		if (idx_to_replace < k) {
			running_sample[idx_to_replace] = x;
		}
	}
	return running_sample;
}

int main(void) {


}