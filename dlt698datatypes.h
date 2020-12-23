#ifndef DLT698DATATYPES_H
#define DLT698DATATYPES_H

#pragma once

#include <bits/wordsize.h>

typedef bool            BOOLEAN;
typedef unsigned char   BYTE;
typedef int             INT32;
typedef unsigned int    UINT32;
typedef char            CHAR;
typedef short           SHORT;
typedef unsigned short  WORD;

#if __WORDSIZE == 64
typedef long int                LONG64;
typedef unsigned long int       ULONG64;
#else
__extension__
typedef long long int           LONG64;
typedef unsigned long long int  ULONG64;
#endif

/*typedef NULL        null_c;*/
typedef BOOLEAN		bool_c;
typedef BYTE		bit_string_c/*[SEQUENCENUM]*/;
typedef INT32		double_long_c;
typedef UINT32		double_long_unsigned_c;
typedef BYTE		Octet_string_c/*[SEQUENCENUM]*/;
typedef CHAR		visible_string_c/*[SEQUENCENUM]*/;
typedef BYTE		UTF8_string_c/*[SEQUENCENUM]*/;
typedef CHAR		integer_c;
typedef SHORT		long_c;
typedef BYTE		unsigned_c;
typedef WORD		long_unsigned_c;
typedef LONG64		long64_c;
typedef ULONG64		long64_unsigned_c;
typedef BYTE		enum_c;
typedef float		float32_c ;
typedef double		float64_c ;

typedef long_unsigned_c OI_c;

typedef enum _eDataType
{
    t_null = 0,//空
    t_array = 1,//SEQUENCE OF Data 见6.3.3.1　）
    t_structure = 2,//SEQUENCE OF Data 见6.3.3.1　）
    t_bool = 3,//01-true;00-false
    t_bit_string = 4,//比特位串（BIT STRING）
    t_double_long = 5,//32比特位整数（Integer32）-2p31…2p31-1
    t_double_long_unsigned = 6,//32比特位正整数 0…2p32-1
    t_octet_string = 9,//8比特位位组（字节）串（OCTET STRING）
    t_visible_string = 10,//ASCII字符串（VisibleString）
    t_utf8_string = 12,//UTF-8编码的字符串
    t_bcd = 13,//
    t_integer = 15,//8比特位整数（integer） -128…127
    t_long = 16,//16比特位整数（long） -32768…32767
    t_unsigned = 17,//8比特位正整数（Unsigned8） 0…255
    t_long_unsigned = 18,//16比特位正整数（Unsigned16）0…65535
    t_long64 = 20,//64比特位整数（Integer64）-2p63…2p63-1
    t_long64_unsigned = 21,//64比特位正整数（Unsigned64）0…2p64-1
    t_enum = 22,//0…255
    t_float32 = 23,//octet-string（SIZE（4））
    t_float64 = 24,//octet-string（SIZE（8））
    t_date_time = 25,//octet-string（SIZE（10））
    t_date = 26,//octet-string（SIZE（5））
    t_time = 27,//octet-string（SIZE（3））
    t_datetime_s = 28,//octet-string（SIZE（7））
    t_datetimebcd_h = 29,//
    t_datetimebcd_s = 30,//
    t_datebcd = 31,//
    t_timebcd = 32,//
    t_oi = 80,//
    t_oad = 81,//
    t_road = 82,//
    t_omd = 83,//
    t_ti = 84,//
    t_tsa = 85,//
    t_mac = 86,//
    t_rn = 87,//
    t_region = 88,//
    t_scaler_unit = 89,//
    t_rsd = 90,//
    t_csd = 91,//
    t_ms = 92,//
    t_sid = 93,//
    t_sid_mac = 94,//
    t_comdcb = 95,////
    t_rcsd = 96,//
    /// 自定义数据类型
    t_nothing = 255//

}eDataType;

typedef enum _eSecurityAPDU
{
    ///     安全请求
    SecurityRequest = 16,
    ///     安全响应
    SecurityResponse = 144

}SecurityAPDU;


#endif // DLT698DATATYPES_H
