
#include "posapi.h"
#include "pack8583.h"
/*----------------2014-5-20 IP encryption----------------*/
//#ifdef IP_ENCRYPT
#include "global.h"
//#endif
/*----------------2014-5-20 IP encryption----------------*/
/********************** Internal macros declaration ************************/
/********************* Internal functions declaration **********************/
static int PackElement(FIELD_ATTR *pAttr, uchar *pusIn, uchar *pusOut,
                       uint *puiOutLen);
static int UnPackElement(FIELD_ATTR *pAttr, uchar *pusIn, uchar *pusOut,
                         uint *puiInLen);

/*----------------2014-5-20 IP encryption----------------*/
#ifdef IP_ENCRYPT
static EFTSec_Control* stEFTSec_Control;
#endif
/*----------------2014-5-20 IP encryption----------------*/
/********************** Internal variables declaration *********************/
/******************>>>>>>>>>>>>>Implementations<<<<<<<<<<<<*****************/
extern uchar PPDCC_ChkIfDccAcq(void);

// change 8583 struct to 8583 packet
int PubPack8583(FIELD_ATTR *pDataAttr, void *pSt8583, uchar *pusOut, uint *puiOutLen)
{
    int     iRet;
    uint    i, iMsgLen, iDataLen, iFieldLen, uiBitmap;
    uchar   *pusI, *pusO, *pusB;
/*----------------2014-5-20 IP encryption----------------*/
#ifdef IP_ENCRYPT
	uint ulLenOfEFT;
	uint uiStart;
//	uint uiKeyIdx;
#endif
/*----------------2014-5-20 IP encryption----------------*/
    
    pusI        = (uchar *)pSt8583;
    pusO        = pusOut;
    iMsgLen     = 0;
    iDataLen    = 0;
    *puiOutLen  = 0;

   
	if(ChkIfIndirectCupAcq())//fixed by xiehuan20170627
    {
		
		if( ChkIfDsb() || ChkIfCupDsb()) //
		{
			if(glProcInfo.stTranLog.ucTranType == UPLOAD)
			{
				(pDataAttr+54)->eElementAttr = Attr_UnUsed;
				(pDataAttr+55)->eElementAttr = Attr_UnUsed;
				(pDataAttr+56)->eElementAttr = Attr_UnUsed;
				(pDataAttr+60)->eElementAttr = Attr_UnUsed;
				(pDataAttr+61)->eElementAttr = Attr_UnUsed;
				(pDataAttr+62)->eElementAttr = Attr_UnUsed;
				(pDataAttr+63)->eElementAttr = Attr_UnUsed;
				(pDataAttr+64)->eElementAttr = Attr_UnUsed;
		 #ifdef APP_DEBUG_RICHARD
			PubDebugTx("File_%s,LineNo:%d,Function():%s,remove all field after 42 \n",__FILE__,__LINE__, __FUNCTION__);
		 #endif
			}
			else
			{
				(pDataAttr+54)->eElementAttr = Attr_a;
				(pDataAttr+55)->eElementAttr = Attr_b;
		#ifdef ENABLE_EMV
				(pDataAttr+56)->eElementAttr = Attr_b;
		#else
				(pDataAttr+56)->eElementAttr = Attr_UnUsed;   
		#endif
				(pDataAttr+60)->eElementAttr = Attr_a;
				(pDataAttr+61)->eElementAttr = Attr_a;
				(pDataAttr+62)->eElementAttr = Attr_b;
				(pDataAttr+63)->eElementAttr = Attr_b;
				(pDataAttr+64)->eElementAttr = Attr_b;
				if(glProcInfo.stTranLog.ucTranType == LOGON)
				{
					(pDataAttr+60)->eElementAttr = Attr_n;
				}
				else if(glProcInfo.stTranLog.ucTranType == SETTLEMENT)
				{
					(pDataAttr+60)->eElementAttr = Attr_n;
					(pDataAttr+60)->eLengthAttr = Attr_var2;
				}
				else 
				{
					(pDataAttr+60)->eElementAttr = Attr_a;
					(pDataAttr+60)->eLengthAttr = Attr_var2;
					(pDataAttr+60)->uiLength = 22;
				}
			}
		}
		else
		{
			if(glProcInfo.stTranLog.ucTranType == LOGON)
			{
				(pDataAttr+60)->eElementAttr = Attr_n;
			}
			else if(glProcInfo.stTranLog.ucTranType == SETTLEMENT)
			{
				(pDataAttr+60)->eElementAttr = Attr_n;
				(pDataAttr+60)->eLengthAttr = Attr_var2;
			}
			else 
			{
				(pDataAttr+60)->eElementAttr = Attr_a;
				(pDataAttr+60)->eLengthAttr = Attr_var2;
				(pDataAttr+60)->uiLength = 22;
			}
		}

	}//if(ChkIfIndirectCupAcq())
    iRet = PackElement(pDataAttr, pusI, pusO, (uint *)&iFieldLen);

    if( iRet<=0 )
    {
        return -1;
    }
    pusI    += (pDataAttr->uiLength + 2);
    pusO    += iFieldLen;
    iMsgLen += iFieldLen;
    
    /*** generate data and bitmap of 8583 packet ***/
    uiBitmap =  (pDataAttr+1)->uiLength;
    pusI     += (uiBitmap*2);
    pusB     =  pusO;
    
    pusO     += (uiBitmap*2);
    iDataLen =  uiBitmap*2;
    memset(pusB, 0, uiBitmap*2);
    /*----------------2014-5-20 IP encryption----------------*/
#ifdef IP_ENCRYPT
/////jerome
	ulLenOfEFT = 0; //眖材2办56办璸衡┮рmt, bitㄢ办10竊倒┛菠奔
	/////end of jerome;

#endif


/*----------------2014-5-20 IP encryption----------------*/
    for(i=1; i<uiBitmap*2*8; i++)
    {
        if( (pDataAttr+i+1)->eElementAttr==Attr_Over )
        {
            break;
        }
        if( (pDataAttr+i+1)->eElementAttr==Attr_UnUsed )
        {
            continue;
        }
        iRet = PackElement(pDataAttr+i+1, pusI, pusO, (uint *)&iFieldLen);
/*----------------2014-5-20 IP encryption----------------*/
#ifdef IP_ENCRYPT
	
		if (ChkEdcOption(EDC_BEA_IP_ENCRY))  //Gillian 20160923
		{

	/////Jerome
	//		if (i <= 55)     //i=1癸莱材2办55癸莱56办glEdcDefΤ64办既ぃσ納128办薄猵
	//		{
				ulLenOfEFT += iFieldLen; //璸衡盞办
	//		}
			/////end of Jerome;
		}
#endif
/*----------------2014-5-20 IP encryption----------------*/
        if( iRet<0 )
        {
            return ((-1)*(1000+(i+1)));
        }
        if( iRet>0 )
        {
            pusO     += iFieldLen;
            iDataLen += iFieldLen;
            *(pusB+(i/8)) |= (0x80>>(i%8));
        }
		//2011/10/12 Mandy for PPDCC
		//F35 最后一位是F
		if (PPDCC_ChkIfDccAcq())
		{
			if ((i+1) == 35) //build88R: bug fix DCC message
			{
				iRet = strlen(pusI) % 2;
				
				if(iRet)   
				{
					pusB[iDataLen-1] |= 0x0F;
				}
			}
		}
		//end
        pusI+= ((pDataAttr+i+1)->uiLength + 2);
    }
    if( i%((pDataAttr+1)->uiLength*8) )
    {
        return ((-1)*(2000+(i+1)));
    }
    
    /* process bitmap */
    for(i=uiBitmap*2-1; i>=0; i--)
    {
        if(*(pusB+i))
            break;
    }
    if( i>=8 )
    {
        *pusB |= 0x80;
    }
    else
    {
        memmove(pusB+uiBitmap, pusB+uiBitmap*2, iDataLen-uiBitmap*2);
        iDataLen -= uiBitmap;
    }
    
    *puiOutLen = iMsgLen+iDataLen;
    /*----------------2014-5-20 IP encryption----------------*/
#ifdef IP_ENCRYPT
	
	if (ChkEdcOption(EDC_BEA_IP_ENCRY))  //Gillian 20160923
	{
		if (glCurAcq.ucIsSupportKIN == SupportKIN&& glCommCfg.ucCommType==CT_TCPIP)//2014-9-1 only TCP/IP mode need encrypt   //耞Μ虫︽Gillian 20160923
		{
			stEFTSec_Control = &glEFTSec_Control;
			if (stEFTSec_Control->ulEDSKIN != 0)
			{
				uiStart = 10;  //ぃ恨或ゴ材2办ぇ玡ㄢ办琌ゲ斗Τ10竊┮uiStart﹚眖10秨﹍璸衡⊿Τ材2办┪办计沮
				iDataLen += 14;  //2 bytes Message Type id, 5 bytes TPDU, 7 bytes EDS; τ8 bytes bit map竒砆iDataLenいぃ璶
			
				stEFTSec_Control->ulDataLen = iDataLen;
				stEFTSec_Control->ulEDSLength = ulLenOfEFT;	
				if (i>=8)      //secondary bit map 
				{
					stEFTSec_Control->ulEDSStart = uiStart + 8;
				//	stEFTSec_Control->ulEDSLength = ulLenOfEFT-8;	
					//stEFTSec_Control->ulDataLen = iDataLen + 8;
				}
				else
				{
					stEFTSec_Control->ulEDSStart = uiStart;
				}
				/*		memmove(stEFTSec_Control->strTPDUNII, glSendData.sContent+1, 2);
				memmove(stEFTSec_Control->strTPDUSRC, glSendData.sContent+3, 2);
				*/
			
				//iDataLen跑TPDU,EDS, Application盞Pad bytes琌璶σ納э*puiOutLen

			}
		
		}
	}
#endif
/*----------------2014-5-20 IP encryption----------------*/
    return 0;
}


