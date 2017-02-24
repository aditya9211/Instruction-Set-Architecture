/*           ISA
                by :   Aditya Sharma 14UCS007

*/

/* Sample Program
    MOVI $15 R01     // Move value 15 to register R01
    MOVI $25 R02    // Move value 25 to register R01
    ADD R02 R01     // Add value R02 = R02 + R01 and store in register R02
    PRINT R02       // Print R02
    HLT             // End of Program
*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define M 70

int flag=0;


char* dec_binary(int num)
{
    int k,c;
    char *binary=(char *)malloc(sizeof(char)*7);
    for (c = 6; c >= 0; c--)
    {
        k = num >> c;

        if (k & 1)
          binary[6-c]='1';
        else
          binary[6-c]='0';
    }
    return binary;

}

char* ChkTwoAddress(char *st)
{

	if(strcmp(st,"MOV")==0)
		return "00000";

	else if(strcmp(st,"MOVI")==0)       // %%%I Means Immediate value
		return "00001";

	else if(strcmp(st,"ADD")==0)
		return "00010";

	else if(strcmp(st,"ADDI")==0)
		return "00011";

	else if(strcmp(st,"SUB")==0)
		return "00100";

	else if(strcmp(st,"SUBI")==0)
		return "00101";

	else if(strcmp(st,"TEST")==0)
		return "00110";

	else if(strcmp(st,"TESTI")==0)
		return "00111";

	else if(strcmp(st,"CMP")==0)
		return "01000";

	else if(strcmp(st,"CMPI")==0)
		return "01001";

	else if(strcmp(st,"CMPII")==0)
		return "01010";

    else if(strcmp(st,"AND")==0)
		return "01011";

    else if(strcmp(st,"ANDI")==0)
		return "01100";

    else if(strcmp(st,"MUL")==0)
		return "01101";

    else if(strcmp(st,"MULI")==0)
		return "01110";

    else if(strcmp(st,"DIV")==0)
		return "01111";

    else if(strcmp(st,"DIVI")==0)
		return "10000";

    else if(strcmp(st,"SAR")==0)
		return "10001";

    else if(strcmp(st,"SAL")==0)
		return "10010";


	else return "-1";

}


char * ChkOneAddress(char *st)
{
	if(strcmp(st,"SCAN")==0)
		return "100110000000";

	else if(strcmp(st,"PRINT")==0)
		return "100110000001";

	else return "-1";
}
char * ChkOneAddandlabel(char *st)
{
	 if(strcmp(st,"JNZ")==0)
		return "1001100000100000";

	else if(strcmp(st,"JMP")==0)
		return "1001100000100001";

	else if(strcmp(st,"JZ")==0)
		return "1001100000100010";

	else if(strcmp(st,"JG")==0)
		return "1001100000100011";


	else return "-1";
}


char * ChkZeroAddress(char * st)
{
	if(strcmp(st,"HLT")==0)
		return "1001100000100100000";

	else if(strcmp(st,"NOP")==0)
		return "1001100000100100001";

	else return "-1";

}


char * ChkReg(char *st)
{
	if(strcmp(st,"R00")==0)
		return "0000000";

	else if(strcmp(st,"R01")==0)
		return "0000001";

	else if(strcmp(st,"R02")==0)
		return "0000010";

	else if(strcmp(st,"R03")==0)
		return "0000011";

	else if(strcmp(st,"R04")==0)
		return "0000100";

	else if(strcmp(st,"R05")==0)
		return "0000101";

	else if(strcmp(st,"R06")==0)
		return "0000110";

	else if(strcmp(st,"R07")==0)
		return "0000111";

	else if(strcmp(st,"R08")==0)
		return "0001000";

	else if(strcmp(st,"R09")==0)
		return "0001001";

	else if(strcmp(st,"R10")==0)
		return "0001010";

	else if(strcmp(st,"R11")==0)
		return "0001011";

	else if(strcmp(st,"R12")==0)
		return "0001100";

	else if(strcmp(st,"R13")==0)
		return "0001101";

	else if(strcmp(st,"R14")==0)
		return "0001110";

	else if(strcmp(st,"R15")==0)
		return "0001111";

	else
		return "-1";
}


char * ChkLabel(char *st)
{
	if(strcmp(st,"L00")==0)
		return "000";

	else if(strcmp(st,"L01")==0)
		return "001";

	else if(strcmp(st,"L02")==0)
		return "010";

	else if(strcmp(st,"L03")==0)
		return "011";

	else if(strcmp(st,"L04")==0)
		return "100";

	else if(strcmp(st,"L05")==0)
		return "101";

	else if(strcmp(st,"L06")==0)
		return "110";

	else if(strcmp(st,"L07")==0)
		return "111";

    else
        return "-1";

}


char  *ChkVal(char *st)
{
	if(atoi(st)>=0 && atoi(st)<128)
		return dec_binary(atoi(st));
		else
        {
            return "-1";
        }
}





void Error_Msg()
{
	fprintf(stdout,"Error in Previous Line\n");
}
char* ChkInputValuesTwoAdd(FILE *f1,char *str1)
{
	if(str1[0]=='$')
	{
		if(strcmp(ChkVal(str1+1),"-1")==0)
        {                                   // No Range should be from [0 to 128)
            flag=1;
            return NULL;
        }
        else
            return ChkVal(str1+1);
	}
	else if(strcmp(ChkReg(str1),"-1")!=0)
			return ChkReg(str1);
	else
    {
        flag=1;
        return NULL;
    }
}
char* ChkInputValuesOneAdd(FILE *f1,char *str1)
{
	if(strcmp(ChkReg(str1),"-1")!=0)
			return ChkReg(str1);
	else
    {
        flag=1;
        return NULL;
    }
}

char* ChkInputValuesLabel(FILE *f1,char *str1)
{
    if(strcmp(ChkLabel(str1),"-1")!=0)
			return ChkLabel(str1);
	else
    {
        flag=1;
        return NULL;
    }
}
void TakeInput(FILE *f1,FILE *f2)
{
	char str1[M],str2[M],str3[M],str4[M],str5[M],str6[M],*str_t1,*str_t2,val1[M],val2[M];
    int count =0,tmp;
	do{
        flag=0;
		fscanf(stdin,"%s",str1);

		strcpy(str2,ChkTwoAddress(str1));
		strcpy(str3,ChkOneAddress(str1));
		strcpy(str4,ChkZeroAddress(str1));
		strcpy(str5,ChkOneAddandlabel(str1));
		strcpy(str6,ChkLabel(str1));

		if(strcmp(str2,"-1")!=0)
		{
			fscanf(stdin,"%s %s",val1,val2);
			str_t1=ChkInputValuesTwoAdd(f1,val1);
			str_t2=ChkInputValuesTwoAdd(f1,val2);
			if(flag==1)
            {
                Error_Msg();
            }
            else
            {
                fprintf(f1,"0000000000000%s%s%s",ChkTwoAddress(str1),str_t1,str_t2);
                fprintf(f1,"\n");
                count++;
            }
		}
		else if(strcmp(str3,"-1")!=0)
		{
			fscanf(stdin,"%s",val1);
			str_t1=ChkInputValuesOneAdd(f1,val1);

			if(flag==1)
            {
                Error_Msg();
            }
            else
            {
                fprintf(f1,"0000000000000%s%s",ChkOneAddress(str1),str_t1);
                fprintf(f1,"\n");
                count++;
            }
		}
		else if(strcmp(str4,"-1")!=0)
		{
			fprintf(f1,"0000000000000%s",ChkZeroAddress(str1));
			if(strcmp(ChkZeroAddress(str1),"1001100000100100000")==0)
               count++;
            else{
			fprintf(f1,"\n");
			count++;
            }
		}
		else if(strcmp(str5,"-1")!=0)
		{
			fscanf(stdin,"%s",val1);
			str_t1=ChkInputValuesLabel(f1,val1);
			if(flag==1)
            {
                Error_Msg();
            }
            else
            {
                fprintf(f1,"0000000000000%s%s",ChkOneAddandlabel(str1),str_t1);
                fprintf(f1,"\n");
                count++;
            }
		}
		else if(strcmp(str6,"-1")!=0)
		{
		    tmp=count+1;
			fprintf(f2,"%d %s %s",tmp,ChkLabel(str1),str1);
			fprintf(f2,"\n");
		}
		else
		{
			gets(val1);
			Error_Msg();
		}

	}while(strcmp(str1,"HLT")!=0);
	}
int main()
{
	FILE *f1,*f2;
	f1=fopen("machinecode.txt","w");
	f2=fopen("symbol.txt","w");
	TakeInput(f1,f2);
	fclose(f1);
	fclose(f2);
	return 0;
}

