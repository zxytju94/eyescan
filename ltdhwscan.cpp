#include "ltdhwscan.h"

LTDHWScanReader::LTDHWScanReader(LTDHWScan* hwscan, std::string & str) :
    hwscan_0x0(hwscan),
    hwrx_0x8(nullptr),
    hwlink_0x10(nullptr),
    filename_0x18(str)
{
    scan_type_num_0x38 = 0;

    descr_str_0xa0 = "SCAN_0";
    time_started_str_0x60 = "2021-Apr-28 06:16:37";
    time_ended_str_0x80 = "2021-Apr-28 06:16:43";
    open_area_str_0x100 = "14400";
    horiz_perc_str_0x140 = "76.47";
    link_settings_str_0xc0 = "N/A";
    horz_incr_str_0x200 = "8";
    horz_range_str_0x220 = "-0.500 UI to 0.500 UI";
    vertical_incr_str_0x240 = "8";
    vertical_range_str_0x260 = "100%";
}

LTDHWScanReader::LTDHWScanReader(LTDHWRX* hwrx, LTDHWLink *hwlink, std::string & str) :
    hwscan_0x0(nullptr),
    hwrx_0x8(hwrx),
    hwlink_0x10(hwlink),
    filename_0x18(str)
{
    scan_type_num_0x38 = 0;
}

LTDHWScanReader::~LTDHWScanReader() {}