// change 8583 packet to 8583 struct
int PubUnPack8583(FIELD_ATTR *pDataAttr, uchar *pusIn, uint uiInLen, void *pSt8583)
{
    int     iRet;
    uint    i, iLen, iFieldLen, uiBitmap;
    uchar   *pusI, *pusO, *pusB;
    
    pusI = pusIn;
    pusO = (uchar *)pSt8583;
    iLen = 0;
    
    /*** generate message of 8583 struct ***/
    iRet = UnPackElement(pDataAttr, pusI, pusO, (uint *)&iFieldLen);
    if( iRet<0 )
    {
        return -1;
    }
    pusI += iFieldLen;
    pusO += (pDataAttr->uiLength + 2);
    iLen += iFieldLen;
    
    /*** generate data and bitmap of 8583 struct ***/
    pusB = pusI;
    if( pusB[0] & 0x80 )
    {
        uiBitmap = (pDataAttr+1)->uiLength*2;
    }
    else
    {
        uiBitmap= (pDataAttr+1)->uiLength;
    }
    memcpy(pusO, pusB, uiBitmap);
    pusI += uiBitmap;
    pusO += (pDataAttr+1)->uiLength*2;
    iLen += uiBitmap;
    
    for(i=1; i<(uiBitmap*8); i++)
    {
        if( (pDataAttr+i+1)->eElementAttr==Attr_Over )
        {
            return ((-1)*(2000+(i+1)));
        }
        if( *(pusB+i/8) & (0x80>>i%8) )
        {
            if( (pDataAttr+i+1)->eElementAttr==Attr_UnUsed )
            {
                return ((-1)*(2000+(i+1)));
            }
            iRet = UnPackElement(pDataAttr+i+1, pusI, pusO, (uint *)&iFieldLen);
            if( iRet<0 )
            {
                return ((-1)*(1000+(i+1)));
            }
            pusI += iFieldLen;
            iLen += iFieldLen;
        }
        
        if( (pDataAttr+i+1)->eElementAttr==Attr_UnUsed )
        {
            continue;
        }
        pusO += ((pDataAttr+i+1)->uiLength + 2);
    }   /*** for ***/
    
    if( uiInLen!=iLen )
    {
        return ERR_UNPACK_LEN;
    }
    
    return 0;
}


