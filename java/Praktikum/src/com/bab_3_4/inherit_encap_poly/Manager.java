package com.bab_3_4.inherit_encap_poly;

class Manager extends Karyawan {
  Manager() {
    gaji += 2000000;
    setBonus(500000);
  }

  void naikGaji() {
    gaji += 3000000; // 3jt
  }
}
