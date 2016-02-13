#ifndef LADSIGNALTBL_H
#define LADSIGNALTBL_H
#include "def.h"

typedef unsigned char byte;

//DB+   内容在#include "lad_getrun.h"中 =================================//
//======================================================================//
/*=========================================PLC==========================*/
/*=========================================数据表========================*/

#define ANum   32
#define XNum   64
#define YNum   48
#define GNum   64
#define FNum   64
#define KNum   64
#define RNum   512

#define CncDgn_BitNum     90
#define CncDgn_DataNum    90

#define DTblSize 128
#define CTRNum   128
#define TMRNum   128

#define X_Signal  0x08
#define F_Signal  0x28
#define Y_Signal  0x48
#define G_Signal  0x60
#define MAX_USER_DATA_NUM 256
#define MAX_SFT_NUM 128
#define MAX_END1_BUF_NUM 500
#define MAX_PROG_OR_LBL 100
#define MAX_DIF_CMD 256
#define MAX_MOVE_LAD_NUM 100
#define Max_NestingNum 18

#define CodFuncBlockSize  64
#define FuncTypeSize 36
#define PlcSendDataSize   256
#define NodeStrSize 50
#define MCodeMaxRow 98
#define LadFileNum 20
#define MSTMcode_Max  99
#define LadFileSize_Min 480

//======================================================================//
/*==========================PLC=========================================*/
//======================================================================//

struct SignalTbl
{
   byte X_MTInputPMCAddr[XNum];
   byte Y_PMCOutMTAddr[YNum];
   byte F_CNCInputPMCAddr[FNum];
   byte G_PMCOutCNCAddr[GNum];
   byte R_PMCAddr[RNum];
   byte A_PMCAlmAddr[ANum];
   u16  TMRVal0[TMRNum];
   u16  CtrTbl0[CTRNum];
   u16  TMRVal1[TMRNum];
   u16  CtrTbl1[CTRNum];
   u16  TMRBValue[TMRNum];
   int  m_bModified;
};

char kk();

void SignalTbl_Init(void);
bool SignalTbl_BitCheck(char chType,U16 addr);
bool SignalTbl_AdrCheck(char chType,U16 addr);
bool SignalNumCheckError(char *InputStr,int firstbit,int *col,bool bound_adjust);
bool SignalTbl_SetByte(char chType,U16 addr,U16 Setval);
int   SignalTbl_ReadByte(char chType,U16 addr);
bool SignalTbl_SetBit(char chType,U16 addr,U16 bitpos,U16 value);
bool SignalTbl_ReadBit(char chType,U16 addr,U16 bitpos);
bool ReadSignalBit(int chType,U16 addr,U16 bitpos);
void WriteSignalBit(int chType,U16 addr,U16 bitpos,U16 value);
u8 ReadSignalByte(int chType,U16 addr);
void WriteSignalByte(int chType,U16 addr,U16 value);

#endif // LAD_SIGNALTBL_H

