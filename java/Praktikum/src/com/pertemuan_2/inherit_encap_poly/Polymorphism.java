package com.pertemuan_2.inherit_encap_poly;

public class Polymorphism {
  public static void main(String[] args) {
    Karyawan karyawan[] = new Karyawan[3];
    karyawan[0] = new Manager();
    karyawan[1] = new Receptionist();
    karyawan[2] = new Manager();

    for (int i = 0; i < 3; i++) {
      System.out.println("Gaji karyawan " + i + " adalah " +
          karyawan[i].getTotalGaji());
    }

    // Dinaikin gajinya
    for (int i = 0; i < 3; i++) {
      karyawan[i].naikGaji();
    }

    for (int i = 0; i < 3; i++) {
      System.out.println(
          "Gaji karyawan " + i + " sekarang adalah " + karyawan[i].getTotalGaji());
    }
  }
}
