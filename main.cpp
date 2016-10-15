#include "State.h"
#include "Algorithms.h"
#include <string>

using namespace sbp;

int main(int argc, char* argv[]){
    State state(argv[1]);
    //random_walk(state, std::stoi(argv[2]));
    std::cout << bfs(state) << std::endl;
    return 0;
}

