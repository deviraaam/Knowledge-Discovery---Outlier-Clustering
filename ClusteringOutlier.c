#include <stdio.h>
#include <math.h>

main(void)
{
    int i,j,k,l,b,a,ranking[200][200],iterasi,loop,newmax,newmin;
    float I[200][200],c[20][20],jarak[200],rank[5],jumlah[5],mean1[200][200],mean2[200][200],mean3[200][200], mean[200][200],kelas[200],kelastesting[200];

    freopen("task1.txt","r",stdin);//if You want to notepad , with name input.txt
    for( int i = 1 ; i <=155; i++ )
    {
        for(j=1; j<=19; j++)
        {
            scanf("%f", &I[i][j]);
        }
        scanf("%f",&kelas[i]);
    }



    //Data Baru yang sudah diNormalisasi Min-Max(0-1)
    //Data Learning
    newmax=1;
    newmin=0;
    for(i=1; i<=155; i++)
    {
        I[i][1]=((I[i][1]-7)*(newmax-newmin))/((78-7)+newmin);
        I[i][14]=((I[i][14]-1)*(newmax-newmin))/((8-1)+newmin);
        I[i][15]=((I[i][15]-26)*(newmax-newmin))/((295-26)+newmin);
        I[i][16]=((I[i][16]-14)*(newmax-newmin))/((648-14)+newmin);
        I[i][17]=((I[i][17]-3)*(newmax-newmin))/((5-3)+newmin);
        I[i][18]=((I[i][18]-0)*(newmax-newmin))/((100-0)+newmin);
        //printf("%d = %f %f %f %f %f %f\n",i,Age[i],Bilir[i],Alk[i],Sgot[i],Albumin[i],Protime[i]);
    }

    for(i=1; i<=2; i++)
    {
        for(j=1; j<=19; j++)
        {
            c[i][j]=rand()%100/99.1938129;
            //printf("c[%d][%d]= %f\n",i,j,c[i][j]);
        }
    }

    jumlah[1]=0;
    jumlah[2]=0;
    jumlah[3]=0;



    loop=10;
    for(iterasi=1; iterasi<=loop; iterasi++)
    {
        jumlah[1]=0;
        jumlah[2]=0;
        jumlah[3]=0;

        for(i=1; i<=3; i++)
        {
            for(j=1; j<=3; j++)
            {
                mean[i][j]=0;
            }
        }


        printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
        printf("\niterasi = %d\n\n",iterasi);
    for(i=1; i<=155; i++)
    {
        for(j=1; j<=2; j++) //CLuster
        {
            jarak[j]=0;
            for(k=1; k<=19; k++) //Penjumlahan jarak
            {
                jarak[j]=jarak[j]+pow(I[i][k]-c[j][k],2);
            }
            jarak[j]=sqrt(jarak[j]);
            //printf("jarak[%d][%d]=%f\n",i,j,jarak[j]);
        }
         for(j=1; j<=2; j++)
            {
                rank[j]=1;
                for(b=1; b<=2; b++)
                    {
                        if(jarak[j]>jarak[b])
                        {
                            rank[j]++;
                        }
                    }
            }
            //printf("Nilai Ujian\t Rangking\n");

        for(j=1; j<=2; j++)
        //printf("%f\t\t %f\n",jarak[j], rank[j]);

        for(j=1; j<=2; j++)
        {
            if(rank[j]==1 && j==1)
            {
                jumlah[j]=jumlah[j]+1;
                ranking[i][j]=j;
            }
            else if(rank[j]==1 && j==2)
            {
                jumlah[j]=jumlah[j]+1;
                ranking[i][j]=j;
            }
            else
            {
                ranking[i][j]=0;
            }
        }

    }

    printf("\n\n");
    for(i=1; i<=2; i++)
    {
        printf("jumlah[%d] = %f\n",i,jumlah[i]);
    }

    for(i=1; i<=155; i++)
    {
        printf("i= %d   ",i);
        for(j=1; j<=2; j++)
        {
            if(ranking[i][j]==1)
            {
                kelastesting[i]=ranking[i][j];
                printf("class[%d] = %f\n",i,kelastesting[i]);
                mean[ranking[i][j]][1]=mean[ranking[i][j]][1]+I[i][1];
                mean[ranking[i][j]][2]=mean[ranking[i][j]][2]+I[i][2];
                mean[ranking[i][j]][3]=mean[ranking[i][j]][3]+I[i][3];
                mean[ranking[i][j]][4]=mean[ranking[i][j]][4]+I[i][4];
                mean[ranking[i][j]][5]=mean[ranking[i][j]][5]+I[i][5];
                mean[ranking[i][j]][6]=mean[ranking[i][j]][6]+I[i][6];
                mean[ranking[i][j]][7]=mean[ranking[i][j]][7]+I[i][7];
                mean[ranking[i][j]][8]=mean[ranking[i][j]][8]+I[i][8];
                mean[ranking[i][j]][9]=mean[ranking[i][j]][9]+I[i][9];
                mean[ranking[i][j]][10]=mean[ranking[i][j]][10]+I[i][10];
                mean[ranking[i][j]][11]=mean[ranking[i][j]][11]+I[i][11];
                mean[ranking[i][j]][12]=mean[ranking[i][j]][12]+I[i][12];
                mean[ranking[i][j]][13]=mean[ranking[i][j]][13]+I[i][13];
                mean[ranking[i][j]][14]=mean[ranking[i][j]][14]+I[i][14];
                mean[ranking[i][j]][15]=mean[ranking[i][j]][15]+I[i][15];
                mean[ranking[i][j]][16]=mean[ranking[i][j]][16]+I[i][16];
                mean[ranking[i][j]][17]=mean[ranking[i][j]][17]+I[i][17];
                mean[ranking[i][j]][18]=mean[ranking[i][j]][18]+I[i][18];
                mean[ranking[i][j]][19]=mean[ranking[i][j]][19]+I[i][19];
            }
            else if(ranking[i][j]==2)
            {
                kelastesting[i]=ranking[i][j];
                printf("class[%d] = %f\n",i,kelastesting[i]);
                mean[ranking[i][j]][1]=mean[ranking[i][j]][1]+I[i][1];
                mean[ranking[i][j]][2]=mean[ranking[i][j]][2]+I[i][2];
                mean[ranking[i][j]][3]=mean[ranking[i][j]][3]+I[i][3];
                mean[ranking[i][j]][4]=mean[ranking[i][j]][4]+I[i][4];
                mean[ranking[i][j]][5]=mean[ranking[i][j]][5]+I[i][5];
                mean[ranking[i][j]][6]=mean[ranking[i][j]][6]+I[i][6];
                mean[ranking[i][j]][7]=mean[ranking[i][j]][7]+I[i][7];
                mean[ranking[i][j]][8]=mean[ranking[i][j]][8]+I[i][8];
                mean[ranking[i][j]][9]=mean[ranking[i][j]][9]+I[i][9];
                mean[ranking[i][j]][10]=mean[ranking[i][j]][10]+I[i][10];
                mean[ranking[i][j]][11]=mean[ranking[i][j]][11]+I[i][11];
                mean[ranking[i][j]][12]=mean[ranking[i][j]][12]+I[i][12];
                mean[ranking[i][j]][13]=mean[ranking[i][j]][13]+I[i][13];
                mean[ranking[i][j]][14]=mean[ranking[i][j]][14]+I[i][14];
                mean[ranking[i][j]][15]=mean[ranking[i][j]][15]+I[i][15];
                mean[ranking[i][j]][16]=mean[ranking[i][j]][16]+I[i][16];
                mean[ranking[i][j]][17]=mean[ranking[i][j]][17]+I[i][17];
                mean[ranking[i][j]][18]=mean[ranking[i][j]][18]+I[i][18];
                mean[ranking[i][j]][19]=mean[ranking[i][j]][19]+I[i][19];
            }
        }
    }

    printf("\n\n");
    for(i=1; i<=2; i++)
    {
        for(j=1; j<=19; j++)
        {
            printf("mean[%d][%d] = %f\n",i,j,mean[i][j]);
        }
    }

    //printf("\n\n");
    for(i=1; i<=2; i++)
    {
        if(i==1)
        {
            for(j=1; j<=19; j++)
            {
                if(mean[i][j]==0||jumlah[i]==0)
                {
                    c[i][j]=0;
                    printf("c[%d][%d] = %f\n",i,j,c[i][j]);
                }
                else if(mean[i][j]!=0||jumlah[i]!=0)
                {
                    c[i][j]=mean[i][j]/jumlah[i];
                    printf("c[%d][%d] = %f\n",i,j,c[i][j]);
                }
            }
        }
        else if(i==2)
        {
            for(j=1; j<=19; j++)
            {
                if(mean[i][j]==0||jumlah[i]==0)
                {
                    c[i][j]=0;
                    printf("c[%d][%d] = %f\n",i,j,c[i][j]);
                }
                else if(mean[i][j]!=0||jumlah[i]!=0)
                {
                    c[i][j]=mean[i][j]/jumlah[i];
                    printf("c[%d][%d] = %f\n",i,j,c[i][j]);
                }
            }
        }
    }
    }

    for(i=1; i<=155; i++)
    {
        if(kelastesting[i]==1)
        {
            kelastesting[i]=0;
            printf("kelastesting[%d] = %f\n",i,kelastesting[i]);
        }
        else if(kelastesting[i]==2)
        {
            kelastesting[i]=1;
            printf("kelastesting[%d] = %f\n",i,kelastesting[i]);
        }
    }

    /*
    //menghitung error keseluruhan
    int error;
    error=0;
    for(i=1; i<=155; i++)
    {
        if(kelas[i]==kelastesting[i])
        {
            error=error+0;
        }
        else if(kelas[i]!=kelastesting[i])
        {
            error=error+1;
        }
    }

    printf("error = %d\n",error);
    float totalerror = error*100/155;
    printf("totalerror = %f\n",totalerror);
    */

    }

