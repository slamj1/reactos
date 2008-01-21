/*
* PROJECT:         ReactOS Setup Driver
* LICENSE:         GPL - See COPYING in the top level directory
* FILE:            drivers/setup/blue/font.c
* PURPOSE:         Loading specific fonts into VGA
* PROGRAMMERS:     Aleksey Bragin (aleksey@reactos.org)
*                  Colin Finck (mail@colinfinck.de)
*/

/* INCLUDES ***************************************************************/

#include <ntddk.h>
#include "blue.h"

#define NDEBUG
#include <debug.h>

VOID OpenBitPlane();
VOID CloseBitPlane();
VOID LoadFont(PBYTE Bitplane, PUCHAR FontBitfield);

static UCHAR Cp850Font[2048];
static UCHAR Cp866Font[2048];

/* FUNCTIONS ****************************************************************/

VOID
ScrLoadFontTable(UINT CodePage)
{
    PHYSICAL_ADDRESS BaseAddress;
    PBYTE Bitplane;
    PUCHAR FontBitfield = NULL;

    /* open bit plane for font table access */
    OpenBitPlane();

    /* get pointer to video memory */
    BaseAddress.QuadPart = BITPLANE_BASE;
    Bitplane = (PBYTE)MmMapIoSpace (BaseAddress, 0xFFFF, MmNonCached);

    switch(CodePage)
    {
        case 850: FontBitfield = Cp850Font; break;
        case 866: FontBitfield = Cp866Font; break;
    }

    if(FontBitfield)
        LoadFont(Bitplane, FontBitfield);

    MmUnmapIoSpace(Bitplane, 0xFFFF);

    /* close bit plane */
    CloseBitPlane();
}

/* PRIVATE FUNCTIONS *********************************************************/

/* Font-load specific funcs */
VOID
OpenBitPlane()
{
    /* disable interrupts */
    _disable();

    /* sequence reg */
    WRITE_PORT_UCHAR (SEQ_COMMAND, SEQ_RESET); WRITE_PORT_UCHAR (SEQ_DATA, 0x01);
    WRITE_PORT_UCHAR (SEQ_COMMAND, SEQ_ENABLE_WRT_PLANE); WRITE_PORT_UCHAR (SEQ_DATA, 0x04);
    WRITE_PORT_UCHAR (SEQ_COMMAND, SEQ_MEM_MODE); WRITE_PORT_UCHAR (SEQ_DATA, 0x07);
    WRITE_PORT_UCHAR (SEQ_COMMAND, SEQ_RESET); WRITE_PORT_UCHAR (SEQ_DATA, 0x03);

    /* graphic reg */
    WRITE_PORT_UCHAR (GCT_COMMAND, GCT_READ_PLANE); WRITE_PORT_UCHAR (GCT_DATA, 0x02);
    WRITE_PORT_UCHAR (GCT_COMMAND, GCT_RW_MODES); WRITE_PORT_UCHAR (GCT_DATA, 0x00);
    WRITE_PORT_UCHAR (GCT_COMMAND, GCT_GRAPH_MODE); WRITE_PORT_UCHAR (GCT_DATA, 0x00);

    /* enable interrupts */
    _enable();
}

VOID
CloseBitPlane()
{
    /* disable interrupts */
    _disable();

    /* sequence reg */
    WRITE_PORT_UCHAR (SEQ_COMMAND, SEQ_RESET); WRITE_PORT_UCHAR (SEQ_DATA, 0x01);
    WRITE_PORT_UCHAR (SEQ_COMMAND, SEQ_ENABLE_WRT_PLANE); WRITE_PORT_UCHAR (SEQ_DATA, 0x03);
    WRITE_PORT_UCHAR (SEQ_COMMAND, SEQ_MEM_MODE); WRITE_PORT_UCHAR (SEQ_DATA, 0x03);
    WRITE_PORT_UCHAR (SEQ_COMMAND, SEQ_RESET); WRITE_PORT_UCHAR (SEQ_DATA, 0x03);

    /* graphic reg */
    WRITE_PORT_UCHAR (GCT_COMMAND, GCT_READ_PLANE); WRITE_PORT_UCHAR (GCT_DATA, 0x00);
    WRITE_PORT_UCHAR (GCT_COMMAND, GCT_RW_MODES); WRITE_PORT_UCHAR (GCT_DATA, 0x10);
    WRITE_PORT_UCHAR (GCT_COMMAND, GCT_GRAPH_MODE); WRITE_PORT_UCHAR (GCT_DATA, 0x0e);

    /* enable interrupts */
    _enable();
}

VOID
LoadFont(PBYTE Bitplane, PUCHAR FontBitfield)
{
    UINT i,j;

    for (i=0; i<256; i++)
    {
        for (j=0; j<8; j++)
        {
            *Bitplane = FontBitfield[i*8+j];
            Bitplane++;
        }

        // padding
        for (j=8; j<32; j++)
        {
            *Bitplane = 0;
            Bitplane++;
        }
    }
}

/* This font has been imported from DragonFlyBSD / FreeBSD
   Original URL is: http://opengrok.creo.hu/dragonfly/xref/src/share/syscons/fonts/ (2008/01/21) */
