# Algoritma Analizi ve Tasarımı Ödevi

[cite_start]Bu proje, bir sıralama ve bir arama algoritmasının hem teorik hem de deneysel olarak analiz edilmesini amaçlamaktadır[cite: 3]. [cite_start]Proje kapsamında **Bucket Sort** ve **Rabin-Karp** algoritmaları, **Brute Force** yöntemleriyle performans açısından karşılaştırılmıştır[cite: 21, 24].

# Proje İçeriği
* **Atanmış Sıralama Algoritması:** Bucket Sort [cite: 6]
* **Atanmış Arama Algoritması:** Rabin-Karp Algorithm [cite: 6]
* **Deneysel Veri:** Öğrenci numarasına özel üretilmiş 1000 sayılık `.csv` dosyası[cite: 7, 8].
* **Arama Metni:** *Alice's Adventures in Wonderland* (`alice_in_wonderland.txt`)[cite: 13].

---

# Kullanılan Algoritmalar ve Analiz

### 1. Bucket Sort (Kova Sıralaması)
[cite_start]Verileri belirli aralıklara (kovalara) dağıtarak her kovayı kendi içinde sıralayan ve ardından birleştiren bir algoritmadır[cite: 15].
* [cite_start]**Karmaşıklık:** Ortalama $O(n+k)$ sürede çalışır[cite: 15].
* [cite_start]**Brute Force Karşılaştırması:** $O(n^2)$ karmaşıklığa sahip olan **Bubble Sort** gibi bir brute force yöntemiyle kıyaslanmıştır[cite: 21].



#2. Rabin-Karp Algoritması
Hashing (karma) yöntemini kullanarak metin içerisinde desen arayan bir algoritmadır[cite: 15].
***Karmaşıklık:** Ortalama durumda $O(n+m)$ performans sağlar[cite: 15].
* ]**Brute Force Karşılaştırması:** Metni karakter karakter kontrol eden **Linear Search** ile kıyaslanmıştır[cite: 21, 23].



---

# Deneysel Sonuçlar
Algoritmalar C++ dilinde sıfırdan kodlanmış ve çalışma süreleri saniye cinsinden ölçülmüştür[cite: 18, 22].

| Algoritma | Tip | Zaman (Saniye) |
| :--- | :--- | :--- |
| **Bucket Sort** | Atanmış | 0.002s |
| **Bubble Sort** | Brute Force | 0.045s |
| **Rabin-Karp** | Atanmış | 0.015s |
| **Linear Search** | Brute Force | 0.080s |

> **Not:** Yukarıdaki süreler örnek değerlerdir. [cite_start]Kendi bilgisayarınızdaki sonuçlarla güncelleyiniz[cite: 24].

---

# Sunum ve Teslimat
Ödev kapsamında hazırlanan 10-20 dakikalık sunum videosunda şunlar yer almaktadır[cite: 25]:
* Algoritmaların teorik çalışma mantığı ve Big-O analizleri[cite: 26].
* Kodun kritik kısımlarının açıklaması[cite: 26].
* Deneysel performans sonuçlarının ve Brute Force farklarının yorumlanması[cite: 27].

---

#Kurulum ve Çalıştırma
1. C++ dosyalarını Visual Studio ortamında açın[cite: 10].
2. `veriler.csv` ve `alice_in_wonderland.txt` dosyalarının ana dizinde olduğundan emin olun[cite: 11, 29].
3. Projeyi derleyip çalıştırarak konsol ekranındaki zaman analizlerini inceleyin.

**Hazırlayan:** Burak Çavuşoğlu  
**Üniversite:** Kırklareli Üniversitesi - Yazılım Mühendisliği

---
