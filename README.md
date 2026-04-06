# 📚 Stack Applications

Bu proje, **Yığın (Stack)** veri yapısının temel çalışma mantığını ve gerçek dünya problemlerindeki uygulamalarını içeren bir laboratuvar çalışmasıdır. Proje, **LIFO (Last-In-First-Out)** prensibinin farklı algoritmalar üzerindeki etkisini göstermektedir.

---

## 📌 Proje Hakkında

Stack (Yığın), eleman ekleme ve çıkarma işlemlerinin sadece listenin üst (top) kısmından yapıldığı doğrusal bir veri yapısıdır. Bu projede, yığının temel operasyonları ve bu yapıyı kullanan popüler algoritmalar uygulanmıştır.

### Desteklenen Temel Özellikler:

* **Temel Operasyonlar:** `push` (ekleme), `pop` (çıkarma), `peek` (en üsttekini görme) ve `isEmpty` kontrolleri.
* **Parantez Dengeleme:** Verilen bir ifadedeki parantezlerin `{()}` doğru açılıp kapandığını kontrol etme.
* **Infix to Postfix:** Matematiksel ifadeleri bilgisayarın daha kolay işleyebileceği Postfix (Reverse Polish Notation) formuna dönüştürme.
* **Postfix Evaluation:** Dönüştürülen matematiksel ifadelerin sonucunu hesaplama.

---

## 🏗 Veri Yapısı Mimarısı

Stack yapısı "Son Giren İlk Çıkar" prensibiyle çalışır:



Her bir işlem `top` adı verilen bir işaretçi üzerinden yürütülür. Eleman eklendikçe yığın yukarı doğru büyür, eleman çekildikçe aşağı doğru iner.

---

## 🚀 Başlangıç

Projeyi yerel bilgisayarınızda çalıştırmak için aşağıdaki adımları izleyebilirsiniz.

### Gereksinimler

* C/C++ Derleyicisi (GCC, Clang veya MSVC)
* Git (Opsiyonel)

### Kurulum ve Çalıştırma

1. **Depoyu Klonlayın:**
```bash
git clone [https://github.com/EKaptanE/Stack_Applications.git](https://github.com/EKaptanE/Stack_Applications.git)
cd Stack_Applications
```
2. **Derleyin:**
```bash
g++ main.cpp -o stack_apps
```
3. **Çalıştırın:**
```bash
./stack_apps
```

## 🛠 Kullanım Örneği (C++)
Aşağıda bir yığının nasıl başlatılacağı ve basit bir parantez kontrolü algoritmasında nasıl kullanılacağı gösterilmiştir:

```cpp
#include <iostream>
#include "Stack.h"

int main() {
    Stack s;
    
    // Basit push/pop işlemleri
    s.push('(');
    s.push('{');
    
    if (s.peek() == '{') {
        std::cout << "Yığının üstündeki eleman: {" << std::endl;
    }
    
    s.pop(); // '{' çıkarıldı
    
    return 0;
}
```

---

**Geliştirici:** [EKaptanE](https://www.google.com/search?q=https://github.com/EKaptanE)

---
