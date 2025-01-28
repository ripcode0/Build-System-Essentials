# VSCode ile LLVM Clang Kullanımı için Gereksinimler

<img src="image/llvm.png" alt="LLVM Clang" width="200">

### VSCode ile LLVM Kurulum Adımları
---
1. **LLVM İndir**
   - [Resmi LLVM Sürümleri Sayfası](https://releases.llvm.org/) adresini ziyaret edin.
   - LLVM'nin en son sürümünü seçin.
   - Yükleyiciyi indirin (örneğin, `LLVM-XX.X.X-win64.exe`).
   - Yükleyiciyi çalıştırın ve kurulum sırasında şunlara dikkat edin:
     - LLVM'yi mevcut kullanıcı veya tüm kullanıcılar için sistem yoluna ekleme seçeneğini seçin.
     - Varsayılan kurulum yolunu kullanın: `C:\Program Files\LLVM\`.
---
2. **Kurulumu Doğrula**
   - Komut İstemi'ni (`cmd`) açın.
   - `clang++` erişilebilirliğini kontrol etmek için aşağıdaki komutu çalıştırın:
     ```bash
     clang++ --version
     ```
   - Eğer sürüm bilgisi görüntüleniyorsa kurulum başarılıdır.
---
3. **CMake Tools ile VSCode Ayarla (İsteğe Bağlı)**
   - [VSCode Marketplace](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools)'ten CMake Tools eklentisini yükleyin.
   - Komut paletini `Ctrl + Shift + P` ile açın.
   - **CMake: Select a Kit** seçeneğini seçin.
   - Eğer `LLVM-Clang` kit listesinde görünüyorsa, ayarlar tamamlanmıştır.
---
4. **Ninja Build Sistemi Desteği için Ninja Kur (İsteğe Bağlı)**
   - [Ninja Releases](https://github.com/ninja-build/ninja/releases) sayfasından en son Ninja sürümünü indirin.
   - `ninja.exe` dosyasını çıkarın ve `C:\Program Files\LLVM\bin` dizinine yerleştirin.
