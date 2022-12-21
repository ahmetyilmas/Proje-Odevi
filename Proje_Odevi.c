#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*
Bu fonksiyon ilk parametrede girilen degiskenin, ikinci girilen parametreye gore basamagini hesaplar.
Birler basamagini bulmak icin ikinci parametreye 1, Onlar basamagi icin 10, Yuzler basamagi icin 100 vs. yaziniz.
*/

int basamak_bul(int sayi,int istenen_basamak)
{
    int basamak;
    
    basamak = sayi%(istenen_basamak * 10) / istenen_basamak;

    return basamak;
}

void main()
{
    printf("\n\nBilgisayar sizden sectiginiz zorluga gore sayi tahmin etmenizi isteyecektir ve tahmininizi\nkendi sayisinin basamaklariyla karsilastiracaktir.");
    printf("\n\nTahmininiz dogruluguna gore girdiginiz sayinin altinda 0, 1 ve 2 rakamlarini goreceksiniz.");
    printf("\n\nEger girdiginiz sayinin altinda 0 rakami varsa bilgisayarin sayisinda o rakam bulunmuyor demektir.");   
    printf("\nEger girdiginiz sayinin altinda 1 rakami varsa bilgisayarin sayisinda o rakam vardir ve basamagi dogrudur.");
    printf("\nEger girdiginiz sayinin altinda 2 rakami varsa bilgisayarin sayisinda o rakam vardir fakat basamagi dogru degildir.");

    
    int sayilar[5];
    FILE *fp;

    srand(time(NULL));
    int rastgele_sayi = rand()%5;

    fp = fopen("kolay_sayilar.txt","r");
    
    for (int i = 0; i < 5; i++)
    {
        fread(&sayilar[i],sizeof(int),1,fp);
    }

    int kolay_sayi = sayilar[rastgele_sayi];
    fclose(fp);
    
    int kolay_sayi_birler,kolay_sayi_onlar,kolay_sayi_yuzler;

    kolay_sayi_birler = basamak_bul(kolay_sayi,1);
    kolay_sayi_onlar = basamak_bul(kolay_sayi,10);
    kolay_sayi_yuzler = basamak_bul(kolay_sayi,100);
    
    fp = fopen("orta_sayilar.txt","r");
    
    for (int i = 0; i < 5; i++)
    {
        fread(&sayilar[i],sizeof(int),1,fp);
    }
    
    int orta_sayi = sayilar[rastgele_sayi];
    fclose(fp);
    
    int orta_sayi_birler,orta_sayi_onlar,orta_sayi_yuzler,orta_sayi_binler;
    
    orta_sayi_birler = basamak_bul(orta_sayi,1);
    orta_sayi_onlar = basamak_bul(orta_sayi,10);
    orta_sayi_yuzler = basamak_bul(orta_sayi,100);
    orta_sayi_binler = basamak_bul(orta_sayi,1000);

    fp = fopen("zor_sayilar.txt","r");
    
    for (int i = 0; i < 5; i++)
    {
        fread(&sayilar[i],sizeof(int),1,fp);
    }

    int zor_sayi = sayilar[rastgele_sayi];
    fclose(fp);

    int zor_sayi_birler,zor_sayi_onlar,zor_sayi_yuzler,zor_sayi_binler,zor_sayi_onbinler;

    zor_sayi_birler = basamak_bul(zor_sayi,1);
    zor_sayi_onlar = basamak_bul(zor_sayi,10);
    zor_sayi_yuzler = basamak_bul(zor_sayi,100);
    zor_sayi_binler = basamak_bul(zor_sayi,1000);
    zor_sayi_onbinler = basamak_bul(zor_sayi,10000);

    char cikis = 1;
    while (cikis == 1)
    {
        char zorluk_secimi;
        printf("\n\n****Zorluk Seciniz****");
        printf("\nK-Kolay\nO-Orta\nZ-Zor\nX-Programdan cikis\n");
        zorluk_secimi = getchar();
        switch (zorluk_secimi)
        {
        case 'X':
        case 'x':
            cikis--;
            break;
        case 'K':
        case 'k':
            printf("\nBilgisayarin sayisi uc basamaklidir");
            for (int k = 6; k >= 0; k--)
            {
                int tahmin,tahmin_birler,tahmin_onlar,tahmin_yuzler;
                
                if (k == 0)
                {
                    printf("\nTahmin hakkiniz kalmadi.");
                    printf("\nYeniden oynamak istiyorsaniz Enter, Oyundan cikmak icin 'X' basiniz.\n");
                    if (getchar() == 'X' | getchar() == 'x')
                    {
                        cikis--;
                        break;
                    }
                    else
                    {    
                        break;
                    }
                }
                
                printf("\nTahmin Hakkiniz:%d",k);
                printf("\nTahmininiz:\n");
                scanf("%d",&tahmin);
                tahmin_birler = basamak_bul(tahmin,1);
                tahmin_onlar = basamak_bul(tahmin,10);
                tahmin_yuzler = basamak_bul(tahmin,100);


                if (tahmin == kolay_sayi)
                {
                    printf("\nTebrikler tahmininiz dogru!");
                    printf("\nYeniden oynamak istiyorsaniz Enter, oyundan cikmak istiyorsaniz 'X' basiniz\n");
                    if (getchar()  == 'X' | getchar() == 'x')
                    {
                        cikis--;
                        break;
                    }
                    else
                    {
                        break;
                    }
                }
                
                // Asagida yuzler basamaginin kontrolunun yapildigi kisim bulunmakta.

                if (tahmin_yuzler == kolay_sayi_yuzler)             
                {
                    printf("1");
                }
                else if (tahmin_yuzler == kolay_sayi_onlar)
                {
                    printf("2");
                }
                else if (tahmin_yuzler == kolay_sayi_birler)
                {
                    printf("2");
                }
                else
                {
                    printf("0");
                }
                
                // Asagida onlar basamaginin kontrolunun yapildigi kisim bulunmakta.

                if (tahmin_onlar == kolay_sayi_yuzler)              
                {
                    printf("2");
                }
                else if (tahmin_onlar == kolay_sayi_onlar)
                {
                    printf("1");
                }
                else if (tahmin_onlar == kolay_sayi_birler)
                {
                    printf("2");
                }
                else
                {
                    printf("0");
                }
                
                //  Asagida birler basamaginin kontrolunun yapildigi kisim bulunmakta

                if ((tahmin_birler == kolay_sayi_yuzler))           
                {
                    printf("2");
                }
                else if (tahmin_birler == kolay_sayi_onlar)
                {
                    printf("2");
                }
                else if (tahmin_birler == kolay_sayi_birler)
                {
                    printf("1");
                }
                else
                {
                    printf("0");
                }
                
            }
            break;
        case 'O':
        case 'o':
            printf("\nBilgisayarin sayisi dort basamaklidir.");
            for (int o = 5; o >= 0; o--)
            {
                int tahmin,tahmin_birler,tahmin_onlar,tahmin_yuzler,tahmin_binler;

                if (o == 0)
                {
                    printf("\nTahmin hakkiniz kalmadi.");
                    printf("\nYeniden oynamak istiyorsaniz Enter, Oyundan cikmak icin 'X' basiniz.\n");
                    if (getchar() == 'X' | getchar() == 'x')
                    {
                        cikis--;
                        break;
                    }
                    else
                    {    
                        break;
                    }
                }

                printf("\nTahmin hakkiniz:%d",o);
                printf("\nTahmininiz:\n");
                scanf("%d",&tahmin);
                tahmin_birler = basamak_bul(tahmin,1);
                tahmin_onlar = basamak_bul(tahmin,10);
                tahmin_yuzler = basamak_bul(tahmin,100);
                tahmin_binler = basamak_bul(tahmin,1000);
                
                if (tahmin == orta_sayi)
                {
                    printf("\nTebrikler tahmininiz dogru!");
                    printf("\nYeniden oynamak istiyorsaniz Enter, oyundan cikmak istiyorsaniz 'X' basiniz\n");
                    if (getchar()  == 'X' | getchar() == 'x')
                    {
                        cikis--;
                        break;
                    }
                    else
                    {
                        break;
                    }
                }
                
                //  Binler basamaginin kontrol edildigi kisim
                if (tahmin_binler == orta_sayi_binler)
                {
                    printf("1");
                }
                else if (tahmin_binler == orta_sayi_yuzler)
                {
                    printf("2");
                }
                else if (tahmin_binler == orta_sayi_onlar)
                {
                    printf("2");
                }
                else if (tahmin_binler == orta_sayi_birler)
                {
                    printf("2");
                }
                else
                {
                    printf("0");
                }
                
                //  Yuzler basamaginin kontrol edildigi kisim
                if (tahmin_yuzler == orta_sayi_binler)
                {
                    printf("2");
                }
                else if (tahmin_yuzler == orta_sayi_yuzler)
                {
                    printf("1");
                }
                else if (tahmin_yuzler == orta_sayi_onlar)
                {
                    printf("2");
                }
                else if (tahmin_yuzler == orta_sayi_birler)
                {
                    printf("2");
                }
                else
                {
                    printf("0");
                }
                
                // Onlar basamaginin kontrol edildigi kisim
                if (tahmin_onlar == orta_sayi_binler)
                {
                    printf("2");
                }
                else if (tahmin_onlar == orta_sayi_yuzler)
                {
                    printf("2");
                }
                else if (tahmin_onlar == orta_sayi_onlar)
                {
                    printf("1");
                }
                else if (tahmin_onlar == orta_sayi_birler)
                {
                    printf("2");
                }
                else
                {
                    printf("0");
                }

                //  Birler basamaginin kontrol edildigi kisim
                if (tahmin_birler == orta_sayi_binler)
                {
                    printf("2");
                }
                else if (tahmin_birler == orta_sayi_yuzler)
                {
                    printf("2");
                }
                else if (tahmin_birler == orta_sayi_onlar)
                {
                    printf("2");
                }
                else if (tahmin_birler == orta_sayi_birler)
                {
                    printf("1");
                }
                else
                {
                    printf("0");
                }
            }
            break;
        case 'Z':
        case 'z':
            printf("\nBilgisayarin sayisi bes basamaklidir.");
            for (int z = 5; z >= 0; z--)
            {
                int tahmin,tahmin_birler,tahmin_onlar,tahmin_yuzler,tahmin_binler,tahmin_onbinler;
                if (z== 0)
                {
                    printf("\nTahmin hakkiniz kalmadi.");
                    printf("\nYeniden oynamak istiyorsaniz Enter, Oyundan cikmak icin 'X' basiniz.\n");
                    if (getchar() == 'X' | getchar() == 'x')
                    {
                        cikis--;
                        break;
                    }
                    else
                    {    
                        break;
                    }
                }
                printf("\nTahmin hakkiniz:%d",z);
                printf("\nTahmininiz:\n");
                scanf("%d",&tahmin);
                tahmin_birler = basamak_bul(tahmin,1);
                tahmin_onlar = basamak_bul(tahmin,10);
                tahmin_yuzler = basamak_bul(tahmin,100);
                tahmin_binler = basamak_bul(tahmin,1000);
                tahmin_binler = basamak_bul(tahmin,10000);
                
                if (tahmin == zor_sayi)
                {
                    printf("\nTebrikler tahmininiz dogru!");
                    printf("\nYeniden oynamak istiyorsaniz Enter, oyundan cikmak istiyorsaniz 'X' basiniz\n");
                    if (getchar()  == 'X' | getchar() == 'x')
                    {
                        cikis--;
                        break;
                    }
                    else
                    {
                        break;
                    }
                }

                //  Onbinler basamaginin kontrol edildigi kisim
                if (tahmin_onbinler == zor_sayi_onbinler)
                {
                    printf("1");
                }
                else if (tahmin_onbinler == zor_sayi_binler)
                {
                    printf("2");
                }
                else if (tahmin_onbinler == zor_sayi_yuzler)
                {
                    printf("2");
                }
                else if (tahmin_onbinler == zor_sayi_onlar)
                {
                    printf("2");
                }
                else if (tahmin_onbinler == zor_sayi_birler)
                {
                    printf("2");
                }
                else
                {
                    printf("0");
                }
                
                //  Binler basamaginin kontrol edildigi kisim
                if (tahmin_binler == zor_sayi_onbinler)
                {
                    printf("2");
                }
                else if (tahmin_binler == zor_sayi_binler)
                {
                    printf("1");
                }
                else if (tahmin_binler == zor_sayi_yuzler)
                {
                    printf("2");
                }
                else if (tahmin_binler == zor_sayi_onlar)
                {
                    printf("2");
                }
                else if (tahmin_binler == zor_sayi_birler)
                {
                    printf("2");
                }
                else
                {
                    printf("0");
                }
                
                //  Yuzler basamaginin kontrol edildigi kisim
                if (tahmin_yuzler == zor_sayi_onbinler)
                {
                    printf("2");
                }
                else if (tahmin_yuzler == zor_sayi_binler)
                {
                    printf("2");
                }
                else if (tahmin_yuzler == zor_sayi_yuzler)
                {
                    printf("1");
                }
                else if (tahmin_yuzler == zor_sayi_onlar)
                {
                    printf("2");
                }
                else if (tahmin_yuzler == zor_sayi_birler)
                {
                    printf("2");
                }
                else
                {
                    printf("0");
                }

                //  Onlar basamaginin kontrol edildigi kisim
                if (tahmin_onlar == zor_sayi_onbinler)
                {
                    printf("2");
                }
                else if (tahmin_onlar == zor_sayi_binler)
                {
                    printf("2");
                }
                else if (tahmin_onlar == zor_sayi_yuzler)
                {
                    printf("2");
                }
                else if (tahmin_onlar == zor_sayi_onlar)
                {
                    printf("1");
                }
                else if (tahmin_onlar == zor_sayi_birler)
                {
                    printf("2");
                }
                else
                {
                    printf("0");
                }

                //  Birler basamaginin kontrol edildigi kisim
                if (tahmin_birler == zor_sayi_onbinler)
                {
                    printf("2");
                }
                else if (tahmin_birler == zor_sayi_binler)
                {
                    printf("2");
                }
                else if (tahmin_birler == zor_sayi_yuzler)
                {
                    printf("2");
                }
                else if (tahmin_birler == zor_sayi_onlar)
                {
                    printf("2");
                }
                else if (tahmin_birler == zor_sayi_birler)
                {
                    printf("1");
                }
                else
                {
                    printf("0");
                }
            }
            break;
        default:
            printf("\nLutfen belirtilen harflerden birisini giriniz.\n");
            zorluk_secimi = getchar();
            
            break;
        }
    }
    
}