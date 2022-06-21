#include "Support_function.h"

bool item_number_compare(const Line* a, const Line* b) { return ((*a).get_item_number() < (*b).get_item_number()); }
bool name_compare(const Line* a, const Line* b) { return ((*a).get_name() < (*b).get_name()); }
bool station_code_compare(const Line* a, const Line* b) { return ((*a).get_station_code() < (*b).get_station_code()); }