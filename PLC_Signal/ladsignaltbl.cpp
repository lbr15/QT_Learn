#include "ladsignaltbl.h"
#include <math.h>
//#include <QApplication>

struct SignalTbl iSignalTbl;

volatile u8 PlcSignal_X[64];
volatile u8 PlcSignal_Y[48];
volatile u8 PlcSignal_F[64];
volatile u8 PlcSignal_G[64];

char mm=0;

char kk()
{
    mm++;
    return mm;
}

//=========================================================================//
void SignalTbl_Init(void)
{
   //memset(&iSignalTbl,0,sizeof(iSignalTbl));
}


//=========================================================================//
//DB_R 输入地址范围检查 返回值为是否正确
bool SignalTbl_BitCheck(char chType,U16 addr)
{
	bool bRetval = false;
	
	switch(chType){
		case 'A':  if(addr<ANum)   bRetval = true;   break;
		case 'K':  if(addr<KNum)   bRetval = true;   break;
		case 'F':  if(addr<FNum)   bRetval = true;   break;
		case 'G':  if(addr<GNum)   bRetval = true;   break;
		case 'X':  if(addr<XNum)   bRetval = true;   break;
		case 'Y':  if(addr<YNum)   bRetval = true;   break;
		case 'R':  if(addr<RNum)   bRetval = true;   break;
		default:   bRetval = false;
	}
	return bRetval;
}

//=========================================================================//
bool SignalTbl_AdrCheck(char chType,U16 addr)
{
	bool bRetval = false;
	
	switch(chType){
		case 'A':  if(addr<ANum)   bRetval = true;   break;
		case 'K':  if(addr<KNum)   bRetval = true;   break;
		case 'F':  if(addr<FNum)   bRetval = true;   break;
		case 'G':  if(addr<GNum)   bRetval = true;   break;
		case 'X':  if(addr<XNum)   bRetval = true;   break;
		case 'Y':  if(addr<YNum)   bRetval = true;   break;
		case 'R':  if(addr<RNum)   bRetval = true;   break;
		case 'D':  if(addr<DTblSize)   bRetval = true;   break;
		case 'B':  if(addr<TMRNum)   bRetval = true;   break;
		case 'T':  if((addr/2)<TMRNum)   bRetval = true;   break;
		case 'C':  if((addr/2)<CTRNum)   bRetval = true;   break;
		default:   bRetval = false;
	}
	return bRetval;
}
/*
//=========================================================================//
bool SignalNumCheckError(char *InputStr,int firstbit,int *col,bool bound_adjust)
{
	int sign_regit=0;
	bool error=false;
	int index;
	bool adjust=false;
	char AdjustStr[7]="";
	char tmp[4]="";

	index=strlen(InputStr);	
	if(index>(5+firstbit)||index<(1+firstbit)){   
		error=true;
	}else{
		index=atoi(&InputStr[1]);
		switch(InputStr[0]){      
			case 'F':   if(index>=FNum){ if(bound_adjust){ index=FNum-1; adjust=true; }else error=true;}break;
			case 'G':  if(index>=GNum){ if(bound_adjust){ index=GNum-1; adjust=true; }else error=true;}break;
			case 'X':  if(index>=XNum){ if(bound_adjust){ index=XNum-1; adjust=true; }else error=true;}break;
			case 'Y':  if(index>=YNum){ if(bound_adjust){ index=YNum-1; adjust=true; }else error=true;}break;
			case 'A':  if(index>=ANum){ if(bound_adjust){ index=ANum-1; adjust=true; }else error=true;}break;
			case 'R':  if(index>=RNum){ if(bound_adjust){ index=RNum-1; adjust=true; }else error=true;}break;
			case 'K':  if(index>=KNum){ if(bound_adjust){ index=KNum-1; adjust=true; }else error=true;}break;
			default:  if(InputStr[0]<'0'||InputStr[0]>'9') error=true;break;	  
		}
		if(adjust){ 
			sprintf(tmp,"%03d",index);
			AdjustStr[0]=InputStr[0];
			strcat(AdjustStr,tmp);
		}
		if(!error){
			for(index=firstbit;index<strlen(InputStr);index++){
				if((InputStr[index]<'0'||InputStr[index]>'9')&&InputStr[index]!='.'){ 
					error=true;
					break;
				}
				if(InputStr[index]=='.'){
					if(index==firstbit||sign_regit>0||(strlen(InputStr)-index)!=2) { error=true;break;}
					sign_regit=index;
					if(adjust) AdjustStr[4]='.';
				}
				else if(sign_regit>0){
					if(InputStr[index]>'7'){ if(bound_adjust) InputStr[index]='7';else{ error=true;break;}}
					if(InputStr[index]<'0') { error=true;break;}
					else *col=7-atoi(&InputStr[index]);
					if(adjust) AdjustStr[5]=InputStr[index];
				}
			}
			if(adjust){
//DB_R				CNCStrCpy(InputStr, AdjustStr,7);
                strcpy(InputStr, AdjustStr);
			}
		}
	}
	return error;
}
*/

