#include <stdio.h>
#include <locale.h>

#define MAX_KATILIMCI_SAYISI 3

// Art�rma i�lemi i�in kullan�lan teklif yap�s�
typedef struct 
{
    int teklifveren_no;  // Teklifi yapan kat�l�mc�n�n numaras�
    double teklif;       // Yap�lan teklif miktar�
} Teklif;

// Art�rma i�lemi yap�s�n� tan�mlayan yap�
typedef struct
{
    int katilimci_sayisi;     // Art�rmaya kat�lan toplam kat�l�mc� say�s�
    Teklif teklifler[MAX_KATILIMCI_SAYISI]; // Teklifleri i�eren dizi
    
} Artirma;

// Teklif sonu�lar�n� temsil eden yap�
typedef struct 
{
    int bid;               // Kazanan�n numaras�
    int teklifveren_no;    // Kazanan teklifi yapan kat�l�mc�n�n numaras�
    double teklif;         // Kazanan teklif miktar�
} Bid;

// Kazanan kat�l�mc�n�n d���ndaki kat�l�mc�lara �deme yap�lmas�n� hesaplayan fonksiyon
double odemeyi_hesapla(Artirma a, int kazanan_no) 
{
    double odeme = 0.0;
    
    int i;
    for (i = 0; i < a.katilimci_sayisi; i++)
	 {
        if (i != kazanan_no) 
		{
            odeme += a.teklifler[i].teklif;
        }
    }
    return odeme;
}

// En y�ksek teklifi ve kazanan� bulan fonksiyon
double en_yuksek_teklifi_bul(Artirma a, int *kazanan_no) 
{
    double en_yuksek_teklif = -1.0;
    *kazanan_no = -1;
    
    int i;
    for (i = 0; i < a.katilimci_sayisi; i++)
	 {
        if (a.teklifler[i].teklif > en_yuksek_teklif)
		 {
            en_yuksek_teklif = a.teklifler[i].teklif;
            *kazanan_no = i;
        }
    }

    return en_yuksek_teklif;
}

int main() {
	
	setlocale(LC_ALL, "Turkish");
	
    // �rnek kullan�m
    Artirma artirma;
    artirma.katilimci_sayisi = 3; // �rnek bir de�er
    artirma.teklifler[0].teklifveren_no = 1;
    artirma.teklifler[0].teklif = 90.0;
    artirma.teklifler[1].teklifveren_no = 2;
    artirma.teklifler[1].teklif = 200.0;
    artirma.teklifler[2].teklifveren_no = 3;
    artirma.teklifler[2].teklif = 300.0;

    int kazanan_no;
    double en_yuksek_teklif = en_yuksek_teklifi_bul(artirma, &kazanan_no);

    if (en_yuksek_teklif != -1.0) 
	{
        printf("En y�ksek teklif: %lf\n", en_yuksek_teklif);
        printf("Kazanan no: %d\n", kazanan_no + 1);

        double odeme = odemeyi_hesapla(artirma, kazanan_no);
        printf("�deme: %lf\n", odeme);
    } 
	else
	{
        printf("Hi� teklif yok.\n");
    }

    return 0;
}

