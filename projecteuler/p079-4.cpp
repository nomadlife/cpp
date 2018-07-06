bool hasIncoming(unsigned n, const std::array<std::array<bool, 10>, 10>& edge, const std::set<unsigned>& nodes) {
    for (const auto& m : nodes) {
        if (edge[m][n]) return true;
    }
    return false;
}

void solve_079() {
    auto start = std::chrono::high_resolution_clock::now();

    std::ifstream file("problem_079.txt");
    std::array<std::array<bool, 10>, 10> edge = { 0 }; //edge[i][j] is 1 if there is an edge from i to j.
    std::array<bool, 10> isNode = { 0 };
    std::string s;
    while (std::getline(file, s)) {
        for (const auto& c : s) {
            isNode[c - '0'] = 1;
        }
        edge[s[0] - '0'][s[1] - '0'] = 1;
        edge[s[1] - '0'][s[2] - '0'] = 1;
    }
    std::set<unsigned> nodes;
    unsigned i;
    for (i = 0; i < 10; ++i) {
        if (isNode[i]) {
            nodes.insert(i);
        }
    }

    std::string L;
    std::vector<unsigned> S;
    for (const auto& n : nodes) {
        if (!hasIncoming(n, edge, nodes)) {
            S.push_back(n);
        }
    }
    unsigned n;
    while (!S.empty()) {
        n = S.back();
        L.push_back('0' + n);
        S.pop_back();
        nodes.erase(n);
        for (const auto& m : nodes) {
            edge[n][m] = 0;
            if (!hasIncoming(m, edge, nodes)) {
                S.push_back(m);
            }
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> elapsed = end - start;
    std::cout << "The shortest possible passcode is " << L << "." << std::endl;
    std::cout << "Computation took " << elapsed.count() << " microseconds." << std::endl;
}