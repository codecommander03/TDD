#pragma once

#include <string>

// Dates are "MM-DD" in a non-leap year; returns the number of days both
// Alice and Bob are in Rome (inclusive ranges).
int countDaysTogether(const std::string& arriveAlice, const std::string& leaveAlice,
                      const std::string& arriveBob, const std::string& leaveBob);
