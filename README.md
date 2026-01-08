# 🌌 Güneş Sistemi Fizik Laboratuvarı (Solar System Physics Lab)

> **Ders:** Algoritmalar ve Programlama  
> **Dönem:** 2025-2026 Güz  
> **Kurum:** Bursa Teknik Üniversitesi

Bu proje, C programlama dili kullanılarak geliştirilen, işaretçi (pointer) aritmetiği temelli bir konsol simülasyonudur. Uygulama, kullanıcının girdiği verileri Güneş Sistemi'ndeki 8 farklı gezegenin çekim ivmesine göre işleyerek karşılaştırmalı fiziksel sonuçlar üretir.

---

## 👤 Geliştirici Kimliği

| Alan | Bilgi |
| :--- | :--- |
| **Öğrenci** | Deniz BAŞAT |
| **Şube** | 1 |
| **Öğrenci No** | 24360859921 |
| **Bölüm** | Bilgisayar Mühendisliği |

---

## 📂 Proje Mimarisi

Kaynak kodları modüler bir yapıda düzenlenmiştir. Derleme işlemi `main.c` üzerinden yapılırken, konfigürasyon ve mantıksal işlemler `src` klasöründen çağrılır.

```text
.
├── src/
│   ├── config.h       # Gezegen sabitleri (g) ve isim dizileri
│   └── utils.h        # Fizik formülleri ve hesaplama motoru
├── main.c             # Program giriş noktası ve menü döngüsü
├── Rapor.pdf          # Proje teknik raporu
└── README.md          # Proje dokümantasyonu

```

---

## 🛠️ Teknik Yetkinlikler

Bu proje, standart C standartlarına uygun olarak ve aşağıdaki teknik gereksinimler gözetilerek kodlanmıştır:

* **Pointer Tabanlı Bellek Erişimi:** Diziler üzerinde `[]` indeksleme operatörü kesinlikle kullanılmamıştır. Tüm veri okuma işlemleri `*(ptr + i)` şeklinde **pointer aritmetiği** ile gerçekleştirilmiştir.
* **Input Sanitization (Girdi Temizleme):** Kullanıcıdan alınan kütle, zaman gibi skaler büyüklüklerin negatif girilmesi durumunda, `if-else` yerine **Ternary Operator** (`x < 0 ? -x : x`) kullanılarak mutlak değer dönüşümü sağlanır.
* **Header-Only Modülerlik:** Fonksiyon prototipleri ve tanımlamaları, ana kodun okunabilirliğini artırmak amacıyla başlık dosyalarına (`.h`) ayrılmıştır.

---

## 🔬 Simülasyon İçeriği

Program, kullanıcı "Bilim İnsanı" ismini girdikten sonra aşağıdaki 9 farklı deneyi tüm gezegenler için simüle eder:

| No | Deney Adı | Formül | Açıklama |
| --- | --- | --- | --- |
| **1** | Serbest Düşme |  | Zamana bağlı düşüş mesafesi hesaplanır. |
| **2** | Yukarı Atış |  | İlk hız ile çıkılabilecek max yükseklik. |
| **3** | Ağırlık |  | Kütlenin gezegenlerdeki ağırlık karşılığı. |
| **4** | Potansiyel Enerji |  | Konumdan kaynaklı enerji hesabı. |
| **5** | Hidrostatik Basınç |  | Sıvı basıncının derinliğe göre değişimi. |
| **6** | Arşimet Prensibi |  | Sıvı içindeki cisme etkiyen kaldırma kuvveti. |
| **7** | Basit Sarkaç |  | Salınım periyodu hesabı. |
| **8** | İp Gerilmesi |  | Statik sistemde ipteki gerilim. |
| **9** | Asansör Deneyi |  | İvmeli sistemlerde hissedilen ağırlık. |

---

## 🚀 Derleme ve Çalıştırma (Build & Run)

Projeyi yerel ortamınızda çalıştırmak için GCC derleyicisine ihtiyacınız vardır.

**1. Projeyi Klonlayın:**

```bash
git clone https://github.com/Heysh1n/24360859921_DenizBASAT_AVP_Proje.git

```

**2. Derleme (Compile):**
Matematik kütüphanesini dahil etmek için `-lm` bayrağını unutmayınız.

```bash
gcc main.c -o dist/main -lm

```

**3. Çalıştırma:**

```bash
./dist/main.exe

```

---

## ⚠️ Lisans ve Uyarılar

* Bu proje **Bursa Teknik Üniversitesi** akademik dürüstlük ilkelerine uygun olarak bireysel hazırlanmıştır.
* Kodların izinsiz kopyalanması veya başka projelerde aynen kullanılması yasaktır.

