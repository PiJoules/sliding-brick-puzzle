#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "State.h"

namespace sbp {
    void random_walk(State& state, const int& n);
    State bfs(const State state);
    State dfs(const State state);
    State ids(const State state);
}

#endif
