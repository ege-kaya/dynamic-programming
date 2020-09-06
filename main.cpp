/*
Student Name: EGE CAN KAYA
Student Number: 2018400018
Project Number: 5
Compile Status: SUCCESS
Running Status: SUCCESS
Notes: -
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <fstream> // to handle the files
#include <algorithm> // for sort
#include <math.h> // for ceil

typedef long long ll; // for convenience


// a neat little data structure that will hold all the data we'll need
class Calculator {
public:
    int N = -1;
    int M = -1;
    ll sum = 0;
    std::vector<int> v;
    std::vector<ll> known;
    Calculator(int N, int M, int days, std::vector<int>& v) {
        known.resize(N, 0);
        this->N = N;
        this->M = M;
        this->v = v;
    }
};

// predefine some functions we'll call in main
Calculator parseInput(std::ifstream& inFile);
void calculate(int K, Calculator& c, std::ofstream& outFile);


int main(int argc, char* argv[]){
    // this part is borrowed directly from previous projects
    // Command line arguments are malformed
    if (argc != 3) {
        return 1;
    }
    // Open the input and output files, check for failures
    std::ifstream inFile(argv[1]);
    if (!inFile) {
        return 1;
    }
    std::ofstream outFile(argv[2]);
    if (!outFile) {
        return 1;
    }

    // let parseInput create an instance of a Calculator so that we can pass it in to our calculate function
    Calculator c = parseInput(inFile);

    // we'll call calculate for each K from 1 up to N
    for (int K = 1; K < c.N + 1; K++) {
        calculate(K, c, outFile);
    }
    outFile.close();
    return 0;
}

// parses the given input
Calculator parseInput(std::ifstream& inFile) {

    std::string line = "";
    int N, M;
    // Read the first line, should contain N & M
    getline(inFile, line);
    std::istringstream ss(line);
    std::string number;
    for (int i = 0; i < 2; i++) {
        getline(ss, number, ' ');
        if (i == 0) N = stoi(number);
        else M = stoi(number);
    }
    int days = ceil((double) N / (double) M);
    getline(inFile, line);
    std::istringstream linestream(line);
    std::string price;
    std::vector<int> v;

    // push all the prices into a vector
    while (getline(linestream, price, ' ')) {
        v.push_back(stoi(price));
    }

    // then sort the vector
    std::sort(v.begin(), v.end());

    // pass the necessary data into our Calculator c
    Calculator c(N, M, days, v);
    inFile.close();
    return c;
}

// not easy to explain. draw a matrix of all the prices and their multiples for rows.
// then it is easy to recognize a pattern. the key is remembering the values we already
// calculated instead of recalculating them again and again. that's why we keep a "known"
// vector.

void calculate(int K, Calculator& c, std::ofstream& outFile) {
    c.sum += c.v[K-1];
    if(K-1-c.M > -1) c.sum += c.known[K-1-c.M];
    c.known[K-1] = c.v[K-1];
    if (K-1-c.M > -1) c.known[K-1] += c.known[K-1-c.M];
    outFile << c.sum << " ";
}
