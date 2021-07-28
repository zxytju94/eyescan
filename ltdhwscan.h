#ifndef LTDHWSCAN_H
#define LTDHWSCAN_H

#include <string>
#include <vector>
#include <map>
#include <thread>
#include <unordered_map>

class LTDHWScan;
class LTDHWRX;
class LTDHWLink;
class LTDHWSweep;


class LTDHWScanPoint {
 public:
  int x_int_0x0;
  int y_int_0x4;
  double value_double_0x8;
  unsigned long long errors_ull_0x10;
  unsigned long long samples_ull_0x18;
};

//=============== class LTDHWScanReader ===============
class LTDHWScanReader {
 public:
  LTDHWScan* hwscan_0x0;
  LTDHWRX* hwrx_0x8;
  LTDHWLink* hwlink_0x10;
  std::string filename_0x18;
  int32_t scan_type_num_0x38;  // scan_type_num_0x98
  std::string scan_type_str_0x40;
  std::string time_started_str_0x60;
  std::string time_ended_str_0x80;
  std::string descr_str_0xa0;   // Scan 0  (Title)
  std::string link_settings_str_0xc0;
  std::string apply_settings_str_0xe0;
  std::string open_area_str_0x100;
  std::string horiz_open_str_0x120;
  std::string horiz_perc_str_0x140;
  std::string vertical_open_str_0x160;
  std::string vertical_perc_str_0x180;
  std::string dwell_str_0x1a0;
  std::string dwell_ber_str_0x1c0;
  std::string dwell_time_str_0x1e0;
  std::string horz_incr_str_0x200;
  std::string horz_range_str_0x220;
  std::string vertical_incr_str_0x240;
  std::string vertical_range_str_0x260;
  std::string misc_info_str_0x280;
  std::vector<LTDHWScanPoint *> scan_points_0x2a0;

 public:
  LTDHWScanReader(LTDHWScan*, std::string&);
  LTDHWScanReader(LTDHWRX*, LTDHWLink*, std::string&);
  ~LTDHWScanReader();

  /*void readKeyValue(LTDCsvParser&, unsigned int&, std::string&, std::string&);
  void readHeader(LTDCsvParser&, unsigned int&);
  void readScanData(LTDCsvParser&, unsigned int&);
  void setScan();
  LTDHWScan* read();*/
};

class LTDHWScan {
public:
 std::string name_0x38;
 std::string description_0x58;
 std::string type_0x78;
 int32_t scan_type_num_0x98;
 std::string descr_str_0xa0;
 LTDHWRX* hwrx_ptr_0xc0;
 LTDHWLink* link_ptr_0xc8;
 LTDHWSweep* sweep_ptr_0xd0;
 std::vector<LTDHWScanPoint*> scan_data_0xd8;
 std::vector<LTDHWScanPoint*> new_scan_data_0xf0;
 std::string debug_header_0x108; //
 std::vector<std::string> debug_lines_0x128;

 uint64_t uint_slave_map_func_ptr_0x140;
 uint64_t uint_slave_map_func_ptr_0x148;
 uint64_t void_bool_func_ptr_0x150;
 uint64_t void_bool_func_ptr_0x158;
 bool is_stopped_0x160;
 bool is_running_0x161;
 uint16_t word0_0x162;
 uint32_t dword0_0x164;
 long long_val0_0x168; // long or unsigned long long
 pthread_mutex_t p_mutex2_0x170;

 std::unordered_map<std::string, std::string> params_0x198; //

 long long time_val_0x1d0;
 int32_t horz_min_0x1d8;
 int32_t horz_max_0x1dc;
 int32_t vert_min_0x1e0;
 int32_t vert_max_0x1e4;
 int32_t last_horz_incr_0x1e8;
 int32_t last_vert_incr_0x1ec;
 std::string last_horz_range_str_0x1f0;
 std::string last_vert_range_str_0x210;
 double last_horz_range_double_0x230;
 double last_vert_range_double_0x238;
 int32_t horz_range_0x240;
 int32_t scaned_num_0x244;
 std::map<std::string, std::string> propertysetting_0x248;//para or property
 std::vector<std::string> svg_view_types_0x278;
 std::string scan_type_0x290;
 std::string svg_data_str_0x2b0;
 std::string svg_key_str_0x2d0;
 bool no_svg_0x2f0;
 char char4_0x2f1[3];
 int32_t bathtub_min_0x2f4;
 int32_t bathtub_max_0x2f8;
};
#endif // LTDHWSCAN_H
