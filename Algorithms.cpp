#include "Algorithms.h"
#include <random>
#include <iterator>
#include <vector>
#include <deque>

namespace sbp {
    /**
     * Select random element from vector.
     */
    template<typename Iter, typename RandomGenerator>
    Iter random_element(Iter start, Iter end, RandomGenerator& g) {
        std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
        std::advance(start, dis(g));
        return start;
    }

    template<typename Iter>
    Iter random_element(Iter start, Iter end) {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        return random_element(start, end, gen);
    }

    /**
     * Perform random walk given move cap.
     * 1. Generate all possible moves for board in current state.
     * 2. Select 1 move at random.
     * 3. Execute move.
     * 4. Normalize resulting game state.
     * 5. Stop if reached goal or reached cap on moves. Otherwise, repeat at 1.
     *
     * Print the state and move after each iteration.
     */
    void random_walk(State& state, const int& n){
        // Print initial state
        std::cout << state << std::endl;
        if (state.is_complete()){
            return;
        }

        std::vector<Move> moves = state.possible_moves();
        for (int i = 0; i < n; i++){
            Move move = *random_element(moves.begin(), moves.end());
            state.apply_move(move);

            // Print move and state
            std::cout << move << std::endl;
            std::cout << state << std::endl;

            state.normalize();
            if (state.is_complete()){
                break;
            }
            moves = state.possible_moves();
        }
    }

    /**
     * Breadth first search.
     * Ignore sequences of moves that lead to same state.
     */
    State bfs(const State state){
        if (state.is_complete()){
            return state;
        }

        std::deque<State> states;
        states.push_back(state);
        while (!states.empty()){
            const State& first = states[0];
            std::cout << first << std::endl;
            std::vector<Move> moves = state.possible_moves();
            std::cout << 3 << std::endl;
            for (const auto& move : moves){
                std::cout << 4 << std::endl;
                std::cout << move << std::endl;
                std::cout << first << std::endl;
                //State state_ = first.apply_move_cloning(move);
                //std::cout << 5 << std::endl;
                //if (state_.is_complete()){
                //    return state_;
                //}
                //states.push_back(state_);
                //std::cout << 2 << std::endl;
            }
            std::cout << 1 << std::endl;
            std::cout << states.size() << std::endl;
            //states.erase(states.begin());
            states.pop_front();
        }
    }
}

