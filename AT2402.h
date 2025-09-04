#ifndef __AT2402_H__
#define __AT2402_H__

#define XPT2046_XP_8       0x9C
#define XPT2046_YP_8       0xDC
#define XPT2046_VBAT_8     0xAC
#define XPT2046_AUX_8      0xEC

#define XPT2046_XP_16      0x94
#define XPT2046_YP_16      0xD4
#define XPT2046_VBAT_16    0xA4
#define XPT2046_AUX_16     0xE4

void AT24C02_WriteByte(unsigned char WordAddress,Date);
unsigned char AT24C02_ReadByte(unsigned char WordAddress);

#endif