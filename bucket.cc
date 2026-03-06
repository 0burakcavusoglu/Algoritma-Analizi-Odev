#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>

using namespace std;

// --- SIRALAMA ALGORİTMALARI ---

// Brute Force: Bubble Sort [cite: 21]
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
        }
    }
}

// Atanmış: Bucket Sort [cite: 6, 14, 15]
void bucketSort(vector<int>& arr) {
    int n = arr.size();
    if (n <= 0) return;
    vector<int> buckets[10]; // 1-1000 arası için 10 kova [cite: 8]
    for (int i = 0; i < n; i++) {
        int idx = (arr[i] - 1) / 100;
        if (idx > 9) idx = 9;
        buckets[idx].push_back(arr[i]);
    }
    int index = 0;
    for (int i = 0; i < 10; i++) {
        bubbleSort(buckets[i]); // Her kovayı kendi içinde sırala
        for (int x : buckets[i]) arr[index++] = x;
    }
}

// --- ARAMA ALGORİTMALARI ---

// Brute Force: Linear Search [cite: 21, 23]
int linearSearch(string text, string pattern) {
    int count = 0, n = text.length(), m = pattern.length();
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) if (text[i + j] != pattern[j]) break;
        if (j == m) count++;
    }
    return count;
}

// Atanmış: Rabin-Karp [cite: 6, 14, 23]
int rabinKarp(string text, string pattern) {
    int n = text.length(), m = pattern.length(), count = 0;
    int h = 1, p = 0, t = 0, d = 256, q = 101;
    for (int i = 0; i < m - 1; i++) h = (h * d) % q;
    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }
    for (int i = 0; i <= n - m; i++) {
        if (p == t) {
            int j;
            for (j = 0; j < m; j++) if (text[i + j] != pattern[j]) break;
            if (j == m) count++;
        }
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0) t += q;
        }
    }
    return count;
}

int main() {
    // 1. .csv Verisini Oku [cite: 22, 29]
    vector<int> numbers;
    ifstream csvFile("veriler.csv");
    int val;
    while (csvFile >> val) numbers.push_back(val);
    csvFile.close();

    // 2. Metni Oku [cite: 13, 23]
    ifstream txtFile("alice_in_wonderland.txt");
    string content((istreambuf_iterator<char>(txtFile)), istreambuf_iterator<char>());
    txtFile.close();

    // --- SIRALAMA TESTİ ---
    vector<int> numbersCopy = numbers;
    auto s1 = chrono::high_resolution_clock::now();
    bucketSort(numbers);
    auto e1 = chrono::high_resolution_clock::now();
    cout << "Bucket Sort Suresi: " << chrono::duration<double>(e1 - s1).count() << "s\n";

    auto s2 = chrono::high_resolution_clock::now();
    bubbleSort(numbersCopy);
    auto e2 = chrono::high_resolution_clock::now();
    cout << "Bubble Sort (Brute Force) Suresi: " << chrono::duration<double>(e2 - s2).count() << "s\n";

    // --- ARAMA TESTİ ---
    string words[] = {"Alice", "Rabbit", "Wonderland"}; // Programın vereceği örnek kelimeler [cite: 9, 23]
    for (string w : words) {
        auto s3 = chrono::high_resolution_clock::now();
        int c1 = rabinKarp(content, w);
        auto e3 = chrono::high_resolution_clock::now();
        cout << w << " kelimesi Rabin-Karp ile " << c1 << " kez bulundu. Sure: " << chrono::duration<double>(e3 - s3).count() << "s\n";
    }

    return 0;
}