/****************************************************************************
Function:          generate data element of 8583 packet
Param in:
pAttr           struct pointer to define attribute of data element
pusIn           source data
Param out:
pusOut          object data
puiOutLen       bytes of object data
Return Code:
= 0             absent
= 1             present
< 0             length overflow
****************************************************************************/
int PackElement(FIELD_ATTR *pAttr, uchar *pusIn, uchar *pusOut,
                uint *puiOutLen)
{
    uint    i, j, iInLen, iOutLen;
    
    *puiOutLen = 0;
    
    if( pAttr->eElementAttr!=Attr_b )
    {
        iInLen = strlen((char *)pusIn);
    }
    else
    {
        iInLen = ((uint)pusIn[0]<<8) | (uint)pusIn[1];
        pusIn += 2;
    }
    
    if( iInLen<=0 )
    {
        return 0;
    }
    if( iInLen>pAttr->uiLength )
    {
        return -1;
    }
    
    switch( pAttr->eLengthAttr )
    {
    case Attr_fix:
        iOutLen = pAttr->uiLength;
        break;
    case Attr_var1:
        pusOut[0] = ((iInLen/10)<<4) | (iInLen%10);
        pusOut++;
        iOutLen = 1+iInLen;
        break;
    case Attr_var2:
        pusOut[0] = iInLen/100;
        pusOut[1] = (((iInLen%100)/10)<<4) | ((iInLen%100)%10);
        pusOut += 2;
        iOutLen = 2+iInLen;
        break;
    }   /*** switch(pAttr->eLengthAttr ***/
    
    // !!!! warning : multiple level of "switch" logic
    switch( pAttr->eElementAttr )
    {
    case Attr_n:
        switch( pAttr->eLengthAttr )
        {
        case Attr_fix:
            iOutLen= (pAttr->uiLength+1)/2;
            
            memset(pusOut, 0, iOutLen);
            for(i=0,j=0; i<iInLen; i+=2,j++)
            {
                if( i==iInLen-1 )
                {
                    if( toupper(pusIn[iInLen-i-1])<'A' )
                    {
                        pusOut[iOutLen-j-1] = (pusIn[iInLen-i-1]&0x0F);
                    }
                    else
                    {
                        pusOut[iOutLen-j-1] = toupper(pusIn[iInLen-i-1])-'A'+0x0A;
                    }
                }
                else
                {
                    if( toupper(pusIn[iInLen-i-2])<'A' )
                    {
                        pusOut[iOutLen-j-1] = (pusIn[iInLen-i-2]&0x0F)<<4;
                    }
                    else
                    {
                        pusOut[iOutLen-j-1] = (toupper(pusIn[iInLen-i-2])-'A'+0x0A)<<4;
                    }
                    
                    if( toupper(pusIn[iInLen-i-1])<'A' )
                    {
                        pusOut[iOutLen-j-1] |= (pusIn[iInLen-i-1]&0x0F);
                    }
                    else
                    {
                        pusOut[iOutLen-j-1] |= (toupper(pusIn[iInLen-i-1])-'A'+0x0A);
                    }
                }
            }   /*** for(i=0; ***/
            break;
            
        case Attr_var1:
        case Attr_var2:
            iOutLen = iOutLen - iInLen + (iInLen+1)/2;
            
#ifndef VarAttrN_RightJustify
            for(i=0; i<(iInLen+1)/2; i++)
            {
                if( toupper(pusIn[2*i])<'A' )
                {
                    pusOut[i] = (pusIn[2*i]&0x0F)<<4;
                }
                else
                {
                    pusOut[i] = (toupper(pusIn[2*i])-'A'+0x0A)<<4;
                }
                
                if( toupper(pusIn[2*i+1])<'A')
                {
                    pusOut[i] |= (pusIn[2*i+1]&0x0F);
                }
                else
                {
                    pusOut[i] |= (toupper(pusIn[2*i+1])-'A'+0x0A);
                }
#ifdef VarAttrN_PadFToOddLength
                if ((iInLen%2) && (2*(i+1)>iInLen))
                {
                    // length is odd and need pad '0' or 'F' at the end
                    pusOut[i] |= 0x0F;
                }
#endif
            }
            
#else
            memset(pusOut, 0, (iInLen+1)/2);
            for(i=0,j=0; i<iInLen; i+=2,j++)
            {
                if( i==iInLen-1 )
                {
                    if( toupper(pusIn[iInLen-i-1])<'A' )
                    {
                        pusOut[(iInLen+1)/2-j-1] = (pusIn[iInLen-i-1]&0x0F);
                    }
                    else
                    {
                        pusOut[(iInLen+1)/2-j-1] = toupper(pusIn[iInLen-i-1])-'A'+0x0A;
                    }
                }
                else
                {
                    if( toupper(pusIn[iInLen-i-2])<'A' )
                    {
                        pusOut[(iInLen+1)/2-j-1] = (pusIn[iInLen-i-2]&0x0F)<<4;
                    }
                    else
                    {
                        pusOut[(iInLen+1)/2-j-1] = (toupper(pusIn[iInLen-i-2])-'A'+0x0A)<<4;
                    }
                    
                    if( toupper(pusIn[iInLen-i-1])<'A' )
                    {
                        pusOut[(iInLen+1)/2-j-1] |= (pusIn[iInLen-i-1]&0x0F);
                    }
                    else
                    {
                        pusOut[(iInLen+1)/2-j-1] |= (toupper(pusIn[iInLen-i-1])-'A'+0x0A);
                    }
                }
            }   /*** for ***/
#endif
            break;
        }   /*** switch(pAttr->eLengthAttr) ***/
        break;
        
    case Attr_z:
        switch( pAttr->eLengthAttr )
        {
        case Attr_fix:
            iOutLen = (pAttr->uiLength+1)/2;
            
            memset( pusOut, 0, iOutLen );
            for(i=0,j=0; i<iInLen; i+=2,j++)
            {
                if( i==iInLen-1 )
                {
                    pusOut[iOutLen-j-1] = (pusIn[iInLen-i-1]&0x0F);
                }
                else
                {
                    pusOut[iOutLen-j-1] = ((pusIn[iInLen-i-2]&0x0F)<<4) | (pusIn[iInLen-i-1]&0x0F);
                }
            }   /*** for ***/
            break;
            
        case Attr_var1:
        case Attr_var2:
            iOutLen = iOutLen - iInLen + (iInLen+1)/2;
            for(i=0; i<(iInLen+1)/2; i++)
            {
                pusOut[i] = ((pusIn[2*i]&0x0F)<<4) | (pusIn[2*i+1]&0x0F);
            }
            break;
        }   /*** switch(pAttr->eLengthAttr) ***/
        break;
        
    case Attr_b:
        switch( pAttr->eLengthAttr )
        {
        case Attr_fix:
            memset(pusOut, 0, iOutLen);
            memcpy(pusOut, pusIn, iInLen);
            break;
            
        case Attr_var1:
        case Attr_var2:
            memcpy(pusOut, pusIn, iInLen);
            break;
        }
        break;
        
    case Attr_a:
        switch( pAttr->eLengthAttr )
        {
        case Attr_fix:
            memset(pusOut, ' ', iOutLen);
            memcpy(pusOut, pusIn, iInLen);
            break;
            
        case Attr_var1:
        case Attr_var2:
            memcpy(pusOut, pusIn, iInLen);
            break;
        }
        break;
    }    /*** switch(pAttr->eElementAttr) ***/
    
    *puiOutLen = iOutLen;
    
    return 1;
}

