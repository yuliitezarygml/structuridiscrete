#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

using ull = unsigned long long;

ull calculateFactorial(unsigned n);
ull calculateFactorialRecursive(unsigned n);
ull calculatePermutations(unsigned n);
ull calculateArrangements(unsigned n, unsigned m);
ull calculateCombinations(unsigned n, unsigned m);
ull calculateCombinationsOptimized(unsigned n, unsigned m);
ull power(unsigned base, unsigned exponent);
ull calculatePermutationsWithRepetition(unsigned n);
ull calculateArrangementsWithRepetition(unsigned n, unsigned m);
ull calculateCombinationsWithRepetition(unsigned n, unsigned m);
ull calculateWordPermutations(const string& word);
void displayBinomialTheorem(unsigned power);
ull calculateLicensePlates();

int main() {
    unsigned n, m;
    
    cout << "Enter the total number: n = ";
    cin >> n;
    
    cout << "Enter the selection number: m = ";
    cin >> m;

    cout << "Project #2, developed by Terentii Iulian\n";
    cout << "Topic: Elements of Combinatorics.\n";
    

    cout << "\n1.1. Iterative Factorial\n";
    
    for (unsigned i = 0; i <= 20; ++i) {
        cout << setw(2) << left << i << "! = " 
             << setw(20) << calculateFactorial(i) << "| ";
        
        if (i % 4 == 0) cout << '\n';
    }
    

    cout << "\n1.2. Recursive Factorial\n";
    
    for (unsigned i = 0; i <= 20; ++i) {
        cout << setw(2) << left << i << "! = " 
             << setw(20) << calculateFactorialRecursive(i) << "| ";
        
        if (i % 4 == 0) cout << '\n';
    }

    cout << "\n2. Permutations> P(" << n << ") = " 
         << calculatePermutations(n) << '\n';
              
    cout << "3. Arrangements> A(" << n << ", " << m << ") = " 
         << calculateArrangements(n, m) << '\n';
              
    cout << "4. Combinations> C(" << n << ", " << m << ") = " 
         << calculateCombinations(n, m) << '\n';
              
    cout << "5. Optimized Combinations> C(" << n << ", " << m << ") = " 
         << calculateCombinationsOptimized(n, m) << '\n';
              
    cout << "6.1. Permutations with repetition (n^n)> PR(" << n << ") = " 
         << calculatePermutationsWithRepetition(n) << '\n';
              
    cout << "6.2. Arrangements with repetition (n^m)> AR(" << n << ", " << m << ") = " 
         << calculateArrangementsWithRepetition(n, m) << '\n';
              
    cout << "7. Combinations with repetition> CR(" << n << ", " << m << ") = " 
         << calculateCombinationsWithRepetition(n, m) << '\n';

    unsigned p;
    cout << "\nEnter p for Binomial Theorem (coefficients and form of (a+b)^p): p = ";
    cin >> p;
    displayBinomialTheorem(p);

    cout << "\nEnter a word (max 19 characters) for distinct permutations: ";
    string word;
    cin >> word;
    cout << "Number of distinct permutations of the word '" << word << "' = " 
         << calculateWordPermutations(word) << '\n';

    cout << "\n--- Problem 10: License Plates ---\n";
    cout << "Condition: a license plate consists of 3 distinct letters + 3 digits (repetition allowed)\n";
    cout << "Total number of distinct license plates: " << calculateLicensePlates() << '\n';

    return 0;
}

ull calculateFactorial(unsigned n) {
    ull result = 1;
    
    for (unsigned i = 2; i <= n; ++i) {
        result *= i;
    }
    
    return result;
}

ull calculateFactorialRecursive(unsigned n) {
    if (n <= 1) return 1;
    
    return calculateFactorialRecursive(n - 1) * n;
}

ull calculatePermutations(unsigned n) {
    return calculateFactorial(n);
}

ull calculateArrangements(unsigned n, unsigned m) {
    if (m > n) return 0;
    
    return calculateFactorial(n) / calculateFactorial(n - m);
}

ull calculateCombinations(unsigned n, unsigned m) {
    if (m > n) return 0;
    
    return calculateFactorial(n) / (calculateFactorial(m) * calculateFactorial(n - m));
}

ull calculateCombinationsOptimized(unsigned n, unsigned m) {
    if (m > n) return 0;
    
    unsigned k = (m < n - m) ? m : n - m;
    
    ull result = 1;
    
    for (unsigned i = 1; i <= k; ++i) {
        result = result * (n - k + i) / i;
    }
    
    return result;
}

ull power(unsigned base, unsigned exponent) {
    ull result = 1;
    
    for (unsigned i = 0; i < exponent; ++i) {
        result *= base;
    }
    
    return result;
}

ull calculatePermutationsWithRepetition(unsigned n) {
    return power(n, n);
}

ull calculateArrangementsWithRepetition(unsigned n, unsigned m) {
    return power(n, m);
}

ull calculateCombinationsWithRepetition(unsigned n, unsigned m) {
    return calculateCombinationsOptimized(n + m - 1, m);
}

ull calculateWordPermutations(const string& word) {
    if (word.empty() || word.length() > 19) return 0;
    
    vector<unsigned> frequency(256, 0);
    
    for (char c : word) {
        frequency[static_cast<unsigned char>(c)]++;
    }
    
    ull denominator = 1;
    for (unsigned count : frequency) {
        
        if (count > 1) {
            denominator *= calculateFactorial(count);
        }
    }
    
    return calculateFactorial(word.length()) / denominator;
}

void displayBinomialTheorem(unsigned p) {
    cout << "\nBinomial Theorem for p = " << p << "\n";
    
    cout << "Coefficients C(" << p << ", k):\n";
    for (unsigned k = 0; k <= p; ++k) {
        cout << "C(" << p << "," << k << ") = " << calculateCombinationsOptimized(p, k);
        
        if (k < p) cout << ", ";
    }
    
    cout << "\n\nSymbolic form (a+b)^" << p << " = ";
    for (unsigned k = 0; k <= p; ++k) {
        ull coefficient = calculateCombinationsOptimized(p, k);
        
        if (k > 0) cout << " + ";
        
        if (coefficient != 1) cout << coefficient << "*";
        
        if (p - k > 0) {
            cout << "a";
            
            if (p - k > 1) cout << "^" << (p - k);
        }
        
        if (k > 0) {
            
            if (p - k > 0) cout << "*";
            cout << "b";
            
            if (k > 1) cout << "^" << k;
        }
    }
    cout << "\n";
}

ull calculateLicensePlates() {
    const ull distinctLetters = 26ULL * 25ULL * 24ULL;
    const ull digitsWithRepetition = 1000ULL;
    
    return distinctLetters * digitsWithRepetition;
}