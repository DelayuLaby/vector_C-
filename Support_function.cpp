#include "Support_function.h"

bool item_number_compare(const Line& a, const Line& b) { return (a.get_item_number() < b.get_item_number()); }
bool category_compare(const Line* a, const Line* b) { return ((*a).get_category() < (*b).get_category()); }
bool subcategory2_compare(const Line* a, const Line* b) { return ((*a).get_subcategory2() < (*b).get_subcategory2()); }
bool subcategory3_compare(const Line* a, const Line* b) { return ((*a).get_subcategory3() < (*b).get_subcategory3()); }
bool vendor_code_compare(const Line* a, const Line* b) { return ((*a).get_vendor_code() < (*b).get_vendor_code()); }
bool name_compare(const Line* a, const Line* b) { return ((*a).get_name() < (*b).get_name()); }
bool price_compare(const Line* a, const Line* b) { return ((*a).get_price() < (*b).get_price()); }
bool q_of_goods_compare(const Line* a, const Line* b) { return ((*a).get_quantity_of_goods() < (*b).get_quantity_of_goods()); }