
    #include <iostream>
    #include <string>
    #include <cstdlib>
    #include <cassert>

    void solve_testcase(){

        int n = 0;
        std::string s;
        std::cin >> n >> s;

        //test assumptions midway (disable with -DNDEBUG)
        assert(s.size() == n);

        int number_of_heads = 0;
        for(const char c : s)
            if(c == 'H')
                number_of_heads++;

        std::cout << ((number_of_heads > n / 2) ? "A" : "B") << "\n";

    }

    int main(){

        int T = 0;
        std::cin >> T;

        while(T--)
            solve_testcase();

        return EXIT_SUCCESS;
    }


//Compile `g++ -std=c++17 -Wall -pedantic -O3 -DNDEBUG solution.cpp -o solution` 

//Test with `(time ./solution < example.in) | diff -bBZ - example.out`

