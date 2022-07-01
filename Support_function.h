#pragma once
#include "Line.h"

bool item_number_compare(const Line& a, const Line& b);
bool category_compare(const Line* a, const Line* b);
bool subcategory2_compare(const Line* a, const Line* b);
bool subcategory3_compare(const Line* a, const Line* b);
bool vendor_code_compare(const Line* a, const Line* b);
bool name_compare(const Line* a, const Line* b);
bool price_compare(const Line* a, const Line* b);
bool q_of_goods_compare(const Line* a, const Line* b);