/****************************************************************************
Function           generate data element of 8583 struct
Param in:
pAttr           struct pointer to define attribute of data element
pusIn           source data
Param out:
pusOut          object data
puiInLen        bytes of source data to be used
Return Code:
= 0             success
< 0             length overflow
****************************************************************************/
int UnPackElement(FIELD_ATTR *pAttr, uchar *pusIn, uchar *pusOut,
                  uint *puiInLen)
{
    uint    i, j, iInLen, iTmpLen;
    
    memset(pusOut, 0, pAttr->uiLength);
    *puiInLen = 0;
    
    switch( pAttr->eLengthAttr )
    {
    case Attr_fix:
        iInLen  = pAttr->uiLength;
        iTmpLen = iInLen;
        break;
        
    case Attr_var1:
        iTmpLen= (pusIn[0]>>4)*10 + (pusIn[0]&0x0F);
        pusIn++;
        iInLen= 1+iTmpLen;
        break;
        
    case Attr_var2:
        iTmpLen = (pusIn[0]&0x0F)*100 + (pusIn[1]>>4)*10 + (pusIn[1]&0x0F);
        pusIn += 2;
        iInLen = 2+iTmpLen;
        break;
    }   /*** switch(pAttr->eLengthAttr ***/
    
    if( iTmpLen>pAttr->uiLength )
    {
        return -1;
    }
    if( pAttr->eElementAttr==Attr_b )
    {
        pusOut[0] = (uchar)(iTmpLen>>8);
        pusOut[1] = (uchar)iTmpLen;
        pusOut   += 2;
    }
    
    switch( pAttr->eElementAttr )
    {
    case Attr_n:
        switch( pAttr->eLengthAttr )
        {
        case Attr_fix:
            iInLen= (pAttr->uiLength+1)/2;
            
            for(i=0,j=0; i<pAttr->uiLength; i+=2,j++)
            {
                if( (pusIn[iInLen-j-1]&0x0F)<0x0A )
                {
                    pusOut[pAttr->uiLength-i-1] = (pusIn[iInLen-j-1]&0x0F)|0x30;
                }
                else
                {
                    pusOut[pAttr->uiLength-i-1] = (pusIn[iInLen-j-1]&0x0F)-0x0A+'A';
                }
                
                if( i!=pAttr->uiLength-1 )
                {
                    if( (pusIn[iInLen-j-1]>>4)<0x0A )
                    {
                        pusOut[pAttr->uiLength-i-2] = (pusIn[iInLen-j-1]>>4)|0x30;
                    }
                    else
                    {
                        pusOut[pAttr->uiLength-i-2] = (pusIn[iInLen-j-1]>>4)-0x0A+'A';
                    }
                }
            }
            break;
            
        case Attr_var1:
        case Attr_var2:
            iInLen = iInLen - iTmpLen + (iTmpLen+1)/2;
            
#ifndef VarAttrN_RightJustify
            for(i=0; i<(iTmpLen/2); i++)
            {
                if( (pusIn[i]>>4)<0x0A )
                {
                    pusOut[2*i] = (pusIn[i]>>4) | 0x30;
                }else{
                    pusOut[2*i] = (pusIn[i]>>4) -0x0A + 'A';
                }
                
                if( (pusIn[i]&0x0F)<0x0A )
                {
                    pusOut[2*i+1] = (pusIn[i]&0x0F) | 0x30;
                }
                else
                {
                    pusOut[2*i+1] = (pusIn[i]&0x0F) - 0x0A + 'A';
                }
            }
            
            if( iTmpLen%2 )
            {
                if( (pusIn[i]>>4)<0x0A )
                {
                    pusOut[2*i] = (pusIn[i]>>4) | 0x30;
                }
                else
                {
                    pusOut[2*i] = (pusIn[i]>>4) - 0x0A + 'A';
                }
            }
#else
            for(i=0,j=0; i<iTmpLen; i+=2,j++)
            {
                if( (pusIn[(iTmpLen+1)/2-j-1]&0x0F)<0x0A )
                {
                    pusOut[iTmpLen-i-1] = (pusIn[(iTmpLen+1)/2-j-1]&0x0F)|0x30;
                }
                else
                {
                    pusOut[iTmpLen-i-1] = (pusIn[(iTmpLen+1)/2-j-1]&0x0F)-0x0A+'A';
                }
                
                if( i!=pAttr->uiLength-1 )
                {
                    if( (pusIn[(iTmpLen+1)/2-j-1]>>4)<0x0A )
                    {
                        pusOut[iTmpLen-i-2] = (pusIn[(iTmpLen+1)/2-j-1]>>4)|0x30;
                    }
                    else
                    {
                        pusOut[iTmpLen-i-2] = (pusIn[(iTmpLen+1)/2-j-1]>>4)-0x0A+'A';
                    }
                }
            }
#endif
            break;
        }   /*** switch(pAttr->eLengthAttr) ***/
        break;
        
    case Attr_z:
        switch( pAttr->eLengthAttr )
        {
        case Attr_fix:
            iInLen = (pAttr->uiLength+1)/2;
            
            for(i=0,j=0; i<pAttr->uiLength; i+=2,j++)
            {
                pusOut[pAttr->uiLength-i-1] = (pusIn[iInLen-j-1]&0x0F)|0x30;
                if( i!=pAttr->uiLength-1 )
                {
                    pusOut[pAttr->uiLength-i-2]= (pusIn[iInLen-j-1]>>4)|0x30;
                }
            }
            break;
            
        case Attr_var1:
        case Attr_var2:
            iInLen = iInLen - iTmpLen + (iTmpLen+1)/2;
            
            for(i=0; i<(iTmpLen/2); i++)
            {
                pusOut[2*i]   = (pusIn[i]>>4) | 0x30;
                pusOut[2*i+1] = (pusIn[i]&0x0F) | 0x30;
            }
            if( iTmpLen%2 )
            {
                pusOut[2*i] = (pusIn[i]>>4) | 0x30;
            }
            break;
        }   /*** switch(pAttr->eLengthAttr) ***/
        break;
            
    case Attr_b:
        memcpy(pusOut, pusIn, iTmpLen);
        break;
        
    case Attr_a:
        memcpy(pusOut, pusIn, iTmpLen);
        break;
    }    /*** switch(pAttr->eElementAttr) ***/
    
    *puiInLen = iInLen;
    
    return 0;
}

// end of file

