package com.pertemuan_2;

public class Receptionist extends Karyawan {
  Receptionist() {
    gaji += 1000000;
    setBonus(300000);
  }

  void naikGaji() {
    gaji += 1000000; // 1jt
  }
}
