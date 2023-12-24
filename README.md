# Acik-Arttirma

Struct (Yapı)
C programlamada struct kullanılarak yeni veri türleri tanımlanabilir. Bir struct içinde, farklı veri tiplerine sahip birden çok değişkeni bir araya getirebilirsiniz. Örneğin, aşağıda bir Teklif yapısı tanımlanmıştır:

![1](https://github.com/ecemreer/Acik-Arttirma/assets/153460547/a3c5f18f-e9d0-444a-b431-ad51399844c8)

Bu yapı, teklifveren_no ve teklif adlı iki değişkeni içerir ve bu değişkenler Teklif adlı bir veri tipini temsil eder.

Typedef
typedef anahtar kelimesi, mevcut bir veri tipine alternatif bir isim atamak için kullanılır. Yukarıdaki örnekte, struct Teklif için kısa bir isim olan Teklif kullanılarak daha okunabilir bir kod elde edilmiştir.!
![2](https://github.com/ecemreer/Acik-Arttirma/assets/153460547/1434bd9b-1279-4040-9a85-bded9ec78966)

İşaretçiler
Bu bölümde, C programlamadaki işaretçi kavramı açıklanacaktır. İşaretçiler, bellek adreslerini tutan değişkenlerdir ve program içinde doğrudan belleğe erişim sağlarlar.

İşaretçi Kavramı
İşaretçiler, bellek adresini tutan değişkenlerdir. Bir değişkenin bellek adresini içeren işaretçiler, o değişkenin değerine doğrudan erişim sağlarlar.

Örneğin:
![3](https://github.com/ecemreer/Acik-Arttirma/assets/153460547/b204366f-f721-42da-ba45-04f23e31f245)
Burada, isaretcisayi değişkeni, sayi değişkeninin bellek adresini tutar. Bu işaretçi aracılığıyla, sayi değişkeninin değerine erişilebilir.

Açık Artırma ve Oyun Teorisi İlişkisi
Açık artırma, bir mal veya hizmetin alıcıya en yüksek fiyatı teklif eden kişiye satıldığı bir satış yöntemidir. Oyun teorisi, karar verme stratejilerini inceleyen bir matematik dalıdır ve açık artırmalar gibi rekabetçi durumları modellemek için kullanılabilir.

Açık artırmalarda, katılımcılar kendi çıkarları doğrultusunda stratejiler belirlerler. Oyun teorisi, katılımcıların birbirlerini nasıl etkilediğini ve optimal stratejilerin neler olduğunu analiz eder. Örneğin, bir katılımcının teklif stratejisi diğerlerini nasıl etkiler ve en iyi sonucu elde etmek için en uygun teklifi nasıl yapar, gibi sorular oyun teorisi tarafından incelenir.

Bu iki konsept arasındaki ilişki, katılımcıların kendi çıkarları doğrultusunda en uygun stratejiyi belirlemeye çalıştığı rekabetçi bir ortamı modellemek için kullanılabilir. Oyun teorisi, açık artırmalarda stratejik davranışları anlamak ve analiz etmek için güçlü bir araç olabilir.

Kodlar:
```c
#include <stdio.h>
#include <locale.h>

#define MAX_KATILIMCI_SAYISI 3

// Artırma işlemi için kullanılan teklif yapısı
typedef struct 
{
    int teklifveren_no;  // Teklifi yapan katılımcının numarası
    double teklif;       // Yapılan teklif miktarı
} Teklif;

// Artırma işlemi yapısını tanımlayan yapı
typedef struct
{
    int katilimci_sayisi;     // Artırmaya katılan toplam katılımcı sayısı
    Teklif teklifler[MAX_KATILIMCI_SAYISI]; // Teklifleri içeren dizi
    
} Artirma;

// Teklif sonuçlarını temsil eden yapı
typedef struct 
{
    int bid;               // Kazananın numarası
    int teklifveren_no;    // Kazanan teklifi yapan katılımcının numarası
    double teklif;         // Kazanan teklif miktarı
} Bid;

// Kazanan katılımcının dışındaki katılımcılara ödeme yapılmasını hesaplayan fonksiyon
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

// En yüksek teklifi ve kazananı bulan fonksiyon
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
	
    // Örnek kullanım
    Artirma artirma;
    artirma.katilimci_sayisi = 3; // Örnek bir değer
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







