        /* ISA */

/*
    Output of a Sample Program
    How each Statement Execute line by line.
    value of each register used and flags.
    Output is : 40 (value of register R02
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 33
#define MAX 127
#define M 33

int loc=-1;
int line[100],p=0;
char lbl[100][5];
int R[16]={0};
int sign=0,ovflow=0,zero=0,loc;

void MOV(int val1,int val2)
{
    R[val2]=R[val1];
    printf("MOV Operation is Performed......\n");
    printf("ALU Control Signal :S4 S3 S2 S1 S0 :0 0 0 0 0\n");
    sign=0;
    ovflow=0;
    zero=0;

    printf("Zero Flag = %d \nSign Flag = %d \nOverflow Flag = %d \n",zero,sign,ovflow);
    printf("R[%d]=%d\nR[%d]=%d\n\n",val1,R[val1],val2,R[val2]);

}

void MOVI(int val1,int val2)
{
    R[val2]=val1;
    printf("MOVI Operation is Performed......\n");
    printf("ALU Control Signal : S4 S3 S2 S1 S0 :0 0 0 0 1\n");
    sign=0;
    ovflow=0;
    zero=0;
    printf("Zero Flag = %d \nSign Flag = %d \nOverflow Flag = %d \n",zero,sign,ovflow);
    printf("R[%d]=%d\n\n",val2,R[val2]);
}

void ADD(int val1,int val2)
{
    //R[val2]=R[val1]+R[val2];
    int y=R[val1];
    int x=R[val2];

        while (y != 0)

        {

            int carry = x & y;

            x = x ^ y;

            y = carry << 1;

        }
    R[val2]=x;

    printf("ADD Operation is Performed......\n");
    printf("ALU Control Signal : S4 S3 S2 S1 S0 :0 0 0 1 0\n");
    sign=0;
    if(R[val2]>MAX)
        ovflow=1;
    else
        ovflow=0;
    zero=0;

    printf("Zero Flag = %d \nSign Flag = %d \nOverflow Flag = %d \n",zero,sign,ovflow);
    printf("R[%d]=%d\nR[%d]=%d\n\n",val1,R[val1],val2,R[val2]);
}

void ADDI(int val1,int val2)
{
   // R[val2]=val1+R[val2];

    int y=val1;
    int x=R[val2];

        while (y != 0)

        {

            int carry = x & y;

            x = x ^ y;

            y = carry << 1;

        }
    R[val2]=x;


    printf("ADDI Operation is Performed......\n");
    printf("ALU Control Signal : S4 S3 S2 S1 S0 :0 0 0 1 1\n");
    sign=0;
    if(R[val2]>MAX)
        ovflow=1;
    else
        ovflow=0;
    zero=0;

    printf("Zero Flag = %d \nSign Flag = %d \nOverflow Flag = %d \n",zero,sign,ovflow);
    printf("R[%d]=%d\n\n",val2,R[val2]);
}

void SUB(int val1,int val2)
{
   // R[val2]=R[val2]-R[val1];

    int y=R[val1];
    int x=R[val2];
    while (y != 0)
    {
        // borrow contains common set bits of y and unset
        // bits of x
        int borrow = (~x) & y;

        // Subtraction of bits of x and y where at least
        // one of the bits is not set
        x = x ^ y;

        // Borrow is shifted by one so that subtracting it from
        // x gives the required sum
        y = borrow << 1;
    }
    R[val2]=x;

    printf("SUB Operation is Performed......\n");
    printf("ALU Control Signal :S4 S3 S2 S1 S0 :0 0 1 0 0\n");
    if(R[val2]>MAX)
        ovflow=1;
    else
        ovflow=0;

    if(R[val2]<0)
        sign=1;
    else
        sign=0;
    zero=0;

    printf("Zero Flag = %d \nSign Flag = %d \nOverflow Flag = %d \n",zero,sign,ovflow);
    printf("R[%d]=%d\nR[%d]=%d\n\n",val1,R[val1],val2,R[val2]);
}

void SUBI(int val1,int val2)
{
   // R[val2]=R[val2]-val1;

    int y=val1;
    int x=R[val2];
    while (y != 0)
    {
        // borrow contains common set bits of y and unset
        // bits of x
        int borrow = (~x) & y;

        // Subtraction of bits of x and y where at least
        // one of the bits is not set
        x = x ^ y;

        // Borrow is shifted by one so that subtracting it from
        // x gives the required sum
        y = borrow << 1;
    }
    R[val2]=x;


    printf("SUBI Operation is Performed......\n");
    printf("ALU Control Signal :S4 S3 S2 S1 S0 :0 0 1 0 1\n");
    if(R[val2]>MAX)
        ovflow=1;
    else
        ovflow=0;

    if(R[val2]<0)
        sign=1;
    else
        sign=0;
    zero=0;

    printf("Zero Flag = %d \nSign Flag = %d \nOverflow Flag = %d \n",zero,sign,ovflow);
    printf("R[%d]=%d\n\n",val2,R[val2]);
}

void TEST(int val1,int val2)
{
    R[val2]=R[val2]&R[val1];
    printf("TEST Operation is Performed......\n");
    printf("ALU Control Signal :S4 S3 S2 S1 S0 :0 0 1 1 0\n");
    sign=0;
    ovflow=0;

    if(R[val2]==0)
        zero=1;
    else
        zero=0;

    printf("Zero Flag = %d \nSign Flag = %d \nOverflow Flag = %d \n",zero,sign,ovflow);

}

void TESTI(int val1,int val2)
{
    R[val2]=R[val2]&val1;
    printf("TESTI Operation is Performed......\n");
    printf("ALU Control Signal :S4 S3 S2 S1 S0 :0 0 1 1 1\n");
    sign=0;
    ovflow=0;

    if(R[val2]==0)
        zero=1;
    else
        zero=0;

    printf("Zero Flag = %d \nSign Flag = %d \nOverflow Flag = %d \n",zero,sign,ovflow);
}

void CMP(int val1,int val2)
{
   // int val=R[val2]-R[val1];
    int val;
    int y=R[val1];
    int x=R[val2];
    while (y != 0)
    {
        // borrow contains common set bits of y and unset
        // bits of x
        int borrow = (~x) & y;

        // Subtraction of bits of x and y where at least
        // one of the bits is not set
        x = x ^ y;

        // Borrow is shifted by one so that subtracting it from
        // x gives the required sum
        y = borrow << 1;
    }
    val=x;


    printf("CMP Operation is Performed......\n");
    printf("ALU Control Signal :S4 S3 S2 S1 S0 :0 1 0 0 0\n");
    zero=0;
    sign=0;

    if(val==0)
        zero=1;
    if(val<0)
        sign=1;

    ovflow=0;

    printf("Zero Flag = %d \nSign Flag = %d \nOverflow Flag = %d \n",zero,sign,ovflow);

}

void CMPI(int val1,int val2)
{
    //int val=R[val2]-val1;
    int val;
    int y=val1;
    int x=R[val2];
    while (y != 0)
    {
        // borrow contains common set bits of y and unset
        // bits of x
        int borrow = (~x) & y;

        // Subtraction of bits of x and y where at least
        // one of the bits is not set
        x = x ^ y;

        // Borrow is shifted by one so that subtracting it from
        // x gives the required sum
        y = borrow << 1;
    }
    val=x;


    printf("CMPI Operation is Performed......\n");
    printf("ALU Control Signal :S4 S3 S2 S1 S0 :0 1 0 0 1\n");
    zero=0;
    sign=0;

    if(val==0)
        zero=1;
    if(val<0)
        sign=1;

    ovflow=0;

    printf("Zero Flag = %d \nSign Flag = %d \nOverflow Flag = %d \n",zero,sign,ovflow);
}

void CMPII(int val1,int val2)
{
   // int val=val2-val1;
   int val;

    int y=val1;
    int x=val2;
    while (y != 0)
    {
        // borrow contains common set bits of y and unset
        // bits of x
        int borrow = (~x) & y;

        // Subtraction of bits of x and y where at least
        // one of the bits is not set
        x = x ^ y;

        // Borrow is shifted by one so that subtracting it from
        // x gives the required sum
        y = borrow << 1;
    }
    val=x;


    printf("CMPII Operation is Performed......\n");
    printf("ALU Control Signal :S4 S3 S2 S1 S0 :0 1 0 1 0\n");
    zero=0;
    sign=0;

    if(val==0)
        zero=1;
    if(val<0)
        sign=1;

    ovflow=0;

    printf("Zero Flag = %d \nSign Flag = %d \nOverflow Flag = %d \n",zero,sign,ovflow);

}

void AND(int val1,int val2)
{
    int val=R[val2]&&R[val1];
    printf("AND Operation is Performed......\n");
    printf("ALU Control Signal :S4 S3 S2 S1 S0 :0 1 0 1 1 \n");
    sign=0;
    ovflow=0;
    if(val==0)
        zero=1;
    else
        zero=0;

    printf("Zero Flag = %d \nSign Flag = %d \nOverflow Flag = %d \n",zero,sign,ovflow);
}

void ANDI(int val1,int val2)
{
    int val=R[val2]&&val1;
    printf("ANDI Operation is Performed......\n");
    printf("ALU Control Signal :S4 S3 S2 S1 S0 :0 1 1 0 0 \n");
    sign=0;
    ovflow=0;
    if(val==0)
        zero=1;
    else
        zero=0;

    printf("Zero Flag = %d \nSign Flag = %d \nOverflow Flag = %d \n",zero,sign,ovflow);
}

void MUL(int val1,int val2)
{
    //R[val2]=R[val1]*R[val2];
    int a=R[val1];
    int b=R[val2];
    int result = 0;

    while (b != 0)               // Iterate the loop till b == 0
    {
        if (b & 01)               // Bitwise & of the value of b with 01
        {
            result = result + a;  // Add a to result if b is odd .
        }
        a<<=1;                    // Left shifting the value contained in 'a' by 1
                                  // Multiplies a by 2 for each loop
        b>>=1;                    // Right shifting the value contained in 'b' by 1.
    }

    R[val2]=result;

    printf("MUL Operation is Performed......\n");
    printf("ALU Control Signal :S4 S3 S2 S1 S0 :0 1 1 0 1 \n");
    sign=0;
    if(R[val2]>MAX)
        ovflow=1;
    else
        ovflow=0;
    zero=0;

    printf("Zero Flag = %d \nSign Flag = %d \nOverflow Flag = %d \n",zero,sign,ovflow);
    printf("R[%d]=%d\nR[%d]=%d\n\n",val1,R[val1],val2,R[val2]);
}

void MULI(int val1,int val2)
{
   // R[val2]=R[val2]*val1;

    int a=val1;
    int b=R[val2];
    int result = 0;

    while (b != 0)               // Iterate the loop till b == 0
    {
        if (b & 01)               // Bitwise & of the value of b with 01
        {
            result = result + a;  // Add a to result if b is odd .
        }
        a<<=1;                    // Left shifting the value contained in 'a' by 1
                                  // Multiplies a by 2 for each loop
        b>>=1;                    // Right shifting the value contained in 'b' by 1.
    }

    R[val2]=result;


    printf("MULI Operation is Performed......\n");
    printf("ALU Control Signal :S4 S3 S2 S1 S0 :0 1 1 1 0 \n");
    sign=0;
    if(R[val2]>MAX)
        ovflow=1;
    else
        ovflow=0;
    zero=0;

    printf("Zero Flag = %d \nSign Flag = %d \nOverflow Flag = %d \n",zero,sign,ovflow);
    printf("R[%d]=%d\n\n",val2,R[val2]);
}

void DIV(int val1,int val2)
{
   // R[val2]=R[val2]/R[val1];

    int numerator=R[val2];
    int denominator=R[val1];
    int mask = 0x1;
    int quotient = 0;

    while (denominator <= numerator) {
    denominator <<= 1;
    mask <<= 1;
    }

    while (mask > 1) {
    denominator >>= 1;
    mask >>= 1;
    if (numerator >= denominator) {
    numerator -= denominator;
    quotient |= mask;
    }
    }
    R[val2]=quotient;

    printf("DIV Operation is Performed......\n");
    printf("ALU Control Signal :S4 S3 S2 S1 S0 :0 1 1 1 1 \n");
    sign=0;
    ovflow=0;
    zero=0;

    printf("Zero Flag = %d \nSign Flag = %d \nOverflow Flag = %d \n",zero,sign,ovflow);
    printf("R[%d]=%d\nR[%d]=%d\n\n",val1,R[val1],val2,R[val2]);
}

void DIVI(int val1,int val2)
{
   // R[val2]=R[val2]/val1;

    int numerator=R[val2];
    int denominator=val1;
    int mask = 0x1;
    int quotient = 0;

    while (denominator <= numerator) {
    denominator <<= 1;
    mask <<= 1;
    }

    while (mask > 1) {
    denominator >>= 1;
    mask >>= 1;
    if (numerator >= denominator) {
    numerator -= denominator;
    quotient |= mask;
    }
    }
    R[val2]=quotient;


    printf("DIVI Operation is Performed......\n");
    printf("ALU Control Signal :S4 S3 S2 S1 S0 :1 0 0 0 0\n");

    sign=0;
    ovflow=0;
    zero=0;

    printf("Zero Flag = %d \nSign Flag = %d \nOverflow Flag = %d \n",zero,sign,ovflow);
    printf("R[%d]=%d\n\n",val2,R[val2]);
}

void SAR(int val1,int val2)
{
    R[val2]=R[val2]>>val1;
    printf("SAR Operation is Performed......\n");
    printf("ALU Control Signal :S4 S3 S2 S1 S0 :1 0 0 0 1\n");
    sign=0;
    if(R[val2] > MAX)
        ovflow=1;
    else
        ovflow=0;

    if(R[val2]==0)
        zero=1;
    else
        zero=0;

    printf("Zero Flag = %d \nSign Flag = %d \nOverflow Flag = %d \n",zero,sign,ovflow);
    printf("R[%d]=%d\n\n",val2,R[val2]);

}

void SAL(int val1,int val2)
{
    R[val2]=R[val2]<<val1;
    printf("SAL Operation is Performed......\n");
    printf("ALU Control Signal :S4 S3 S2 S1 S0 :1 0 0 1 0\n");
    sign=0;
    if(R[val2] > MAX)
        ovflow=1;
    else
        ovflow=0;

    if(R[val2]==0)
        zero=1;
    else
        zero=0;

    printf("Zero Flag = %d \nSign Flag = %d \nOverflow Flag = %d \n",zero,sign,ovflow);
    printf("R[%d]=%d\n\n",val2,R[val2]);
}

void SCAN(int val1)
{
    int in;
    printf("Enter Values\n");
    scanf("%d",&in);
    R[val1]=in;
    printf("\nR[%d]=%d\n\n",val1,R[val1]);

}

void PRINT(int val1)
{
    printf("Output : %d\n\n",R[val1]);
}


void JNZ(int val1)
{
    int i;
    if(zero!=1){
    for(i=0;i<p;i++)
    {
        if(strtol(lbl[i],NULL,2)==val1)
            loc=line[i];
    }
    printf("\n");
    }
}


void JMP(int val1)
{
    int i;
    for(i=0;i<p;i++)
    {
        if(strtol(lbl[i],NULL,2)==val1)
            loc=line[i];
    }
    printf("\n");
}

void JZ(int val1)
{
    int i;

    if(zero==1)
    {
        for(i=0;i<p;i++)
        {
            if(strtol(lbl[i],NULL,2)==val1)
                loc=line[i];
        }
        printf("\n");
    }
}

void JG(int val1)
{
    int i;

    if(zero==0 && sign==0 && ovflow==0)
    {
        for(i=0;i<p;i++)
        {
            if(strtol(lbl[i],NULL,2)==val1)
                loc=line[i];
        }
        printf("\n");
    }
}

void HLT()
{
    return;
}

void NOP()
{
    printf("\n");
}


void Chck2Operand(char *st)
{
    int i,k=0;
    char tmp1[M],tmp2[M],op[M];
    int opc,val1,val2;

    for(i=13;i<13+5;i++,k++)
        op[k]=st[i];
    op[k]='\0';
    opc=strtol(op,NULL,2);
    k=0;

    for(i=18;i<18+7;i++,k++)
        tmp1[k]=st[i];
    tmp1[k]='\0';
    val1=strtol(tmp1,NULL,2);
    k=0;

    for(i=18+7;i<strlen(st);i++,k++)
        tmp2[k]=st[i];
    tmp2[k]='\0';
    val2=strtol(tmp2,NULL,2);
    k=0;


    if(opc==strtol("00000",NULL,2))
    {
        MOV(val1,val2);
    }

	else if(opc==strtol("00001",NULL,2))       // %%%I Means Immediate value
		MOVI(val1,val2);

	else if(opc==strtol("00010",NULL,2))
		ADD(val1,val2);

	else if(opc==strtol("00011",NULL,2))
		ADDI(val1,val2);

	else if(opc==strtol("00100",NULL,2))
		SUB(val1,val2);

	else if(opc==strtol("00101",NULL,2))
		SUBI(val1,val2);

	else if(opc==strtol("00110",NULL,2))
		TEST(val1,val2);

	else if(opc==strtol("00111",NULL,2))
		TESTI(val1,val2);

	else if(opc==strtol("01000",NULL,2))
		CMP(val1,val2);

	else if(opc==strtol("01001",NULL,2))
		CMPI(val1,val2);

	else if(opc==strtol("01010",NULL,2))
		CMPII(val1,val2);

    else if(opc==strtol("01011",NULL,2))
		AND(val1,val2);

    else if(opc==strtol("01100",NULL,2))
		ANDI(val1,val2);

    else if(opc==strtol("01101",NULL,2))
		MUL(val1,val2);

    else if(opc==strtol("01110",NULL,2))
		MULI(val1,val2);

    else if(opc==strtol("01111",NULL,2))
		DIV(val1,val2);

    else if(opc==strtol("10000",NULL,2))
		DIVI(val1,val2);

    else if(opc==strtol("10001",NULL,2))
		SAR(val1,val2);

    else //(strcmp(op,"10010")==0)
		SAL(val1,val2);
}


void Chck1Operand(char *st)
{
    char tmp[M],op[M];
    int opc,val1;
    int i,k=0;

    for(i=13;i<13+12;i++,k++)
    {
        op[k]=st[i];
    }
    op[k]='\0';
    opc=strtol(op,NULL,2);
    k=0;

    for(i=13+12;i<strlen(st);i++,k++)
    {
        tmp[k]=st[i];
    }
    tmp[k]='\0';
    val1=strtol(tmp,NULL,2);
    k=0;

	if(opc==strtol("100110000000",NULL,2))
		SCAN(val1);

	else //(strcmp(op,"100110000011")==0)
		PRINT(val1);
}

void Chck1LabelOperand(char *st)
{
    char tmp[M],op[M];
    int opc,val1;
    int i,k=0;

    for(i=13;i<13+16;i++,k++)
    {
        op[k]=st[i];
    }
    op[k]='\0';
    opc=strtol(op,NULL,2);
    k=0;

    for(i=13+16;i<strlen(st);i++,k++)
    {
        tmp[k]=st[i];
    }
    tmp[k]='\0';
    val1=strtol(tmp,NULL,2);
    k=0;

    if(opc==strtol("1001100000100000",NULL,2))
		 JNZ(val1);

	else if(opc==strtol("1001100000100001",NULL,2))
		 JMP(val1);

	else if(opc==strtol("1001100000100010",NULL,2))
		 JZ(val1);

	else //(strcmp(op,"1001100000100011")==0)
		 JG(val1);
}

void Chck0Operand(char *st)
{
    int op;
    op=strtol(st,NULL,2);
    if(op==strtol("1001100000100100000",NULL,2))
		HLT();

	else//(strcmp(st,"1001100001000100001")==0)
		NOP();
}


int ChckTwoAddress(int st)
{
    if(st==strtol("00000",NULL,2))
		return 1;

	else if(st==strtol("00001",NULL,2))       // %%%I Means Immediate value
		return 1;

	else if(st==strtol("00010",NULL,2))
		return 1;

	else if(st==strtol("00011",NULL,2))
		return 1;

	else if(st==strtol("00100",NULL,2))
		return 1;

	else if(st==strtol("00101",NULL,2))
		return 1;

	else if(st==strtol("00110",NULL,2))
		return 1;

	else if(st==strtol("00111",NULL,2))
		return 1;

	else if(st==strtol("01000",NULL,2))
		return 1;

	else if(st==strtol("01001",NULL,2))
		return 1;

	else if(st==strtol("01010",NULL,2))
		return 1;

    else if(st==strtol("01011",NULL,2))
		return 1;

    else if(st==strtol("01100",NULL,2))
		return 1;

    else if(st==strtol("01101",NULL,2))
		return 1;

    else if(st==strtol("01110",NULL,2))
		return 1;

    else if(st==strtol("01111",NULL,2))
		return 1;

    else if(st==strtol("10000",NULL,2))
		return 1;

    else if(st==strtol("10001",NULL,2))
		return 1;

    else if(st==strtol("10010",NULL,2))
		return 1;


	else return -1;
}


int ChckOneAddress(int val)
{
    if(val==strtol("100110000000",NULL,2))
		return 1;

	else if(val==strtol("100110000001",NULL,2))
		return 1;

	else return -1;
}

int ChckOneAddressLabel(int st)
{
    if(st==strtol("1001100000100000",NULL,2))
		return 1;

	else if(st==strtol("1001100000100001",NULL,2))
		return 1;

	else if(st==strtol("1001100000100010",NULL,2))
		return 1;

	else if(st==strtol("1001100000100011",NULL,2))
		return 1;

	else return -1;
}

int ChckZeroAddrress(int st)
{
    if(st==strtol("1001100000100100000",NULL,2))
		return 1;

	else if(st==strtol("1001100000100100001",NULL,2))
		return 1;

    else return -1;
}






void Error_Msg()
{
    printf("Enter Valid Statement\n");
}

void DispOut(char *strr)
{
    int i,k=0;
    char str1[N],str2[N],str0[N],str1l[N];
    int val1,val2,val0,val1l;

    k=0;
    for(i=13;i<13+5;i++)
    {
        str2[k]=strr[i];
        k++;
    }
    str2[k]='\0';
    val2=strtol(str2,NULL,2);

    k=0;
    for(i=13;i<13+12;i++)
    {
        str1[k]=strr[i];
        k++;
    }
    str1[k]='\0';
    val1=strtol(str1,NULL,2);

    k=0;
    for(i=13;i<13+16;i++)
    {
        str1l[k]=strr[i];
        k++;
    }
    str1l[k]='\0';
    val1l=strtol(str1l,NULL,2);

    k=0;
    for(i=13;i<strlen(strr);i++)
    {
        str0[k]=strr[i];
        k++;
    }
    str0[k]='\0';
    val0=strtol(str0,NULL,2);
    k=0;
   /* chck2=ChckTwoAddress(str2);
    chck1=ChckOneAddress(str1);
    chck1l=ChckOneAddressLabel(str1l);
    chck0=ChckZeroAddress(str0);
    */

    if(ChckTwoAddress(val2)!=-1)
    {
        Chck2Operand(strr);
    }
    else if (ChckOneAddress(val1)!=-1)
    {
        Chck1Operand(strr);
    }
    else if (ChckOneAddressLabel(val1l)!=-1)
    {
        Chck1LabelOperand(strr);

    }
    else if (ChckZeroAddrress(val0)!=-1)
    {
        if(val0==strtol("1001100000100100000",NULL,2))
            return;
        else
            Chck0Operand(strr);
    }
    else
    {
        Error_Msg();
    }
}

main()
{
    FILE *fp,*fp2;
    char str[N];
    int count=0,i;

    fp=fopen("machinecode.txt","r");
    fp2=fopen("symbol.txt","r");


    while(fscanf(fp2,"%s",str)!=EOF)
    {
      line[p]=atoi(str);
      fscanf(fp2,"%s",str);
      strcpy(lbl[p],str);
      p++;

      if(fscanf(fp2,"%s",str)==EOF)
        break;
    }

    while(fscanf(fp,"%s",str)!=EOF)
    {
        DispOut(str);
        if(loc!=-1)
        fseek(fp,(loc-1)*33,0);
        loc=-1;
    }

    fclose(fp);
    fclose(fp2);
}
