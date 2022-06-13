#pragma once
#include "Line.h"
#include <vector>

bool item_number_compare(const Line* a, const Line* b);
bool name_compare(const Line* a, const Line* b);
bool station_code_compare(const Line* a, const Line* b);

std::vector<Line*>::iterator lower_bound(std::vector<Line*>::iterator _FirstIt, std::vector<Line*>::iterator _SecondIt, const Line& val, bool (*comp)(const Line* a, const Line* b));
