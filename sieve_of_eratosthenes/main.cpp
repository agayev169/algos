#include <iostream>
#include <vector>

using namespace std;

unsigned int num_to_index(unsigned int num) {
    return (num - 3) / 2;
}

unsigned int index_to_num(unsigned int index) {
    return index * 2 + 3;
}

// 2 is not in the list to save more memory.
vector<bool> sieve(unsigned int sieve_max) {
    if (sieve_max < 3) return {};
    vector<bool> primes(num_to_index(sieve_max), true);
    unsigned int p = 3;
    unsigned int prev_p;
    while (true) {
        prev_p = p;

        for (unsigned int i = 3; p * i <= sieve_max; i += 2) 
            primes[num_to_index(p * i)] = false;
        
        for (unsigned int i = p + 2; i * i < sieve_max; i += 2) {
            if (primes[num_to_index(i)]) {
                p = i;
                break;
            }
        }

        if (prev_p == p) {
            break;
        }
    }

    return primes;
}

int main() {
    unsigned int sieve_max = 10000000;

    vector<bool> primes = sieve(sieve_max);

    unsigned int res = (primes.size() > 0) ? 1 : 0; // Consider 2 as prime
    for (unsigned long int i = 0u; i < primes.size(); ++i) {
        if (primes[i]) ++res;
    }

    cout << "There are " << res << " primes under " << sieve_max << endl;

    return 0;
}