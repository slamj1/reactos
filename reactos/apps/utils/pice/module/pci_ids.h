/*++

Copyright (c) 1998-2001 Klaus P. Gerlicher

Module Name:

    pci_ids.h

Abstract:

    HEADER, PCI vendor IDs

Environment:

    LINUX 2.2.X
    Kernel mode only

Author: 

    Klaus P. Gerlicher

Revision History:

    15-Nov-2000:    general cleanup of source files

Copyright notice:

  This file may be distributed under the terms of the GNU Public License.

--*/
struct _PCI_VENDOR_IDS
{
    USHORT vendorid;
    char* vendor_name;
}PCIVendorIDs[]=
{
    {0x0033 ,"PARADYNE CORP."},
    {0x003D ,"REAL 3D"},
    {0x0100 ,"NCIPHER CORP. LTD"},
    {0x0A89 ,"BREA TECHNOLOGIES INC"},
    {0x0E11 ,"COMPAQ COMPUTER CORP."},
    {0x1000 ,"SYMBIOS LOGIC INC/LSI LOGIC"},
    {0x1001 ,"KOLTER ELECTRONIC"},
    {0x1002 ,"ATI TECHNOLOGIES INC"},
    {0x1004 ,"VLSI TECHNOLOGY INC"},
    {0x100B ,"NATIONAL SEMICONDUCTOR CORPORATION"},
    {0x1010 ,"VIDEO LOGIC LTD"},
    {0x1014 ,"IBM"},
    {0x1018 ,"UNISYS CORPORATION"},
    {0x1019 ,"ELITEGROUP COMPUTER SYS"},
    {0x101A ,"NCR"},
    {0x101E ,"AMERICAN MEGATRENDS"},
    {0x1020 ,"HITACHI COMPUTER PRODUCTS"},
    {0x1021 ,"OKI ELECTRIC INDUSTRY CO. LTD."},
    {0x1022 ,"ADVANCED MICRO DEVICES"},
    {0x1023 ,"TRIDENT MICROSYSTEMS"},
    {0x1028 ,"DELL COMPUTER CORPORATION"},
    {0x102A ,"LSI LOGIC CORPORATION"},
    {0x102B ,"MATROX GRAPHICS, INC."},
    {0x102F ,"TOSHIBA AMERICA, ELEC. COMPANY"},
    {0x1033 ,"NEC CORPORATION"},
    {0x1038 ,"AMP, INC"},
    {0x1039 ,"SILICON INTEGRATED SYSTEMS"},
    {0x103C ,"HEWLETT PACKARD"},
    {0x103F ,"SYNOPSYS/LOGIC MODELING GROUP"},
    {0x1042 ,"MICRON ELECTRONICS, INC."},
    {0x1043 ,"ASUSTEK COMPUTER, INC."},
    {0x1044 ,"DISTRIBUTED PROCESSING TECHNOLOGY"},
    {0x1045 ,"OPTI INC."},
    {0x1048 ,"ELSA AG"},
    {0x1049 ,"FOUNTAIN TECHNOLOGIES, INC."},
    {0x104C ,"TEXAS INSTRUMENTS"},
    {0x104D ,"SONY CORPORATION"},
    {0x1050 ,"WINBOND ELECTRONICS CORP"},
    {0x1054 ,"HITACHI, LTD"},
    {0x1055 ,"STANDARD MICROSYSTEMS CORP."},
    {0x1057 ,"MOTOROLA"},
    {0x1058 ,"ETRI"},
    {0x1059 ,"TEKNOR INDUSTRIAL COMPUTERS INC"},
    {0x105A ,"PROMISE TECHNOLOGY, INC."},
    {0x105B ,"FOXCONN INTERNATIONAL INC"},
    {0x105D ,"NUMBER 9 VISUAL TECHNOLOGY"},
    {0x105F ,"INFOTRONIC AMERICA INC"},
    {0x1063 ,"OCEAN MANUFACTURING LTD"},
    {0x1064 ,"ALCATEL"},
    {0x1067 ,"MITSUBISHI ELECTRIC AMERICA"},
    {0x1068 ,"DIVERSIFIED TECHNOLOGY"},
    {0x1069 ,"MYLEX CORPORATION"},
    {0x106B ,"APPLE COMPUTER INC."},
    {0x106D ,"SEQUENT COMPUTER SYSTEMS"},
    {0x1070 ,"DAEWOO TELECOM LTD"},
    {0x1071 ,"MITAC"},
    {0x1073 ,"YAMAHA CORPORATION"},
    {0x1077 ,"QLOGIC"},
    {0x1079 ,"I-BUS"},
    {0x107B ,"GATEWAY 2000"},
    {0x107E ,"INTERPHASE CORPORATION"},
    {0x108D ,"OLICOM"},
    {0x1095 ,"CMD TECHNOLOGY INC"},
    {0x1096 ,"ALACRON"},
    {0x1097 ,"APPIAN/ETMA"},
    {0x109A ,"PACKARD BELL NEC"},
    {0x109E ,"BROOKTREE CORPORATION"},
    {0x109F ,"TRIGEM COMPUTER INC."},
    {0x10A0 ,"MEIDENSHA CORPORATION"},
    {0x10A2 ,"QUANTUM EFFECT DESIGN"},
    {0x10A9 ,"SILICON GRAPHICS"},
    {0x10AC ,"HONEYWELL IAC"},
    {0x10AF ,"MICRO COMPUTER SYSTEMS INC"},
    {0x10B5 ,"PLX TECHNOLOGY, INC."},
    {0x10B6 ,"MADGE NETWORKS"},
    {0x10B7 ,"3COM CORPORATION"},
    {0x10B9 ,"ACER LABS INC."},
    {0x10BA ,"MITSUBISHI ELECTRIC CORP."},
    {0x10C2 ,"AUSPEX SYSTEMS INC."},
    {0x10C8 ,"NEOMAGIC CORPORATION"},
    {0x10CA ,"FUJITSU MICROELECTRONIC., INC."},
    {0x10CB ,"OMRON CORPORATION"},
    {0x10CD ,"ADVANCED SYSTEM PRODUCTS, INC"},
    {0x10CF ,"FUJITSU LIMITED"},
    {0x10D1 ,"FUTUREPLUS SYSTEMS CORP."},
    {0x10D2 ,"MOLEX INCORPORATED"},
    {0x10DB ,"ROHM LSI SYSTEMS"},
    {0x10DD ,"EVANS & SUTHERLAND"},
    {0x10DE ,"NVIDIA CORPORATION"},
    {0x10DF ,"EMULEX CORPORATION"},
    {0x10E1 ,"TEKRAM TECHNOLOGY CO.,LTD."},
    {0x10E3 ,"TUNDRA SEMICONDUCTOR CORP."},
    {0x10E5 ,"MICRO INDUSTRIES CORPORATION"},
    {0x10EC ,"REALTEK SEMICONDUCTOR CORP."},
    {0x10EE ,"XILINX, INC."},
    {0x10F1 ,"TYAN COMPUTER"},
    {0x10F5 ,"NKK CORPORATION"},
    {0x10F6 ,"CREATIVE ELECTRONIC SYSTEMS SA"},
    {0x10FC ,"I-O DATA DEVICE, INC."},
    {0x10FE ,"FAST MULTIMEDIA AG"},
    {0x1101 ,"INITIO CORPORATION"},
    {0x1102 ,"CREATIVE LABS"},
    {0x1105 ,"SIGMA DESIGNS, INC"},
    {0x1106 ,"VIA TECHNOLOGIES, INC."},
    {0x1107 ,"ASCEND COMMUNICATIONS, INC."},
    {0x1109 ,"ADAPTEC/COGENT DATA TECHNOLOGIES INC"},
    {0x110A ,"SIEMENS PC SYSTEME GMBH"},
    {0x1111 ,"SANTA CRUZ OPERATION"},
    {0x1113 ,"ACCTON TECHNOLOGY CORPORATION"},
    {0x1116 ,"MEDIA 100, INC"},
    {0x1117 ,"DATACUBE, INC"},
    {0x1118 ,"FCI ELECTRONICS"},
    {0x1119 ,"ICP-VORTEX COMPUTERSYSTEM GMBH"},
    {0x111A ,"EFFICIENT NETWORKS, INC"},
    {0x111D ,"INTEGRATED DEVICE TECH"},
    {0x1120 ,"EMC CORPORATION"},
    {0x1127 ,"FORE SYSTEMS INC"},
    {0x112A ,"HERMES ELECTRONICS COMPANY, LTD."},
    {0x112F ,"IMAGING TECHNOLOGY, INC"},
    {0x1131 ,"PHILIPS SEMICONDUCTORS"},
    {0x1132 ,"MITEL CORP."},
    {0x1133 ,"EICON TECHNOLOGY CORPORATION"},
    {0x1134 ,"MERCURY COMPUTER SYSTEMS"},
    {0x1135 ,"FUJI XEROX CO LTD"},
    {0x1136 ,"MOMENTUM DATA SYSTEMS"},
    {0x1137 ,"CISCO SYSTEMS INC"},
    {0x1138 ,"ZIATECH CORPORATION"},
    {0x113C ,"CYCLONE MICROSYSTEMS, INC."},
    {0x113E ,"SANYO ELECTRIC CO - INFORMATION SYSTEMS DIVISION"},
    {0x1141 ,"CREST MICROSYSTEM INC."},
    {0x1145 ,"WORKBIT CORPORATION"},
    {0x1146 ,"FORCE COMPUTERS GMBH"},
    {0x1148 ,"SYSKONNECT"},
    {0x114C ,"ANNABOOKS"},
    {0x114F ,"DIGI INTERNATIONAL"},
    {0x1154 ,"MELCO INC"},
    {0x115C ,"PHOTRON LTD."},
    {0x115D ,"XIRCOM"},
    {0x1161 ,"PFU LIMITED"},
    {0x1163 ,"RENDITION, A DIVISION OF MICRON"},
    {0x1166 ,"RELIANCE COMPUTER"},
    {0x116E ,"ELECTRONICS FOR IMAGING"},
    {0x1170 ,"INVENTEC CORPORATION"},
    {0x1171 ,"BLUE WAVE SYSTEMS"},
    {0x1172 ,"ALTERA CORPORATION"},
    {0x1179 ,"TOSHIBA AMERICA INFO SYSTEMS"},
    {0x1180 ,"RICOH CO LTD"},
    {0x1186 ,"D-LINK SYSTEM INC"},
    {0x1187 ,"ADVANCED TECHNOLOGY LABORATORIES, INC."},
    {0x1189 ,"MATSUSHITA ELECTIC INDUSTRIAL CO LTD"},
    {0x118B ,"PLATYPUS TECHNOLOGY PTY LTD"},
    {0x118C ,"COROLLARY, INC"},
    {0x1191 ,"ACARD TECHNOLOGY CORP"},
    {0x1195 ,"RATOC SYSTEMS INC"},
    {0x119A ,"MINDSHARE, INC."},
    {0x119D ,"BUG, INC."},
    {0x119E ,"FUJITSU MICROELECTRONICS LTD."},
    {0x119F ,"BULL HN INFORMATION SYSTEMS"},
    {0x11A1 ,"HAMAMATSU PHOTONICS K.K."},
    {0x11A9 ,"INNOSYS"},
    {0x11AA ,"ACTEL"},
    {0x11AB ,"GALILEO TECHNOLOGY LTD."},
    {0x11AD ,"LITE-ON COMMUNICATIONS INC"},
    {0x11AE ,"SCITEX CORPORATION"},
    {0x11AF ,"AVID TECHNOLOGY INC"},
    {0x11B0 ,"V3 SEMICONDUCTOR INC."},
    {0x11B2 ,"EASTMAN KODAK"},
    {0x11B3 ,"BARR SYSTEMS INC."},
    {0x11BF ,"ASTRODESIGN, INC."},
    {0x11C6 ,"DAINIPPON SCREEN MFG. CO. LTD"},
    {0x11C8 ,"DOLPHIN INTERCONNECT SOLUTIONS AS"},
    {0x11C9 ,"MAGMA"},
    {0x11CA ,"LSI SYSTEMS, INC"},
    {0x11CB ,"SPECIALIX INTERNATIONAL LTD"},
    {0x11CE ,"NETACCESS"},
    {0x11D0 ,"LOCKHEED MARTIN - ELECTRONISS & COMMUNICATIONS"},
    {0x11D1 ,"AURAVISION"},
    {0x11D2 ,"INTERCOM INC."},
    {0x11D4 ,"ANALOG DEVICES"},
    {0x11D5 ,"IKON CORPORATION"},
    {0x11D9 ,"TOSHIBA TEC CORPORATION"},
    {0x11DA ,"NOVELL"},
    {0x11DF ,"NEW WAVE PDG"},
    {0x11E3 ,"QUICKLOGIC CORPORATION"},
    {0x11EC ,"CORECO INC"},
    {0x11EE ,"DOME IMAGING SYSTEMS INC"},
    {0x11F8 ,"PMC-SIERRA INC"},
    {0x1203 ,"AGFA CORPORATION"},
    {0x1206 ,"AMDAHL CORPORATION"},
    {0x120F ,"ESSENTIAL COMMUNICATIONS"},
    {0x1214 ,"PERFORMANCE TECHNOLOGIES, INC."},
    {0x1216 ,"PURUP - ESKOFOT A/S"},
    {0x1217 ,"O2MICRO, INC."},
    {0x121A ,"3DFX INTERACTIVE, INC."},
    {0x121B ,"VIRATA LTD"},
    {0x1221 ,"CONTEC CO., LTD"},
    {0x1223 ,"ARTESYN COMMUNICATIONS PRODUCTS INC"},
    {0x1227 ,"TECH-SOURCE"},
    {0x122C ,"SICAN GMBH"},
    {0x1232 ,"MARCONI COMMUNICATIONS LTD"},
    {0x123C ,"CENTURY SYSTEMS, INC."},
    {0x123D ,"ENGINEERING DESIGN TEAM, INC."},
    {0x123F ,"C-CUBE MICROSYSTEMS"},
    {0x1242 ,"JAYCOR NETWORKS INC."},
    {0x1244 ,"AVM AUDIOVISUELLES MKTG & COMPUTER SYSTEM GMBH"},
    {0x124B ,"SBS TECHNOLOGIES"},
    {0x1250 ,"HITACHI ULSI SYSTEMS CO LTD"},
    {0x1253 ,"GUZIK TECHNICAL ENTERPRISES"},
    {0x1255 ,"OPTIBASE LTD"},
    {0x1259 ,"ALLIED TELESYN INTERNATIONAL"},
    {0x125C ,"AURORA TECHNOLOGIES, INC."},
    {0x125F ,"CONCURRENT TECHNOLOGIES"},
    {0x1260 ,"INTERSIL CORP"},
    {0x1261 ,"MATSUSHITA-KOTOBUKI ELECTRONICS INDUSTRIES, LTD."},
    {0x1264 ,"AVAL NAGASAKI CORPORATION"},
    {0x1268 ,"TEKTRONIX"},
    {0x126C ,"NORTEL NETWORKS"},
    {0x126D ,"SPLASH TECHNOLOGY, INC."},
    {0x126E ,"SUMITOMO METAL INDUSTRIES, LTD."},
    {0x126F ,"SILICON MOTION, INC."},
    {0x1270 ,"OLYMPUS OPTICAL CO., LTD."},
    {0x1274 ,"CREATIVE LABS, INC. MALVERN"},
    {0x1275 ,"NETWORK APPLIANCE CORPORATION"},
    {0x1278 ,"TRANSTECH DSP LTD"},
    {0x1279 ,"TRANSMETA CORPORATION"},
    {0x127D ,"VELA RESEARCH LP"},
    {0x127F ,"FUJIFILM"},
    {0x1281 ,"YOKOGAWA ELECTRIC CORPORATION"},
    {0x1283 ,"INTEGRATED TECHNOLOGY EXPRESS, INC."},
    {0x1286 ,"MAZET GMBH"},
    {0x128B ,"TRANSWITCH CORPORATION"},
    {0x128D ,"G2 NETWORKS, INC."},
    {0x128F ,"TATENO DENNOU, INC."},
    {0x1290 ,"TOSHIBA PERSONAL COMPUTER SYSTEM CORP."},
    {0x1291 ,"NCS COMPUTER ITALIA SRL"},
    {0x1292 ,"TRITECH MICROELECTRONICS INC"},
    {0x1297 ,"SHUTTLE COMPUTER"},
    {0x1299 ,"KNOWLEDGE TECHNOLOGY LAB."},
    {0x129A ,"VMETRO, INC."},
    {0x129E ,"VICTOR COMPANY OF JAPAN, LTD."},
    {0x12A0 ,"ALLEN- BRADLEY COMPANY"},
    {0x12A3 ,"LUCENT TECHNOLOGIES"},
    {0x12A7 ,"AMO GMBH"},
    {0x12A9 ,"XIOTECH CORPORATION"},
    {0x12AB ,"YUAN YUAN ENTERPRISE CO., LTD."},
    {0x12AE ,"ALTEON WEBSYSTEMS INC"},
    {0x12B6 ,"NATURAL MICROSYSTEMS"},
    {0x12B7 ,"COGNEX MODULAR VISION SYSTEMS DIV. - ACUMEN INC."},
    {0x12B9 ,"3COM CORP."},
    {0x12BC ,"ARRAY MICROSYSTEMS"},
    {0x12BE ,"ANCHOR CHIPS INC."},
    {0x12BF ,"FUJIFILM MICRODEVICES"},
    {0x12C0 ,"INFIMED"},
    {0x12C3 ,"HOLTEK SEMICONDUCTOR INC"},
    {0x12C4 ,"CONNECT TECH INC"},
    {0x12C6 ,"MITAN CORPORATION"},
    {0x12C7 ,"DIALOGIC CORP"},
    {0x12CA ,"INTEGRATED COMPUTING ENGINES"},
    {0x12CD ,"AIMS LAB"},
    {0x12D3 ,"GE VINGMED ULTRASOUND AS"},
    {0x12D4 ,"COMVERSE NETWORKS SYSTEM & ULTICOM, INC."},
    {0x12D5 ,"EQUATOR TECHNOLOGIES"},
    {0x12D6 ,"ANALOGIC CORP"},
    {0x12D8 ,"PERICOM SEMICONDUCTOR"},
    {0x12D9 ,"ACULAB PLC"},
    {0x12DA ,"TRUE TIME INC."},
    {0x12DE ,"RAINBOW TECHNOLOGIES"},
    {0x12DF ,"SBS TECHNOLOGIES INC"},
    {0x12E0 ,"CHASE RESEARCH"},
    {0x12E2 ,"DATUM INC. BANCOMM-TIMING DIVISION"},
    {0x12E4 ,"BROOKTROUT TECHNOLOGY INC"},
    {0x12E7 ,"SEBRING SYSTEMS, INC"},
    {0x12EA ,"REAL VISION, INC"},
    {0x12EB ,"AUREAL INC."},
    {0x12EC ,"3A INTERNATIONAL, INC."},
    {0x12F0 ,"PENTEK"},
    {0x12F7 ,"COGNEX INC."},
    {0x12FB ,"SPECTRUM SIGNAL PROCESSING"},
    {0x12FC ,"CAPITAL EQUIPMENT CORP"},
    {0x12FE ,"ESD ELECTRONIC SYSTEM DESIGN GMBH"},
    {0x1304 ,"JUNIPER NETWORKS INC."},
    {0x1307 ,"COMPUTER BOARDS"},
    {0x1308 ,"LEVEL ONE COMMUNICATIONS INC"},
    {0x130A ,"MITSUBISHI ELECTRIC MICROCOMPUTER"},
    {0x130B ,"COLORGRAPHIC COMMUNICATIONS CORP"},
    {0x130F ,"ADVANET INC"},
    {0x1310 ,"GESPAC"},
    {0x1313 ,"YASKAWA ELECTRIC CO."},
    {0x1316 ,"TERADYNE INC."},
    {0x1317 ,"ADMTEK INC"},
    {0x1318 ,"PACKET ENGINES INC."},
    {0x1319 ,"FORTEMEDIA, INC"},
    {0x131F ,"SIIG INC"},
    {0x1325 ,"SALIX TECHNOLOGIES INC"},
    {0x1326 ,"SEACHANGE INTERNATIONAL"},
    {0x1331 ,"RADISYS CORP."},
    {0x133D ,"PRISA NETWORKS"},
    {0x133F ,"SCM MICROSYSTEMS"},
    {0x1342 ,"PROMAX SYSTEMS INC"},
    {0x1344 ,"MICRON TECHNOLOGY INC"},
    {0x134B ,"ARK RESEARCH CORP."},
    {0x134C ,"CHORI JOHO SYSTEM CO. LTD"},
    {0x134D ,"PC-TEL INC"},
    {0x135A ,"BRAIN BOXES LIMITED"},
    {0x135C ,"QUATECH INC"},
    {0x135E ,"SEALEVEL SYSTEMS INC"},
    {0x135F ,"I-DATA INTERNATIONAL A-S"},
    {0x1360 ,"MEINBERG FUNKUHREN"},
    {0x1361 ,"SOLITON SYSTEMS K.K."},
    {0x1363 ,"PHOENIX TECHNOLOGIES LTD"},
    {0x1367 ,"HITACHI ZOSEN CORPORATION"},
    {0x1368 ,"SKYWARE CORPORATION"},
    {0x1369 ,"DIGIGRAM"},
    {0x136B ,"KAWASAKI STEEL CORPORATION"},
    {0x136C ,"ADTEK SYSTEM SCIENCE CO LTD"},
    {0x1375 ,"BOEING - SUNNYVALE"},
    {0x1377 ,"ELECTRONIC EQUIPMENT PRODUUTION & DISTRIBUTION GMBH"},
    {0x137A ,"MARK OF THE UNICORN INC"},
    {0x137B ,"PPT VISION"},
    {0x137C ,"IWATSU ELECTRIC CO LTD"},
    {0x137D ,"DYNACHIP CORPORATION"},
    {0x1380 ,"SANRITZ AUTOMATION CO LTC"},
    {0x1381 ,"BRAINS CO. LTD"},
    {0x1383 ,"CONTROLNET INC"},
    {0x1384 ,"STELLAR SEMICONDUCTOR INC"},
    {0x1385 ,"NETGEAR"},
    {0x1387 ,"SYSTRAN CORP"},
    {0x1388 ,"HITACHI INFORMATION TECHNOLOGY CO LTD"},
    {0x1389 ,"APPLICOM INTERNATIONAL"},
    {0x138A ,"SITERA"},
    {0x138B ,"TOKIMEC INC"},
    {0x138E ,"BASLER GMBH"},
    {0x138F ,"PATAPSCO DESIGNS INC"},
    {0x1393 ,"MOXA TECHNOLOGIES CO LTD"},
    {0x1394 ,"LEVEL ONE COMMUNICATIONS"},
    {0x1395 ,"AMBICOM INC"},
    {0x1396 ,"CIPHER SYSTEMS INC"},
    {0x1397 ,"COLOGNE CHIP DESIGNS GMBH"},
    {0x1398 ,"CLARION CO. LTD"},
    {0x1399 ,"RIOS SYSTEMS CO LTD"},
    {0x139A ,"ALACRITECH INC"},
    {0x139C ,"QUANTUM 3D INC"},
    {0x139D ,"XSTREAMS PLC/ EPL LIMITED"},
    {0x139E ,"ECHOSTAR DATA NETWORKS"},
    {0x139F ,"AETHRA S.R.L."},
    {0x13A0 ,"CRYSTAL GROUP INC"},
    {0x13A1 ,"KAWASAKI HEAVY INDUSTRIES LTD"},
    {0x13A2 ,"OSITECH COMMUNICATIONS INC"},
    {0x13A4 ,"RASCOM INC"},
    {0x13A7 ,"TELES AG"},
    {0x13A8 ,"EXAR CORP."},
    {0x13A9 ,"SIEMENS MEDICAL SYSTEMS, ULTRASOUND GROUP"},
    {0x13AA ,"NORTEL NETWORKS - BWA DIVISION"},
    {0x13AF ,"T.SQWARE"},
    {0x13B1 ,"TAMURA CORPORATION"},
    {0x13B4 ,"WELLBEAN CO INC"},
    {0x13B5 ,"ARM LTD"},
    {0x13B6 ,"DLOG GMBH"},
    {0x13B8 ,"NOKIA TELECOMMUNICATIONS OY"},
    {0x13BD ,"SHARP CORPORATION"},
    {0x13BF ,"SHAREWAVE INC"},
    {0x13C1 ,"3WARE INC"},
    {0x13C2 ,"TECHNOTREND SYSTEMTECHNIK GMBH"},
    {0x13C3 ,"JANZ COMPUTER AG"},
    {0x13C6 ,"CONDOR ENGINEERING INC"},
    {0x13C7 ,"BLUE CHIP TECHNOLOGY LTD"},
    {0x13CA ,"IOMEGA CORPORATION"},
    {0x13CC ,"METHEUS CORPORATION"},
    {0x13CF ,"STUDIO AUDIO & VIDEO LTD"},
    {0x13D0 ,"B2C2, INC"},
    {0x13D1 ,"ABOCOM SYSTEMS INC"},
    {0x13D2 ,"SHARK MULTIMEDIA INC"},
    {0x13D3 ,"IMC NETWORKS"},
    {0x13D4 ,"GRAPHICS MICROSYSTEMS INC"},
    {0x13D6 ,"K.I. TECHNOLOGY CO LTD"},
    {0x13D7 ,"TOSHIBA ENGINEERING CORPORATION"},
    {0x13D8 ,"PHOBOS CORPORATION"},
    {0x13D9 ,"APEX INC"},
    {0x13DC ,"NETBOOST CORPORATION"},
    {0x13DE ,"ABB ROBOTICS PRODUCTS AB"},
    {0x13DF ,"E-TECH INC"},
    {0x13E0 ,"GVC CORPORATION"},
    {0x13E3 ,"NEST INC"},
    {0x13E4 ,"CALCULEX INC"},
    {0x13E5 ,"TELESOFT DESIGN LTD"},
    {0x13E9 ,"INTRASERVER TECHNOLOGY INC"},
    {0x13EA ,"DALLAS SEMICONDUCTOR"},
    {0x13F0 ,"SUNDANCE TECHNOLOGY INC"},
    {0x13F1 ,"OCE' - TECHNOLOGIES B.V."},
    {0x13F2 ,"FORD MICROELECTRONICS INC"},
    {0x13F4 ,"TROIKA NETWORKS INC"},
    {0x13F6 ,"C-MEDIA ELECTRONICS INC"},
    {0x13F9 ,"NTT ADVANCED TECHNOLOGY CORP."},
    {0x13FB ,"AYDIN CORP"},
    {0x13FD ,"MICRO SCIENCE INC"},
    {0x1400 ,"ARTX INC"},
    {0x1402 ,"MEILHAUS ELECTRONIC GMBH"},
    {0x1404 ,"FUNDAMENTAL SOFTWARE INC"},
    {0x1406 ,"OCE' PRINTING SYSTEMS GMBH"},
    {0x1407 ,"LAVA COMPUTER MFG INC"},
    {0x1408 ,"ALOKA CO. LTD"},
    {0x140A ,"DSP RESEARCH INC"},
    {0x140B ,"RAMIX INC"},
    {0x140D ,"MATSUSHITA ELECTRIC WORKS LTD"},
    {0x1413 ,"ADDONICS"},
    {0x1415 ,"OXFORD SEMICONDUCTOR LTD"},
    {0x1418 ,"KYUSHU ELECTRONICS SYSTEMS INC"},
    {0x1419 ,"EXCEL SWITCHING CORP"},
    {0x141B ,"ZOOM TELEPHONICS INC"},
    {0x141E ,"FANUC LTD"},
    {0x1420 ,"PSION DACOM PLC"},
    {0x1428 ,"EDEC CO LTD"},
    {0x1429 ,"UNEX TECHNOLOGY CORP."},
    {0x142A ,"KINGMAX TECHNOLOGY INC"},
    {0x142B ,"RADIOLAN"},
    {0x142C ,"MINTON OPTIC INDUSTRY CO LTD"},
    {0x142D ,"PIXSTREAM INC"},
    {0x1430 ,"ITT AEROSPACE/COMMUNICATIONS DIVISION"},
    {0x1433 ,"ELTEC ELEKTRONIK GMBH"},
    {0x1436 ,"CIS TECHNOLOGY INC"},
    {0x1437 ,"NISSIN INC CO"},
    {0x1438 ,"ATMEL-DREAM"},
    {0x143F ,"LIGHTWELL CO LTD - ZAX DIVISION"},
    {0x1441 ,"AGIE SA."},
    {0x1445 ,"LOGICAL CO LTD"},
    {0x1446 ,"GRAPHIN CO. LTD"},
    {0x1447 ,"AIM GMBH"},
    {0x144A ,"ADLINK TECHNOLOGY"},
    {0x144B ,"LORONIX INFORMATION SYSTEMS INC"},
    {0x144D ,"SAMSUNG ELECTRONICS CO LTD"},
    {0x1450 ,"OCTAVE COMMUNICATIONS IND."},
    {0x1451 ,"SP3D CHIP DESIGN GMBH"},
    {0x1453 ,"MYCOM INC"},
    {0x1455 ,"LOGIC PLUS PLUS INC"},
    {0x1458 ,"GIGA-BYTE TECHNOLOGY"},
    {0x145C ,"CRYPTEK"},
    {0x145F ,"BALDOR ELECTRIC COMPANY"},
    {0x1460 ,"DYNARC INC"},
    {0x1462 ,"MICRO-STAR INTERNATIONAL CO LTD"},
    {0x1463 ,"FAST CORPORATION"},
    {0x1464 ,"INTERACTIVE CIRCUITS & SYSTEMS LTD"},
    {0x1465 ,"GN NETTEST TELECOM DIV."},
    {0x1468 ,"AMBIT MICROSYSTEMS CORP."},
    {0x1469 ,"CLEVELAND MOTION CONTROLS"},
    {0x146C ,"RUBY TECH CORP."},
    {0x146D ,"TACHYON, INC."},
    {0x146E ,"WILLIAMS ELECTRONICS GAMES, INC."},
    {0x1471 ,"INTEGRATED TELECOM EXPRESS INC"},
    {0x1473 ,"ZAPEX TECHNOLOGIES INC"},
    {0x1474 ,"DOUG CARSON & ASSOCIATES"},
    {0x1477 ,"NET INSIGHT"},
    {0x1478 ,"DIATREND CORPORATION"},
    {0x147B ,"ABIT COMPUTER CORP."},
    {0x147F ,"NIHON UNISYS, LTD."},
    {0x1482 ,"ISYTEC - INTEGRIERTE SYSTEMTECHNIK GMBH"},
    {0x1483 ,"LABWAY COPORATION"},
    {0x1485 ,"ERMA - ELECTRONIC GMBH"},
    {0x1489 ,"KYE SYSTEMS CORPORATION"},
    {0x148A ,"OPTO 22"},
    {0x148B ,"INNOMEDIALOGIC INC."},
    {0x148E ,"OSI PLUS CORPORATION"},
    {0x148F ,"PLANT EQUIPMENT, INC."},
    {0x1490 ,"TC LABS PTY LTD."},
    {0x1493 ,"MAKER COMMUNICATIONS"},
    {0x1495 ,"TOKAI COMMUNICATIONS INDUSTRY CO. LTD"},
    {0x1496 ,"JOYTECH COMPUTER CO., LTD."},
    {0x1497 ,"SMA REGELSYSTEME GMBH"},
    {0x1499 ,"EMTEC CO., LTD"},
    {0x149A ,"ANDOR TECHNOLOGY LTD"},
    {0x149B ,"SEIKO INSTRUMENTS INC"},
    {0x149C ,"OVISLINK CORP."},
    {0x149D ,"NEWTEK INC"},
    {0x149E ,"MAPLETREE NETWORKS INC."},
    {0x149F ,"LECTRON CO LTD"},
    {0x14A0 ,"SOFTING GMBH"},
    {0x14A1 ,"SYSTEMBASE CO LTD"},
    {0x14A2 ,"MILLENNIUM ENGINEERING INC"},
    {0x14A3 ,"MAVERICK NETWORKS"},
    {0x14A4 ,"GVC/BCM ADVANCED RESEARCH"},
    {0x14A5 ,"XIONICS DOCUMENT TECHNOLOGIES INC."},
    {0x14A6 ,"INOVA COMPUTERS GMBH & CO KG"},
    {0x14A8 ,"FEATRON TECHNOLOGIES CORPORATION"},
    {0x14A9 ,"HIVERTEC INC."},
    {0x14AB ,"MENTOR GRAPHICS CORP."},
    {0x14AC ,"NOVAWEB TECHNOLOGIES INC"},
    {0x14AD ,"TIME SPACE RADIO AB"},
    {0x14AE ,"CTI PET SYSTEMS, INC"},
    {0x14AF ,"GUILLEMOT CORPORATION"},
    {0x14B0 ,"BST COMMUNICATION TECHNOLOGY LTD"},
    {0x14B1 ,"NEXTCOM K.K."},
    {0x14B2 ,"ENNOVATE NETWORKS INC"},
    {0x14B3 ,"XPEED INC."},
    {0x14B4 ,"PHILIPS BUSINESS ELECTRONICS B.V."},
    {0x14B5 ,"CREAMWARE GMBH"},
    {0x14B6 ,"QUANTUM DATA CORP."},
    {0x14B7 ,"PROXIM INC"},
    {0x14B8 ,"TECHSOFT TECHNOLOGY CO LTD"},
    {0x14B9 ,"AIRONET WIRELESS COMMUNICATIONS"},
    {0x14BA ,"INTERNIX INC."},
    {0x14BB ,"SEMTECH CORPORATION"},
    {0x14BC ,"GLOBESPAN SEMICONDUCTOR INC."},
    {0x14BD ,"CARDIO CONTROL N.V."},
    {0x14BE ,"L3 COMMUNICATIONS"},
    {0x14BF ,"SPIDER COMMUNICATIONS INC."},
    {0x14C0 ,"COMPAL ELECTRONICS INC"},
    {0x14C1 ,"MYRICOM INC."},
    {0x14C2 ,"DTK COMPUTER"},
    {0x14C3 ,"MEDIATEK CORP."},
    {0x14C4 ,"IWASAKI INFORMATION SYSTEMS CO LTD"},
    {0x14C5 ,"ABB AUTOMATION PRODUCTS AB"},
    {0x14C6 ,"DATA RACE INC"},
    {0x14C7 ,"MODULAR TECHNOLOY HOLDINGS LTD"},
    {0x14C8 ,"TURBOCOMM TECH. INC."},
    {0x14C9 ,"ODIN TELESYSTEMS INC"},
    {0x14CA ,"PE LOGIC CORP."},
    {0x14CB ,"BILLIONTON SYSTEMS INC./CADMUS MICRO INC."},
    {0x14CC ,"NAKAYO TELECOMMUNICATIONS INC"},
    {0x14CD ,"UNIVERSAL SCIENTIFIC IND."},
    {0x14CE ,"WHISTLE COMMUNICATIONS"},
    {0x14CF ,"TEK MICROSYSTEMS INC."},
    {0x14D0 ,"ERICSSON AXE R & D"},
    {0x14D1 ,"COMPUTER HI-TECH CO LTD"},
    {0x14D2 ,"TITAN ELECTRONICS INC"},
    {0x14D3 ,"CIRTECH (UK) LTD"},
    {0x14D4 ,"PANACOM TECHNOLOGY CORP"},
    {0x14D5 ,"NITSUKO CORPORATION"},
    {0x14D6 ,"ACCUSYS INC"},
    {0x14D7 ,"HIRAKAWA HEWTECH CORP"},
    {0x14D8 ,"HOPF ELEKTRONIK GMBH"},
    {0x14D9 ,"ALPHA PROCESSOR INC"},
    {0x14DA ,"NATIONAL AEROSPACE LABORATORIES"},
    {0x14DB ,"AVLAB TECHNOLOGY INC"},
    {0x14DC ,"AMPLICON LIVELINE LTD"},
    {0x14DD ,"IMODL INC."},
    {0x14DE ,"APPLIED INTEGRATION CORPORATION"},
    {0x14DF ,"BASIS COMMUNICATIONS CORP"},
    {0x14E1 ,"INVERTEX"},
    {0x14E2 ,"INFOLIBRIA"},
    {0x14E3 ,"AMTELCO"},
    {0x14E4 ,"BROADCOM CORPORATION"},
    {0x14E5 ,"PIXELFUSION LTD"},
    {0x14E6 ,"SHINING TECHNOLOGY INC"},
    {0x14E7 ,"3CX"},
    {0x14E8 ,"RAYCER INC"},
    {0x14E9 ,"GARNETS SYSTEM CO LTD"},
    {0x14EA ,"PLANEX COMMUNICATIONS INC"},
    {0x14EB ,"SEIKO EPSON CORPORATION"},
    {0x14EC ,"ACQIRIS"},
    {0x14ED ,"DATAKINETICS LTD"},
    {0x14EE ,"MASPRO KENKOH CORP"},
    {0x14EF ,"CARRY COMPUTER ENG. CO LTD"},
    {0x14F0 ,"CANON RESEACH CENTRE FRANCE"},
    {0x14F1 ,"CONEXANT"},
    {0x14F2 ,"MOBILITY ELECTRONICS"},
    {0x14F3 ,"BROADLOGIC"},
    {0x14F4 ,"TOKYO ELECTRONIC INDUSTRY CO LTD"},
    {0x14F5 ,"SOPAC LTD"},
    {0x14F6 ,"COYOTE TECHNOLOGIES LLC"},
    {0x14F7 ,"WOLF TECHNOLOGY INC"},
    {0x14F8 ,"AUDIOCODES INC"},
    {0x14F9 ,"AG COMMUNICATIONS"},
    {0x14FA ,"WAVETEK WANDEL & GOLTERMANN"},
    {0x14FB ,"TRANSAS MARINE (UK) LTD"},
    {0x14FC ,"QUADRICS SUPERCOMPUTERS WORLD"},
    {0x14FD ,"JAPAN COMPUTER INDUSTRY INC."},
    {0x14FE ,"ARCHTEK TELECOM CORP."},
    {0x14FF ,"TWINHEAD INTERNATIONAL CORP."},
    {0x1500 ,"LANTECH COMPUTER COMPANY"},
    {0x1501 ,"BANKSOFT CANADA LTD"},
    {0x1502 ,"MITSUBISHI ELECTRIC LOGISTICS SUPPORT CO LTD"},
    {0x1503 ,"KAWASAKI LSI USA INC"},
    {0x1504 ,"KAISER ELECTRONICS"},
    {0x1505 ,"ITA INGENIEURBURO FUR TESTAUFGABEN GMBH"},
    {0x1506 ,"CHAMELEON SYSTEMS INC"},
    {0x1507 ,"HTEC LTD"},
    {0x1508 ,"HONDA CONNECTORS/MHOTRONICS INC"},
    {0x1509 ,"FIRST INTERNATIONAL COMPUTER INC"},
    {0x150A ,"FORVUS RESEARCH INC"},
    {0x150B ,"YAMASHITA SYSTEMS CORP"},
    {0x150C ,"KYOPAL CO LTD"},
    {0x150D ,"WARPSPPED INC"},
    {0x150E ,"C-PORT CORPORATION"},
    {0x150F ,"INTEC GMBH"},
    {0x1510 ,"BEHAVIOR TECH COMPUTER CORP"},
    {0x1511 ,"CENTILLIUM TECHNOLOGY CORP"},
    {0x1512 ,"ROSUN TECHNOLOGIES INC"},
    {0x1513 ,"RAYCHEM"},
    {0x1514 ,"TFL LAN INC"},
    {0x1515 ,"ICS ADVENT"},
    {0x1516 ,"MYSON TECHNOLOGY INC"},
    {0x1517 ,"ECHOTEK CORPORATION"},
    {0x1518 ,"PEP MODULAR COMPUTERS GMBH"},
    {0x1519 ,"TELEFON AKTIEBOLAGET LM ERICSSON"},
    {0x151A ,"GLOBETEK INC"},
    {0x151B ,"COMBOX LTD"},
    {0x151C ,"DIGITAL AUDIO LABS INC"},
    {0x151D ,"FUJITSU COMPUTER PRODUCTS OF AMERICA"},
    {0x151E ,"MATRIX CORP."},
    {0x151F ,"TOPIC SEMICONDUCTOR CORP"},
    {0x1520 ,"CHAPLET SYSTEM INC"},
    {0x1521 ,"BELL CORPORATION"},
    {0x1522 ,"MAINPINE LIMITED"},
    {0x1523 ,"MUSIC SEMICONDUCTORS"},
    {0x1524 ,"ENE TECHNOLOGY INC"},
    {0x1525 ,"IMPACT TECHNOLOGIES"},
    {0x1526 ,"ISS, INC"},
    {0x1527 ,"SOLECTRON"},
    {0x1528 ,"ACKSYS"},
    {0x1529 ,"AMERICAN MICROSYSTEMS INC"},
    {0x152A ,"QUICKTURN DESIGN SYSTEMS"},
    {0x152B ,"FLYTECH TECHNOLOGY CO LTD"},
    {0x152C ,"MACRAIGOR SYSTEMS LLC"},
    {0x152D ,"QUANTA COMPUTER INC"},
    {0x152E ,"MELEC INC"},
    {0x152F ,"PHILIPS - CRYPTO"},
    {0x1530 ,"ACQIS TECHNOLOGY INC"},
    {0x1531 ,"CHRYON CORP."},
    {0x1532 ,"ECHELON CORPORATION"},
    {0x1533 ,"BALTIMORE"},
    {0x1534 ,"ROAD CORPORATION"},
    {0x1535 ,"EVERGREEN TECHNOLOGIES INC"},
    {0x1537 ,"DATALEX COMMUNCATIONS"},
    {0x1538 ,"ARALION INC."},
    {0x1539 ,"ATELIER INFORMATIQUES ET ELECTRONIQUE ETUDES S.A."},
    {0x153A ,"ONO SOKKI"},
    {0x153B ,"TERRATEC ELECTRONIC GMBH"},
    {0x153C ,"ANTAL ELECTRONIC"},
    {0x153D ,"FILANET CORPORATION"},
    {0x153E ,"TECHWELL INC"},
    {0x153F ,"MIPS DENMARK"},
    {0x1540 ,"PROVIDEO MULTIMEDIA CO LTD"},
    {0x1541 ,"TELOSITY INC."},
    {0x1542 ,"VIVID TECHNOLOGY INC"},
    {0x1543 ,"SILICON LABORATORIES"},
    {0x1544 ,"DCM DATA SYSTEMS"},
    {0x1545 ,"VISIONTEK"},
    {0x1546 ,"IOI TECHNOLOGY CORP."},
    {0x1547 ,"MITUTOYO CORPORATION"},
    {0x1548 ,"JET PROPULSION LABORATORY"},
    {0x1549 ,"INTERCONNECT SYSTEMS SOLUTIONS"},
    {0x154A ,"MAX TECHNOLOGIES INC."},
    {0x154B ,"COMPUTEX CO LTD"},
    {0x154C ,"VISUAL TECHNOLOGY INC."},
    {0x154D ,"PAN INTERNATIONAL INDUSTRIAL CORP"},
    {0x154E ,"SERVOTEST LTD"},
    {0x154F ,"STRATABEAM TECHNOLOGY"},
    {0x1550 ,"OPEN NETWORK CO LTD"},
    {0x1551 ,"SMART ELECTRONIC DEVELOPMENT GMBH"},
    {0x1552 ,"RACAL AIRTECH LTD"},
    {0x1553 ,"CHICONY ELECTRONICS CO LTD"},
    {0x1554 ,"PROLINK MICROSYSTEMS CORP."},
    {0x1555 ,"GESYTEC GMBH"},
    {0x1556 ,"PLD APPLICATIONS"},
    {0x1557 ,"MEDIASTAR CO. LTD"},
    {0x1558 ,"CLEVO/KAPOK COMPUTER"},
    {0x1559 ,"SI LOGIC LTD"},
    {0x155A ,"INNOMEDIA INC"},
    {0x155B ,"PROTAC INTERNATIONAL CORP"},
    {0x155C ,"CEMAX-ICON INC"},
    {0x155D ,"MAC SYSTEM CO LTD"},
    {0x155E ,"LP ELEKTRONIK GMBH"},
    {0x155F ,"PERLE SYSTEMS LIMITED"},
    {0x1560 ,"TERAYON COMMUNICATIONS SYSTEMS"},
    {0x1561 ,"VIEWGRAPHICS INC"},
    {0x1562 ,"SYMBOL TECHNOLOGIES"},
    {0x1563 ,"A-TREND TECHNOLOGY CO LTD"},
    {0x1564 ,"YAMAKATSU ELECTRONICS INDUSTRY CO LTD"},
    {0x1565 ,"BIOSTAR MICROTECH INT'L CORP"},
    {0x1566 ,"ARDENT TECHNOLOGIES INC"},
    {0x1567 ,"JUNGSOFT"},
    {0x1568 ,"DDK ELECTRONICS INC"},
    {0x1569 ,"PALIT MICROSYSTEMS INC"},
    {0x156A ,"AVTEC SYSTEMS"},
    {0x156B ,"2WIRE, INC"},
    {0x156C ,"VIDAC ELECTRONICS GMBH"},
    {0x156D ,"ALPHA-TOP CORP"},
    {0x156E ,"ALFA INC."},
    {0x156F ,"M-SYSTEMS FLASH DISK PIONEERS LTD"},
    {0x1570 ,"LECROY CORPORATION"},
    {0x1571 ,"CONTEMPORARY CONTROLS"},
    {0x1572 ,"OTIS ELEVATOR COMPANY"},
    {0x1573 ,"LATTICE - VANTIS"},
    {0x1574 ,"FAIRCHILD SEMICONDUCTOR"},
    {0x1575 ,"VOLTAIRE ADVANCED DATA SECURITY LTD"},
    {0x1576 ,"VIEWCAST COM"},
    {0x1578 ,"HITT"},
    {0x1579 ,"DUAL TECHNOLOGY CORPORATION"},
    {0x157A ,"JAPAN ELECRONICS IND. INC"},
    {0x157B ,"STAR MULTIMEDIA CORP."},
    {0x157C ,"EUROSOFT (UK) LTD"},
    {0x157D ,"GEMFLEX NETWORKS"},
    {0x157E ,"TRANSITION NETWORKS"},
    {0x157F ,"PX INSTRUMENTS TECHNOLOGY LTD"},
    {0x1580 ,"PRIMEX AEROSPACE CO."},
    {0x1581 ,"SEH COMPUTERTECHNIK GMBH"},
    {0x1582 ,"CYTEC CORPORATION"},
    {0x1583 ,"INET TECHNOLOGIES INC"},
    {0x1584 ,"UNIWILL COMPUTER CORP."},
    {0x1585 ,"LOGITRON"},
    {0x1586 ,"LANCAST INC"},
    {0x1587 ,"KONICA CORPORATION"},
    {0x1588 ,"SOLIDUM SYSTEMS CORP"},
    {0x1589 ,"ATLANTEK MICROSYSTEMS PTY LTD"},
    {0x158A ,"DIGALOG SYSTEMS INC"},
    {0x158B ,"ALLIED DATA TECHNOLOGIES"},
    {0x158C ,"HITACHI SEMICONDUCTOR & DEVICES SALES CO LTD"},
    {0x158D ,"POINT MULTIMEDIA SYSTEMS"},
    {0x158E ,"LARA TECHNOLOGY INC"},
    {0x158F ,"DITECT COOP"},
    {0x1590 ,"3PARDATA INC."},
    {0x1591 ,"ARN"},
    {0x1592 ,"SYBA TECH LIMITED"},
    {0x1593 ,"BOPS INC"},
    {0x1594 ,"NETGAME LTD"},
    {0x1595 ,"DIVA SYSTEMS CORP."},
    {0x1596 ,"FOLSOM RESEARCH INC"},
    {0x1597 ,"MEMEC DESIGN SERVICES"},
    {0x1598 ,"GRANITE MICROSYSTEMS"},
    {0x1599 ,"DELTA ELECTRONICS INC"},
    {0x159A ,"GENERAL INSTRUMENT"},
    {0x159B ,"FARADAY TECHNOLOGY CORP"},
    {0x159C ,"STRATUS COMPUTER SYSTEMS"},
    {0x159D ,"NINGBO HARRISON ELECTRONICS CO LTD"},
    {0x159E ,"A-MAX TECHNOLOGY CO LTD"},
    {0x159F ,"GALEA NETWORK SECURITY"},
    {0x15A0 ,"COMPUMASTER SRL"},
    {0x15A1 ,"GEOCAST NETWORK SYSTEMS INC"},
    {0x15A2 ,"CATALYST ENTERPRISES INC"},
    {0x15A3 ,"ITALTEL"},
    {0x15A4 ,"X-NET OY"},
    {0x15A5 ,"TOYOTA MACS INC"},
    {0x15A6 ,"SUNLIGHT ULTRASOUND TECHNOLOGIES LTD"},
    {0x15A7 ,"SSE TELECOM INC"},
    {0x15A8 ,"SHANGHAI COMMUNICATIONS TECHNOLOGIES CENTER"},
    {0x15AA ,"MORETON BAY"},
    {0x15AB ,"BLUESTEEL NETWORKS INC"},
    {0x15AC ,"NORTH ATLANTIC INSTRUMENTS"},
    {0x15AD ,"VMWARE"},
    {0x15AE ,"AMERSHAM PHARMACIA BIOTECH"},
    {0x15B0 ,"ZOLTRIX INTERNATIONAL LIMITED"},
    {0x15B1 ,"SOURCE TECHNOLOGY INC"},
    {0x15B2 ,"MOSAID TECHNOLOGIES INC."},
    {0x15B3 ,"MELLANOX TECHNOLOGY"},
    {0x15B4 ,"CCI/TRIAD"},
    {0x15B5 ,"CIMETRICS INC"},
    {0x15B6 ,"TEXAS MEMORY SYSTEMS INC"},
    {0x15B7 ,"SANDISK CORP."},
    {0x15B8 ,"ADDI-DATA GMBH"},
    {0x15B9 ,"MAESTRO DIGITAL COMMUNICATIONS"},
    {0x15BA ,"IMPACCT TECHNOLOGY CORP"},
    {0x15BB ,"PORTWELL INC"},
    {0x15BC ,"AGILENT TECHNOLOGIES"},
    {0x15BD ,"DFI INC."},
    {0x15BE ,"SOLA ELECTRONICS"},
    {0x15BF ,"HIGH TECH COMPUTER CORP (HTC)"},
    {0x15C0 ,"BVM LIMITED"},
    {0x15C1 ,"QUANTEL"},
    {0x15C2 ,"NEWER TECHNOLOGY INC"},
    {0x15C3 ,"TAIWAN MYCOMP CO LTD"},
    {0x15C4 ,"EVSX, INC"},
    {0x15C5 ,"PROCOMP INFORMATICS LTD"},
    {0x15C6 ,"TECHNICAL UNIVERSITY OF BUDAPEST"},
    {0x15C7 ,"TATEYAMA SYSTEM LABORATORY CO LTD"},
    {0x15C8 ,"PENTA MEDIA CO. LTD"},
    {0x15C9 ,"SEROME TECHNOLOGY INC"},
    {0x15CA ,"BITBOYS OY"},
    {0x15CB ,"AG ELECTRONICS LTD"},
    {0x15CC ,"HOTRAIL INC."},
    {0x15CD ,"DREAMTECH CO LTD"},
    {0x15CE ,"GENRAD INC."},
    {0x15CF ,"HILSCHER GMBH"},
    {0x15D1 ,"INFINEON TECHNOLOGIES AG"},
    {0x15D2 ,"FIC (FIRST INTERNATIONAL COMPUTER INC)"},
    {0x15D3 ,"NDS TECHNOLOGIES ISRAEL LTD"},
    {0x15D4 ,"IWILL CORPORATION"},
    {0x15D5 ,"TATUNG CO."},
    {0x15D6 ,"ENTRIDIA CORPORATION"},
    {0x15D7 ,"ROCKWELL-COLLINS, INC"},
    {0x15D8 ,"CYBERNETICS TECHNOLOGY CO LTD"},
    {0x15D9 ,"SUPER MICRO COMPUTER INC"},
    {0x15DA ,"CYBERFIRM INC."},
    {0x15DB ,"APPLIED COMPUTING SYSTEMS INC."},
    {0x15DC ,"LITRONIC INC"},
    {0x15DD ,"SIGMATEL INC."},
    {0x15DE ,"MALLEABLE TECHNOLOGIES INC"},
    {0x15DF ,"INFINILINK CORP."},
    {0x15E0 ,"CACHEFLOW INC"},
    {0x15E1 ,"VOICE TECHNOLOGIES GROUP INC."},
    {0x15E2 ,"QUICKNET TECHNOLOGIES INC"},
    {0x15E3 ,"NETWORTH TECHNOLOGIES INC"},
    {0x15E4 ,"VSN SYSTEMEN BV"},
    {0x15E5 ,"VALLEY TECHNOLOGIES INC"},
    {0x15E6 ,"AGERE INC."},
    {0x15E7 ,"GET ENGINEERING CORP."},
    {0x15E8 ,"NATIONAL DATACOMM CORP."},
    {0x15E9 ,"PACIFIC DIGITAL CORP."},
    {0x15EA ,"TOKYO DENSHI SEKEI K.K."},
    {0x15EB ,"DRSEARCH GMBH"},
    {0x15EC ,"BECKHOFF GMBH"},
    {0x15ED ,"MACROLINK INC"},
    {0x15EE ,"IN WIN DEVELOPMENT INC."},
    {0x15EF ,"INTELLIGENT PARADIGM INC"},
    {0x15F0 ,"B-TREE SYSTEMS INC"},
    {0x15F1 ,"TIMES N SYSTEMS INC"},
    {0x15F2 ,"DIAGNOSTIC INSTRUMENTS INC"},
    {0x15F3 ,"DIGITMEDIA CORP."},
    {0x15F4 ,"VALUESOFT"},
    {0x15F5 ,"POWER MICRO RESEARCH"},
    {0x15F6 ,"EXTREME PACKET DEVICE INC"},
    {0x15F7 ,"BANCTEC"},
    {0x15F8 ,"KOGA ELECTRONICS CO"},
    {0x15F9 ,"ZENITH ELECTRONICS CORPORATION"},
    {0x15FA ,"J.P. AXZAM CORPORATION"},
    {0x15FB ,"ZILOG INC."},
    {0x15FC ,"TECHSAN ELECTRONICS CO LTD"},
    {0x15FD ,"N-CUBED.NET"},
    {0x15FE ,"KINPO ELECTRONICS INC"},
    {0x15FF ,"FASTPOINT TECHNOLOGIES INC."},
    {0x1600 ,"NORTHROP GRUMMAN - CANADA LTD"},
    {0x1601 ,"TENTA TECHNOLOGY"},
    {0x1602 ,"PROSYS-TEC INC."},
    {0x1603 ,"NOKIA WIRELESS BUSINESS COMMUNICATIONS"},
    {0x1604 ,"CENTRAL SYSTEM RESEARCH CO LTD"},
    {0x1605 ,"PAIRGAIN TECHNOLOGIES"},
    {0x1606 ,"EUROPOP AG"},
    {0x1607 ,"LAVA SEMICONDUCTOR MANUFACTURING INC."},
    {0x1608 ,"AUTOMATED WAGERING INTERNATIONAL"},
    {0x1609 ,"SCIEMETRIC INSTRUMENTS INC"},
    {0x1813 ,"AMBIENT TECHNOLOGIES INC"},
    {0x1B13 ,"JATON CORP"},
    {0x2001 ,"TEMPORAL RESEARCH LTD"},
    {0x270F ,"CHAINTECH COMPUTER CO. LTD"},
    {0x3388 ,"HINT CORP"},
    {0x3411 ,"QUANTUM DESIGNS (H.K.) INC."},
    {0x4005 ,"AVANCE LOGIC INC"},
    {0x4033 ,"DELTA NETWORKS INC"},
    {0x416C ,"ALADDIN KNOWLEDGE SYSTEMS"},
    {0x4444 ,"ICOMPRESION INC."},
    {0x4943 ,"GROWTH NETWORKS"},
    {0x4CA1 ,"SEANIX TECHNOLOGY INC"},
    {0x4D51 ,"MEDIAQ INC."},
    {0x4D54 ,"MICROTECHNICA CO LTD"},
    {0x5136 ,"S S TECHNOLOGIES"},
    {0x5333 ,"S3 INC."},
    {0x544C ,"TERALOGIC INC"},
    {0x5555 ,"GENROCO INC"},
    {0x6409 ,"LOGITEC CORP."},
    {0x6666 ,"DECISION COMPUTER INTERNATIONAL CO."},
    {0x8086 ,"INTEL CORP."},
    {0x8888 ,"SILICON MAGIC CORP."},
    {0x8E0E ,"COMPUTONE CORPORATION"},
    {0x9004 ,"ADAPTEC"},
    {0x919A ,"GIGAPIXEL CORP"},
    {0x9699 ,"OMNI MEDIA TECHNOLOGY INC."},
    {0xA0A0 ,"AOPEN INC."},
    {0xA0F1 ,"UNISYS CORPORATION"},
    {0xA259 ,"HEWLETT PACKARD"},
    {0xAC1E ,"DIGITAL RECEIVER TECHNOLOGY INC"},
    {0xC0DE ,"MOTOROLA"},
    {0xC0FE ,"MOTION ENGINEERING, INC."},
    {0xCA50 ,"VARIAN AUSTRIALIA PTY LTD"},
    {0xCAFE ,"CHRYSALIS-ITS"},
    {0xCCCC ,"CATAPULT COMMUNICATIONS"},
    {0xD4D4 ,"DY4 SYSTEMS INC"},
    {0xE4BF ,"EKF ELEKTRONIK GMBH"},
    {0xEA01 ,"EAGLE TECHNOLOGY"},
    {0xFA57 ,"FAST SEARCH & TRANSFER ASA"},
    {0xFEDA ,"EPIGRAM INC"}
};