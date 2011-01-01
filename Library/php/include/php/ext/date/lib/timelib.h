/*
   +----------------------------------------------------------------------+
   | PHP Version 5                                                        |
   +----------------------------------------------------------------------+
   | Copyright (c) 1997-2010 The PHP Group                                |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Authors: Derick Rethans <derick@derickrethans.nl>                    |
   +----------------------------------------------------------------------+
 */

/* $Id: timelib.h 293036 2010-01-03 09:23:27Z sebastian $ */

#ifndef __TIMELIB_H__
#define __TIMELIB_H__

#include "timelib_structs.h"
#if HAVE_LIMITS_H
#include <limits.h>
#endif

#define TIMELIB_NONE             0x00
#define TIMELIB_OVERRIDE_TIME    0x01
#define TIMELIB_NO_CLONE         0x02

#define TIMELIB_SPECIAL_WEEKDAY  0x01

#ifndef LONG_MAX
#define LONG_MAX 2147483647L
#endif

#ifndef LONG_MIN
#define LONG_MIN (- LONG_MAX - 1)
#endif

#if defined(_MSC_VER) && !defined(strcasecmp)
#define strcasecmp stricmp
#endif

#if defined(_MSC_VER) && !defined(strncasecmp)
#define strncasecmp strnicmp
#endif

/* From dow.c */
timelib_sll timelib_day_of_week(timelib_sll y, timelib_sll m, timelib_sll d);
timelib_sll timelib_iso_day_of_week(timelib_sll y, timelib_sll m, timelib_sll d);
timelib_sll timelib_day_of_year(timelib_sll y, timelib_sll m, timelib_sll d);
timelib_sll timelib_daynr_from_weeknr(timelib_sll y, timelib_sll w, timelib_sll d);
timelib_sll timelib_days_in_month(timelib_sll y, timelib_sll m);
void timelib_isoweek_from_date(timelib_sll y, timelib_sll m, timelib_sll d, timelib_sll *iw, timelib_sll *iy);

/* From parse_date.re */
timelib_time *timelib_strtotime(char *s, int len, timelib_error_container **errors, const timelib_tzdb *tzdb);
void timelib_fill_holes(timelib_time *parsed, timelib_time *now, int options);
char *timelib_timezone_id_from_abbr(const char *abbr, long gmtoffset, int isdst);
const timelib_tz_lookup_table *timelib_timezone_abbreviations_list(void);

/* From tm2unixtime.c */
void timelib_update_ts(timelib_time* time, timelib_tzinfo* tzi);

/* From unixtime2tm.c */
int timelib_apply_localtime(timelib_time *t, unsigned int localtime);
void timelib_unixtime2gmt(timelib_time* tm, timelib_sll ts);
void timelib_unixtime2local(timelib_time *tm, timelib_sll ts);
void timelib_update_from_sse(timelib_time *tm);
void timelib_set_timezone(timelib_time *t, timelib_tzinfo *tz);

/* From parse_tz.c */
int timelib_timezone_id_is_valid(char *timezone, const timelib_tzdb *tzdb);
timelib_tzinfo *timelib_parse_tzfile(char *timezone, const timelib_tzdb *tzdb);
int timelib_timestamp_is_in_dst(timelib_sll ts, timelib_tzinfo *tz);
timelib_time_offset *timelib_get_time_zone_info(timelib_sll ts, timelib_tzinfo *tz);
timelib_sll timelib_get_current_offset(timelib_time *t);
void timelib_dump_tzinfo(timelib_tzinfo *tz);
const timelib_tzdb *timelib_builtin_db(void);
const timelib_tzdb_index_entry *timelib_timezone_builtin_identifiers_list(int *count);

/* From timelib.c */
timelib_tzinfo* timelib_tzinfo_ctor(char *name);
void timelib_time_tz_abbr_update(timelib_time* tm, char* tz_abbr);
void timelib_time_tz_name_update(timelib_time* tm, char* tz_name);
void timelib_tzinfo_dtor(timelib_tzinfo *tz);
timelib_tzinfo* timelib_tzinfo_clone(timelib_tzinfo *tz);

timelib_time* timelib_time_ctor(void);
void timelib_time_set_option(timelib_time* tm, int option, void* option_value);
void timelib_time_dtor(timelib_time* t);

timelib_time_offset* timelib_time_offset_ctor(void);
void timelib_time_offset_dtor(timelib_time_offset* t);

void timelib_error_container_dtor(timelib_error_container *errors);

signed long timelib_date_to_int(timelib_time *d, int *error);
void timelib_dump_date(timelib_time *d, int options);

void timelib_decimal_hour_to_hms(double h, int *hour, int *min, int *sec);

/* from astro.c */
double timelib_ts_to_juliandate(timelib_sll ts);
int timelib_astro_rise_set_altitude(timelib_time *time, double lon, double lat, double altit, int upper_limb, double *h_rise, double *h_set, timelib_sll *ts_rise, timelib_sll *ts_set, timelib_sll *ts_transit);

#endif
