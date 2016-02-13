#include<db.h>

#define bool char
/*
int LoadArray_File(char *PLadFileName, u8 type)
{
    Ladder_Node *pNode;
    int i,j,nRowNum;
    CNCFILE *pfile;
    int nLoadOK=0;
    int tmp=0,k;

    pfile=OpenOSFile(0,PLadFileName, FILEMODE_READ);
    if(pfile==NULL){//不存在则直接退出
           return -2;
    }
    if(type==2){
        CloseOSFile(pfile);
        return 1;
    }
    LadArrayDestroy_File();
    ReadOSFile(pfile,&IntToU8_Obj.Midchar[0],1);
    ReadOSFile(pfile,&IntToU8_Obj.Midchar[1],1);
    nRowNum = IntToU8_Obj.IntValue;

    if(type==0){
        ReadOSFile(pfile, &IntToU8_Obj.Midchar[0],1);
        ReadOSFile(pfile, &IntToU8_Obj.Midchar[1],1);
        Level1RowNum = IntToU8_Obj.IntValue;

        ReadOSFile(pfile, &IntToU8_Obj.Midchar[0],1);
        ReadOSFile(pfile, &IntToU8_Obj.Midchar[1],1);
        DataIndex_LadRun = IntToU8_Obj.IntValue;

        ReadOSFile(pfile, &IntToU8_Obj.Midchar[0],1);
        ReadOSFile(pfile, &IntToU8_Obj.Midchar[1],1);
        Level1StepNum = IntToU8_Obj.IntValue;

        if(LadInfoRead_File(pfile,&LadFileEdit->LadInfoObj)){
            nLoadOK=1;
        }
    }else{
           nLoadOK=1;
    }
    if(nLoadOK==1&&nRowNum>=2&&nRowNum<LadFile_MaxRow){
        NodeMaxRow=IntToU8_Obj.IntValue;//无用
        for(i=0;i<=nRowNum;i++){
            pNode=LadArray_GetRowAdr();
            for(j=0;j<LadFile_Col;j++){
                LadNodeRead_File(pfile,&pNode[j]);
            }
            ReadOSFile(pfile,(unsigned char *)LadRowMeanArray[i], RowNote_StrNum);
            StrMeanUnicodeDeal(LadRowMeanArray[i]);
            LadArray_AddRow(pNode);
            if((pNode[0].m_nType&0xff00)==ndCODT){
                tmp++;
            }else if(tmp>0){
                for(k=i-1;;k--){
                    if((PLadderArrayObj->m_pIndex[k][0].m_nType&0xff00)!=ndCODT)
                        break;
                    for(j = 0; j<LadFile_Col; j++)
                        PLadderArrayObj->m_pIndex[k][j].m_CodtHeight=tmp;
                }
                tmp=0;
            }
        }
        for(i=nRowNum+1;i<LadFile_MaxRow;i++){
            PLadderArrayObj->m_pIndex[i]=LadArrayAddr_Array[i];//先初始化指针,防止以后出现野指针
        }
        if(type==1){
            if(LadInfoRead_File(pfile,&LadFileEdit->LadInfoObj)){
                nLoadOK=1;
            }else{
                nLoadOK=-1;
                LadArrayDestroy_File();
            }
        }
    }else{
        nLoadOK=-1;
    }
    CloseOSFile(pfile);
    VersionConvert();
    return nLoadOK;
}
*/

struct LadFileCell
{

    bool isCreated;                      //是否已经创建此号文件
    char names[13];                      //完整文件名
    int name;
    long size;                               //文件大小
    int LadFileMaxRow;                           //梯图行数
    int LadFileEnd1Row;                    //一级程序行数
    int LadFileAllStep;                           //梯图总步数
    int LadFileEnd1Step;                    //一级程序步数
//    Ladder_Info LadInfoObj;

    int LadFileIsModify;                         //是否需要保存用户对梯图的修改
    int LadFileCurRow;
    int LadFileCurCol;
    int LadFileUpRow;

    int CodTableSize[64][2];
//    bool CtrUseNote[CTRNum];
//    bool TmrUseNote[TMRNum];
//    bool TMRBUseNote[TMRNum];
//    bool LBLUseNote[MAX_PROG_OR_LBL];
//    bool SPUseNote[MAX_PROG_OR_LBL];
//    bool DifuArray[MAX_DIF_CMD];
};