static UCHAR Cp850Font[2048] = {
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x7E,0x81,0xA5,0x81,0xBD,0x99,0x81,0x7E,
0x7E,0xFF,0xDB,0xFF,0xC3,0xE7,0xFF,0x7E,
0x6C,0xFE,0xFE,0xFE,0x7C,0x38,0x10,0x00,
0x10,0x38,0x7C,0xFE,0x7C,0x38,0x10,0x00,
0x38,0x7C,0x38,0xFE,0xFE,0xD6,0x10,0x38,
0x10,0x38,0x7C,0xFE,0xFE,0x7C,0x10,0x38,
0x00,0x00,0x18,0x3C,0x3C,0x18,0x00,0x00,
0xFF,0xFF,0xE7,0xC3,0xC3,0xE7,0xFF,0xFF,
0x00,0x3C,0x66,0x42,0x42,0x66,0x3C,0x00,
0xFF,0xC3,0x99,0xBD,0xBD,0x99,0xC3,0xFF,
0x0F,0x07,0x0F,0x7D,0xCC,0xCC,0xCC,0x78,
0x3C,0x66,0x66,0x66,0x3C,0x18,0x7E,0x18,
0x3F,0x33,0x3F,0x30,0x30,0x70,0xF0,0xE0,
0x7F,0x63,0x7F,0x63,0x63,0x67,0xE6,0xC0,
0x18,0xDB,0x3C,0xE7,0xE7,0x3C,0xDB,0x18,
0x80,0xE0,0xF8,0xFE,0xF8,0xE0,0x80,0x00,
0x02,0x0E,0x3E,0xFE,0x3E,0x0E,0x02,0x00,
0x18,0x3C,0x7E,0x18,0x18,0x7E,0x3C,0x18,
0x66,0x66,0x66,0x66,0x66,0x00,0x66,0x00,
0x7F,0xDB,0xDB,0x7B,0x1B,0x1B,0x1B,0x00,
0x3E,0x61,0x3C,0x66,0x66,0x3C,0x86,0x7C,
0x00,0x00,0x00,0x00,0x7E,0x7E,0x7E,0x00,
0x18,0x3C,0x7E,0x18,0x7E,0x3C,0x18,0xFF,
0x18,0x3C,0x7E,0x18,0x18,0x18,0x18,0x00,
0x18,0x18,0x18,0x18,0x7E,0x3C,0x18,0x00,
0x00,0x18,0x0C,0xFE,0x0C,0x18,0x00,0x00,
0x00,0x30,0x60,0xFE,0x60,0x30,0x00,0x00,
0x00,0x00,0xC0,0xC0,0xC0,0xFE,0x00,0x00,
0x00,0x24,0x66,0xFF,0x66,0x24,0x00,0x00,
0x00,0x18,0x3C,0x7E,0xFF,0xFF,0x00,0x00,
0x00,0xFF,0xFF,0x7E,0x3C,0x18,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x18,0x3C,0x3C,0x18,0x18,0x00,0x18,0x00,
0x66,0x66,0x24,0x00,0x00,0x00,0x00,0x00,
0x6C,0x6C,0xFE,0x6C,0xFE,0x6C,0x6C,0x00,
0x18,0x3E,0x60,0x3C,0x06,0x7C,0x18,0x00,
0x00,0xC6,0xCC,0x18,0x30,0x66,0xC6,0x00,
0x38,0x6C,0x38,0x76,0xDC,0xCC,0x76,0x00,
0x18,0x18,0x30,0x00,0x00,0x00,0x00,0x00,
0x0C,0x18,0x30,0x30,0x30,0x18,0x0C,0x00,
0x30,0x18,0x0C,0x0C,0x0C,0x18,0x30,0x00,
0x00,0x66,0x3C,0xFF,0x3C,0x66,0x00,0x00,
0x00,0x18,0x18,0x7E,0x18,0x18,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x30,
0x00,0x00,0x00,0x7E,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00,
0x06,0x0C,0x18,0x30,0x60,0xC0,0x80,0x00,
0x38,0x6C,0xC6,0xD6,0xC6,0x6C,0x38,0x00,
0x18,0x38,0x18,0x18,0x18,0x18,0x7E,0x00,
0x7C,0xC6,0x06,0x1C,0x30,0x66,0xFE,0x00,
0x7C,0xC6,0x06,0x3C,0x06,0xC6,0x7C,0x00,
0x1C,0x3C,0x6C,0xCC,0xFE,0x0C,0x1E,0x00,
0xFE,0xC0,0xC0,0xFC,0x06,0xC6,0x7C,0x00,
0x38,0x60,0xC0,0xFC,0xC6,0xC6,0x7C,0x00,
0xFE,0xC6,0x0C,0x18,0x30,0x30,0x30,0x00,
0x7C,0xC6,0xC6,0x7C,0xC6,0xC6,0x7C,0x00,
0x7C,0xC6,0xC6,0x7E,0x06,0x0C,0x78,0x00,
0x00,0x18,0x18,0x00,0x00,0x18,0x18,0x00,
0x00,0x18,0x18,0x00,0x00,0x18,0x18,0x30,
0x06,0x0C,0x18,0x30,0x18,0x0C,0x06,0x00,
0x00,0x00,0x7E,0x00,0x00,0x7E,0x00,0x00,
0x60,0x30,0x18,0x0C,0x18,0x30,0x60,0x00,
0x7C,0xC6,0x0C,0x18,0x18,0x00,0x18,0x00,
0x7C,0xC6,0xDE,0xDE,0xDE,0xC0,0x78,0x00,
0x38,0x6C,0xC6,0xFE,0xC6,0xC6,0xC6,0x00,
0xFC,0x66,0x66,0x7C,0x66,0x66,0xFC,0x00,
0x3C,0x66,0xC0,0xC0,0xC0,0x66,0x3C,0x00,
0xF8,0x6C,0x66,0x66,0x66,0x6C,0xF8,0x00,
0xFE,0x62,0x68,0x78,0x68,0x62,0xFE,0x00,
0xFE,0x62,0x68,0x78,0x68,0x60,0xF0,0x00,
0x3C,0x66,0xC0,0xC0,0xCE,0x66,0x3A,0x00,
0xC6,0xC6,0xC6,0xFE,0xC6,0xC6,0xC6,0x00,
0x3C,0x18,0x18,0x18,0x18,0x18,0x3C,0x00,
0x1E,0x0C,0x0C,0x0C,0xCC,0xCC,0x78,0x00,
0xE6,0x66,0x6C,0x78,0x6C,0x66,0xE6,0x00,
0xF0,0x60,0x60,0x60,0x62,0x66,0xFE,0x00,
0xC6,0xEE,0xFE,0xFE,0xD6,0xC6,0xC6,0x00,
0xC6,0xE6,0xF6,0xDE,0xCE,0xC6,0xC6,0x00,
0x7C,0xC6,0xC6,0xC6,0xC6,0xC6,0x7C,0x00,
0xFC,0x66,0x66,0x7C,0x60,0x60,0xF0,0x00,
0x7C,0xC6,0xC6,0xC6,0xC6,0xCE,0x7C,0x0E,
0xFC,0x66,0x66,0x7C,0x6C,0x66,0xE6,0x00,
0x3C,0x66,0x30,0x18,0x0C,0x66,0x3C,0x00,
0x7E,0x7E,0x5A,0x18,0x18,0x18,0x3C,0x00,
0xC6,0xC6,0xC6,0xC6,0xC6,0xC6,0x7C,0x00,
0xC6,0xC6,0xC6,0xC6,0xC6,0x6C,0x38,0x00,
0xC6,0xC6,0xC6,0xD6,0xD6,0xFE,0x6C,0x00,
0xC6,0xC6,0x6C,0x38,0x6C,0xC6,0xC6,0x00,
0x66,0x66,0x66,0x3C,0x18,0x18,0x3C,0x00,
0xFE,0xC6,0x8C,0x18,0x32,0x66,0xFE,0x00,
0x3C,0x30,0x30,0x30,0x30,0x30,0x3C,0x00,
0xC0,0x60,0x30,0x18,0x0C,0x06,0x02,0x00,
0x3C,0x0C,0x0C,0x0C,0x0C,0x0C,0x3C,0x00,
0x10,0x38,0x6C,0xC6,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,
0x30,0x18,0x0C,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x78,0x0C,0x7C,0xCC,0x76,0x00,
0xE0,0x60,0x7C,0x66,0x66,0x66,0xDC,0x00,
0x00,0x00,0x7C,0xC6,0xC0,0xC6,0x7C,0x00,
0x1C,0x0C,0x7C,0xCC,0xCC,0xCC,0x76,0x00,
0x00,0x00,0x7C,0xC6,0xFE,0xC0,0x7C,0x00,
0x3C,0x66,0x60,0xF8,0x60,0x60,0xF0,0x00,
0x00,0x00,0x76,0xCC,0xCC,0x7C,0x0C,0xF8,
0xE0,0x60,0x6C,0x76,0x66,0x66,0xE6,0x00,
0x18,0x00,0x38,0x18,0x18,0x18,0x3C,0x00,
0x06,0x00,0x06,0x06,0x06,0x66,0x66,0x3C,
0xE0,0x60,0x66,0x6C,0x78,0x6C,0xE6,0x00,
0x38,0x18,0x18,0x18,0x18,0x18,0x3C,0x00,
0x00,0x00,0xEC,0xFE,0xD6,0xD6,0xD6,0x00,
0x00,0x00,0xDC,0x66,0x66,0x66,0x66,0x00,
0x00,0x00,0x7C,0xC6,0xC6,0xC6,0x7C,0x00,
0x00,0x00,0xDC,0x66,0x66,0x7C,0x60,0xF0,
0x00,0x00,0x76,0xCC,0xCC,0x7C,0x0C,0x1E,
0x00,0x00,0xDC,0x76,0x60,0x60,0xF0,0x00,
0x00,0x00,0x7E,0xC0,0x7C,0x06,0xFC,0x00,
0x30,0x30,0xFC,0x30,0x30,0x36,0x1C,0x00,
0x00,0x00,0xCC,0xCC,0xCC,0xCC,0x76,0x00,
0x00,0x00,0xC6,0xC6,0xC6,0x6C,0x38,0x00,
0x00,0x00,0xC6,0xD6,0xD6,0xFE,0x6C,0x00,
0x00,0x00,0xC6,0x6C,0x38,0x6C,0xC6,0x00,
0x00,0x00,0xC6,0xC6,0xC6,0x7E,0x06,0xFC,
0x00,0x00,0x7E,0x4C,0x18,0x32,0x7E,0x00,
0x0E,0x18,0x18,0x70,0x18,0x18,0x0E,0x00,
0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x00,
0x70,0x18,0x18,0x0E,0x18,0x18,0x70,0x00,
0x76,0xDC,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x10,0x38,0x6C,0xC6,0xC6,0xFE,0x00,
0x7C,0xC6,0xC0,0xC0,0xC6,0x7C,0x0C,0x78,
0xCC,0x00,0xCC,0xCC,0xCC,0xCC,0x76,0x00,
0x0C,0x18,0x7C,0xC6,0xFE,0xC0,0x7C,0x00,
0x7C,0x82,0x78,0x0C,0x7C,0xCC,0x76,0x00,
0xC6,0x00,0x78,0x0C,0x7C,0xCC,0x76,0x00,
0x30,0x18,0x78,0x0C,0x7C,0xCC,0x76,0x00,
0x30,0x30,0x78,0x0C,0x7C,0xCC,0x76,0x00,
0x00,0x00,0x7E,0xC0,0xC0,0x7E,0x0C,0x38,
0x7C,0x82,0x7C,0xC6,0xFE,0xC0,0x7C,0x00,
0xC6,0x00,0x7C,0xC6,0xFE,0xC0,0x7C,0x00,
0x30,0x18,0x7C,0xC6,0xFE,0xC0,0x7C,0x00,
0x66,0x00,0x38,0x18,0x18,0x18,0x3C,0x00,
0x7C,0x82,0x38,0x18,0x18,0x18,0x3C,0x00,
0x30,0x18,0x00,0x38,0x18,0x18,0x3C,0x00,
0xC6,0x38,0x6C,0xC6,0xFE,0xC6,0xC6,0x00,
0x38,0x6C,0x7C,0xC6,0xFE,0xC6,0xC6,0x00,
0x18,0x30,0xFE,0xC0,0xF8,0xC0,0xFE,0x00,
0x00,0x00,0x7E,0x12,0xFE,0x90,0xFE,0x00,
0x3E,0x6C,0xCC,0xFE,0xCC,0xCC,0xCE,0x00,
0x7C,0x82,0x7C,0xC6,0xC6,0xC6,0x7C,0x00,
0xC6,0x00,0x7C,0xC6,0xC6,0xC6,0x7C,0x00,
0x30,0x18,0x7C,0xC6,0xC6,0xC6,0x7C,0x00,
0x78,0x84,0x00,0xCC,0xCC,0xCC,0x76,0x00,
0x60,0x30,0xCC,0xCC,0xCC,0xCC,0x76,0x00,
0xC6,0x00,0xC6,0xC6,0xC6,0x7E,0x06,0xFC,
0xC6,0x38,0x6C,0xC6,0xC6,0x6C,0x38,0x00,
0xC6,0x00,0xC6,0xC6,0xC6,0xC6,0x7C,0x00,
0x00,0x02,0x7C,0xCE,0xD6,0xE6,0x7C,0x80,
0x38,0x6C,0x64,0xF0,0x60,0x66,0xFC,0x00,
0x3A,0x6C,0xCE,0xD6,0xE6,0x6C,0xB8,0x00,
0x00,0xC6,0x6C,0x38,0x6C,0xC6,0x00,0x00,
0x0E,0x1B,0x18,0x3C,0x18,0xD8,0x70,0x00,
0x18,0x30,0x78,0x0C,0x7C,0xCC,0x76,0x00,
0x0C,0x18,0x00,0x38,0x18,0x18,0x3C,0x00,
0x0C,0x18,0x7C,0xC6,0xC6,0xC6,0x7C,0x00,
0x18,0x30,0xCC,0xCC,0xCC,0xCC,0x76,0x00,
0x76,0xDC,0x00,0xDC,0x66,0x66,0x66,0x00,
0x76,0xDC,0x00,0xE6,0xF6,0xDE,0xCE,0x00,
0x3C,0x6C,0x6C,0x3E,0x00,0x7E,0x00,0x00,
0x38,0x6C,0x6C,0x38,0x00,0x7C,0x00,0x00,
0x18,0x00,0x18,0x18,0x30,0x63,0x3E,0x00,
0x7E,0x81,0xB9,0xA5,0xB9,0xA5,0x81,0x7E,
0x00,0x00,0x00,0xFE,0x06,0x06,0x00,0x00,
0x63,0xE6,0x6C,0x7E,0x33,0x66,0xCC,0x0F,
0x63,0xE6,0x6C,0x7A,0x36,0x6A,0xDF,0x06,
0x18,0x00,0x18,0x18,0x3C,0x3C,0x18,0x00,
0x00,0x33,0x66,0xCC,0x66,0x33,0x00,0x00,
0x00,0xCC,0x66,0x33,0x66,0xCC,0x00,0x00,
0x22,0x88,0x22,0x88,0x22,0x88,0x22,0x88,
0x55,0xAA,0x55,0xAA,0x55,0xAA,0x55,0xAA,
0x77,0xDD,0x77,0xDD,0x77,0xDD,0x77,0xDD,
0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,
0x18,0x18,0x18,0x18,0xF8,0x18,0x18,0x18,
0x30,0x60,0x38,0x6C,0xC6,0xFE,0xC6,0x00,
0x7C,0x82,0x38,0x6C,0xC6,0xFE,0xC6,0x00,
0x18,0x0C,0x38,0x6C,0xC6,0xFE,0xC6,0x00,
0x7E,0x81,0x9D,0xA1,0xA1,0x9D,0x81,0x7E,
0x36,0x36,0xF6,0x06,0xF6,0x36,0x36,0x36,
0x36,0x36,0x36,0x36,0x36,0x36,0x36,0x36,
0x00,0x00,0xFE,0x06,0xF6,0x36,0x36,0x36,
0x36,0x36,0xF6,0x06,0xFE,0x00,0x00,0x00,
0x18,0x18,0x7E,0xC0,0xC0,0x7E,0x18,0x18,
0x66,0x66,0x3C,0x7E,0x18,0x7E,0x18,0x18,
0x00,0x00,0x00,0x00,0xF8,0x18,0x18,0x18,
0x18,0x18,0x18,0x18,0x1F,0x00,0x00,0x00,
0x18,0x18,0x18,0x18,0xFF,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0xFF,0x18,0x18,0x18,
0x18,0x18,0x18,0x18,0x1F,0x18,0x18,0x18,
0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,
0x18,0x18,0x18,0x18,0xFF,0x18,0x18,0x18,
0x76,0xDC,0x7C,0x06,0x7E,0xC6,0x7E,0x00,
0x76,0xDC,0x38,0x6C,0xC6,0xFE,0xC6,0x00,
0x36,0x36,0x37,0x30,0x3F,0x00,0x00,0x00,
0x00,0x00,0x3F,0x30,0x37,0x36,0x36,0x36,
0x36,0x36,0xF7,0x00,0xFF,0x00,0x00,0x00,
0x00,0x00,0xFF,0x00,0xF7,0x36,0x36,0x36,
0x36,0x36,0x37,0x30,0x37,0x36,0x36,0x36,
0x00,0x00,0xFF,0x00,0xFF,0x00,0x00,0x00,
0x36,0x36,0xF7,0x00,0xF7,0x36,0x36,0x36,
0x00,0xC6,0x7C,0xC6,0xC6,0x7C,0xC6,0x00,
0x30,0x7E,0x0C,0x7C,0xCC,0xCC,0x78,0x00,
0xF8,0x6C,0x66,0xF6,0x66,0x6C,0xF8,0x00,
0x7C,0x82,0xFE,0xC0,0xFC,0xC0,0xFE,0x00,
0xC6,0x00,0xFE,0xC0,0xFC,0xC0,0xFE,0x00,
0x30,0x18,0xFE,0xC0,0xFC,0xC0,0xFE,0x00,
0x00,0x00,0x38,0x18,0x18,0x18,0x3C,0x00,
0x0C,0x18,0x3C,0x18,0x18,0x18,0x3C,0x00,
0x3C,0x42,0x3C,0x18,0x18,0x18,0x3C,0x00,
0x66,0x00,0x3C,0x18,0x18,0x18,0x3C,0x00,
0x18,0x18,0x18,0x18,0xF8,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x1F,0x18,0x18,0x18,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,
0x18,0x18,0x18,0x00,0x00,0x18,0x18,0x18,
0x30,0x18,0x3C,0x18,0x18,0x18,0x3C,0x00,
0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,
0x30,0x60,0x38,0x6C,0xC6,0x6C,0x38,0x00,
0x78,0xCC,0xCC,0xD8,0xCC,0xC6,0xCC,0x00,
0x7C,0x82,0x38,0x6C,0xC6,0x6C,0x38,0x00,
0x0C,0x06,0x38,0x6C,0xC6,0x6C,0x38,0x00,
0x76,0xDC,0x7C,0xC6,0xC6,0xC6,0x7C,0x00,
0x76,0xDC,0x38,0x6C,0xC6,0x6C,0x38,0x00,
0x00,0x00,0x66,0x66,0x66,0x66,0x7C,0xC0,
0xE0,0x60,0x7C,0x66,0x66,0x7C,0x60,0xF0,
0xF0,0x60,0x7C,0x66,0x7C,0x60,0xF0,0x00,
0x18,0x30,0xC6,0xC6,0xC6,0xC6,0x7C,0x00,
0x7C,0x82,0x00,0xC6,0xC6,0xC6,0x7C,0x00,
0x60,0x30,0xC6,0xC6,0xC6,0xC6,0x7C,0x00,
0x18,0x30,0xC6,0xC6,0xC6,0x7E,0x06,0xFC,
0x0C,0x18,0x66,0x66,0x3C,0x18,0x3C,0x00,
0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x0C,0x18,0x30,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x7E,0x00,0x00,0x00,0x00,
0x18,0x18,0x7E,0x18,0x18,0x00,0x7E,0x00,
0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0xFF,
0xE1,0x32,0xE4,0x3A,0xF6,0x2A,0x5F,0x86,
0x7F,0xDB,0xDB,0x7B,0x1B,0x1B,0x1B,0x00,
0x3E,0x61,0x3C,0x66,0x66,0x3C,0x86,0x7C,
0x00,0x18,0x00,0x7E,0x00,0x18,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x18,0x0C,0x38,
0x38,0x6C,0x6C,0x38,0x00,0x00,0x00,0x00,
0x00,0xC6,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x18,0x00,0x00,0x00,0x00,
0x18,0x38,0x18,0x18,0x3C,0x00,0x00,0x00,
0x78,0x0C,0x38,0x0C,0x78,0x00,0x00,0x00,
0x78,0x0C,0x18,0x30,0x7C,0x00,0x00,0x00,
0x00,0x00,0x3C,0x3C,0x3C,0x3C,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

/* This font was provided by ??? */
static UCHAR Cp866Font[2048] = {
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x7E,0x81,0xA5,0x81,0xBD,0x99,0x81,0x7E,
0x7E,0xFF,0xDB,0xFF,0xC3,0xE7,0xFF,0x7E,
0x6C,0xFE,0xFE,0xFE,0x7C,0x38,0x10,0x00,
0x10,0x38,0x7C,0xFE,0x7C,0x38,0x10,0x00,
0x38,0x7C,0x38,0xFE,0xFE,0x7C,0x38,0x7C,
0x10,0x10,0x38,0x7C,0xFE,0x7C,0x38,0x7C,
0x00,0x00,0x18,0x3C,0x3C,0x18,0x00,0x00,
0xFF,0xFF,0xE7,0xC3,0xC3,0xE7,0xFF,0xFF,
0x00,0x3C,0x66,0x42,0x42,0x66,0x3C,0x00,
0xFF,0xC3,0x99,0xBD,0xBD,0x99,0xC3,0xFF,
0x0F,0x07,0x0F,0x7D,0xCC,0xCC,0xCC,0x78,
0x3C,0x66,0x66,0x66,0x3C,0x18,0x7E,0x18,
0x3F,0x33,0x3F,0x30,0x30,0x70,0xF0,0xE0,
0x7F,0x63,0x7F,0x63,0x63,0x67,0xE6,0xC0,
0x99,0x5A,0x3C,0xE7,0xE7,0x3C,0x5A,0x99,
0x80,0xE0,0xF8,0xFE,0xF8,0xE0,0x80,0x00,
0x02,0x0E,0x3E,0xFE,0x3E,0x0E,0x02,0x00,
0x18,0x3C,0x7E,0x18,0x18,0x7E,0x3C,0x18,
0x66,0x66,0x66,0x66,0x66,0x00,0x66,0x00,
0x7F,0xDB,0xDB,0x7B,0x1B,0x1B,0x1B,0x00,
0x3E,0x63,0x38,0x6C,0x6C,0x38,0xCC,0x78,
0x00,0x00,0x00,0x00,0x7E,0x7E,0x7E,0x00,
0x18,0x3C,0x7E,0x18,0x7E,0x3C,0x18,0xFF,
0x18,0x3C,0x7E,0x18,0x18,0x18,0x18,0x00,
0x18,0x18,0x18,0x18,0x7E,0x3C,0x18,0x00,
0x00,0x18,0x0C,0xFE,0x0C,0x18,0x00,0x00,
0x00,0x30,0x60,0xFE,0x60,0x30,0x00,0x00,
0x00,0x00,0xC0,0xC0,0xC0,0xFE,0x00,0x00,
0x00,0x24,0x66,0xFF,0x66,0x24,0x00,0x00,
0x00,0x18,0x3C,0x7E,0xFF,0xFF,0x00,0x00,
0x00,0xFF,0xFF,0x7E,0x3C,0x18,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x30,0x78,0x78,0x30,0x30,0x00,0x30,0x00, // !   33   21
0x6C,0x6C,0x6C,0x00,0x00,0x00,0x00,0x00, // "   34   22
0x6C,0x6C,0xFE,0x6C,0xFE,0x6C,0x6C,0x00, // #   35   23
0x30,0x7C,0xC0,0x78,0x0C,0xF8,0x30,0x00, // $   36   24
0x00,0xC6,0xCC,0x18,0x30,0x66,0xC6,0x00, // %   37   25
0x38,0x6C,0x38,0x76,0xDC,0xCC,0x76,0x00, // &   38   26
0x60,0x60,0xC0,0x00,0x00,0x00,0x00,0x00, // '   39   27
0x18,0x30,0x60,0x60,0x60,0x30,0x18,0x00, // (   40   28
0x60,0x30,0x18,0x18,0x18,0x30,0x60,0x00, // )   41   29
0x00,0x66,0x3C,0xFF,0x3C,0x66,0x00,0x00, // *   42   2A
0x00,0x30,0x30,0xFC,0x30,0x30,0x00,0x00, // +   43   2B
0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x60, // ,   44   2C
0x00,0x00,0x00,0xFC,0x00,0x00,0x00,0x00, // -   45   2D
0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x00, // .   46   2E
0x06,0x0C,0x18,0x30,0x60,0xC0,0x80,0x00, // /   47   2F
0x7C,0xC6,0xCE,0xDE,0xF6,0xE6,0x7C,0x00, // 0   48   30
0x30,0x70,0x30,0x30,0x30,0x30,0xFC,0x00, // 1   49   31
0x78,0xCC,0x0C,0x38,0x60,0xCC,0xFC,0x00, // 2   50   32
0x78,0xCC,0x0C,0x38,0x0C,0xCC,0x78,0x00, // 3   51   33
0x1C,0x3C,0x6C,0xCC,0xFE,0x0C,0x1E,0x00, // 4   52   34
0xFC,0xC0,0xF8,0x0C,0x0C,0xCC,0x78,0x00, // 5   53   35
0x38,0x60,0xC0,0xF8,0xCC,0xCC,0x78,0x00, // 6   54   36
0xFC,0xCC,0x0C,0x18,0x30,0x30,0x30,0x00, // 7   55   37
0x78,0xCC,0xCC,0x78,0xCC,0xCC,0x78,0x00, // 8   56   38
0x78,0xCC,0xCC,0x7C,0x0C,0x18,0x70,0x00, // 9   57   39
0x00,0x30,0x30,0x00,0x00,0x30,0x30,0x00, // :   58   3A
0x00,0x30,0x30,0x00,0x00,0x30,0x30,0x60, //  //   59   3B
0x18,0x30,0x60,0xC0,0x60,0x30,0x18,0x00, // <   60   3C
0x00,0x00,0xFC,0x00,0x00,0xFC,0x00,0x00, // =   61   3D
0x60,0x30,0x18,0x0C,0x18,0x30,0x60,0x00, // >   62   3E
0x78,0xCC,0x0C,0x18,0x30,0x00,0x30,0x00, // ?   63   3F
0x7C,0xC6,0xDE,0xDE,0xDE,0xC0,0x78,0x00, // @   64   40
0x30,0x78,0xCC,0xCC,0xFC,0xCC,0xCC,0x00, // A   65   41
0xFC,0x66,0x66,0x7C,0x66,0x66,0xFC,0x00, // B   66   42
0x3C,0x66,0xC0,0xC0,0xC0,0x66,0x3C,0x00, // C   67   43
0xF8,0x6C,0x66,0x66,0x66,0x6C,0xF8,0x00, // D   68   44
0xFE,0x62,0x68,0x78,0x68,0x62,0xFE,0x00, // E   69   45
0xFE,0x62,0x68,0x78,0x68,0x60,0xF0,0x00, // F   70   46
0x3C,0x66,0xC0,0xC0,0xCE,0x66,0x3E,0x00, // G   71   47
0xCC,0xCC,0xCC,0xFC,0xCC,0xCC,0xCC,0x00, // H   72   48
0x78,0x30,0x30,0x30,0x30,0x30,0x78,0x00, // I   73   49
0x1E,0x0C,0x0C,0x0C,0xCC,0xCC,0x78,0x00, // J   74   4A
0xE6,0x66,0x6C,0x78,0x6C,0x66,0xE6,0x00, // K   75   4B
0xF0,0x60,0x60,0x60,0x62,0x66,0xFE,0x00, // L   76   4C
0xC6,0xEE,0xFE,0xFE,0xD6,0xC6,0xC6,0x00, // M   77   4D
0xC6,0xE6,0xF6,0xDE,0xCE,0xC6,0xC6,0x00, // N   78   4E
0x38,0x6C,0xC6,0xC6,0xC6,0x6C,0x38,0x00, // O   79   4F
0xFC,0x66,0x66,0x7C,0x60,0x60,0xF0,0x00, // P   80   50
0x78,0xCC,0xCC,0xCC,0xDC,0x78,0x1C,0x00, // Q   81   51
0xFC,0x66,0x66,0x7C,0x6C,0x66,0xE6,0x00, // R   82   52
0x78,0xCC,0xE0,0x70,0x1C,0xCC,0x78,0x00, // S   83   53
0xFC,0xB4,0x30,0x30,0x30,0x30,0x78,0x00, // T   84   54
0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0xFC,0x00, // U   85   55
0xCC,0xCC,0xCC,0xCC,0xCC,0x78,0x30,0x00, // V   86   56
0xC6,0xC6,0xC6,0xD6,0xFE,0xEE,0xC6,0x00, // W   87   57
0xC6,0xC6,0x6C,0x38,0x38,0x6C,0xC6,0x00, // X   88   58
0xCC,0xCC,0xCC,0x78,0x30,0x30,0x78,0x00, // Y   89   59
0xFE,0xC6,0x8C,0x18,0x32,0x66,0xFE,0x00, // Z   90   5A
0x78,0x60,0x60,0x60,0x60,0x60,0x78,0x00, // [   91   5B
0xC0,0x60,0x30,0x18,0x0C,0x06,0x02,0x00, // \   92   5C
0x78,0x18,0x18,0x18,0x18,0x18,0x78,0x00, // ]   93   5D
0x10,0x38,0x6C,0xC6,0x00,0x00,0x00,0x00, // ^   94   5E
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF, // _   95   5F
0x30,0x30,0x18,0x00,0x00,0x00,0x00,0x00, // `   96   60
0x00,0x00,0x78,0x0C,0x7C,0xCC,0x76,0x00, // a   97   61
0xE0,0x60,0x60,0x7C,0x66,0x66,0xDC,0x00, // b   98   62
0x00,0x00,0x78,0xCC,0xC0,0xCC,0x78,0x00, // c   99   63
0x1C,0x0C,0x0C,0x7C,0xCC,0xCC,0x76,0x00, // d   100   64
0x00,0x00,0x78,0xCC,0xFC,0xC0,0x78,0x00, // e   101   65
0x38,0x6C,0x60,0xF0,0x60,0x60,0xF0,0x00, // f   102   66
0x00,0x00,0x76,0xCC,0xCC,0x7C,0x0C,0xF8, // g   103   67
0xE0,0x60,0x6C,0x76,0x66,0x66,0xE6,0x00, // h   104   68
0x30,0x00,0x70,0x30,0x30,0x30,0x78,0x00, // i   105   69
0x0C,0x00,0x0C,0x0C,0x0C,0xCC,0xCC,0x78, // j   106   6A
0xE0,0x60,0x66,0x6C,0x78,0x6C,0xE6,0x00, // k   107   6B
0x70,0x30,0x30,0x30,0x30,0x30,0x78,0x00, // l   108   6C
0x00,0x00,0xCC,0xFE,0xFE,0xD6,0xC6,0x00, // m   109   6D
0x00,0x00,0xF8,0xCC,0xCC,0xCC,0xCC,0x00, // n   110   6E
0x00,0x00,0x78,0xCC,0xCC,0xCC,0x78,0x00, // o   111   6F
0x00,0x00,0xDC,0x66,0x66,0x7C,0x60,0xF0, // p   112   70
0x00,0x00,0x76,0xCC,0xCC,0x7C,0x0C,0x1E, // q   113   71
0x00,0x00,0xDC,0x76,0x66,0x60,0xF0,0x00, // r   114   72
0x00,0x00,0x7C,0xC0,0x78,0x0C,0xF8,0x00, // s   115   73
0x10,0x30,0x7C,0x30,0x30,0x34,0x18,0x00, // t   116   74
0x00,0x00,0xCC,0xCC,0xCC,0xCC,0x76,0x00, // u   117   75
0x00,0x00,0xCC,0xCC,0xCC,0x78,0x30,0x00, // v   118   76
0x00,0x00,0xC6,0xD6,0xFE,0xFE,0x6C,0x00, // w   119   77
0x00,0x00,0xC6,0x6C,0x38,0x6C,0xC6,0x00, // x   120   78
0x00,0x00,0xCC,0xCC,0xCC,0x7C,0x0C,0xF8, // y   121   79
0x00,0x00,0xFC,0x98,0x30,0x64,0xFC,0x00, // z   122   7A
0x1C,0x30,0x30,0xE0,0x30,0x30,0x1C,0x00, // {   123   7B
0x18,0x18,0x18,0x00,0x18,0x18,0x18,0x00, // |   124   7C
0xE0,0x30,0x30,0x1C,0x30,0x30,0xE0,0x00, // }   125   7D
0x76,0xDC,0x00,0x00,0x00,0x00,0x00,0x00, // ~   126   7E
0x00,0x10,0x38,0x6C,0xC6,0xC6,0xFE,0x00, //    127   7F
0x30,0x78,0xCC,0xCC,0xFC,0xCC,0xCC,0x00, // �   128   80
0xFE,0x62,0x60,0x7C,0x66,0x66,0xFC,0x00, // �   129   81
0xFC,0x66,0x66,0x7C,0x66,0x66,0xFC,0x00, // �   130   82
0xFE,0x62,0x60,0x60,0x60,0x60,0xF0,0x00, // �   131   83
0x3C,0x4C,0x4C,0x4C,0x4C,0x4C,0xFE,0x82, // �   132   84
0xFE,0x62,0x68,0x78,0x68,0x62,0xFE,0x00, // �   133   85
0xD6,0xD6,0x54,0x38,0xD6,0xD6,0xD6,0x00, // �   134   86
0x78,0xCC,0x0C,0x38,0x0C,0xCC,0x78,0x00, // �   135   87
0xC6,0xC6,0xCE,0xDE,0xF6,0xE6,0xC6,0x00, // �   136   88
0xD6,0xC6,0xCE,0xDE,0xF6,0xE6,0xC6,0x00, // �   137   89
0xE6,0x66,0x6C,0x78,0x6C,0x66,0xE6,0x00, // �   138   8A
0x3E,0x66,0x66,0x66,0x66,0x66,0xE6,0x00, // �   139   8B
0xC6,0xEE,0xFE,0xFE,0xD6,0xC6,0xC6,0x00, // �   140   8C
0xCC,0xCC,0xCC,0xFC,0xCC,0xCC,0xCC,0x00, // �   141   8D
0x38,0x6C,0xC6,0xC6,0xC6,0x6C,0x38,0x00, // �   142   8E
0xFC,0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0x00, // �   143   8F
0xFC,0x66,0x66,0x7C,0x60,0x60,0xF0,0x00, // �   144   90
0x3C,0x66,0xC0,0xC0,0xC0,0x66,0x3C,0x00, // �   145   91
0xFC,0xB4,0x30,0x30,0x30,0x30,0x78,0x00, // �   146   92
0xCC,0xCC,0xCC,0x7C,0x0C,0xCC,0x78,0x00, // �   147   93
0x7C,0xD6,0xD6,0xD6,0x7C,0x10,0x38,0x00, // �   148   94
0xC6,0xC6,0x6C,0x38,0x38,0x6C,0xC6,0x00, // �   149   95
0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0xFE,0x02, // �   150   96
0xCC,0xCC,0xCC,0xCC,0x7C,0x0C,0x0C,0x00, // �   151   97
0xC6,0xC6,0xC6,0xD6,0xD6,0xD6,0xFE,0x00, // �   152   98
0xC6,0xC6,0xC6,0xD6,0xD6,0xD6,0xFF,0x01, // �   153   99
0xF8,0xB0,0x30,0x3C,0x36,0x36,0x7C,0x00, // �   154   9A
0xC6,0xC6,0xC6,0xE6,0xD6,0xD6,0xE6,0x00, // �   155   9B
0xF0,0x60,0x60,0x7C,0x66,0x66,0xFC,0x00, // �   156   9C
0x78,0xCC,0x06,0x1E,0x06,0xCC,0x78,0x00, // �   157   9D
0xCC,0xD6,0xD6,0xF6,0xD6,0xD6,0xCC,0x00, // �   158   9E
0x7C,0xCC,0xCC,0x7C,0x6C,0xCC,0xCE,0x00, // �   159   9F
0x00,0x00,0x78,0x0C,0x7C,0xCC,0x76,0x00, // �   160   A0
0x1C,0x30,0x60,0x7C,0x66,0x66,0x3C,0x00, // �   161   A1
0x00,0x00,0xFC,0x66,0x7C,0x66,0xFC,0x00, // �   162   A2
0x00,0x00,0xFE,0x62,0x60,0x60,0xF0,0x00, // �   163   A3
0x00,0x00,0x3C,0x4C,0x4C,0x4C,0xFE,0x82, // �   164   A4
0x00,0x00,0x78,0xCC,0xFC,0xC0,0x78,0x00, // �   165   A5
0x00,0x00,0xD6,0xD6,0x7C,0xD6,0xD6,0x00, // �   166   A6
0x00,0x00,0x7C,0xC6,0x0C,0xC6,0x7C,0x00, // �   167   A7
0x00,0x00,0xC6,0xCE,0xD6,0xE6,0xC6,0x00, // �   168   A8
0x38,0x00,0xC6,0xCE,0xD6,0xE6,0xC6,0x00, // �   169   A9
0x00,0x00,0xE6,0x6C,0x78,0x6C,0xE6,0x00, // �   170   AA
0x00,0x00,0x3E,0x66,0x66,0x66,0xE6,0x00, // �   171   AB
0x00,0x00,0xC6,0xEE,0xFE,0xD6,0xC6,0x00, // �   172   AC
0x00,0x00,0xCC,0xCC,0xFC,0xCC,0xCC,0x00, // �   173   AD
0x00,0x00,0x78,0xCC,0xCC,0xCC,0x78,0x00, // �   174   AE
0x00,0x00,0xFC,0xCC,0xCC,0xCC,0xCC,0x00, // �   175   AF
0x22,0x88,0x22,0x88,0x22,0x88,0x22,0x88, // -   176   B0
0x55,0xAA,0x55,0xAA,0x55,0xAA,0x55,0xAA, // -   177   B1
0xDB,0x77,0xDB,0xEE,0xDB,0x77,0xDB,0xEE, // -   178   B2
0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18, // ?   179   B3
0x18,0x18,0x18,0x18,0xF8,0x18,0x18,0x18, // +   180   B4
0x18,0x18,0xF8,0x18,0xF8,0x18,0x18,0x18, // ?   181   B5
0x36,0x36,0x36,0x36,0xF6,0x36,0x36,0x36, // ?   182   B6
0x00,0x00,0x00,0x00,0xFE,0x36,0x36,0x36, // ?   183   B7
0x00,0x00,0xF8,0x18,0xF8,0x18,0x18,0x18, // ?   184   B8
0x36,0x36,0xF6,0x06,0xF6,0x36,0x36,0x36, // ?   185   B9
0x36,0x36,0x36,0x36,0x36,0x36,0x36,0x36, // ?   186   BA
0x00,0x00,0xFE,0x06,0xF6,0x36,0x36,0x36, // ?   187   BB
0x36,0x36,0xF6,0x06,0xFE,0x00,0x00,0x00, // -   188   BC
0x36,0x36,0x36,0x36,0xFE,0x00,0x00,0x00, // -   189   BD
0x18,0x18,0xF8,0x18,0xF8,0x00,0x00,0x00, // -   190   BE
0x00,0x00,0x00,0x00,0xF8,0x18,0x18,0x18, // ?   191   BF
0x18,0x18,0x18,0x18,0x1F,0x00,0x00,0x00, // L   192   C0
0x18,0x18,0x18,0x18,0xFF,0x00,0x00,0x00, // +   193   C1
0x00,0x00,0x00,0x00,0xFF,0x18,0x18,0x18, // T   194   C2
0x18,0x18,0x18,0x18,0x1F,0x18,0x18,0x18, // +   195   C3
0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00, // -   196   C4
0x18,0x18,0x18,0x18,0xFF,0x18,0x18,0x18, // +   197   C5
0x18,0x18,0x1F,0x18,0x1F,0x18,0x18,0x18, // ?   198   C6
0x36,0x36,0x36,0x36,0x37,0x36,0x36,0x36, // ?   199   C7
0x36,0x36,0x37,0x30,0x3F,0x00,0x00,0x00, // L   200   C8
0x00,0x00,0x3F,0x30,0x37,0x36,0x36,0x36, // �   201   C9
0x36,0x36,0xF7,0x00,0xFF,0x00,0x00,0x00, // ?   202   CA
0x00,0x00,0xFF,0x00,0xF7,0x36,0x36,0x36, // T   203   CB
0x36,0x36,0x37,0x30,0x37,0x36,0x36,0x36, // ?   204   CC
0x00,0x00,0xFF,0x00,0xFF,0x00,0x00,0x00, // =   205   CD
0x36,0x36,0xF7,0x00,0xF7,0x36,0x36,0x36, // +   206   CE
0x18,0x18,0xFF,0x00,0xFF,0x00,0x00,0x00, // ?   207   CF
0x36,0x36,0x36,0x36,0xFF,0x00,0x00,0x00, // ?   208   D0
0x00,0x00,0xFF,0x00,0xFF,0x18,0x18,0x18, // T   209   D1
0x00,0x00,0x00,0x00,0xFF,0x36,0x36,0x36, // T   210   D2
0x36,0x36,0x36,0x36,0x3F,0x00,0x00,0x00, // L   211   D3
0x18,0x18,0x1F,0x18,0x1F,0x00,0x00,0x00, // L   212   D4
0x00,0x00,0x1F,0x18,0x1F,0x18,0x18,0x18, // -   213   D5
0x00,0x00,0x00,0x00,0x3F,0x36,0x36,0x36, // �   214   D6
0x36,0x36,0x36,0x36,0xFF,0x36,0x36,0x36, // +   215   D7
0x18,0x18,0xFF,0x18,0xFF,0x18,0x18,0x18, // +   216   D8
0x18,0x18,0x18,0x18,0xF8,0x00,0x00,0x00, // -   217   D9
0x00,0x00,0x00,0x00,0x1F,0x18,0x18,0x18, // -   218   DA
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF, // -   219   DB
0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF, // -   220   DC
0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0, // ?   221   DD
0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F, // ?   222   DE
0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00, // -   223   DF
0x00,0x00,0xFC,0x66,0x7C,0x60,0xF0,0x00, // �   224   E0
0x00,0x00,0x78,0xCC,0xC0,0xCC,0x78,0x00, // �   225   E1
0x00,0x00,0xFC,0xB4,0x30,0x30,0x78,0x00, // �   226   E2
0x00,0x00,0xCC,0xCC,0x7C,0x0C,0xF8,0x00, // �   227   E3
0x00,0x00,0x7C,0xD6,0xD6,0x7C,0x10,0x00, // �   228   E4
0x00,0x00,0xC6,0x6C,0x38,0x6C,0xC6,0x00, // �   229   E5
0x00,0x00,0xCC,0xCC,0xCC,0xCC,0x76,0x02, // �   230   E6
0x00,0x00,0xCC,0xCC,0x7C,0x0C,0x0C,0x00, // �   231   E7
0x00,0x00,0xC6,0xC6,0xD6,0xD6,0xFE,0x00, // �   232   E8
0x00,0x00,0xC6,0xC6,0xD6,0xD6,0xFF,0x01, // �   233   E9
0x00,0x00,0xF0,0xB0,0x3C,0x32,0xFC,0x00, // �   234   EA
0x00,0x00,0xC6,0xE6,0xD6,0xD6,0xE6,0x00, // �   235   EB
0x00,0x00,0xE0,0x60,0x7C,0x62,0xFC,0x00, // �   236   EC
0x00,0x00,0xFC,0x06,0x1E,0x06,0xFC,0x00, // �   237   ED
0x00,0x00,0xCC,0xD6,0xF6,0xD6,0xCC,0x00, // �   238   EE
0x00,0x00,0x76,0xCC,0x7C,0x2C,0xCE,0x00, // �   239   EF
0x00,0x7C,0x00,0x7C,0x00,0x7C,0x00,0x00, // �   240   F0
0x30,0x30,0xFC,0x30,0x30,0x00,0xFC,0x00, // �   241   F1
0x60,0x30,0x18,0x30,0x60,0x00,0xFC,0x00, // �   242   F2
0x18,0x30,0x60,0x30,0x18,0x00,0xFC,0x00, // �   243   F3
0x0E,0x1B,0x1B,0x18,0x18,0x18,0x18,0x18, // �   244   F4
0x18,0x18,0x18,0x18,0x18,0xD8,0xD8,0x70, // �   245   F5
0x30,0x30,0x00,0xFC,0x00,0x30,0x30,0x00, // �   246   F6
0x00,0x76,0xDC,0x00,0x76,0xDC,0x00,0x00, // �   247   F7
0x38,0x6C,0x6C,0x38,0x00,0x00,0x00,0x00, // �   248   F8
0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00, //    249   F9
0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x00, // �   250   FA
0x0F,0x0C,0x0C,0x0C,0xEC,0x6C,0x3C,0x1C, // v   251   FB
0x78,0x6C,0x6C,0x6C,0x6C,0x00,0x00,0x00, // �   252   FC
0x70,0x18,0x30,0x60,0x78,0x00,0x00,0x00, // �   253   FD
0x00,0x00,0x3C,0x3C,0x3C,0x3C,0x00,0x00, // ?   254   FE
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00  // �   255   FF
};
