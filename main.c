#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int reverse(char* h)
{
    if (h==NULL) return 51;
    int m = *h;
    int* mas;
    mas = (int*) malloc(8*sizeof(mas[0]));
    if (mas==NULL) return 52;
    int i;
    for (i=0; i<8; i++)
    {
        mas[i]=m%2;
        m=m/2;
    }
    m=0;
    for (i=0; i<8; i++)
    {
        if (mas[i]==1) mas[i] = 0;
        else if (mas[i]==0) mas[i] = 1;
    }
    int a=2;
    for (i=0; i<8; i++)
    {
        m+=mas[i]*(int)pow((double)a,(double)i);
    }
    *h=m;
    free(mas);
    return 0;
}

int Bruce (FILE* file1, int k1)
{
    if (file1==NULL) return 11;
    if (k1==0) return 12;
    int i, j;
    for (i=0; i<k1; i++)
    {
        if (fputc('0', file1) == EOF) return 13;
    }
    if (fseek(file1, 0, SEEK_SET)!=0) return 14;

    for (i=0; i<k1; i++)
    {
        if (fputc('1', file1) == EOF) return 13;
    }
    if (fseek(file1, 0, SEEK_SET)!=0) return 14;

    for (j=0; j<5; j++){
        for (i=0; i<k1; i++)
        {
            char a = rand()%256;
            if (fputc(a, file1) == EOF) return 13;
        }
        if (fseek(file1, 0, SEEK_SET)!=0) return 14;
    }

    return 0;
}

int DOD (FILE* file2, int k2)
{
    if (file2==NULL) return 21;
    if (k2==0) return 22;
    int i, erik;
    char a;
    for (i=0; i<k2; i++)
    {
        a = rand()%256;
        if (fputc(a, file2) == EOF) return 23;
    }
    if(fseek(file2 , 0, SEEK_SET)!=0) return 24;

    char s;
    for (i=0; i<k2; i++)
    {
        if ((s=fgetc(file2))==EOF) return 25;
        if (fseek(file2 , -1, SEEK_CUR)!=0);
        erik=reverse(&s);
        if (erik==51) return 51;
            else if (erik==52) return 52;
        if (fputc(s, file2) == EOF) return 23;
    }
    if(fseek(file2 , 0, SEEK_SET)!=0) return 24;

    for (i=0; i<k2; i++)
    {
        a = rand()%256;
        if (fputc(a, file2) == EOF) return 23;
    }
    if(fseek(file2 , 0, SEEK_SET)!=0) return 24;

    return 0;
}

int ownmethod (FILE* file3, int k3, char* massiv, int kol)
{
    if (file3==NULL) return 31;
    if (k3==0) return 32;
    if (massiv==NULL) return 33;
    if (kol==0) return 34;
    int i, j;
    for (j=0; j<kol; j++)
    {
        for (i=0; i<k3; i++)
        {
            if (fputc(massiv[j], file3) == EOF) return 35;
        }
        if (fseek(file3, 0, SEEK_SET)!=0) return 36;
    }

    return 0;
}

int main()
{
    int kolzat;
    int i;
    char answer[10], check[]="DeLeTe";
    int err;
    if (printf("Enter DeLeTe to destroy the file: ")<0) return 41;
    if (scanf("%[^\n]s", answer)!=1) return 42;
    if (fflush(stdin)!=0) return 43;
    if (printf("\n")<0) return 41;
    if (strcmp(answer, check)!=0)
    {
        return 44;
    }

    char name[100];
    int kol;
    if (printf("Enter the file name: ")<0) return 41;
    if (scanf("%[^\n]s\n\n", name)!=1) return 42;
    if (fflush(stdin)!=0) return 43;
    if (printf("\n")<0) return 41;
    FILE* file;
    if ((file = fopen(name, "r+b")) == NULL)
    {
        return 45;
    }
    if (fseek(file, 0, SEEK_END)!=0) return 46;
    if ((kol=ftell(file))==-1) return 47;
    if(fseek(file, 0, SEEK_SET)!=0) return 46;

    int k;
    if (printf("Choose how you want to destroy the information:\n1. Bruce Schneier's Algorithm\n2. US DoD 5220.22-M\n3. Your own method\nEnter the method number: ")<0) return 41;
    if (scanf("%d", &k)!=1) return 42;
    if (fflush(stdin)!=0) return 43;
    if (printf("\n")<0) return 41;

    switch(k)
    {
    default:
        while ((k<1)||(k>3))
        {
            if (printf("There is no such number in the list!\n")<0) return 41;
            if (printf("Choose how you want to destroy the information:\n1. Bruce Schneier's Algorithm\n2. US DoD 5220.22-M\n3. Your own method\nEnter the method number: ")<0) return 41;
            if (scanf("%d", &k)!=1) return 42;
            if (fflush(stdin)!=0) return 43;
            if (printf("\n")<0) return 41;
        }
    case 1:
        err=Bruce(file, kol);
        if (err==0) {if (printf("The information has been deleted.\n")<0) return 41;}
            else if (err==11) return 11;
                else if (err==12) return 12;
                    else if (err==13) return 13;
                        else if (err==14) return 14;
        break;
    case 2:
        err=DOD(file, kol);
        if (err==0) {if (printf("The information has been deleted.\n")<0) return 41;}
            else if (err==21) return 21;
                else if (err==22) return 22;
                    else if (err==23) return 23;
                        else if (err==24) return 24;
                            else if (err==25) return 25;
                                else if (err==51) return 51;
                                    else if (err==52) return 52;
        break;
    case 3:
        if (printf("Enter the number of mashing: ")<0) return 41;
        if (scanf("%d", &kolzat)!=1) return 42;
        if (fflush(stdin)!=0) return 43;

        char mass[kolzat];
        if (printf("Enter the values with which you will overwrite:\n")<0) return 41;
        for (i=0; i<kolzat; i++)
        {
            if (scanf("%c", &mass[i])!=1) return 42;
            if (fflush(stdin)!=0) return 43;
        }
        err = ownmethod(file, kol, mass, kolzat);
        if (err==0) {if (printf("The information has been deleted.\n")<0) return 41;}
            else if (err==31) return 31;
                else if (err==32) return 32;
                    else if (err==33) return 33;
                        else if (err==34) return 34;
                            else if (err==35) return 35;
        break;
    }

    if (fclose(file)==EOF) return 48;
    return 0;
}
