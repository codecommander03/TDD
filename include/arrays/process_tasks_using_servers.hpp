#pragma once
#include <vector>

// Returns, for each task, the index of the server it runs on: at second j task j
// goes to the free server with the smallest weight (then smallest index), or, if
// none is free, to the first server to free up.
std::vector<int> assignTasks(std::vector<int>& servers, std::vector<int>& tasks);
