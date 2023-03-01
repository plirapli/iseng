package com.bab_1_2.makhluk_hidup.hewan;

public class Burung {
  public final boolean bisaTerbang = true;
  public String nama = "";

  public Burung(String nama) {
    this.nama = nama;
  }

  public void hapusNama(String nama) {
    this.nama = "";
  }

  public String readNama() {
    return this.nama;
  }
}
