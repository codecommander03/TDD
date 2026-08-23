#include "strings/sum_game.hpp"

bool sumGame(const std::string& num) {
    // Each '?' is worth 4.5 to its half when both sides play optimally: the
    // player who wants a mismatch picks 9 or 0, and the opponent answers in the
    // same half with the complement, so pairs of '?' in one half average out.
    int n = static_cast<int>(num.size());
    int leftMarks = 0, rightMarks = 0, diff = 0;
    for (int i = 0; i < n / 2; i++) {
        if (num[i] == '?') leftMarks++;
        else diff += num[i] - '0';
    }
    for (int i = n / 2; i < n; i++) {
        if (num[i] == '?') rightMarks++;
        else diff -= num[i] - '0';
    }

    // An odd number of blanks leaves Alice with the last move, and she can
    // always break a tie with it.
    if ((leftMarks + rightMarks) % 2) return true;

    // Bob survives only when the known digits already offset the 4.5 per blank
    // that the extra '?'s bring to their half; doubled to stay in integers.
    return 2 * diff != 9 * (rightMarks - leftMarks);
}
