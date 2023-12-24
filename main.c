#include <stdio.h>
#include <locale.h>

#define MAX_KATILIMCI_SAYISI 3

// Artýrma iþlemi için kullanýlan teklif yapýsý
typedef struct 
{
    int teklifveren_no;  // Teklifi yapan katýlýmcýnýn numarasý
    double teklif;       // Yapýlan teklif miktarý
} Teklif;

// Artýrma iþlemi yapýsýný tanýmlayan yapý
typedef struct
{
    int katilimci_sayisi;     // Artýrmaya katýlan toplam katýlýmcý sayýsý
    Teklif teklifler[MAX_KATILIMCI_SAYISI]; // Teklifleri içeren dizi
    
} Artirma;

// Teklif sonuçlarýný temsil eden yapý
typedef struct 
{
    int bid;               // Kazananýn numarasý
    int teklifveren_no;    // Kazanan teklifi yapan katýlýmcýnýn numarasý
    double teklif;         // Kazanan teklif miktarý
} Bid;

// Kazanan katýlýmcýnýn dýþýndaki katýlýmcýlara ödeme yapýlmasýný hesaplayan fonksiyon
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

// En yüksek teklifi ve kazananý bulan fonksiyon
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
	
    // Örnek kullaným
    Artirma artirma;
    artirma.katilimci_sayisi = 3; // Örnek bir deðer
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
        printf("En yüksek teklif: %lf\n", en_yuksek_teklif);
        printf("Kazanan no: %d\n", kazanan_no + 1);

        double odeme = odemeyi_hesapla(artirma, kazanan_no);
        printf("Ödeme: %lf\n", odeme);
    } 
	else
	{
        printf("Hiç teklif yok.\n");
    }

    return 0;
}

