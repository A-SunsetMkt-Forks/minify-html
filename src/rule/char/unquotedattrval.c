#include "./whitespace.c"

static nh_set_int32_t hbr_unquotedattrval_blacklist;

void hbr_unquotedattrval_init(void) {
  hbr_unquotedattrval_blacklist = nh_set_int32_create();
  hbr_whitespace_add_elems(hbr_unquotedattrval_blacklist);
  nh_set_int32_add(hbr_unquotedattrval_blacklist, '"');
  nh_set_int32_add(hbr_unquotedattrval_blacklist, '\'');
  nh_set_int32_add(hbr_unquotedattrval_blacklist, '`');
  nh_set_int32_add(hbr_unquotedattrval_blacklist, '=');
  nh_set_int32_add(hbr_unquotedattrval_blacklist, '<');
  nh_set_int32_add(hbr_unquotedattrval_blacklist, '>');
}

int hbr_unquotedattrval_check(hb_char_t c) {
  return !nh_set_int32_has(hbr_unquotedattrval_blacklist, c);
}