/*
//=========================================================================//
bool  SignalTbl_SetByte(char chType,U16 addr,U16 Setval)
{   
	if(!SignalTbl_AdrCheck(chType,addr))   
		return 0;  
	
	switch(chType){
		case 'K':  
			PLC_KeepSignal[addr]=(u8)Setval;   
			NvRamCopyToBak((unsigned char *)&PLC_KeepSignal[addr],sizeof(U8));	
			break;
		case 'F':  
			WriteSignalByte(F_Signal,addr,Setval);
			iSignalTbl.F_CNCInputPMCAddr[addr]=(u8)Setval;   
			break;
		case 'G':  
			WriteSignalByte(G_Signal,addr,Setval);
			iSignalTbl.G_PMCOutCNCAddr[addr]=(u8)Setval;
			break;
		case 'X':  
			WriteSignalByte(X_Signal,addr,Setval);
			iSignalTbl.X_MTInputPMCAddr[addr]=(u8)Setval;   
			break;
		case 'Y':  
			WriteSignalByte(Y_Signal,addr,Setval);
			iSignalTbl.Y_PMCOutMTAddr[addr]=(u8)Setval;
			break;
		case 'A':  
			iSignalTbl.A_PMCAlmAddr[addr]=(u8)Setval;
			break;
		case 'R':  
			iSignalTbl.R_PMCAddr[addr]=(u8)Setval;
			break;
		case 'D':  
			DataTbl[addr]=Setval;
			break;
		case 'T':  
			if(addr%2==0) 
				iSignalTbl.TMRVal0[addr/2]=Setval;
			else 
				iSignalTbl.TMRVal1[addr/2]=Setval;
			break;
		case 'C': 
			if(addr%2==0) 
				iSignalTbl.CtrTbl0[addr/2]=Setval;
			else 
				iSignalTbl.CtrTbl1[addr/2]=Setval;
			break;
		default:   return 0;
	}
	return 1;
}
//=========================================================================//
//=========================================================================//
int SignalTbl_ReadByte(char chType,U16 addr)
{
	int Readval;
	
	if(!SignalTbl_AdrCheck(chType,addr))   
		return USERERR; 
	
	switch(chType){
		case 'K':  
			Readval=PLC_KeepSignal[addr];   
			break;
		case 'F':  
			Readval=ReadSignalByte(F_Signal,addr);
			iSignalTbl.F_CNCInputPMCAddr[addr]=Readval;   
			break;
		case 'G':  
			Readval=ReadSignalByte(G_Signal,addr);
			iSignalTbl.G_PMCOutCNCAddr[addr]=Readval;
			break;
		case 'X':  
			Readval=ReadSignalByte(X_Signal,addr);
			iSignalTbl.X_MTInputPMCAddr[addr]=Readval;   
			break;
		case 'Y':  
			Readval=ReadSignalByte(Y_Signal,addr);
			iSignalTbl.Y_PMCOutMTAddr[addr]=Readval;
			break;
		case 'A':  
			Readval=iSignalTbl.A_PMCAlmAddr[addr];
			break;
		case 'R':  
			Readval=iSignalTbl.R_PMCAddr[addr];
			break;
		case 'D':  
			Readval=DataTbl[addr];
			break;
		case 'B':  
			Readval=iSignalTbl.TMRBValue[addr];
			break;
		case 'T':  
			Readval= (addr%2==0) ? iSignalTbl.TMRVal0[addr/2] : iSignalTbl.TMRVal1[addr/2]; 
			break;
		case 'C':  
			Readval= (addr%2==0) ? iSignalTbl.CtrTbl0[addr/2] : iSignalTbl.CtrTbl1[addr/2]; 
			break;
		default:  
			return 0;
	}
	return Readval;  
}
//=========================================================================//
bool SignalTbl_SetBit(char chType,U16 addr,U16 bitpos,U16 value)
{
	if(!SignalTbl_AdrCheck(chType,addr))   
		return false; 

	switch(chType){
		case 'K':  
			if(value>0){ 
				PLC_KeepSignal[addr]|=(u8)ReadBitMap[bitpos];
			}else{
				PLC_KeepSignal[addr]&=(u8)ReadBitMap0[bitpos];
			}
			NvRamCopyToBak((unsigned char *)&PLC_KeepSignal[addr],sizeof(U8));	
			break;
		case 'F':  
			WriteSignalBit(F_Signal,addr,bitpos,value);			
			break;
		case 'G':  
			WriteSignalBit(G_Signal,addr,bitpos,value);			
			break;
		case 'X':  
			WriteSignalBit(X_Signal,addr,bitpos,value);
			break;
		case 'Y':  
			WriteSignalBit(Y_Signal,addr,bitpos,value);			
			break;
		case 'A':  
			if(value>0){ 
				iSignalTbl.A_PMCAlmAddr[addr]|=(u8)ReadBitMap[bitpos];
			}else{
				iSignalTbl.A_PMCAlmAddr[addr]&=(u8)ReadBitMap0[bitpos];
			}
			break;
		case 'R':  
			if(value>0){ 
				iSignalTbl.R_PMCAddr[addr]|=(u8)ReadBitMap[bitpos];
			}else{
				iSignalTbl.R_PMCAddr[addr]&=(u8)ReadBitMap0[bitpos];
			}
			break;
		default:
			return 0;
	}

	return true;	
}
//=========================================================================//
bool SignalTbl_ReadBit(char chType,U16 addr,U16 bitpos)
{
	int getValue=0;
	
	if(!SignalTbl_AdrCheck(chType,addr))   
		return 0;  
	
	switch(chType){
		case 'K':  
			getValue=PLC_KeepSignal[addr]; 
			getValue&=ReadBitMap[bitpos];		
			break;
		case 'F':  
			getValue=ReadSignalBit (F_Signal,addr,bitpos);	
			break;
		case 'G':  
			getValue=ReadSignalBit (G_Signal,addr,bitpos);	
			break;
		case 'X':  
			getValue=ReadSignalBit (X_Signal,addr,bitpos);	
			break;
		case 'Y':  
			getValue=ReadSignalBit (Y_Signal,addr,bitpos);
			break;
		case 'A':  
			getValue=iSignalTbl.A_PMCAlmAddr[addr]; 
			getValue&=ReadBitMap[bitpos];		
			break;
		case 'R':  
			getValue=iSignalTbl.R_PMCAddr[addr]; 
			getValue&=ReadBitMap[bitpos];		
			break;
		default: 
			return 0;
	}
	
	if(getValue!=0) 
		return 1;
	else
		return 0;	
}
//=========================================================================//
bool ReadSignalBit(int chType,U16 addr,U16 bitpos)
{
	U8 getValue=0;
	
	switch(chType){
		case F_Signal:  
			getValue=PlcSignal_F[addr]; 
			getValue&=ReadBitMap[bitpos];		
			break;
		case G_Signal:  
			getValue=PlcSignal_G[addr]; 
			getValue&=ReadBitMap[bitpos];		
			break;
		case X_Signal:  
			getValue = PlcSignal_X[addr]; 
			getValue &= ReadBitMap[bitpos];		
			break;
		case Y_Signal:  
			getValue = PlcSignal_Y[addr]; 
			getValue &= ReadBitMap[bitpos];		
			break;
		default: 
			return 0;
	}
	
	if(getValue!=0) 
		return 1;
	else
		return 0;	
}
//=========================================================================//
void WriteSignalBit(int chType,U16 addr,U16 bitpos,U16 value)
{
	switch(chType){
		case F_Signal:  
			if(value>0){ 
				PlcSignal_F[addr] |= (u8)ReadBitMap[bitpos];
			}else{
				PlcSignal_F[addr] &= (u8)ReadBitMap0[bitpos];
			}
			break;
		case G_Signal:  
			if(value>0){ 
				PlcSignal_G[addr] |= (u8)ReadBitMap[bitpos];
			}else{
				PlcSignal_G[addr] &= (u8)ReadBitMap0[bitpos];
			}
			break;
		case X_Signal:  
			if(value>0){ 
				PlcSignal_X[addr] |= (u8)ReadBitMap[bitpos];
			}else{
				PlcSignal_X[addr] &= (u8)ReadBitMap0[bitpos];
			}
			break;
		case Y_Signal:  
			if(value>0){ 
				PlcSignal_Y[addr] |= (u8)ReadBitMap[bitpos];
			}else{
				PlcSignal_Y[addr] &= (u8)ReadBitMap0[bitpos];
			}
			break;
		default: 
			return;
	}
	
	return;	
}
*/

/*
//=========================================================================//
u8 ReadSignalByte(int chType,U16 addr)
{
	u8 getValue=0;
	
	switch(chType){
		case F_Signal:  
			getValue=PlcSignal_F[addr]; 
			break;
		case G_Signal:  
			getValue=PlcSignal_G[addr]; 
			break;
		case X_Signal:  
			getValue = PlcSignal_X[addr]; 
			break;
		case Y_Signal:  
			getValue = PlcSignal_Y[addr]; 
			break;
		default: 
			return 0;
	}
	return getValue;	
}
//=========================================================================//
void WriteSignalByte(int chType,U16 addr,U16 value)
{
	switch(chType){
		case F_Signal:  
			PlcSignal_F[addr] = value;
			break;
		case G_Signal:  
			PlcSignal_G[addr] = value;
			break;
		case X_Signal:  
			PlcSignal_X[addr] = value;
			break;
		case Y_Signal:  
			PlcSignal_Y[addr] = value;
			break;
		default: 
			return;
	}
	
	return;	
}

*/
