package com.pertemuan_2;

class Manager extends Karyawan {
  Manager() {
    gaji += 2000000;
    setBonus(500000);
  }

  void naikGaji() {
    gaji += 3000000; // 3jt
  }
}
