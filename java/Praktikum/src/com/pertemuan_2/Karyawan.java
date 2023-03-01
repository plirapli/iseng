package com.pertemuan_2;

public class Karyawan {
  double gaji;
  private double bonus;

  Karyawan() {
    this.gaji = 1000000;
    this.bonus = 200000;

    System.out.println(
        "Gaji mula-mula " + this.gaji + " dan bonus standar " + this.bonus);
  }

  private double hitungGaji(double gaji, double bonus) {
    return gaji + bonus;
  }

  void naikGaji() {
    System.out.println("Beda profesi beda gaji");
  }

  void setBonus(double bonus) {
    this.bonus = bonus;
  }

  double getTotalGaji() {
    return hitungGaji(gaji, bonus);
  }
}
