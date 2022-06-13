#include "Support_function.h"

bool item_number_compare(const Line* a, const Line* b) { return ((*a).get_item_number() < (*b).get_item_number()); }
bool name_compare(const Line* a, const Line* b) { return ((*a).get_name() < (*b).get_name()); }
bool station_code_compare(const Line* a, const Line* b) { return ((*a).get_station_code() < (*b).get_station_code()); }


std::vector<Line*>::iterator lower_bound(std::vector<Line*>::iterator _FirstIt, std::vector<Line*>::iterator _SecondIt, const Line& val, bool (*comp)(const Line* a, const Line* b))
{

    std::vector<Line*>::iterator it;
    int count, step;
    count = std::distance(_FirstIt, _SecondIt);
    const Line* temp = &val;
    while (count > 0)
    {
        it = _FirstIt; step = count / 2; std::advance(it, step);
        if (comp(*it, temp)) {
            _FirstIt = ++it;
            count -= step + 1;
        }
        else count = step;
    }
    return _FirstIt;
}